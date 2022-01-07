#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesPrivateKey.h"
#include "CPPCadesCPPrivateKey.h"

using namespace CryptoPro::PKI::CAdES;

CCadesPrivateKey *CCadesPrivateKey_create()
{
    CCadesPrivateKey *m;
    CPPCadesCPPrivateKeyObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPPrivateKeyObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesPrivateKey_destroy(CCadesPrivateKey *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    free(m->err);
    free(m);
}

void CCadesPrivateKey_change_pin(CCadesPrivateKey *m)
{
    HRESULT hr = reinterpret_cast<CPPCadesCPPrivateKeyObject *>(m->obj)->ChangePin();
    ErrMsgFromHResult(hr, m->err);
    return;
}

char* CCadesPrivateKey_get_container_name(CCadesPrivateKey *m)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    CAtlStringA sValue;
    HRESULT hr = obj->get_ContainerName(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesPrivateKey_get_unique_container_name(CCadesPrivateKey *m)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    CAtlStringA sValue;
    HRESULT hr = obj->get_UniqueContainerName(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesPrivateKey_get_provider_name(CCadesPrivateKey *m)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_ProviderName(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

int CCadesPrivateKey_get_provider_type(CCadesPrivateKey *m)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    CAPICOM_PROV_TYPE val;
    HRESULT hr = obj->get_ProviderType(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, m->err);
    return r;
}

int CCadesPrivateKey_get_key_spec(CCadesPrivateKey *m)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    CAPICOM_KEY_SPEC val;
    HRESULT hr = obj->get_KeySpec(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, m->err);
    return r;
}

bool CCadesPrivateKey_get_is_default_pin(CCadesPrivateKey *m)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsDefaultPin(res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

void CCadesPrivateKey_set_cache(CCadesPrivateKey *m, bool value)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    DWORD r = value ? TRUE : FALSE;
    HRESULT hr = obj->set_CachePin(r);
    ErrMsgFromHResult(hr, m->err);
    return;
}

void CCadesPrivateKey_set_key_pin(CCadesPrivateKey *m, char* value)
{
    CPPCadesCPPrivateKeyObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPPrivateKeyObject *>(m->obj);
    CAtlStringA sValue(value);
    HRESULT hr = obj->set_KeyPin(sValue);
    ErrMsgFromHResult(hr, m->err);
    return;
}
