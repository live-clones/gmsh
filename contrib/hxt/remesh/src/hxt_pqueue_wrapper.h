#ifndef HXT_PQUEUE_WRAPPER_H
#define HXT_PQUEUE_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#include "hxt_message.h"
#include <stdint.h>
#endif

HXTStatus hxtPQueueCreate(void ** data);
HXTStatus hxtPQueueDelete(void ** data);

HXTStatus hxtPQueueInsert(const double priority, const uint32_t id, void *data);
HXTStatus hxtPQueuePop(uint32_t *id, void *data);
HXTStatus hxtPQueueTop(uint32_t *id, void *data);

HXTStatus hxtPQueueIsEmpty(void *data, uint32_t *is);
HXTStatus hxtPQueueSize(void *data, uint32_t *size);
HXTStatus hxtPQueueShow(void *data);

#ifdef __cplusplus
}
#endif

#endif
