// Hxt - Copyright (C)
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "HXTSPR.h"
#include "hxt_tetOptiUtils.h"
#include "hxt_tetFlag.h"
#include "predicates.h"


#ifdef _MSC_VER
#define SPRNOINLINE __declspec(noinline)
#else
#define SPRNOINLINE __attribute__ ((noinline))
#endif

// get the index in a tet. of node i from facet j by doing nodeFromFacet[i][j];
static const int nodeFromFacet[3][4] = {{1, 2, 3, 0 },
                                        {3, 3, 1, 1 },
                                        {2, 0, 0, 2 }};

static inline void add_face_map(SPRCavity* SPR,
                                unsigned v0,
                                unsigned v1,
                                unsigned v2,
                                uint16_t index)
{
  SPR->map.faces[v0*(SPR_MAX_PTS*SPR_MAX_PTS)+v1*SPR_MAX_PTS+v2] = index;
  SPR->map.faces[v1*(SPR_MAX_PTS*SPR_MAX_PTS)+v2*SPR_MAX_PTS+v0] = index;
  SPR->map.faces[v2*(SPR_MAX_PTS*SPR_MAX_PTS)+v0*SPR_MAX_PTS+v1] = index;
}

static inline void remove_face_map(SPRCavity* SPR,
                                   unsigned v0,
                                   unsigned v1,
                                   unsigned v2)
{
  add_face_map(SPR, v0, v1, v2, UINT16_MAX);
}

static inline uint16_t get_face_map(SPRCavity* SPR,
                                    unsigned v0,
                                    unsigned v1,
                                    unsigned v2) {
  return SPR->map.faces[v0*(SPR_MAX_PTS*SPR_MAX_PTS) + v1*SPR_MAX_PTS + v2];
}


static inline void decrement_3valences(SPRCavity* SPR,
                                       uint8_t v0,
                                       uint8_t v1,
                                       uint8_t v2) {
  SPR->points.array[v0].valence--;
  SPR->points.array[v1].valence--;
  SPR->points.array[v2].valence--;
}


static inline void increment_3valences(SPRCavity* SPR,
                                       uint8_t v0,
                                       uint8_t v1,
                                       uint8_t v2) {
  SPR->points.array[v0].valence++;
  SPR->points.array[v1].valence++;
  SPR->points.array[v2].valence++;
}


static inline unsigned get_compressed_index(unsigned v0,
                                            unsigned v1,
                                            unsigned v2,
                                            unsigned v3)
{
#define SPRSWAP(x,y) if(x>y){unsigned tmp=x; x=y; y=tmp;}
  SPRSWAP(v0,v1)
  SPRSWAP(v2,v3)
  SPRSWAP(v0,v2)
  SPRSWAP(v1,v3)
  SPRSWAP(v1,v2)
#undef SPRSWAP

  unsigned aux = v3*(v3-3);
  return v0 + (v1*(v1-1)>>1) + v2*(v2-1)*(v2-2)/6 + aux*(aux+2)/24;
  // *index = v0 + v1*(v1-1)/2 + v2*(v2-1)*(v2-2)/6 + v3*(v3-1)*(v3-2)*(v3-3)/24;
}

#ifdef SPR_SAVE_ORIENT3D
static SPRNOINLINE uint32_t add_orient3d(SPRCavity* SPR,
                                         unsigned v0,
                                         unsigned v1,
                                         unsigned v2,
                                         unsigned v3)
{
  const unsigned config[12][4] = {
    {0, 1, 2, 3},{0, 2, 3, 1},{0, 3, 1, 2},
    {1, 2, 0, 3},{1, 0, 3, 2},{1, 3, 2, 0},
    {2, 3, 0, 1},{2, 0, 1, 3},{2, 1, 3, 0},
    {3, 1, 0, 2},{3, 0, 2, 1},{3, 2, 1, 0}
  };

  const unsigned v[4] = {v0, v1, v2, v3};

  // compute the orientation
  double orientation = orient3d(SPR->points.array[v0].coord,
                                SPR->points.array[v1].coord,
                                SPR->points.array[v2].coord,
                                SPR->points.array[v3].coord);

  uint32_t val = 2 + (orientation>0.0) - (orientation<0.0);
  uint32_t oppval = 2 + (orientation<0.0) - (orientation>0.0);
  const unsigned n1 = SPR_MAX_PTS;
  const unsigned n2 = SPR_MAX_PTS*SPR_MAX_PTS;
  const unsigned n3 = n2*n1;
  unsigned ID, index, bit;
  for (int i=0; i<12; i++)
  {
    v0 = v[config[i][0]];
    v1 = v[config[i][1]];
    v2 = v[config[i][2]];
    v3 = v[config[i][3]];

    ID = v0*n3+v1*n2+v2*n1+v3;
    index = ID/16;
    bit = ID%16 * 2;
    SPR->map.orient3d[index] &= ~(3U<<bit); // clear bits
    SPR->map.orient3d[index] |= val<<bit; // set bits

    ID = v0*n3+v1*n2+v3*n1+v2;
    index = ID/16;
    bit = ID%16 * 2;
    SPR->map.orient3d[index] &= ~(3U<<bit); // clear bits
    SPR->map.orient3d[index] |= oppval<<bit; // set bits
  }

  return val;
}

static int get_orient3d(SPRCavity* SPR,
                        unsigned v0,
                        unsigned v1,
                        unsigned v2,
                        unsigned v3)
{
  if(v0==v1 || v0==v2 || v0==v3 || v1==v2 || v1==v3 || v2==v3)
    return 0;
  const unsigned n = SPR_MAX_PTS;
  unsigned ID = v0*(n*n*n)+v1*(n*n)+v2*n+v3;
  unsigned index = ID/16;
  unsigned bit = ID%16 * 2;
  uint32_t val = SPR->map.orient3d[index]>>bit & 3;
  if(val==0) {
    return (int)add_orient3d(SPR, v0, v1, v2 ,v3) - 2;
  }
  else {
    return (int)val - 2;
  }
}

#else
static int get_orient3d(SPRCavity* SPR,
                        unsigned v0,
                        unsigned v1,
                        unsigned v2,
                        unsigned v3)
{

  if(v0==v1 || v0==v2 || v0==v3 || v1==v2 || v1==v3 || v2==v3)
    return 0;

  return orient3d_inline(SPR->points.array[v0].coord,
                         SPR->points.array[v1].coord,
                         SPR->points.array[v2].coord,
                         SPR->points.array[v3].coord);
}
#endif


// triangle-edge intersection following orient3ds
// !! the case where v0 or v1 lie on the triangle
// must be checked independently !!
static inline int tri_edge_intersection(int t012v0,
                                        int t012v1,
                                        int t01v01,
                                        int t12v01,
                                        int t20v01)
{
  return t012v0*t012v1<0 &&
         t012v0*t01v01<=0 &&
         t012v0*t12v01<=0 &&
         t012v0*t20v01<=0;
}

