#ifndef _CB_MESH_H_
#define _CB_MESH_H_

/* mesh event handler */
					     
#define  MESH_DELETE                         1
#define  MESH_1D                             2
#define  MESH_2D                             3 
#define  MESH_3D                             4
#define  MESH_DEFINE_CHAR_LENGTH             5
#define  MESH_DEFINE_TRSF_LINE               6
#define  MESH_DEFINE_TRSF_SURFACE            7
#define  MESH_DEFINE_TRSF_VOLUME             8
#define  MESH_DEFINE_RECOMBINE               9
#define  MESH_DEFINE_ATTRACTOR_POINT         10
#define  MESH_DEFINE_ATTRACTOR_LINE          11
#define  MESH_DEFINE_ATTRACTOR_SURFACE       12

/* MeshCb */

#define  MESH_TRSF_LINE_PTS                  100
#define  MESH_TRSF_LINE_TYPE                 101
#define  MESH_TRSF_VOL_NUM                   102
#define  MESH_CHAR_LENGTH                    103
#define  MESH_ATTRACTOR_X                    104
#define  MESH_ATTRACTOR_Y                    105
#define  MESH_ATTRACTOR_Z                    106

void CancelMeshThread(void);
void mesh_event_handler (int event);
					     
#endif
