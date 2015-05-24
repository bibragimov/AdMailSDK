using System;
using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal sealed class Banner
    {
        [DataMember]
        public string AgeRestrictions { get; set; }

        [DataMember(Name = "bannerID")]
        public long BannerId { get; set; }

        [DataMember(Name = "bundle_id")]
        public string BundleId { get; set; }

        [DataMember]
        public CategoryEnum Category { get; set; }

        [DataMember]
        public string CtaText { get; set; }

        [DataMember]
        public string Description { get; set; }

        [DataMember]
        public string Disclaimer { get; set; }

        [DataMember]
        public Uri Domain { get; set; }

        [DataMember(Name = "extern_id")]
        public string ExternId { get; set; }

        [DataMember]
        public Uri FinalLink { get; set; }

        [DataMember]
        public float IconHeight { get; set; }

        [DataMember]
        public Uri IconLink { get; set; }

        [DataMember]
        public float IconWidth { get; set; }

        [DataMember]
        public float ImageHeight { get; set; }

        [DataMember]
        public Uri ImageLink { get; set; }

        [DataMember]
        public float ImageWidth { get; set; }

        [DataMember]
        public NavigationTypeEnum NavigationType { get; set; }

        [DataMember]
        public float Rating { get; set; }

        [DataMember]
        public SubcategoryEnum Subcategory { get; set; }

        [DataMember]
        public string Title { get; set; }

        [DataMember]
        public string TrackingLink { get; set; }

        [DataMember]
        public TypeEnum Type { get; set; }

        [DataMember]
        public Uri UrlScheme { get; set; }

        [DataMember]
        public ulong Votes { get; set; }
    }
}