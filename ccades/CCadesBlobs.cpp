#include "stdafx.h"
#include <stdlib.h>
#include "CCadesBlobs.h"
#include "CCadesOID.h"
#include "CPPCadesCollections.h"
#include "CPPCadesCPAttribute.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesBlobs_t
{
    boost::shared_ptr<CPPCadesCPBlobsObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};
struct CCadesAttribute_t
{
    boost::shared_ptr<CPPCadesCPAttributeObject> obj;
    boost::shared_ptr<CAtlStringA> err;
};

CCadesBlobs *CCadesBlobs_create()
{
    CCadesBlobs *m;

    m = (typeof(m))calloc(1, sizeof(*m));
    m->obj = boost::make_shared<CPPCadesCPBlobsObject>();
    m->err = boost::make_shared<CAtlStringA>();

    return m;
}

void CCadesBlobs_destroy(CCadesBlobs *m)
{
    if (m == NULL)
        return;
    m->obj.reset();
    free(m);
}

char *CCadesBlobs_error(CCadesBlobs *m)
{
    if (!m)
        return 0;
    return m->err->GetBuffer();
}

int CCadesBlobs_get_count(CCadesBlobs *m)
{
    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, *(m->err));
        return 0;
    }

    unsigned int r;
    HRESULT hr = m->obj->get_Count(&r);
    ErrMsgFromHResult(hr, *(m->err));
    return r;
}

char* CCadesBlobs_get_item(CCadesBlobs *m, int value)
{
    boost::shared_ptr<CryptoPro::CBlob> blob;
    HRESULT hr = m->obj->get_Item(value, blob);
    char *buf = (char*)calloc(blob->cbData() + 1, sizeof(char));
    memcpy(buf, blob->pbData(), blob->cbData());
    ErrMsgFromHResult(hr, *(m->err));
    return buf;
}
