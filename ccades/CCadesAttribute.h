#ifndef CCADESATTRIBUTE_H
#define CCADESATTRIBUTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesOID.h"

struct CCadesAttribute_t;
typedef struct CCadesAttribute_t CCadesAttribute;

CCadesAttribute *CCadesAttribute_create();
void CCadesAttribute_destroy(CCadesAttribute *m);
char* CCadesAttribute_error(CCadesAttribute *m);

CCadesOID* CCadesAttribute_get_oid(CCadesAttribute *m);
void CCadesAttribute_put_oid(CCadesAttribute *m, char* value);
char* CCadesAttribute_get_value(CCadesAttribute *m);
void CCadesAttribute_put_value(CCadesAttribute *m, char* value);
void CCadesAttribute_put_name(CCadesAttribute *m, int value);
int CCadesAttribute_get_name(CCadesAttribute *m);
void CCadesAttribute_put_value_encoding(CCadesAttribute *m, int value);
int CCadesAttribute_get_value_encoding(CCadesAttribute *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESATTRIBUTE_H__ */