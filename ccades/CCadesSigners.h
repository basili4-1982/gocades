#ifndef CCADESSIGNERS_H
#define CCADESSIGNERS_H

#include "CCadesSigner.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesSigners_t;
typedef struct CCadesSigners_t CCadesSigners;

CCadesSigners *CCadesSigners_create();
void CCadesSigners_destroy(CCadesSigners *m);
char* CCadesSigners_error(CCadesSigners *m);

int CCadesSigners_get_count(CCadesSigners *m);
CCadesSigner* CCadesSigners_get_item(CCadesSigners *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNERS_H__ */