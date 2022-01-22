#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAbout.h"
#include "CCadesVersion.h"
#include "CPPCadesAbout.h"
#include "CPPVersion.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesAbout_t
{
    boost::shared_ptr<CPPCadesAboutObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

struct CCadesVersion_t
{
    boost::shared_ptr<CPPVersionObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesAbout *CCadesAbout_create()
{
    CCadesAbout *m = (typeof(m))calloc(1, sizeof(*m));
    if (!m)
    {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    m->obj = boost::make_shared<CPPCadesAboutObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesAbout_destroy(CCadesAbout *m)
{
    if (!m)
        return;
    m->obj.reset();
    free(m);
}

char *CCadesAbout_get_version(CCadesAbout *m)
{
    if (!m)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_Version(sValue);
    char *buf = (char *)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

int CCadesAbout_get_major_version(CCadesAbout *m)
{
    if (!m)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_MajorVersion(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

int CCadesAbout_get_minor_version(CCadesAbout *m)
{
    if (!m)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_MinorVersion(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

int CCadesAbout_get_build_version(CCadesAbout *m)
{
    if (!m)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_BuildVersion(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

CCadesVersion *CCadesAbout_get_csp_version(CCadesAbout *m, char *szProvName, int dwProvType)
{
    CAtlString provName = CAtlString(szProvName);
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPVersionObject> pObj;
    HRESULT hr = m->obj->get_CSPVersion(provName, dwProvType, pObj);
    ErrMsgFromHResult(hr, *(m->err));

    CCadesVersion *ret = CCadesVersion_create();
    ret->obj = pObj;

    return ret;
}

char *CCadesAbout_get_csp_name(CCadesAbout *m, int dwProvType)
{
    if (!m)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlString sValue;
    HRESULT hr = m->obj->get_CSPName(dwProvType, sValue);
    ErrMsgFromHResult(hr, *(m->err));
    return (char *)sValue.GetString();
}

void CCadesAbout_media_filter(CCadesAbout *m, int dwMediaType)
{
    if (!m)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->MediaFilter(dwMediaType);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

void CCadesAbout_reader_filter(CCadesAbout *m, int EnabledTypes, int EnabledOperations, char *FilterRegexp)
{
    if (!m)
    {
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    CAtlStringA sFilterRegexp(FilterRegexp);
    HRESULT hr = m->obj->ReaderFilter(EnabledTypes, EnabledOperations, sFilterRegexp);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

char* CCadesAbout_error(CCadesAbout *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}
