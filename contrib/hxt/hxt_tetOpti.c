#include "hxt_tet_aspect_ratio.h"
#include "hxt_mesh.h"
#include "hxt_tetUtils.h"
#include "predicates.h"
#include "hxt_tetRepair.h"
#include "hxt_tetFlag.h"
#include "hxt_vertices.h"
#include "hxt_tools.h"
#include "hxt_sort.h"
#include <float.h>

#define NV -128               // not a valid entry
#define HXT_MAX_CAVITY_SIZE 7 // because no cavity is has more than 7 tetrahedra while swapping
#define DELETED_BUFFER_SIZE 8192
#define SMALLEST_ROUND 1024

/* usefull macros */
#define MAX(x,y) ((x)>(y) ? (x) : (y))
#define MIN(x,y) ((x)<(y) ? (x) : (y))
#define SWAP(x,y) do{int tmp=x; x=y; y=tmp;}while(0)


/*
An oriented edge {up,down} is described by its 'in' and 'out' facets:
       v_up
       |\`-_
       | \  `-_ 
       |  \    `-_                in_facet
       |   \      `-_              |
       |    \   up   `-_          /
       |     \  facet   `-_   <--'
our    |      \            `-_
edge   | out   \              `-_
-----> | facet  \v_out__________`>v_in
       |        /               _-'
       |       /             _-'
       |      /  down     _-'
       |     /  facet  _-'
       |    /       _-'
       |   /     _-'
       |  /   _-'
       | / _-'
       |/-'
      v_down
        
    _->
   /
   \    we scan tetrahedra in a counterclockwise order when viewed from up
    `-__-'


 We keep the numbering of facets and the orientation of tetrahedra as before so:

 mesh->tetrahedra.node[4*t + in_facet] = v_out
 mesh->tetrahedra.node[4*t + out_facet] = v_in
 mesh->tetrahedra.node[4*t + down_facet] = v_up
 mesh->tetrahedra.node[4*t + up_facet] = v_down


There are 12 possible oriented edges (in_facet!=out_facet)
There are also 12 possibilities for a valid tetrahedra, each can be uniquely defined by an oriented edge...

in_f=0 out_f=1 up_f=2 down_f=3    in_f=0 out_f=2 up_f=3 down_f=1     in_f=0 out_f=3 up_f=1 down_f=2
      v_3                              v_1                              v_2                    
       |\`-_                            |\`-_                            |\`-_                 
       | \  `-_                         | \  `-_                         | \  `-_              
       |  \    `-_                      |  \    `-_                      |  \    `-_           
       |   \      `-_                   |   \      `-_                   |   \      `-_        
       |    \        `-_                |    \        `-_                |    \        `-_     
       |     \v_0_______`>v_1           |     \v_0_______`>v_2           |     \v_0_______`>v_3
       |     /         _-'              |     /         _-'              |     /         _-'   
       |    /       _-'                 |    /       _-'                 |    /       _-'      
       |   /     _-'                    |   /     _-'                    |   /     _-'         
       |  /   _-'                       |  /   _-'                       |  /   _-'            
       | / _-'                          | / _-'                          | / _-'               
       |/-'                             |/-'                             |/-'                  
      v_2                              v_3                              v_1


in_f=1 out_f=2 up_f=0 down_f=3    in_f=1 out_f=0 up_f=3 down_f=2     in_f=1 out_f=3 up_f=2 down_f=0
      v_3                              v_2                              v_0                    
       |\`-_                            |\`-_                            |\`-_                 
       | \  `-_                         | \  `-_                         | \  `-_              
       |  \    `-_                      |  \    `-_                      |  \    `-_           
       |   \      `-_                   |   \      `-_                   |   \      `-_        
       |    \        `-_                |    \        `-_                |    \        `-_     
       |     \v_1_______`>v_2           |     \v_1_______`>v_0           |     \v_1_______`>v_3
       |     /         _-'              |     /         _-'              |     /         _-'   
       |    /       _-'                 |    /       _-'                 |    /       _-'      
       |   /     _-'                    |   /     _-'                    |   /     _-'         
       |  /   _-'                       |  /   _-'                       |  /   _-'            
       | / _-'                          | / _-'                          | / _-'               
       |/-'                             |/-'                             |/-'                  
      v_0                              v_3                              v_2


in_f=2 out_f=3 up_f=0 down_f=1    in_f=2 out_f=0 up_f=1 down_f=3     in_f=2 out_f=1 up_f=3 down_f=0
      v_1                              v_3                              v_0                    
       |\`-_                            |\`-_                            |\`-_                 
       | \  `-_                         | \  `-_                         | \  `-_              
       |  \    `-_                      |  \    `-_                      |  \    `-_           
       |   \      `-_                   |   \      `-_                   |   \      `-_        
       |    \        `-_                |    \        `-_                |    \        `-_     
       |     \v_3_______`>v_2           |     \v_2_______`>v_0           |     \v_2_______`>v_1
       |     /         _-'              |     /         _-'              |     /         _-'   
       |    /       _-'                 |    /       _-'                 |    /       _-'      
       |   /     _-'                    |   /     _-'                    |   /     _-'         
       |  /   _-'                       |  /   _-'                       |  /   _-'            
       | / _-'                          | / _-'                          | / _-'               
       |/-'                             |/-'                             |/-'                  
      v_0                              v_1                              v_3                    


in_f=3 out_f=1 up_f=0 down_f=2    in_f=3 out_f=0 up_f=2 down_f=1     in_f=3 out_f=2 up_f=1 down_f=0
      v_2                              v_1                              v_0                    
       |\`-_                            |\`-_                            |\`-_                 
       | \  `-_                         | \  `-_                         | \  `-_              
       |  \    `-_                      |  \    `-_                      |  \    `-_           
       |   \      `-_                   |   \      `-_                   |   \      `-_        
       |    \        `-_                |    \        `-_                |    \        `-_     
       |     \v_2_______`>v_1           |     \v_3_______`>v_0           |     \v_3_______`>v_2
       |     /         _-'              |     /         _-'              |     /         _-'   
       |    /       _-'                 |    /       _-'                 |    /       _-'      
       |   /     _-'                    |   /     _-'                    |   /     _-'         
       |  /   _-'                       |  /   _-'                       |  /   _-'            
       | / _-'                          | / _-'                          | / _-'               
       |/-'                             |/-'                             |/-'                  
      v_0                              v_2                              v_1                    
*/

const int _UP_FACET[4][4] = {{NV, 2, 3, 1},
                             { 3,NV, 0, 2},
                             { 1, 3,NV, 0},
                             { 2, 0, 1,NV}};

#define UP_FACET(in_facet, out_facet) _UP_FACET[in_facet][out_facet]
#define DOWN_FACET(in_facet, out_facet) _UP_FACET[out_facet][in_facet]

#define UP_VERTEX(in_facet, out_facet) DOWN_FACET(in_facet, out_facet)
#define DOWN_VERTEX(in_facet, out_facet) UP_FACET(in_facet, out_facet)
#define IN_VERTEX(in_facet, out_facet) (out_facet)
#define OUT_VERTEX(in_facet, out_facet) (in_facet)

/* that's everything we need to handle edges !

 NOW, we need patterns of triangulation around edges to make swaps
 */

typedef struct {
  const unsigned char (*triangles)[3];      /* triangles array                                     */
  const uint64_t *triangle_in_triangul;     /* in which triangulation is the triangles (bit array) */
  const unsigned char (*triangulations)[5]; /* triangulation array                                 */
  const signed char (*triangul_neigh)[20];  /* array to find adjacencies back                      */
  const unsigned num_triangles;             /* number of different triangles                       */
  const unsigned num_triangulations ;       /* number of different triangulations                  */
  // const int num_triangles_per_triangulation; /* simply the number of nodes +2...              */
} SwapPattern ;


const unsigned char triangles3[][3] = { {0,1,2} };
const uint64_t triangle_in_triangul3[] = { 1};
const unsigned char triangulations3[][5] = {{0}};
const signed char triangul_neigh3[][20] = {
  {-2,-3,-1,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV}
};


