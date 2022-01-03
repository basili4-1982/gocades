#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesAttributes.h"
#include "CCadesOID.h"
#include "CPPCadesCPAttributes.h"
#include "CPPCadesCPAttribute.h"

using namespace CryptoPro::PKI::CAdES;

CCadesAttributes *CCadesAttributes_create()
{
    CCadesAttributes *m;
    CPPCadesCPAttributeObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPAttributeObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesAttributes_destroy(CCadesAttributes *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPAttributeObject *>(m->obj);
    free(m->err);
    free(m);
}

int CCadesAttributes_get_count(CCadesAttributes *m)
{
    CPPCadesCPAttributesObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPAttributesObject *>(m->obj);
    long int r;
    HRESULT hr = obj->get_Count(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

void CCadesAttributes_remove(CCadesAttributes *m, int value)
{
    CPPCadesCPAttributesObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPAttributesObject *>(m->obj);
    HRESULT hr = obj->Remove(value);
    ErrMsgFromHResult(hr, m->err);
    return;
}

CCadesAttribute* CCadesAttributes_get_item(CCadesAttributes *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributeObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPAttributesObject *>(m->obj)->get_Item(value, pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesAttribute *ret = CCadesAttribute_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

void CCadesAttributes_add(CCadesAttributes *m, CCadesAttribute *obj)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributeObject> pObj((CPPCadesCPAttributeObject*)obj->obj);
    HRESULT hr = reinterpret_cast<CPPCadesCPAttributesObject *>(m->obj)->Add(pObj);
    ErrMsgFromHResult(hr, m->err);
    return;
}

void CCadesAttributes_clear(CCadesAttributes *m)
{
    HRESULT hr = reinterpret_cast<CPPCadesCPAttributesObject *>(m->obj)->Clear();
    ErrMsgFromHResult(hr, m->err);
    return;
}
