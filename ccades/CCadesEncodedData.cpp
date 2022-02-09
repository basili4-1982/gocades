#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEncodedData.h"
#include "CPPCadesCPEncodedData.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesEncodedData_t
{
    boost::shared_ptr<CPPCadesCPEncodedDataObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesEncodedData *CCadesEncodedData_create()
{
    CCadesEncodedData *m;
    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPEncodedDataObject>();
    m->err = boost::make_shared<CAtlStringA>();
    return m;
}

void CCadesEncodedData_destroy(CCadesEncodedData *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char* CCadesEncodedData_error(CCadesEncodedData *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

char* CCadesEncodedData_format(CCadesEncodedData *m, bool value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CAtlStringW sValueW;
    HRESULT hr = m->obj->Format(value, sValueW);
    CAtlString sValue = CAtlString(sValueW);
    char *buf = (char*)calloc(sValue.GetLength() + 1, sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}

char* CCadesEncodedData_get_value(CCadesEncodedData *m, int value)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    CryptoPro::CBlob blob;
    HRESULT hr = m->obj->get_Value((CAPICOM_ENCODING_TYPE)value, blob);
    char *buf = (char*)calloc(blob.cbData() + 1, sizeof(char));
    memcpy(buf, blob.pbData(), blob.cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}
