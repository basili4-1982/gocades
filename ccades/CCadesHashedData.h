#ifndef CCADESHASHEDDATA_H
#define CCADESHASHEDDATA_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesHashedData_t;
typedef struct CCadesHashedData_t CCadesHashedData;

CCadesHashedData *CCadesHashedData_create();
void CCadesHashedData_destroy(CCadesHashedData *m);
char* CCadesHashedData_error(CCadesHashedData *m);

void CCadesHashedData_put_algorithm(CCadesHashedData *m, int value);
int CCadesHashedData_get_algorithm(CCadesHashedData *m);
char* CCadesHashedData_get_value(CCadesHashedData *m);
void CCadesHashedData_put_data_encoding(CCadesHashedData *m, int value);
int CCadesHashedData_get_data_encoding(CCadesHashedData *m);
char* CCadesHashedData_get_key(CCadesHashedData *m);
void CCadesHashedData_put_key(CCadesHashedData *m, char* value);
void CCadesHashedData_hash(CCadesHashedData *m, char* value);
void CCadesHashedData_set_hash_value(CCadesHashedData *m, char* value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESHASHEDDATA_H__ */