#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CCadesCertificateStatus.h"
#include "CPPCadesCPCertificateStatus.h"

using namespace CryptoPro::PKI::CAdES;

CCadesCertificateStatus *CCadesCertificateStatus_create()
{
    CCadesCertificateStatus *m;
    CPPCadesCPCertificateStatusObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPCadesCPCertificateStatusObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesCertificateStatus_destroy(CCadesCertificateStatus *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPCadesCPCertificateStatusObject *>(m->obj);
    free(m->err);
    free(m);
}

bool CCadesCertificateStatus_get_result(CCadesCertificateStatus *m)
{
    CPPCadesCPCertificateStatusObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPCadesCPCertificateStatusObject *>(m->obj);
    BOOL res;
    HRESULT hr = obj->get_Result(&res);
    ErrMsgFromHResult(hr, m->err);
    return res;
}
