#include "stdafx.h"
#include <stdlib.h>
#include "CCadesCRL.h"
#include "CPPCadesCPCRL.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesCRL_t
{
    boost::shared_ptr<CPPCadesCPCRLObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesCRL *CCadesCRL_create()
{
    CCadesCRL *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPCRLObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesCRL_destroy(CCadesCRL *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesCRL_error(CCadesCRL *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

void CCadesCRL_import(CCadesCRL *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char*)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = m->obj->Import(blob);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesCRL_export(CCadesCRL *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->Export((CAPICOM_ENCODING_TYPE)value, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}


char* CCadesCRL_get_issuer_name(CCadesCRL *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_IssuerName(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesCRL_get_this_update(CCadesCRL *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CDateTime d;
    HRESULT hr = m->obj->get_ThisUpdate(d);
    CAtlString sValue = d.tostring().c_str();
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesCRL_get_next_update(CCadesCRL *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CDateTime d;
    HRESULT hr = m->obj->get_NextUpdate(d);
    CAtlString sValue = d.tostring().c_str();
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesCRL_get_thumbprint(CCadesCRL *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_Thumbprint(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesCRL_get_auth_key_id(CCadesCRL *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_AuthKeyID(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}