static inline int tet_tri_intersection(SPRCavity* SPR,
                                       HXTBbox* tetBbox,
                                       uint8_t tet[4],
                                       uint8_t* tri)
{
  HXTBbox triangleBbox;
  hxtBboxFrom(&triangleBbox, SPR->points.array[tri[0]].coord);
  hxtBboxAddOne(&triangleBbox, SPR->points.array[tri[1]].coord);
  hxtBboxAddOne(&triangleBbox, SPR->points.array[tri[2]].coord);
  hxtBboxAddOne(&triangleBbox, SPR->points.array[tri[3]].coord);
  if(hxtBboxesIntersect(tetBbox, &triangleBbox)==0)
    return 0;

#ifndef NDEBUG
  int v = get_orient3d(SPR, tet[0], tet[1], tet[2], tet[3]);
  if(v>=0) {
    HXT_TRACE_MSG(HXT_STATUS_ERROR, "Fatal Error: degenerated tetrahedron created %d\n",v);
    exit(EXIT_FAILURE);
  }
#endif

  int tri0_to_tet = -1;
  int tri1_to_tet = -1;
  int tri2_to_tet = -1;

  int tet0_to_tri = -1;
  int tet1_to_tri = -1;
  int tet2_to_tri = -1;
  int tet3_to_tri = -1;

  if(tri[0]==tet[0]){
    tri0_to_tet = 0;
    tet0_to_tri = 0;
  }
  else if(tri[0]==tet[1]){
    tri0_to_tet = 1;
    tet1_to_tri = 0;
  }
  else if(tri[0]==tet[2]){
    tri0_to_tet = 2;
    tet2_to_tri = 0;
  }
  else if(tri[0]==tet[3]){
    tri0_to_tet = 3;
    tet3_to_tri = 0;
  }

  if(tri[1]==tet[0]){
    tri1_to_tet = 0;
    tet0_to_tri = 1;
  }
  else if(tri[1]==tet[1]){
    tri1_to_tet = 1;
    tet1_to_tri = 1;
  }
  else if(tri[1]==tet[2]){
    tri1_to_tet = 2;
    tet2_to_tri = 1;
  }
  else if(tri[1]==tet[3]){
    tri1_to_tet = 3;
    tet3_to_tri = 1;
  }

  if(tri[2]==tet[0]){
    tri2_to_tet = 0;
    tet0_to_tri = 2;
  }
  else if(tri[2]==tet[1]){
    tri2_to_tet = 1;
    tet1_to_tri = 2;
  }
  else if(tri[2]==tet[2]){
    tri2_to_tet = 2;
    tet2_to_tri = 2;
  }
  else if(tri[2]==tet[3]){
    tri2_to_tet = 3;
    tet3_to_tri = 2;
  }

  if(tri0_to_tet!=-1 && tri1_to_tet!=-1 && tri2_to_tet!=-1) // the triangle is there
    return 0;

  int f0v0 = get_orient3d(SPR, tri[0], tet[1], tet[2], tet[3]);
  int f0v1 = get_orient3d(SPR, tri[1], tet[1], tet[2], tet[3]);
  int f0v2 = get_orient3d(SPR, tri[2], tet[1], tet[2], tet[3]);

  // if the triangle is entirely on one side of the tet: no intersection
  if((f0v0 > 0 || (f0v0==0 && tri0_to_tet!=-1)) &&
     (f0v1 > 0 || (f0v1==0 && tri1_to_tet!=-1)) &&
     (f0v2 > 0 || (f0v2==0 && tri2_to_tet!=-1)) )
    return 0;

  int f1v0 = get_orient3d(SPR, tet[0], tri[0], tet[2], tet[3]);
  int f1v1 = get_orient3d(SPR, tet[0], tri[1], tet[2], tet[3]);
  int f1v2 = get_orient3d(SPR, tet[0], tri[2], tet[2], tet[3]);

  // we repeat that with the 3 other faces
  if((f1v0 > 0 || (f1v0==0 && tri0_to_tet!=-1)) &&
     (f1v1 > 0 || (f1v1==0 && tri1_to_tet!=-1)) &&
     (f1v2 > 0 || (f1v2==0 && tri2_to_tet!=-1)) )
    return 0;

  int f2v0 = get_orient3d(SPR, tet[0], tet[1], tri[0], tet[3]);
  int f2v1 = get_orient3d(SPR, tet[0], tet[1], tri[1], tet[3]);
  int f2v2 = get_orient3d(SPR, tet[0], tet[1], tri[2], tet[3]);

  if((f2v0 > 0 || (f2v0==0 && tri0_to_tet!=-1)) &&
     (f2v1 > 0 || (f2v1==0 && tri1_to_tet!=-1)) &&
     (f2v2 > 0 || (f2v2==0 && tri2_to_tet!=-1)) )
     return 0;

  int f3v0 = get_orient3d(SPR, tet[0], tet[1], tet[2], tri[0]);
  int f3v1 = get_orient3d(SPR, tet[0], tet[1], tet[2], tri[1]);
  int f3v2 = get_orient3d(SPR, tet[0], tet[1], tet[2], tri[2]);

  if((f3v0 > 0 || (f3v0==0 && tri0_to_tet!=-1)) &&
     (f3v1 > 0 || (f3v1==0 && tri1_to_tet!=-1)) &&
     (f3v2 > 0 || (f3v2==0 && tri2_to_tet!=-1)) )
     return 0;

  // if a point is inside but is not a point of the tet: intersection
  if( (tri0_to_tet==-1 && f0v0<=0 && f1v0<=0 && f2v0<=0 && f3v0<=0) ||
      (tri1_to_tet==-1 && f0v1<=0 && f1v1<=0 && f2v1<=0 && f3v1<=0) ||
      (tri2_to_tet==-1 && f0v2<=0 && f1v2<=0 && f2v2<=0 && f3v2<=0) )
    return 1;

  int v0f = get_orient3d(SPR, tet[0], tri[0], tri[1], tri[2]);
  int v1f = get_orient3d(SPR, tet[1], tri[0], tri[1], tri[2]);
  int v2f = get_orient3d(SPR, tet[2], tri[0], tri[1], tri[2]);
  int v3f = get_orient3d(SPR, tet[3], tri[0], tri[1], tri[2]);

  // if the tet is entirely on one side of the triangle: no intersection
  if(v0f > 0 && v1f > 0 && v2f > 0 && v3f > 0)
    return 0;

  if(v0f < 0 && v1f < 0 && v2f < 0 && v3f < 0)
    return 0;

  // now we want to know if an edge of the triangle pierce a facet or not
  int e0e0, e1e0, e2e0, e3e0, e4e0, e5e0;
  int e0e1, e1e1, e2e1, e3e1, e4e1, e5e1;
  int e0e2, e1e2, e2e2, e3e2, e4e2, e5e2;

  e0e0 = get_orient3d(SPR, tet[0], tet[1], tri[0], tri[1]);
  e1e0 = get_orient3d(SPR, tet[0], tet[2], tri[0], tri[1]);
  e2e0 = get_orient3d(SPR, tet[0], tet[3], tri[0], tri[1]);
  e3e0 = get_orient3d(SPR, tet[1], tet[2], tri[0], tri[1]);
  e4e0 = get_orient3d(SPR, tet[1], tet[3], tri[0], tri[1]);
  e5e0 = get_orient3d(SPR, tet[2], tet[3], tri[0], tri[1]);

  // if a point of the edge is coplanar with the facet of
  // the tet, we don't really care trying to check the intersection
  // between the edge and this facet. Indeed:
  // - if the whole line is coplanar to the facet and intersects it,
  // it will intersect another facet
  // - if only one point is coplanar to the facet, it must be on the
  // triangle to intersect it. That case is detected earlier anyway
  if( tri_edge_intersection( f0v0,  f0v1, -e3e0, -e5e0,  e4e0)
   || tri_edge_intersection( f1v0,  f1v1, -e2e0,  e5e0,  e1e0)
   || tri_edge_intersection( f2v0,  f2v1, -e0e0, -e4e0,  e2e0)
   || tri_edge_intersection( f3v0,  f3v1, -e1e0,  e3e0,  e0e0))
    return 1;


  e0e1 = get_orient3d(SPR, tet[0], tet[1], tri[1], tri[2]);
  e1e1 = get_orient3d(SPR, tet[0], tet[2], tri[1], tri[2]);
  e2e1 = get_orient3d(SPR, tet[0], tet[3], tri[1], tri[2]);
  e3e1 = get_orient3d(SPR, tet[1], tet[2], tri[1], tri[2]);
  e4e1 = get_orient3d(SPR, tet[1], tet[3], tri[1], tri[2]);
  e5e1 = get_orient3d(SPR, tet[2], tet[3], tri[1], tri[2]);

  if( tri_edge_intersection( f0v1,  f0v2, -e3e1, -e5e1,  e4e1)
   || tri_edge_intersection( f1v1,  f1v2, -e2e1,  e5e1,  e1e1)
   || tri_edge_intersection( f2v1,  f2v2, -e0e1, -e4e1,  e2e1)
   || tri_edge_intersection( f3v1,  f3v2, -e1e1,  e3e1,  e0e1))
    return 1;

  e0e2 = get_orient3d(SPR, tet[0], tet[1], tri[2], tri[0]);
  e1e2 = get_orient3d(SPR, tet[0], tet[2], tri[2], tri[0]);
  e2e2 = get_orient3d(SPR, tet[0], tet[3], tri[2], tri[0]);
  e3e2 = get_orient3d(SPR, tet[1], tet[2], tri[2], tri[0]);
  e4e2 = get_orient3d(SPR, tet[1], tet[3], tri[2], tri[0]);
  e5e2 = get_orient3d(SPR, tet[2], tet[3], tri[2], tri[0]);

  if( tri_edge_intersection( f0v2,  f0v0, -e3e2, -e5e2,  e4e2)
   || tri_edge_intersection( f1v2,  f1v0, -e2e2,  e5e2,  e1e2)
   || tri_edge_intersection( f2v2,  f2v0, -e0e2, -e4e2,  e2e2)
   || tri_edge_intersection( f3v2,  f3v0, -e1e2,  e3e2,  e0e2))
    return 1;

  // now we want to know if an edge of the tetrahedron pierce the triangle or not
  // if v0f or v1f or v2f or v3f is 0 and an edge that is coplanar to the triangle
  // intersects it, then another edge should also intersect. (2nd nice property of tet :p)
  if( (tet0_to_tri==-1 && tet1_to_tri==-1 && tri_edge_intersection(v0f==0?v1f:-v0f, -v1f, e0e0, e0e1, e0e2))
   || (tet0_to_tri==-1 && tet2_to_tri==-1 && tri_edge_intersection(v0f==0?v2f:-v0f, -v2f, e1e0, e1e1, e1e2))
   || (tet0_to_tri==-1 && tet3_to_tri==-1 && tri_edge_intersection(v0f==0?v3f:-v0f, -v3f, e2e0, e2e1, e2e2))
   || (tet1_to_tri==-1 && tet2_to_tri==-1 && tri_edge_intersection(v1f==0?v2f:-v1f, -v2f, e3e0, e3e1, e3e2))
   || (tet1_to_tri==-1 && tet3_to_tri==-1 && tri_edge_intersection(v1f==0?v3f:-v1f, -v3f, e4e0, e4e1, e4e2))
   || (tet2_to_tri==-1 && tet3_to_tri==-1 && tri_edge_intersection(v2f==0?v3f:-v2f, -v3f, e5e0, e5e1, e5e2))
    )
    return 1;

  return 0;
}


