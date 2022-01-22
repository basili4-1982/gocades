#ifndef CCADESSTORE_H
#define CCADESSTORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificates.h"
#include "CCadesCRL.h"

struct CCadesStore_t;
typedef struct CCadesStore_t CCadesStore;

CCadesStore *CCadesStore_create();
void CCadesStore_destroy(CCadesStore *m);
char* CCadesStore_error(CCadesStore *m);

void CCadesStore_open(CCadesStore *m, int value, char* name, int mode);
void CCadesStore_close(CCadesStore *m);
void CCadesStore_add(CCadesStore *m, CCadesCertificate *obj);
void CCadesStore_add_crl(CCadesStore *m, CCadesCRL *obj);
CCadesCertificates* CCadesStore_get_certificates(CCadesStore *m);
int CCadesStore_get_location(CCadesStore *m);
char* CCadesStore_get_name(CCadesStore *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSTORE_H__ */