#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSignedData.h"
#include "CPPCadesCPSignedData.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesSignedData_t
{
    boost::shared_ptr<CPPCadesSignedDataObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCertificates_t
{
    boost::shared_ptr<CPPCadesCPCertificatesObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesSigners_t
{
    boost::shared_ptr<CPPCadesCPSignersObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesSigner_t
{
    boost::shared_ptr<CPPCadesCPSignerObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesHashedData_t
{
    boost::shared_ptr<CPPCadesCPHashedDataObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesSignedData *CCadesSignedData_create()
{
    CCadesSignedData *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesSignedDataObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesSignedData_destroy(CCadesSignedData *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesSignedData_error(CCadesSignedData *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

CCadesCertificates *CCadesSignedData_get_certificates(CCadesSignedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificatesObject> pObj;
    HRESULT hr = m->obj->get_Certificates(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesCertificates *ret = CCadesCertificates_create();
    ret->obj = pObj;

    return ret;
}

void CCadesSignedData_put_content(CCadesSignedData *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_Content(sValue.GetBuffer() + 1, sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesSignedData_get_content(CCadesSignedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CStringBlob sValue;
    HRESULT hr = m->obj->get_Content(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSignedData_put_content_encoding(CCadesSignedData *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_ContentEncoding((CADESCOM_CONTENT_ENCODING_TYPE)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesSignedData_get_content_encoding(CCadesSignedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CADESCOM_CONTENT_ENCODING_TYPE val;
    HRESULT hr = m->obj->get_ContentEncoding(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

CCadesSigners *CCadesSignedData_get_recipients(CCadesSignedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPSignersObject> pObj;
    HRESULT hr = m->obj->get_Signers(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesSigners *ret = CCadesSigners_create();
    ret->obj = pObj;

    return ret;
}

void CCadesSignedData_put_display_data(CCadesSignedData *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_DisplayData(value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesSignedData_get_display_data(CCadesSignedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_DisplayData(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

char *CCadesSignedData_cosign(CCadesSignedData *m, CCadesSigner *signer, int EncodingType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->CoSign(signer->obj, (CAPICOM_ENCODING_TYPE)EncodingType, &blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char *CCadesSignedData_sign(CCadesSignedData *m, CCadesSigner *signer, bool isDetached, int EncodingType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->Sign(signer->obj, isDetached, (CAPICOM_ENCODING_TYPE)EncodingType, &blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSignedData_verify(CCadesSignedData *m, char* value, bool isDetached, int Flag)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = m->obj->Verify(blob, isDetached, (CAPICOM_SIGNED_DATA_VERIFY_FLAG)Flag);
    ErrMsgFromHResult(hr, *(m->err));
    return ;
}

char *CCadesSignedData_cosign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, int EncodingType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->CoSignCades(signer->obj, (CADESCOM_CADES_TYPE)CadesType, (CAPICOM_ENCODING_TYPE)EncodingType, &blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char *CCadesSignedData_enhance_cades(CCadesSignedData *m, int CadesType, char* TSAAddress, int EncodingType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CryptoPro::CBlob blob;
    CAtlStringA sValue(TSAAddress);
    HRESULT hr = m->obj->EnhanceCades((CADESCOM_CADES_TYPE)CadesType, sValue, (CAPICOM_ENCODING_TYPE)EncodingType, &blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char *CCadesSignedData_sign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, bool isDetached, int EncodingType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->SignCades(signer->obj, (CADESCOM_CADES_TYPE)CadesType, isDetached, (CAPICOM_ENCODING_TYPE)EncodingType, &blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSignedData_verify_cades(CCadesSignedData *m, char* value, int CadesType, bool isDetached)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = m->obj->VerifyCades(blob, (CADESCOM_CADES_TYPE)CadesType, isDetached);
    ErrMsgFromHResult(hr, *(m->err));
    return ;
}

char *CCadesSignedData_cosign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->CoSignHash(signer->obj, hashed->obj, (CADESCOM_CADES_TYPE)CadesType, (CAPICOM_ENCODING_TYPE)EncodingType, &blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char *CCadesSignedData_sign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->SignHash(signer->obj, hashed->obj, (CADESCOM_CADES_TYPE)CadesType, (CAPICOM_ENCODING_TYPE)EncodingType, &blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSignedData_verify_hash(CCadesSignedData *m, CCadesHashedData *hashed, char* value, int CadesType)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = m->obj->VerifyHash(hashed->obj, blob, (CADESCOM_CADES_TYPE)CadesType);
    ErrMsgFromHResult(hr, *(m->err));
    return ;
}
