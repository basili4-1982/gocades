#include "stdafx.h"
#include <stdlib.h>
#include "CCadesRawSignature.h"
#include "CPPCadesRawSignature.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesRawSignature_t
{
    boost::shared_ptr<CPPCadesRawSignatureObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesHashedData_t
{
    boost::shared_ptr<CPPCadesCPHashedDataObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesRawSignature *CCadesRawSignature_create()
{
    CCadesRawSignature *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesRawSignatureObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesRawSignature_destroy(CCadesRawSignature *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesRawSignature_error(CCadesRawSignature *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

char *CCadesRawSignature_sign_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return NULL;
    }

    CAtlString s;
    HRESULT hr = m->obj->SignHash(hashed->obj, signer->obj, s);
    char *buf = (char*)calloc(s.GetLength() + 1, sizeof(char));
    memcpy(buf, s.GetBuffer(), s.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesRawSignature_verify_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->VerifyHash(hashed->obj, sValue, signer->obj);
    ErrMsgFromHResult(hr, *(m->err));
    return ;
}
