#include <mystdlib.h>
#include "meshing.hpp"

namespace netgen
{
enum HPREF_ELEMENT_TYPE {
  HP_NONE=0,
  HP_TRIG = 10,
  HP_TRIG_SINGCORNER,
  HP_TRIG_SINGCORNER12,
  HP_TRIG_SINGCORNER123,
  HP_TRIG_SINGEDGE = 20,
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,
  HP_TRIG_SINGEDGECORNER12,
  HP_TRIG_SINGEDGECORNER3,
  HP_TRIG_SINGEDGECORNER13,
  HP_TRIG_SINGEDGECORNER23,
  HP_TRIG_SINGEDGECORNER123,
  HP_TRIG_SINGEDGES = 30,
  HP_TRIG_SINGEDGES2,
  HP_TRIG_SINGEDGES3,
  HP_TRIG_SINGEDGES23,
  HP_TRIG_3SINGEDGES = 40,

  HP_QUAD = 50,
  HP_QUAD_SINGCORNER,
  HP_DUMMY_QUAD_SINGCORNER,
  HP_QUAD_SINGEDGE,
  HP_QUAD_SINGEDGES,

  HP_TET = 100,
  HP_TET_0E_1V,
  HP_TET_0E_2V,
  HP_TET_0E_3V,
  HP_TET_0E_4V,
  HP_TET_1E_0V = 200,
  HP_TET_1E_1VA,    // V on edge
  HP_TET_1E_1VB,    // V not on edge
  HP_TET_1E_2VA,    // both on edge
  HP_TET_1E_2VB,
  HP_TET_1E_2VC,
  HP_TET_1E_2VD,    // non on edge
  HP_TET_1E_3VA,    // 2 on edge
  HP_TET_1E_3VB,    // 1 on edge
  HP_TET_1E_4V,

  // 2 connected edges, additonally marked Vs
  HP_TET_2EA_0V = 220, 
  HP_TET_2EA_1VA, 
  HP_TET_2EA_1VB, 
  HP_TET_2EA_1VC, 
  HP_TET_2EA_2VA, 
  HP_TET_2EA_2VB, 
  HP_TET_2EA_2VC, 
  HP_TET_2EA_3V, 

  // 2 opposite edges
  HP_TET_2EB_0V = 230,
  HP_TET_2EB_1V,
  HP_TET_2EB_2VA,
  HP_TET_2EB_2VB,
  HP_TET_2EB_2VC,
  HP_TET_2EB_3V,
  HP_TET_2EB_4V,

  HP_TET_3EA_0V = 400,  // 3 edges connected
  HP_TET_3EA_3V,

  HP_TET_3EB_2V = 420,  // 3 edges chain
  HP_TET_3EC_2V = 430,  // 3 edges chain, alter
  HP_PRISM = 1000,
  HP_PRISM_SINGEDGE,

  HP_PYRAMID = 2000,
  HP_PYRAMID_0E_1V,
  HP_PYRAMID_EDGES,

