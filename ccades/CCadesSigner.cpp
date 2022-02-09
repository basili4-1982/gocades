#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSigner.h"
#include "CPPCadesCPSigner.h"
#include "CPPCadesSignatureStatus.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesSigner_t
{
    boost::shared_ptr<CPPCadesCPSignerObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesAttributes_t
{
    boost::shared_ptr<CPPCadesCPAttributesObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesBlobs_t
{
    boost::shared_ptr<CPPCadesCPBlobsObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesSignatureStatus_t
{
    boost::shared_ptr<CPPCadesSignatureStatusObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesSigner *CCadesSigner_create()
{
    CCadesSigner *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPSignerObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesSigner_destroy(CCadesSigner *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesSigner_error(CCadesSigner *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

CCadesAttributes *CCadesSigner_get_authenticated_attributes2(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributesObject> pObj;
    HRESULT hr = m->obj->get_AuthenticatedAttributes(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesAttributes *ret = CCadesAttributes_create();
    ret->obj = pObj;

    return ret;
}

void CCadesSigner_put_authenticated_attributes2(CCadesSigner *m, CCadesAttributes *obj)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_AuthenticatedAttributes(obj->obj);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

CCadesAttributes *CCadesSigner_get_unauthenticated_attributes(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributesObject> pObj;
    HRESULT hr = m->obj->get_UnauthenticatedAttributes(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesAttributes *ret = CCadesAttributes_create();
    ret->obj = pObj;

    return ret;
}

void CCadesSigner_put_unauthenticated_attributes(CCadesSigner *m, CCadesAttributes *obj)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_UnauthenticatedAttributes(obj->obj);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

CCadesCertificate *CCadesSigner_get_certificate(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
    HRESULT hr = m->obj->get_Certificate(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesCertificate *ret = CCadesCertificate_create();
    ret->obj = pObj;

    return ret;
}

void CCadesSigner_put_certificate(CCadesSigner *m, CCadesCertificate *obj)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Certificate(obj->obj);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesSigner_put_options(CCadesSigner *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Options((CAPICOM_CERTIFICATE_INCLUDE_OPTION)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesSigner_get_options(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_CERTIFICATE_INCLUDE_OPTION val;
    HRESULT hr = m->obj->get_Options(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

CCadesBlobs *CCadesSigner_get_crls(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPBlobsObject> pObj;
    HRESULT hr = m->obj->get_CRLs(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesBlobs *ret = CCadesBlobs_create();
    ret->obj = pObj;

    return ret;
}

CCadesBlobs *CCadesSigner_get_ocsp_responses(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPBlobsObject> pObj;
    HRESULT hr = m->obj->get_OCSPResponses(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesBlobs *ret = CCadesBlobs_create();
    ret->obj = pObj;

    return ret;
}

void CCadesSigner_put_tsa_address(CCadesSigner *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_TSAAddress(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesSigner_get_tsa_address(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlStringA sValue;
    HRESULT hr = m->obj->get_TSAAddress(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesSigner_get_signature_timestamp_time(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CDateTime d;
    HRESULT hr = m->obj->get_SignatureTimeStampTime(d);
    CAtlString sValue = d.tostring().c_str();
    ErrMsgFromHResult(hr, *(m->err));
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesSigner_get_signing_time(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CDateTime d;
    HRESULT hr = m->obj->get_SigningTime(d);
    CAtlString sValue = d.tostring().c_str();
    ErrMsgFromHResult(hr, *(m->err));
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSigner_put_key_pin(CCadesSigner *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_KeyPin(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

CCadesSignatureStatus *CCadesSigner_get_signature_status(CCadesSigner *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesSignatureStatusObject> pObj;
    HRESULT hr = m->obj->get_SignatureStatus(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesSignatureStatus *ret = CCadesSignatureStatus_create();
    ret->obj = pObj;

    return ret;
}

void CCadesSigner_put_check_certificate(CCadesSigner *m, bool value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_CheckCertificate(value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

bool CCadesSigner_get_check_certificate(CCadesSigner *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_CheckCertificate(res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}
