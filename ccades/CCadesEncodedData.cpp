#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesEncodedData.h"
#include "CPPCadesCPEncodedData.h"

using namespace CryptoPro::PKI::CAdES;

CCadesEncodedData *CCadesEncodedData_create()
{
    CCadesEncodedData *m;
    CPPCadesCPEncodedDataObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPEncodedDataObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesEncodedData_destroy(CCadesEncodedData *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPEncodedDataObject *>(m->obj);
    free(m->err);
    free(m);
}

char* CCadesEncodedData_format(CCadesEncodedData *m, bool value)
{
    CPPCadesCPEncodedDataObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPEncodedDataObject *>(m->obj);
    CAtlStringW sValueW;
    HRESULT hr = obj->Format(value, sValueW);
    CAtlString sValue = CAtlString(sValueW);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesEncodedData_get_value(CCadesEncodedData *m, int value)
{
    CPPCadesCPEncodedDataObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPEncodedDataObject *>(m->obj);
    CryptoPro::CBlob blob;
    HRESULT hr = obj->get_Value((CAPICOM_ENCODING_TYPE)value, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}