  HP_HEX = 3000,
  HP_HEX_0E_1V,
  HP_HEX_1E_0V,
  HP_HEX_3E_0V,
};


struct HPRef_Struct {
  HPREF_ELEMENT_TYPE geom;
  int (*splitedges)[3];
  int (*splitfaces)[4];
  int (*splitelements)[5];
  HPREF_ELEMENT_TYPE * neweltypes;
  int (*newels)[8];
};



// HP_TRIG
int reftrig_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_newelstypes[] =
{
  HP_TRIG,
  HP_NONE,
};
int reftrig_newels[][8] =
{
  { 1, 2, 3 },
};
HPRef_Struct reftrig =
{
  HP_TRIG, 
  reftrig_splitedges, 
  0, 0, 
  reftrig_newelstypes, 
  reftrig_newels
};




// HP_TRIG_SINGCORNER
int reftrig_singcorner_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singcorner_newelstypes[] =
{
  HP_TRIG_SINGCORNER,
  HP_QUAD,
  HP_NONE,
};
int reftrig_singcorner_newels[][8] =
{
  { 1, 4, 5 },
  { 2, 3, 5, 4 },
};
HPRef_Struct reftrig_singcorner =
{
  HP_TRIG,
  reftrig_singcorner_splitedges, 
  0, 0,
  reftrig_singcorner_newelstypes, 
  reftrig_singcorner_newels
};


/*
// HP_TRIG_SINGCORNER, trigs only
int reftrig_singcorner_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singcorner_newelstypes[] =
{
  HP_TRIG_SINGCORNER,
  HP_TRIG,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singcorner_newels[][8] =
{
  { 1, 4, 5 },
  { 4, 2, 5 },
  { 5, 2, 3 },
};
HPRef_Struct reftrig_singcorner =
{
  HP_TRIG,
  reftrig_singcorner_splitedges, 
  0, 0,
  reftrig_singcorner_newelstypes, 
  reftrig_singcorner_newels
};
*/





// HP_TRIG_SINGCORNER12
int reftrig_singcorner12_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 1, 6 },
  { 2, 3, 7 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singcorner12_newelstypes[] =
{
  HP_TRIG_SINGCORNER,
  HP_TRIG_SINGCORNER,
  HP_QUAD,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singcorner12_newels[][8] =
{
  { 1, 4, 5 },
  { 2, 7, 6 },
  { 4, 6, 7, 5 },
  { 5, 7, 3 },
};
HPRef_Struct reftrig_singcorner12 =
{
  HP_TRIG,
  reftrig_singcorner12_splitedges, 
  0, 0,
  reftrig_singcorner12_newelstypes, 
  reftrig_singcorner12_newels
};




// HP_TRIG_SINGCORNER123
int reftrig_singcorner123_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 1, 6 },
  { 2, 3, 7 },
  { 3, 1, 8 },
  { 3, 2, 9 },
  { 0, 0, 0 }
};
int reftrig_singcorner123_splitfaces[][4] =
{
  { 1, 2, 3, 10 },
  { 2, 3, 1, 11 },
  { 3, 1, 2, 12 },
  { 0, 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singcorner123_newelstypes[] =
{
  HP_DUMMY_QUAD_SINGCORNER,
  HP_DUMMY_QUAD_SINGCORNER,
  HP_DUMMY_QUAD_SINGCORNER,
  //  HP_TRIG_SINGCORNER,
  //  HP_TRIG,
  //  HP_TRIG_SINGCORNER,
  //  HP_TRIG,
  //  HP_TRIG_SINGCORNER,
  //  HP_TRIG,
  HP_QUAD,
  HP_QUAD,
  HP_QUAD,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singcorner123_newels[][8] =
{
  { 1, 4, 10, 5 },
  { 2, 7, 11, 6 },
  { 3, 8, 12, 9 },
  //  { 1, 4, 5 },
  //  { 5, 4, 10 },
  //  { 2, 7, 6 },
  //  { 6, 7, 11 },
  //  { 3, 8, 9 },
  //  { 8, 12, 9 },
  { 4, 6, 11, 10 },
  { 7, 9, 12, 11 },
  { 8, 5, 10, 12 },
  { 10, 11, 12 },
};
HPRef_Struct reftrig_singcorner123 =
{
  HP_TRIG,
  reftrig_singcorner123_splitedges, 
  reftrig_singcorner123_splitfaces, 
  0, 
  reftrig_singcorner123_newelstypes, 
  reftrig_singcorner123_newels
};













// HP_TRIG_SINGEDGE
int reftrig_singedge_splitedges[][3] =
{
  { 2, 3, 4 },
  { 1, 3, 5 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedge_newelstypes[] =
{
  HP_TRIG,
  HP_QUAD_SINGEDGE,
  HP_NONE,
};
int reftrig_singedge_newels[][8] =
{
  { 4, 3, 5 },
  { 1, 2, 4, 5 },
};
HPRef_Struct reftrig_singedge =
{
  HP_TRIG,
  reftrig_singedge_splitedges, 
  0, 0,
  reftrig_singedge_newelstypes, 
  reftrig_singedge_newels
};






// HP_TRIG_SINGEDGECORNER1
int reftrig_singedgecorner1_splitedges[][3] =
{
  { 1, 2, 6 },
  { 1, 3, 5 },
  { 2, 3, 4 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedgecorner1_newelstypes[] =
{
  HP_TRIG_SINGEDGECORNER1,
  HP_QUAD_SINGEDGE,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singedgecorner1_newels[][8] =
{
  { 1, 6, 5 },
  { 6, 2, 4, 5 },
  { 5, 4, 3 },
};
HPRef_Struct reftrig_singedgecorner1 =
{
  HP_TRIG,
  reftrig_singedgecorner1_splitedges, 
  0, 0, 
  reftrig_singedgecorner1_newelstypes, 
  reftrig_singedgecorner1_newels
};








// HP_TRIG_SINGEDGECORNER2
int reftrig_singedgecorner2_splitedges[][3] =
{
  { 2, 1, 6 },
  { 1, 3, 5 },
  { 2, 3, 4 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedgecorner2_newelstypes[] =
{
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singedgecorner2_newels[][8] =
{
  { 6, 2, 4},
  { 1, 6, 4, 5 },
  { 5, 4, 3 },
};
HPRef_Struct reftrig_singedgecorner2 =
{
  HP_TRIG,
  reftrig_singedgecorner2_splitedges, 
  0, 0,
  reftrig_singedgecorner2_newelstypes, 
  reftrig_singedgecorner2_newels
};




// HP_TRIG_SINGEDGECORNER12
int reftrig_singedgecorner12_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 1, 6 },
  { 2, 3, 7 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedgecorner12_newelstypes[] =
{
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singedgecorner12_newels[][8] =
{
  { 1, 4, 5 },
  { 6, 2, 7 },
  { 4, 6, 7, 5 },
  { 5, 7, 3 },
};
HPRef_Struct reftrig_singedgecorner12 =
{
  HP_TRIG,
  reftrig_singedgecorner12_splitedges, 
  0, 0,
  reftrig_singedgecorner12_newelstypes, 
  reftrig_singedgecorner12_newels
};







// HP_TRIG_SINGEDGECORNER3
int reftrig_singedgecorner3_splitedges[][3] =
{
  { 1, 3, 4 },
  { 3, 1, 5 },
  { 2, 3, 6 },
  { 3, 2, 7 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedgecorner3_newelstypes[] =
{
  HP_QUAD_SINGEDGE,
  HP_QUAD,
  HP_TRIG_SINGCORNER,
  HP_NONE,
};
int reftrig_singedgecorner3_newels[][8] =
{
  { 1, 2, 6, 4 },
  { 4, 6, 7, 5 },
  { 3, 5, 7 },
};
HPRef_Struct reftrig_singedgecorner3 =
{
  HP_TRIG,
  reftrig_singedgecorner3_splitedges, 
  0, 0,
  reftrig_singedgecorner3_newelstypes, 
  reftrig_singedgecorner3_newels
};




// HP_TRIG_SINGEDGECORNER13
int reftrig_singedgecorner13_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 3, 6 },
  { 3, 1, 7 },
  { 3, 2, 8 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedgecorner13_newelstypes[] =
{
  HP_TRIG_SINGEDGECORNER1,
  HP_QUAD_SINGEDGE,
  HP_QUAD,
  HP_TRIG_SINGCORNER,
  HP_NONE,
};
int reftrig_singedgecorner13_newels[][8] =
{
  { 1, 4, 5 },
  { 4, 2, 6, 5 },
  { 5, 6, 8, 7 },
  { 3, 7, 8 },
};
HPRef_Struct reftrig_singedgecorner13 =
{
  HP_TRIG,
  reftrig_singedgecorner13_splitedges, 
  0, 0,
  reftrig_singedgecorner13_newelstypes, 
  reftrig_singedgecorner13_newels
};





// HP_TRIG_SINGEDGECORNER23
int reftrig_singedgecorner23_splitedges[][3] =
{
  { 1, 3, 4 },
  { 2, 1, 5 },
  { 2, 3, 6 },
  { 3, 1, 7 },
  { 3, 2, 8 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedgecorner23_newelstypes[] =
{
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_QUAD,
  HP_TRIG_SINGCORNER,
  HP_NONE,
};
int reftrig_singedgecorner23_newels[][8] =
{
  { 5, 2, 6 },
  { 1, 5, 6, 4 },
  { 4, 6, 8, 7 },
  { 3, 7, 8 },
};
HPRef_Struct reftrig_singedgecorner23 =
{
  HP_TRIG,
  reftrig_singedgecorner23_splitedges, 
  0, 0,
  reftrig_singedgecorner23_newelstypes, 
  reftrig_singedgecorner23_newels
};



// HP_TRIG_SINGEDGECORNER123
int reftrig_singedgecorner123_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 1, 6 },
  { 2, 3, 7 },
  { 3, 1, 8 },
  { 3, 2, 9 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftrig_singedgecorner123_newelstypes[] =
{
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_QUAD,
  HP_TRIG_SINGCORNER,
  HP_NONE,
};
int reftrig_singedgecorner123_newels[][8] =
{
  { 1, 4, 5 },
  { 6, 2, 7 },
  { 4, 6, 7, 5 },
  { 5, 7, 9, 8 },
  { 3, 8, 9 },
};
HPRef_Struct reftrig_singedgecorner123 =
{
  HP_TRIG,
  reftrig_singedgecorner123_splitedges, 
  0, 0,
  reftrig_singedgecorner123_newelstypes, 
  reftrig_singedgecorner123_newels
};













// HP_TRIG_SINGEDGES
int reftrig_singedges_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 3, 6 },
  { 3, 2, 7 },
  { 0, 0, 0 }
};
int reftrig_singedges_splitfaces[][4] =
{
  { 1, 2, 3, 8 },
  { 0, 0, 0, 0 }
};

HPREF_ELEMENT_TYPE reftrig_singedges_newelstypes[] =
{
  //  HP_QUAD_SINGEDGES,
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_QUAD_SINGEDGE,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singedges_newels[][8] =
{
  // { 1, 4, 8, 5 },
  { 1, 4, 8 },
  { 5, 1, 8 },
  { 4, 2, 6, 8 },
  { 3, 5, 8, 7 },
  { 6, 7, 8 },
};
HPRef_Struct reftrig_singedges =
{
  HP_TRIG,
  reftrig_singedges_splitedges, 
  reftrig_singedges_splitfaces, 
  0,
  reftrig_singedges_newelstypes, 
  reftrig_singedges_newels
};








// HP_TRIG_SINGEDGES2
int reftrig_singedges2_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 1, 6 },
  { 2, 3, 7 },
  { 3, 2, 8 },
  { 0, 0, 0 }
};
int reftrig_singedges2_splitfaces[][4] =
{
  { 1, 2, 3, 9 },
  { 0, 0, 0, 0 }
};

HPREF_ELEMENT_TYPE reftrig_singedges2_newelstypes[] =
{
  //  HP_QUAD_SINGEDGES,
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_QUAD_SINGEDGE,
  HP_TRIG_SINGEDGECORNER2,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singedges2_newels[][8] =
{
  //  { 1, 4, 9, 5 },
  { 1, 4, 9 },
  { 5, 1, 9 },
  { 4, 6, 7, 9 },
  { 3, 5, 9, 8 },
  { 6, 2, 7 },
  { 7, 8, 9 },
};
HPRef_Struct reftrig_singedges2 =
{
  HP_TRIG,
  reftrig_singedges2_splitedges, 
  reftrig_singedges2_splitfaces, 
  0,
  reftrig_singedges2_newelstypes, 
  reftrig_singedges2_newels
};




// HP_TRIG_SINGEDGES3
int reftrig_singedges3_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 3, 6 },
  { 3, 1, 7 },
  { 3, 2, 8 },
  { 0, 0, 0 }
};
int reftrig_singedges3_splitfaces[][4] =
{
  { 1, 2, 3, 9 },
  { 0, 0, 0, 0 }
};

HPREF_ELEMENT_TYPE reftrig_singedges3_newelstypes[] =
{
  //  HP_QUAD_SINGEDGES,
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_QUAD_SINGEDGE,
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singedges3_newels[][8] =
{
  //  { 1, 4, 9, 5 },
  { 1, 4, 9 },
  { 5, 1, 9 },
  { 4, 2, 6, 9 },
  { 7, 5, 9, 8 },
  { 3, 7, 8 },
  { 6, 8, 9 },
};
HPRef_Struct reftrig_singedges3 =
{
  HP_TRIG,
  reftrig_singedges3_splitedges, 
  reftrig_singedges3_splitfaces, 
  0,
  reftrig_singedges3_newelstypes, 
  reftrig_singedges3_newels
};






// HP_TRIG_SINGEDGES23
int reftrig_singedges23_splitedges[][3] =
{
  { 1, 2, 4 },
  { 1, 3, 5 },
  { 2, 1, 6 },
  { 2, 3, 7 },
  { 3, 1, 8 },
  { 3, 2, 9 },
  { 0, 0, 0 }
};
int reftrig_singedges23_splitfaces[][4] =
{
  { 1, 2, 3, 10 },
  { 0, 0, 0, 0 }
};

HPREF_ELEMENT_TYPE reftrig_singedges23_newelstypes[] =
{
  //  HP_QUAD_SINGEDGES,
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,

  HP_QUAD_SINGEDGE,
  HP_QUAD_SINGEDGE,
  HP_TRIG_SINGEDGECORNER2,
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG,
  HP_NONE,
};
int reftrig_singedges23_newels[][8] =
{
  //  { 1, 4, 10, 5 },
  { 1 , 4, 10 },
  { 5, 1, 10 },
  { 4, 6, 7, 10 },
  { 8, 5, 10, 9 },
  { 6, 2, 7 },
  { 3, 8, 9 },
  { 7, 9, 10 },
};
HPRef_Struct reftrig_singedges23 =
{
  HP_TRIG,
  reftrig_singedges23_splitedges, 
  reftrig_singedges23_splitfaces, 
  0,
  reftrig_singedges23_newelstypes, 
  reftrig_singedges23_newels
};













// HP_QUAD
int refquad_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refquad_newelstypes[] =
{
  HP_QUAD,
  HP_NONE,
};
int refquad_newels[][8] =
{
  { 1, 2, 3, 4 },
};
HPRef_Struct refquad =
{
  HP_QUAD,
  refquad_splitedges, 
  0, 0,
  refquad_newelstypes, 
  refquad_newels
};







// HP_QUAD_SINGCORNER
int refquad_singcorner_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 4, 6 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refquad_singcorner_newelstypes[] =
{
  HP_TRIG_SINGCORNER,
  HP_QUAD,
  HP_TRIG,
  HP_NONE,
};
int refquad_singcorner_newels[][8] =
{
  { 1, 5, 6 },
  { 2, 4, 6, 5 },
  { 2, 3, 4 },
};
HPRef_Struct refquad_singcorner =
{
  HP_QUAD,
  refquad_singcorner_splitedges, 
  0, 0,
  refquad_singcorner_newelstypes, 
  refquad_singcorner_newels
};





// HP_DUMMY_QUAD_SINGCORNER
int refdummyquad_singcorner_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refdummyquad_singcorner_newelstypes[] =
{
  HP_TRIG_SINGCORNER,
  HP_TRIG,
  HP_NONE,
};
int refdummyquad_singcorner_newels[][8] =
{
  { 1, 2, 4 },
  { 4, 2, 3 },
};
HPRef_Struct refdummyquad_singcorner =
{
  HP_QUAD,
  refdummyquad_singcorner_splitedges, 
  0, 0,
  refdummyquad_singcorner_newelstypes, 
  refdummyquad_singcorner_newels
};







// HP_QUAD_SINGEDGE
int refquad_singedge_splitedges[][3] =
{
  { 1, 4, 5 },
  { 2, 3, 6 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refquad_singedge_newelstypes[] =
{
  HP_QUAD_SINGEDGE,
  HP_QUAD,
  HP_NONE,
};
int refquad_singedge_newels[][8] =
{
  { 1, 2, 6, 5 },
  { 5, 6, 3, 4 },
};
HPRef_Struct refquad_singedge =
{
  HP_QUAD,
  refquad_singedge_splitedges, 
  0, 0,
  refquad_singedge_newelstypes, 
  refquad_singedge_newels
};





// HP_QUAD_SINGEDGES
int refquad_singedges_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 4, 6 },
  { 2, 3, 7 },
  { 4, 3, 8 },
  { 0, 0, 0 }
};
int refquad_singedges_splitfaces[][4] =
{
  { 1, 2, 4, 9 },
  { 0, 0, 0, 0 },
};
HPREF_ELEMENT_TYPE refquad_singedges_newelstypes[] =
{
  HP_TRIG_SINGEDGECORNER1,
  HP_TRIG_SINGEDGECORNER2,
  HP_QUAD_SINGEDGE,
  HP_QUAD_SINGEDGE,
  HP_QUAD,
  HP_NONE,
};
int refquad_singedges_newels[][8] =
{
  { 1, 5, 9 },
  { 6, 1, 9 },
  { 5, 2, 7, 9 },
  { 4, 6, 9, 8 },
  { 9, 7, 3, 8 },
};
HPRef_Struct refquad_singedges =
{
  HP_QUAD,
  refquad_singedges_splitedges, 
  refquad_singedges_splitfaces, 
  0,
  refquad_singedges_newelstypes, 
  refquad_singedges_newels
};













// HP_TET
int reftet_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftet_newelstypes[] =
{
  HP_TET,
  HP_NONE,
};
int reftet_newels[][8] =
{
  { 1, 2, 3, 4 },
};
HPRef_Struct reftet =
{
  HP_TET,
  reftet_splitedges, 
  0, 0,
  reftet_newelstypes, 
  reftet_newels
};



/* *********** Tet - Refinement - 0 edges *************** */

// HP_TET_0E_1V
int reftet_0e_1v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftet_0e_1v_newelstypes[] =
{
  HP_TET_0E_1V,
  HP_PRISM,
  HP_NONE,
};
int reftet_0e_1v_newels[][8] =
{
  { 1, 5, 6, 7 },
  { 5, 6, 7, 2, 3, 4 }
};
HPRef_Struct reftet_0e_1v =
{
  HP_TET,
  reftet_0e_1v_splitedges, 
  0, 0,
  reftet_0e_1v_newelstypes, 
  reftet_0e_1v_newels
};



// HP_TET_0E_2V
int reftet_0e_2v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftet_0e_2v_newelstypes[] =
{
  HP_TET_0E_1V,
  HP_TET_0E_1V,
  HP_PRISM,
  HP_PRISM,
  HP_NONE,
};
int reftet_0e_2v_newels[][8] =
{
  { 1, 5, 6, 7 },
  { 2, 10, 9, 8 },
  { 5, 6, 7, 8, 9, 10 },
  { 4, 10, 7, 3, 9, 6 },
};
HPRef_Struct reftet_0e_2v =
{
  HP_TET,
  reftet_0e_2v_splitedges, 
  0, 0,
  reftet_0e_2v_newelstypes, 
  reftet_0e_2v_newels
};





// HP_TET_0E_3V
int reftet_0e_3v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 1, 11 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 0, 0, 0 }
};
int reftet_0e_3v_splitfaces[][4] =
  {
    { 1, 2, 3, 14 },
    { 2, 3, 1, 15 },
    { 3, 1, 2, 16 },
    { 0, 0, 0, 0 },
  };
HPREF_ELEMENT_TYPE reftet_0e_3v_newelstypes[] =
{
  HP_PYRAMID_0E_1V,
  HP_PYRAMID_0E_1V,
  HP_PYRAMID_0E_1V,
  HP_PRISM,
  HP_PRISM,
  HP_PRISM,
  HP_PRISM,
  HP_TET,
  HP_NONE,
};
int reftet_0e_3v_newels[][8] =
{
  { 1, 5, 14, 6, 7 },
  { 2, 9, 15, 8, 10 },
  { 3, 11, 16, 12, 13 },
  { 5, 14, 7, 8, 15, 10 },
  { 9, 15, 10, 12, 16, 13 },
  { 6, 7, 14, 11, 13, 16 },
  { 14, 15, 16, 7, 10, 13 },
  { 7, 10, 13, 4 }
};
HPRef_Struct reftet_0e_3v =
{
  HP_TET,
  reftet_0e_3v_splitedges, 
  reftet_0e_3v_splitfaces, 
  0,
  reftet_0e_3v_newelstypes, 
  reftet_0e_3v_newels
};





// HP_TET_0E_4V
int reftet_0e_4v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 1, 11 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 4, 1, 14 },
  { 4, 2, 15 },
  { 4, 3, 16 },
  { 0, 0, 0 }
};
int reftet_0e_4v_splitfaces[][4] =
  {
    { 1, 2, 3, 17 },
    { 1, 2, 4, 18 },
    { 1, 3, 4, 19 },

    { 2, 1, 3, 20 },
    { 2, 1, 4, 21 },
    { 2, 3, 4, 22 },

    { 3, 1, 2, 23 },
    { 3, 1, 4, 24 },
    { 3, 2, 4, 25 },

    { 4, 1, 2, 26 },
    { 4, 1, 3, 27 },
    { 4, 2, 3, 28 },
    { 0, 0, 0, 0 },
  };
int reftet_0e_4v_splitelements[][5] =
  {
    { 1, 2, 3, 4, 29 },
    { 2, 3, 4, 1, 30 },
    { 3, 4, 1, 2, 31 },
    { 4, 1, 2, 3, 32 },
    { 0 },
  };
HPREF_ELEMENT_TYPE reftet_0e_4v_newelstypes[] =
{
  HP_HEX_0E_1V,
  HP_HEX_0E_1V,
  HP_HEX_0E_1V,
  HP_HEX_0E_1V,
  HP_PRISM, HP_PRISM, 
  HP_PRISM, HP_PRISM, 
  HP_PRISM, HP_PRISM, 
  HP_PRISM, HP_PRISM, 
  HP_PRISM, HP_PRISM, 
  HP_PRISM, HP_PRISM, 
  /*
  HP_HEX, 
  HP_HEX, 
  HP_HEX, 
  HP_HEX, 
  HP_HEX, 
  HP_HEX, 
  */
  HP_PRISM,
  HP_PRISM,
  HP_PRISM,
  HP_PRISM,
  HP_TET,
  HP_NONE,
};
int reftet_0e_4v_newels[][8] =
{
  { 1, 5, 17, 6, 7, 18, 29, 19 },
  { 2, 9, 20, 8, 10, 22, 30, 21 },
  { 3, 11, 23, 12, 13, 24, 31, 25 },
  { 4, 15, 26, 14, 16, 28, 32, 27 },
  { 5, 17, 18, 8, 20, 21 },
  { 18, 17, 29, 21, 20, 30 },
  { 6, 19, 17,  11, 24, 23 },
  { 17, 19, 29,  23, 24, 31 },
  { 7, 18, 19, 14, 26, 27 },
  { 19, 18, 29, 27, 26, 32 },
  { 9, 20, 22, 12, 23, 25 },
  { 22, 20, 30, 25, 23, 31 },
  { 10, 22, 21, 15, 28, 26 },
  { 21, 22, 30, 26, 28, 32 },
  { 13, 24, 25, 16, 27, 28 },
  { 25, 24, 31, 28, 27, 32 },
  /*
  { 5, 17, 29, 18, 8, 20, 30, 21 },
  { 6, 19, 29, 17, 11, 24, 31, 23 },
  { 7, 18, 29, 19, 14, 26, 32, 27 },
  { 9, 20, 30, 22, 12, 23, 31, 25 },
  { 10, 22, 30, 21, 15, 28, 32, 26 },
  { 13, 24, 31, 25, 16, 27, 32, 28 },
  */
  { 17, 20, 23, 29, 30, 31 },
  { 18, 26, 21, 29, 32, 30 },
  { 19, 24, 27, 29, 31, 32 },
  { 22, 28, 25, 30, 32, 31 },

  { 29, 30, 31, 32 },
};
HPRef_Struct reftet_0e_4v =
{
  HP_TET,
  reftet_0e_4v_splitedges, 
  reftet_0e_4v_splitfaces, 
  reftet_0e_4v_splitelements, 
  reftet_0e_4v_newelstypes, 
  reftet_0e_4v_newels
};

















/* *********** Tet - Refinement - 1 edge *************** */



// HP_TET_1E_0V
int reftet_1e_0v_splitedges[][3] =
{
  { 1, 3, 5 },
  { 1, 4, 6 },
  { 2, 3, 7 },
  { 2, 4, 8 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftet_1e_0v_newelstypes[] =
{
  HP_PRISM_SINGEDGE,
  HP_PRISM,
  HP_NONE,
};
int reftet_1e_0v_newels[][8] =
{
  { 1, 5, 6, 2, 7, 8 },
  { 7, 3, 5, 8, 4, 6 }
};
HPRef_Struct reftet_1e_0v =
{
  HP_TET,
  reftet_1e_0v_splitedges, 
  0, 0,
  reftet_1e_0v_newelstypes, 
  reftet_1e_0v_newels
};





// HP_TET_1E_1VA
int reftet_1e_1va_splitedges[][3] =
{
  { 1, 3, 5 },
  { 1, 4, 6 },
  { 2, 3, 7 },
  { 2, 4, 8 },
  { 1, 2, 9 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftet_1e_1va_newelstypes[] =
{
  HP_TET_1E_1VA,
  HP_PRISM_SINGEDGE,
  HP_PRISM,
  HP_NONE,
};
int reftet_1e_1va_newels[][8] =
{
  { 1, 9, 5, 6 },
  { 9, 5, 6, 2, 7, 8 },
  { 7, 3, 5, 8, 4, 6 }
};
HPRef_Struct reftet_1e_1va =
{
  HP_TET,
  reftet_1e_1va_splitedges, 
  0, 0,
  reftet_1e_1va_newelstypes, 
  reftet_1e_1va_newels
};






// HP_TET_1E_1VB
int reftet_1e_1vb_splitedges[][3] =
{
  { 1, 3, 5 },
  { 1, 4, 6 },
  { 2, 3, 7 },
  { 2, 4, 8 },
  { 4, 1, 9 },
  { 4, 2, 10 },
  { 4, 3, 11 },
  { 0, 0, 0 }
};
int reftet_1e_1vb_splitelements[][5] =
{
  { 4, 1, 2, 3, 12 },
  { 0 }
};

HPREF_ELEMENT_TYPE reftet_1e_1vb_newelstypes[] =
{
  HP_PRISM_SINGEDGE,
  HP_TET_0E_1V,
  HP_PYRAMID,
  HP_TET,
  HP_PYRAMID, 
  HP_TET,
  HP_PYRAMID,
  HP_TET,
  HP_PYRAMID,
  HP_TET,
  HP_NONE,
};
int reftet_1e_1vb_newels[][8] =
{
  { 1, 5, 6, 2, 7, 8 },
  { 4, 11, 10, 9 },
  { 7, 8, 10, 11, 12 },
  { 3, 7, 11, 12 },
  { 5, 11, 9, 6, 12 },
  { 5, 3, 11, 12 },
  { 6, 9, 10, 8, 12 },
  { 5, 7, 3, 12 },
  { 5, 6, 8, 7, 12 },
  { 9, 11, 10, 12 }
};
HPRef_Struct reftet_1e_1vb =
{
  HP_TET,
  reftet_1e_1vb_splitedges, 
  0,
  reftet_1e_1vb_splitelements, 
  reftet_1e_1vb_newelstypes, 
  reftet_1e_1vb_newels
};








// HP_TET_1E_2VA
int reftet_1e_2va_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftet_1e_2va_newelstypes[] =
{
  HP_TET_1E_1VA,
  HP_TET_1E_1VA,
  HP_PRISM_SINGEDGE,
  HP_PRISM,
  HP_NONE,
};
int reftet_1e_2va_newels[][8] =
{
  { 1, 5, 6, 7 },
  { 2, 8, 10, 9 },
  { 5, 6, 7, 8, 9, 10 },
  { 4, 10, 7, 3, 9, 6 },
};
HPRef_Struct reftet_1e_2va =
{
  HP_TET,
  reftet_1e_2va_splitedges, 
  0, 0,
  reftet_1e_2va_newelstypes, 
  reftet_1e_2va_newels
};







// HP_TET_1E_2VB
int reftet_1e_2vb_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 3, 8 },
  { 2, 4, 9 },
  { 3, 1, 10 },
  { 3, 2, 11 },
  { 3, 4, 12 },
  { 0, 0, 0 }
};
int reftet_1e_2vb_splitelements[][5] =
{
  { 3, 4, 1, 2, 13 },
  { 0 }
};

HPREF_ELEMENT_TYPE reftet_1e_2vb_newelstypes[] =
{
  HP_TET_1E_1VA,
  HP_PRISM_SINGEDGE,
  HP_TET_0E_1V,
  HP_PYRAMID,
  HP_TET,
  HP_PYRAMID, 
  HP_TET,
  HP_PYRAMID,
  HP_TET,
  HP_PYRAMID,
  HP_TET,
  HP_NONE,
};
int reftet_1e_2vb_newels[][8] =
{
  { 1, 5, 6, 7 },
  { 5, 6, 7, 2, 8, 9 },
  { 3, 10, 11, 12 },

  { 8, 9, 12, 11, 13 },
  { 4, 12, 9, 13 },
  { 6, 10, 12, 7, 13 },
  { 4, 7, 12, 13 },
  { 6, 8, 11, 10, 13 },
  { 4, 9, 7, 13 },
  { 6, 7, 9, 8, 13 },
  { 10, 11, 12, 13 },
};
HPRef_Struct reftet_1e_2vb =
{
  HP_TET,
  reftet_1e_2vb_splitedges, 
  0,
  reftet_1e_2vb_splitelements, 
  reftet_1e_2vb_newelstypes, 
  reftet_1e_2vb_newels
};






// HP_TET_1E_2VC
int reftet_1e_2vc_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 3, 8 },
  { 2, 4, 9 },
  { 4, 1, 10 },
  { 4, 2, 11 },
  { 4, 3, 12 },
  { 0, 0, 0 }
};
int reftet_1e_2vc_splitelements[][5] =
{
  { 4, 1, 2, 3, 13 },
  { 0 }
};

HPREF_ELEMENT_TYPE reftet_1e_2vc_newelstypes[] =
{
  HP_TET_1E_1VA,
  HP_PRISM_SINGEDGE,
  HP_TET_0E_1V,
  HP_PYRAMID,
  HP_TET,
  HP_PYRAMID, 
  HP_TET,
  HP_PYRAMID,
  HP_TET,
  HP_PYRAMID,
  HP_TET,
  HP_NONE,
};
int reftet_1e_2vc_newels[][8] =
{
  { 1, 5, 6, 7 },
  { 5, 6, 7, 2, 8, 9 },
  { 4, 11, 10, 12 },
  { 8, 9, 11, 12, 13 },
  { 3, 8, 12, 13 },
  { 7, 6, 12, 10, 13 },
  { 3, 12, 6, 13 },
  { 9, 7, 10, 11, 13 },
  { 3, 6, 8, 13 },
  { 6, 7, 9, 8, 13 },
  { 10, 12, 11, 13 }
};
HPRef_Struct reftet_1e_2vc =
{
  HP_TET,
  reftet_1e_2vc_splitedges, 
  0,
  reftet_1e_2vc_splitelements, 
  reftet_1e_2vc_newelstypes, 
  reftet_1e_2vc_newels
};










// HP_TET_1E_2VD
int reftet_1e_2vd_splitedges[][3] =
{
  { 1, 3, 5 },
  { 1, 4, 6 },
  { 2, 3, 7 },
  { 2, 4, 8 },
  { 3, 1, 9 },
  { 3, 2, 10 },
  { 3, 4, 11 },
  { 4, 1, 12 },
  { 4, 2, 13 },
  { 4, 3, 14 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE reftet_1e_2vd_newelstypes[] =
{
  HP_PRISM_SINGEDGE,
  HP_TET_0E_1V,
  HP_TET_0E_1V,
  HP_PRISM,
  HP_HEX,
  HP_NONE,
};
int reftet_1e_2vd_newels[][8] =
{
  { 1, 5, 6, 2, 7, 8 },
  { 4, 13, 12, 14 },
  { 3, 10, 11, 9 },
  { 14, 13, 12, 11, 10, 9 },
  { 6, 12, 13, 8, 5, 9, 10, 7 },
};
HPRef_Struct reftet_1e_2vd =
{
  HP_TET,
  reftet_1e_2vd_splitedges, 
  0, 0,
  reftet_1e_2vd_newelstypes, 
  reftet_1e_2vd_newels
};












//  HP_TET_2EA_0V,  // 2 edges connected
int reftet_2ea_0v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 0, 0, 0 }
};
int reftet_2ea_0v_splitfaces[][4] =
  {
    { 1, 2, 3, 17 },
    { 0, 0, 0, 0 }
  };
HPREF_ELEMENT_TYPE reftet_2ea_0v_newelstypes[] =
  {
    HP_PYRAMID_EDGES,
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,
    HP_PRISM,
    HP_TET,
    HP_NONE,
  };
int reftet_2ea_0v_newels[][8] =
{
  { 1, 5, 17, 6, 7 },
  { 5, 17, 7, 2, 9, 10 },
  { 6, 7, 17, 3, 13, 12 },
  { 17, 9, 12, 7, 10, 13 },
  { 7, 10, 13, 4 },
};
HPRef_Struct reftet_2ea_0v =
{
  HP_TET,
  reftet_2ea_0v_splitedges, 
  reftet_2ea_0v_splitfaces, 
  0,
  reftet_2ea_0v_newelstypes, 
  reftet_2ea_0v_newels
};






//  HP_TET_2EA_1VB, 
int reftet_2ea_1vb_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 1, 11 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 0, 0, 0 }
};
int reftet_2ea_1vb_splitfaces[][4] =
  {
    { 1, 2, 3, 17 },
    { 0, 0, 0, 0 }
  };
HPREF_ELEMENT_TYPE reftet_2ea_1vb_newelstypes[] =
  {
    HP_PYRAMID_EDGES,
    HP_TET_1E_1VA,
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,
    HP_PRISM,
    HP_TET,
    HP_NONE,
  };
int reftet_2ea_1vb_newels[][8] =
{
  { 1, 5, 17, 6, 7 },
  { 3, 11, 12, 13 },
  { 5, 17, 7, 2, 9, 10 },
  { 6, 7, 17, 11, 13, 12 },
  { 17, 9, 12, 7, 10, 13 },
  { 7, 10, 13, 4 },
};
HPRef_Struct reftet_2ea_1vb =
{
  HP_TET,
  reftet_2ea_1vb_splitedges, 
  reftet_2ea_1vb_splitfaces, 
  0,
  reftet_2ea_1vb_newelstypes, 
  reftet_2ea_1vb_newels
};









//  HP_TET_2EA_3V,  // 2 edges connected
int reftet_2ea_3v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 1, 11 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 4, 1, 14 },
  { 4, 2, 15 },
  { 4, 3, 16 },
  { 0, 0, 0 }
};
int reftet_2ea_3v_splitfaces[][4] =
  {
    { 1, 2, 3, 17 },
    { 2, 3, 4, 18 },
    { 3, 4, 2, 19 },
    { 4, 2, 3, 20 },
    { 0, 0, 0, 0 }
  };
int reftet_2ea_3v_splitelements[][5] =
  {
    { 1, 2, 3, 4, 21 },
    { 0, 0, 0, 0 }
  };
HPREF_ELEMENT_TYPE reftet_2ea_3v_newelstypes[] =
  {
    HP_PYRAMID_EDGES,
    HP_TET_1E_1VA,
    HP_TET_1E_1VA,
    HP_TET_0E_1V,
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,

    HP_TET, HP_TET, HP_TET, HP_TET, 
    HP_PYRAMID, HP_PYRAMID, HP_PYRAMID, 
    HP_PYRAMID, HP_PYRAMID, HP_TET,
    HP_PYRAMID, HP_PYRAMID, HP_TET,
    //     HP_PRISM,
    //    HP_PRISM,
    HP_NONE,
  };
int reftet_2ea_3v_newels[][8] =
{
  { 1, 5, 17, 6, 7 },
  { 2, 8, 10, 9 },
  { 3, 11, 12, 13 },
  { 4, 15, 14, 16 }, 
  { 5, 17, 7, 8, 9, 10 },
  { 6, 7, 17, 11, 13, 12 },
 
  { 9, 10, 18, 21 },
  { 13, 12, 19, 21 },
  { 15, 16, 20, 21 },
  { 18, 20, 19, 21 },
  { 10, 15, 20, 18, 21 },
  { 13, 19, 20, 16, 21 },
  { 9, 18, 19, 12, 21 },
  
  { 7, 13, 16, 14, 21 },
  { 7, 14, 15, 10, 21 },
  { 9, 12, 17, 21 },
  { 7, 10, 9, 17, 21 },
  { 7, 17, 12, 13, 21 },
  { 14, 16, 15, 21 },
  //  { 17, 9, 12, 7, 10, 13 },
  //  { 7, 10, 13, 14, 15, 16 },
};
HPRef_Struct reftet_2ea_3v =
{
  HP_TET,
  reftet_2ea_3v_splitedges, 
  reftet_2ea_3v_splitfaces, 
  reftet_2ea_3v_splitelements, 
  reftet_2ea_3v_newelstypes, 
  reftet_2ea_3v_newels
};






//  HP_TET_2EB_4V,  // 2 opposite edges
int reftet_2eb_4v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 1, 11 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 4, 1, 14 },
  { 4, 2, 15 },
  { 4, 3, 16 },
  { 0, 0, 0 }
};

HPREF_ELEMENT_TYPE reftet_2eb_4v_newelstypes[] =
  {
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,
    HP_TET_1E_1VA,
    HP_TET_1E_1VA,
    HP_TET_1E_1VA,
    HP_TET_1E_1VA,
    HP_HEX,
    HP_NONE,
  };
int reftet_2eb_4v_newels[][8] =
{
  { 5, 6, 7, 8, 9, 10 },
  { 16, 15, 14, 13, 12, 11 },
  { 1, 5, 6, 7 },
  { 2, 8, 10, 9 },
  { 3, 13, 11, 12 },
  { 4, 16, 15, 14 },
  { 7, 14, 15, 10, 6, 11, 12, 9 }
};
HPRef_Struct reftet_2eb_4v =
{
  HP_TET,
  reftet_2eb_4v_splitedges, 
  0, 0,
  reftet_2eb_4v_newelstypes, 
  reftet_2eb_4v_newels
};















//  HP_TET_3EA_0V,  
int reftet_3ea_0v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 3, 8 },
  { 2, 4, 9 },
  { 3, 2, 10 },
  { 3, 4, 11 },
  { 4, 2, 12 },
  { 4, 3, 13 },
  { 0, 0, 0 }
};
int reftet_3ea_0v_splitfaces[][4] =
  {
    { 1, 2, 3, 14 },
    { 1, 2, 4, 15 },
    { 1, 3, 4, 16 },
    { 2, 3, 4, 17 },
    { 3, 4, 2, 18 },
    { 4, 2, 3, 19 },
    { 0, 0, 0, 0 }
  };
int reftet_3ea_0v_splitelements[][5] =
  {
    { 1, 2, 3, 4, 20 },
    { 0 },
  };

HPREF_ELEMENT_TYPE reftet_3ea_0v_newelstypes[] =
  {
    HP_HEX_3E_0V,
    HP_HEX_1E_0V,
    HP_HEX_1E_0V,
    HP_HEX_1E_0V,
    HP_PRISM,
    HP_PRISM,
    HP_PRISM,
    HP_TET,
    HP_NONE,
  };
int reftet_3ea_0v_newels[][8] =
{
  { 1, 5, 14, 6, 7, 15, 20, 16 },
  { 5, 2, 8, 14, 15, 9, 17, 20 },
  { 3, 6, 14, 10, 11, 16, 20, 18 },
  { 7, 4, 12, 15, 16, 13, 19, 20 },
  { 11, 13, 16, 18, 19, 20 },
  { 15, 12, 9, 20, 19, 17 },
  { 8, 10, 14, 17, 18, 20 },
  { 20, 17, 18, 19 },
};
HPRef_Struct reftet_3ea_0v =
{
  HP_TET,
  reftet_3ea_0v_splitedges, 
  reftet_3ea_0v_splitfaces, 
  reftet_3ea_0v_splitelements, 
  reftet_3ea_0v_newelstypes, 
  reftet_3ea_0v_newels
};







//  HP_TET_3EA_3V,  
int reftet_3ea_3v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 3, 8 },
  { 2, 4, 9 },
  { 3, 2, 10 },
  { 3, 4, 11 },
  { 4, 2, 12 },
  { 4, 3, 13 },
  { 2, 1, 21 },
  { 3, 1, 22 },
  { 4, 1, 23 },
  { 0, 0, 0 }
};
int reftet_3ea_3v_splitfaces[][4] =
  {
    { 1, 2, 3, 14 },
    { 1, 2, 4, 15 },
    { 1, 3, 4, 16 },
    { 2, 3, 4, 17 },
    { 3, 4, 2, 18 },
    { 4, 2, 3, 19 },
    { 0, 0, 0, 0 }
  };
