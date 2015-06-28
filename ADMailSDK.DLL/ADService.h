

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat May 23 21:56:44 2015
 */
/* Compiler settings for C:\Users\2C82~1\AppData\Local\Temp\ADService.idl-8f53aad5:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ADService_h__
#define __ADService_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(__cplusplus)
#if defined(__MIDL_USE_C_ENUM)
#define MIDL_ENUM enum
#else
#define MIDL_ENUM enum class
#endif
#endif


/* Forward Declarations */ 

#ifndef ____x_ABI_CADMailSDK_CDLL_CIADService_FWD_DEFINED__
#define ____x_ABI_CADMailSDK_CDLL_CIADService_FWD_DEFINED__
typedef interface __x_ABI_CADMailSDK_CDLL_CIADService __x_ABI_CADMailSDK_CDLL_CIADService;

#ifdef __cplusplus
namespace ABI {
    namespace ADMailSDK {
        namespace DLL {
            interface IADService;
        } /* end namespace */
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CADMailSDK_CDLL_CIADService_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ADService_0000_0000 */
/* [local] */ 


#ifdef __cplusplus
namespace ABI {
namespace ADMailSDK {
namespace DLL {
class ADService;
} /*DLL*/
} /*ADMailSDK*/
}
#endif
#if !defined(____x_ABI_CADMailSDK_CDLL_CIADService_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_ADMailSDK_DLL_IADService[] = L"ADMailSDK.DLL.IADService";
#endif /* !defined(____x_ABI_CADMailSDK_CDLL_CIADService_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_ADService_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_ADService_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ADService_0000_0000_v0_0_s_ifspec;

#ifndef ____x_ABI_CADMailSDK_CDLL_CIADService_INTERFACE_DEFINED__
#define ____x_ABI_CADMailSDK_CDLL_CIADService_INTERFACE_DEFINED__

/* interface __x_ABI_CADMailSDK_CDLL_CIADService */
/* [uuid][object] */ 



/* interface ABI::ADMailSDK::DLL::IADService */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CADMailSDK_CDLL_CIADService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace ADMailSDK {
            namespace DLL {
                
                MIDL_INTERFACE("79f404a2-7dc3-47ed-a739-65da9f5211b8")
                IADService : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetInt( 
                        /* [out][retval] */ INT32 *result) = 0;
                    
                    virtual HRESULT STDMETHODCALLTYPE ShowSomeText( void) = 0;
                    
                };

                extern const __declspec(selectany) IID & IID_IADService = __uuidof(IADService);

                
            }  /* end namespace */
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CADMailSDK_CDLL_CIADServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetInt )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This,
            /* [out][retval] */ INT32 *result);
        
        HRESULT ( STDMETHODCALLTYPE *ShowSomeText )( 
            __x_ABI_CADMailSDK_CDLL_CIADService * This);
        
        END_INTERFACE
    } __x_ABI_CADMailSDK_CDLL_CIADServiceVtbl;

    interface __x_ABI_CADMailSDK_CDLL_CIADService
    {
        CONST_VTBL struct __x_ABI_CADMailSDK_CDLL_CIADServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CADMailSDK_CDLL_CIADService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CADMailSDK_CDLL_CIADService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CADMailSDK_CDLL_CIADService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CADMailSDK_CDLL_CIADService_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CADMailSDK_CDLL_CIADService_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CADMailSDK_CDLL_CIADService_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CADMailSDK_CDLL_CIADService_GetInt(This,result)	\
    ( (This)->lpVtbl -> GetInt(This,result) ) 

#define __x_ABI_CADMailSDK_CDLL_CIADService_ShowSomeText(This)	\
    ( (This)->lpVtbl -> ShowSomeText(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CADMailSDK_CDLL_CIADService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ADService_0000_0001 */
/* [local] */ 

#ifndef RUNTIMECLASS_ADMailSDK_DLL_ADService_DEFINED
#define RUNTIMECLASS_ADMailSDK_DLL_ADService_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_ADMailSDK_DLL_ADService[] = L"ADMailSDK.DLL.ADService";
#endif


/* interface __MIDL_itf_ADService_0000_0001 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_ADService_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ADService_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


