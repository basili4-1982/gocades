#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEKUs.h"
#include "CCadesOID.h"
#include "CPPCadesCollections.h"
#include "CPPCadesCPEKU.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesEKU_t
{
    boost::shared_ptr<CPPCadesCPEKUObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesEKUs_t
{
    boost::shared_ptr<CPPCadesCPEKUsObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesEKUs *CCadesEKUs_create()
{
    CCadesEKUs *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPEKUsObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesEKUs_destroy(CCadesEKUs *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesEKUs_error(CCadesEKUs *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesEKUs_get_count(CCadesEKUs *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    unsigned int r;
    HRESULT hr = m->obj->get_Count(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

CCadesEKU* CCadesEKUs_get_item(CCadesEKUs *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEKUObject> pObj;
    HRESULT hr = m->obj->get_Item(value, pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesEKU *ret = CCadesEKU_create();
    ret->obj = pObj;

    return ret;
}