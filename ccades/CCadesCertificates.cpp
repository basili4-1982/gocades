#include "stdafx.h"
#include <stdlib.h>
#include "CCadesCertificates.h"
#include "CCadesCertificates.h"
#include "CPPCadesCPCertificates.h"
#include "CPPCadesCPCertificate.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCertificates_t
{
    boost::shared_ptr<CPPCadesCPCertificatesObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesCertificates* CCadesCertificates_create()
{
    CCadesCertificates *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPCertificatesObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesCertificates_destroy(CCadesCertificates *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesCertificates_error(CCadesCertificates *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesCertificates_get_count(CCadesCertificates *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    unsigned int r;
    HRESULT hr = m->obj->Count(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

CCadesCertificate* CCadesCertificates_get_item(CCadesCertificates *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
    HRESULT hr = m->obj->Item(value, pObj);
    ErrMsgFromHResult(hr, *(m->err));

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
    ErrMsgFromHResult(hr, *(m->err));

    CCadesCertificates *ret = CCadesCertificates_create();
    ret->obj = pObj;

    return ret;
}
