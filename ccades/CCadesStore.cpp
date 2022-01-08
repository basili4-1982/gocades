#include "stdafx.h"
#include <stdlib.h>
#include "CCadesStore.h"
#include "CPPCadesCPStore.h"

using namespace CryptoPro::PKI::CAdES;

CCadesStore *CCadesStore_create()
{
    CCadesStore *m;
    CPPCadesCPStoreObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPStoreObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesStore_destroy(CCadesStore *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPStoreObject *>(m->obj);
    free(m->err);
    free(m);
}

void CCadesStore_open(CCadesStore *m, int value, char* name, int mode)
{
    CPPCadesCPStoreObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    CAtlStringW wName(name);
    CAPICOM_STORE_OPEN_MODE mod = (CAPICOM_STORE_OPEN_MODE)mode;
    obj = static_cast<CPPCadesCPStoreObject *>(m->obj);
    HRESULT hr = obj->Open((CADESCOM_STORE_LOCATION)value, wName, mod);
    ErrMsgFromHResult(hr, m->err);
    return;
}

void CCadesStore_close(CCadesStore *m)
{
    HRESULT hr = reinterpret_cast<CPPCadesCPStoreObject *>(m->obj)->Close();
    ErrMsgFromHResult(hr, m->err);
    return;
}

void CCadesStore_add(CCadesStore *m, CCadesCertificate *obj)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj((CPPCadesCPCertificateObject*)obj->obj);
    HRESULT hr = reinterpret_cast<CPPCadesCPStoreObject *>(m->obj)->Add(pObj);
    ErrMsgFromHResult(hr, m->err);
    return;
}

void CCadesStore_add_crl(CCadesStore *m, CCadesCRL *obj)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCRLObject> pObj((CPPCadesCPCRLObject*)obj->obj);
    HRESULT hr = reinterpret_cast<CPPCadesCPStoreObject *>(m->obj)->AddCRL(pObj);
    ErrMsgFromHResult(hr, m->err);
    return;
}

CCadesCertificates* CCadesStore_get_certificates(CCadesStore *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificatesObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPStoreObject *>(m->obj)->get_Certificates(pObj);

    ErrMsgFromHResult(hr, m->err);
    CCadesCertificates *ret = CCadesCertificates_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

int CCadesStore_get_location(CCadesStore *m)
{
    CPPCadesCPStoreObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPStoreObject *>(m->obj);
    CADESCOM_STORE_LOCATION val;
    HRESULT hr = obj->get_Location(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, m->err);
    return r;
}

char* CCadesStore_get_name(CCadesStore *m)
{
    CPPCadesCPStoreObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPStoreObject *>(m->obj);
    CAtlStringA sValue;
    HRESULT hr = obj->get_Name(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}
