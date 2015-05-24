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
                                  float rating,
                                  ulong votes)
            : base(ageRestrictions, advertisingLabel, title, icon, description)
        {
            Rating = rating/5;
            Votes = votes;
        }

        public float Rating { get; private set; }
        public ulong Votes { get; private set; }
    }
}