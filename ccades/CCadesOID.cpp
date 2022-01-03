#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesOID.h"
#include "CPPCadesCPOID.h"

using namespace CryptoPro::PKI::CAdES;

CCadesOID *CCadesOID_create()
{
    CCadesOID *m;
    CPPCadesCPOIDObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPOIDObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesOID_destroy(CCadesOID *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPOIDObject *>(m->obj);
    free(m->err);
    free(m);
}

char* CCadesOID_get_value(CCadesOID *m)
{
    CPPCadesCPOIDObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPOIDObject *>(m->obj);
    boost::shared_ptr<CAtlStringA> sValue;
    HRESULT hr = obj->get_Value(sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue->GetString();
}

void CCadesOID_set_value(CCadesOID *m, char* value)
{
    CPPCadesCPOIDObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPOIDObject *>(m->obj);
    HRESULT hr = obj->put_Value(value);
    ErrMsgFromHResult(hr, m->err);
    return;
}

char* CCadesOID_get_friendly_name(CCadesOID *m)
{
    CPPCadesCPOIDObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPOIDObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_FriendlyName(sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

void CCadesOID_set_friendly_name(CCadesOID *m, char* szFriendlyName)
{
    CPPCadesCPOIDObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPOIDObject *>(m->obj);
    CAtlString sValue = CAtlString(szFriendlyName);
    HRESULT hr = obj->put_FriendlyName(sValue);
    ErrMsgFromHResult(hr, m->err);
    return;
}

int CCadesOID_get_name(CCadesOID *m)
{
    CPPCadesCPOIDObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPOIDObject *>(m->obj);
    CAPICOM_OID r;
    HRESULT hr = obj->get_Name(&r);
    ErrMsgFromHResult(hr, m->err);
    return (int)r;
}

void CCadesOID_set_name(CCadesOID *m, int Name)
{
    CPPCadesCPOIDObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPOIDObject *>(m->obj);
    HRESULT hr = obj->put_Name((CAPICOM_OID)Name);
    ErrMsgFromHResult(hr, m->err);
    return;
}
