#include "pch.h"
#include "ADService.h"
#include <windows.applicationmodel.core.h>
#include <d2d1.h>
#include <d2d1_1.h>
#include <D3D11.h>
#include <DXGI.h>
#include <DXGI1_3.h>
#include <D2d1_1helper.h>

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
					D3D_FEATURE_LEVEL m_featureLevel;
					ID2D1Factory1* m_d2dFactory;
					ID2D1Device* m_d2dDevice;
					ID2D1DeviceContext* m_d2dContext;
					IDXGISwapChain1* m_swapChain;

					hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_d2dFactory);

					ComPtr<ICoreApplication> coreApplication;
					hr = GetActivationFactory(HStringReference(RuntimeClass_Windows_ApplicationModel_Core_CoreApplication).Get(), coreApplication.GetAddressOf());

					ComPtr<ICoreApplicationView> coreApplicationView;
					hr = coreApplication->GetCurrentView(coreApplicationView.GetAddressOf());

					ComPtr<ICoreWindow> coreWindow;
					hr = coreApplicationView->get_CoreWindow(coreWindow.GetAddressOf());

					UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

					D3D_FEATURE_LEVEL featureLevels[] =
					{
						D3D_FEATURE_LEVEL_11_1,
						D3D_FEATURE_LEVEL_11_0,
						D3D_FEATURE_LEVEL_10_1,
						D3D_FEATURE_LEVEL_10_0,
						D3D_FEATURE_LEVEL_9_3,
						D3D_FEATURE_LEVEL_9_2,
						D3D_FEATURE_LEVEL_9_1
					};

					ComPtr<ID3D11Device> device;
					ComPtr<ID3D11DeviceContext> context;

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

					hr = m_d2dFactory->CreateDevice(dxgiDevice.Get(), &m_d2dDevice);

					hr = m_d2dDevice->CreateDeviceContext(
						D2D1_DEVICE_CONTEXT_OPTIONS_NONE,
						&m_d2dContext
						);

					DXGI_SWAP_CHAIN_DESC1 swapChainDesc = { 0 };
					swapChainDesc.Width = 0;                           // use automatic sizing
					swapChainDesc.Height = 0;
					swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; // this is the most common swapchain format
					swapChainDesc.Stereo = false;
					swapChainDesc.SampleDesc.Count = 1;                // don't use multi-sampling
					swapChainDesc.SampleDesc.Quality = 0;
					swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
					swapChainDesc.BufferCount = 2;                     // use double buffering to enable flip
					swapChainDesc.Scaling = DXGI_SCALING_NONE;
					swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL; // all apps must use this SwapEffect
					swapChainDesc.Flags = 0;

					ComPtr<IDXGIAdapter> dxgiAdapter;
					hr = dxgiDevice->GetAdapter(&dxgiAdapter);

					ComPtr<IDXGIFactory2> dxgiFactory;
					hr = dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));

					hr = dxgiFactory->CreateSwapChainForComposition(
						device.Get(),
						&swapChainDesc,
						nullptr,    // allow on all displays
						&m_swapChain
						);

					dxgiDevice->SetMaximumFrameLatency(1);

					ComPtr<ID3D11Texture2D> backBuffer;
					hr = m_swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));

					D2D1_BITMAP_PROPERTIES1 bitmapProperties =
						D2D1::BitmapProperties1(
						D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
						D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE)
						);

					ComPtr<IDXGISurface> dxgiBackBuffer;
					hr = m_swapChain->GetBuffer(0, IID_PPV_ARGS(&dxgiBackBuffer));

					ComPtr<ID2D1Bitmap1> m_d2dTargetBitmap;
					hr = m_d2dContext->CreateBitmapFromDxgiSurface(
						dxgiBackBuffer.Get(),
						&bitmapProperties,
						&m_d2dTargetBitmap
						);

					m_d2dContext->SetTarget(m_d2dTargetBitmap.Get());

					ComPtr<ID2D1SolidColorBrush> pBlackBrush;
					m_d2dContext->CreateSolidColorBrush(
						D2D1::ColorF(D2D1::ColorF::Red),
						&pBlackBrush
						);

					m_d2dContext->BeginDraw();

					m_d2dContext->DrawRectangle(
						D2D1::RectF(
						0.0f,
						0.0f,
						100.0f,
						100.0f),
						pBlackBrush.Get());

					m_d2dContext->EndDraw();

					m_swapChain->Present(1, 0);

					return S_OK;
				}
			};

			ActivatableClass(ADService);
		}
	}
}