using System;

namespace MyTargetSDK.ViewModel
{
    public sealed class WebBannerViewModel : ABCBannerViewModel
    {
        public WebBannerViewModel(string ageRestrictions,
                                  string advertisingLabel,
                                  string title,
                                  Uri icon,
                                  string description,
                                  Uri domain)
            : base(ageRestrictions, advertisingLabel, title, icon, description)
        {
            Domain = domain;
        }

        public Uri Domain { get; private set; }
    }
}