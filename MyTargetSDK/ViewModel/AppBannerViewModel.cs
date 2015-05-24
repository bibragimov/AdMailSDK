using System;

namespace MyTargetSDK.ViewModel
{
    public sealed class AppBannerViewModel : ABCBannerViewModel
    {
        public AppBannerViewModel(string ageRestrictions,
                                  string advertisingLabel,
                                  string title,
                                  Uri icon,
                                  string description,
                                  float raiting,
                                  ulong votes)
            : base(ageRestrictions, advertisingLabel, title, icon, description)
        {
            Raiting = raiting;
            Votes = votes;
        }

        public Single Raiting { get; private set; }

        public UInt64 Votes { get; private set; }
    }
}