#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesBasicConstraints.h"
#include "CPPCadesCPBasicConstraints.h"

using namespace CryptoPro::PKI::CAdES;

CCadesBasicConstraints *CCadesBasicConstraints_create()
{
    CCadesBasicConstraints *m;
    CPPCadesCPBasicConstraintsObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPBasicConstraintsObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesBasicConstraints_destroy(CCadesBasicConstraints *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    free(m->err);
    free(m);
}

bool CCadesBasicConstraints_get_is_present(CCadesBasicConstraints *m)
{
    CPPCadesCPBasicConstraintsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsPresent(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

void CCadesBasicConstraints_put_is_present(CCadesBasicConstraints *m, bool value)
{
    CPPCadesCPBasicConstraintsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    HRESULT hr = obj->put_IsPresent(value);
    ErrMsgFromHResult(hr, m->err);
    return;
}

bool CCadesBasicConstraints_get_is_critical(CCadesBasicConstraints *m)
{
    CPPCadesCPBasicConstraintsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsCritical(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

void CCadesBasicConstraints_put_is_critical(CCadesBasicConstraints *m, bool value)
{
    CPPCadesCPBasicConstraintsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return;
    }

    obj = static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    HRESULT hr = obj->put_IsCritical(value);
    ErrMsgFromHResult(hr, m->err);
    return;
}

bool CCadesBasicConstraints_get_is_certificate_authority(CCadesBasicConstraints *m)
{
    CPPCadesCPBasicConstraintsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsCertificateAuthority(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

bool CCadesBasicConstraints_get_is_path_len_constraint_present(CCadesBasicConstraints *m)
{
    CPPCadesCPBasicConstraintsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_IsPathLenConstraintPresent(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}

int CCadesBasicConstraints_get_path_len_constraint(CCadesBasicConstraints *m)
{
    CPPCadesCPBasicConstraintsObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPBasicConstraintsObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_PathLenConstraint(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}
