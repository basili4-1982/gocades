#ifndef CCADESSIGNEDXML_H
#define CCADESSIGNEDXML_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificates.h"
#include "CCadesSigners.h"
#include "CCadesSigner.h"

struct CCadesSignedXML_t;
typedef struct CCadesSignedXML_t CCadesSignedXML;

CCadesSignedXML *CCadesSignedXML_create();
void CCadesSignedXML_destroy(CCadesSignedXML *m);
char* CCadesSignedXML_error(CCadesSignedXML *m);

CCadesSigners *CCadesSignedXML_get_signers(CCadesSignedXML *m);
void CCadesSignedXML_put_content(CCadesSignedXML *m, char* value);
char* CCadesSignedXML_get_content(CCadesSignedXML *m);
void CCadesSignedXML_put_signature_type(CCadesSignedXML *m, int value);
void CCadesSignedXML_put_signature_method(CCadesSignedXML *m, char* value);
void CCadesSignedXML_put_digest_method(CCadesSignedXML *m, char* value);
char *CCadesSignedXML_sign(CCadesSignedXML *m, CCadesSigner *signer, char* xpath);
void CCadesSignedXML_verify(CCadesSignedXML *m, char* value, char* xpath);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNEDXML_H__ */