#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesPublicKey.h"
#include "CPPCadesCPPublicKey.h"

using namespace CryptoPro::PKI::CAdES;

CCadesPublicKey *CCadesPublicKey_create()
{
    CCadesPublicKey *m;
    CPPCadesCPPublicKeyObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPPublicKeyObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesPublicKey_destroy(CCadesPublicKey *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPPublicKeyObject *>(m->obj);
    free(m->err);
    free(m);
}

CCadesOID* CCadesPublicKey_get_algorithm(CCadesPublicKey *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPOIDObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPPublicKeyObject *>(m->obj)->get_Algorithm(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesOID *ret = CCadesOID_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

CCadesEncodedData* CCadesPublicKey_get_encoded_key(CCadesPublicKey *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEncodedDataObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPPublicKeyObject *>(m->obj)->get_EncodedKey(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesEncodedData *ret = CCadesEncodedData_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

CCadesEncodedData* CCadesPublicKey_get_encoded_parameters(CCadesPublicKey *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEncodedDataObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPPublicKeyObject *>(m->obj)->get_EncodedParameters(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesEncodedData *ret = CCadesEncodedData_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

int CCadesPublicKey_get_length(CCadesPublicKey *m)
{
    CPPCadesCPPublicKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPPublicKeyObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_Length(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}
