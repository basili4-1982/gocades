#include "stdafx.h"
#include <stdlib.h>
#include "CCadesHashedData.h"
#include "CPPCadesCPHashedData.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesHashedData_t
{
    boost::shared_ptr<CPPCadesCPHashedDataObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesHashedData *CCadesHashedData_create()
{
    CCadesHashedData *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPHashedDataObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesHashedData_destroy(CCadesHashedData *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesHashedData_error(CCadesHashedData *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

void CCadesHashedData_put_algorithm(CCadesHashedData *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Algorithm((CAPICOM_HASH_ALGORITHM)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesHashedData_get_algorithm(CCadesHashedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_HASH_ALGORITHM val;
    HRESULT hr = m->obj->get_Algorithm(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

char* CCadesHashedData_get_value(CCadesHashedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlStringA sValue;
    HRESULT hr = m->obj->get_Value(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesHashedData_put_data_encoding(CCadesHashedData *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_DataEncoding((CADESCOM_CONTENT_ENCODING_TYPE)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesHashedData_get_data_encoding(CCadesHashedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CADESCOM_CONTENT_ENCODING_TYPE val;
    HRESULT hr = m->obj->get_DataEncoding(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

char* CCadesHashedData_get_key(CCadesHashedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlStringA sValue;
    HRESULT hr = m->obj->get_Key(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesHashedData_put_key(CCadesHashedData *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_Key(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesHashedData_hash(CCadesHashedData *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_Hash(sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesHashedData_set_hash_value(CCadesHashedData *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlString sValue(value);
    HRESULT hr = m->obj->put_HashValue(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}