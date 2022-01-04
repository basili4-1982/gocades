#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesKeyUsage.h"
#include "CPPCadesCPKeyUsage.h"

using namespace CryptoPro::PKI::CAdES;

CCadesKeyUsage *CCadesKeyUsage_create()
{
    CCadesKeyUsage *m;
    CPPCadesCPKeyUsageObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPKeyUsageObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesKeyUsage_destroy(CCadesKeyUsage *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    free(m->err);
    free(m);
}

bool CCadesKeyUsage_get_is_present(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsPresent(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_critical(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsCritical(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_crl_sign_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsCRLSignEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_data_encipherment_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsDataEnciphermentEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_decipher_only_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsDecipherOnlyEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_digital_signature_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsDigitalSignatureEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_encipher_only_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsEncipherOnlyEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_key_agreement_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsKeyAgreementEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_key_cert_sign_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsKeyCertSignEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_key_encipherment_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsKeyEnciphermentEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesKeyUsage_get_is_non_repudation_enabled(CCadesKeyUsage *m)
{
    CPPCadesCPKeyUsageObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPKeyUsageObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsNonRepudiationEnabled(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}