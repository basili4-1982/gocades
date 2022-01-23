#ifndef CCADESSIGNER_H
#define CCADESSIGNER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesAttributes.h"
#include "CCadesCertificate.h"
#include "CCadesSignatureStatus.h"
#include "CCadesBlobs.h"

struct CCadesSigner_t;
typedef struct CCadesSigner_t CCadesSigner;

CCadesSigner *CCadesSigner_create();
void CCadesSigner_destroy(CCadesSigner *m);
char* CCadesSigner_error(CCadesSigner *m);

CCadesAttributes *CCadesSigner_get_authenticated_attributes2(CCadesSigner *m);
void CCadesSigner_put_authenticated_attributes2(CCadesSigner *m, CCadesAttributes *obj);
CCadesAttributes *CCadesSigner_get_unauthenticated_attributes(CCadesSigner *m);
void CCadesSigner_put_unauthenticated_attributes(CCadesSigner *m, CCadesAttributes *obj);
CCadesCertificate *CCadesSigner_get_certificate(CCadesSigner *m);
void CCadesSigner_put_certificate(CCadesSigner *m, CCadesCertificate *obj);
void CCadesSigner_put_options(CCadesSigner *m, int value);
int CCadesSigner_get_options(CCadesSigner *m);
CCadesBlobs *CCadesSigner_get_ocsp_responses(CCadesSigner *m);
CCadesBlobs *CCadesSigner_get_crls(CCadesSigner *m);
void CCadesSigner_put_tsa_address(CCadesSigner *m, char* value);
char* CCadesSigner_get_tsa_address(CCadesSigner *m);
char* CCadesSigner_get_signature_timestamp_time(CCadesSigner *m);
char* CCadesSigner_get_signing_time(CCadesSigner *m);
void CCadesSigner_put_key_pin(CCadesSigner *m, char* value);
CCadesSignatureStatus *CCadesSigner_get_signature_status(CCadesSigner *m);
bool CCadesSigner_get_check_certificate(CCadesSigner *m);
void CCadesSigner_put_check_certificate(CCadesSigner *m, bool value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNER_H__ */