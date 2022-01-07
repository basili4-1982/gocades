#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesAttribute.h"
#include "CCadesOID.h"
#include "CPPCadesCPAttribute.h"
#include "CPPCadesCPOID.h"

using namespace CryptoPro::PKI::CAdES;

CCadesAttribute *CCadesAttribute_create()
{
    CCadesAttribute *m;
    CPPCadesCPAttributeObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPAttributeObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesAttribute_destroy(CCadesAttribute *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPAttributeObject *>(m->obj);
    free(m->err);
    free(m);
}

CCadesOID* CCadesAttribute_get_oid(CCadesAttribute *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPOIDObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPAttributeObject *>(m->obj)->get_OID(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesOID *ret = CCadesOID_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

void CCadesAttribute_put_oid(CCadesAttribute *m, char* value)
{
    CPPCadesCPAttributeObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPAttributeObject *>(m->obj);
    CAtlStringA sValue(value);
    HRESULT hr = obj->put_OID(sValue);
    ErrMsgFromHResult(hr, m->err);
    return;
}

char* CCadesAttribute_get_value(CCadesAttribute *m)
{
    CPPCadesCPAttributeObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPAttributeObject *>(m->obj);
    CryptoPro::CBlob blob;
    HRESULT hr = obj->get_Value(blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, m->err);
    //std::cout << buf << std::endl;
    return buf;
}

void CCadesAttribute_put_value(CCadesAttribute *m, char* value)
{
    CPPCadesCPAttributeObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPAttributeObject *>(m->obj);
    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = obj->put_Value(blob);
    ErrMsgFromHResult(hr, m->err);
    return;
}

void CCadesAttribute_put_name(CCadesAttribute *m, int value)
{
    CPPCadesCPAttributeObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPAttributeObject *>(m->obj);
    HRESULT hr = obj->put_Name((CADESCOM_ATTRIBUTE)value);
    ErrMsgFromHResult(hr, m->err);
    return;
}

int CCadesAttribute_get_name(CCadesAttribute *m)
{
    CPPCadesCPAttributeObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPAttributeObject *>(m->obj);
    CADESCOM_ATTRIBUTE val;
    HRESULT hr = obj->get_Name(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, m->err);
    return r;
}

void CCadesAttribute_put_value_encoding(CCadesAttribute *m, int value)
{
    CPPCadesCPAttributeObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPAttributeObject *>(m->obj);
    HRESULT hr = obj->put_ValueEncoding((CAPICOM_ENCODING_TYPE)value);
    ErrMsgFromHResult(hr, m->err);
    return;
}

int CCadesAttribute_get_value_encoding(CCadesAttribute *m)
{
    CPPCadesCPAttributeObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPAttributeObject *>(m->obj);
    CAPICOM_ENCODING_TYPE val;
    HRESULT hr = obj->get_ValueEncoding(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, m->err);
    return r;
}
