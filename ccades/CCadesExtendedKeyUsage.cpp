#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesExtendedKeyUsage.h"
#include "CPPCadesCPExtendedKeyUsage.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesEKUs_t
{
    boost::shared_ptr<CPPCadesCPEKUsObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesExtendedKeyUsage_t
{
    boost::shared_ptr<CPPCadesCPExtendedKeyUsageObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesExtendedKeyUsage *CCadesExtendedKeyUsage_create()
{
    CCadesExtendedKeyUsage *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPExtendedKeyUsageObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesExtendedKeyUsage_destroy(CCadesExtendedKeyUsage *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesExtendedKeyUsage_error(CCadesExtendedKeyUsage *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

CCadesEKUs* CCadesExtendedKeyUsage_get_ekus(CCadesExtendedKeyUsage *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEKUsObject> pObj;
    HRESULT hr = m->obj->get_EKUs(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesEKUs *ret = CCadesEKUs_create();
    ret->obj = pObj;

    return ret;
}

bool CCadesExtendedKeyUsage_get_is_present(CCadesExtendedKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsPresent(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesExtendedKeyUsage_get_is_critical(CCadesExtendedKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsCritical(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}
