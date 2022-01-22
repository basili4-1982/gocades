#include "stdafx.h"
#include <stdlib.h>
#include "CCadesPublicKey.h"
#include "CPPCadesCPPublicKey.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesEncodedData_t
{
    boost::shared_ptr<CPPCadesCPEncodedDataObject> obj;
    CAtlStringA err;
};
struct CCadesOID_t
{
    boost::shared_ptr<CPPCadesCPOIDObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesPublicKey_t
{
    boost::shared_ptr<CPPCadesCPPublicKeyObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesPublicKey *CCadesPublicKey_create()
{
    CCadesPublicKey *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPPublicKeyObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesPublicKey_destroy(CCadesPublicKey *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesPublicKey_error(CCadesPublicKey *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

CCadesOID* CCadesPublicKey_get_algorithm(CCadesPublicKey *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPOIDObject> pObj;
    HRESULT hr = m->obj->get_Algorithm(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesOID *ret = CCadesOID_create();
    ret->obj = pObj;

    return ret;
}

CCadesEncodedData* CCadesPublicKey_get_encoded_key(CCadesPublicKey *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEncodedDataObject> pObj;
    HRESULT hr = m->obj->get_EncodedKey(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesEncodedData *ret = CCadesEncodedData_create();
    ret->obj = pObj;

    return ret;
}

CCadesEncodedData* CCadesPublicKey_get_encoded_parameters(CCadesPublicKey *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEncodedDataObject> pObj;
    HRESULT hr = m->obj->get_EncodedParameters(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesEncodedData *ret = CCadesEncodedData_create();
    ret->obj = pObj;

    return ret;
}

int CCadesPublicKey_get_length(CCadesPublicKey *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_Length(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}
