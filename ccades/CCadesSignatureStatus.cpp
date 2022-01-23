#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSignatureStatus.h"
#include "CPPCadesSignatureStatus.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesSignatureStatus_t
{
    boost::shared_ptr<CPPCadesSignatureStatusObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesSignatureStatus *CCadesSignatureStatus_create()
{
    CCadesSignatureStatus *m;

    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesSignatureStatusObject>();
    m->err = boost::make_shared<CAtlStringA>();

    return m;
}

void CCadesSignatureStatus_destroy(CCadesSignatureStatus *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesSignatureStatus_error(CCadesSignatureStatus *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

bool CCadesSignatureStatus_is_valid(CCadesSignatureStatus *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return false;
    }

    bool res;
    HRESULT hr = m->obj->IsValid(res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}
