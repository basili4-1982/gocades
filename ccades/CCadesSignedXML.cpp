#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSignedXML.h"
#include "CPPCadesSignedXML.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesSignedXML_t
{
    boost::shared_ptr<CPPCadesSignedXMLObject> obj;
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

CCadesSignedXML *CCadesSignedXML_create()
{
    CCadesSignedXML *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesSignedXMLObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesSignedXML_destroy(CCadesSignedXML *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesSignedXML_error(CCadesSignedXML *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

CCadesSigners *CCadesSignedXML_get_signers(CCadesSignedXML *m)
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

void CCadesSignedXML_put_content(CCadesSignedXML *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CStringBlob sValue(value);
    HRESULT hr = m->obj->put_Content(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesSignedXML_get_content(CCadesSignedXML *m)
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

void CCadesSignedXML_put_signature_type(CCadesSignedXML *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_SignatureType((CADESCOM_XML_SIGNATURE_TYPE)value);
    ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
    return;
}

void CCadesSignedXML_put_signature_method(CCadesSignedXML *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_SignatureMethod(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesSignedXML_put_digest_method(CCadesSignedXML *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_DigestMethod(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char *CCadesSignedXML_sign(CCadesSignedXML *m, CCadesSigner *signer, char* xpath)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CStringBlob blob;
    CStringBlob sValue(xpath);
    HRESULT hr = m->obj->Sign(signer->obj, sValue, blob);
    char *buf = (char*)calloc(blob.GetLength() + 1, sizeof(char));
    memcpy(buf, blob.GetBuffer(), blob.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesSignedXML_verify(CCadesSignedXML *m, char* value, char* xpath)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CStringBlob sValue(value);
    CStringBlob sPath(xpath);
    HRESULT hr = m->obj->Verify(sValue, sPath);
    ErrMsgFromHResult(hr, *(m->err));
    return ;
}
