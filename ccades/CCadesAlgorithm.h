#ifndef CCADESALGORITHM_H
#define CCADESALGORITHM_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesAlgorithm_t;
typedef struct CCadesAlgorithm_t CCadesAlgorithm;

CCadesAlgorithm *CCadesAlgorithm_create();
void CCadesAlgorithm_destroy(CCadesAlgorithm *m);
char* CCadesAlgorithm_error(CCadesAlgorithm *m);

int CCadesAlgorithm_get_name(CCadesAlgorithm *m);
void CCadesAlgorithm_put_name(CCadesAlgorithm *m, int value);
int CCadesAlgorithm_get_key_length(CCadesAlgorithm *m);
void CCadesAlgorithm_put_key_length(CCadesAlgorithm *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESALGORITHM_H__ */