int reftet_3ea_3v_splitelements[][5] =
  {
    { 1, 2, 3, 4, 20 },
    { 0 },
  };

HPREF_ELEMENT_TYPE reftet_3ea_3v_newelstypes[] =
  {
    HP_HEX_3E_0V,
    HP_TET_1E_1VA,
    HP_PRISM_SINGEDGE,
    HP_PRISM,
    HP_TET_1E_1VA,
    HP_PRISM_SINGEDGE,
    HP_PRISM,
    HP_TET_1E_1VA,
    HP_PRISM_SINGEDGE,
    HP_PRISM,

    HP_PRISM,
    HP_PRISM,
    HP_PRISM,
    HP_TET,
    HP_NONE,
  };
int reftet_3ea_3v_newels[][8] =
{
  { 1, 5, 14, 6, 7, 15, 20, 16 },

  { 2, 21, 9, 8 },
  { 5, 14, 15, 21, 8, 9 },
  { 15, 14, 20, 9, 8, 17 },
  { 3, 22, 10, 11 },
  { 6, 16, 14, 22, 11, 10 },
  { 14, 16, 20, 10, 11, 18 },
  { 4, 23, 13, 12 },
  { 7, 15, 16, 23, 12, 13 },
  { 16, 15, 20, 13, 12, 19 },

  { 11, 13, 16, 18, 19, 20 },
  { 15, 12, 9, 20, 19, 17 },
  { 8, 10, 14, 17, 18, 20 },
  { 20, 17, 18, 19 },
};
HPRef_Struct reftet_3ea_3v =
{
  HP_TET,
  reftet_3ea_3v_splitedges, 
  reftet_3ea_3v_splitfaces, 
  reftet_3ea_3v_splitelements, 
  reftet_3ea_3v_newelstypes, 
  reftet_3ea_3v_newels
};