const unsigned char triangles4[][3] = {
  {0,1,2}, {2,3,0}, {1,2,3}, {3,0,1}
};
const uint64_t triangle_in_triangul4[] = { 1, 1, 2, 2};
const unsigned char triangulations4[][5] = {
  {0,1}, {2,3}
};
const signed char triangul_neigh4[][20] = {
  {-2,5,-1,NV,-4,1,-3,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {-3,5,-2,NV,-1,1,-4,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV}
};



const unsigned char triangles5[][3] = {
  {0,1,2}, {0,2,3}, {0,3,4}, {0,1,4}, {1,3,4},
  {1,2,3}, {2,3,4}, {0,2,4}, {0,1,3}, {1,2,4}
};
const uint64_t triangle_in_triangul5[] = {5, 1, 9, 18, 2, 10, 20, 4, 8, 16};
const unsigned char triangulations5[][5] = { {0,1,2}, {3,4,5}, {0,6,7}, {2,5,8}, {3,6,9} };
const signed char triangul_neigh5[][20] = {
  {-2,6,-1,NV,-3,10,1,NV,-4,-5,5,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {5,-5,-1,NV,-4,0,9,NV,-3,6,-2,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {-2,10,-1,NV,-4,8,-3,NV,5,-5,1,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {-4,-5,9,NV,-3,8,-2,NV,5,2,-1,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {9,-5,-1,NV,-4,8,-3,NV,5,0,-2,NV,NV,NV,NV,NV,NV,NV,NV,NV}
};


const unsigned char triangles6[][3] = {
  {0,1,2}, {0,2,3}, {0,3,4}, {0,4,5}, {0,2,5}, {2,4,5}, {2,3,4}, {0,3,5},
  {3,4,5}, {0,2,4}, {2,3,5}, {1,2,3}, {0,1,3}, {0,1,5}, {1,4,5}, {1,3,4},
  {0,1,4}, {1,3,5}, {1,2,4}, {1,2,5}
};
const uint64_t triangle_in_triangul6[] = {
  31, 5, 33, 2345, 18, 4098, 7178, 132, 8852, 8, 8208,
  992, 160, 13888, 1088, 320, 2304, 512, 3072, 12288};
const unsigned char triangulations6[][5] = {
  {0,1,2,3}, {0,4,5,6}, {0,1,7,8}, {0,3,6,9}, {0,4,8,10},
  {2,3,11,12}, {11,13,14,15}, {7,8,11,12}, {3,11,15,16},
  {8,11,13,17}, {6,13,14,18}, {3,6,16,18}, {5,6,13,19},
  {8,10,13,19}
};
const signed char triangul_neigh6[][20] = {
  {-2,6,-1,NV,-3,10,1,NV,-4,14,5,NV,-5,-6,9,NV,NV,NV,NV,NV},
  {-2,6,-1,NV,9,-6,1,NV,-5,4,13,NV,-4,10,-3,NV,NV,NV,NV,NV},
  {-2,6,-1,NV,-3,10,1,NV,13,-6,5,NV,-5,8,-4,NV,NV,NV,NV,NV},
  {-2,14,-1,NV,-5,-6,13,NV,-4,12,-3,NV,9,6,1,NV,NV,NV,NV,NV},
  {-2,6,-1,NV,13,-6,1,NV,-5,12,-4,NV,9,4,-3,NV,NV,NV,NV,NV},
  {-4,6,13,NV,-5,-6,1,NV,-3,12,-2,NV,9,2,-1,NV,NV,NV,NV,NV},
  {-3,14,-2,NV,9,-6,-1,NV,-5,4,13,NV,-4,10,1,NV,NV,NV,NV,NV},
  {5,-6,13,NV,-5,0,-4,NV,-3,12,-2,NV,9,2,-1,NV,NV,NV,NV,NV},
  {-5,-6,13,NV,-3,10,-2,NV,-4,12,5,NV,9,2,-1,NV,NV,NV,NV,NV},
  {-5,12,-4,NV,-3,14,-2,NV,13,-6,-1,NV,1,8,5,NV,NV,NV,NV,NV},
  {-4,12,-3,NV,9,-6,-1,NV,-5,4,13,NV,1,10,-2,NV,NV,NV,NV,NV},
  {-5,-6,9,NV,-4,12,-3,NV,13,2,-1,NV,5,8,-2,NV,NV,NV,NV,NV},
  {-5,12,5,NV,-4,2,-3,NV,13,-6,-1,NV,1,8,-2,NV,NV,NV,NV,NV},
  {-5,4,-4,NV,1,12,-3,NV,13,-6,-1,NV,5,8,-2,NV,NV,NV,NV,NV}
};


const unsigned char triangles7[][3] = { 
  {0,1,2}, {0,2,3}, {0,3,4}, {0,4,5}, {0,5,6}, {0,3,6}, {3,5,6}, {3,4,5}, {0,4,6},
  {4,5,6}, {0,3,5}, {3,4,6}, {0,2,4}, {2,3,4}, {0,2,6}, {2,5,6}, {2,4,5}, {0,2,5},
  {2,4,6}, {2,3,5}, {2,3,6}, {0,1,3}, {1,2,3}, {0,1,4}, {1,3,4}, {0,1,6}, {1,5,6},
  {1,4,5}, {0,1,5}, {1,4,6}, {1,3,5}, {1,3,6}, {1,2,4}, {1,2,5}, {1,2,6}
};
const uint64_t triangle_in_triangul7[] = {
  16383, 31, 81925, 268976161, 294512118057, 294930, 1099578773506, 2061701913610,
  1075904644, 2273256481428, 131080, 2199157743632, 160, 137170519008, 13888, 584115553344,
  60129542464, 2304, 68719477248, 962072677376, 3298534895616, 507904, 268419072, 1344798720,
  16252928, 4102458179584, 146583584768, 2689597440, 294243008512, 4303355904, 50331648, 201326592,
  8321499136, 438086664192, 3951369912320
 };
const unsigned char triangulations7[][5] = {
  {0,1,2,3,4}, {0,1,5,6,7}, {0,1,2,8,9}, {0,1,4,7,10}, {0,1,5,9,11}, {0,3,4,12,13},
  {0,13,14,15,16}, {0,8,9,12,13}, {0,4,13,16,17}, {0,9,13,14,18}, {0,7,14,15,19},
  {0,4,7,17,19}, {0,6,7,14,20}, {0,9,11,14,20}, {2,3,4,21,22}, {5,6,7,21,22},
  {2,8,9,21,22}, {4,7,10,21,22}, {5,9,11,21,22}, {3,4,22,23,24}, {22,24,25,26,27},
  {8,9,22,23,24}, {4,22,24,27,28}, {9,22,24,25,29}, {7,22,25,26,30}, {4,7,22,28,30},
  {6,7,22,25,31}, {9,11,22,25,31}, {3,4,13,23,32}, {13,25,26,27,32}, {8,9,13,23,32},
  {4,13,27,28,32}, {9,13,25,29,32}, {13,16,25,26,33}, {4,13,16,28,33},
  {13,15,16,25,34}, {9,13,18,25,34}, {7,19,25,26,33}, {4,7,19,28,33},
  {7,15,19,25,34}, {6,7,20,25,34}, {9,11,20,25,34}
};
const signed char triangul_neigh7[][20] = {
  {-2,6,-1,NV,-3,10,1,NV,-4,14,5,NV,-5,18,9,NV,-6,-7,13,NV},
  {-2,6,-1,NV,-3,10,1,NV,13,-7,5,NV,-6,8,17,NV,-5,14,-4,NV},
  {-2,6,-1,NV,-3,10,1,NV,-4,14,5,NV,17,-7,9,NV,-6,12,-5,NV},
  {-2,6,-1,NV,-3,18,1,NV,-6,-7,17,NV,-5,16,-4,NV,13,10,5,NV},
  {-2,6,-1,NV,-3,10,1,NV,17,-7,5,NV,-6,16,-5,NV,13,8,-4,NV},
  {-2,14,-1,NV,-5,10,13,NV,-6,-7,5,NV,17,6,1,NV,-4,12,-3,NV},
  {-2,10,-1,NV,-4,18,-3,NV,13,-7,1,NV,-6,8,17,NV,-5,14,5,NV},
  {-2,14,-1,NV,9,-7,13,NV,-6,4,-5,NV,17,6,1,NV,-4,12,-3,NV},
  {-2,18,-1,NV,-6,-7,17,NV,-4,14,-3,NV,-5,16,9,NV,13,6,1,NV},
  {-2,14,-1,NV,-6,16,-5,NV,-4,18,-3,NV,17,-7,1,NV,5,12,9,NV},
  {-2,10,-1,NV,-5,16,-4,NV,13,-7,1,NV,-6,8,17,NV,5,14,-3,NV},
  {-2,14,-1,NV,-6,-7,13,NV,-5,16,-4,NV,17,6,1,NV,9,12,-3,NV},
  {-2,14,-1,NV,-6,16,9,NV,-5,6,-4,NV,17,-7,1,NV,5,12,-3,NV},
  {-2,14,-1,NV,-6,8,-5,NV,5,16,-4,NV,17,-7,1,NV,9,12,-3,NV},
  {-4,6,13,NV,-5,10,1,NV,-6,-7,5,NV,17,2,-1,NV,-3,12,-2,NV},
  {5,-7,13,NV,-6,0,9,NV,-5,6,-4,NV,17,2,-1,NV,-3,12,-2,NV},
  {-4,6,13,NV,9,-7,1,NV,-6,4,-5,NV,17,2,-1,NV,-3,12,-2,NV},
  {-6,-7,9,NV,-5,8,-4,NV,5,2,13,NV,17,10,-1,NV,-3,12,-2,NV},
  {9,-7,13,NV,-6,8,-5,NV,5,0,-4,NV,17,2,-1,NV,-3,12,-2,NV},
  {-5,6,13,NV,-6,-7,1,NV,-3,18,-2,NV,17,2,-1,NV,-4,12,9,NV},
  {-3,6,-2,NV,-4,18,1,NV,13,-7,-1,NV,-6,8,17,NV,-5,14,5,NV},
  {5,-7,13,NV,-6,0,-5,NV,-3,18,-2,NV,17,2,-1,NV,-4,12,9,NV},
  {-6,-7,17,NV,-3,10,-2,NV,-4,14,5,NV,-5,16,9,NV,13,2,-1,NV},
  {-6,16,-5,NV,-3,10,-2,NV,-4,18,5,NV,17,-7,-1,NV,1,12,9,NV},
  {-5,16,-4,NV,-3,18,-2,NV,13,-7,-1,NV,-6,8,17,NV,1,14,5,NV},
  {-6,-7,13,NV,-5,16,-4,NV,-3,18,-2,NV,17,2,-1,NV,5,12,9,NV},
  {-6,16,5,NV,-5,2,-4,NV,-3,18,-2,NV,17,-7,-1,NV,1,12,9,NV},
  {-6,4,-5,NV,1,16,-4,NV,-3,18,-2,NV,17,-7,-1,NV,5,12,9,NV},
  {-5,6,13,NV,-6,-7,1,NV,-4,16,-3,NV,17,2,-1,NV,9,12,-2,NV},
  {-4,16,-3,NV,9,-7,-1,NV,-6,4,13,NV,-5,10,17,NV,1,14,-2,NV},
  {5,-7,13,NV,-6,0,-5,NV,-4,16,-3,NV,17,2,-1,NV,9,12,-2,NV},
  {-6,-7,13,NV,-4,16,-3,NV,-5,12,17,NV,9,2,-1,NV,5,10,-2,NV},
  {-6,12,-5,NV,-4,16,-3,NV,13,-7,-1,NV,1,8,17,NV,5,14,-2,NV},
  {-4,6,-3,NV,-5,16,1,NV,13,-7,-1,NV,-6,8,17,NV,5,14,-2,NV},
  {-6,-7,13,NV,-4,10,-3,NV,-5,16,5,NV,17,2,-1,NV,9,12,-2,NV},
  {-4,10,-3,NV,-6,16,9,NV,-5,6,1,NV,17,-7,-1,NV,5,12,-2,NV},
  {-6,8,-5,NV,-4,10,-3,NV,1,16,5,NV,17,-7,-1,NV,9,12,-2,NV},
  {-5,4,-4,NV,1,16,-3,NV,13,-7,-1,NV,-6,8,17,NV,5,14,-2,NV},
  {-6,-7,13,NV,-5,8,-4,NV,5,16,-3,NV,17,2,-1,NV,9,12,-2,NV},
  {-5,8,-4,NV,-6,16,9,NV,1,6,-3,NV,17,-7,-1,NV,5,12,-2,NV},
  {-6,8,5,NV,-5,2,-4,NV,1,16,-3,NV,17,-7,-1,NV,9,12,-2,NV},
  {-6,4,-5,NV,1,8,-4,NV,5,16,-3,NV,17,-7,-1,NV,9,12,-2,NV}
};


SwapPattern patterns[8] = {
  {0},{0},{0},
  {
    // pattern with 3 points around edge  | 3 tetra in, 2 tetra out
    .triangles = triangles3,
    .num_triangles = 1,
    .triangulations = triangulations3,
    .num_triangulations = 1,
    .triangul_neigh = triangul_neigh3,
    .triangle_in_triangul = triangle_in_triangul3
  },

  {
    // pattern with 4 points around edge  | 4 tetra in, 4 tetra out
    .triangles = triangles4,
    .num_triangles = 4,
    .triangulations = triangulations4,
    .num_triangulations = 2,
    .triangul_neigh = triangul_neigh4,
    .triangle_in_triangul = triangle_in_triangul4
  },

  {
    // pattern with 5 points around edge  | 5 tetra in, 6 tetra out
    .triangles = triangles5,
    .num_triangles = 10,
    .triangulations = triangulations5,
    .num_triangulations = 5,
    .triangul_neigh = triangul_neigh5,
    .triangle_in_triangul = triangle_in_triangul5
  },

  {
    // pattern with 6 points around edge
    .triangles = triangles6,
    .num_triangles = 20,
    .triangulations = triangulations6,
    .num_triangulations = 14,
    .triangul_neigh = triangul_neigh6,
    .triangle_in_triangul = triangle_in_triangul6
  },

  {
    // pattern with 7 points around edge
    .triangles = triangles7,
    .num_triangles = 35,
    .triangulations = triangulations7,
    .num_triangulations = 42, // see Catalan numbers ;)
    .triangul_neigh = triangul_neigh7,
    .triangle_in_triangul = triangle_in_triangul7
  }
};


/**************** that's it for the DATAs ****************/

typedef struct {
  struct {
    HXTGroup2* tetID_dist;
    uint64_t num;
    uint64_t size;
  } badTets;

  struct {
    double* values;
    double threshold;
  } quality2;
} ThreadShared;

typedef struct 
{
  struct {
    uint64_t neigh_up  [HXT_MAX_CAVITY_SIZE];
    uint64_t neigh_down[HXT_MAX_CAVITY_SIZE];
    unsigned char flag [HXT_MAX_CAVITY_SIZE];
    uint32_t annulus   [HXT_MAX_CAVITY_SIZE];
    uint32_t v_up;
    uint32_t v_down;
    uint32_t num;
  } cavity;

  struct {
    uint64_t* tetID;
    uint64_t num;
    uint64_t size;
  } deleted;

  struct {
    uint64_t startDist;
    uint64_t endDist;
    uint32_t first;
    uint32_t length;
  } partition;
} ThreadLocal;



/*
 Compute the squared aspect ratio of a tet. quickly return 0.0 if the tet is inverted
*/
static inline double tetQuality2 (HXTMesh *mesh, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3)
{
  return hxtTetAspectFastRatio (&mesh->vertices.coord[4*p0],
                                &mesh->vertices.coord[4*p1],
                                &mesh->vertices.coord[4*p2],
                                &mesh->vertices.coord[4*p3]);
}

/***********************************************
           re-allocation functions
 ***********************************************/
static HXTStatus synchronizeReallocation(HXTMesh* mesh, ThreadShared* shared, volatile int* toCopy, volatile int* copy){
  // threads cant be doing something while the realloc portion happen
  #pragma omp barrier
  
  // this unable us to have the same value of toCopy for everyone, as we are sure nothing happens to those variables here
  if(toCopy!=copy){
    *copy = *toCopy;
  }

  HXTStatus status = HXT_STATUS_OK;
  // make reallocations in a critical section
  #pragma omp single
  {
    if(mesh->tetrahedra.num > mesh->tetrahedra.size){
      status = hxtAlignedRealloc(&shared->quality2.values, sizeof(double)*mesh->tetrahedra.num);
      if(status==HXT_STATUS_OK) status = hxtTetrahedraReserve(mesh, mesh->tetrahedra.num);
    }
  } // implicit barrier here

  if(status!=HXT_STATUS_OK)
    HXT_TRACE(status);
  
  return status;
}

static inline HXTStatus reserveNewDeleted(ThreadLocal* local, uint64_t num){
  num += local->deleted.num;
  if(num > local->deleted.size){
      HXT_CHECK( hxtAlignedRealloc(&local->deleted.tetID, 2*num*sizeof(uint64_t)) );
      local->deleted.size = 2*num;
  }

  return HXT_STATUS_OK;
}


static inline HXTStatus createNewDeleted(HXTMesh* mesh, ThreadShared* shared, ThreadLocal* local) {
  uint64_t needed = DELETED_BUFFER_SIZE-local->deleted.num;

  uint64_t ntet;

  // TODO: when multi-threading, don't forget atomic operation and critical sections
  #pragma omp atomic capture
  { ntet = mesh->tetrahedra.num; mesh->tetrahedra.num+=needed;}

  HXT_CHECK( synchronizeReallocation(mesh, shared, NULL, NULL) );
  HXT_CHECK( reserveNewDeleted(local, needed) );

  #pragma omp simd
  for (uint64_t i=0; i<needed; i++){
    local->deleted.tetID[local->deleted.num+i] = ntet+i;
    shared->quality2.values[ntet+i] = DBL_MAX;
    // setDeletedFlag(mesh, ntet+i);
    // printf("adding tet %lu to deleted[%lu]\n", ntet+i, local->deleted.num+i);
  }

  local->deleted.num = DELETED_BUFFER_SIZE;
  return HXT_STATUS_OK;
}

// suppose that the right capacity for quality2 values is already allocated
static HXTStatus threadShared_update(HXTMesh* mesh, ThreadShared* shared) {
  int maxThreads = omp_get_max_threads();
  HXTStatus status = HXT_STATUS_OK;

  uint64_t* badTetsCount;
  HXT_CHECK( hxtMalloc(&badTetsCount, maxThreads*sizeof(uint64_t)) );

  #pragma omp parallel
  {
    int threadID = omp_get_thread_num();
    badTetsCount[threadID] = 0;

    #pragma omp for schedule(static)
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(mesh->tetrahedra.colors[i]!=UINT16_MAX && shared->quality2.values[i]<shared->quality2.threshold)
        badTetsCount[threadID]++;
    }

    #pragma omp barrier
    #pragma omp single
    {
      int nthreads = omp_get_num_threads();
      shared->badTets.num = 0;
      for (int i=0; i<nthreads; i++) {
        uint64_t tsum = badTetsCount[i] + shared->badTets.num;
        badTetsCount[i] = shared->badTets.num;
        shared->badTets.num = tsum;
      }

      if(shared->badTets.num > shared->badTets.size){
        status = hxtAlignedRealloc(&shared->badTets.tetID_dist, sizeof(HXTGroup2)*shared->badTets.num);
        shared->badTets.size = shared->badTets.num;
      }
    }

    if(status==HXT_STATUS_OK){
      #pragma omp for schedule(static)
      for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
        if(mesh->tetrahedra.colors[i]!=UINT16_MAX && shared->quality2.values[i]<shared->quality2.threshold){
          uint64_t badTetsID = badTetsCount[threadID]++;
          shared->badTets.tetID_dist[badTetsID].v[1] = i;
        }
      }
    }
  }
  HXT_CHECK( hxtFree(&badTetsCount) );

  return status;
}


static HXTStatus threadShared_create(HXTMesh *mesh, double qualityThreshold, ThreadShared** shared) {
  ThreadShared* newShared;
  HXT_CHECK( hxtMalloc(&newShared, sizeof(ThreadShared)));

  if(qualityThreshold<0.0)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "quality threshold must be positive");

  newShared->badTets.num = 0;
  newShared->badTets.size = 0;
  newShared->quality2.threshold = qualityThreshold*qualityThreshold/24.;
  HXT_CHECK( hxtAlignedMalloc(&newShared->quality2.values, sizeof(double)*mesh->tetrahedra.size) );
  newShared->badTets.tetID_dist = NULL;

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    uint32_t* nodes = mesh->tetrahedra.node + 4*i;
    if(nodes[3]==HXT_GHOST_VERTEX)
      newShared->quality2.values[i] = DBL_MAX; // exterior tetrahedra have maximum quality
    else
      newShared->quality2.values[i] = tetQuality2(mesh, nodes[0], nodes[1], nodes[2], nodes[3]);
  }

  *shared = newShared;
  return HXT_STATUS_OK;
}



static HXTStatus threadShared_destroy(ThreadShared** shared) {
  HXT_CHECK( hxtAlignedFree(&(*shared)->quality2.values) );
  HXT_CHECK( hxtAlignedFree(&(*shared)->badTets.tetID_dist) );
  HXT_CHECK( hxtFree(shared) );
  return HXT_STATUS_OK;
}


static inline int vertexOutOfPartition(HXTVertex* vertices, uint32_t v, uint64_t rel, uint64_t startDist) {
  return vertices[v].padding.hilbertDist - startDist >= rel;
}


static HXTStatus threadLocals_create(ThreadLocal** locals_ptr, int nthreads) {
  ThreadLocal* newLocal;
  HXT_CHECK( hxtMalloc(&newLocal, nthreads*sizeof(ThreadLocal)));

  for (int threadID=0; threadID<nthreads; threadID++) {
    newLocal[threadID].deleted.num = 0;
    newLocal[threadID].deleted.size = DELETED_BUFFER_SIZE;
    HXT_CHECK( hxtAlignedMalloc(&newLocal[threadID].deleted.tetID,
                                sizeof(uint64_t)*DELETED_BUFFER_SIZE) );
  }

  *locals_ptr = newLocal;
  return HXT_STATUS_OK;
}

static HXTStatus threadLocals_update(HXTMesh* mesh, HXTBbox* bbox, double minSize,
                                     ThreadShared* shared, ThreadLocal* locals,
                                     int nthreads, uint32_t* seed, int changePartitions, uint64_t* nConflict_ptr, uint32_t* nbits) {

  if(nthreads>1) {
    HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
    HXTGroup2* badTets = shared->badTets.tetID_dist;

    double indexShift_percent = (double) hxtReproducibleLCG(seed)/RAND_MAX;

    if(changePartitions) {
      double hxtDeclareAligned bboxShift[3];

      bboxShift[0] = (double) hxtReproducibleLCG(seed)/RAND_MAX;
      bboxShift[1] = (double) hxtReproducibleLCG(seed)/RAND_MAX;
      bboxShift[2] = (double) hxtReproducibleLCG(seed)/RAND_MAX;

      *nbits = hxtAdvancedHilbertBits(bbox, minSize, minSize,
                                      mesh->vertices.num,
                                      mesh->vertices.num,
                                      mesh->vertices.num,
                                      shared->badTets.num,
                                      nthreads);

      HXT_CHECK( hxtVerticesHilbertDist(bbox, vertices, mesh->vertices.num, nbits, bboxShift) );
    }

    #pragma omp parallel for simd aligned(badTets:SIMD_ALIGN)
    for (uint64_t i=0; i<shared->badTets.num; i++) {
      uint32_t firstNode = mesh->tetrahedra.node[4*badTets[i].v[1]];
      badTets[i].v[0] = vertices[firstNode].padding.hilbertDist;
    }

    // sort the bad tetrahedrons following their first node hilbert dist
    HXT_CHECK(  group2_sort_v0(badTets, shared->badTets.num, (UINT64_C(1)<<(*nbits)) - 1) );

    const uint64_t step = shared->badTets.num/nthreads;
    uint64_t indexShift = MIN(step-1,(uint64_t) indexShift_percent*step);
    uint64_t nConflict = 0;

    #pragma omp parallel num_threads(nthreads) reduction(+:nConflict)
    {
      const int threadID = omp_get_thread_num();

      uint64_t first = step*threadID + indexShift;
      uint64_t startDist = badTets[first].v[0];

      uint64_t up = 1;
      while(first+up<shared->badTets.num && startDist==badTets[first + up].v[0])
        up++;

      first = first+up==shared->badTets.num?0:first+up;
      if(first > 0)
        startDist = (badTets[first].v[0]
                                              + badTets[first - 1].v[0] + 1)/2;
      else
        startDist = badTets[shared->badTets.num-1].v[0] + 
                            (badTets[first].v[0] - badTets[shared->badTets.num - 1].v[0])/2;

      locals[threadID].partition.first = first;
      locals[threadID].partition.startDist = startDist;

      #pragma omp barrier

      uint64_t firstNext = locals[(threadID+1)%nthreads].partition.first;
      uint64_t endDist = locals[(threadID+1)%nthreads].partition.startDist;
      locals[threadID].partition.length = (firstNext + shared->badTets.num - first)%shared->badTets.num;
      locals[threadID].partition.endDist = endDist;

      uint64_t rel = startDist - endDist;

      // dismiss tetrahedron that are in our list but not in our partition
      for (uint64_t i=0; i<locals[threadID].partition.length; i++) {
        uint64_t index = (locals[threadID].partition.first + i)%shared->badTets.num;
        uint64_t curTet = shared->badTets.tetID_dist[index].v[1];

        uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;

        if(vertexOutOfPartition(vertices, nodes[0], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[1], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[2], rel, startDist) + 
           vertexOutOfPartition(vertices, nodes[3], rel, startDist) > 1) {
          shared->badTets.tetID_dist[index].v[1] = HXT_NO_ADJACENT;
          nConflict++;
        }
      }
    }

    *nConflict_ptr+=nConflict;
  }
  else {
    locals[0].partition.startDist = 0;
    locals[0].partition.endDist = UINT64_MAX;
    locals[0].partition.first = 0;
    locals[0].partition.length = shared->badTets.num;
  }

  return HXT_STATUS_OK;
}


static HXTStatus threadLocals_destroy(ThreadLocal** local, int nthreads) {
  for (int threadID=0; threadID<nthreads; threadID++) {
    HXT_CHECK( hxtAlignedFree(&(*local)[threadID].deleted.tetID) );
  }
  HXT_CHECK( hxtFree(local) );
  return HXT_STATUS_OK;
}


// static HXTStatus flip2_3(HXTMesh* mesh, ThreadShared* shared, ThreadLocal* local,
//                          const uint64_t tet_0, uint16_t color, unsigned out_facet_0)
// {
//   if(getFacetConstraint(mesh, tet_0, out_facet_0) || mesh->tetrahedra.neigh[4*tet_0 + out_facet_0]==HXT_NO_ADJACENT)
//     return HXT_STATUS_INTERNAL;

//   uint64_t neigh = mesh->tetrahedra.neigh[4*tet_0 + out_facet_0];
  

//   uint64_t tet_1 = neigh/4;

//   HXT_ASSERT(tet_1<mesh->tetrahedra.num);
//   HXT_ASSERT(tet_1!=tet_0);
//   HXT_ASSERT(mesh->tetrahedra.neigh[neigh]==4*tet_0 + out_facet_0);
//   unsigned in_facet_1 = neigh%4;

//   { // check for conflict with other threads'partition
//     const uint64_t startDist = local->partition.startDist;
//     const uint64_t rel = local->partition.endDist - startDist;
//     HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
//     if(vertexOutOfPartition(vertices, mesh->tetrahedra.node[4*tet_1 + 0], rel, startDist) +
//        vertexOutOfPartition(vertices, mesh->tetrahedra.node[4*tet_1 + 1], rel, startDist) +
//        vertexOutOfPartition(vertices, mesh->tetrahedra.node[4*tet_1 + 2], rel, startDist) +
//        vertexOutOfPartition(vertices, mesh->tetrahedra.node[4*tet_1 + 3], rel, startDist) > 1)
//        return HXT_STATUS_CONFLICT;
//    }

//   double worst_qual = shared->quality2.values[tet_0];

//   if(shared->quality2.values[tet_1]<worst_qual)
//     worst_qual = shared->quality2.values[tet_1];

//   local->cavity.v_up = mesh->tetrahedra.node[4*tet_0 + out_facet_0];
//   local->cavity.v_down = mesh->tetrahedra.node[4*tet_1 + in_facet_1];

//   // choose a reference facet in the tet_0
//   unsigned in_facet_0 = (out_facet_0+1)%4;

//   // adding vertices of the annulus:
//   local->cavity.annulus[0] = mesh->tetrahedra.node[4*tet_0 + UP_VERTEX(in_facet_0, out_facet_0)];
//   local->cavity.annulus[1] = mesh->tetrahedra.node[4*tet_0 + DOWN_VERTEX(in_facet_0, out_facet_0)];
//   local->cavity.annulus[2] = mesh->tetrahedra.node[4*tet_0 + OUT_VERTEX(in_facet_0, out_facet_0)];

//   local->cavity.neigh_up[0] = mesh->tetrahedra.neigh[4*tet_0 + in_facet_0];
//   local->cavity.neigh_up[1] = mesh->tetrahedra.neigh[4*tet_0 + DOWN_FACET(in_facet_0, out_facet_0)];
//   local->cavity.neigh_up[2] = mesh->tetrahedra.neigh[4*tet_0 + UP_FACET(in_facet_0, out_facet_0)];

//   uint32_t v = local->cavity.annulus[2];

//   // find one of the vertex in the tet_1
//   uint32_t* nodes = mesh->tetrahedra.node + 4*tet_1;

//   unsigned out_facet_1;
//   for (out_facet_1=0; out_facet_1<4; out_facet_1++)
//       if(nodes[out_facet_1]==v)
//         break;

//   // HXT_ASSERT(out_facet_1!=4);
//   // HXT_ASSERT(out_facet_1!=in_facet_1);
//   // HXT_ASSERT((isEdgeConstrainedSafe(mesh, tet_0, in_facet_0, out_facet_0)!=0)==(isEdgeConstrainedSafe(mesh, tet_1, in_facet_1, out_facet_1)!=0));
//   // HXT_ASSERT((isEdgeConstrainedSafe(mesh, tet_0, in_facet_0, out_facet_0)!=0)==(isEdgeConstrainedSafe(mesh, tet_1, in_facet_1, out_facet_1)!=0));
//   // HXT_ASSERT((isEdgeConstrainedSafe(mesh, tet_0, DOWN_FACET(in_facet_0, out_facet_0), out_facet_0)!=0)
//   //          ==(isEdgeConstrainedSafe(mesh, tet_1, DOWN_FACET(in_facet_1, out_facet_1), in_facet_1)!=0));
//   // HXT_ASSERT((isEdgeConstrainedSafe(mesh, tet_0, UP_FACET(in_facet_0, out_facet_0), out_facet_0)!=0)
//   //          ==(isEdgeConstrainedSafe(mesh, tet_1, UP_FACET(in_facet_1, out_facet_1), in_facet_1)!=0));
//   // HXT_ASSERT((getFacetConstraint(mesh, tet_0, out_facet_0)!=0)==(getFacetConstraint(mesh, tet_1, in_facet_1)!=0));
//   // if(mesh->tetrahedra.neigh[neigh]!=4*tet_0+out_facet_0)
//   //   return HXT_ERROR_MSG(HXT_STATUS_ERROR, "mesh->tetrahedra.neigh[%lu]==%lu instead of %lu",neigh,mesh->tetrahedra.neigh[neigh],4*tet_0+out_facet_0);

//   local->cavity.neigh_down[0] = mesh->tetrahedra.neigh[4*tet_1 + out_facet_1];
//   local->cavity.neigh_down[1] = mesh->tetrahedra.neigh[4*tet_1 + DOWN_FACET(in_facet_1, out_facet_1)];
//   local->cavity.neigh_down[2] = mesh->tetrahedra.neigh[4*tet_1 + UP_FACET(in_facet_1, out_facet_1)];

//   local->cavity.flag[0] = ((getFacetConstraint(mesh, tet_0, in_facet_0)!=0)<<12) +
//                           ((getFacetConstraint(mesh, tet_1, out_facet_1)!=0)<<8) +
//                           ((isEdgeConstrainedSafe(mesh, tet_1, out_facet_1, DOWN_FACET(in_facet_1, out_facet_1))!=0)<<2) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, in_facet_0, DOWN_FACET(in_facet_0, out_facet_0))!=0)<<3) +
//                           ((isEdgeConstrainedSafe(mesh, tet_1, out_facet_1, UP_FACET(in_facet_1, out_facet_1))!=0)<<6) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, in_facet_0, UP_FACET(in_facet_0, out_facet_0))!=0)<<7) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, in_facet_0, out_facet_0)!=0)<<11);

//   local->cavity.flag[1] = ((getFacetConstraint(mesh, tet_0, DOWN_FACET(in_facet_0, out_facet_0))!=0)<<12) +
//                           ((getFacetConstraint(mesh, tet_1, DOWN_FACET(in_facet_1, out_facet_1))!=0)<<8) +
//                           ((isEdgeConstrainedSafe(mesh, tet_1, DOWN_FACET(in_facet_1, out_facet_1), UP_FACET(in_facet_1, out_facet_1))!=0)<<2) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, DOWN_FACET(in_facet_0, out_facet_0), UP_FACET(in_facet_0, out_facet_0))!=0)<<3) +
//                           ((isEdgeConstrainedSafe(mesh, tet_1, DOWN_FACET(in_facet_1, out_facet_1), out_facet_1)!=0)<<6) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, DOWN_FACET(in_facet_0, out_facet_0), in_facet_0)!=0)<<7) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, DOWN_FACET(in_facet_0, out_facet_0), out_facet_0)!=0)<<11);

//   local->cavity.flag[2] = ((getFacetConstraint(mesh, tet_0, UP_FACET(in_facet_0, out_facet_0))!=0)<<12) +
//                           ((getFacetConstraint(mesh, tet_1, UP_FACET(in_facet_1, out_facet_1))!=0)<<8) +
//                           ((isEdgeConstrainedSafe(mesh, tet_1, UP_FACET(in_facet_1, out_facet_1), out_facet_1)!=0)<<2) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, UP_FACET(in_facet_0, out_facet_0), in_facet_0)!=0)<<3) +
//                           ((isEdgeConstrainedSafe(mesh, tet_1, UP_FACET(in_facet_1, out_facet_1), DOWN_FACET(in_facet_1, out_facet_1))!=0)<<6) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, UP_FACET(in_facet_0, out_facet_0), DOWN_FACET(in_facet_0, out_facet_0))!=0)<<7) +
//                           ((isEdgeConstrainedSafe(mesh, tet_0, UP_FACET(in_facet_0, out_facet_0), out_facet_0)!=0)<<11);

//   // now we have everything... we just need to test if the quality of tetrahedra would be good
//   double qual[3];
//   for (int i=0; i<3; i++) {
//     qual[i] = tetQuality2(mesh, local->cavity.annulus[i], local->cavity.annulus[(i+1)%3], local->cavity.v_up, local->cavity.v_down);
//     if(qual[i]<worst_qual){
//       return HXT_STATUS_INTERNAL;
//     }
//   }

//   if(local->deleted.num<1)
//     HXT_CHECK( createNewDeleted(mesh, shared, local) );

//   local->deleted.num--;
//   uint64_t newTet[3] = {tet_0, tet_1, local->deleted.tetID[local->deleted.num]};

//   for (unsigned i=0; i<3; i++) {
//     uint64_t curTet = newTet[i];
//     mesh->tetrahedra.node[4*curTet + 0] = local->cavity.annulus[i];
//     mesh->tetrahedra.node[4*curTet + 1] = local->cavity.annulus[(i+1)%3];
//     mesh->tetrahedra.node[4*curTet + 2] = local->cavity.v_up;
//     mesh->tetrahedra.node[4*curTet + 3] = local->cavity.v_down;

//     mesh->tetrahedra.neigh[4*curTet + 0] = 4*newTet[(i+1)%3] + 1;
//     // mesh->tetrahedra.neigh[4*curTet + 1] = 4*newTet[(i+4)%3] + 0;
//     mesh->tetrahedra.neigh[4*newTet[(i+1)%3] + 1] = 4*curTet + 0;

//     mesh->tetrahedra.neigh[4*curTet + 2] = local->cavity.neigh_down[i];
//     if( local->cavity.neigh_down[i]!=HXT_NO_ADJACENT)
//       mesh->tetrahedra.neigh[local->cavity.neigh_down[i]] = 4*curTet + 2;

//     mesh->tetrahedra.neigh[4*curTet + 3] = local->cavity.neigh_up[i];
//     if( local->cavity.neigh_up[i]!=HXT_NO_ADJACENT)
//       mesh->tetrahedra.neigh[local->cavity.neigh_up[i]] = 4*curTet + 3;

//     mesh->tetrahedra.colors[curTet] = color;

//     // TODO: verify flags are well done
//     mesh->tetrahedra.flag[curTet] = local->cavity.flag[i];
//     shared->quality2.values[curTet] = qual[i];
//   }

//   return HXT_STATUS_OK;
//   // return HXT_STATUS_INTERNAL;
// }


static inline HXTStatus buildEdgeCavity(HXTMesh* mesh, ThreadLocal* local,
                                        const uint64_t badTet,
                                        unsigned in_facet, unsigned out_facet)
{
  const uint64_t startDist = local->partition.startDist;
  const uint64_t rel = local->partition.endDist - startDist;
  int edgeOut = 0;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  uint64_t curTet = badTet;
  local->cavity.num = 0;

  if(getEdgeConstraint(mesh, badTet, getEdgeFromFacets(in_facet, out_facet)))
    return HXT_STATUS_INTERNAL;

  local->cavity.v_up = mesh->tetrahedra.node[4*badTet + UP_VERTEX(in_facet, out_facet)];
  edgeOut += vertexOutOfPartition(vertices, local->cavity.v_up, rel, startDist);
  local->cavity.v_down = mesh->tetrahedra.node[4*badTet + DOWN_VERTEX(in_facet, out_facet)];
  edgeOut += vertexOutOfPartition(vertices, local->cavity.v_down, rel, startDist);

  HXT_CHECK( reserveNewDeleted(local, 7) );

  do{
    // add the current tetrahedra
    local->deleted.tetID[local->deleted.num + local->cavity.num] = curTet;

    {
      unsigned up_facet = UP_FACET(in_facet, out_facet);
      unsigned down_facet = DOWN_FACET(in_facet, out_facet);

      // add the neighbor up and down
      local->cavity.neigh_up[local->cavity.num] = mesh->tetrahedra.neigh[4*curTet + up_facet];
      local->cavity.neigh_down[local->cavity.num] = mesh->tetrahedra.neigh[4*curTet + down_facet];

      int upDownEdge = getEdgeFromFacets(up_facet, down_facet);
      int upOutEdge = getEdgeFromFacets(up_facet, out_facet);
      int upInEdge = getEdgeFromFacets(up_facet, in_facet);
      int downOutEdge = getEdgeFromFacets(down_facet, out_facet);
      int downInEdge = getEdgeFromFacets(down_facet, in_facet);


      // TODO: just store one flag for up and down. the one of the default tetrahedron
      local->cavity.flag[local->cavity.num] = (getFacetConstraint(mesh, curTet, up_facet)!=0) +
                                              ((getEdgeConstraint(mesh, curTet, upOutEdge)!=0)<<1) +
                                              ((getEdgeConstraint(mesh, curTet, upDownEdge)!=0)<<2) +
                                              ((getEdgeConstraint(mesh, curTet, upInEdge)!=0)<<3) +
                                              ((getFacetConstraint(mesh, curTet, down_facet)!=0)<<4) +
                                              ((getEdgeConstraint(mesh, curTet, downOutEdge)!=0)<<5) +
                                              ((getEdgeConstraint(mesh, curTet, downInEdge)!=0)<<6) +
                                              ((getEdgeConstraint(mesh, curTet, upDownEdge)!=0)<<7);
    }
    // add the annulus vertex
    uint32_t oldV = mesh->tetrahedra.node[4*curTet + out_facet];
    uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

    local->cavity.annulus[local->cavity.num] = oldV;
    local->cavity.num++;

    // go into the neighbor through out_facet
    uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
    if(neigh == HXT_NO_ADJACENT
      || (getFacetConstraint(mesh, neigh/4, neigh%4)!=0)
      || local->cavity.num>=HXT_MAX_CAVITY_SIZE) {
      return HXT_STATUS_INTERNAL;
    }

    if(vertexOutOfPartition(vertices, oldV, rel, startDist) +
       vertexOutOfPartition(vertices, newV, rel, startDist) + edgeOut > 1) {
      return HXT_STATUS_CONFLICT;
  }

    curTet = neigh/4;
    in_facet = neigh%4;

    uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;

    for (out_facet=0; out_facet<3; out_facet++)
      if(nodes[out_facet]==newV)
        break;

  }while(curTet!=badTet);

  return HXT_STATUS_OK;
}


static HXTStatus edgeSwap(HXTMesh *mesh, ThreadShared* shared, ThreadLocal* local,
                             const uint64_t badTet, const uint16_t color,
                             unsigned in_facet, unsigned out_facet)
{
  HXT_CHECK( buildEdgeCavity(mesh, local, badTet, in_facet, out_facet) );

  // find worst quality2 tet of the cavity
  double worst = DBL_MAX;
  for (uint64_t i=0; i<local->cavity.num; i++) {
    uint64_t tet = local->deleted.tetID[local->deleted.num+i];
    double qual = shared->quality2.values[tet];
    if(qual<worst)
      worst = qual;
  }

  const SwapPattern* patt = &patterns[local->cavity.num];
  const unsigned num_triangle_per_triangul = local->cavity.num-2;
  uint32_t* annulus = local->cavity.annulus;

  // calculate qualities of all possible tetrahedra
  // TODO: optimize the fact that a facet is common in qual_up and qual_down
  double hxtDeclareAligned qual_up[35];
  double hxtDeclareAligned qual_down[35];
  uint64_t mask = 0;
  for (unsigned i=0; i<patt->num_triangles; i++) {
    uint32_t p0 = annulus[patt->triangles[i][0]];
    uint32_t p1 = annulus[patt->triangles[i][1]];
    uint32_t p2 = annulus[patt->triangles[i][2]];

    // printf("%u %u %u\n", p0, p1, p2);

    qual_up[i] = tetQuality2(mesh, p0, p1, local->cavity.v_up, p2);
    qual_down[i] = tetQuality2(mesh, p0, p1, p2, local->cavity.v_down);

    if(qual_up[i]<=worst || qual_down[i]<=worst)
      mask |= patt->triangle_in_triangul[i];
  }

  // find the best triangulation
  int best_triangulation = -1;
  double best_worst = 0;
  for (unsigned i=0; i<patt->num_triangulations; i++) {
    if((mask & (UINT64_C(1)<<i))==0) {
      double cur_worst = DBL_MAX;
      // this mean that no triangle in the triangulation
      //   is worst than the current worst tetrahedron
      for (unsigned j=0; j<num_triangle_per_triangul; j++) {
        double q_u = qual_up[patt->triangulations[i][j]];
        double q_d = qual_down[patt->triangulations[i][j]];
        if(q_u<best_worst || q_d<best_worst){
          cur_worst = 0;
          break;
        }
        if(q_u<cur_worst)
          cur_worst = q_u;
        if(q_d<cur_worst)
          cur_worst = q_d;
      }

      if(cur_worst > best_worst){
        best_worst = cur_worst;
        best_triangulation = i;
      }
    }
  }

  // if no triangulation are better, return
  if(best_triangulation==-1) {
    return HXT_STATUS_INTERNAL;
  }
  
  
  // mark new deleted tet as deleted
  for (uint64_t i=0; i<local->cavity.num; i++) {
    shared->quality2.values[local->deleted.tetID[local->deleted.num+i]] = DBL_MAX; // deleted tets have good quality2
    // setDeletedFlag(mesh, local->deleted.tetID[local->deleted.num+i]);
  }
  local->deleted.num += local->cavity.num;

  // reserve enough tetrahedra
  if(2*num_triangle_per_triangul > local->deleted.num){ // tetrahedra are created...
    HXT_CHECK(createNewDeleted(mesh, shared, local) );
  }

  uint64_t start = local->deleted.num - 2*num_triangle_per_triangul;

  // make the swap
  for (unsigned i=0; i<num_triangle_per_triangul; i++) {
    uint32_t tri = patt->triangulations[best_triangulation][i];
    uint32_t p0 = annulus[patt->triangles[tri][0]];
    uint32_t p1 = annulus[patt->triangles[tri][1]];
    uint32_t p2 = annulus[patt->triangles[tri][2]];

    // neighbor information. if positive, the neighbor is a new tetrahedra
    int n0 = patt->triangul_neigh[best_triangulation][4*i];
    int n1 = patt->triangul_neigh[best_triangulation][4*i+1];
    int n2 = patt->triangul_neigh[best_triangulation][4*i+2];

    const uint64_t newTet_up = local->deleted.tetID[start + i*2];
    const uint64_t newTet_down = local->deleted.tetID[start + i*2 + 1];

    // create the upper tet.
    {
      uint32_t* nodes = mesh->tetrahedra.node + 4*newTet_up;
      uint64_t* neigh = mesh->tetrahedra.neigh + 4*newTet_up;

      mesh->tetrahedra.colors[newTet_up] = color;
      mesh->tetrahedra.flag[newTet_up] = 0;
      shared->quality2.values[newTet_up] = qual_up[tri];

      nodes[0] = p0;
      nodes[1] = p1;
      nodes[2] = local->cavity.v_up;
      nodes[3] = p2;

      if(n0>=0){
        neigh[0] = 4*local->deleted.tetID[start + (n0/4)*2] + (n0%4) + (n0%4)/2;
      }
      else {
        neigh[0] = local->cavity.neigh_up[-n0-1];

        //  (down=2, in=3, out=1, up=0)
        mesh->tetrahedra.flag[newTet_up] |= (local->cavity.flag[-n0-1]&1)<<8 |// face (bit 0) is the up_facet => 0  (bit 8)
                                            (local->cavity.flag[-n0-1]&2)>>1 |// first edge (bit 1) was between up_facet and out_facet => 0-1  (bit 0)
                                            (local->cavity.flag[-n0-1]&4)>>1 |// second edge (bit 2) was between up_facet and down_facet => 0-2 (bit 1)
                                            (local->cavity.flag[-n0-1]&8)>>1; // third edge (bit 3) was between up_facet and in_facet => 0-3    (bit 2)

        if(neigh[0]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[0]] = 4*newTet_up + 0;
      }
      if(n1>=0){
        neigh[1] = 4*local->deleted.tetID[start + (n1/4)*2] + (n1%4) + (n1%4)/2;
      }
      else {
        neigh[1] = local->cavity.neigh_up[-n1-1];

        //  (down=2, in=0, out=3, up=1)
        mesh->tetrahedra.flag[newTet_up] |= (local->cavity.flag[-n1-1]&1)<<9 |// face (bit 0) is the up_facet => 1  (bit 9)
                                            (local->cavity.flag[-n1-1]&2)<<3 |// first edge (bit 1) was between up_facet and out_facet => 1-3   (bit 4)
                                            (local->cavity.flag[-n1-1]&4)<<1 |// second edge (bit 2) was between up_facet and down_facet => 1-2 (bit 3)
                                            (local->cavity.flag[-n1-1]&8)>>3; // third edge (bit 3) was between up_facet and in_facet => 0-1    (bit 0)

        if(neigh[1]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[1]] = 4*newTet_up + 1;
      }
      neigh[2] = newTet_down*4 + 3;
      if(n2>=0){
        neigh[3] = 4*local->deleted.tetID[start + (n2/4)*2] + (n2%4) + (n2%4)/2;
      }
      else {
        neigh[3] = local->cavity.neigh_up[-n2-1];

        //  (down=2, in=1, out=0, up=3)
        mesh->tetrahedra.flag[newTet_up] |= (local->cavity.flag[-n2-1]&1)<<11 |// face (bit 0) is the up_facet => 3  (bit 11)
                                            (local->cavity.flag[-n2-1]&2)<<1  |// first edge (bit 1) was between up_facet and out_facet => 0-3   (bit 2)
                                            (local->cavity.flag[-n2-1]&4)<<3  |// second edge (bit 2) was between up_facet and down_facet => 2-3 (bit 5)
                                            (local->cavity.flag[-n2-1]&8)<<1;  // third edge (bit 3) was between up_facet and in_facet => 1-3    (bit 4)

        if(neigh[3]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[3]] = 4*newTet_up + 3;
      }
    }

    // create the down tet.
    {
      uint32_t* nodes = mesh->tetrahedra.node + 4*newTet_down;
      uint64_t* neigh = mesh->tetrahedra.neigh + 4*newTet_down;

      mesh->tetrahedra.colors[newTet_down] = color;
      mesh->tetrahedra.flag[newTet_down] = 0;
      shared->quality2.values[newTet_down] = qual_down[tri];

      nodes[0] = p0;
      nodes[1] = p1;
      nodes[2] = p2;
      nodes[3] = local->cavity.v_down;

      if(n0>=0){
        neigh[0] = 4*local->deleted.tetID[start + (n0/4)*2 +1] + (n0%4);
      }
      else {
        neigh[0] = local->cavity.neigh_down[-n0-1];

        //  (down=0, in=2, out=1, up=3)
        mesh->tetrahedra.flag[newTet_down] |= (local->cavity.flag[-n0-1]&16)<<4 |// face (bit 4) is the down_facet => 0  (bit 8)
                                              (local->cavity.flag[-n0-1]&32)>>5 |// first edge (bit 5) was between down_facet and out_facet => 0-1   (bit 0)
                                              (local->cavity.flag[-n0-1]&64)>>5 |// second edge (bit 6) was between down_facet and in_facet => 0-2   (bit 1)
                                              (local->cavity.flag[-n0-1]&128)>>5;// third edge (bit 7) was between down_facet and up_facet => 0-3    (bit 2)

        if(neigh[0]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[0]] = 4*newTet_down + 0;
      }
      if(n1>=0){
        neigh[1] = 4*local->deleted.tetID[start + (n1/4)*2 +1] + (n1%4);
      }
      else {
        neigh[1] = local->cavity.neigh_down[-n1-1];

        //  (down=1, in=0, out=2, up=3)
        mesh->tetrahedra.flag[newTet_down] |= (local->cavity.flag[-n1-1]&16)<<5 |// face (bit 4) is the down_facet => 1  (bit 9)
                                              (local->cavity.flag[-n1-1]&32)>>2 |// first edge (bit 5) was between down_facet and out_facet => 1-2   (bit 3)
                                              (local->cavity.flag[-n1-1]&64)>>6 |// second edge (bit 6) was between down_facet and in_facet => 0-1   (bit 0)
                                              (local->cavity.flag[-n1-1]&128)>>3;// third edge (bit 7) was between down_facet and up_facet => 1-3    (bit 4)

        if(neigh[1]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[1]] = 4*newTet_down + 1;
      }
      if(n2>=0){
        neigh[2] = 4*local->deleted.tetID[start + (n2/4)*2 +1] + (n2%4);
      }
      else {
        neigh[2] = local->cavity.neigh_down[-n2-1];

        //  (down=2, in=1, out=0, up=3)
        mesh->tetrahedra.flag[newTet_down] |= (local->cavity.flag[-n2-1]&16)<<6 |// face (bit 4) is the down_facet => 2*4  (bit 10)
                                              (local->cavity.flag[-n2-1]&32)>>4 |// first edge (bit 5) was between down_facet and out_facet => 0-2   (bit 1)
                                              (local->cavity.flag[-n2-1]&64)>>3 |// second edge (bit 6) was between down_facet and in_facet => 1-2   (bit 3)
                                              (local->cavity.flag[-n2-1]&128)>>2;// third edge (bit 7) was between down_facet and up_facet => 2-3    (bit 5)

        if(neigh[2]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[2]] = 4*newTet_down + 2;
      }
      neigh[3] = newTet_up*4 + 2;
    }
  }

  local->deleted.num = start;

  return HXT_STATUS_OK;
}


static inline HXTStatus buildVertexCavity(HXTMesh* mesh, ThreadLocal* local,
                                          uint64_t startFace,
                                          const uint32_t numVerticesConstrained) {
  const uint64_t startDist = local->partition.startDist;
  const uint64_t rel = local->partition.endDist - startDist;
  const uint32_t vertex = mesh->tetrahedra.node[startFace];
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  // the vertex we are moving should be in the partition or we don't even try...
  if(vertex < numVerticesConstrained || vertexOutOfPartition(vertices, vertex, rel, startDist))
    return HXT_STATUS_INTERNAL;

  HXT_CHECK( reserveNewDeleted(local, 4) );
  local->deleted.tetID[local->deleted.num++] = startFace;
  setDeletedFlag(mesh, startFace/4);

  for (uint64_t start=local->deleted.num-1; start<local->deleted.num; start++) {
    HXT_CHECK( reserveNewDeleted(local, 3) );

    uint64_t curFace = local->deleted.tetID[start];
    uint64_t curTet = curFace/4;
    unsigned face = curFace%4;

    // all the cases where this function will fail.
    for (int j=0; j<3; j++) {
      uint64_t f = (face+j+1)%4;
      uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + f];
      uint64_t neighTet = neigh/4;
      unsigned neighF = neigh%4;

      if(neigh==HXT_NO_ADJACENT)
        return HXT_STATUS_INTERNAL;

      if(getDeletedFlag(mesh, neighTet))
        continue;

      if(getFacetConstraint(mesh, curTet, f))
        return HXT_STATUS_INTERNAL;

      for(unsigned k=0; k<4; k++){
        if(k!=f && getEdgeConstraint(mesh, curTet, getEdgeFromFacets(f, k)))
          return HXT_STATUS_INTERNAL;
      }

      // uint32_t a = mesh->tetrahedra.node[(face+j)%4];
      uint32_t b = mesh->tetrahedra.node[4*curTet + (face+j+2)%4];
      uint32_t c = mesh->tetrahedra.node[4*curTet + (face+j+3)%4];
      uint32_t d = mesh->tetrahedra.node[neigh];
      if(vertexOutOfPartition(vertices, b, rel, startDist) +
         vertexOutOfPartition(vertices, c, rel, startDist) +
         vertexOutOfPartition(vertices, d, rel, startDist) > 1)
        return HXT_STATUS_CONFLICT;

      // we can add the face without any fears now, but we have to find where is the vertex
      if(mesh->tetrahedra.node[4*neighTet + (neighF+1)%4]==vertex)
        local->deleted.tetID[local->deleted.num++] = 4*neighTet + (neighF+1)%4;
      else if(mesh->tetrahedra.node[4*neighTet + (neighF+2)%4]==vertex)
        local->deleted.tetID[local->deleted.num++] = 4*neighTet + (neighF+2)%4;
      else
        local->deleted.tetID[local->deleted.num++] = 4*neighTet + (neighF+3)%4;

      setDeletedFlag(mesh, neighTet);
    }
  }

  return HXT_STATUS_OK;
}

