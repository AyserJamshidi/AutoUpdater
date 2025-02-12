#include <urlmon.h>

#include <qdebug.h>

class MyCallback : public IBindStatusCallback {
	public:
	MyCallback() {}

	~MyCallback() {}

	// This one is called by URLDownloadToFile
	STDMETHOD(OnProgress)(/* [in] */ ULONG ulProgress, /* [in] */ ULONG ulProgressMax, /* [in] */ ULONG ulStatusCode, /* [in] */ LPCWSTR wszStatusText) {
		qDebug() << "Downloaded " << ulProgress << " of " << ulProgressMax << " byte(s), " << " Status Code = " << ulStatusCode;
		return S_OK;
	}

	// The rest  don't do anything...
	STDMETHOD(OnStartBinding)(/* [in] */ DWORD dwReserved, /* [in] */ IBinding __RPC_FAR *pib) {
		return E_NOTIMPL;
	}

	STDMETHOD(GetPriority)(/* [out] */ LONG __RPC_FAR *pnPriority) {
		return E_NOTIMPL;
	}

	STDMETHOD(OnLowResource)(/* [in] */ DWORD reserved) {
		return E_NOTIMPL;
	}

	STDMETHOD(OnStopBinding)(/* [in] */ HRESULT hresult, /* [unique][in] */ LPCWSTR szError) {
		return E_NOTIMPL;
	}

	STDMETHOD(GetBindInfo)(/* [out] */ DWORD __RPC_FAR *grfBINDF, /* [unique][out][in] */ BINDINFO __RPC_FAR *pbindinfo) {
		return E_NOTIMPL;
	}

	STDMETHOD(OnDataAvailable)(/* [in] */ DWORD grfBSCF, /* [in] */ DWORD dwSize, /* [in] */ FORMATETC __RPC_FAR *pformatetc, /* [in] */ STGMEDIUM __RPC_FAR *pstgmed) {
		return E_NOTIMPL;
	}

	STDMETHOD(OnObjectAvailable)(/* [in] */ REFIID riid, /* [iid_is][in] */ IUnknown __RPC_FAR *punk) {
		return E_NOTIMPL;
	}

	// IUnknown stuff
	STDMETHOD_(ULONG, AddRef)() {
		return 0;
	}

	STDMETHOD_(ULONG, Release)() {
		return 0;
	}

	STDMETHOD(QueryInterface)(/* [in] */ REFIID riid, /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject) {
		return E_NOTIMPL;
	}
};