using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal enum TypeEnum
    {
        [EnumMember(Value = "")] Unknown,

        [EnumMember] Teaser
    }
}