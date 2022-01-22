#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAttributes.h"
#include "CCadesOID.h"
#include "CPPCadesCPAttributes.h"
#include "CPPCadesCPAttribute.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesAttributes_t
{
    boost::shared_ptr<CPPCadesCPAttributesObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesAttribute_t
{
    boost::shared_ptr<CPPCadesCPAttributeObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};


CCadesAttributes *CCadesAttributes_create()
{
    CCadesAttributes *m;

    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPAttributesObject>();
    m->err = boost::make_shared<CAtlStringA>();

    return m;
}

void CCadesAttributes_destroy(CCadesAttributes *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char *CCadesAttributes_error(CCadesAttributes *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesAttributes_get_count(CCadesAttributes *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    long int r;
    HRESULT hr = m->obj->get_Count(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

void CCadesAttributes_remove(CCadesAttributes *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->Remove(value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

CCadesAttribute* CCadesAttributes_get_item(CCadesAttributes *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributeObject> pObj;
    HRESULT hr = m->obj->get_Item(value, pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesAttribute *ret = CCadesAttribute_create();
    ret->obj = pObj;

    return ret;
}

void CCadesAttributes_add(CCadesAttributes *m, CCadesAttribute *obj)
{
    HRESULT hr = m->obj->Add(obj->obj);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesAttributes_clear(CCadesAttributes *m)
{
    HRESULT hr = m->obj->Clear();
    ErrMsgFromHResult(hr, *(m->err));
    return;
}
