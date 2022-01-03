#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesCRL.h"
#include "CPPCadesCPCRL.h"

using namespace CryptoPro::PKI::CAdES;

CCadesCRL *CCadesCRL_create()
{
    CCadesCRL *m;
    CPPCadesCPCRLObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPCRLObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesCRL_destroy(CCadesCRL *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPCRLObject *>(m->obj);
    free(m->err);
    free(m);
}

void CCadesCRL_import(CCadesCRL *m, char* value)
{
    CPPCadesCPCRLObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPCRLObject *>(m->obj);
    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char*)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = obj->Import(blob);
    ErrMsgFromHResult(hr, m->err);
    return;
}

char* CCadesCRL_export(CCadesCRL *m, int value)
{
    CPPCadesCPCRLObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCRLObject *>(m->obj);
    CryptoPro::CBlob blob;
    HRESULT hr = obj->Export((CAPICOM_ENCODING_TYPE)value, blob);
    CAtlString sValue((char *)blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}


char* CCadesCRL_get_issuer_name(CCadesCRL *m)
{
    CPPCadesCPCRLObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCRLObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_IssuerName(sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

char* CCadesCRL_get_this_update(CCadesCRL *m)
{
    CPPCadesCPCRLObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCRLObject *>(m->obj);
    CryptoPro::CDateTime d;
    HRESULT hr = obj->get_ThisUpdate(d);
    CAtlString sValue = d.tostring().c_str();
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

char* CCadesCRL_get_next_update(CCadesCRL *m)
{
    CPPCadesCPCRLObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCRLObject *>(m->obj);
    CryptoPro::CDateTime d;
    HRESULT hr = obj->get_NextUpdate(d);
    CAtlString sValue = d.tostring().c_str();
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

char* CCadesCRL_get_thumbprint(CCadesCRL *m)
{
    CPPCadesCPCRLObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCRLObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_Thumbprint(sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

char* CCadesCRL_get_auth_key_id(CCadesCRL *m)
{
    CPPCadesCPCRLObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCRLObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_AuthKeyID(sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}
