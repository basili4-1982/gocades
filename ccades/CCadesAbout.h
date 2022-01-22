#ifndef CCADESABOUT_H
#define CCADESABOUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesVersion.h"

struct CCadesAbout_t;
typedef struct CCadesAbout_t CCadesAbout;

CCadesAbout *CCadesAbout_create();
void CCadesAbout_destroy(CCadesAbout *m);
char* CCadesAbout_error(CCadesAbout *m);

char* CCadesAbout_get_version(CCadesAbout *m);
int CCadesAbout_get_major_version(CCadesAbout *m);
int CCadesAbout_get_minor_version(CCadesAbout *m);
int CCadesAbout_get_build_version(CCadesAbout *m);
char* CCadesAbout_get_csp_name(CCadesAbout *m, int dwProvType);
CCadesVersion* CCadesAbout_get_csp_version(CCadesAbout *m, char* szProvName, int dwProvType);
void CCadesAbout_media_filter(CCadesAbout *m, int dwMediaType);
void CCadesAbout_reader_filter(CCadesAbout *m, int EnabledTypes, int EnabledOperations, char* FilterRegexp);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESABOUT_H__ */