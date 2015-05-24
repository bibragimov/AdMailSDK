using System;
using System.Linq;
using System.Reactive.Linq;
using MyTargetSDK.JSONModels;
using MyTargetSDK.ViewModel;

namespace MyTargetSDK.Infrastructure
{
    public static class BannerViewModelFactory
    {
        private static IBannerViewModel Create(string advertisingLabel, Banner model)
        {
            switch (model.NavigationType)
            {
                case NavigationTypeEnum.Store:
                    return new AppBannerViewModel(model.AgeRestrictions,
                                                  advertisingLabel,
                                                  model.Title,
                                                  model.IconLink,
                                                  model.Description,
                                                  model.Raiting,
                                                  model.Votes);
                case NavigationTypeEnum.Web:
                    return new WebBannerViewModel(model.AgeRestrictions,
                                                  advertisingLabel,
                                                  model.Title,
                                                  model.IconLink,
                                                  model.Description,
                                                  model.Domain);
            }
            return null;
        }

        public static IObservable<IBannerViewModel> GetObservable(TimeSpan refresh)
        {
            return Observable.Timer(DateTimeOffset.Now, refresh)
                             .Select(_ => APIService.Get())
                             .Switch()
                             .Retry()
                             .Select(response =>
                                     {
                                         var ad = response.NativeAds;
                                         if (ad == null)
                                             return null;

                                         var model = ad.Banners.FirstOrDefault();
                                         return model == null
                                                    ? null
                                                    : Create(ad.Settings == null ? null : ad.Settings.AdvertisingLabel, model);
                                     });
        }
    }
}