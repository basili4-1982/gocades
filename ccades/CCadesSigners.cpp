#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSigners.h"
#include "CCadesOID.h"
#include "CPPCadesCollections.h"
#include "CPPCadesCPSigner.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesSigner_t
{
    boost::shared_ptr<CPPCadesCPSignerObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesSigners_t
{
    boost::shared_ptr<CPPCadesCPSignersObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesSigners *CCadesSigners_create()
{
    CCadesSigners *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPSignersObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesSigners_destroy(CCadesSigners *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesSigners_error(CCadesSigners *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesSigners_get_count(CCadesSigners *m)
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

CCadesSigner* CCadesSigners_get_item(CCadesSigners *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPSignerObject> pObj;
    HRESULT hr = m->obj->get_Item(value, pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesSigner *ret = CCadesSigner_create();
    ret->obj = pObj;

    return ret;
}