static SPRNOINLINE int tet_edge_intersection(SPRCavity* SPR,
                                             HXTBbox* tetBbox,
                                             uint8_t tet[4],
                                             uint8_t* edge)
{
  double* l0 = SPR->points.array[edge[0]].coord;
  double* l1 = SPR->points.array[edge[1]].coord;
  if((tetBbox->max[0]<l0[0] && tetBbox->max[0]<l1[0]) ||
     (tetBbox->max[1]<l0[1] && tetBbox->max[1]<l1[1]) ||
     (tetBbox->max[2]<l0[2] && tetBbox->max[2]<l1[2]) ||
     (tetBbox->min[0]>l0[0] && tetBbox->min[0]>l1[0]) ||
     (tetBbox->min[1]>l0[1] && tetBbox->min[1]>l1[1]) ||
     (tetBbox->min[2]>l0[2] && tetBbox->min[2]>l1[2]) )
    return 0;

  int l0_to_tet = -1;
  int l1_to_tet = -1;

  if(edge[0]==tet[0]){
    l0_to_tet = 0;
  }
  else if(edge[0]==tet[1]){
    l0_to_tet = 1;
  }
  else if(edge[0]==tet[2]){
    l0_to_tet = 2;
  }
  else if(edge[0]==tet[3]){
    l0_to_tet = 3;
  }

  if(edge[1]==tet[0]){
    l1_to_tet = 0;
  }
  else if(edge[1]==tet[1]){
    l1_to_tet = 1;
  }
  else if(edge[1]==tet[2]){
    l1_to_tet = 2;
  }
  else if(edge[1]==tet[3]){
    l1_to_tet = 3;
  }

  if(l0_to_tet!=-1 && l1_to_tet!=-1) // the line is there: no intersection
    return 0;

  int f0v0 = get_orient3d(SPR, edge[0], tet[1], tet[2], tet[3]);
  int f0v1 = get_orient3d(SPR, edge[1], tet[1], tet[2], tet[3]);

  // if the triangle is entirely on one side of the tet: no intersection
  if((f0v0 > 0 || (f0v0==0 && l0_to_tet!=-1)) &&
     (f0v1 > 0 || (f0v1==0 && l1_to_tet!=-1)) )
    return 0;

  int f1v0 = get_orient3d(SPR, tet[0], edge[0], tet[2], tet[3]);
  int f1v1 = get_orient3d(SPR, tet[0], edge[1], tet[2], tet[3]);

  if((f1v0 > 0 || (f1v0==0 && l0_to_tet!=-1)) &&
     (f1v1 > 0 || (f1v1==0 && l1_to_tet!=-1)) )
    return 0;

  int f2v0 = get_orient3d(SPR, tet[0], tet[1], edge[0], tet[3]);
  int f2v1 = get_orient3d(SPR, tet[0], tet[1], edge[1], tet[3]);

  if((f2v0 > 0 || (f2v0==0 && l0_to_tet!=-1)) &&
     (f2v1 > 0 || (f2v1==0 && l1_to_tet!=-1)) )
    return 0;

  int f3v0 = get_orient3d(SPR, tet[0], tet[1], tet[2], edge[0]);
  int f3v1 = get_orient3d(SPR, tet[0], tet[1], tet[2], edge[1]);

  if((f3v0 > 0 || (f3v0==0 && l0_to_tet!=-1)) &&
     (f3v1 > 0 || (f3v1==0 && l1_to_tet!=-1)) )
    return 0;

  // if a point is inside but is not a point of the tet: intersection
  if( (l0_to_tet==-1 && f0v0<=0 && f1v0<=0 && f2v0<=0 && f3v0<=0) ||
      (l1_to_tet==-1 && f0v1<=0 && f1v1<=0 && f2v1<=0 && f3v1<=0) )
    return 1;

  // now, we know that a point in the plane of a triangle is never
  // in the triangle, so we can conclude a little bit more
  if((f0v0 == 0 && f0v1 > 0) || (f0v1 == 0 && f0v0 > 0) ||
     (f1v0 == 0 && f1v1 > 0) || (f1v1 == 0 && f1v0 > 0) ||
     (f2v0 == 0 && f2v1 > 0) || (f2v1 == 0 && f2v0 > 0) ||
     (f3v0 == 0 && f3v1 > 0) || (f3v1 == 0 && f3v0 > 0))
    return 0;

  // the line with each edge of the tetrahedra
  int c0 = get_orient3d(SPR, tet[0], tet[1], edge[0], edge[1]);
  int c1 = get_orient3d(SPR, tet[0], tet[2], edge[0], edge[1]);
  int c2 = get_orient3d(SPR, tet[0], tet[3], edge[0], edge[1]);
  int c3 = get_orient3d(SPR, tet[1], tet[2], edge[0], edge[1]);
  int c4 = get_orient3d(SPR, tet[1], tet[3], edge[0], edge[1]);
  int c5 = get_orient3d(SPR, tet[2], tet[3], edge[0], edge[1]);

  // if one point of the edge is coplanar with the facet of
  // the tet, we don't really care trying to check the intersection
  // between the edge and this facet.
  // If the point is on the facet, it would have been detected earlier
  // If the line is coplanar to the facet and intersects it,
  // it will intersect another facet (1st nice property of tets :p)
  if( tri_edge_intersection( f0v0,  f0v1,-c3, -c5,  c4)
   || tri_edge_intersection( f1v0,  f1v1,-c2,  c5,  c1)
   || tri_edge_intersection( f2v0,  f2v1,-c0, -c4,  c2)
   || tri_edge_intersection( f3v0,  f3v1,-c1,  c3,  c0) )
    return 1;

  return 0;
}


static int tet_contains_pt(SPRCavity* SPR,
                           HXTBbox* tetBbox,
                           uint8_t tet[4],
                           unsigned pt) {
  double* pt_coord = SPR->points.array[pt].coord;

  if(pt==tet[0] || pt==tet[1] || pt==tet[2] || pt==tet[3] ||
     pt_coord[0] < tetBbox->min[0] ||
     pt_coord[1] < tetBbox->min[1] ||
     pt_coord[2] < tetBbox->min[2] ||
     pt_coord[0] > tetBbox->max[0] ||
     pt_coord[1] > tetBbox->max[1] ||
     pt_coord[2] > tetBbox->max[2] ||
     get_orient3d(SPR, tet[1], tet[3], tet[2], pt)>0 ||
     get_orient3d(SPR, tet[2], tet[3], tet[0], pt)>0 ||
     get_orient3d(SPR, tet[3], tet[1], tet[0], pt)>0 ||
     get_orient3d(SPR, tet[0], tet[1], tet[2], pt)>0)
    return 0;

  return 1;
}

static SPRNOINLINE double add_quality_map(SPRCavity* SPR,
                                         unsigned v0,
                                         unsigned v1,
                                         unsigned v2,
                                         unsigned v3,
                                         unsigned index)
{
  double* c0 = SPR->points.array[v0].coord;
  double* c1 = SPR->points.array[v1].coord;
  double* c2 = SPR->points.array[v2].coord;
  double* c3 = SPR->points.array[v3].coord;
  double qual = SPR->quality.function(c0, c1, c2, c3,
                                 SPR->quality.userData);

  if(qual<0.0) {
    HXT_WARNING("negative quality with correct orientation\n");
    qual = DBL_MIN;
  }

  SPR->map.qualities[index] = qual;

  return qual;
}


static double get_quality_map(SPRCavity* SPR,
                              unsigned v0,
                              unsigned v1,
                              unsigned v2,
                              unsigned v3,
                              unsigned* index_ptr)
{
  int orientation = get_orient3d(SPR, v0, v1, v2, v3);
  if(orientation >= 0.0)
    return -DBL_MAX;

  unsigned index = get_compressed_index(v0, v1, v2, v3);
  if(index_ptr!=NULL)
    *index_ptr = index;

  double qual = SPR->map.qualities[index];

  if(!isnan(qual)) {
    return qual;
  }
  else if(SPR->quality.function==NULL) {
      return DBL_MAX;
  }
  else {
    return add_quality_map(SPR, v0, v1, v2, v3,
                           index);
  }
}


/* Compute the worst face (the face that we should begin with)
 * and the minimum value among all maximum quality we can
 * get from a face. This value is an estimation for the quality
 * that the best tetrahedralization could have */
static inline uint16_t best_face_heuristic(SPRCavity* SPR, double* qualMax)
{
  const uint16_t nfaces = SPR->bndTriangles.num;

  const uint8_t npts = SPR->points.num;
  int minValid = 255;
  uint16_t worstFaceID = UINT16_MAX;
  double minimax = DBL_MAX;

  // new faces have a better chances of being bad, that why we decrement
  for (uint16_t i=nfaces; i>0; i--) {
    uint16_t triangleID = i-1;
    SPRTet tet = SPR->bndTriangles.array[triangleID];

    int numValid = 0;
    double max = 0.0;

    for (tet.node[3]=0; tet.node[3] < npts && numValid < minValid; tet.node[3]++)
    {
      if(tet.node[3] == tet.node[0] ||
         tet.node[3] == tet.node[1] ||
         tet.node[3] == tet.node[2] ||
         SPR->points.array[tet.node[3]].valence==0)
        continue;

      double qual = get_quality_map(SPR,
                                    tet.node[0],
                                    tet.node[1],
                                    tet.node[2],
                                    tet.node[3], NULL);
      if(qual<=SPR->tetrahedra.quality)
        continue;

      if(qual>max)
        max = qual;

      numValid++;
    }

    if(numValid == 0)
      return UINT16_MAX;

    if(max < minimax)
      minimax = max;

    if(numValid < minValid) {
      minValid = numValid;
      worstFaceID = triangleID;
    }
  }

  *qualMax = minimax;
  return worstFaceID;
}


