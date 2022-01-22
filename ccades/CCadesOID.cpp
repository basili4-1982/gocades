#include "stdafx.h"
#include <stdlib.h>
#include "CCadesOID.h"
#include "CPPCadesCPOID.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesOID_t
{
    boost::shared_ptr<CPPCadesCPOIDObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesOID *CCadesOID_create()
{
    CCadesOID *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPOIDObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesOID_destroy(CCadesOID *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesOID_error(CCadesOID *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

char* CCadesOID_get_value(CCadesOID *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CAtlStringA> sValue;
    HRESULT hr = m->obj->get_Value(sValue);
    char *buf = (char*)calloc(sValue->GetLength(), sizeof(char));
    memcpy(buf, sValue->GetBuffer(), sValue->GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesOID_set_value(CCadesOID *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Value(value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesOID_get_friendly_name(CCadesOID *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_FriendlyName(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesOID_set_friendly_name(CCadesOID *m, char* szFriendlyName)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlString sValue = CAtlString(szFriendlyName);
    HRESULT hr = m->obj->put_FriendlyName(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesOID_get_name(CCadesOID *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_OID r;
    HRESULT hr = m->obj->get_Name(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return (int)r;
}

void CCadesOID_set_name(CCadesOID *m, int Name)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Name((CAPICOM_OID)Name);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}
