#include "stdafx.h"
#include <stdlib.h>
#include "CCadesCertificateStatus.h"
#include "CPPCadesCPCertificateStatus.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesCertificateStatus_t
{
    boost::shared_ptr<CPPCadesCPCertificateStatusObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesCertificateStatus *CCadesCertificateStatus_create()
{
    CCadesCertificateStatus *m;

    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPCertificateStatusObject>();
    m->err = boost::make_shared<CAtlStringA>();

    return m;
}

void CCadesCertificateStatus_destroy(CCadesCertificateStatus *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesCertificateStatus_error(CCadesCertificateStatus *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

bool CCadesCertificateStatus_get_result(CCadesCertificateStatus *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_Result(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}
