using System;

namespace MyTargetSDK.ViewModel
{
    public interface IBannerViewModel
    {
        string AgeRestrictions { get; }
        string AdvertisingLabel { get; }
        string Title { get; }
        Uri Icon { get; }
        string Description { get; }
    }
}