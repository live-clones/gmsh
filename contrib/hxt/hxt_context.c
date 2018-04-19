#include <stdlib.h>
#include <stdio.h>
#include "hxt_tools.h"
#include "hxt_context.h"

HXTStatus hxtInit(int argc, char **argv) {
  return HXT_STATUS_OK;
}

HXTStatus  hxtContextCreate  ( HXTContext** ctxtPtr){
  HXT_CHECK( hxtMalloc (ctxtPtr, sizeof(HXTContext)) );
  return HXT_STATUS_OK;
}


HXTStatus  hxtContextDelete  ( HXTContext** ctxtPtr){
  HXT_CHECK( hxtFree(ctxtPtr) );
  return HXT_STATUS_OK;
}