static inline void compute_candidates(SPRCavity* SPR,
                                      SPRStep* step,
                                      double qualMax)
{
  const int nPts = SPR->points.num;

  SPRTet* tet = &step->tet;
  uint8_t num = 0;

  uint8_t score[SPR_MAX_PTS];
  uint8_t candidate[SPR_MAX_PTS];

  for (tet->node[3]=0; tet->node[3]<nPts; tet->node[3]++)
  {
    if(tet->node[3] == tet->node[0] ||
       tet->node[3] == tet->node[1] ||
       tet->node[3] == tet->node[2] ||
       SPR->points.array[tet->node[3]].valence==0)
      continue;

    double qual = get_quality_map(SPR, tet->node[0],
                                       tet->node[1],
                                       tet->node[2],
                                       tet->node[3], NULL);
    if(qual<=SPR->tetrahedra.quality)
      continue;

    // those heuristics can be changed in many way
    // if you have some theory validating some choice,
    // you can give a higher/lower score depending on
    //  - valence of points
    //  - ...
    uint8_t curScore = 0;

    // big bonus if the point is an interior point
    if(SPR->points.array[tet->node[3]].is_interior)
      curScore += 4;

    // bonus if you don't degrade partial cavity
    if(qual > step->quality)
      curScore+=2;
    else if(qual == step->quality)
      curScore+=1;

    // bonus if you don't degrade the best quality we can hope for...
    if(qual > qualMax)
      curScore+=2;
    else if(qual == qualMax)
      curScore+=1;

    // bonus if the point is in an adjacent triangle
    for (int f=0; f<3; f++) {
      uint8_t p0 = tet->node[nodeFromFacet[0][f]];
      uint8_t p1 = tet->node[nodeFromFacet[1][f]];
      uint8_t p2 = tet->node[nodeFromFacet[2][f]];

      if(get_face_map(SPR, p0, p1, p2)!=UINT16_MAX)
        curScore+=2;
    }

    // the maximum score is 4+2+2+3*2 = 14

    candidate[num] = tet->node[3];
    score[num] = curScore;
    num++;
  }

  // simple radix sort pass
  uint8_t count[16] = {0};
  for (uint8_t i=0; i<num; i++) {
    count[score[i]]++;
  }

  uint8_t sum = 0;
  for (int i=0; i<16; i++) {
    uint8_t tsum = sum + count[i];
    count[i] = sum;
    sum = tsum;
  }

  HXT_ASSERT(sum==num);

  for (uint8_t i=0; i<num; i++) {
    step->candidate[count[score[i]]++] = candidate[i];
  }

  step->numCandidates=num;
}



static void add_face(SPRCavity* SPR,
                     uint8_t v0,
                     uint8_t v1,
                     uint8_t v2)
{
  SPR->bndTriangles.array[SPR->bndTriangles.num].node[0] = v0;
  SPR->bndTriangles.array[SPR->bndTriangles.num].node[1] = v1;
  SPR->bndTriangles.array[SPR->bndTriangles.num].node[2] = v2;
  SPR->bndTriangles.array[SPR->bndTriangles.num].node[3] = v0;
  add_face_map(SPR, v0, v1, v2, SPR->bndTriangles.num);
  increment_3valences(SPR, v0, v1, v2);
  SPR->bndTriangles.num++;
}

static void remove_face(SPRCavity* SPR, uint16_t triangleID)
{
  SPRTriangle* del = &SPR->bndTriangles.array[triangleID];
  remove_face_map(SPR, del->node[0], del->node[1], del->node[2]);
  decrement_3valences(SPR, del->node[0], del->node[1], del->node[2]);

  if(triangleID!=SPR->bndTriangles.num-1) {
    SPRTriangle* last = &SPR->bndTriangles.array[SPR->bndTriangles.num-1];
    add_face_map(SPR, last->node[0], last->node[1], last->node[2], triangleID);
    *del = *last;
  }

  SPR->bndTriangles.num--;
}

static inline void new_tetrahedralization(SPRCavity* SPR, SPRStep* step)
{

  HXT_ASSERT(step->numCandidates<0);
  HXT_ASSERT(step->quality > SPR->tetrahedra.quality);
#ifndef NDEBUG
  for (int i=0; i<SPR->points.num; i++) {
    if(SPR->points.array[i].is_interior && SPR->points.array[i].valence!=1){
      HXT_TRACE_MSG(HXT_STATUS_ERROR, "DEBUG: This should never happen... valence!=1 for interior point %u\n", i);
      exit(EXIT_FAILURE);
    }
    else if(!SPR->points.array[i].is_interior && SPR->points.array[i].valence!=0) {
      HXT_TRACE_MSG(HXT_STATUS_ERROR, "DEBUG: This should never happen... valence!=0 for boundary point %u\n", i);
      exit(EXIT_FAILURE);
    }
  }
#endif

  SPR->tetrahedra.quality = step->quality;

  for (int i=0; i<SPR->steps.num; i++) {
    SPR->tetrahedra.array[i] = SPR->steps.array[i].tet;
  }
  SPR->tetrahedra.num = SPR->steps.num;
}


/***************************
 * Initialization
 ***************************/
static void SPR_clear_maps(SPRCavity* SPR)
{
  { // initializing map.face
    size_t face_len = sizeof(SPR->map.faces)/sizeof(uint16_t);

    // compiler should replace this by a memset (UINT16_MAX is all ones)
    for (size_t i=0; i<face_len; i++) {
      SPR->map.faces[i] = UINT16_MAX;
    }
  }

  { // initializing map.qualities
    size_t qual_len = sizeof(SPR->map.qualities)/sizeof(double);

    // compiler should also replace this by a memset (NAN is all ones)
    for (size_t i=0; i<qual_len; i++) {
      SPR->map.qualities[i] = NAN;
    }
  }

#ifdef SPR_SAVE_ORIENT3D
  { // allocating & setting to zero map.orient3d
    size_t ori_len = sizeof(SPR->map.orient3d)/sizeof(uint32_t);

    // compiler should also replace this by a memset
    for (size_t i=0; i<ori_len; i++) {
      SPR->map.orient3d[i] = 0;
    }
  }
#endif
}


static void SPR_detect_interior_points(SPRCavity* SPR)
{
  for (int i=0; i<SPR->points.num; i++) {
    if(SPR->points.array[i].valence==0) {
      SPR->points.array[i].is_interior = 1;

      /* interior points should have a positive valence */
      SPR->points.array[i].valence = 1;
    }
  }
}

static void SPR_init_faceMap_and_valences(SPRCavity* SPR)
{
  for (int i=0; i<SPR->points.num; i++) {
    SPRPoint* p = &SPR->points.array[i];
    p->valence = 0;
    p->is_interior = 0;
  }

  for (uint16_t i=0; i<SPR->bndTriangles.num; i++) {
    uint8_t* v = SPR->bndTriangles.array[i].node;
    v[3] = v[0];
    increment_3valences(SPR, v[0], v[1], v[2]);
    add_face_map(SPR, v[0], v[1], v[2], i);
  }
}


static void SPR_init_step(SPRCavity* SPR)
{
  SPR->steps.num = 0;
  SPRStep* step = &SPR->steps.array[0];
  step->numCandidates = -1; // candidates not computed yet
  step->quality = DBL_MAX;  // we can hope for the biggest quality at the moment
}


