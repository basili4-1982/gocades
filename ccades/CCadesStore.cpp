#include "stdafx.h"
#include <stdlib.h>
#include "CCadesStore.h"
#include "CPPCadesCPStore.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCertificates_t
{
    boost::shared_ptr<CPPCadesCPCertificatesObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCRL_t
{
    boost::shared_ptr<CPPCadesCPCRLObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesStore_t
{
    boost::shared_ptr<CPPCadesCPStoreObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesStore *CCadesStore_create()
{
    CCadesStore *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPStoreObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesStore_destroy(CCadesStore *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesStore_error(CCadesStore *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

void CCadesStore_open(CCadesStore *m, int value, char* name, int mode)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringW wName(name);
    CAPICOM_STORE_OPEN_MODE mod = (CAPICOM_STORE_OPEN_MODE)mode;
    HRESULT hr = m->obj->Open((CADESCOM_STORE_LOCATION)value, wName, mod);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesStore_close(CCadesStore *m)
{
    HRESULT hr = m->obj->Close();
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesStore_add(CCadesStore *m, CCadesCertificate *obj)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj(obj->obj);
    HRESULT hr = m->obj->Add(pObj);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesStore_add_crl(CCadesStore *m, CCadesCRL *obj)
{
    HRESULT hr = m->obj->AddCRL(obj->obj);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

CCadesCertificates* CCadesStore_get_certificates(CCadesStore *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificatesObject> pObj;
    HRESULT hr = m->obj->get_Certificates(pObj);

    ErrMsgFromHResult(hr, *(m->err));
    CCadesCertificates *ret = CCadesCertificates_create();
    ret->obj = pObj;

    return ret;
}

int CCadesStore_get_location(CCadesStore *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CADESCOM_STORE_LOCATION val;
    HRESULT hr = m->obj->get_Location(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

char* CCadesStore_get_name(CCadesStore *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlStringA sValue;
    HRESULT hr = m->obj->get_Name(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}
