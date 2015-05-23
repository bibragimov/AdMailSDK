using System.Runtime.Serialization;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    internal enum CategoryEnum
    {
        [EnumMember(Value = "")] None,

        [EnumMember] Apps
    }
}