static double compute_worst_quality(HXTMesh* mesh, ThreadLocal* local, uint64_t prevNumDeleted) {
  double worst = DBL_MAX;

  // compute worst quality
  for (uint64_t i=prevNumDeleted; i<local->deleted.num; i++) {
    uint64_t tet = local->deleted.tetID[i]/4;
    double qual = tetQuality2(mesh,
                              mesh->tetrahedra.node[4*tet + 0],
                              mesh->tetrahedra.node[4*tet + 1],
                              mesh->tetrahedra.node[4*tet + 2],
                              mesh->tetrahedra.node[4*tet + 3]);
    if(qual < worst)
      worst = qual;
  }

  return worst;
}


static inline void interpolate_coord(const double start[3], const double end[3], double coord[3], double alpha) {
  for (int i=0; i<3; i++) {
    coord[i] = alpha*(start[i])+(1-alpha)*end[i];
  }
}


static HXTStatus golden_section_search(HXTMesh* mesh,
                                       ThreadShared* shared,
                                       ThreadLocal* local,
                                       uint64_t prevNumDeleted,
                                       double start[3],
                                       double end[3],
                                       uint32_t vertex)
{
  double* coord = mesh->vertices.coord + 4*vertex;
  double tol = 0.00001;
  const double invPhi = 0.6180339887498949;
  double a = 1;
  double b = 0;
  double c = invPhi;
  double d = 1-invPhi;

  interpolate_coord(start, end, coord, a);
  double fa = compute_worst_quality(mesh, local, prevNumDeleted);

  interpolate_coord(start, end, coord, b);
  double fb = compute_worst_quality(mesh, local, prevNumDeleted);

  interpolate_coord(start, end, coord, c);
  double fc = compute_worst_quality(mesh, local, prevNumDeleted);

  interpolate_coord(start, end, coord, d);
  double fd = compute_worst_quality(mesh, local, prevNumDeleted);


  // double fstart = fa, fend = fb;
  // int iter = 0;
  
  while(fc>fa && fc>fb && fd>fa && fd>fb && (fabs(fa-fb)>tol || fa==0.0 || fb==0.0)) {
    if(fc>=fd) { // maximum is between a & d, (b <-- d and d <-- c, compute new position of c)
      fb = fd;
      b = d;
      fd = fc;
      d = c;
      c = a + invPhi*(b-a); // (1-invPhi)*a+invPhi*b;
      interpolate_coord(start, end, coord, c);
      fc = compute_worst_quality(mesh, local, prevNumDeleted);
    }
    else { // maximum is between c & b, (a <-- c and c <-- d, compute new position of d)
      fa = fc;
      a = c;
      fc = fd;
      c = d;
      d = b + invPhi*(a-b); // invPhi*a+(1-invPhi)*b;
      interpolate_coord(start, end, coord, d);
      fd = compute_worst_quality(mesh, local, prevNumDeleted);
    }

    // iter++;
  }

  // printf("fa:%f  fb:%f  fc:%f  fd:%f  fstart:%f  fend:%f  iter:%d\n", fa, fb, fc, fd, fstart, fend, iter);

  // best of fa fb
  if(fb > fa) {
    // printf("%f\n", fb);
    a = b;
    interpolate_coord(start, end, coord, b);
  }
  else {
    // printf("%f\n", fa);
    interpolate_coord(start, end, coord, a);
  }

  if(a<0.999) {
    // compute new qualities
    for (uint64_t i=prevNumDeleted; i<local->deleted.num; i++) {
      uint64_t tet = local->deleted.tetID[i]/4;
      shared->quality2.values[tet] = tetQuality2(mesh,
                                     mesh->tetrahedra.node[4*tet + 0],
                                     mesh->tetrahedra.node[4*tet + 1],
                                     mesh->tetrahedra.node[4*tet + 2],
                                     mesh->tetrahedra.node[4*tet + 3]);
    }
  }
  else if(a!=1.0) {
    interpolate_coord(start, end, coord, 1.0);
  }

  return HXT_STATUS_OK;
}

