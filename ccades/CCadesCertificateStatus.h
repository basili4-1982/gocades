#ifndef CCADESCERTIFICATESTATUS_H
#define CCADESCERTIFICATESTATUS_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCertificateStatus_t;
typedef struct CCadesCertificateStatus_t CCadesCertificateStatus;

CCadesCertificateStatus *CCadesCertificateStatus_create();
void CCadesCertificateStatus_destroy(CCadesCertificateStatus *m);
char* CCadesCertificateStatus_error(CCadesCertificateStatus *m);
bool CCadesCertificateStatus_get_result(CCadesCertificateStatus *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCERTIFICATESTATUS_H__ */