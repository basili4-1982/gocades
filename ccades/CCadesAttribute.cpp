#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAttribute.h"
#include "CCadesOID.h"
#include "CPPCadesCPAttribute.h"
#include "CPPCadesCPOID.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesAttribute_t
{
    boost::shared_ptr<CPPCadesCPAttributeObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

struct CCadesOID_t
{
    boost::shared_ptr<CPPCadesCPOIDObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesAttribute *CCadesAttribute_create()
{
    CCadesAttribute *m = (typeof(m))calloc(1, sizeof(*m));
    if (!m)
    {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    m->obj = boost::make_shared<CPPCadesCPAttributeObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesAttribute_destroy(CCadesAttribute *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char *CCadesAttribute_error(CCadesAttribute *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

CCadesOID *CCadesAttribute_get_oid(CCadesAttribute *m)
{
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPOIDObject> pObj;
    HRESULT hr = m->obj->get_OID(pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesOID *ret = CCadesOID_create();
    ret->obj = pObj;

    return ret;
}

void CCadesAttribute_put_oid(CCadesAttribute *m, char *value)
{
    if (m == NULL)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_OID(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char *CCadesAttribute_get_value(CCadesAttribute *m)
{
    if (m == NULL)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->get_Value(blob);
    char *buf = (char *)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesAttribute_put_value(CCadesAttribute *m, char *value)
{
    if (m == NULL)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
    HRESULT hr = m->obj->put_Value(blob);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesAttribute_put_name(CCadesAttribute *m, int value)
{
    if (m == NULL)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Name((CADESCOM_ATTRIBUTE)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesAttribute_get_name(CCadesAttribute *m)
{
    if (m == NULL)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CADESCOM_ATTRIBUTE val;
    HRESULT hr = m->obj->get_Name(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

void CCadesAttribute_put_value_encoding(CCadesAttribute *m, int value)
{
    if (m == NULL)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_ValueEncoding((CAPICOM_ENCODING_TYPE)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesAttribute_get_value_encoding(CCadesAttribute *m)
{
    if (m == NULL)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_ENCODING_TYPE val;
    HRESULT hr = m->obj->get_ValueEncoding(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}