// curFace is the face opposite to the vertex we are going to move
static HXTStatus smoothing(HXTMesh *mesh,
                           ThreadShared* shared,
                           ThreadLocal* local,
                           const uint64_t curFace,
                           const uint32_t numVerticesConstrained)
{
  uint64_t prevNumDeleted = local->deleted.num;
  HXTStatus status = buildVertexCavity(mesh, local, curFace, numVerticesConstrained);
  if(status!=HXT_STATUS_OK && status!=HXT_STATUS_INTERNAL && status!=HXT_STATUS_CONFLICT){
    HXT_TRACE(status);
    return status;
  }

  for (uint64_t i=prevNumDeleted; i<local->deleted.num; i++) {
    unsetDeletedFlag(mesh, local->deleted.tetID[i]/4);
  }

  if(status==HXT_STATUS_INTERNAL || status==HXT_STATUS_CONFLICT){
    local->deleted.num = prevNumDeleted;
    return status;
  }

  const uint64_t numTetInCavity = local->deleted.num - prevNumDeleted;

  // move the point
  uint32_t vertex = mesh->tetrahedra.node[curFace];
  double oldCoord[3];
  double centerCoord[3] = {0};
  for (int j=0; j<3; j++) {
    oldCoord[j] = mesh->vertices.coord[4*vertex+j];
  }

  for (uint64_t i=prevNumDeleted; i<local->deleted.num; i++) {
    uint64_t tet = local->deleted.tetID[i]/4;
    unsigned face = local->deleted.tetID[i]%4;
    double* a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet + (face+1)%4];
    double* b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet + (face+2)%4];
    double* c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet + (face+3)%4];
    for (int j=0; j<3; j++) {
      centerCoord[j] += (a[j]+b[j]+c[j])/3.0;
    }
  }

  for (int j=0; j<3; j++) {
    centerCoord[j] /= (double) numTetInCavity ;
  }

  HXT_CHECK( golden_section_search(mesh, shared, local, prevNumDeleted, oldCoord, centerCoord, vertex) );

  local->deleted.num = prevNumDeleted;

  if(shared->quality2.values[curFace/4] < shared->quality2.threshold)
    return HXT_STATUS_INTERNAL;
  
  return HXT_STATUS_OK;
}


