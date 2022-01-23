#ifndef CCADESBLOBS_H
#define CCADESBLOBS_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesBlobs_t;
typedef struct CCadesBlobs_t CCadesBlobs;

CCadesBlobs *CCadesBlobs_create();
void CCadesBlobs_destroy(CCadesBlobs *m);
char* CCadesBlobs_error(CCadesBlobs *m);

int CCadesBlobs_get_count(CCadesBlobs *m);
char* CCadesBlobs_get_item(CCadesBlobs *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESBLOBS_H__ */