//  HP_TET_3EV_2V,  
int reftet_3eb_2v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 1, 11 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 4, 1, 14 },
  { 4, 2, 15 },
  { 4, 3, 16 },
  { 0, 0, 0 }
};
int reftet_3eb_2v_splitfaces[][4] =
  {
    { 1, 2, 4, 17 },
    { 2, 1, 3, 18 },
    { 0, 0, 0, 0 }
  };
int reftet_3eb_2v_splitelements[][5] =
  {
    { 1, 2, 3, 4, 20 },
    { 0 },
  };

HPREF_ELEMENT_TYPE reftet_3eb_2v_newelstypes[] =
  {
    HP_PYRAMID_EDGES,
    HP_PYRAMID_EDGES,
    HP_TET_1E_1VA,
    HP_TET_1E_1VA,
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,
    
    HP_PYRAMID,
    HP_PYRAMID,
    HP_TET,
    HP_TET,
    HP_PYRAMID,
    HP_PYRAMID,
    HP_PYRAMID,
    HP_NONE,
  };
int reftet_3eb_2v_newels[][8] =
{
  { 1, 7, 17, 5, 6 },
  { 2, 9, 18, 8, 10 },
  { 3, 12, 13, 11 },
  { 4, 14, 16, 15 },
  { 5, 6, 17, 8, 18, 10 },
  { 7, 17, 6, 14, 15, 16 },
  { 9, 18, 10, 12, 11, 13 },
  
  { 10, 15, 16, 13, 20 },
  { 6, 11, 13, 16, 20 },
  { 10, 17, 15, 20 },
  { 6, 18, 11, 20 },
  { 6, 17, 10, 18, 20 },
  { 6, 16, 15, 17, 20 },
  { 18, 10, 13, 11, 20 },
};
HPRef_Struct reftet_3eb_2v =
{
  HP_TET,
  reftet_3eb_2v_splitedges, 
  reftet_3eb_2v_splitfaces, 
  reftet_3eb_2v_splitelements, 
  reftet_3eb_2v_newelstypes, 
  reftet_3eb_2v_newels
};









