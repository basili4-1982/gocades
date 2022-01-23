#ifndef CCADESRECIPIENTS_H
#define CCADESRECIPIENTS_H

#include "CCadesCertificate.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesRecipients_t;
typedef struct CCadesRecipients_t CCadesRecipients;

CCadesRecipients *CCadesRecipients_create();
void CCadesRecipients_destroy(CCadesRecipients *m);
char* CCadesRecipients_error(CCadesRecipients *m);

int CCadesRecipients_get_count(CCadesRecipients *m);
CCadesCertificate* CCadesRecipients_get_item(CCadesRecipients *m, int value);
void CCadesRecipients_remove(CCadesRecipients *m, int value);
void CCadesRecipients_add(CCadesRecipients *m, CCadesCertificate *obj);
void CCadesRecipients_clear(CCadesRecipients *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESRECIPIENTS_H__ */