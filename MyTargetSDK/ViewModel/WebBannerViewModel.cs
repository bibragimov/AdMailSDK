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
                                  string domain)
            : base(ageRestrictions, advertisingLabel, title, icon, description)
        {
            Domain = domain;
        }

        public string Domain { get; private set; }
    }
}