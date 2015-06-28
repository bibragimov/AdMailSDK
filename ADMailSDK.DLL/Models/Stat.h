#pragma once
#include <string>

namespace ADMailSDK
{
	class Stat final
	{
		const std::string _type;
		const std::string _url;
	public:
		Stat(std::string&& type, std::string&& url) throw()
			 : _type(std::move(type))
			 , _url(std::move(url))
		{
		}
	};
}
