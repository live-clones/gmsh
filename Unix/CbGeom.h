/* $Id: CbGeom.h,v 1.2 2000-11-23 14:11:41 geuzaine Exp $ */
#ifndef _CB_GEOM_H_
#define _CB_GEOM_H_

/* geom event handler */

#define  GEOM_ELEM_ADD_NEW_PARAMETER         1
#define  GEOM_ELEM_ADD_NEW_POINT             2
#define  GEOM_ELEM_ADD_NEW_LINE              3
#define  GEOM_ELEM_ADD_NEW_SPLINE            4
#define  GEOM_ELEM_ADD_NEW_BEZIER            5
#define  GEOM_ELEM_ADD_NEW_BSPLINE           6
#define  GEOM_ELEM_ADD_NEW_CIRCLE            7
#define  GEOM_ELEM_ADD_NEW_ELLIPSIS          8
#define  GEOM_ELEM_ADD_NEW_PLANE_SURF        9
#define  GEOM_ELEM_ADD_NEW_RULED_SURF        10
#define  GEOM_ELEM_ADD_NEW_NURBS_SURF        11
#define  GEOM_ELEM_ADD_NEW_VOLUME            12
#define  GEOM_ELEM_ADD_TRANSLATE_POINT       13
#define  GEOM_ELEM_ADD_TRANSLATE_LINE        14
#define  GEOM_ELEM_ADD_TRANSLATE_SURF        15
#define  GEOM_ELEM_ADD_ROTATE_POINT          16
#define  GEOM_ELEM_ADD_ROTATE_LINE           17
#define  GEOM_ELEM_ADD_ROTATE_SURF           18
#define  GEOM_ELEM_ADD_DILATE_POINT          19
#define  GEOM_ELEM_ADD_DILATE_LINE           20
#define  GEOM_ELEM_ADD_DILATE_SURF           21
#define  GEOM_ELEM_MOVE_TRANSLATE_POINT      22
#define  GEOM_ELEM_MOVE_TRANSLATE_LINE       23
#define  GEOM_ELEM_MOVE_TRANSLATE_SURF       24
#define  GEOM_ELEM_MOVE_ROTATE_POINT         25
#define  GEOM_ELEM_MOVE_ROTATE_LINE          26
#define  GEOM_ELEM_MOVE_ROTATE_SURF          27
#define  GEOM_ELEM_MOVE_DILATE_POINT         28
#define  GEOM_ELEM_MOVE_DILATE_LINE          29
#define  GEOM_ELEM_MOVE_DILATE_SURF          30
#define  GEOM_ELEM_EXTRUDE_TRANSLATE_POINT   31
#define  GEOM_ELEM_EXTRUDE_TRANSLATE_LINE    32
#define  GEOM_ELEM_EXTRUDE_TRANSLATE_SURF    33
#define  GEOM_ELEM_EXTRUDE_ROTATE_POINT      34
#define  GEOM_ELEM_EXTRUDE_ROTATE_LINE       35
#define  GEOM_ELEM_EXTRUDE_ROTATE_SURF       36
#define  GEOM_ELEM_DELETE_POINT              37
#define  GEOM_ELEM_DELETE_LINE               38
#define  GEOM_ELEM_DELETE_SURF               39
#define  GEOM_ELEM_SKETCH                    40
#define  GEOM_PHYS_ADD_POINT                 41
#define  GEOM_PHYS_ADD_LINE                  42
#define  GEOM_PHYS_ADD_SURF                  43
#define  GEOM_PHYS_ADD_VOLUME                44
#define  GEOM_PHYS_DELETE_POINT              45
#define  GEOM_PHYS_DELETE_LINE               46
#define  GEOM_PHYS_DELETE_SURF               47
#define  GEOM_PHYS_DELETE_VOLUME             48
#define  GEOM_PARSE                          49

/* GeomCb */

#define  GEOM_PARAMETER_ADD                  1
#define  GEOM_PARAMETER_NAME                 2
#define  GEOM_PARAMETER_VALUE                3
#define  GEOM_POINT_ADD                      4
#define  GEOM_POINT_X                        5
#define  GEOM_POINT_Y                        6
#define  GEOM_POINT_Z                        7
#define  GEOM_POINT_L                        8
#define  GEOM_TRAN_X                         9
#define  GEOM_TRAN_Y                         10
#define  GEOM_TRAN_Z                         11
#define  GEOM_ROT_PX                         12
#define  GEOM_ROT_PY                         13
#define  GEOM_ROT_PZ                         14
#define  GEOM_ROT_AX                         15
#define  GEOM_ROT_AY                         16
#define  GEOM_ROT_AZ                         17
#define  GEOM_ROT_ANGLE                      18
#define  GEOM_DILAT_X                        19
#define  GEOM_DILAT_Y                        20
#define  GEOM_DILAT_Z                        21
#define  GEOM_DILAT_F                        22

void geom_event_handler (int event);

#endif
