using System.Runtime.Serialization;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;

namespace MyTargetSDK.JSONModels
{
    [DataContract]
    [JsonConverter(typeof(StringEnumConverter))]
    internal enum TypeEnum
    {
        [EnumMember(Value = "")] Unknown,

        [EnumMember] Teaser
    }
}