#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesEKU.h"
#include "CPPCadesCPEKU.h"

using namespace CryptoPro::PKI::CAdES;

CCadesEKU *CCadesEKU_create()
{
    CCadesEKU *m;
    CPPCadesCPEKUObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPEKUObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesEKU_destroy(CCadesEKU *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPEKUObject *>(m->obj);
    free(m->err);
    free(m);
}

int CCadesEKU_get_name(CCadesEKU *m)
{
    CPPCadesCPEKUObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPEKUObject *>(m->obj);
    CAPICOM_EKU val;
    HRESULT hr = obj->get_Name(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, m->err);
    return r;
}

void CCadesEKU_put_name(CCadesEKU *m, int value)
{
    CPPCadesCPEKUObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPEKUObject *>(m->obj);
    HRESULT hr = obj->put_Name((CAPICOM_EKU)value);
    ErrMsgFromHResult(hr, m->err);
    return;
}

char* CCadesEKU_get_oid(CCadesEKU *m)
{
    CPPCadesCPEKUObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPEKUObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_OID(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

void CCadesEKU_put_oid(CCadesEKU *m, char* value)
{
    CPPCadesCPEKUObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPEKUObject *>(m->obj);
    CAtlStringA sValue(value);
    HRESULT hr = obj->put_OID(sValue);
    ErrMsgFromHResult(hr, m->err);
    return;
}