/*|=======================================================|*\
|*|    _____                                              |*|
|*|   / ____|                                             |*|
|*|  | (___              _ _                              |*|
|*|   \___ \  _ __  __ _| | |                             |*|
|*|   ____) || '  \/ _` | | |                             |*|
|*|  |_____/ |_|_|_\__,_|_|_|                             |*|
|*|   _____                                               |*|
|*|  |  __ \                                              |*|
|*|  | |__) |   _      _           _                      |*|
|*|  |  ___/___| |_  _| |_  ___ __| |_ _ ___ _ _          |*|
|*|  | |   / _ \ | || | ' \/ -_) _` | '_/ _ \ ' \         |*|
|*|  |_|   \___/_|\_, |_||_\___\__,_|_| \___/_||_|        |*|
|*|   _____       |__/                                    |*|
|*|  |  __ \                                              |*|
|*|  | |__) |                             _   _           |*|
|*|  |  _  /  ___ __ ___ _ _  _ _  ___ __| |_(_)___ _ _   |*|
|*|  | | \ \ / -_) _/ _ \ ' \| ' \/ -_) _|  _| / _ \ ' \  |*|
|*|  |_|  \_\\___\__\___/_||_|_||_\___\__|\__|_\___/_||_| |*|
\*|=======================================================|*/
static HXTStatus hxtSPR_advanced(SPRCavity* SPR) {

  // this variable could be avoided, as step is
  // SPR->steps.array[SPR->steps.num] all along
  SPRStep* step = &SPR->steps.array[SPR->steps.num];

  while(1) {
    if(SPR->num_search_nodes >= SPR->max_search_nodes){
      return HXT_STATUS_INTERNAL;
    }

    int rewind = 0;
    if(SPR->bndTriangles.num==0) { // we found a new (better) tetrahedralization
      new_tetrahedralization(SPR, step);
      rewind = 1;
    }
    else if(step->numCandidates<0){

      // choosing the starting triangle
      double qualMax;
      const uint16_t triangleID = best_face_heuristic(SPR, &qualMax);

      if(triangleID == UINT16_MAX) {
        step->numCandidates = -1;
        rewind = 1;
      }
      else {
        step->tet = SPR->bndTriangles.array[triangleID];

        // create (and order) the candidate array
        compute_candidates(SPR, step, qualMax);

        // remove the face from the map
        remove_face(SPR, triangleID);
      }
    }

    if(step->numCandidates>0) {
      step->tet.node[3] = step->candidate[--step->numCandidates];

      unsigned index;
      double qual = get_quality_map(SPR,
                                    step->tet.node[0],
                                    step->tet.node[1],
                                    step->tet.node[2],
                                    step->tet.node[3], &index);

      // best quality could have changed if there was a rewind
      if(qual <= SPR->tetrahedra.quality || qual == -DBL_MAX)
        continue;

      int stop = 0;
      HXTBbox tetBbox;
      hxtBboxFrom(&tetBbox, SPR->points.array[step->tet.node[0]].coord);
      hxtBboxAddOne(&tetBbox, SPR->points.array[step->tet.node[1]].coord);
      hxtBboxAddOne(&tetBbox, SPR->points.array[step->tet.node[2]].coord);
      hxtBboxAddOne(&tetBbox, SPR->points.array[step->tet.node[3]].coord);

      for (int ptID=0; ptID<SPR->points.num; ptID++) {
        if(tet_contains_pt(SPR, &tetBbox, step->tet.node, ptID)) {
          stop = 1;
          SPR->map.qualities[index] = -DBL_MAX;
          break;
        }
      }

      if(stop)
        continue;

      for (int edgeID=0; edgeID<SPR->CIEdges.num; edgeID++) {
        uint8_t* edge = SPR->CIEdges.array[edgeID].node;
        if(tet_edge_intersection(SPR, &tetBbox, step->tet.node, edge)) {
          stop = 1;
          SPR->map.qualities[index] = -DBL_MAX;
          break;
        }
      }

      if(stop)
        continue;

      for (int triangleID=0; triangleID<SPR->CITriangles.num; triangleID++) {
        uint8_t* tri = SPR->CITriangles.array[triangleID].node;
        if(tet_tri_intersection(SPR, &tetBbox, step->tet.node, tri)) {
          stop = 1;
          SPR->map.qualities[index] = -DBL_MAX;
          break;
        }
      }

      if(stop)
        continue;

      // test intersection with boundary triangles
      for (int otherFaceID=0; otherFaceID<SPR->bndTriangles.num; otherFaceID++) {
        uint8_t* tri = SPR->bndTriangles.array[otherFaceID].node;
        if(tet_tri_intersection(SPR, &tetBbox, step->tet.node, tri)){
          stop = 1;
          break;
        }
      }

      if(stop)
        continue;

      SPR->num_search_nodes++;

      for (int f=0; f<3; f++) {
        uint8_t p0 = step->tet.node[nodeFromFacet[0][f]];
        uint8_t p1 = step->tet.node[nodeFromFacet[1][f]];
        uint8_t p2 = step->tet.node[nodeFromFacet[2][f]];

        uint16_t index = get_face_map(SPR, p0, p1, p2);

        if(index == UINT16_MAX) {
          // add the face to the map
          add_face(SPR, p0, p2, p1);
        }
        else {
          // remove the face from the map
          remove_face(SPR, index);
        }
      }

      double oldQual = step->quality;
      step = &SPR->steps.array[++SPR->steps.num];
      step->quality = qual < oldQual ? qual : oldQual;
      step->numCandidates = -1;
    }
    else if(step->numCandidates==0){
      add_face(SPR,
               step->tet.node[0],
               step->tet.node[1],
               step->tet.node[2]);
      rewind = 1;
    }

    if(rewind) {
      if(SPR->steps.num==0) {
        return HXT_STATUS_OK;
      }

      step = &SPR->steps.array[--SPR->steps.num];
      for (int f=0; f<3; f++) {
        uint8_t p0 = step->tet.node[nodeFromFacet[0][f]];
        uint8_t p1 = step->tet.node[nodeFromFacet[1][f]];
        uint8_t p2 = step->tet.node[nodeFromFacet[2][f]];

        uint16_t index = get_face_map(SPR, p0, p2, p1);

        if(index == UINT16_MAX) {
          // add the face to the map
          add_face(SPR, p0, p1, p2);
        }
        else {
          // remove the face from the map
          remove_face(SPR, index);
        }
      }

      if(step->quality <= SPR->tetrahedra.quality) {
        step->numCandidates = 0;
      }
    }
  }
}


HXTStatus hxtSPR(SPRCavity* SPR)
{
  SPR_clear_maps(SPR);
  SPR_init_faceMap_and_valences(SPR);
  SPR_detect_interior_points(SPR);
  SPR_init_step(SPR);

  HXT_CHECK( hxtSPR_advanced(SPR) );

  return HXT_STATUS_OK;
}


/* if hxtSPR or hxtSPR_advanced stopped abruptly
 * because it reached max_search_nodes, we can rewind
 * the cavity to its initial state thanks to this function
 */
static void hxtSPR_rewind(SPRCavity* SPR) {
  SPRStep* step = &SPR->steps.array[SPR->steps.num];

  while(1) {
    if(step->numCandidates>=0){
      add_face(SPR,
               step->tet.node[0],
               step->tet.node[1],
               step->tet.node[2]);
    }

    if(SPR->steps.num==0) {
      return;
    }

    step = &SPR->steps.array[--SPR->steps.num];
    for (int f=0; f<3; f++) {
      uint8_t p0 = step->tet.node[nodeFromFacet[0][f]];
      uint8_t p1 = step->tet.node[nodeFromFacet[1][f]];
      uint8_t p2 = step->tet.node[nodeFromFacet[2][f]];

      uint16_t index = get_face_map(SPR, p0, p2, p1);

      if(index == UINT16_MAX) {
        // add the face to the map
        add_face(SPR, p0, p1, p2);
      }
      else {
        // remove the face from the map
        remove_face(SPR, index);
      }
    }
  }
}



/*****************************************************************




 The following part uses SPR in the context of mesh optimization




******************************************************************/
typedef struct {
  SPRCavity cavity;

  // neighbor (mesh indices) of boundary triangles, given in original order
  uint64_t meshAdjacencies[SPR_MAX_BNDTRIANGLES];

  double worstQuality;
} SPRGrowingCavity;


static void add_knownPositive_quality_map(SPRCavity* SPR,
                                          unsigned v0,
                                          unsigned v1,
                                          unsigned v2,
                                          unsigned v3,
                                          double qual)
{
#ifndef NDEBUG
  int orientation = get_orient3d(SPR, v0, v1, v2, v3);
  if(orientation >= 0.0){
    HXT_WARNING("a tetrahedron has a negative volume but a quality of %f", qual);
  }
  if(qual<0.0) {
    HXT_WARNING("WARNING: negative quality (maybe even negative orientation ?) in mesh");
    qual = DBL_MIN;
  }
#endif

  unsigned index = get_compressed_index(v0, v1, v2, v3);
  SPR->map.qualities[index] = qual;
}


static int tetOutOfPartition(HXTVertex* vertices,
                             HXTPartition* partition,
                             uint32_t* nodes)
{
  if(vertexOutOfPartition(vertices, nodes[0], partition->lengthDist, partition->startDist) +
     vertexOutOfPartition(vertices, nodes[1], partition->lengthDist, partition->startDist) +
     vertexOutOfPartition(vertices, nodes[2], partition->lengthDist, partition->startDist) +
     vertexOutOfPartition(vertices, nodes[3], partition->lengthDist, partition->startDist) > 1)
    return 1;
  return 0;
}


/* initialize growingCav->cavity (SPR) with a cavity composed of badTet only
 *            growingCav->worstQuality is the quality of that tet
 *            growingCav->meshAdjacencies[] are the adjacencies of that tet */
