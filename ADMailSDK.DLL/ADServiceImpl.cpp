#include "pch.h"
#include "ADService.h"
#include <windows.applicationmodel.core.h>
#include <d3

using namespace Microsoft::WRL;

namespace ABI
{
	namespace ADMailSDK
	{
		namespace DLL
		{
			using namespace Microsoft::WRL;
			using namespace Microsoft::WRL::Wrappers;
			using namespace Windows::Foundation;
			using namespace Windows::ApplicationModel::Core;
			using namespace ABI::Windows::UI::Core;

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

				STDMETHODIMP ShowSomeText() override
				{
					HRESULT hr;
					
					ComPtr<ICoreApplication> coreApplication;
					hr = GetActivationFactory(HStringReference(RuntimeClass_Windows_ApplicationModel_Core_CoreApplication).Get(), coreApplication.GetAddressOf());

					ComPtr<ICoreApplicationView> coreApplicationView;
					hr = coreApplication->GetCurrentView(coreApplicationView.GetAddressOf());

					ComPtr<ICoreWindow> coreWindow;
					hr = coreApplicationView->get_CoreWindow(coreWindow.GetAddressOf());


					return S_OK;
				}
			};

			ActivatableClass(ADService);
		}
	}
}