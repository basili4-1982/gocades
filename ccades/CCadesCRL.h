#ifndef CCADESCRL_H
#define CCADESCRL_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCRL_t
{
    void *obj;
    char *err;
};

typedef struct CCadesCRL_t CCadesCRL;

CCadesCRL *CCadesCRL_create();
void CCadesCRL_destroy(CCadesCRL *m);
void CCadesCRL_import(CCadesCRL *m, char* value);
char* CCadesCRL_export(CCadesCRL *m, int value);
char* CCadesCRL_get_issuer_name(CCadesCRL *m);
char* CCadesCRL_get_this_update(CCadesCRL *m);
char* CCadesCRL_get_next_update(CCadesCRL *m);
char* CCadesCRL_get_thumbprint(CCadesCRL *m);
char* CCadesCRL_get_auth_key_id(CCadesCRL *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCRL_H__ */