#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEKU.h"
#include "CPPCadesCPEKU.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesEKU_t
{
    boost::shared_ptr<CPPCadesCPEKUObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesEKU *CCadesEKU_create()
{
    CCadesEKU *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPEKUObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesEKU_destroy(CCadesEKU *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesEKU_error(CCadesEKU *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesEKU_get_name(CCadesEKU *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_EKU val;
    HRESULT hr = m->obj->get_Name(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

void CCadesEKU_put_name(CCadesEKU *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Name((CAPICOM_EKU)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesEKU_get_oid(CCadesEKU *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_OID(sValue);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

void CCadesEKU_put_oid(CCadesEKU *m, char* value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sValue(value);
    HRESULT hr = m->obj->put_OID(sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}
