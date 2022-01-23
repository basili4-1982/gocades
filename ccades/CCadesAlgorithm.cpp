#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAlgorithm.h"
#include "CPPCadesCPAlgorithm.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesAlgorithm_t
{
    boost::shared_ptr<CPPCadesCPAlgorithmObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesAlgorithm *CCadesAlgorithm_create()
{
    CCadesAlgorithm *m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPAlgorithmObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesAlgorithm_destroy(CCadesAlgorithm *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesAlgorithm_error(CCadesAlgorithm *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesAlgorithm_get_name(CCadesAlgorithm *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CADESCOM_ENCRYPTION_ALGORITHM val;
    HRESULT hr = m->obj->get_Name(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

void CCadesAlgorithm_put_name(CCadesAlgorithm *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_Name((CADESCOM_ENCRYPTION_ALGORITHM)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}

int CCadesAlgorithm_get_key_length(CCadesAlgorithm *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAPICOM_ENCRYPTION_KEY_LENGTH val;
    HRESULT hr = m->obj->get_KeyLength(&val);
    DWORD r = (DWORD)val;
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

void CCadesAlgorithm_put_key_length(CCadesAlgorithm *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return;
    }

    HRESULT hr = m->obj->put_KeyLength((CAPICOM_ENCRYPTION_KEY_LENGTH)value);
    ErrMsgFromHResult(hr, *(m->err));
    return;
}
