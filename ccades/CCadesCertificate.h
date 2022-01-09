#ifndef CCADESCERTIFICATE_H
#define CCADESCERTIFICATE_H

#include "CCadesBasicConstraints.h"
#include "CCadesCertificateStatus.h"
#include "CCadesExtendedKeyUsage.h"
#include "CCadesKeyUsage.h"
#include "CCadesPrivateKey.h"
#include "CCadesPublicKey.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCertificate_t;
typedef struct CCadesCertificate_t CCadesCertificate;

CCadesCertificate *CCadesCertificate_create();
void CCadesCertificate_destroy(CCadesCertificate *m);
char* CCadesCertificate_error(CCadesCertificate *m);

char* CCadesCertificate_get_info(CCadesCertificate *m, int value);
bool CCadesCertificate_has_private_key(CCadesCertificate *m);
CCadesCertificateStatus* CCadesCertificate_is_valid(CCadesCertificate *m);
CCadesExtendedKeyUsage* CCadesCertificate_extended_key_usage(CCadesCertificate *m);
CCadesKeyUsage* CCadesCertificate_key_usage(CCadesCertificate *m);
char* CCadesCertificate_export(CCadesCertificate *m, int value);
void CCadesCertificate_import(CCadesCertificate *m, char* value);
char* CCadesCertificate_get_thumbprint(CCadesCertificate *m);
char* CCadesCertificate_get_serial_number(CCadesCertificate *m);
char* CCadesCertificate_get_subject_name(CCadesCertificate *m);
char* CCadesCertificate_get_issuer_name(CCadesCertificate *m);
int CCadesCertificate_get_version(CCadesCertificate *m);
char* CCadesCertificate_get_valid_to_date(CCadesCertificate *m);
char* CCadesCertificate_get_valid_from_date(CCadesCertificate *m);
CCadesBasicConstraints* CCadesCertificate_basic_constraints(CCadesCertificate *m);
CCadesPublicKey* CCadesCertificate_public_key(CCadesCertificate *m);
CCadesPrivateKey* CCadesCertificate_private_key(CCadesCertificate *m);
void CCadesCertificate_find_private_key(CCadesCertificate *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCERTIFICATE_H__ */