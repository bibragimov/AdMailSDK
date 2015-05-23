// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain(HMODULE /* hModule */, DWORD ul_reason_for_call, LPVOID /* lpReserved */)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

STDAPI DllGetActivationFactory(_In_ HSTRING activatibleClassId, _COM_Outptr_ IActivationFactory** factory)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return module.GetActivationFactory(activatibleClassId, factory);
}

STDAPI DllCanUnloadNow()
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return module.Terminate() ? S_OK : S_FALSE;
}

STDAPI DllGetClassObject(__in REFCLSID rclsid, __in REFIID riid, __deref_out LPVOID FAR* ppv)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return module.GetClassObject(rclsid, riid, ppv);
}