HXTStatus hxtOptimizeTetrahedra(HXTMesh *mesh,
                                HXTBbox* bbox,
                                int maxThreads,
                                double minSize,
                                double qualityThreshold,
                                uint32_t numVerticesConstrained){
  ThreadLocal* locals = NULL;
  ThreadShared* shared = NULL;
  volatile HXTStatus globalStatus = HXT_STATUS_OK;
  uint32_t seed = 1;
  uint32_t nbits = 0;
  int changePartitions = 1;

  if(maxThreads<0)
    maxThreads = omp_get_num_procs();
  else if(maxThreads==0)
    maxThreads = omp_get_max_threads();

  HXT_CHECK( threadShared_create(mesh, qualityThreshold, &shared) );
  HXT_CHECK( threadLocals_create(&locals, maxThreads) );

  int nthreads = maxThreads;
  uint64_t nSwaps = UINT64_MAX;
  uint64_t nConflict = 0;
  uint64_t nAttempt = 1;

  do {
    int threadFinished = 0;

    HXT_CHECK( threadShared_update(mesh, shared) );
    if(shared->badTets.num==0)
      break;

    // TODO: we still need to update heuristics
    if(nSwaps<10 || 100.*nConflict/nAttempt > 45.0) {
      nthreads=(nthreads+1)/2;
      changePartitions = 1;
    }
    else if(100.*nConflict/nAttempt > 8.0){
      changePartitions=1;
    }

    nSwaps = 0;
    nConflict = 0;

    HXT_CHECK( threadLocals_update(mesh, bbox, minSize, shared, locals, nthreads, &seed, changePartitions, &nConflict, &nbits) );

    nAttempt = nConflict;
    changePartitions = 0;
    HXT_INFO("%lu bad tetrahedra being optimized on %d threads", shared->badTets.num, nthreads);

    #pragma omp parallel num_threads(nthreads) reduction(+:nSwaps,nConflict,nAttempt)
    {
      const int threadID = omp_get_thread_num();
      ThreadLocal* local = locals + threadID;

      for (uint64_t i=0; i<local->partition.length && globalStatus==HXT_STATUS_OK; i++) {
        // eliminate the bad tetrahedra with swaps
        uint64_t index = (local->partition.first + i)%shared->badTets.num;
        uint64_t curTet = shared->badTets.tetID_dist[index].v[1];

        if(curTet==HXT_NO_ADJACENT || shared->quality2.values[curTet]>= shared->quality2.threshold)
          continue;

        uint16_t color = mesh->tetrahedra.colors[curTet];
        uint64_t* neighs = mesh->tetrahedra.neigh + 4*curTet;

        /*** sort the neighbor by their qualities **/

        double hxtDeclareAligned qual[4];
        for (int j=0; j<4; j++) {
          if(neighs[j]==HXT_NO_ADJACENT ||
            mesh->tetrahedra.colors[neighs[j]/4]!=color) {
            qual[j]=DBL_MAX;
          }
          else
            qual[j] = shared->quality2.values[neighs[j]/4];
        }

        unsigned hxtDeclareAligned order[4] = {0,1,2,3};

        // sort first pair
        if(qual[order[1]] < qual[order[0]])
          SWAP(order[1], order[0]);

        // sort second pair
        if(qual[order[3]] < qual[order[2]])
          SWAP(order[3], order[2]);

        // after this, order[0] is at the right place
        if(qual[order[2]] < qual[order[0]])
          SWAP(order[2], order[0]);

        // after this, order[3] is at the right place
        if(qual[order[3]] < qual[order[1]])
          SWAP(order[3], order[1]);

        // remains order[1] and order[2]
        if(qual[order[2]] < qual[order[1]])
          SWAP(order[2], order[1]);

        HXTStatus status=HXT_STATUS_OK;
        status = smoothing(mesh, shared, local, 4*curTet+order[3], numVerticesConstrained);
        nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
        if(status<=HXT_STATUS_INTERNAL) {
          status = smoothing(mesh, shared, local, 4*curTet+order[2], numVerticesConstrained);
          nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
          if(status<=HXT_STATUS_INTERNAL) {
            status = smoothing(mesh, shared, local, 4*curTet+order[1], numVerticesConstrained);
            nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
            if(status<=HXT_STATUS_INTERNAL) {
              status = smoothing(mesh, shared, local, 4*curTet+order[0], numVerticesConstrained);
              nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
            }
          }
        }


        /*** make a swap whenever it is possible and it is an improvement ***/
        if(status<=HXT_STATUS_INTERNAL  && qual[order[1]]!=DBL_MAX) {
          status = edgeSwap(mesh, shared, local, curTet, color, order[0], order[1]);
          nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
          if(status<=HXT_STATUS_INTERNAL && qual[order[2]]!=DBL_MAX) {
            status = edgeSwap(mesh, shared, local, curTet, color, order[0], order[2]);
            nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
            if(status<=HXT_STATUS_INTERNAL) {
              status = edgeSwap(mesh, shared, local, curTet, color, order[1], order[2]);
              nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
            }
            if(status<=HXT_STATUS_INTERNAL && qual[order[3]]!=DBL_MAX) {
              status = edgeSwap(mesh, shared, local, curTet, color, order[0], order[3]);
              nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
              if(status<=HXT_STATUS_INTERNAL) {
                status = edgeSwap(mesh, shared, local, curTet, color, order[1], order[3]);
                nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
              }
              if(status<=HXT_STATUS_INTERNAL) {
                status = edgeSwap(mesh, shared, local, curTet, color, order[2], order[3]);
                nConflict+=status==HXT_STATUS_CONFLICT; nAttempt++;
              }
            }
          }
        }

        // if(status<=HXT_STATUS_INTERNAL && qual[order[0]]!=DBL_MAX) {
        //   status = flip2_3(mesh, shared, local, curTet, color, order[0]);
        //   if(status<=HXT_STATUS_INTERNAL && qual[order[1]]!=DBL_MAX) {
        //     status = flip2_3(mesh, shared, local, curTet, color, order[1]);
        //     if(status<=HXT_STATUS_INTERNAL && qual[order[2]]!=DBL_MAX) {
        //       status = flip2_3(mesh, shared, local, curTet, color, order[2]);
        //       if(status<=HXT_STATUS_INTERNAL && qual[order[3]]!=DBL_MAX) {
        //         status = flip2_3(mesh, shared, local, curTet, color, order[3]);
        //       }
        //     }
        //   }
        // }

        if(status<=HXT_STATUS_INTERNAL) // the cavity cannot be built
        {
          // HXT_WARNING("bad tetrahedron %lu cannot be improved", curTet);
          // status=HXT_STATUS_OK;
          continue;
        }
        else if(status!=HXT_STATUS_OK) {
          #pragma omp atomic write
          globalStatus = status;
          break;
        }

        nSwaps++;
      }

      #pragma omp atomic update
        threadFinished++;

      int val = 0;
      do{
        // threads are waiting here for a reallocation
        HXTStatus status = synchronizeReallocation(mesh, shared, &threadFinished, &val);

        if(status!=HXT_STATUS_OK) {
          #pragma omp atomic write
          globalStatus = status;
        }
      }while(val<nthreads);

    }

    if(globalStatus!=HXT_STATUS_OK){
      HXT_TRACE(globalStatus);
      return globalStatus;
    }

    HXT_INFO("%lu mesh optimizations done (%.2f%%)", nSwaps, nSwaps*100.0/shared->badTets.num);
    
  } while(nConflict!=0 || nSwaps!=0);

  for (int threadID=0; threadID<maxThreads; threadID++) {
    for (uint64_t i=0; i<locals[threadID].deleted.num; i++) {
      uint64_t delTet = locals[threadID].deleted.tetID[i];
      setDeletedFlag(mesh, delTet);
      for (int j=0; j<4; j++)
        mesh->tetrahedra.neigh[4*delTet+j] = HXT_NO_ADJACENT;
    }
  }

  HXT_CHECK( hxtRemoveDeleted(mesh) );

  double mean = 0;
  // #pragma omp parallel for reduction(+:mean)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(shared->quality2.values[i]!=DBL_MAX && mesh->tetrahedra.colors[i]!=UINT16_MAX)
      mean += sqrt(shared->quality2.values[i]*24.0)/mesh->tetrahedra.num;
  }

  double min = DBL_MAX;
  // #pragma omp parallel for reduction(min:min)
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(shared->quality2.values[i]!=DBL_MAX && mesh->tetrahedra.colors[i]!=UINT16_MAX)
      min = fmin(sqrt(shared->quality2.values[i]*24.0), min);
  }

  //  printf("mean quality: %f | min quality: %f\n", mean, min);

  HXT_CHECK( threadLocals_destroy(&locals, maxThreads) );
  HXT_CHECK( threadShared_destroy(&shared) );

  return HXT_STATUS_OK;
}

