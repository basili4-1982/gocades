#ifndef CCADESENVELOPEDDATA_H
#define CCADESENVELOPEDDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesAlgorithm.h"
#include "CCadesRecipients.h"

struct CCadesEnvelopedData_t;
typedef struct CCadesEnvelopedData_t CCadesEnvelopedData;

CCadesEnvelopedData *CCadesEnvelopedData_create();
void CCadesEnvelopedData_destroy(CCadesEnvelopedData *m);
char* CCadesEnvelopedData_error(CCadesEnvelopedData *m);

CCadesAlgorithm *CCadesEnvelopedData_get_algorithm(CCadesEnvelopedData *m);
void CCadesEnvelopedData_put_content(CCadesEnvelopedData *m, char* value);
char* CCadesEnvelopedData_get_content(CCadesEnvelopedData *m);
void CCadesEnvelopedData_put_content_encoding(CCadesEnvelopedData *m, int value);
int CCadesEnvelopedData_get_content_encoding(CCadesEnvelopedData *m);
CCadesRecipients *CCadesEnvelopedData_get_recipients(CCadesEnvelopedData *m);
char* CCadesEnvelopedData_encrypt(CCadesEnvelopedData *m, int value);
void CCadesEnvelopedData_decrypt(CCadesEnvelopedData *m, char* value);
char* CCadesEnvelopedData_stream_encrypt(CCadesEnvelopedData *m, char* value, bool isFinal);
char* CCadesEnvelopedData_stream_decrypt(CCadesEnvelopedData *m, char* value, bool isFinal);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESENVELOPEDDATA_H__ */