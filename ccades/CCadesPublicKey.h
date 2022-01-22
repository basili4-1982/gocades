#ifndef CCADESPUBLICKEY_H
#define CCADESPUBLICKEY_H

#include "CCadesOID.h"
#include "CCadesEncodedData.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesPublicKey_t;
typedef struct CCadesPublicKey_t CCadesPublicKey;

CCadesPublicKey *CCadesPublicKey_create();
void CCadesPublicKey_destroy(CCadesPublicKey *m);
char* CCadesPublicKey_error(CCadesPublicKey *m);

CCadesOID* CCadesPublicKey_get_algorithm(CCadesPublicKey *m);
CCadesEncodedData* CCadesPublicKey_get_encoded_key(CCadesPublicKey *m);
CCadesEncodedData* CCadesPublicKey_get_encoded_parameters(CCadesPublicKey *m);
int CCadesPublicKey_get_length(CCadesPublicKey *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESPublicKey_H__ */
