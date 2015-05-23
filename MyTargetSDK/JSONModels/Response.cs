using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal sealed class Response
    {
        [DataMember]
        public Advertisement[] NativeAds { get; set; }
    }
}