static inline HXTStatus SPROpti_init(SPRGrowingCavity* growingCav,
                                     ThreadLocal* local,
                                     uint64_t badTet)
{
  SPRCavity* SPR = &growingCav->cavity;
  growingCav->worstQuality = local->quality->values[badTet];

  // initialize the SPR structure maps and arrays
  SPR_clear_maps(SPR);
  // SPR_init_step(SPR); % already done later
  SPR->points.num = 4;    // we add those 4 points in the for loop hereafter
  SPR->CIEdges.num = 0;     // only constrained edge entirely interior
  SPR->CITriangles.num = 0; // add_face() (in second for loop) already increments num
  SPR->bndTriangles.num = 0;
  SPR->tetrahedra.num = 1;
  SPR->tetrahedra.array[0] = (SPRTet) {{0,1,2,3}};
  SPR->tetrahedra.quality = local->quality->values[badTet];
  SPR->quality.function = local->quality->function;
  SPR->quality.userData = local->quality->userData;
  SPR->num_search_nodes = 0;
  SPR->max_search_nodes = local->SPR.maxSearchNodes;

  HXTMesh* mesh = local->toSync->mesh;
  HXTPartition* partition = &local->partition;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  // maybe this is unnecessary... better check anyway
  if(tetOutOfPartition(vertices, partition, &mesh->tetrahedra.node[4*badTet]))
    return HXT_STATUS_CONFLICT;

  HXTDeleted* deleted = &local->deleted;
  HXT_CHECK( askForDeleted(deleted, 1) );
  setDeletedFlag(mesh, badTet);
  deleted->array[deleted->num++] = badTet;

  // adding the points of the bad tet
  for(int i=0; i<4; i++) {
    uint32_t node = mesh->tetrahedra.node[4*badTet + i];
    double* coord = vertices[node].coord;

    SPR->points.array[i] = (SPRPoint) {
      .coord = {coord[0], coord[1], coord[2]},
      .userID = node,
      .valence = 0, // add_face already increments the valences
      .is_interior = 0,
      .is_optional = 0,
    };
  }

  add_knownPositive_quality_map(SPR, 0, 1, 2, 3, local->quality->values[badTet]);

  // adding faces and linked stuffs
  for(int i=0; i<4; i++) {
    // add the faces of the tet
    unsigned v0 = getNode0FromFacet(i);
    unsigned v1 = getNode1FromFacet(i);
    unsigned v2 = getNode2FromFacet(i);

    add_face(SPR, v0, v1, v2);
    growingCav->meshAdjacencies[i] = mesh->tetrahedra.neigh[4*badTet + i];
  }

  return HXT_STATUS_OK;
}



static inline HXTStatus find_best_point(SPRGrowingCavity* growingCav,
                                        ThreadLocal* local,
                                        int* bestPoint) {
  /* A point is good if it is very connected to the cavity !
   * (connection <==> a tet containing the point having a face on the cavity)
   * If multiple points have the same number of connections the quality of
   * tets that makes the connections are taken into account (highest sum win)
   */

  /* For every face of the cavity, we take the opposite point on the
   * external side.
   * We add each point, if it is not already present, to the
   * opposite_point[] array, If it is present, we increment numConnected.
   */
  SPRCavity* SPR = &growingCav->cavity;
  HXTMesh* mesh = local->toSync->mesh;
  uint64_t* adjacencies = growingCav->meshAdjacencies;

  uint32_t opposite_point[SPR_MAX_BNDTRIANGLES];
  uint16_t numConnected[SPR_MAX_BNDTRIANGLES];
  int numPoints = 0;

  // for each point outside of the cavity
  for(int i=0; i<SPR->bndTriangles.num; i++) {
    unsigned facet = adjacencies[i]%4;
    uint64_t tet = adjacencies[i]/4;

    if(adjacencies[i]==HXT_NO_ADJACENT || getFacetConstraint(mesh, tet, facet))
      continue;

#ifdef DEBUG
    if(getDeletedFlag(mesh, tet))
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "DEBUG: adjacent tet already deleted");
#endif

    uint32_t node = mesh->tetrahedra.node[adjacencies[i]];
    int p;

    // just make a stupid linear search
    for(p=0; p<numPoints; p++) {
      if(opposite_point[p]==node) {
        numConnected[p]++;
        break;
      }
    }

    if(p==numPoints) {
      opposite_point[p] = node;
      numConnected[p] = 1;
      numPoints++;
    }
  }

  /* we determine if there is equality
   * if not, we determine the most connect point */
  uint32_t mostConnectedPoint;
  uint16_t mostNumConnected = 0;
  int equality = 0;
  for(int i=0; i<numPoints; i++) {
    if(numConnected[i]>mostNumConnected) {
      mostNumConnected = numConnected[i];
      mostConnectedPoint = opposite_point[i];
      equality = 0;
    }
    else if(numConnected[i]==mostNumConnected) {
      equality = 1;
    }
  }

  if(mostNumConnected==0) // cavity is completely constrained
    return HXT_STATUS_INTERNAL;

  /* if there is equality, we must compute the sum of qualities
   * for each point with mostNumConnected connection   */
  if(equality) {
    double bestScore = -DBL_MAX;

    for(int i=0; i<numPoints; i++) {

      if(numConnected[i]==mostNumConnected) {
        uint32_t node = opposite_point[i];
        double score = 0.0;

        for(int t=0; t<SPR->bndTriangles.num; t++) {
          if(adjacencies[t]==HXT_NO_ADJACENT || mesh->tetrahedra.node[adjacencies[t]]!=node || getFacetConstraint(mesh, adjacencies[t]/4, adjacencies[t]%4))
            continue;
          score -= local->quality->values[adjacencies[t]/4];
        }

        if(score > bestScore) {
          bestScore = score;
          mostConnectedPoint = node;
        }
      }
    }
  }

  *bestPoint = mostConnectedPoint;

  return HXT_STATUS_OK;
}


/* determine if an edge needs to be added to SPR->edges.
 * <=> if the edge is constrained and is completely contained within the cavity */
static inline int needNewSPREdge(HXTMesh* mesh, uint64_t meshTet, int in_facet, int out_facet)
{
  int edgeNum = getEdgeFromFacets(in_facet, out_facet);

  if(!getEdgeConstraint(mesh, meshTet, edgeNum))
    return -1;

  // we will turn around the edge and see if we stay in the cavity
  // if a tet is not deleted, it's not in the cavity so we return -1
  uint64_t firstTet=meshTet;

  do
  {
    if(getFacetConstraint(mesh, meshTet, out_facet))
      return -1;

    uint32_t oppositeNode = mesh->tetrahedra.node[4*meshTet + in_facet];

    // go into the neighbor through out_facet
    uint64_t neigh = mesh->tetrahedra.neigh[4*meshTet + out_facet];
    if(neigh==HXT_NO_ADJACENT ||
       getDeletedFlag(mesh, neigh/4)==0) {
      return -1;
    }

    meshTet = neigh/4;
    in_facet = neigh%4;
    uint32_t* nodes = mesh->tetrahedra.node + 4*meshTet;
    for (out_facet=0; out_facet<3; out_facet++)
      if(nodes[out_facet]==oppositeNode)
        break;

  } while (meshTet!=firstTet);

  return edgeNum;
}



/* attach the best point (see find_best_point()) to the cavity */
static inline HXTStatus attach_best_point(SPRGrowingCavity* growingCav,
                                          ThreadLocal* local)
{
  SPRCavity* SPR = &growingCav->cavity;
  HXTMesh* mesh = local->toSync->mesh;

  int newNode;
  HXT_CHECK( find_best_point(growingCav, local, &newNode) );

  // we can now add mostConnectPoint !! :-)
  double* coord = &mesh->vertices.coord[4*newNode];
  uint8_t newV = SPR->points.num++;
  SPR->points.array[newV] = (SPRPoint) {
    .coord = {coord[0], coord[1], coord[2]},
    .userID = newNode,
    .valence = 0, // add_face already increments the valences
    .is_interior = 0,
    .is_optional = 0,
  };

  uint64_t* adjacencies = growingCav->meshAdjacencies;

  /* we delete tetrahedra that contain the added point. */
  HXTPartition* partition = &local->partition;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  HXTDeleted* deleted = &local->deleted;

  for(int i=0; i<SPR->bndTriangles.num;) { // notice we don't increment i here
    uint64_t meshTet = adjacencies[i]/4;
    unsigned facet = adjacencies[i]%4;

    if(adjacencies[i]==HXT_NO_ADJACENT ||
       getFacetConstraint(mesh, meshTet, facet)) {
      i++;
      continue;
    }

    uint32_t oppositeNode = mesh->tetrahedra.node[adjacencies[i]];
    uint8_t oppositeV = 255;

    for(int j=0; j<SPR->points.num; j++) {
      if(oppositeNode==SPR->points.array[j].userID) {
        oppositeV = j;
        break;
      }
    }

    if(oppositeV==255) {
      i++;
      continue;
    }

    // verify that the tet is in our partition
    if(tetOutOfPartition(vertices, partition, &mesh->tetrahedra.node[4*meshTet])){
        return HXT_STATUS_CONFLICT;
    }

    // delete the tet and flag it accordingly
    HXT_CHECK( askForDeleted(deleted, 1) );
    setDeletedFlag(mesh, meshTet);
    deleted->array[deleted->num++] = meshTet;

#ifdef DEBUG
    if(!getDeletedFlag(mesh, mesh->tetrahedra.neigh[adjacencies[i]]/4))
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "DEBUG: reverse adjacency is not deleted");
#endif

    // we must now find the corresponding points ID in the SPR structure
    // and we add the tet to the SPR structure :-)
    uint8_t* triV = SPR->bndTriangles.array[i].node;
    uint8_t* tetV = SPR->tetrahedra.array[SPR->tetrahedra.num++].node;

    tetV[facet] = oppositeV;
    for(int j=0; j<3; j++) {
      if(SPR->points.array[triV[j]].userID == mesh->tetrahedra.node[4*meshTet + getNode0FromFacet(facet)]) {
        tetV[getNode0FromFacet(facet)] = triV[j];
        tetV[getNode1FromFacet(facet)] = triV[(j+2)%3];
        tetV[getNode2FromFacet(facet)] = triV[(j+1)%3];
        break;
      }
    }

#ifdef DEBUG
    // verify that we filled the tetV array correctly
    for(int j=0; j<4; j++) {
      if(SPR->points.array[tetV[j]].userID != mesh->tetrahedra.node[4*meshTet + j])
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "DEBUG: bug in the way we make SPR<->mesh correspond");
    }
