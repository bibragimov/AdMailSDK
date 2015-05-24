using System.Runtime.Serialization;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    [JsonConverter(typeof(StringEnumConverter))]
    internal enum CategoryEnum
    {
        [EnumMember(Value = "")] None,

        [EnumMember] Apps
    }
}