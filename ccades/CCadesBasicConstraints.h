#ifndef CCADESBASICCONSTRAINTS_H
#define CCADESBASICCONSTRAINTS_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesBasicConstraints_t
{
    void *obj;
    char *err;
};

typedef struct CCadesBasicConstraints_t CCadesBasicConstraints;

CCadesBasicConstraints *CCadesBasicConstraints_create();
void CCadesBasicConstraints_destroy(CCadesBasicConstraints *m);
bool CCadesBasicConstraints_get_is_present(CCadesBasicConstraints *m);
void CCadesBasicConstraints_put_is_present(CCadesBasicConstraints *m, bool value);
bool CCadesBasicConstraints_get_is_critical(CCadesBasicConstraints *m);
void CCadesBasicConstraints_put_is_critical(CCadesBasicConstraints *m, bool value);
bool CCadesBasicConstraints_get_is_certificate_authority(CCadesBasicConstraints *m);
bool CCadesBasicConstraints_get_is_path_len_constraint_present(CCadesBasicConstraints *m);
int CCadesBasicConstraints_get_path_len_constraint(CCadesBasicConstraints *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESBASICCONSTRAINTS_H__ */