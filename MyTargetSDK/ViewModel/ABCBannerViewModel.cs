using System;

namespace MyTargetSDK.ViewModel
{
    public abstract class ABCBannerViewModel : IBannerViewModel
    {
        protected ABCBannerViewModel(string ageRestrictions,
                                     string advertisingLabel,
                                     string title,
                                     Uri icon,
                                     string description)
        {
            AgeRestrictions = ageRestrictions;
            AdvertisingLabel = advertisingLabel;
            Title = title;
            Icon = icon;
            Description = description;
        }

        public string AgeRestrictions { get; private set; }

        public string AdvertisingLabel { get; private set; }

        public string Title { get; private set; }

        public Uri Icon { get; private set; }

        public string Description { get; private set; }
    }
}