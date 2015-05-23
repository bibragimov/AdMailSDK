using System;
using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal sealed class Settings
    {
        [DataMember]
        public String AdvertisingLabel { get; set; }
    }
}