//  HP_TET_3EC_2V,  
int reftet_3ec_2v_splitedges[][3] =
{
  { 1, 2, 5 },
  { 1, 3, 6 },
  { 1, 4, 7 },
  { 2, 1, 8 },
  { 2, 3, 9 },
  { 2, 4, 10 },
  { 3, 1, 11 },
  { 3, 2, 12 },
  { 3, 4, 13 },
  { 4, 1, 14 },
  { 4, 2, 15 },
  { 4, 3, 16 },
  { 0, 0, 0 }
};
int reftet_3ec_2v_splitfaces[][4] =
  {
    { 1, 2, 3, 17 },
    { 2, 1, 4, 18 },
    { 0, 0, 0, 0 }
  };
int reftet_3ec_2v_splitelements[][5] =
  {
    { 1, 2, 3, 4, 20 },
    { 0 },
  };

HPREF_ELEMENT_TYPE reftet_3ec_2v_newelstypes[] =
  {
    HP_PYRAMID_EDGES,
    HP_PYRAMID_EDGES,
    HP_TET_1E_1VA,
    HP_TET_1E_1VA,
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,
    HP_PRISM_SINGEDGE,
    
    HP_PYRAMID,
    HP_PYRAMID,
    HP_TET,
    HP_TET,
    HP_PYRAMID,
    HP_PYRAMID,
    HP_PYRAMID,
    HP_NONE,
  };
int reftet_3ec_2v_newels[][8] =
{
  { 1, 5, 17, 6, 7 },
  { 2, 8, 18, 10, 9 },
  { 3, 11, 12, 13 },
  { 4, 15, 14, 16 },
  { 5, 17, 7, 8, 9, 18 },
  { 6, 7, 17, 11, 13, 12 },
  { 10, 9, 18, 15, 16, 14 },
  
  { 9, 16, 13, 12, 20 },
  { 7, 13, 16, 14, 20 },
  { 7, 14, 18, 20 },
  { 9, 12, 17, 20 },
  { 17, 7, 18, 9, 20 },
  { 7, 17, 12, 13, 20 },
  { 9, 18, 14, 16, 20 },
};
HPRef_Struct reftet_3ec_2v =
{
  HP_TET,
  reftet_3ec_2v_splitedges, 
  reftet_3ec_2v_splitfaces, 
  reftet_3ec_2v_splitelements, 
  reftet_3ec_2v_newelstypes, 
  reftet_3ec_2v_newels
};














// HP_PRISM
int refprism_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refprism_newelstypes[] =
{
  HP_PRISM,
  HP_NONE,
};
int refprism_newels[][8] =
{
  { 1, 2, 3, 4, 5, 6 }
};
HPRef_Struct refprism =
{
  HP_PRISM,
  refprism_splitedges, 
  0, 0,
  refprism_newelstypes, 
  refprism_newels
};



