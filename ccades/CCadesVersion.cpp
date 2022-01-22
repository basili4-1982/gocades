#include "stdafx.h"
#include <stdlib.h>
#include "CCadesVersion.h"
#include "CPPVersion.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesVersion_t
{
    boost::shared_ptr<CPPVersionObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesVersion *CCadesVersion_create()
{
    CCadesVersion *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPVersionObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesVersion_destroy(CCadesVersion *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesVersion_error(CCadesVersion *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

char* CCadesVersion_to_string(CCadesVersion *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->toString(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

int CCadesVersion_get_major_version(CCadesVersion *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_MajorVersion(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

int CCadesVersion_get_minor_version(CCadesVersion *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_MinorVersion(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

int CCadesVersion_get_build_version(CCadesVersion *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_BuildVersion(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}
