using System;

namespace MyTargetSDK.ViewModel
{
    internal interface IBannerViewModel
    {
        string AgeRestrictions { get; }
        string AdvertisingLabel { get; }
        string Title { get; }
        Uri Icon { get; }
        string Description { get; }
    }
}