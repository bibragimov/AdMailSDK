using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal sealed class Advertisement
    {
        [DataMember]
        public Settings Settings { get; set; }

        [DataMember]
        public Banner[] Banners { get; set; }
    }
}