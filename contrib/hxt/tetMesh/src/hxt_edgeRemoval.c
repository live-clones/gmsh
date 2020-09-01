// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_edgeRemoval.h"
#include "hxt_tetFlag.h"


#define NV -128                // not a valid entry
#define HXT_EDGE_REMOVAL_MAX 7 // you cannot increase it above 7 ATM

typedef struct { // bipyramidal cavity for the edge-removal
    uint64_t neigh_up  [HXT_EDGE_REMOVAL_MAX];
    uint64_t neigh_down[HXT_EDGE_REMOVAL_MAX];
    uint16_t flag      [HXT_EDGE_REMOVAL_MAX];
    uint32_t annulus   [HXT_EDGE_REMOVAL_MAX];
    uint32_t v_up;
    uint32_t v_down;
    uint32_t num;
} HXTBipyramid;


/*
An oriented edge {up,down} is described by its 'in' and 'out' facets :
(hxt_tetFlag.h is of little help, because edge contraints are not oriented)


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

static const int _UP_FACET[4][4] = {{NV, 2, 3, 1},
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
  /* further explanation because triangul_neigh is weird :
   * if the number n is positive:
   *   - the neighbor is a new tet. (the face is not a boundary face of the cavity)
   *   - the index of the neighbor in the triangulation is n/4
   *   - the index of the edge in the neighbor triangle is n%4
   *   (- we could have use n/3 and n%3 but %4 is faster)
   *
   * if the number n is negative
   *   - the neighbor is a old tet. a tet outisde the boundary of the cavity
   *   - the index of the neighbor-number in the list of neighbor is directly -n-1
   *
   */

  const unsigned num_triangles;             /* number of different triangles                       */
  const unsigned num_triangulations ;       /* number of different triangulations                  */
  // const int num_triangles_per_triangulation; /* simply the number of nodes +2...              */
} SwapPattern ;


static const unsigned char triangles3[][3] = { {0,1,2} };
static const uint64_t triangle_in_triangul3[] = { 1};
static const unsigned char triangulations3[][5] = {{0}};
static const signed char triangul_neigh3[][20] = {
  {-2,-3,-1,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV}
};