#endif

    // add the quality of the meshTet to known cavities :-)
    add_knownPositive_quality_map(SPR,
                                  tetV[0], tetV[1], tetV[2], tetV[3],
                                  local->quality->values[meshTet]);

    // update the quality to the worst one...
    if(local->quality->values[meshTet] < growingCav->worstQuality) {
      SPR->tetrahedra.quality = local->quality->values[meshTet];
      growingCav->worstQuality = local->quality->values[meshTet];
    }

    adjacencies[i] = adjacencies[SPR->bndTriangles.num-1];
    remove_face(SPR, i);

    // for each facet
    for (unsigned f=0; f<4; f++) {
      if(f==facet)
        continue;
      uint8_t p0 = tetV[nodeFromFacet[0][f]];
      uint8_t p1 = tetV[nodeFromFacet[1][f]];
      uint8_t p2 = tetV[nodeFromFacet[2][f]];

      uint16_t index = get_face_map(SPR, p0, p2, p1);

      if(index == UINT16_MAX) {
        // add the adjacency
        adjacencies[SPR->bndTriangles.num] = mesh->tetrahedra.neigh[4*meshTet + f];
        // add the face to the map
        add_face(SPR, p0, p1, p2);
      }
      else {
        if(getFacetConstraint(mesh, meshTet, f)) {
          // we remove the found face and add the facet to the constrained facet.
          adjacencies[index] = adjacencies[SPR->bndTriangles.num-1];
          remove_face(SPR, index);

          SPR->CITriangles.array[SPR->CITriangles.num++] = (SPRTriangle) {{p0, p1, p2, p0}};
        }
        else {
          // we may have a new constrained edge that is completely inside the cavity
          for(unsigned f2=0; f2<4; f2++) {
            if(f2==f)
              continue;

            int edgeNum = needNewSPREdge(mesh, meshTet, f, f2);
            if(edgeNum!=-1) {
              unsigned n0, n1;
              getNodesFromEdge(edgeNum, &n0, &n1);

              // add the edge to the SPR structure
              SPR->CIEdges.array[SPR->CIEdges.num++] = (SPREdge) {{tetV[n0], tetV[n1]}};
            }
          }


          // remove the face from the map, only if is not constrained
          adjacencies[index] = adjacencies[SPR->bndTriangles.num-1];
          remove_face(SPR, index);

          // except now we may have a face we did not look at which is before i...
          if(index < i) {
            i = index;
          }
        }
      }
    }


  }

  return HXT_STATUS_OK;
}


/* if edge a-b is constrained, put a '1' in constrainedEdgeMap[a][b]
 * and in constrainedEdgeMap[b][a] */
static HXTStatus fillConstrainedEdgeMap(HXTMesh* mesh, SPRCavity* SPR,
                                        uint64_t* adjacencies,
                                        char constrainedEdgeMap[][SPR_MAX_PTS])
{
  // the edge that are in the SPR cavity structure are constrained
  for(int i=0; i<SPR->CIEdges.num; i++) {
    int v0 = SPR->CIEdges.array[i].node[0];
    int v1 = SPR->CIEdges.array[i].node[1];
    constrainedEdgeMap[v0][v1] = 1;
    constrainedEdgeMap[v1][v0] = 1;
  }

  // there might be other constrained edge on the surface of the cavity
  for(int i=0; i<SPR->bndTriangles.num; i++) {
    if(adjacencies[i]==HXT_NO_ADJACENT)
      continue;

    uint64_t meshTet = adjacencies[i]/4;
    int facet = adjacencies[i]%4;

    // the indices of the node of the triangle in the tet
    unsigned ind[3] = {getNode0FromFacet(facet), getNode2FromFacet(facet), getNode1FromFacet(facet)};

    uint8_t* triV = SPR->bndTriangles.array[i].node;
    // we must test the 3 rotations of the triangle to get one that match...
    int rotation;
    for(rotation=0; rotation<3; rotation++) {
      if(SPR->points.array[triV[rotation]].userID == mesh->tetrahedra.node[4*meshTet + ind[0]]) {
        break;
      }
    }

#ifdef DEBUG
    for(int j=0; j<3; j++) {
      if(SPR->points.array[triV[(rotation+j)%3]].userID!=mesh->tetrahedra.node[4*meshTet + ind[j]]){
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "DEBUG: bug in the way we make SPR<->mesh correspond");
      }
    }
#endif

    for(int j=0; j<3; j++) {
      if(getEdgeConstraint(mesh, meshTet, getEdgeFromNodes(ind[j], ind[(j+1)%3]))) {
        // edge 01 is constrained
        constrainedEdgeMap[triV[(rotation+j)%3]][(rotation+j+1)%3] = 1;
        constrainedEdgeMap[(rotation+j+1)%3][triV[(rotation+j)%3]] = 1;
      }
    }
  }

  return HXT_STATUS_OK;
}


/* replace the interior of the cavity within the mesh by the triangulation
 * found by hxtSPR() */
static inline HXTStatus rebuildMesh(SPRGrowingCavity* growingCav,
                                    ThreadLocal* local,
#ifdef DEBUG
                                    uint64_t prevNumDeleted,
#endif
                                    uint64_t badTet)
{
  HXTDeleted* deleted = &local->deleted;
  HXTMesh* mesh = local->toSync->mesh;
  uint32_t color = mesh->tetrahedra.color[badTet];
  uint16_t lastCheck = local->SPR.dateOfLastCheck;
  local->SPR.dateOfLastCreation = lastCheck;

  SPRCavity* SPR = &growingCav->cavity;

#ifdef DEBUG
  int adjacencies_to_nowhere = 0;
  for(uint64_t i=prevNumDeleted; i<deleted->num; i++) {
    uint64_t oldTet = deleted->array[i];
    for(int j=0; j<4; j++) {
      if(mesh->tetrahedra.neigh[4*oldTet + j] == HXT_NO_ADJACENT)
        adjacencies_to_nowhere++;
    }
  }
#endif

  // we integrate the SPR cavity into the mesh
  if((uint64_t) SPR->tetrahedra.num > deleted->num) {
    HXT_CHECK( createNewDeleted(local->toSync, deleted, SPR->tetrahedra.num) );
  }

  uint64_t* adjacencies = growingCav->meshAdjacencies;
  uint64_t* newTet = &deleted->array[deleted->num - SPR->tetrahedra.num];

  //make a map for edge constraints
  char constrainedEdgeMap[SPR_MAX_PTS][SPR_MAX_PTS] = {0};
  HXT_CHECK( fillConstrainedEdgeMap(mesh, SPR, adjacencies, constrainedEdgeMap) );



#ifdef DEBUG
  int numFound = 0;
#endif
  for(int i=0; i<SPR->tetrahedra.num; i++) {
    uint64_t meshTet = newTet[i];
    uint8_t* v = SPR->tetrahedra.array[i].node;

    for(int j=0; j<4; j++)
      mesh->tetrahedra.node[4*meshTet + j] = SPR->points.array[v[j]].userID;

    mesh->tetrahedra.color[meshTet] = color;
    mesh->tetrahedra.flag[meshTet] = 0;

    unsigned index = get_compressed_index(v[0], v[1], v[2], v[3]);
    local->quality->values[meshTet] = SPR->map.qualities[index];
    local->date->values[meshTet].creation = lastCheck;
    local->date->values[meshTet].check = lastCheck;

    for(int j=0; j<4; j++) {
      // try to find the face in SPRTriangles
      uint16_t index = get_face_map(SPR,
                                    v[getNode0FromFacet(j)],
                                    v[getNode1FromFacet(j)],
                                    v[getNode2FromFacet(j)]);

      remove_face_map(SPR, v[getNode0FromFacet(j)],
                           v[getNode1FromFacet(j)],
                           v[getNode2FromFacet(j)]);

      if(index==UINT16_MAX) {
        mesh->tetrahedra.neigh[4*meshTet + j] = HXT_NO_ADJACENT;
      }
      else {
        uint64_t adj = adjacencies[index];

        if(adj==HXT_NO_ADJACENT) { // happens when there are no ghosts
          mesh->tetrahedra.neigh[4*meshTet + j] = HXT_NO_ADJACENT;
          setFacetConstraint(mesh, meshTet, j);
        }
        else {
          mesh->tetrahedra.neigh[4*meshTet + j] = adj;
          mesh->tetrahedra.neigh[adj] = 4*meshTet + j;
          if(getFacetConstraint(mesh, adj/4, adj%4))
             setFacetConstraint(mesh, meshTet, j);
        }
#ifdef DEBUG
        numFound++;
#endif
      }
    }

    for(int e=0; e<6; e++) {
      unsigned n0, n1;
      getNodesFromEdge(e, &n0, &n1);
      int v0 = SPR->tetrahedra.array[i].node[n0];
      int v1 = SPR->tetrahedra.array[i].node[n1];

      if(constrainedEdgeMap[v0][v1]) {
        setEdgeConstraint(mesh, meshTet, e);
      }
    }
  }

#ifdef DEBUG
  if(numFound!=SPR->bndTriangles.num)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "DEBUG: missing external adjacency");
#endif

  /* now, all external adjacencies (except HXT_NO_ADJACENT ones obviously)
   *  have been found, we just have to find internal adjacencies :p */
  for(int i=0; i<SPR->tetrahedra.num; i++) {
    uint64_t meshTet = newTet[i];

    for(int j=0; j<4; j++) {
      if(mesh->tetrahedra.neigh[4*meshTet+j]==HXT_NO_ADJACENT) {
        add_face_map(SPR,
                     SPR->tetrahedra.array[i].node[getNode0FromFacet(j)],
                     SPR->tetrahedra.array[i].node[getNode1FromFacet(j)],
                     SPR->tetrahedra.array[i].node[getNode2FromFacet(j)],
                     4*i+j);
      }
    }
  }

  // reset constrained triangles flags
  for(int i=0; i<SPR->CITriangles.num; i++) {
    uint16_t adj0 = get_face_map(SPR,
                                 SPR->CITriangles.array[i].node[0],
                                 SPR->CITriangles.array[i].node[1],
                                 SPR->CITriangles.array[i].node[2]);
    uint16_t adj1 = get_face_map(SPR,
                                 SPR->CITriangles.array[i].node[0],
                                 SPR->CITriangles.array[i].node[2],
                                 SPR->CITriangles.array[i].node[1]);

#ifndef NDEBUG
    if(adj0==UINT16_MAX || adj1==UINT16_MAX)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "constrained triangle not found in the tetrahedralization");
#endif
    uint64_t tet0 = newTet[adj0/4];
    unsigned facet0 = adj0%4;
    setFacetConstraint(mesh, tet0, facet0);

    uint64_t tet1 = newTet[adj1/4];
    unsigned facet1 = adj1%4;
    setFacetConstraint(mesh, tet1, facet1);

    mesh->tetrahedra.neigh[4*tet0 + facet0] = 4*tet1 + facet1;
    mesh->tetrahedra.neigh[4*tet1 + facet1] = 4*tet0 + facet0;
  }

  for(int i=0; i<SPR->tetrahedra.num; i++) {
    uint64_t meshTet = newTet[i];

    for(int j=0; j<4; j++) {
      if(mesh->tetrahedra.neigh[4*meshTet+j]==HXT_NO_ADJACENT) {
        uint16_t adj = get_face_map(SPR,
                                    SPR->tetrahedra.array[i].node[getNode0FromFacet(j)],
                                    SPR->tetrahedra.array[i].node[getNode2FromFacet(j)],
                                    SPR->tetrahedra.array[i].node[getNode1FromFacet(j)]);
        if(adj!=UINT16_MAX) {
          uint64_t neighTet = newTet[adj/4];
          mesh->tetrahedra.neigh[4*meshTet+j] = 4*neighTet + adj%4;
        }
      }
    }
  }

#ifdef DEBUG
  for (int i=0; i<SPR->tetrahedra.num; i++) {
    uint64_t meshTet = newTet[i];

    for (int j=0; j<4; ++j)
    {
      if(mesh->tetrahedra.neigh[4*meshTet+j]==HXT_NO_ADJACENT) {
        adjacencies_to_nowhere--;
      }
      else if(mesh->tetrahedra.neigh[4*meshTet+j]!=HXT_NO_ADJACENT && mesh->tetrahedra.neigh[4*meshTet+j]/4>=mesh->tetrahedra.num) {
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "invalid neighbor");
      }
      else if(mesh->tetrahedra.neigh[mesh->tetrahedra.neigh[4*meshTet+j]]!=4*meshTet+j){
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "one of the tetrahedron is not the neighbor of its neighbor");
      }
    }
  }

  if(adjacencies_to_nowhere!=0)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "there are unrecovered adjacencies");
#endif

  deleted->num -= SPR->tetrahedra.num;

  return HXT_STATUS_OK;
}


/* check the creation dates of each tet of the cavity
 * if none of the date are as recent as the last check
 * return 0
 * else, return 1 */
int verifyDates(ThreadLocal* local, uint64_t prevNumDeleted, uint16_t lastCheck)
{
  HXTDeleted* deleted = &local->deleted;
  for(uint64_t i=prevNumDeleted; i<deleted->num; i++) {
    uint16_t creation = local->date->values[deleted->array[i]].creation;
    if(creation >= lastCheck)
      return 1;
  }

  return 0;
}


/* we checked the growing cavity till the end but it didn't work
 * we mark the date of this failure... */
HXTStatus setCheckDate(ThreadLocal* local, uint64_t badTet)
{
  local->date->values[badTet].check = local->SPR.dateOfLastCreation + 1;
  local->SPR.dateOfLastCheck = local->SPR.dateOfLastCreation + 1;
  return HXT_STATUS_OK;
}


static void deleted_reset(ThreadLocal* local, uint64_t prevNumDeleted)
{
  HXTDeleted* deleted = &local->deleted;
  HXTMesh* mesh = local->toSync->mesh;
  for(uint64_t i=prevNumDeleted; i<deleted->num; i++) {
    unsetDeletedFlag(mesh, deleted->array[i]);
  }
  deleted->num = prevNumDeleted;
}






HXTStatus hxtSPR_opti(ThreadLocal* local,
                      uint64_t badTet)
{
  SPRGrowingCavity growingCav;  // all the structure on the stack... it should fit ^^
  SPRCavity* SPR = &growingCav.cavity;
  uint64_t prevNumDeleted = local->deleted.num;

  uint16_t lastCheck = local->date->values[badTet].check;
  int datesOk = 0;

  HXT_CHECK( SPROpti_init(&growingCav, local, badTet) );

  do {
    // return HXT_STATUS_INTERNAL if the cavity if completely constrained
    HXTStatus status = attach_best_point(&growingCav, local);

    if(status==HXT_STATUS_CONFLICT || status==HXT_STATUS_INTERNAL) {
      deleted_reset(local, prevNumDeleted);
      return status;
    }
    else if(status!=HXT_STATUS_OK) {
      HXT_TRACE(status);
      return status;
    }

    if(datesOk==0)
      datesOk = verifyDates(local, prevNumDeleted, lastCheck);

    if(datesOk) {
      /* applying the SPR algorithm, only initializing the necessary minimum */
      SPR_detect_interior_points(SPR);
      SPR_init_step(SPR);

      // save the triangles in their current order
      SPRTriangle original[SPR_MAX_BNDTRIANGLES];
      uint64_t adjacencies[SPR_MAX_BNDTRIANGLES];

      memcpy(original, SPR->bndTriangles.array, SPR->bndTriangles.num*sizeof(SPRTriangle));
      memcpy(adjacencies, growingCav.meshAdjacencies, SPR->bndTriangles.num*sizeof(uint64_t));

      status = hxtSPR_advanced(SPR);

      if(status==HXT_STATUS_INTERNAL) {
        if(growingCav.worstQuality < growingCav.cavity.tetrahedra.quality){
          hxtSPR_rewind(SPR);
        }
        else {
          // HXT_WARNING("Maximum nodes of SPR search reached");
          deleted_reset(local, prevNumDeleted);
          setCheckDate(local, badTet);
          return HXT_STATUS_INTERNAL;
        }
      }

      // reorder the adjacencies in the new order
      for(int i=0; i<SPR->bndTriangles.num; i++) {
        uint8_t* triV = original[i].node;

        uint16_t index = get_face_map(SPR, triV[0], triV[1], triV[2]);

#ifndef NDEBUG
        if(index==UINT16_MAX) {
          return HXT_ERROR_MSG(HXT_STATUS_ERROR, "original is not present in the cavity anymore");
        }
#endif
        growingCav.meshAdjacencies[index] = adjacencies[i];
      }

      if(growingCav.worstQuality < growingCav.cavity.tetrahedra.quality){
        break;// we found a better solution
      }
    }

    if(growingCav.cavity.points.num==SPR_MAX_PTS) {
      // HXT_WARNING("Too much points in SPR cavity");
      deleted_reset(local, prevNumDeleted);
      setCheckDate(local, badTet);
      return HXT_STATUS_INTERNAL;
    }
  } while(1);


#ifdef DEBUG
    HXT_CHECK(rebuildMesh(&growingCav, local, prevNumDeleted, badTet));
#else
    HXT_CHECK(rebuildMesh(&growingCav, local, badTet));
#endif

  return HXT_STATUS_OK;
}
