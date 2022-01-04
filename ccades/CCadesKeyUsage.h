#ifndef CCADESKEYUSAGE_H
#define CCADESKEYUSAGE_H

#include <stdbool.h>
#include "CCadesEKUs.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesKeyUsage_t
{
    void *obj;
    char *err;
};

typedef struct CCadesKeyUsage_t CCadesKeyUsage;

CCadesKeyUsage *CCadesKeyUsage_create();
void CCadesKeyUsage_destroy(CCadesKeyUsage *m);
CCadesEKUs* CCadesKeyUsage_get_ekus(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_present(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_critical(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_crl_sign_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_data_encipherment_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_decipher_only_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_digital_signature_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_encipher_only_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_key_agreement_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_key_cert_sign_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_key_encipherment_enabled(CCadesKeyUsage *m);
bool CCadesKeyUsage_get_is_non_repudation_enabled(CCadesKeyUsage *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESKEYUSAGE_H__ */