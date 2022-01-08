#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesCertificate.h"
#include "CPPCadesCPCertificate.h"

using namespace CryptoPro::PKI::CAdES;

CCadesCertificate *CCadesCertificate_create()
{
    CCadesCertificate *m;
    CPPCadesCPCertificateObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPCertificateObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesCertificate_destroy(CCadesCertificate *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPCertificateObject *>(m->obj);
    free(m->err);
    free(m);
}

char* CCadesCertificate_get_info(CCadesCertificate *m, int value)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->GetInfo((CAPICOM_CERT_INFO_TYPE)value, sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

bool CCadesCertificate_has_private_key(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->HasPrivateKey(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

CCadesCertificateStatus* CCadesCertificate_is_valid(CCadesCertificate *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateStatusObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificateObject *>(m->obj)->IsValid(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesCertificateStatus *ret = CCadesCertificateStatus_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

CCadesExtendedKeyUsage* CCadesCertificate_extended_key_usage(CCadesCertificate *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPExtendedKeyUsageObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificateObject *>(m->obj)->ExtendedKeyUsage(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesExtendedKeyUsage *ret = CCadesExtendedKeyUsage_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

CCadesKeyUsage* CCadesCertificate_key_usage(CCadesCertificate *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPKeyUsageObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificateObject *>(m->obj)->KeyUsage(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesKeyUsage *ret = CCadesKeyUsage_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

char* CCadesCertificate_export(CCadesCertificate *m, int value)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);

    CryptoPro::CBlob blob;
    HRESULT hr = obj->Export((CAPICOM_ENCODING_TYPE)value, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

void CCadesCertificate_import(CCadesCertificate *m, char* value)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = obj->Import(blob);
    ErrMsgFromHResult(hr, m->err);
    return;
}

char* CCadesCertificate_get_thumbprint(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CAtlStringA sValue;
    HRESULT hr = obj->get_Thumbprint(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesCertificate_get_serial_number(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CAtlStringA sValue;
    HRESULT hr = obj->get_SerialNumber(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesCertificate_get_subject_name(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CAtlStringA sValue;
    HRESULT hr = obj->get_SubjectName(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesCertificate_get_issuer_name(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CAtlStringA sValue;
    HRESULT hr = obj->get_IssuerName(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

int CCadesCertificate_get_version(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_Version(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

char* CCadesCertificate_get_valid_to_date(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CryptoPro::CDateTime d;
    HRESULT hr = obj->get_ValidToDate(d);
    CAtlString sValue = d.tostring().c_str();
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

char* CCadesCertificate_get_valid_from_date(CCadesCertificate *m)
{
    CPPCadesCPCertificateObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateObject *>(m->obj);
    CryptoPro::CDateTime d;
    HRESULT hr = obj->get_ValidFromDate(d);
    CAtlString sValue = d.tostring().c_str();
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

CCadesBasicConstraints* CCadesCertificate_basic_constraints(CCadesCertificate *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPBasicConstraintsObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificateObject *>(m->obj)->BasicConstraints(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesBasicConstraints *ret = CCadesBasicConstraints_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

CCadesPublicKey* CCadesCertificate_public_key(CCadesCertificate *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPPublicKeyObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificateObject *>(m->obj)->PublicKey(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesPublicKey *ret = CCadesPublicKey_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

CCadesPrivateKey* CCadesCertificate_private_key(CCadesCertificate *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPPrivateKeyObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificateObject *>(m->obj)->PrivateKey(pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesPrivateKey *ret = CCadesPrivateKey_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

void CCadesCertificate_find_private_key(CCadesCertificate *m)
{
    HRESULT hr = reinterpret_cast<CPPCadesCPCertificateObject *>(m->obj)->FindPrivateKey(CAtlString());
    ErrMsgFromHResult(hr, m->err);
    return;
}
