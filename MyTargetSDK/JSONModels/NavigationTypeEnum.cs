using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal enum NavigationTypeEnum
    {
        [EnumMember(Value = "")] Unknown,

        [EnumMember] Store,

        [EnumMember] Web
    }
}