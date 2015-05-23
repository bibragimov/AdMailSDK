using MyTargetSDK.JSONModels;

namespace MyTargetSDK.ViewModel
{
    internal static class BannerViewModelFactory
    {
        public static IBannerViewModel Create(Banner model)
        {
            switch (model.NavigationType)
            {
                case NavigationTypeEnum.Store:
                    return new AppBannerViewModel(model.AgeRestrictions, null, model.Title, model.IconLink, model.Description, model.Raiting, model.Votes);
                case NavigationTypeEnum.Web:
                    return new WebBannerViewModel(model.AgeRestrictions, null, model.Title, model.IconLink, model.Description, model.Domain);
            }
            return null;
        }
    }
}