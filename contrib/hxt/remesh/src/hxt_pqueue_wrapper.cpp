// Note that by default C++ creates a max-heap 
// for priority queue 
#include <iostream> 
#include <queue> 

#include "hxt_pqueue_wrapper.h"
#include "hxt_tools.h"

#include "hxt_post_debugging.h"

using namespace std; 

typedef struct {
  priority_queue<pair<double,uint32_t>> *pq;
} PQueueWrapperData;


HXTStatus hxtPQueueCreate(void **data)
{
  PQueueWrapperData *p;
  HXT_CHECK(hxtMalloc(&p,sizeof(PQueueWrapperData)));
  p->pq = new priority_queue<pair<double,uint32_t>>;
  *data = p;

  return HXT_STATUS_OK;
}

HXTStatus hxtPQueueDelete(void ** data) {
  PQueueWrapperData *p = (PQueueWrapperData*) *data;
  delete p->pq;
  p->pq = NULL;
  HXT_CHECK( hxtFree(&p) );
  return HXT_STATUS_OK;
}


HXTStatus hxtPQueueInsert(const double priority, const uint32_t id, void *data)
{
  PQueueWrapperData *p = (PQueueWrapperData*) data;

  p->pq->push(make_pair(priority,id));

  return HXT_STATUS_OK;
}


HXTStatus hxtPQueuePop(uint32_t *id, void *data)
{
  PQueueWrapperData *p = (PQueueWrapperData*) data;

  if (p->pq->empty()){
    *id = UINT32_MAX;
    return HXT_STATUS_OK; 
  }

  *id = p->pq->top().second;
  p->pq->pop(); 
  return HXT_STATUS_OK;
}

HXTStatus hxtPQueueTop(uint32_t *id, void *data)
{
  PQueueWrapperData *p = (PQueueWrapperData*) data;

  if (p->pq->empty()){
    *id = UINT32_MAX;
    return HXT_STATUS_OK; 
  }

  *id = p->pq->top().second;
  return HXT_STATUS_OK;
}


HXTStatus hxtPQueueIsEmpty(void *data, uint32_t *is)
{
  PQueueWrapperData *p = (PQueueWrapperData*) data;
  *is = p->pq->empty();
  return HXT_STATUS_OK;
}

HXTStatus hxtPQueueSize(void *data, uint32_t *size)
{ 
  PQueueWrapperData *p = (PQueueWrapperData*) data;

  priority_queue<pair<double,uint32_t>> pn = *p->pq;

  *size = p->pq->size();

  return HXT_STATUS_OK; 
}

HXTStatus hxtPQueueSizePrint(void *data)
{ 
  PQueueWrapperData *p = (PQueueWrapperData*) data;

  priority_queue<pair<double,uint32_t>> pn = *p->pq;

  printf("PQueue size = %lu \n", pn.size());

  return HXT_STATUS_OK; 
}



HXTStatus hxtPQueueShow(void *data)
{ 
  PQueueWrapperData *p = (PQueueWrapperData*) data;

  priority_queue<pair<double,uint32_t>> pn = *p->pq;

  while (!pn.empty())
  { 
    printf("%f %d \n", pn.top().first, pn.top().second);
    pn.pop();
  } 
  cout << '\n'; 

  return HXT_STATUS_OK; 
} 


