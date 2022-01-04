#ifndef CCADESENCODEDDATA_H
#define CCADESENCODEDDATA_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesEncodedData_t
{
    void *obj;
    char *err;
};

typedef struct CCadesEncodedData_t CCadesEncodedData;

CCadesEncodedData *CCadesEncodedData_create();
void CCadesEncodedData_destroy(CCadesEncodedData *m);
char* CCadesEncodedData_format(CCadesEncodedData *m, bool value);
char* CCadesEncodedData_get_value(CCadesEncodedData *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESENCODEDDATA_H__ */