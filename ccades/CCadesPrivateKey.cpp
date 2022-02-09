#include "stdafx.h"
#include <stdlib.h>
#include "CCadesPrivateKey.h"
#include "CPPCadesCPPrivateKey.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesPrivateKey_t
{
    boost::shared_ptr<CPPCadesCPPrivateKeyObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesPrivateKey *CCadesPrivateKey_create()
{
    CCadesPrivateKey *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPPrivateKeyObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesPrivateKey_destroy(CCadesPrivateKey *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesPrivateKey_error(CCadesPrivateKey *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

void CCadesPrivateKey_change_pin(CCadesPrivateKey *m)
{
    HRESULT hr = m->obj->ChangePin();
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesPrivateKey_get_container_name(CCadesPrivateKey *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlStringA sValue;
    HRESULT hr = m->obj->get_ContainerName(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesPrivateKey_get_unique_container_name(CCadesPrivateKey *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlStringA sValue;
    HRESULT hr = m->obj->get_UniqueContainerName(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesPrivateKey_get_provider_name(CCadesPrivateKey *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_ProviderName(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

int CCadesPrivateKey_get_provider_type(CCadesPrivateKey *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_PROV_TYPE val;
    HRESULT hr = m->obj->get_ProviderType(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

int CCadesPrivateKey_get_key_spec(CCadesPrivateKey *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_KEY_SPEC val;
    HRESULT hr = m->obj->get_KeySpec(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

bool CCadesPrivateKey_get_is_default_pin(CCadesPrivateKey *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsDefaultPin(res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

void CCadesPrivateKey_set_cache(CCadesPrivateKey *m, bool value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    DWORD r = value ? TRUE : FALSE;
    HRESULT hr = m->obj->set_CachePin(r);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesPrivateKey_set_key_pin(CCadesPrivateKey *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->set_KeyPin(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}
