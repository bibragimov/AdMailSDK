using System;
using System.Diagnostics;
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
            request.Method = "GET";
            try
            {
                using (var webResponse = await Task<WebResponse>.Factory
                                                      .FromAsync(request.BeginGetResponse, request.EndGetResponse, null)
                                                      .ConfigureAwait(false))
                using (var streamReader = new StreamReader(webResponse.GetResponseStream()))
                using (var jsonReader = new JsonTextReader(streamReader))
                {
                    return new JsonSerializer().Deserialize<Response>(jsonReader);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex.Message);
                throw;
            }
        }
    }
}