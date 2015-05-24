using System;
using System.Diagnostics;
using System.Windows.Controls;
using Microsoft.Phone.Reactive;
using MyTargetSDK.Infrastructure;
using MyTargetSDK.ViewModel;

namespace MyTargetSDK.Silverlight.View
{
    public partial class AdControl
    {
        public AdControl()
        {
            InitializeComponent();

            BannerViewModelFactory.GetObservable(TimeSpan.FromSeconds(30))
                                  .ObserveOnDispatcher()
                                  .Subscribe(model =>
                                             {
                                                 var newAdView = new ContentPresenter
                                                               {
                                                                   Content = model
                                                               };

                                                 var modelType = model.GetType();
                                                 if (modelType == typeof(WebBannerViewModel))
                                                 {
                                                     newAdView.ContentTemplate = WebAd;
                                                 }
                                                 else if (modelType == typeof(AppBannerViewModel))
                                                 {
                                                     newAdView.ContentTemplate = AppAd;
                                                 }
                                                 else
                                                 {
                                                     newAdView.ContentTemplate = Empty;
                                                 }
                                                 Content = newAdView;
                                             },
                                             ex => Debug.WriteLine(ex.Message));
        }

    }
}