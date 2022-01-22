#include "stdafx.h"
#include <stdlib.h>
#include "CCadesBasicConstraints.h"
#include "CPPCadesCPBasicConstraints.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesBasicConstraints_t
{
    boost::shared_ptr<CPPCadesCPBasicConstraintsObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesBasicConstraints *CCadesBasicConstraints_create()
{
    CCadesBasicConstraints *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPBasicConstraintsObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesBasicConstraints_destroy(CCadesBasicConstraints *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesBasicConstraints_error(CCadesBasicConstraints *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

bool CCadesBasicConstraints_get_is_present(CCadesBasicConstraints *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsPresent(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

void CCadesBasicConstraints_put_is_present(CCadesBasicConstraints *m, bool value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_IsPresent(value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

bool CCadesBasicConstraints_get_is_critical(CCadesBasicConstraints *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsCritical(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

void CCadesBasicConstraints_put_is_critical(CCadesBasicConstraints *m, bool value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_IsCritical(value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

bool CCadesBasicConstraints_get_is_certificate_authority(CCadesBasicConstraints *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsCertificateAuthority(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

bool CCadesBasicConstraints_get_is_path_len_constraint_present(CCadesBasicConstraints *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    BOOL res;
    HRESULT hr = m->obj->get_IsPathLenConstraintPresent(&res);
    ErrMsgFromHResult(hr, *(m->err));
    return res;
}

int CCadesBasicConstraints_get_path_len_constraint(CCadesBasicConstraints *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    DWORD r;
    HRESULT hr = m->obj->get_PathLenConstraint(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}
