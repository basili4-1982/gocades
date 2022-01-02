#ifndef CCADESVERSION_H
#define CCADESVERSION_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesVersion_t
{
    void *obj;
    char *err;
};
typedef struct CCadesVersion_t CCadesVersion;

CCadesVersion *CCadesVersion_create();
void CCadesVersion_destroy(CCadesVersion *m);
char* CCadesVersion_to_string(CCadesVersion *m);
int CCadesVersion_get_major_version(CCadesVersion *m);
int CCadesVersion_get_minor_version(CCadesVersion *m);
int CCadesVersion_get_build_version(CCadesVersion *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESVERSION_H__ */