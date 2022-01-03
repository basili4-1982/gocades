#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesAbout.h"
#include "CCadesVersion.h"
#include "CPPCadesAbout.h"
#include "CPPVersion.h"

using namespace CryptoPro::PKI::CAdES;

CCadesAbout *CCadesAbout_create()
{
    CCadesAbout *m;
    CPPCadesAboutObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesAboutObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesAbout_destroy(CCadesAbout *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesAboutObject *>(m->obj);
    free(m->err);
    free(m);
}

char* CCadesAbout_get_version(CCadesAbout *m)
{
    CPPCadesAboutObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesAboutObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_Version(sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

int CCadesAbout_get_major_version(CCadesAbout *m)
{
    CPPCadesAboutObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesAboutObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_MajorVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

int CCadesAbout_get_minor_version(CCadesAbout *m)
{
    CPPCadesAboutObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesAboutObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_MinorVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

int CCadesAbout_get_build_version(CCadesAbout *m)
{
    CPPCadesAboutObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesAboutObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_BuildVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

CCadesVersion* CCadesAbout_get_csp_version(CCadesAbout *m, char* szProvName, int dwProvType)
{
    CAtlString provName = CAtlString(szProvName); 
    boost::shared_ptr<CryptoPro::PKI::CAdES::CPPVersionObject> pObj;
    HRESULT hr = reinterpret_cast<CPPCadesAboutObject *>(m->obj)->get_CSPVersion(provName, dwProvType, pObj);
    ErrMsgFromHResult(hr, m->err);

    CCadesVersion *ret = CCadesVersion_create();
    ret->obj = (void*)pObj.get();

    return ret;
}

char* CCadesAbout_get_csp_name(CCadesAbout *m, int dwProvType)
{
    CPPCadesAboutObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesAboutObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->get_CSPName(dwProvType, sValue);
    ErrMsgFromHResult(hr, m->err);
    return (char*)sValue.GetString();
}

void CCadesAbout_media_filter(CCadesAbout *m, int dwMediaType)
{
    CPPCadesAboutObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesAboutObject *>(m->obj);
    HRESULT hr = obj->MediaFilter(dwMediaType);
    ErrMsgFromHResult(hr, m->err);
    return;
}

void CCadesAbout_reader_filter(CCadesAbout *m, int EnabledTypes, int EnabledOperations, char* FilterRegexp)
{
    CPPCadesAboutObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesAboutObject *>(m->obj);
    CAtlStringA sFilterRegexp(FilterRegexp);
    HRESULT hr = obj->ReaderFilter(EnabledTypes, EnabledOperations, sFilterRegexp);
    ErrMsgFromHResult(hr, m->err);
    return;
}
