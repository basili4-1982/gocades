#ifndef CCADESOID_H
#define CCADESOID_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesOID_t;
typedef struct CCadesOID_t CCadesOID;

CCadesOID *CCadesOID_create();
void CCadesOID_destroy(CCadesOID *m);
char* CCadesOID_error(CCadesOID *m);

char* CCadesOID_get_friendly_name(CCadesOID *m);
void CCadesOID_set_friendly_name(CCadesOID *m, char* szFriendlyName);
int CCadesOID_get_name(CCadesOID *m);
void CCadesOID_set_name(CCadesOID *m, int dwOIDName);
char* CCadesOID_get_value(CCadesOID *m);
void CCadesOID_set_value(CCadesOID *m, char* szFriendlyName);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESOID_H__ */
