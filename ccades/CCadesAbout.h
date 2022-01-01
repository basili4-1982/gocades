#ifndef CCADESABOUT_H
#define CCADESABOUT_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesAbout_t;
typedef struct CCadesAbout_t CCadesAbout;

CCadesAbout *CCadesAbout_create();
void CCadesAbout_destroy(CCadesAbout *m);
char* CCadesAbout_get_version(CCadesAbout *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESABOUT_H__ */