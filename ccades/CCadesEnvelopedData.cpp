#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEnvelopedData.h"
#include "CPPCadesCPEnvelopedData.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesEnvelopedData_t
{
    boost::shared_ptr<CPPCadesCPEnvelopedDataObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesAlgorithm_t
{
    boost::shared_ptr<CPPCadesCPAlgorithmObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesRecipients_t
{
    boost::shared_ptr<CPPCadesCPRecipientsObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesEnvelopedData *CCadesEnvelopedData_create()
{
    CCadesEnvelopedData *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPEnvelopedDataObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesEnvelopedData_destroy(CCadesEnvelopedData *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesEnvelopedData_error(CCadesEnvelopedData *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

CCadesAlgorithm *CCadesEnvelopedData_get_algorithm(CCadesEnvelopedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAlgorithmObject> pObj;
    HRESULT hr = m->obj->get_Algorithm(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesAlgorithm *ret = CCadesAlgorithm_create();
    ret->obj = pObj;

    return ret;
}

void CCadesEnvelopedData_put_content(CCadesEnvelopedData *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_Content(sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesEnvelopedData_get_content(CCadesEnvelopedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CStringBlob sValue;
    HRESULT hr = m->obj->get_Content(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesEnvelopedData_put_content_encoding(CCadesEnvelopedData *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_ContentEncoding((CADESCOM_CONTENT_ENCODING_TYPE)value);
    ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
    return;
}

int CCadesEnvelopedData_get_content_encoding(CCadesEnvelopedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CADESCOM_CONTENT_ENCODING_TYPE val;
    HRESULT hr = m->obj->get_ContentEncoding(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
    return r;
}

CCadesRecipients *CCadesEnvelopedData_get_recipients(CCadesEnvelopedData *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPRecipientsObject> pObj;
    HRESULT hr = m->obj->get_Recipients(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesRecipients *ret = CCadesRecipients_create();
    ret->obj = pObj;

    return ret;
}

void CCadesEnvelopedData_decrypt(CCadesEnvelopedData *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = m->obj->Decrypt(blob);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesEnvelopedData_encrypt(CCadesEnvelopedData *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->Encrypt((CAPICOM_ENCODING_TYPE)value, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char *CCadesEnvelopedData_stream_encrypt(CCadesEnvelopedData *m, char *value, bool isFinal)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->StreamEncrypt((const char *)sValue.GetBuffer(), sValue.GetLength(), isFinal, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char *CCadesEnvelopedData_stream_decrypt(CCadesEnvelopedData *m, char *value, bool isFinal)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->StreamDecrypt((const char *)sValue.GetBuffer(), sValue.GetLength(), isFinal, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}