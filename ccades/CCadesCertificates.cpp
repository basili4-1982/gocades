#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesCertificates.h"
#include "CCadesCertificates.h"
#include "CPPCadesCPCertificates.h"
#include "CPPCadesCPCertificate.h"

using namespace CryptoPro::PKI::CAdES;

CCadesCertificates *CCadesCertificates_create()
{
    CCadesCertificates *m;
    CPPCadesCPCertificatesObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPCertificatesObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesCertificates_destroy(CCadesCertificates *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPCertificatesObject *>(m->obj);
    free(m->err);
    free(m);
}

int CCadesCertificates_get_count(CCadesCertificates *m)
{
    CPPCadesCPCertificatesObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificatesObject *>(m->obj);
    unsigned int r;
    HRESULT hr = obj->Count(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

CCadesCertificate* CCadesCertificates_get_item(CCadesCertificates *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificatesObject *>(m->obj)->Item(value, pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesCertificate *ret = CCadesCertificate_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

CCadesCertificates* CCadesCertificates_find_s(CCadesCertificates *m, int FindType, char* Criteria, bool bValidOnly)
{
    FindCriteria findCriteria;
    findCriteria.str = CAtlString(Criteria);
    findCriteria.dwCriteriaFlag = FIND_CRITERIA_STRING;
    CAPICOM_CERTIFICATE_FIND_TYPE type = (CAPICOM_CERTIFICATE_FIND_TYPE)FindType;
    BOOL ValidOnly = bValidOnly;

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificatesObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificatesObject *>(m->obj)->Find(type, &findCriteria, ValidOnly, pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesCertificates *ret = CCadesCertificates_create();
    ret->obj = (void*)pObj.get();

    return ret;
}
