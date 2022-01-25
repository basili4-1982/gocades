#ifndef CCADESSYMMETRICALGORITHM_H
#define CCADESSYMMETRICALGORITHM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificate.h"

struct CCadesSymmetricAlgorithm_t;
typedef struct CCadesSymmetricAlgorithm_t CCadesSymmetricAlgorithm;

CCadesSymmetricAlgorithm *CCadesSymmetricAlgorithm_create();
void CCadesSymmetricAlgorithm_destroy(CCadesSymmetricAlgorithm *m);
char* CCadesSymmetricAlgorithm_error(CCadesSymmetricAlgorithm *m);

void CCadesSymmetricAlgorithm_put_divers_data(CCadesSymmetricAlgorithm *m, char* value);
char* CCadesSymmetricAlgorithm_get_divers_data(CCadesSymmetricAlgorithm *m);
void CCadesSymmetricAlgorithm_put_iv(CCadesSymmetricAlgorithm *m, char* value);
char* CCadesSymmetricAlgorithm_get_iv(CCadesSymmetricAlgorithm *m);
void CCadesSymmetricAlgorithm_import_key(CCadesSymmetricAlgorithm *m, char* value, CCadesCertificate *cert, char *password);
char* CCadesSymmetricAlgorithm_export_key(CCadesSymmetricAlgorithm *m, CCadesCertificate *cert);
void CCadesSymmetricAlgorithm_generate_key(CCadesSymmetricAlgorithm *m, int value);
CCadesSymmetricAlgorithm* CCadesSymmetricAlgorithm_diversify_key(CCadesSymmetricAlgorithm *m);
char *CCadesSymmetricAlgorithm_encrypt(CCadesSymmetricAlgorithm *m, char *value, bool isFinal);
char *CCadesSymmetricAlgorithm_decrypt(CCadesSymmetricAlgorithm *m, char *value, bool isFinal);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSYMMETRICALGORITHM_H__ */
