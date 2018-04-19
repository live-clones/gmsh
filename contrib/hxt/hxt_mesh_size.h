#ifndef _HXT_MESH_SIZE_H_
#define _HXT_MESH_SIZE_H_

#include "hxt_api.h"

typedef struct {
  void *data;
  int isleaf;
} HXTMeshSizeCell;

struct hxtMeshSizeStruct {
  HXTMeshSizeCell root;
  double bbmin[3], bbmax[3];
  double l0;
  HXTContext* context;
};

#endif
