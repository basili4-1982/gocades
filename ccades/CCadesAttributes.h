#ifndef CCADESATTRIBUTES_H
#define CCADESATTRIBUTES_H

#include "CCadesAttribute.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesAttributes_t;
typedef struct CCadesAttributes_t CCadesAttributes;

CCadesAttributes *CCadesAttributes_create();
void CCadesAttributes_destroy(CCadesAttributes *m);
char* CCadesAttributes_error(CCadesAttributes *m);

int CCadesAttributes_get_count(CCadesAttributes *m);
CCadesAttribute* CCadesAttributes_get_item(CCadesAttributes *m, int value);
void CCadesAttributes_remove(CCadesAttributes *m, int value);
void CCadesAttributes_add(CCadesAttributes *m, CCadesAttribute *obj);
void CCadesAttributes_clear(CCadesAttributes *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESATTRIBUTES_H__ */