static const unsigned char triangles4[][3] = {
  {0,1,2}, {2,3,0}, {1,2,3}, {3,0,1}
};
static const uint64_t triangle_in_triangul4[] = { 1, 1, 2, 2};
static const unsigned char triangulations4[][5] = {
  {0,1}, {2,3}
};
static const signed char triangul_neigh4[][20] = {
  {-2,5,-1,NV,-4,1,-3,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {-3,5,-2,NV,-1,1,-4,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV,NV}
};



static const unsigned char triangles5[][3] = {
  {0,1,2}, {0,2,3}, {0,3,4}, {0,1,4}, {1,3,4},
  {1,2,3}, {2,3,4}, {0,2,4}, {0,1,3}, {1,2,4}
};
static const uint64_t triangle_in_triangul5[] = {5, 1, 9, 18, 2, 10, 20, 4, 8, 16};
static const unsigned char triangulations5[][5] = { {0,1,2}, {3,4,5}, {0,6,7}, {2,5,8}, {3,6,9} };
static const signed char triangul_neigh5[][20] = {
  {-2,6,-1,NV,-3,10,1,NV,-4,-5,5,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {5,-5,-1,NV,-4,0,9,NV,-3,6,-2,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {-2,10,-1,NV,-4,8,-3,NV,5,-5,1,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {-4,-5,9,NV,-3,8,-2,NV,5,2,-1,NV,NV,NV,NV,NV,NV,NV,NV,NV},
  {9,-5,-1,NV,-4,8,-3,NV,5,0,-2,NV,NV,NV,NV,NV,NV,NV,NV,NV}
};


static const unsigned char triangles6[][3] = {
  {0,1,2}, {0,2,3}, {0,3,4}, {0,4,5}, {0,2,5}, {2,4,5}, {2,3,4}, {0,3,5},
  {3,4,5}, {0,2,4}, {2,3,5}, {1,2,3}, {0,1,3}, {0,1,5}, {1,4,5}, {1,3,4},
  {0,1,4}, {1,3,5}, {1,2,4}, {1,2,5}
};
static const uint64_t triangle_in_triangul6[] = {
  31, 5, 33, 2345, 18, 4098, 7178, 132, 8852, 8, 8208,
  992, 160, 13888, 1088, 320, 2304, 512, 3072, 12288};
static const unsigned char triangulations6[][5] = {
  {0,1,2,3}, {0,4,5,6}, {0,1,7,8}, {0,3,6,9}, {0,4,8,10},
  {2,3,11,12}, {11,13,14,15}, {7,8,11,12}, {3,11,15,16},
  {8,11,13,17}, {6,13,14,18}, {3,6,16,18}, {5,6,13,19},
  {8,10,13,19}
};
static const signed char triangul_neigh6[][20] = {
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


static const unsigned char triangles7[][3] = { 
  {0,1,2}, {0,2,3}, {0,3,4}, {0,4,5}, {0,5,6}, {0,3,6}, {3,5,6}, {3,4,5}, {0,4,6},
  {4,5,6}, {0,3,5}, {3,4,6}, {0,2,4}, {2,3,4}, {0,2,6}, {2,5,6}, {2,4,5}, {0,2,5},
  {2,4,6}, {2,3,5}, {2,3,6}, {0,1,3}, {1,2,3}, {0,1,4}, {1,3,4}, {0,1,6}, {1,5,6},
  {1,4,5}, {0,1,5}, {1,4,6}, {1,3,5}, {1,3,6}, {1,2,4}, {1,2,5}, {1,2,6}
};
static const uint64_t triangle_in_triangul7[] = {
  16383, 31, 81925, 268976161, 294512118057, 294930, 1099578773506, 2061701913610,
  1075904644, 2273256481428, 131080, 2199157743632, 160, 137170519008, 13888, 584115553344,
  60129542464, 2304, 68719477248, 962072677376, 3298534895616, 507904, 268419072, 1344798720,
  16252928, 4102458179584, 146583584768, 2689597440, 294243008512, 4303355904, 50331648, 201326592,
  8321499136, 438086664192, 3951369912320
 };
static const unsigned char triangulations7[][5] = {
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
static const signed char triangul_neigh7[][20] = {
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


static const SwapPattern patterns[8] = {
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


/**************************************************************************
                    edge-removal related functions
 **************************************************************************/

/* create a cavity containing all tetrahedra around an edge, by turning around it */
static inline HXTStatus buildERCavity(ThreadLocal* local,
                                      HXTBipyramid* cavity,
                                      const uint64_t badTet,
                                      unsigned in_facet, unsigned out_facet)
{
  const uint64_t startDist = local->partition.startDist;
  const uint64_t rel = local->partition.lengthDist;
  int edgeOut = 0;
  HXTMesh* mesh = local->toSync->mesh;
  HXTDeleted* deleted = &local->deleted;
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  uint64_t curTet = badTet;
  cavity->num = 0;

  if(getEdgeConstraint(mesh, badTet, getEdgeFromFacets(in_facet, out_facet)))
    return HXT_STATUS_CONSTRAINT;

  cavity->v_up = mesh->tetrahedra.node[4*badTet + UP_VERTEX(in_facet, out_facet)];
  edgeOut += vertexOutOfPartition(vertices, cavity->v_up, rel, startDist);
  cavity->v_down = mesh->tetrahedra.node[4*badTet + DOWN_VERTEX(in_facet, out_facet)];
  edgeOut += vertexOutOfPartition(vertices, cavity->v_down, rel, startDist);

  HXT_CHECK( askForDeleted(deleted, 7) );

  do{
    // first, verify that the tetrahedra is not in the buffer zone between partitions
    uint32_t oldV = mesh->tetrahedra.node[4*curTet + out_facet];
    uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

    if(vertexOutOfPartition(vertices, oldV, rel, startDist) +
       vertexOutOfPartition(vertices, newV, rel, startDist) + edgeOut > 1) {
      return HXT_STATUS_CONFLICT;
    }

    // add the current tetrahedra
    deleted->array[deleted->num + cavity->num] = curTet;

    {
      unsigned up_facet = UP_FACET(in_facet, out_facet);
      unsigned down_facet = DOWN_FACET(in_facet, out_facet);

      // add the neighbor up and down
      cavity->neigh_up[cavity->num] = mesh->tetrahedra.neigh[4*curTet + up_facet];
      cavity->neigh_down[cavity->num] = mesh->tetrahedra.neigh[4*curTet + down_facet];

      int upDownEdge = getEdgeFromFacets(up_facet, down_facet);
      int upOutEdge = getEdgeFromFacets(up_facet, out_facet);
      int upInEdge = getEdgeFromFacets(up_facet, in_facet);
      int downOutEdge = getEdgeFromFacets(down_facet, out_facet);
      int downInEdge = getEdgeFromFacets(down_facet, in_facet);


      // TODO: just store one flag for up and down. the one of the default tetrahedron
      cavity->flag[cavity->num] = (getFacetConstraint(mesh, curTet, up_facet)!=0) +
                                            ((getEdgeConstraint(mesh, curTet, upOutEdge)!=0)<<1) +
                                            ((getEdgeConstraint(mesh, curTet, upDownEdge)!=0)<<2) +
                                            ((getEdgeConstraint(mesh, curTet, upInEdge)!=0)<<3) +
                                            ((getFacetConstraint(mesh, curTet, down_facet)!=0)<<4) +
                                            ((getEdgeConstraint(mesh, curTet, downOutEdge)!=0)<<5) +
                                            ((getEdgeConstraint(mesh, curTet, downInEdge)!=0)<<6) +
                                            ((getEdgeConstraint(mesh, curTet, upDownEdge)!=0)<<7);
    }
    // add the annulus vertex
    cavity->annulus[cavity->num] = oldV;
    cavity->num++;

    // go into the neighbor through out_facet
    uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
    if(neigh == HXT_NO_ADJACENT
      || (getFacetConstraint(mesh, curTet, out_facet)!=0)) {
      return HXT_STATUS_CONSTRAINT;
    }

    if(cavity->num>=HXT_EDGE_REMOVAL_MAX)
      return HXT_STATUS_INTERNAL;

    curTet = neigh/4;
    in_facet = neigh%4;

    uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;

    for (out_facet=0; out_facet<3; out_facet++)
      if(nodes[out_facet]==newV)
        break;

  }while(curTet!=badTet);

  return HXT_STATUS_OK;
}




/* perform the edge removal, also called edge swap */
HXTStatus hxtEdgeRemoval_opti(ThreadLocal* local,
                              uint64_t badTet,
                              unsigned edgeID)
{
  unsigned in_facet, out_facet;
  getFacetsFromEdge(edgeID, &in_facet, &out_facet);
  HXTMesh* mesh = local->toSync->mesh;
  HXTDeleted* deleted = &local->deleted;
  double* qualityArray = local->quality->values;

  HXTBipyramid cavity;
  HXT_CHECK( buildERCavity(local, &cavity, badTet, in_facet, out_facet) );

  // find worst quality tet of the cavity
  double worst = DBL_MAX;
  for (uint32_t i=0; i<cavity.num; i++) {
    uint64_t tet = deleted->array[deleted->num+i];
    double qual = qualityArray[tet];
    if(qual<worst)
      worst = qual;
  }

  const SwapPattern* patt = &patterns[cavity.num];
  const unsigned num_triangle_per_triangul = cavity.num-2;
  uint32_t* annulus = cavity.annulus;

  // calculate qualities of all possible tetrahedra
  double hxtDeclareAligned qual_up[35];
  double hxtDeclareAligned qual_down[35];
  uint64_t mask = 0;
  for (unsigned i=0; i<patt->num_triangles; i++) {
    uint32_t p0 = annulus[patt->triangles[i][0]];
    uint32_t p1 = annulus[patt->triangles[i][1]];
    uint32_t p2 = annulus[patt->triangles[i][2]];

    // printf("%u %u %u\n", p0, p1, p2);

    qual_up[i] = tetQuality(mesh, local->quality, p0, p1, cavity.v_up, p2);
    qual_down[i] = tetQuality(mesh, local->quality, p0, p1, p2, cavity.v_down);

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
    return HXT_STATUS_NOTBETTER;
  }
  
  // mark new deleted tet as deleted
  for (uint32_t i=0; i<cavity.num; i++) {
    setDeletedFlag(mesh, deleted->array[deleted->num+i]);
  }
  deleted->num += cavity.num;

  // reserve enough tetrahedra
  if(2*num_triangle_per_triangul > deleted->num){ // tetrahedra are created...
    HXT_CHECK(createNewDeleted(local->toSync, deleted, 2*num_triangle_per_triangul) );
  }

  uint64_t start = deleted->num - 2*num_triangle_per_triangul;
  double color = mesh->tetrahedra.color[badTet];

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

    const uint64_t newTet_up = deleted->array[start + i*2];
    const uint64_t newTet_down = deleted->array[start + i*2 + 1];

    // create the upper tet.
    {
      uint32_t* nodes = mesh->tetrahedra.node + 4*newTet_up;
      uint64_t* neigh = mesh->tetrahedra.neigh + 4*newTet_up;

      mesh->tetrahedra.color[newTet_up] = color;
      mesh->tetrahedra.flag[newTet_up] = 0;
      qualityArray[newTet_up] = qual_up[tri];
      local->date->values[newTet_up].creation = local->date->current;

      nodes[0] = p0;
      nodes[1] = p1;
      nodes[2] = cavity.v_up;
      nodes[3] = p2;

      if(n0>=0){                                                     //  v   we add this because if n0%4==2 then it should be 3
        neigh[0] = 4*deleted->array[start + (n0/4)*2] + (n0%4) + (n0%4)/2;
      }
      else {
        neigh[0] = cavity.neigh_up[-n0-1];

        //  (down=2, in=3, out=1, up=0)
        mesh->tetrahedra.flag[newTet_up] |= (cavity.flag[-n0-1]&UINT16_C(1))<<8 |// face (bit 0) is the up_facet => 0  (bit 8)
                                            (cavity.flag[-n0-1]&UINT16_C(2))>>1 |// first edge (bit 1) was between up_facet and out_facet => 0-1  (bit 0)
                                            (cavity.flag[-n0-1]&UINT16_C(4))>>1 |// second edge (bit 2) was between up_facet and down_facet => 0-2 (bit 1)
                                            (cavity.flag[-n0-1]&UINT16_C(8))>>1; // third edge (bit 3) was between up_facet and in_facet => 0-3    (bit 2)

        if(neigh[0]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[0]] = 4*newTet_up + 0;
      }
      if(n1>=0){
        neigh[1] = 4*deleted->array[start + (n1/4)*2] + (n1%4) + (n1%4)/2;
      }
      else {
        neigh[1] = cavity.neigh_up[-n1-1];

        //  (down=2, in=0, out=3, up=1)
        mesh->tetrahedra.flag[newTet_up] |= (cavity.flag[-n1-1]&UINT16_C(1))<<9 |// face (bit 0) is the up_facet => 1  (bit 9)
                                            (cavity.flag[-n1-1]&UINT16_C(2))<<3 |// first edge (bit 1) was between up_facet and out_facet => 1-3   (bit 4)
                                            (cavity.flag[-n1-1]&UINT16_C(4))<<1 |// second edge (bit 2) was between up_facet and down_facet => 1-2 (bit 3)
                                            (cavity.flag[-n1-1]&UINT16_C(8))>>3; // third edge (bit 3) was between up_facet and in_facet => 0-1    (bit 0)

        if(neigh[1]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[1]] = 4*newTet_up + 1;
      }
      neigh[2] = newTet_down*4 + 3;
      if(n2>=0){
        neigh[3] = 4*deleted->array[start + (n2/4)*2] + (n2%4) + (n2%4)/2;
      }
      else {
        neigh[3] = cavity.neigh_up[-n2-1];

        //  (down=2, in=1, out=0, up=3)
        mesh->tetrahedra.flag[newTet_up] |= (cavity.flag[-n2-1]&UINT16_C(1))<<11 |// face (bit 0) is the up_facet => 3  (bit 11)
                                            (cavity.flag[-n2-1]&UINT16_C(2))<<1  |// first edge (bit 1) was between up_facet and out_facet => 0-3   (bit 2)
                                            (cavity.flag[-n2-1]&UINT16_C(4))<<3  |// second edge (bit 2) was between up_facet and down_facet => 2-3 (bit 5)
                                            (cavity.flag[-n2-1]&UINT16_C(8))<<1;  // third edge (bit 3) was between up_facet and in_facet => 1-3    (bit 4)

        if(neigh[3]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[3]] = 4*newTet_up + 3;
      }
    }

    // create the down tet.
    {
      uint32_t* nodes = mesh->tetrahedra.node + 4*newTet_down;
      uint64_t* neigh = mesh->tetrahedra.neigh + 4*newTet_down;

      mesh->tetrahedra.color[newTet_down] = color;
      mesh->tetrahedra.flag[newTet_down] = 0;
      qualityArray[newTet_down] = qual_down[tri];
      local->date->values[newTet_down].creation = local->date->current;

      nodes[0] = p0;
      nodes[1] = p1;
      nodes[2] = p2;
      nodes[3] = cavity.v_down;

      if(n0>=0){
        neigh[0] = 4*deleted->array[start + (n0/4)*2 +1] + (n0%4);
      }
      else {
        neigh[0] = cavity.neigh_down[-n0-1];

        //  (down=0, in=2, out=1, up=3)
        mesh->tetrahedra.flag[newTet_down] |= (cavity.flag[-n0-1]&UINT16_C(16))<<4 |// face (bit 4) is the down_facet => 0  (bit 8)
                                              (cavity.flag[-n0-1]&UINT16_C(32))>>5 |// first edge (bit 5) was between down_facet and out_facet => 0-1   (bit 0)
                                              (cavity.flag[-n0-1]&UINT16_C(64))>>5 |// second edge (bit 6) was between down_facet and in_facet => 0-2   (bit 1)
                                              (cavity.flag[-n0-1]&UINT16_C(128))>>5;// third edge (bit 7) was between down_facet and up_facet => 0-3    (bit 2)

        if(neigh[0]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[0]] = 4*newTet_down + 0;
      }
      if(n1>=0){
        neigh[1] = 4*deleted->array[start + (n1/4)*2 +1] + (n1%4);
      }
      else {
        neigh[1] = cavity.neigh_down[-n1-1];

        //  (down=1, in=0, out=2, up=3)
        mesh->tetrahedra.flag[newTet_down] |= (cavity.flag[-n1-1]&UINT16_C(16))<<5 |// face (bit 4) is the down_facet => 1  (bit 9)
                                              (cavity.flag[-n1-1]&UINT16_C(32))>>2 |// first edge (bit 5) was between down_facet and out_facet => 1-2   (bit 3)
                                              (cavity.flag[-n1-1]&UINT16_C(64))>>6 |// second edge (bit 6) was between down_facet and in_facet => 0-1   (bit 0)
                                              (cavity.flag[-n1-1]&UINT16_C(128))>>3;// third edge (bit 7) was between down_facet and up_facet => 1-3    (bit 4)

        if(neigh[1]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[1]] = 4*newTet_down + 1;
      }
      if(n2>=0){
        neigh[2] = 4*deleted->array[start + (n2/4)*2 +1] + (n2%4);
      }
      else {
        neigh[2] = cavity.neigh_down[-n2-1];

        //  (down=2, in=1, out=0, up=3)
        mesh->tetrahedra.flag[newTet_down] |= (cavity.flag[-n2-1]&UINT16_C(16))<<6 |// face (bit 4) is the down_facet => 2*4  (bit 10)
                                              (cavity.flag[-n2-1]&UINT16_C(32))>>4 |// first edge (bit 5) was between down_facet and out_facet => 0-2   (bit 1)
                                              (cavity.flag[-n2-1]&UINT16_C(64))>>3 |// second edge (bit 6) was between down_facet and in_facet => 1-2   (bit 3)
                                              (cavity.flag[-n2-1]&UINT16_C(128))>>2;// third edge (bit 7) was between down_facet and up_facet => 2-3    (bit 5)

        if(neigh[2]!=HXT_NO_ADJACENT)
          mesh->tetrahedra.neigh[neigh[2]] = 4*newTet_down + 2;
      }
      neigh[3] = newTet_up*4 + 2;
    }
  }

  deleted->num = start;

  return HXT_STATUS_OK;
}