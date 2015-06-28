#pragma once
#include <string>
#include <cinttypes>

namespace ADMailSDK
{
	namespace Banners
	{
		struct IBanner abstract
		{
			const std::string& getId() throw();
			const std::string& getType() throw();
			const std::string& getUrlScheme() throw();
			const std::string& getBundleId() throw();
			bool isAppInstalled() throw();
			const std::string& getTrackingLink() throw();
			const std::string& getFinalLink() throw();
			uint_fast32_t getTimeout() throw();
			uint_fast32_t getWidth() throw();
			uint_fast32_t getHeight() throw();
			const std::string& getAgeRestriction() throw();
		};
	}
}
