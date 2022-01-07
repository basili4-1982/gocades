#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesLicense.h"
#include "CPPCadesCPLicense.h"

using namespace CryptoPro::PKI::CAdES;

CCadesLicense *CCadesLicense_create()
{
    CCadesLicense *m;
    CPPCadesCPLicenseObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPLicenseObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesLicense_destroy(CCadesLicense *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPLicenseObject *>(m->obj);
    free(m->err);
    free(m);
}

char* CCadesLicense_get_company_name(CCadesLicense *m, int value)
{
    CPPCadesCPLicenseObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPLicenseObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->CompanyName(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesLicense_get_first_install_date(CCadesLicense *m, int value)
{
    CPPCadesCPLicenseObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPLicenseObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->FirstInstallDate(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesLicense_get_serial_number(CCadesLicense *m, int value)
{
    CPPCadesCPLicenseObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPLicenseObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->SerialNumber(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesLicense_get_type(CCadesLicense *m, int value)
{
    CPPCadesCPLicenseObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPLicenseObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->Type(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesLicense_get_valid_to(CCadesLicense *m, int value)
{
    CPPCadesCPLicenseObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPLicenseObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->ValidTo(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

void CCadesLicense_set_license(CCadesLicense *m, char* value1, char* value2, char* value3)
{
    CPPCadesCPLicenseObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPLicenseObject *>(m->obj);
    CAtlStringW sValue1(value1);
    CAtlStringW sValue2(value2);
    CAtlStringW sValue3(value3);
    HRESULT hr = obj->SetLicense(sValue1, sValue2, sValue3);
    ErrMsgFromHResult(hr, m->err);
    return;
}
