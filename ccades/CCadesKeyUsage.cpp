#include "stdafx.h"
#include <stdlib.h>
#include "CCadesKeyUsage.h"
#include "CPPCadesCPKeyUsage.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesKeyUsage_t
{
    boost::shared_ptr<CPPCadesCPKeyUsageObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesKeyUsage *CCadesKeyUsage_create()
{
    CCadesKeyUsage *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPKeyUsageObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesKeyUsage_destroy(CCadesKeyUsage *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesKeyUsage_error(CCadesKeyUsage *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

bool CCadesKeyUsage_get_is_present(CCadesKeyUsage *m)
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

bool CCadesKeyUsage_get_is_critical(CCadesKeyUsage *m)
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

bool CCadesKeyUsage_get_is_crl_sign_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsCRLSignEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_data_encipherment_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsDataEnciphermentEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_decipher_only_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsDecipherOnlyEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_digital_signature_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsDigitalSignatureEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_encipher_only_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsEncipherOnlyEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_key_agreement_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsKeyAgreementEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_key_cert_sign_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsKeyCertSignEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_key_encipherment_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsKeyEnciphermentEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesKeyUsage_get_is_non_repudation_enabled(CCadesKeyUsage *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsNonRepudiationEnabled(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}