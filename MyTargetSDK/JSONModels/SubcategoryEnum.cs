using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal enum SubcategoryEnum
    {
        [EnumMember(Value = "")] Unknown,

        [EnumMember] Communication
    }
}