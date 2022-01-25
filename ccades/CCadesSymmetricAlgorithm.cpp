#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSymmetricAlgorithm.h"
#include "CPPCadesSymmetricAlgorithm.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesSymmetricAlgorithm_t
{
    boost::shared_ptr<CPPCadesSymmetricAlgorithmObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesSymmetricAlgorithm *CCadesSymmetricAlgorithm_create()
{
    CCadesSymmetricAlgorithm *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesSymmetricAlgorithmObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesSymmetricAlgorithm_destroy(CCadesSymmetricAlgorithm *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesSymmetricAlgorithm_error(CCadesSymmetricAlgorithm *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

void CCadesSymmetricAlgorithm_put_divers_data(CCadesSymmetricAlgorithm *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_DiversData(sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesSymmetricAlgorithm_get_divers_data(CCadesSymmetricAlgorithm *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->get_DiversData(blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSymmetricAlgorithm_put_iv(CCadesSymmetricAlgorithm *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_IV(sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesSymmetricAlgorithm_get_iv(CCadesSymmetricAlgorithm *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->get_IV(blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSymmetricAlgorithm_import_key(CCadesSymmetricAlgorithm *m, char* value, CCadesCertificate *cert, char *password)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CryptoPro::CBlob blob;
    CAtlStringA sValue(value);
    CAtlStringA sPassword(password);
    HRESULT hr = m->obj->ImportKey(sValue.GetBuffer(), sValue.GetLength(), cert->obj, sPassword.GetBuffer(), sPassword.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesSymmetricAlgorithm_export_key(CCadesSymmetricAlgorithm *m, CCadesCertificate *cert)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->ExportKey(cert->obj, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSymmetricAlgorithm_generate_key(CCadesSymmetricAlgorithm *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->GenerateKey((CADESCOM_ENCRYPTION_ALGORITHM)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

CCadesSymmetricAlgorithm* CCadesSymmetricAlgorithm_diversify_key(CCadesSymmetricAlgorithm *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesSymmetricAlgorithmObject> pObj;
    HRESULT hr = m->obj->DiversifyKey(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesSymmetricAlgorithm *ret = CCadesSymmetricAlgorithm_create();
    ret->obj = pObj;

    return ret;
}

char *CCadesSymmetricAlgorithm_encrypt(CCadesSymmetricAlgorithm *m, char *value, bool isFinal)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CAtlStringA sValue(value);
    CryptoPro::CStringProxy blob;
    HRESULT hr = m->obj->Encrypt((const char *)sValue.GetBuffer(), sValue.GetLength(), isFinal, blob);
    int len = strlen(blob.c_str());
    char *buf = (char*)calloc(len + 1, sizeof(char));
    memcpy(buf, blob.c_str(), len);
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char *CCadesSymmetricAlgorithm_decrypt(CCadesSymmetricAlgorithm *m, char *value, bool isFinal)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->Decrypt((const char *)sValue.GetBuffer(), sValue.GetLength(), isFinal, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}