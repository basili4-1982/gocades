#ifndef CCADESEXTENDEDKEYUSAGE_H
#define CCADESEXTENDEDKEYUSAGE_H

#include <stdbool.h>
#include "CCadesEKUs.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesExtendedKeyUsage_t
{
    void *obj;
    char *err;
};

typedef struct CCadesExtendedKeyUsage_t CCadesExtendedKeyUsage;

CCadesExtendedKeyUsage *CCadesExtendedKeyUsage_create();
void CCadesExtendedKeyUsage_destroy(CCadesExtendedKeyUsage *m);
CCadesEKUs* CCadesExtendedKeyUsage_get_ekus(CCadesExtendedKeyUsage *m);
bool CCadesExtendedKeyUsage_get_is_present(CCadesExtendedKeyUsage *m);
bool CCadesExtendedKeyUsage_get_is_critical(CCadesExtendedKeyUsage *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESEXTENDEDKEYUSAGE_H__ */