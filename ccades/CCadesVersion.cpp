#include "stdafx.h"
#include <stdlib.h>
#include "CCadesVersion.h"
#include "CPPVerobj->toString(sValue);sion.h"

using namespace CryptoPro::PKI::CAdES;

CCadesVersion *CCadesVersion_create()
{
    CCadesVersion *m;
    CPPVersionObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPVersionObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesVersion_destroy(CCadesVersion *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPVersionObject *>(m->obj);
    free(m->err);
    free(m);
}

char* CCadesVersion_to_string(CCadesVersion_t *m)
{
    CPPVersionObject *obj;

    if (m == NULL)
        return 0;

    obj = static_cast<CPPVersionObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->toString(sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

int CCadesVersion_get_major_version(CCadesVersion_t *m)
{
    CPPVersionObject *obj;

    if (m == NULL)
        return 0;

    obj = static_cast<CPPVersionObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_MajorVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

int CCadesVersion_get_minor_version(CCadesVersion_t *m)
{
    CPPVersionObject *obj;

    if (m == NULL)
        return 0;

    obj = static_cast<CPPVersionObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_MinorVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

int CCadesVersion_get_build_version(CCadesVersion_t *m)
{
    CPPVersionObject *obj;

    if (m == NULL)
        return 0;

    obj = static_cast<CPPVersionObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_BuildVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}
