using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal enum NavigationType
    {
        [EnumMember(Value = "")] Unknown,

        [EnumMember] Store,

        [EnumMember] Web
    }
}