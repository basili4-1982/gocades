#ifndef CCADESSIGNEDDATA_H
#define CCADESSIGNEDDATA_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificates.h"
#include "CCadesSigners.h"
#include "CCadesSigner.h"
#include "CCadesHashedData.h"

struct CCadesSignedData_t;
typedef struct CCadesSignedData_t CCadesSignedData;

CCadesSignedData *CCadesSignedData_create();
void CCadesSignedData_destroy(CCadesSignedData *m);
char* CCadesSignedData_error(CCadesSignedData *m);

CCadesCertificates *CCadesSignedData_get_certificates(CCadesSignedData *m);
void CCadesSignedData_put_content(CCadesSignedData *m, char* value);
char* CCadesSignedData_get_content(CCadesSignedData *m);
void CCadesSignedData_put_content_encoding(CCadesSignedData *m, int value);
int CCadesSignedData_get_content_encoding(CCadesSignedData *m);
CCadesSigners *CCadesSignedData_get_recipients(CCadesSignedData *m);
void CCadesSignedData_put_display_data(CCadesSignedData *m, int value);
int CCadesSignedData_get_display_data(CCadesSignedData *m);
char *CCadesSignedData_cosign(CCadesSignedData *m, CCadesSigner *signer, int EncodingType);
char *CCadesSignedData_sign(CCadesSignedData *m, CCadesSigner *signer, bool isDetached, int EncodingType);
void CCadesSignedData_verify(CCadesSignedData *m, char* value, bool isDetached, int Flag);
char *CCadesSignedData_cosign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, int EncodingType);
char *CCadesSignedData_enhance_cades(CCadesSignedData *m, int CadesType, char* TSAAddress, int EncodingType);
char *CCadesSignedData_sign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, bool isDetached, int EncodingType);
void CCadesSignedData_verify_cades(CCadesSignedData *m, char* value, int CadesType, bool isDetached);
char *CCadesSignedData_cosign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType);
char *CCadesSignedData_sign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType);
void CCadesSignedData_verify_hash(CCadesSignedData *m, CCadesHashedData *hashed, char* value, int CadesType);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNEDDATA_H__ */