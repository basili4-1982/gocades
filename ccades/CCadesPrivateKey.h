#ifndef CCADESPRIVATEKEY_H
#define CCADESPRIVATEKEY_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesPrivateKey_t;
typedef struct CCadesPrivateKey_t CCadesPrivateKey;

CCadesPrivateKey *CCadesPrivateKey_create();
void CCadesPrivateKey_destroy(CCadesPrivateKey *m);
char* CCadesPrivateKey_error(CCadesPrivateKey *m);

void CCadesPrivateKey_change_pin(CCadesPrivateKey *m);
char* CCadesPrivateKey_get_container_name(CCadesPrivateKey *m);
char* CCadesPrivateKey_get_unique_container_name(CCadesPrivateKey *m);
char* CCadesPrivateKey_get_provider_name(CCadesPrivateKey *m);
int CCadesPrivateKey_get_provider_type(CCadesPrivateKey *m);
int CCadesPrivateKey_get_key_spec(CCadesPrivateKey *m);
bool CCadesPrivateKey_get_is_default_pin(CCadesPrivateKey *m);
void CCadesPrivateKey_set_cache(CCadesPrivateKey *m, bool value);
void CCadesPrivateKey_set_key_pin(CCadesPrivateKey *m, char* value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESPrivateKey_H__ */