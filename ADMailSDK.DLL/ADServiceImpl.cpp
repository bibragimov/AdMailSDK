#include "pch.h"
#include "ADService.h"
#include <windows.applicationmodel.core.h>

using namespace Microsoft::WRL;

struct __declspec(uuid("45D64A29-A63E-4CB6-B498-5781D298CB4F")) __declspec(novtable)
ICoreWindowInterop : IUnknown
{
	virtual HRESULT __stdcall get_WindowHandle(HWND * hwnd) = 0;
	virtual HRESULT __stdcall put_MessageHandled(unsigned char) = 0;
};

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

			class ADService : public RuntimeClass < IADService >
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

					ComPtr<ICoreWindowInterop> coreWindowInterop;
					hr = coreWindow.As(&coreWindowInterop);

					HWND hwnd;
					hr = coreWindowInterop->get_WindowHandle(&hwnd);

					ID2D1Factory* pD2DFactory;
					hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);

					Windows::Foundation::Rect boundsRect;
					hr = coreWindow->get_Bounds(&boundsRect);

					UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

					D3D_FEATURE_LEVEL featureLevels[] =
					{
						D3D_FEATURE_LEVEL_9_3
					};

					ComPtr<ID3D11Device> device;
					ComPtr<ID3D11DeviceContext> context;

					D3D_FEATURE_LEVEL m_featureLevel;

					hr = D3D11CreateDevice(
						nullptr,                    // specify null to use the default adapter
						D3D_DRIVER_TYPE_HARDWARE,
						0,
						creationFlags,              // optionally set debug and Direct2D compatibility flags
						featureLevels,              // list of feature levels this app can support
						ARRAYSIZE(featureLevels),   // number of possible feature levels
						D3D11_SDK_VERSION,
						&device,                    // returns the Direct3D device created
						&m_featureLevel,            // returns feature level of device created
						&context                    // returns the device immediate context
						);

					ComPtr<IDXGIDevice1> dxgiDevice;
					hr = device.As(&dxgiDevice);

					ComPtr<IDXGIAdapter> dxgiAdapter;
					hr = dxgiDevice->GetAdapter(&dxgiAdapter);

					ComPtr<IDXGIFactory2> dxgiFactory;
					hr = dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), &dxgiFactory);

					DXGI_SWAP_CHAIN_DESC1 swapChainDesc = { 0 };
					swapChainDesc.Width = static_cast<UINT>(boundsRect.Width); 
					swapChainDesc.Height = static_cast<UINT>(boundsRect.Height);
					swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; 
					swapChainDesc.Stereo = false;
					swapChainDesc.SampleDesc.Count = 1; 
					swapChainDesc.SampleDesc.Quality = 0;
					swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
					swapChainDesc.BufferCount = 1; 
					swapChainDesc.Scaling = DXGI_SCALING_STRETCH; 
					swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; 
					swapChainDesc.Flags = 0;

					ComPtr<IDXGISwapChain1> swapChain;
					hr = dxgiFactory->CreateSwapChainForCoreWindow(
						device.Get(),
						coreWindow.Get(),
						&swapChainDesc,
						nullptr,
						&swapChain
						);

					return S_OK;
				}
			};

			ActivatableClass(ADService);
		}
	}
}