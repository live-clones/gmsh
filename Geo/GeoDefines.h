// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GEO_DEFINES_H_
#define _GEO_DEFINES_H_

// type/100 gives (dimension+1)
#define MSH_POINT              100
#define MSH_POINT_BND_LAYER    101
#define MSH_POINT_DISCRETE     102
#define MSH_POINT_FROM_GMODEL  103

#define MSH_SEGM_LINE          200
#define MSH_SEGM_SPLN          201
#define MSH_SEGM_CIRC          202
#define MSH_SEGM_CIRC_INV      203
#define MSH_SEGM_ELLI          204
#define MSH_SEGM_ELLI_INV      205
#define MSH_SEGM_LOOP          206
#define MSH_SEGM_BSPLN         207
#define MSH_SEGM_NURBS         208
#define MSH_SEGM_BEZIER        209
#define MSH_SEGM_BND_LAYER     211
#define MSH_SEGM_DISCRETE      212
#define MSH_SEGM_FROM_GMODEL   213
#define MSH_SEGM_COMPOUND      214

#define MSH_SURF_PLAN          300
#define MSH_SURF_REGL          301
#define MSH_SURF_TRIC          302
#define MSH_SURF_BND_LAYER     303
#define MSH_SURF_LOOP          304
#define MSH_SURF_DISCRETE      305
#define MSH_SURF_FROM_GMODEL   306
#define MSH_SURF_COMPOUND      307

#define MSH_VOLUME             400
#define MSH_VOLUME_DISCRETE    401
#define MSH_VOLUME_FROM_GMODEL 402
#define MSH_VOLUME_COMPOUND    403

#define MSH_PHYSICAL_POINT     500
#define MSH_PHYSICAL_LINE      501
#define MSH_PHYSICAL_SURFACE   502
#define MSH_PHYSICAL_VOLUME    503

#endif
