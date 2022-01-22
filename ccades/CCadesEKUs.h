#ifndef CCADESEKUS_H
#define CCADESEKUS_H

#include "CCadesEKU.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesEKUs_t;
typedef struct CCadesEKUs_t CCadesEKUs;

CCadesEKUs *CCadesEKUs_create();
void CCadesEKUs_destroy(CCadesEKUs *m);
char* CCadesEKUs_error(CCadesEKUs *m);

int CCadesEKUs_get_count(CCadesEKUs *m);
CCadesEKU* CCadesEKUs_get_item(CCadesEKUs *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESEKUS_H__ */