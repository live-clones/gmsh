#ifndef _HEXTREME_API_H_
#define _HEXTREME_API_H_


#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

/* HEXTREME FUNCTIONS ONLY RETURN A STATUS (except hxtGetMessageString)*/
typedef enum
{
  // positive values mean a success         => HXT_CHECK does nothing for positive values
  HXT_STATUS_OK                    = 0,
  HXT_STATUS_TRUE                  = 0,
  HXT_STATUS_FALSE                 = 1,


  // ====== ERRORS
  // negatives values means errors

  // Fatal Errors                            => HXT_CHECK give trace message and return
  HXT_STATUS_ERROR                 = -1,
  HXT_STATUS_FAILED                = -2,
  HXT_STATUS_ASSERTION_FAILED      = -3,
  HXT_STATUS_OUT_OF_MEMORY         = -4,
  HXT_STATUS_FILE_CANNOT_BE_OPENED = -5,
  HXT_STATUS_POINTER_ERROR         = -6,
  HXT_STATUS_READ_ERROR            = -7,
  HXT_STATUS_WRITE_ERROR           = -8,
  HXT_STATUS_RANGE_ERROR           = -9,
  HXT_STATUS_FORMAT_ERROR          = -10,


  // INTERNAL Errors (<= HXT_STATUS_INTERNAL) => HXT_CHECK does not give trace message but returns... should be catched internally !
  HXT_STATUS_INTERNAL              = -1024,
  HXT_STATUS_CONFLICT              = -1025,
  HXT_STATUS_SKIP                  = -1026,
  HXT_STATUS_TRYAGAIN              = -1027


}HXTStatus;

typedef uint32_t HXTIndex;

const char*  hxtGetStatusString(HXTStatus status);


/* MESSAGE */
typedef struct {
  /* the message content */
  const char* string; // lifetime = time of callback function

  /* information about the location of the code which sent the message */
  const char* func;   // lifetime = forever
  const char* file;   // lifetime = forever
  const char* line;   // lifetime = forever
  int threadId;      // the thread which sent the message
  int numThreads;    // the number of threads

  enum{
    HXT_MSGLEVEL_INFO     = 0,
    HXT_MSGLEVEL_DEBUG    = 1,
    HXT_MSGLEVEL_WARNING  = 2,
    HXT_MSGLEVEL_ERROR    = 3,
    HXT_MSGLEVEL_TRACE    = 4
  } level;
} HXTMessage;


/* INITIALIZE STUFF, SETS GLOBAL PARAMETERS THROUGH COMMAND LINE*/
HXTStatus hxtInit(int argc, char **argv);
HXTStatus hxtFinalize(void);


/* A CONTEXT SIMILAR TO THE CONTEXT OF GMSH (OPTIONS & CO + MESSAGES) */
typedef struct hxtContextStruct HXTContext;
HXTStatus  hxtContextCreate               ( HXTContext** ctxtPtr);
HXTStatus  hxtContextDelete               ( HXTContext** ctxtPtr);


/* MESSAGE AND ERROR HANDLING */
HXTStatus  hxtSetMessageCallback (HXTStatus (*hxtMsgCallback)(HXTMessage* msg));



/* THE MESH OBJECT */
typedef struct hxtMeshStruct HXTMesh ;
HXTStatus  hxtMeshCreate          ( HXTContext* ctxt, HXTMesh** mesh);
HXTStatus  hxtMeshDelete          ( HXTMesh** meshPtr);
HXTStatus  hxtMeshReadGmsh       ( HXTMesh* mesh, const char* filename);
HXTStatus  hxtMeshWriteGmsh      ( HXTMesh* mesh, const char* filename);

/* THE MESH SIZE OBJECT */
typedef struct  hxtMeshSizeStruct HXTMeshSize;
typedef HXTStatus (*HXTMeshSizeCallback)(double x[3], void* data, double* s);
HXTStatus  hxtMeshSizeCreate     ( HXTContext* ctxt, HXTMeshSize** );
HXTStatus  hxtMeshSizeDelete     ( HXTMeshSize** );
HXTStatus  hxtMeshSizeCompute    ( HXTMeshSize* meshSize , double min[3], double max[3], HXTMeshSizeCallback cb, void *data);
HXTStatus  hxtMeshSizeEvaluate   ( HXTMeshSize* meshSize, double x[3], double* v);


/* SOME MESHING ROUTINES */
HXTStatus  hxtMeshTetrahedralize ( HXTMesh* mesh , HXTMeshSize* meshSize);
HXTStatus  hxtMeshOptimize       ( HXTMesh* mesh , HXTMeshSize* meshSize);

#ifdef __cplusplus
}
#endif

#endif
