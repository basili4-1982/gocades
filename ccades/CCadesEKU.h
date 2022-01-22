#ifndef CCADESEKU_H
#define CCADESEKU_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesEKU_t;
typedef struct CCadesEKU_t CCadesEKU;

CCadesEKU *CCadesEKU_create();
void CCadesEKU_destroy(CCadesEKU *m);
char* CCadesEKU_error(CCadesEKU *m);

int CCadesEKU_get_name(CCadesEKU *m);
void CCadesEKU_put_name(CCadesEKU *m, int value);
char* CCadesEKU_get_oid(CCadesEKU *m);
void CCadesEKU_put_oid(CCadesEKU *m, char* value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESEKU_H__ */