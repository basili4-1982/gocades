#ifndef CCADESSIGNATURESTATUS_H
#define CCADESSIGNATURESTATUS_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesSignatureStatus_t;
typedef struct CCadesSignatureStatus_t CCadesSignatureStatus;

CCadesSignatureStatus *CCadesSignatureStatus_create();
void CCadesSignatureStatus_destroy(CCadesSignatureStatus *m);
char* CCadesSignatureStatus_error(CCadesSignatureStatus *m);
bool CCadesSignatureStatus_is_valid(CCadesSignatureStatus *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNATURESTATUS_H__ */