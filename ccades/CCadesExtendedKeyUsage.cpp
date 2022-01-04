#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesExtendedKeyUsage.h"
#include "CPPCadesCPExtendedKeyUsage.h"

using namespace CryptoPro::PKI::CAdES;

CCadesExtendedKeyUsage *CCadesExtendedKeyUsage_create()
{
    CCadesExtendedKeyUsage *m;
    CPPCadesCPExtendedKeyUsageObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPExtendedKeyUsageObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesExtendedKeyUsage_destroy(CCadesExtendedKeyUsage *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPExtendedKeyUsageObject *>(m->obj);
    free(m->err);
    free(m);
}

CCadesEKUs* CCadesExtendedKeyUsage_get_ekus(CCadesExtendedKeyUsage *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEKUsObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPExtendedKeyUsageObject *>(m->obj)->get_EKUs(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesEKUs *ret = CCadesEKUs_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

bool CCadesExtendedKeyUsage_get_is_present(CCadesExtendedKeyUsage *m)
{
    CPPCadesCPExtendedKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPExtendedKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsPresent(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesExtendedKeyUsage_get_is_critical(CCadesExtendedKeyUsage *m)
{
    CPPCadesCPExtendedKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPExtendedKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsCritical(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}
