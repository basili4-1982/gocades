#ifndef CCADESCERTIFICATES_H
#define CCADESCERTIFICATES_H

#include "CCadesCertificate.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCertificates_t
{
    void *obj;
    char *err;
};

typedef struct CCadesCertificates_t CCadesCertificates;

CCadesCertificates *CCadesCertificates_create();
void CCadesCertificates_destroy(CCadesCertificates *m);
int CCadesCertificates_get_count(CCadesCertificates *m);
CCadesCertificate* CCadesCertificates_get_item(CCadesCertificates *m, int value);
CCadesCertificates* CCadesCertificates_find_s(CCadesCertificates *m, int FindType, char* Criteria, bool bValidOnly);
;

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCERTIFICATES_H__ */