// HP_PRISM_SINGEDGE
int refprism_singedge_splitedges[][3] =
{
  { 1, 2, 7 },
  { 1, 3, 8 },
  { 4, 5, 9 },
  { 4, 6, 10 },
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refprism_singedge_newelstypes[] =
{
  HP_PRISM_SINGEDGE,
  HP_HEX,
  HP_NONE,
};
int refprism_singedge_newels[][8] =
{
  { 1, 7, 8, 4, 9, 10 },
  { 3, 8, 7, 2, 6, 10, 9, 5 }
};
HPRef_Struct refprism_singedge =
{
  HP_PRISM,
  refprism_singedge_splitedges, 
  0, 0,
  refprism_singedge_newelstypes, 
  refprism_singedge_newels
};







// HP_PYRAMID
int refpyramid_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refpyramid_newelstypes[] =
{
  HP_PYRAMID,
  HP_NONE,
};
int refpyramid_newels[][8] =
{
  { 1, 2, 3, 4, 5, 6 }
};
HPRef_Struct refpyramid =
{
  HP_PYRAMID,
  refpyramid_splitedges, 
  0, 0,
  refpyramid_newelstypes, 
  refpyramid_newels
};



// HP_PYRAMID_0E_1V
int refpyramid_0e_1v_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refpyramid_0e_1v_newelstypes[] =
{
  HP_TET_0E_1V,
  HP_TET,
  HP_NONE,
};
int refpyramid_0e_1v_newels[][8] =
{
  { 1, 2, 4, 5 },
  { 2, 3, 4, 5 },
};
HPRef_Struct refpyramid_0e_1v =
{
  HP_PYRAMID,
  refpyramid_0e_1v_splitedges, 
  0, 0,
  refpyramid_0e_1v_newelstypes, 
  refpyramid_0e_1v_newels
};



// HP_PYRAMID_EDGES
int refpyramid_edges_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refpyramid_edges_newelstypes[] =
{
  HP_TET_1E_1VA,
  HP_TET_1E_1VA,
  HP_NONE,
};
int refpyramid_edges_newels[][8] =
{
  { 1, 2, 3, 5 },
  { 1, 4, 5, 3 },
};
HPRef_Struct refpyramid_edges =
{
  HP_PYRAMID,
  refpyramid_edges_splitedges, 
  0, 0,
  refpyramid_edges_newelstypes, 
  refpyramid_edges_newels
};







// HP_HEX
int refhex_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refhex_newelstypes[] =
{
  HP_HEX,
  HP_NONE,
};
int refhex_newels[][8] =
{
  { 1, 2, 3, 4, 5, 6, 7, 8 }
};
HPRef_Struct refhex =
{
  HP_HEX,
  refhex_splitedges, 
  0, 0,
  refhex_newelstypes, 
  refhex_newels
};




// HP_HEX_0E_1V
int refhex_0e_1v_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refhex_0e_1v_newelstypes[] =
{
  HP_TET_0E_1V,
  HP_TET,
  HP_TET,
  HP_TET,
  HP_TET,
  HP_TET,
  HP_NONE,
};
int refhex_0e_1v_newels[][8] =
{
  { 1, 5, 2, 4 },
  { 7, 3, 6, 8 },
  { 2, 8, 5, 6 },
  { 2, 8, 6, 3 },
  { 2, 8, 3, 4 },
  { 2, 8, 4, 5 },
};
HPRef_Struct refhex_0e_1v =
{
  HP_HEX,
  refhex_0e_1v_splitedges, 
  0, 0,
  refhex_0e_1v_newelstypes, 
  refhex_0e_1v_newels
};






// HP_HEX_3E_0V
int refhex_3e_0v_splitedges[][3] =
{
  { 0, 0, 0 }
};
HPREF_ELEMENT_TYPE refhex_3e_0v_newelstypes[] =
{
  HP_TET_1E_1VA,
  HP_TET_1E_1VA,
  HP_TET_1E_1VA,
  HP_TET_0E_1V,
  HP_TET,
  HP_NONE,
};
int refhex_3e_0v_newels[][8] =
{
  { 1, 2, 3, 6 },
  { 1, 4, 8, 3 },
  { 1, 5, 6, 8 },
  { 1, 6, 3, 8 },
  { 3, 8, 6, 7 },
};
HPRef_Struct refhex_3e_0v =
{
  HP_HEX,
  refhex_3e_0v_splitedges, 
  0, 0,
  refhex_3e_0v_newelstypes, 
  refhex_3e_0v_newels
};




// HP_HEX_1E_0V
int refhex_1e_0v_splitedges[][3] =
{
  { 0, 0, 0 }
};

HPREF_ELEMENT_TYPE refhex_1e_0v_newelstypes[] =
{
  HP_PRISM_SINGEDGE,
  HP_PRISM,
  HP_NONE,
};
int refhex_1e_0v_newels[][8] =
{
  { 1, 4, 5, 2, 3, 6 },
  { 5, 4, 8, 6, 3, 7 },
};
HPRef_Struct refhex_1e_0v =
{
  HP_HEX,
  refhex_1e_0v_splitedges, 
  0, 0,
  refhex_1e_0v_newelstypes, 
  refhex_1e_0v_newels
};








HPRef_Struct * Get_HPRef_Struct (HPREF_ELEMENT_TYPE type)
{
  HPRef_Struct * hps = NULL;
  switch (type)
    {
    case HP_TRIG:
      hps = &reftrig; break;
    case HP_TRIG_SINGCORNER:
      hps = &reftrig_singcorner; break;
    case HP_TRIG_SINGCORNER12:
      hps = &reftrig_singcorner12; break;
    case HP_TRIG_SINGCORNER123:
      hps = &reftrig_singcorner123; break;
    case HP_TRIG_SINGEDGE:
      hps = &reftrig_singedge; break;
    case HP_TRIG_SINGEDGECORNER1:
      hps = &reftrig_singedgecorner1; break;
    case HP_TRIG_SINGEDGECORNER2:
      hps = &reftrig_singedgecorner2; break;
    case HP_TRIG_SINGEDGECORNER12:
      hps = &reftrig_singedgecorner12; break;
    case HP_TRIG_SINGEDGECORNER3:
      hps = &reftrig_singedgecorner3; break;
    case HP_TRIG_SINGEDGECORNER13:
      hps = &reftrig_singedgecorner13; break;
    case HP_TRIG_SINGEDGECORNER23:
      hps = &reftrig_singedgecorner23; break;
    case HP_TRIG_SINGEDGECORNER123:
      hps = &reftrig_singedgecorner123; break;
    case HP_TRIG_SINGEDGES:
      hps = &reftrig_singedges; break;
    case HP_TRIG_SINGEDGES2:
      hps = &reftrig_singedges2; break;
    case HP_TRIG_SINGEDGES3:
      hps = &reftrig_singedges3; break;
    case HP_TRIG_SINGEDGES23:
      hps = &reftrig_singedges23; break;
    case HP_QUAD:
      hps = &refquad; break;
    case HP_DUMMY_QUAD_SINGCORNER:
      hps = &refdummyquad_singcorner; break;
    case HP_QUAD_SINGCORNER:
      hps = &refquad_singcorner; break;
    case HP_QUAD_SINGEDGE:
      hps = &refquad_singedge; break;
    case HP_QUAD_SINGEDGES:
      hps = &refquad_singedges; break;

    case HP_TET:
      hps = &reftet; break;
    case HP_TET_0E_1V:
      hps = &reftet_0e_1v; break;
    case HP_TET_0E_2V:
      hps = &reftet_0e_2v; break;
    case HP_TET_0E_3V:
      hps = &reftet_0e_3v; break;
    case HP_TET_0E_4V:
      hps = &reftet_0e_4v; break;

    case HP_TET_1E_0V:      
      hps = &reftet_1e_0v; break;
    case HP_TET_1E_1VA:
      hps = &reftet_1e_1va; break;
    case HP_TET_1E_1VB:
      hps = &reftet_1e_1vb; break;

    case HP_TET_1E_2VA:
      hps = &reftet_1e_2va; break;
    case HP_TET_1E_2VB:
      hps = &reftet_1e_2vb; break;
    case HP_TET_1E_2VC:
      hps = &reftet_1e_2vc; break;
    case HP_TET_1E_2VD:
      hps = &reftet_1e_2vd; break;

    case HP_TET_2EA_0V:
      hps = &reftet_2ea_0v; break;
    case HP_TET_2EA_1VB:
      hps = &reftet_2ea_1vb; break;
    case HP_TET_2EA_3V:
      hps = &reftet_2ea_3v; break;

    case HP_TET_2EB_4V:
      hps = &reftet_2eb_4v; break;


    case HP_TET_3EA_0V:
      hps = &reftet_3ea_0v; break;
    case HP_TET_3EA_3V:
      hps = &reftet_3ea_3v; break;

    case HP_TET_3EB_2V:
      hps = &reftet_3eb_2v; break;
    case HP_TET_3EC_2V:
      hps = &reftet_3ec_2v; break;

    case HP_PRISM:
      hps = &refprism; break;
    case HP_PRISM_SINGEDGE:
      hps = &refprism_singedge; break;

    case HP_PYRAMID:
      hps = &refpyramid; break;
    case HP_PYRAMID_0E_1V:
      hps = &refpyramid_0e_1v; break;
    case HP_PYRAMID_EDGES:
      hps = &refpyramid_edges; break;

    case HP_HEX:
      hps = &refhex; break;
    case HP_HEX_0E_1V:
      hps = &refhex_0e_1v; break;
    case HP_HEX_1E_0V:
      hps = &refhex_1e_0v; break;
    case HP_HEX_3E_0V:
      hps = &refhex_3e_0v; break;
    }

  return hps;
}



class HPRefElement
{
public:
  HPREF_ELEMENT_TYPE type;
  int pnums[8];
  int index;
  int level;
};

static ARRAY<HPRefElement> elements;

void PrepareElements (Mesh & mesh)
{
  cout << "Transform mesh to hp-elements" << endl;

  int i, j, k, pi3, pi4;
  INDEX_2_HASHTABLE<int> edges(mesh.GetNSeg()+1);
  BitArray edgepoint(mesh.GetNP());
  edgepoint.Clear();
  BitArray cornerpoint(mesh.GetNP());
  cornerpoint.Clear();

  // check, if point has as least 3 different surfs:
  ARRAY<INDEX_3> surfonpoint(mesh.GetNP());

  if (mesh.GetDimension() == 3)
    {
      for (i = 1; i <= mesh.GetNP(); i++)
	surfonpoint.Elem(i) = INDEX_3(0,0,0);
      for (i = 1; i <= mesh.GetNSE(); i++)
	{
	  const Element2d & el = mesh.SurfaceElement(i);
	  int ind = el.GetIndex();
	  for (j = 0; j < el.GetNP(); j++)
	    {
	      int pi = el[j];
	      INDEX_3 & i3 = surfonpoint.Elem(pi);
	      if (ind != i3.I1() &&
		  ind != i3.I2() && 
		  ind != i3.I3())
		{
		  i3.I1() = i3.I2();
		  i3.I2() = i3.I3();
		  i3.I3() = ind;
		}
	    }
	}
      for (i = 1; i <= mesh.GetNP(); i++)
	if (surfonpoint.Get(i).I1())
	  cornerpoint.Set(i);
      
      // cornerpoint.Clear();
      //  cornerpoint.Set(1);

      for (i = 1; i <= mesh.GetNSeg(); i++)
	{
	  INDEX_2 i2 (mesh.LineSegment(i).p1, 
		      mesh.LineSegment(i).p2);
	  i2.Sort();
	  // if (i2.I1() == 11 && i2.I2() == 12)
	  {
	    edges.Set (i2, 1);
	    edgepoint.Set (i2.I1());
	    edgepoint.Set (i2.I2());
	  }
	}
    }
  else
    {
      for (i = 1; i <= mesh.GetNP(); i++)
	surfonpoint.Elem(i) = INDEX_3(0,0,0);
      
      for (i = 1; i <= mesh.GetNSeg(); i++)
	{
	  const Segment & seg = mesh.LineSegment(i);
	  int ind = seg.edgenr;
	  if (ind <= 12) continue;

	  INDEX_2 i2 (mesh.LineSegment(i).p1, 
		      mesh.LineSegment(i).p2);
	  i2.Sort();
	  edges.Set (i2, 1);
	  edgepoint.Set(i2.I1());
	  edgepoint.Set(i2.I2());

	  // (*testout) << "seg = " << ind << ", " << seg.p1 << "-" << seg.p2 << endl;
	  for (j = 0; j < 2; j++)
	    {
	      int pi = (j == 0) ? seg.p1 : seg.p2;
	      // if (pi > 20)
		{
		  INDEX_3 & i3 = surfonpoint.Elem(pi);
		  if (ind != i3.I1() &&
		      ind != i3.I2())
		    {
		      i3.I1() = i3.I2();
		      i3.I2() = ind;
		    }
		}
	    }
	}
      for (i = 1; i <= mesh.GetNP(); i++)
	if (surfonpoint.Get(i).I1())
	  {
	    cornerpoint.Set(i);
	  }
    }

  int cnt_undef = 0, cnt_nonimplement = 0;
  ARRAY<int> misses(10000);
  misses = 0;

  for (i = 1; i <= mesh.GetNE(); i++)
    {
      Element & el = mesh.VolumeElement(i);
      
      HPREF_ELEMENT_TYPE type = HP_NONE;
      int pnums[8] = { 0 };


      switch (el.GetType())
	{
	  case TET:
	    {
	      int ep1, ep2, ep3, ep4, cp1, cp2, cp3, cp4;
	      int isedge1, isedge2, isedge3, isedge4, isedge5, isedge6;
	      
	      for (j = 1; j <= 4; j++)
		for (k = 1; k <= 4; k++)
		  {
		    if (j == k) continue;
		    if (type) break;
	    
	    int pi3 = 1;
	    while (pi3 == j || pi3 == k) pi3++;
	    pi4 = 10 - j - k - pi3;

	    // preserve orientation
	    int sort[4];
	    sort[0] = j; sort[1] = k; sort[2] = pi3; sort[3] = pi4;
	    int cnt = 0;
	    for (int jj = 0; jj < 4; jj++)
	      for (int kk = 0; kk < 3; kk++)
		if (sort[kk] > sort[kk+1])
		  {
		    cnt++;
		    Swap (sort[kk], sort[kk+1]);
		  }
	    if (cnt % 2 == 1) Swap (pi3, pi4);

	    ep1 = edgepoint.Test (el.PNum (j));
	    ep2 = edgepoint.Test (el.PNum (k));
	    ep3 = edgepoint.Test (el.PNum (pi3));
	    ep4 = edgepoint.Test (el.PNum (pi4));

	    cp1 = cornerpoint.Test (el.PNum (j));
	    cp2 = cornerpoint.Test (el.PNum (k));
	    cp3 = cornerpoint.Test (el.PNum (pi3));
	    cp4 = cornerpoint.Test (el.PNum (pi4));
	    
	    INDEX_2 i2;
	    i2 = INDEX_2(el.PNum (j), el.PNum (k));
	    i2.Sort();
	    isedge1 = edges.Used (i2);

	    i2 = INDEX_2(el.PNum (j), el.PNum (pi3));
	    i2.Sort();
	    isedge2 = edges.Used (i2);

	    i2 = INDEX_2(el.PNum (j), el.PNum (pi4));
	    i2.Sort();
	    isedge3 = edges.Used (i2);

	    i2 = INDEX_2(el.PNum (k), el.PNum (pi3));
	    i2.Sort();
	    isedge4 = edges.Used (i2);

	    i2 = INDEX_2(el.PNum (k), el.PNum (pi4));
	    i2.Sort();
	    isedge5 = edges.Used (i2);

	    i2 = INDEX_2(el.PNum (pi3), el.PNum (pi4));
	    i2.Sort();
	    isedge6 = edges.Used (i2);

	    switch (isedge1+isedge2+isedge3+isedge4+isedge5+isedge6)
	      {
	      case 0:
		{		
		  if (!ep1 && !ep2 && !ep3 && !ep4)
		    type = HP_TET;
		  
		  if (ep1 && !ep2 && !ep3 && !ep4)
		    type = HP_TET_0E_1V;

		  if (ep1 && ep2 && !ep3 && !ep4)
		    type = HP_TET_0E_2V;

		  if (ep1 && ep2 && ep3 && !ep4)
		    type = HP_TET_0E_3V;

		  if (ep1 && ep2 && ep3 && ep4)
		    type = HP_TET_0E_4V;

		  break;
		}
		
	      case 1:
		{
		  if (!isedge1) break;
		  
		  if (!cp1 && !cp2 && !ep3 && !ep4)
		    type = HP_TET_1E_0V;
		    
		  if (cp1 && !cp2 && !ep3 && !ep4)
		    type = HP_TET_1E_1VA;

		  if (!cp1 && !cp2 && !ep3 && ep4)
		    type = HP_TET_1E_1VB;

		  if (cp1 && cp2 && !ep3 && !ep4)
		    type = HP_TET_1E_2VA;

		  if (cp1 && !cp2 && ep3 && !ep4)
		    type = HP_TET_1E_2VB;

		  if (cp1 && !cp2 && !ep3 && ep4)
		    type = HP_TET_1E_2VC;

		  if (!cp1 && !cp2 && ep3 && ep4)
		    type = HP_TET_1E_2VD;

		  if (cp1 && cp2 && ep3 && !ep4)
		    type = HP_TET_1E_3VA;

		  if (cp1 && !cp2 && ep3 && ep4)
		    type = HP_TET_1E_3VB;

		  if (cp1 && cp2 && ep3 && ep4)
		    type = HP_TET_1E_4V;
		  
		  break;
		}

	      case 2:
		{
		  if (isedge1 && isedge2)
		    {
		      if (!cp2 && !cp3 && !ep4)
			type = HP_TET_2EA_0V;
		      if (cp2 && !cp3 && !ep4)
			type = HP_TET_2EA_1VA;

		      if (!cp2 && cp3 && !ep4)
			type = HP_TET_2EA_1VB;

		      if (!cp2 && !cp3 && ep4)
			type = HP_TET_2EA_1VC;

		      if (cp2 && cp3 && !ep4)
			type = HP_TET_2EA_2VA;
		      if (cp2 && !cp3 && ep4)
			type = HP_TET_2EA_2VB;
		      if (!cp2 && cp3 && ep4)
			type = HP_TET_2EA_2VC;

		      if (cp2 && cp3 && ep4)
			type = HP_TET_2EA_3V;
		    }

		  if (isedge1 && isedge6)
		    {
		      if (!cp1 && !cp2 && !cp3 && !cp4)
			type = HP_TET_2EB_0V;

		      if (cp1 && !cp2 && !cp3 && !cp4)
			type = HP_TET_2EB_1V;

		      if (cp1 && cp2 && !cp3 && !cp4)
			type = HP_TET_2EB_2VA;
		      if (cp1 && !cp2 && cp3 && !cp4)
			type = HP_TET_2EB_2VB;
		      if (cp1 && !cp2 && !cp3 && cp4)
			type = HP_TET_2EB_2VC;

		      if (cp1 && cp2 && cp3 && !cp4)
			type = HP_TET_2EB_3V;

		      if (cp1 && cp2 && cp3 && cp4)
			type = HP_TET_2EB_4V;
		    }
		}

	      case 3:
		{
		  if (isedge1 && isedge2 && isedge3)
		    {
		      if (!cp2 && !cp3 && !cp4)
			type = HP_TET_3EA_0V;
		      if (cp2 && cp3 && ep4)
			type = HP_TET_3EA_3V;
		    }
		  if (isedge1 && isedge3 && isedge4)
		    {
		      if (cp3 && ep4)
			type = HP_TET_3EB_2V;
		    }
		  if (isedge1 && isedge2 && isedge5)
		    {
		      if (cp3 && ep4)
			type = HP_TET_3EC_2V;
		    }
		}
	      }

	    if (type != HP_NONE)
	      {
		pnums[0] = el.PNumMod (j);
		pnums[1] = el.PNumMod (k);
		pnums[2] = el.PNumMod (pi3);
		pnums[3] = el.PNumMod (pi4);
		break;
	      }
		  }


      if (type == HP_NONE)
	{
	  cnt_undef++;
	  (*testout) << "undefined element" << endl
		     << "cp = " << cp1 << cp2 << cp3 << cp4 << endl
		     << "ep = " << ep1 << ep2 << ep3 << ep4 << endl
		     << "isedge = " << isedge1 << isedge2 << isedge3 
		     << isedge4 << isedge5 << isedge6 << endl;
	}
      //      cout << "hpref - element = " << type << endl;
      


	      break;
	    }
	case PRISM:
	  {
	    int pi1, pi2, pi3, pi4, pi5, pi6;
	    int ep1, ep2, ep3, ep4, ep5, ep6, cp1, cp2, cp3, cp4, cp5, cp6;

	    int ishedge1, ishedge2, ishedge3, ishedge4, ishedge5, ishedge6;
	    int isvedge1, isvedge2, isvedge3;
	    
	    for (j = 1; j <= 3; j++)
	      {
		if (type) break;

		pi1 = j;
		pi2 = pi1%3 + 1;
		pi3 = pi2%3 + 1;
		pi4 = pi1+3;
		pi5 = pi2+3;
		pi6 = pi3+3;

		ep1 = edgepoint.Test (el.PNum (pi1));
		ep2 = edgepoint.Test (el.PNum (pi2));
		ep3 = edgepoint.Test (el.PNum (pi3));
		ep4 = edgepoint.Test (el.PNum (pi4));
		ep5 = edgepoint.Test (el.PNum (pi5));
		ep6 = edgepoint.Test (el.PNum (pi6));

		cp1 = cornerpoint.Test (el.PNum (pi1));
		cp2 = cornerpoint.Test (el.PNum (pi2));
		cp3 = cornerpoint.Test (el.PNum (pi3));
		cp4 = cornerpoint.Test (el.PNum (pi4));
		cp5 = cornerpoint.Test (el.PNum (pi5));
		cp6 = cornerpoint.Test (el.PNum (pi6));
	    
		INDEX_2 i2;
		i2 = INDEX_2(el.PNum (pi1), el.PNum (pi4));
		i2.Sort();
		isvedge1 = edges.Used (i2);


		if (isvedge1 + isvedge2 + isvedge3 == 0)
		  {
		    type = HP_PRISM;
		  }
		else if (isvedge1)
		  {
		    type = HP_PRISM_SINGEDGE;
		  }


		if (type != HP_NONE)
		  {
		    pnums[0] = el.PNum (pi1);
		    pnums[1] = el.PNum (pi2);
		    pnums[2] = el.PNum (pi3);
		    pnums[3] = el.PNum (pi4);
		    pnums[4] = el.PNum (pi5);
		    pnums[5] = el.PNum (pi6);
		    break;
		  }
	      }
	    break;
	  }
	default:
	  {
	    cerr << "hp-refinement not defined for element" << endl;
	  }
	}

      if (!Get_HPRef_Struct (type)) 
	{
	  (*testout) << "case " << type << " not implemented " << endl;
	  cnt_nonimplement++;
	  misses[type]++;
	}
      
      HPRefElement hpel;
      hpel.type = type;
      for (j = 0; j < 8; j++)
	hpel.pnums[j] = pnums[j];
      hpel.index = el.GetIndex();
      hpel.level = 1;
      elements.Append (hpel);
    }

  cout << "undefined elements: " << cnt_undef << endl;
  cout << "non-implemented: " << cnt_nonimplement << endl;

  for (i = 0; i < misses.Size(); i++)
    if (misses[i])
      cout << "missing case " << i << " occured " << misses[i] << " times" << endl;

  for (i = 1; i <= mesh.GetNSE(); i++)
    {
      Element2d & el = mesh.SurfaceElement(i);
      
      HPREF_ELEMENT_TYPE type = HP_NONE;
      int pnums[8] = { 0 };

      switch (el.GetType())
	{
	case TRIG:
	  {
	    for (j = 1; j <= 3; j++)
	      {
		int ep1 = edgepoint.Test (el.PNumMod (j));
		int ep2 = edgepoint.Test (el.PNumMod (j+1));
		int ep3 = edgepoint.Test (el.PNumMod (j+2));
		
		int cp1 = cornerpoint.Test (el.PNumMod (j));
		int cp2 = cornerpoint.Test (el.PNumMod (j+1));
		int cp3 = cornerpoint.Test (el.PNumMod (j+2));
		
		INDEX_2 i2;
		i2 = INDEX_2(el.PNumMod (j), el.PNumMod (j+1));
		i2.Sort();
		int isedge1 = edges.Used (i2);
		i2 = INDEX_2(el.PNumMod (j+1), el.PNumMod (j+2));
		i2.Sort();
		int isedge2 = edges.Used (i2);
		i2 = INDEX_2(el.PNumMod (j+2), el.PNumMod (j+3));
		i2.Sort();
		int isedge3 = edges.Used (i2);
		
		if (isedge1 + isedge2 + isedge3 == 0)
		  {
		    if (!ep1 && !ep2 && !ep3)
		      type = HP_TRIG;
		    
		    if (ep1 && !ep2 && !ep3)
		      type = HP_TRIG_SINGCORNER;
		    
		    if (ep1 && ep2 && !ep3)
		      type = HP_TRIG_SINGCORNER12;
		    
		    if (ep1 && ep2 && ep3)
		      type = HP_TRIG_SINGCORNER123;
		    
		    if (type != HP_NONE)
		      {
			pnums[0] = el.PNumMod (j);
			pnums[1] = el.PNumMod (j+1);
			pnums[2] = el.PNumMod (j+2);
			break;
		      }
		  }
		
		if (isedge1 && !isedge2 && !isedge3)
		  {
		    int code = 0;
		    if (cp1) code += 1;
		    if (cp2) code += 2;
		    if (ep3) code += 4;
		    
		    HPREF_ELEMENT_TYPE types[] =
		      {
			HP_TRIG_SINGEDGE, 
			HP_TRIG_SINGEDGECORNER1, 
			HP_TRIG_SINGEDGECORNER2,
			HP_TRIG_SINGEDGECORNER12, 
			HP_TRIG_SINGEDGECORNER3, 
			HP_TRIG_SINGEDGECORNER13, 
			HP_TRIG_SINGEDGECORNER23, 
			HP_TRIG_SINGEDGECORNER123, 
		      };
		    type = types[code];
		    pnums[0] = el.PNumMod (j);
		    pnums[1] = el.PNumMod (j+1);
		    pnums[2] = el.PNumMod (j+2);
		    break;
		  }
		
		
		if (isedge1 && !isedge2 && isedge3)
		  {
		    if (!cp3)
		      {
			if (!cp2) type = HP_TRIG_SINGEDGES;
			else      type = HP_TRIG_SINGEDGES2;
		      }
		    else
		      {
			if (!cp2) type = HP_TRIG_SINGEDGES3;
			else      type = HP_TRIG_SINGEDGES23;
		      }
		    
		    pnums[0] = el.PNumMod (j);
		    pnums[1] = el.PNumMod (j+1);
		    pnums[2] = el.PNumMod (j+2);
		    break;
		  }
		
		if (isedge1 && isedge2 && isedge3)
		  {
		    type = HP_TRIG_3SINGEDGES;
		    pnums[0] = el.PNumMod (j);
		    pnums[1] = el.PNumMod (j+1);
		    pnums[2] = el.PNumMod (j+2);
		    break;
		  }
	      }
	    break;
	  }
	case QUAD:
	  {
	    for (j = 1; j <= 4; j++)
	      {
		int ep1 = edgepoint.Test (el.PNumMod (j));
		int ep2 = edgepoint.Test (el.PNumMod (j+1));
		int ep3 = edgepoint.Test (el.PNumMod (j+2));
		int ep4 = edgepoint.Test (el.PNumMod (j+3));
		
		int cp1 = cornerpoint.Test (el.PNumMod (j));
		int cp2 = cornerpoint.Test (el.PNumMod (j+1));
		int cp3 = cornerpoint.Test (el.PNumMod (j+2));
		int cp4 = cornerpoint.Test (el.PNumMod (j+3));
		
		INDEX_2 i2;
		i2 = INDEX_2(el.PNumMod (j), el.PNumMod (j+1));
		i2.Sort();
		int isedge1 = edges.Used (i2);
		i2 = INDEX_2(el.PNumMod (j+1), el.PNumMod (j+2));
		i2.Sort();
		int isedge2 = edges.Used (i2);
		i2 = INDEX_2(el.PNumMod (j+2), el.PNumMod (j+3));
		i2.Sort();
		int isedge3 = edges.Used (i2);
		i2 = INDEX_2(el.PNumMod (j+3), el.PNumMod (j+4));
		i2.Sort();
		int isedge4 = edges.Used (i2);
		
	  
		if (isedge1 + isedge2 + isedge3 + isedge4 == 0)
		  {
		    type = HP_QUAD;
		  }
		else if (isedge1)
		  {
		    type = HP_QUAD_SINGEDGE;
		  }

		if (type != HP_NONE)
		  {
		    pnums[0] = el.PNumMod (j);
		    pnums[1] = el.PNumMod (j+1);
		    pnums[2] = el.PNumMod (j+2);
		    pnums[3] = el.PNumMod (j+3);
		    break;
		  }
	      }
	    break;
	  }
	}
	  
      HPRefElement hpel;
      hpel.type = type;
      for (j = 0; j < 8; j++)
	hpel.pnums[j] = pnums[j];
      hpel.index = el.GetIndex();
      hpel.level = 1;
      
      elements.Append (hpel);
    }
}



void DoRefinement (Mesh & mesh)
{
  int i, j, k;

  INDEX_2_HASHTABLE<int> newpts(elements.Size()+1);
  INDEX_3_HASHTABLE<int> newfacepts(elements.Size()+1);
  
  // prepare new points
  
  (*testout) << "find new points" << endl;
  int oldelsize = elements.Size();
  for (i = 1; i <= oldelsize; i++)
    {
      (*testout) << "el " << i << endl;

      HPRefElement & el = elements.Elem(i);
      HPRef_Struct * hprs = Get_HPRef_Struct (el.type);

      (*testout) << "type = " << el.type << endl;

      
      if (!hprs)
	{
	  // cout << "Refinementstruct not defined for element " << el.type << endl;
	  continue;
	}

      j = 0;
      while (hprs->splitedges[j][0])
	{
	  INDEX_2 i2(el.pnums[hprs->splitedges[j][0]-1],
		     el.pnums[hprs->splitedges[j][1]-1]);
	  if (!newpts.Used (i2))
	    {
	      Point3d np = Center (mesh.Point (i2.I1()),
				   mesh.Point (i2.I2()));
	      np = Center (mesh.Point (i2.I1()),np);
	      np = Center (mesh.Point (i2.I1()),np);
	      int npi = mesh.AddPoint (np);
	      newpts.Set (i2, npi);
	    }
	  j++;
	}



      j = 0;
      if (hprs->splitfaces)
	while (hprs->splitfaces[j][0])
	  {
	    INDEX_3 i3(el.pnums[hprs->splitfaces[j][0]-1],
		       el.pnums[hprs->splitfaces[j][1]-1],
		       el.pnums[hprs->splitfaces[j][2]-1]);
	    if (i3.I2() > i3.I3())
	      Swap (i3.I2(), i3.I3());
	    if (!newfacepts.Used (i3))
	      {
		Point3d np = Center (mesh.Point (i3.I2()),
				     mesh.Point (i3.I3()));
		np = Center (mesh.Point (i3.I1()),np);
		np = Center (mesh.Point (i3.I1()),np);
		int npi = mesh.AddPoint (np);
		newfacepts.Set (i3, npi);
	      }
	    j++;
	  }
    }
  


  (*testout) << "generate elements" << endl;

  for (i = 1; i <= oldelsize; i++)
    {
      (*testout) << "el " << i << endl;

      HPRefElement & el = elements.Elem(i);
      HPRef_Struct * hprs = Get_HPRef_Struct (el.type);
      int newlevel = el.level + 1;

      if (el.type == HP_TRIG ||
	  el.type == HP_QUAD ||
	  el.type == HP_TET ||
	  el.type == HP_PRISM ||
	  el.type == HP_HEX)
	newlevel = el.level;

      (*testout) << "type = " << el.type << endl;

      if (!hprs)
	{
	  continue;
	}

      int newpnums[33];
      for (j = 0; j < 8; j++)
	newpnums[j] = el.pnums[j];

      j = 0;
      while (hprs->splitedges[j][0])
	{
	  INDEX_2 i2(el.pnums[hprs->splitedges[j][0]-1],
		     el.pnums[hprs->splitedges[j][1]-1]);

	  int npi = newpts.Get(i2);
	  newpnums[hprs->splitedges[j][2]-1] = npi;
	  j++;
	}

      j = 0;
      if (hprs->splitfaces)
	while (hprs->splitfaces[j][0])
	  {
	    INDEX_3 i3(el.pnums[hprs->splitfaces[j][0]-1],
		       el.pnums[hprs->splitfaces[j][1]-1],
		       el.pnums[hprs->splitfaces[j][2]-1]);
	    if (i3.I2() > i3.I3())
	      Swap (i3.I2(), i3.I3());
	    int npi = newfacepts.Get(i3);
	    newpnums[hprs->splitfaces[j][3]-1] = npi;
	    j++;
	  }


      j = 0;
      if (hprs->splitelements)
	while (hprs->splitelements[j][0])
	  {
	    int pi1 = el.pnums[hprs->splitelements[j][0]-1];
	    Point3d np = 
	      Center (Center (mesh.Point (pi1),
			      mesh.Point (el.pnums[hprs->splitelements[j][1]-1])),
		      Center (mesh.Point (el.pnums[hprs->splitelements[j][2]-1]),
			      mesh.Point (el.pnums[hprs->splitelements[j][3]-1])));
	    
	    np = Center (mesh.Point (pi1),np);
	    int npi = mesh.AddPoint (np);
	    newpnums[hprs->splitelements[j][4]-1] = npi;
	    j++;
	  }
      (*testout) << "type = " << el.type << endl;
      (*testout) << "newpnums = ";
      for (k = 0; k < 10; k++)
	(*testout) << newpnums[k] << " ";
      (*testout) << endl;

      j = 0;
      while (hprs->neweltypes[j])
	{
	  HPRefElement newel;
	  newel.type = hprs->neweltypes[j];
	  for (k = 0; k < 8; k++)
	    newel.pnums[k] = newpnums[hprs->newels[j][k]-1];

	  if (newel.pnums[1] == newel.pnums[3])
	    {
	      cout << "same node numbers !!!! " << endl;
	      (*testout) << "same node numbers !!!! " << endl;
	    }
	  (*testout) << "new el: ";
	  for (k = 0; k < 8; k++)
	    (*testout) << newel.pnums[k] << " ";
	  (*testout) << endl;

	  newel.index = elements.Elem(i).index;
	  newel.level = newlevel;

	  if (j == 0)
	    elements.Elem(i) = newel;
	  else
	    elements.Append (newel);
	  j++;
	}
      (*testout) << "el complete" << endl;
    }

  cout << "refinement done" << endl;
}



void DoRefineDummies (Mesh & mesh)
{
  cout << "refine dummies" << endl;
  int i, j, k;

  int oldelsize = elements.Size();

  for (i = 1; i <= oldelsize; i++)
    {
      HPRefElement & el = elements.Elem(i);
      HPRef_Struct * hprs = Get_HPRef_Struct (el.type);

      int newlevel = el.level;

      if (el.type != HP_DUMMY_QUAD_SINGCORNER &&
	  el.type != HP_PYRAMID_EDGES &&
	  el.type != HP_PYRAMID_0E_1V &&
	  el.type != HP_HEX_0E_1V &&
	  el.type != HP_HEX_1E_0V &&
	  el.type != HP_HEX_3E_0V
	  ) continue;

      if (!hprs) continue;

      int newpnums[33];
      for (j = 0; j < 8; j++)
	newpnums[j] = el.pnums[j];

      j = 0;
      while (hprs->neweltypes[j])
	{
	  HPRefElement newel;
	  newel.type = hprs->neweltypes[j];
	  for (k = 0; k < 8; k++)
	    newel.pnums[k] = newpnums[hprs->newels[j][k]-1];
	  newel.index = el.index;

	  newel.level = newlevel;

	  if (j == 0)
	    elements.Elem(i) = newel;
	  else
	    elements.Append (newel);
	  j++;
	}
    }
  cout << "refineme dummies done" << endl;
}







void CalcStatistics ()
{
  int i, p;
  int ntrig = 0, nquad = 0;
  int nhex = 0, nprism = 0, ntet = 0;
  int maxlevel = 0;

  for (i = 1; i <= elements.Size(); i++)
    {
      const HPRefElement & el = elements.Get(i);
      maxlevel = max2 (el.level, maxlevel);
      switch (el.type)
	{
	case HP_TRIG:
	case HP_TRIG_SINGCORNER:
	case HP_TRIG_SINGEDGE:
	case HP_TRIG_SINGEDGECORNER1:
	case HP_TRIG_SINGEDGECORNER2:
	  {
	    ntrig ++;
	    break;
	  }
	case HP_QUAD:
	case HP_QUAD_SINGEDGE:
	  {
	    nquad++;
	    break;
	  }
	case HP_TET:
	case HP_TET_0E_1V:
	case HP_TET_1E_0V:
	case HP_TET_1E_1VA:
	  {
	    ntet++;
	    break;
	  }

	case HP_PRISM:
	case HP_PRISM_SINGEDGE:
	  {
	    nprism++;
	    break;
	  }

	case HP_HEX:
	  {	
	    nhex++;
	    break;
	  }
	}
    }

  cout << "level = " << maxlevel << endl;
  cout << "ntrig = " << ntrig << ", nquad = " << nquad << endl;
  cout << "ntet = " << ntet << ", nprism = " << nprism << ", nhex = " << nhex << endl;

  return;

  double memcost = 0, cpucost = 0;
  for (p = 1; p <= 20; p++)
    {
      memcost = (ntet + nprism + nhex) * pow (p, 6.0);
      cpucost = (ntet + nprism + nhex) * pow (p, 9.0);
      cout << "costs for p = " << p << ": mem = " << memcost << ", cpu = " << cpucost << endl;
    }

  double memcosttet = 0;
  double memcostprism = 0;
  double memcosthex = 0;
  double memcostsctet = 0;
  double memcostscprism = 0;
  double memcostschex = 0;
  double cpucosttet = 0;
  double cpucostprism = 0;
  double cpucosthex = 0;

  for (i = 1; i <= elements.Size(); i++)
    {
      const HPRefElement & el = elements.Get(i);
      switch (el.type)
	{
	case HP_TET:
	case HP_TET_0E_1V:
	case HP_TET_1E_0V:
	case HP_TET_1E_1VA:
	  {
	    int p1 = maxlevel - el.level + 1;
	    (*testout) << "p1 = " << p1 << ", P1^6 = " << pow (p1, 6.0)
		       << " (p1-3)^6 = " << pow ( max2(p1-3, 0), 6.0) 
		       << " p1^3 = " << pow ( p1, 3.0) 
		       << " (p1-3)^3 = " << pow ( p1-3, 3.0) 
		       << " [p1^3-(p1-3)^3]^2 = " << sqr (pow (p1,3.0) - pow ( p1-3, 3.0))
		       << endl;

	    p1 /= 2 +1;
	    memcosttet += pow (p1, 6.0);
	    memcostsctet += pow (p1, 6.0) - pow ( max2(p1-3, 1), 6.0);
	    cpucosttet += pow (p1, 9.0);
	    break;
	  }
	case HP_PRISM:
	case HP_PRISM_SINGEDGE:
	  {
	    int p1 = maxlevel - el.level + 1;
	    p1 /= 2 +1;
	    memcostprism += pow (p1, 6.0);
	    memcostscprism += pow (p1, 6.0) - pow ( max2(p1-3, 1), 6.0);
	    cpucostprism += pow (p1, 9.0);
	    break;
	  }
	case HP_HEX:
	  {	
	    int p1 = maxlevel - el.level + 1;
	    int p2 = maxlevel;
	    p1 /= 2 +1;
	    p2 /= 2 +1;
	    memcosthex += pow (p1, 4.0) * pow (p2, 2.0);
	    memcostschex += pow (p1, 6.0) - pow ( max2(p1-2, 0), 6.0);
	    cpucosthex += pow (p1, 6.0) * pow (p2, 3.0);
	    break;
	  }
	default:
	  ;
	}
    }
  cout << "TET: hp-memcost = " << memcosttet 
       << ", scmemcost = " << memcostsctet
       << ", cpucost = " << cpucosttet
       << endl;
  cout << "PRI: hp-memcost = " << memcostprism
       << ", scmemcost = " << memcostscprism
       << ", cpucost = " << cpucostprism << endl;
  cout << "HEX: hp-memcost = " << memcosthex
       << ", scmemcost = " << memcostschex
       << ", cpucost = " << cpucosthex << endl;
}

void HPRefinement (Mesh & mesh, int levels)
{
  int i, j;
  cout << "HP Refinement called, levels = " << levels;

  PrepareElements (mesh);

  for (j = 1; j <= levels; j++)
    {
      DoRefinement (mesh);
      DoRefineDummies (mesh);
      CalcStatistics ();
    }
  
  mesh.ClearSurfaceElements();
  mesh.ClearVolumeElements();

  for (i = 1; i <= elements.Size(); i++)
    {
      HPRefElement & hpel = elements.Elem(i);
      if (Get_HPRef_Struct (hpel.type))
	switch (Get_HPRef_Struct (hpel.type) -> geom)
	{
	case HP_TRIG:
	  {
	    Element2d el(3);
	    el.PNum(1) = hpel.pnums[0];
	    el.PNum(2) = hpel.pnums[1];
	    el.PNum(3) = hpel.pnums[2];
	    el.SetIndex (hpel.index);
	    mesh.AddSurfaceElement (el);
	    break;
	  }
	case HP_QUAD:
	  {
	    Element2d el(4);
	    el.PNum(1) = hpel.pnums[0];
	    el.PNum(2) = hpel.pnums[1];
	    el.PNum(3) = hpel.pnums[2];
	    el.PNum(4) = hpel.pnums[3];
	    el.SetIndex (hpel.index);
	    mesh.AddSurfaceElement (el);
	    break;
	  }
	case HP_TET:
	  {
	    Element el(4);
	    el.PNum(1) = hpel.pnums[0];
	    el.PNum(2) = hpel.pnums[1];
	    el.PNum(3) = hpel.pnums[2];
	    el.PNum(4) = hpel.pnums[3];
	    el.SetIndex (hpel.index);
	    mesh.AddVolumeElement (el);
	    break;
	  }
	case HP_PRISM:
	  {
	    Element el(6);
	    el.PNum(1) = hpel.pnums[0];
	    el.PNum(2) = hpel.pnums[1];
	    el.PNum(3) = hpel.pnums[2];
	    el.PNum(4) = hpel.pnums[3];
	    el.PNum(5) = hpel.pnums[4];
	    el.PNum(6) = hpel.pnums[5];
	    el.SetIndex (hpel.index);
	    mesh.AddVolumeElement (el);
	    break;
	  }

	case HP_PYRAMID:
	  {
	    Element el(5);
	    el.PNum(1) = hpel.pnums[0];
	    el.PNum(2) = hpel.pnums[1];
	    el.PNum(3) = hpel.pnums[2];
	    el.PNum(4) = hpel.pnums[3];
	    el.PNum(5) = hpel.pnums[4];
	    el.SetIndex (hpel.index);
	    mesh.AddVolumeElement (el);
	    break;
	  }
	case HP_HEX:
	  {
	    Element el(8);
	    el.PNum(1) = hpel.pnums[0];
	    el.PNum(2) = hpel.pnums[1];
	    el.PNum(3) = hpel.pnums[2];
	    el.PNum(4) = hpel.pnums[3];
	    el.PNum(5) = hpel.pnums[4];
	    el.PNum(6) = hpel.pnums[5];
	    el.PNum(7) = hpel.pnums[6];
	    el.PNum(8) = hpel.pnums[7];
	    
	    (*testout) << "hex: " << endl;
	    for (int ii = 1;  ii <= 8; ii++)
	      (*testout) << hpel.pnums[ii-1] << " ";
	    (*testout) << endl;

	    el.SetIndex (hpel.index);
	    mesh.AddVolumeElement (el);
	    break;
	  }

	default:
	  PrintSysError ("hpref, backconversion failed for element ", 
			 int(Get_HPRef_Struct (hpel.type) -> geom));
	}
    }
  
  mesh.UpdateTopology();
}


}
