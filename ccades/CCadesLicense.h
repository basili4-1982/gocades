#ifndef CCADESLICENSE_H
#define CCADESLICENSE_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesLicense_t;
typedef struct CCadesLicense_t CCadesLicense;

CCadesLicense *CCadesLicense_create();
void CCadesLicense_destroy(CCadesLicense *m);
char* CCadesLicense_error(CCadesLicense *m);

char* CCadesLicense_get_company_name(CCadesLicense *m, int value);
char* CCadesLicense_get_first_install_date(CCadesLicense *m, int value);
char* CCadesLicense_get_serial_number(CCadesLicense *m, int value);
char* CCadesLicense_get_type(CCadesLicense *m, int value);
char* CCadesLicense_get_valid_to(CCadesLicense *m, int value);
void CCadesLicense_set_license(CCadesLicense *m, char* value1, char* value2, char* value3);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESLICENSE_H__ */