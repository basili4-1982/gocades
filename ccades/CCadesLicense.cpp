#include "stdafx.h"
#include <stdlib.h>
#include "CCadesLicense.h"
#include "CPPCadesCPLicense.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesLicense_t
{
    boost::shared_ptr<CPPCadesCPLicenseObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesLicense *CCadesLicense_create()
{
    CCadesLicense *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPLicenseObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesLicense_destroy(CCadesLicense *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesLicense_error(CCadesLicense *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

char* CCadesLicense_get_company_name(CCadesLicense *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->CompanyName(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesLicense_get_first_install_date(CCadesLicense *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->FirstInstallDate(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesLicense_get_serial_number(CCadesLicense *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->SerialNumber(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesLicense_get_type(CCadesLicense *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->Type(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesLicense_get_valid_to(CCadesLicense *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->ValidTo(value, sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesLicense_set_license(CCadesLicense *m, char* value1, char* value2, char* value3)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringW sValue1(value1);
    CAtlStringW sValue2(value2);
    CAtlStringW sValue3(value3);
    HRESULT hr = m->obj->SetLicense(sValue1, sValue2, sValue3);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}
