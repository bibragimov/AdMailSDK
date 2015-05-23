#include "pch.h"
#include "ADService.h"

using namespace Microsoft::WRL;

namespace ABI
{
	namespace ADMailSDK
	{
		namespace DLL
		{
			class ADService : public RuntimeClass<IADService>
			{
				InspectableClass(L"ADMailSDK.DLL.ADService", BaseTrust)

			public:
				ADService()
				{
				}

				STDMETHODIMP GetInt(INT32* result) override
				{
					*result = 10;
					return S_OK;
				}
			};

			ActivatableClass(ADService);
		}
	}
}