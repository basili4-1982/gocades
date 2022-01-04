#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesEKUs.h"
#include "CCadesOID.h"
#include "CPPCadesCollections.h"
#include "CPPCadesCPEKU.h"

using namespace CryptoPro::PKI::CAdES;

CCadesEKUs *CCadesEKUs_create()
{
    CCadesEKUs *m;
    CPPCadesCPEKUObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPEKUObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesEKUs_destroy(CCadesEKUs *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPEKUObject *>(m->obj);
    free(m->err);
    free(m);
}

int CCadesEKUs_get_count(CCadesEKUs *m)
{
    CPPCadesCPEKUsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPEKUsObject *>(m->obj);
    unsigned int r;
    HRESULT hr = obj->get_Count(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

CCadesEKU* CCadesEKUs_get_item(CCadesEKUs *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEKUObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPEKUsObject *>(m->obj)->get_Item(value, pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesEKU *ret = CCadesEKU_create();
    ret->obj = (void*)pObj.get();

    return ret;
}