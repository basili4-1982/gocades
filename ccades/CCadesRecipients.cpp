#include "stdafx.h"
#include <stdlib.h>
#include "CCadesRecipients.h"
#include "CCadesOID.h"
#include "CPPCadesCollections.h"
#include "CPPCadesCPCertificate.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesRecipients_t
{
    boost::shared_ptr<CPPCadesCPRecipientsObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};


CCadesRecipients *CCadesRecipients_create()
{
    CCadesRecipients *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPRecipientsObject>();
    m->err = boost::make_shared<CAtlStringA>();

    return m;
}

void CCadesRecipients_destroy(CCadesRecipients *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char *CCadesRecipients_error(CCadesRecipients *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesRecipients_get_count(CCadesRecipients *m)
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

void CCadesRecipients_remove(CCadesRecipients *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->Remove(value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

CCadesCertificate* CCadesRecipients_get_item(CCadesRecipients *m, int value)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
    HRESULT hr = m->obj->get_Item(value, pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesCertificate *ret = CCadesCertificate_create();
    ret->obj = pObj;

    return ret;
}

void CCadesRecipients_add(CCadesRecipients *m, CCadesCertificate *obj)
{
    HRESULT hr = m->obj->Add(obj->obj);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesRecipients_clear(CCadesRecipients *m)
{
    HRESULT hr = m->obj->Clear();
    ErrMsgFromHResult(hr, *(m->err));
    return;
}
