using System;
using System.Diagnostics;
using System.Reactive.Linq;
using Windows.UI.Xaml.Controls;
using MyTargetSDK.Infrastructure;
using MyTargetSDK.ViewModel;

namespace MyTargetSDK.WinRTP.View
{
    public sealed partial class AdControl
    {
        public AdControl()
        {
            InitializeComponent();

            BannerViewModelFactory.GetObservable(TimeSpan.FromSeconds(3))
                                  .ObserveOnDispatcher()
                                  .Subscribe(model =>
                                             {
                                                 var newAdView = new ContentPresenter
                                                                 {
                                                                     Content = model
                                                                 };

                                                 var modelType = model.GetType();
                                                 if (modelType == typeof (WebBannerViewModel))
                                                 {
                                                     newAdView.ContentTemplate = WebAd;
                                                 }
                                                 else if (modelType == typeof (AppBannerViewModel))
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