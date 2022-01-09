#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesCertificates.h"
#include "CCadesCertificates.h"
#include "CPPCadesCPCertificates.h"
#include "CPPCadesCPCertificate.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCertificates_t
{
    boost::shared_ptr<CPPCadesCPCertificatesObject> obj;
    char *err;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
    char *err;
};

char* CCadesCertificates_error(CCadesCertificates *m)
{
    return m->err;
}

CCadesCertificates* CCadesCertificates_create()
{
    CCadesCertificates *m;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = boost::shared_ptr<CPPCadesCPCertificatesObject>(new CPPCadesCPCertificatesObject());
    m->err = err;

    return m;
}

void CCadesCertificates_destroy(CCadesCertificates *m)
{
    if (m == NULL)
        return;
    delete m->obj.get();
    free(m->err);
    free(m);
}

int CCadesCertificates_get_count(CCadesCertificates *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    unsigned int r;
    HRESULT hr = m->obj->Count(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

CCadesCertificate* CCadesCertificates_get_item(CCadesCertificates *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
    HRESULT hr = m->obj->Item(value, pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesCertificate *ret = CCadesCertificate_create();
    ret->obj = pObj;

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
    HRESULT hr = m->obj->Find(type, &findCriteria, ValidOnly, pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesCertificates *ret = CCadesCertificates_create();
    ret->obj = pObj;

    return ret;
}
