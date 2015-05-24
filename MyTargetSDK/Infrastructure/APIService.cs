using System.IO;
using System.Net;
using System.Threading.Tasks;
using MyTargetSDK.JSONModels;
using Newtonsoft.Json;

namespace MyTargetSDK.Infrastructure
{
    internal static class APIService
    {
        public static async Task<Response> Get()
        {
            var request = WebRequest.CreateHttp("http://ad.mail.ru/mobile/6591");
            using (var stream = await Task<Stream>.Factory
                                                  .FromAsync(request.BeginGetRequestStream, request.EndGetRequestStream, null)
                                                  .ConfigureAwait(false))
            using (var jsonReader = new JsonTextReader(new StreamReader(stream)))
            {
                return new JsonSerializer().Deserialize<Response>(jsonReader);
            }
        }
    }
}