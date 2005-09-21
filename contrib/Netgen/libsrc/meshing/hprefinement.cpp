#include <mystdlib.h>
#include "meshing.hpp"




namespace netgen
{


  // HP_SEGM
  int refsegm_splitedges[][3] =
    {
      { 0, 0, 0 }
    };
  
  HPREF_ELEMENT_TYPE refsegm_newelstypes[] =
    {
      HP_SEGM,
      HP_NONE,
    };
  int refsegm_newels[][8] =
    {
      { 1, 2 },
    };
  HPRef_Struct refsegm =
    {
      HP_SEGM, 
      refsegm_splitedges, 
      0, 0, 
      refsegm_newelstypes, 
      refsegm_newels
    };


  // HP_SEGM_SINGCORNERL = 2,
  int refsegm_scl_splitedges[][3] =
    {
      { 1, 2, 3 },
      { 0, 0, 0 }
    };

  HPREF_ELEMENT_TYPE refsegm_scl_newelstypes[] =
    {
      HP_SEGM_SINGCORNERL,
      HP_SEGM,
      HP_NONE,
    };
  int refsegm_scl_newels[][8] =
    {
      { 1, 3 },
      { 3, 2 },
      { 0, 0 },
    };
  HPRef_Struct refsegm_scl =
    {
      HP_SEGM,
      refsegm_scl_splitedges,
      0, 0,
      refsegm_scl_newelstypes,
      refsegm_scl_newels
    };



  // HP_SEGM_SINGCORNERR
  int refsegm_scr_splitedges[][3] =
    {
      { 2, 1, 3 },
      { 0, 0, 0 }
    };

  HPREF_ELEMENT_TYPE refsegm_scr_newelstypes[] =
    {
      HP_SEGM,
      HP_SEGM_SINGCORNERR,
      HP_NONE,
    };
  int refsegm_scr_newels[][8] =
    {
      { 1, 3 },
      { 3, 2 },
      { 0, 0 },
    };
  HPRef_Struct refsegm_scr =
    {
      HP_SEGM,
      refsegm_scr_splitedges,
      0, 0,
      refsegm_scr_newelstypes,
      refsegm_scr_newels
    };






  // HP_SEGM_SINGCORNERS = 3,
  int refsegm_sc2_splitedges[][3] =
    {
      { 1, 2, 3 },
      { 2, 1, 4 },
      { 0, 0, 0 }
    };

  HPREF_ELEMENT_TYPE refsegm_sc2_newelstypes[] =
    {
      HP_SEGM_SINGCORNERL,
      HP_SEGM_SINGCORNERR,
      HP_SEGM,
      HP_NONE,
    };
  int refsegm_sc2_newels[][8] =
    {
      { 1, 3 },
      { 4, 2 },
      { 3, 4 },
      { 0, 0 },
    };
  HPRef_Struct refsegm_sc2 =
    {
      HP_SEGM,
      refsegm_sc2_splitedges,
      0, 0,
      refsegm_sc2_newelstypes,
      refsegm_sc2_newels
    };






#include "hpref_trig.hpp"
#include "hpref_quad.hpp"
#include "hpref_tet.hpp"
#include "hpref_prism.hpp"





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




  // HP_PYRAMID_1FB_0E_1VA
  int refpyramid_1fb_0e_1va_splitedges[][3] =
    {
      { 1, 4, 6 },
      { 2, 3, 7 },
      { 5, 1, 8 },
      { 5, 2, 9 },
      { 5, 3, 10 },
      { 5, 4, 11 },
      { 0, 0, 0 },
    };

  HPREF_ELEMENT_TYPE refpyramid_1fb_0e_1va_newelstypes[] =
    {
      HP_HEX_1F_0E_0V,
      HP_PYRAMID_1FB_0E_1VA,
      HP_PRISM,
      HP_NONE,
    };
  int refpyramid_1fb_0e_1va_newels[][8] =
    {
      { 1, 8, 9, 2, 6, 11, 10, 7 },
      { 8, 9, 10, 11, 5 },
      { 3, 7, 10, 4, 6, 11 }
    };
  HPRef_Struct refpyramid_1fb_0e_1va =
    {
      HP_PYRAMID,
      refpyramid_1fb_0e_1va_splitedges, 
      0, 0,
      refpyramid_1fb_0e_1va_newelstypes, 
      refpyramid_1fb_0e_1va_newels
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




  // HP_HEX_1E_1V
  int refhex_1e_1v_splitedges[][3] =
    {
      { 0, 0, 0 }
    };
  HPREF_ELEMENT_TYPE refhex_1e_1v_newelstypes[] =
    {
      HP_TET_1E_1VA,
      HP_TET,
      HP_TET_0E_1V,
      HP_TET_0E_1V,
      HP_TET_0E_1V,
      HP_TET_0E_1V,
      HP_NONE,
    };
  int refhex_1e_1v_newels[][8] =
    {
      // { 1, 5, 2, 4 }, 
      { 1, 2, 4, 5 },
      { 7, 3, 6, 8 },
      { 2, 8, 5, 6 },
      { 2, 8, 6, 3 },
      { 2, 8, 3, 4 },
      { 2, 8, 4, 5 },
    };
  HPRef_Struct refhex_1e_1v =
    {
      HP_HEX,
      refhex_1e_1v_splitedges, 
      0, 0,
      refhex_1e_1v_newelstypes, 
      refhex_1e_1v_newels
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





  // HP_HEX_1F_0E_0V
  int refhex_1f_0e_0v_splitedges[][3] =
    {
      { 1, 5, 9 },
      { 2, 6, 10 },
      { 3, 7, 11 },
      { 4, 8, 12 },
      { 0, 0, 0 }
    };

  HPREF_ELEMENT_TYPE refhex_1f_0e_0v_newelstypes[] =
    {
      HP_HEX_1F_0E_0V,
      HP_HEX,
      HP_NONE,
    };
  int refhex_1f_0e_0v_newels[][8] =
    {
      { 1, 2, 3, 4, 9, 10, 11, 12 },
      { 9, 10, 11, 12, 5, 6, 7, 8 }
    };
  HPRef_Struct refhex_1f_0e_0v =
    {
      HP_HEX,
      refhex_1f_0e_0v_splitedges, 
      0, 0,
      refhex_1f_0e_0v_newelstypes, 
      refhex_1f_0e_0v_newels
    };







  HPRef_Struct * Get_HPRef_Struct (HPREF_ELEMENT_TYPE type)
  {
    HPRef_Struct * hps = NULL;

    switch (type)
      {
      case HP_SEGM:
	hps = &refsegm; break;
      case HP_SEGM_SINGCORNERL:
	hps = &refsegm_scl; break;
      case HP_SEGM_SINGCORNERR:
	hps = &refsegm_scr; break;
      case HP_SEGM_SINGCORNERS:
	hps = &refsegm_sc2; break;

      case HP_TRIG:
	hps = &reftrig; break;
      case HP_TRIG_SINGCORNER:
	hps = &reftrig_singcorner; break;
      case HP_TRIG_SINGCORNER12:
	hps = &reftrig_singcorner12; break;
      case HP_TRIG_SINGCORNER123:
	hps = &reftrig_singcorner123; break;
      case HP_TRIG_SINGCORNER123_2D:
	hps = &reftrig_singcorner123_2D; break;
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

      case HP_QUAD_0E_2VA:
	hps = &refquad_0e_2va; break;
      case HP_QUAD_0E_2VB:
	hps = &refquad_0e_2vb; break;

      case HP_QUAD_0E_3V:
	hps = &refquad_0e_3v; break;
      case HP_QUAD_0E_4V:
	hps = &refquad_0e_4v; break;

      case HP_QUAD_1E_1VA:
	hps = &refquad_1e_1va; break;
      case HP_QUAD_1E_1VB:
	hps = &refquad_1e_1vb; break;
      case HP_QUAD_1E_1VC:
	hps = &refquad_1e_1vc; break;
      case HP_QUAD_1E_1VD:
	hps = &refquad_1e_1vd; break;

      case HP_QUAD_1E_2VA:
	hps = &refquad_1e_2va; break;
      case HP_QUAD_1E_2VB:
	hps = &refquad_1e_2vb; break;
      case HP_QUAD_1E_2VC:
	hps = &refquad_1e_2vc; break;
      case HP_QUAD_1E_2VD:
	hps = &refquad_1e_2vd; break;
      case HP_QUAD_1E_2VE:
	hps = &refquad_1e_2ve; break;
      case HP_QUAD_1E_2VF:
	hps = &refquad_1e_2vf; break;

      case HP_QUAD_1E_3VA:
	hps = &refquad_1e_3va; break;
      case HP_QUAD_1E_3VB:
	hps = &refquad_1e_3vb; break;
      case HP_QUAD_1E_3VC:
	hps = &refquad_1e_3vc; break;
      case HP_QUAD_1E_3VD:
	hps = &refquad_1e_3vd; break;
      case HP_QUAD_1E_4V:
	hps = &refquad_1e_4v; break;


      case HP_QUAD_2E:
	hps = &refquad_2e; break;
      case HP_QUAD_2E_1VA:
	hps = &refquad_2e_1va; break;
      case HP_QUAD_2E_1VB:
	hps = &refquad_2e_1vb; break;
      case HP_QUAD_2E_1VC:
	hps = &refquad_2e_1vc; break;
      case HP_QUAD_2E_2VA:
	hps = &refquad_2e_2va; break;
      case HP_QUAD_2E_2VB:
	hps = &refquad_2e_2vb; break;
      case HP_QUAD_2E_2VC:
	hps = &refquad_2e_2vc; break;
      case HP_QUAD_2E_3V:
	hps = &refquad_2e_3v; break;

      case HP_QUAD_2EB_0V:
	hps = &refquad_2eb_0v; break;

      case HP_QUAD_2EB_1VA:
	hps = &refquad_2eb_1va; break;
      case HP_QUAD_2EB_1VB:
	hps = &refquad_2eb_1vb; break;


      case HP_QUAD_2EB_2VA:
	hps = &refquad_2eb_2va; break;
      case HP_QUAD_2EB_2VB:
	hps = &refquad_2eb_2vb; break;
      case HP_QUAD_2EB_2VC:
	hps = &refquad_2eb_2vc; break;
      case HP_QUAD_2EB_2VD:
	hps = &refquad_2eb_2vd; break;

      case HP_QUAD_2EB_3VA:
	hps = &refquad_2eb_3va; break;
      case HP_QUAD_2EB_3VB:
	hps = &refquad_2eb_3vb; break;

      case HP_QUAD_2EB_4V:
	hps = &refquad_2eb_4v; break;

      case HP_QUAD_3E:
	hps = &refquad_3e; break;
      case HP_QUAD_3E_3VA:
	hps = &refquad_3e_3va; break;
      case HP_QUAD_3E_3VB:
	hps = &refquad_3e_3vb; break;
      case HP_QUAD_3E_4V:
	hps = &refquad_3e_4v; break;


      case HP_QUAD_4E:
	hps = &refquad_4e; break;


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

      case HP_TET_1E_3VA:
	hps = &reftet_1e_3va; break;
      case HP_TET_1E_3VB:
	hps = &reftet_1e_3vb; break;
      case HP_TET_1E_4V:
	hps = &reftet_1e_4v; break;

      case HP_TET_2EA_0V:
	hps = &reftet_2ea_0v; break;
      case HP_TET_2EA_1VB:
	hps = &reftet_2ea_1vb; break;
      case HP_TET_2EA_1VC:
	hps = &reftet_2ea_1vc; break;
      case HP_TET_2EA_1VA:
	hps = &reftet_2ea_1va; break;
      case HP_TET_2EA_2VA:
	hps = &reftet_2ea_2va; break;
      case HP_TET_2EA_2VB:
	hps = &reftet_2ea_2vb; break;
      case HP_TET_2EA_2VC:
	hps = &reftet_2ea_2vc; break;
      case HP_TET_2EA_3V:
	hps = &reftet_2ea_3v; break;

      case HP_TET_2EB_0V:
	hps = &reftet_2eb_0v; break;
      case HP_TET_2EB_2VA:
	hps = &reftet_2eb_2va; break;
      case HP_TET_2EB_4V:
	hps = &reftet_2eb_4v; break;


      case HP_TET_3EA_0V:
	hps = &reftet_3ea_0v; break;
      case HP_TET_3EA_1V:
	hps = &reftet_3ea_1v; break;
      case HP_TET_3EA_2V:
	hps = &reftet_3ea_2v; break;
      case HP_TET_3EA_3V:
	hps = &reftet_3ea_3v; break;

      case HP_TET_3EB_0V:
	hps = &reftet_3eb_0v; break;
      case HP_TET_3EB_1V:
	hps = &reftet_3eb_1v; break;
      case HP_TET_3EB_2V:
	hps = &reftet_3eb_2v; break;
      case HP_TET_3EC_0V:
	hps = &reftet_3ec_0v; break;
      case HP_TET_3EC_1V:
	hps = &reftet_3ec_1v; break;
      case HP_TET_3EC_2V:
	hps = &reftet_3ec_2v; break;


      case HP_TET_1F_0E_0V:
	hps = &reftet_1f_0e_0v; break;
      case HP_TET_1F_0E_1VA:
	hps = &reftet_1f_0e_1va; break;
      case HP_TET_1F_0E_1VB:
	hps = &reftet_1f_0e_1vb; break;
      case HP_TET_1F_1EA_0V:
	hps = &reftet_1f_1ea_0v; break;
      case HP_TET_1F_1EB_0V:
	hps = &reftet_1f_1eb_0v; break;
      case HP_TET_2F_0E_0V:
	hps = &reftet_2f_0e_0v; break;


      case HP_PRISM:
	hps = &refprism; break;
      case HP_PRISM_SINGEDGE:
	hps = &refprism_singedge; break;
      case HP_PRISM_SINGEDGE_H1:
	hps = &refprism_singedge_h1; break;
      case HP_PRISM_SINGEDGE_H12:
	hps = &refprism_singedge_h12; break;
      case HP_PRISM_SINGEDGE_V12:
	hps = &refprism_singedge_v12; break;

      case HP_PRISM_1FA_0E_0V:
	hps = &refprism_1fa_0e_0v; break;
      case HP_PRISM_1FB_0E_0V:
	hps = &refprism_1fb_0e_0v; break;
      case HP_PRISM_1FB_1EA_0V:
	hps = &refprism_1fb_1ea_0v; break;

      case HP_PYRAMID:
	hps = &refpyramid; break;
      case HP_PYRAMID_0E_1V:
	hps = &refpyramid_0e_1v; break;
      case HP_PYRAMID_EDGES:
	hps = &refpyramid_edges; break;
      case HP_PYRAMID_1FB_0E_1VA:
	hps = &refpyramid_1fb_0e_1va; break;
      case HP_HEX:
	hps = &refhex; break;
      case HP_HEX_0E_1V:
	hps = &refhex_0e_1v; break;
      case HP_HEX_1E_1V:
	hps = &refhex_1e_1v; break;
      case HP_HEX_1E_0V:
	hps = &refhex_1e_0v; break;
      case HP_HEX_3E_0V:
	hps = &refhex_3e_0v; break;

      case HP_HEX_1F_0E_0V:
	hps = &refhex_1f_0e_0v; break;
      }

    if (!hps)
      {
	PrintSysError ("hp-refinement not implemented for case ", type);
      }

    return hps;
  }


  /* *********************** PrepareElements ****************************** */
  
  // Elements (volume, surface, edges)  are classified by singular vertices, edges, faces


  void PrepareElements (Mesh & mesh, ARRAY<HPRefElement> & elements)
  {
    INDEX_2_HASHTABLE<int> edges(mesh.GetNSeg()+1);
    BitArray edgepoint(mesh.GetNP());
    INDEX_2_HASHTABLE<int> edgepoint_dom(mesh.GetNSeg()+1);

    edgepoint.Clear();
    BitArray cornerpoint(mesh.GetNP());
    cornerpoint.Clear();


    // value = nr > 0 ... refine elements in domain nr
    // value = -1   ..... refine elements in any domain
    INDEX_3_HASHTABLE<int> faces(mesh.GetNSE()+1);
    INDEX_2_HASHTABLE<int> face_edges(mesh.GetNSE()+1);
    ARRAY<int, PointIndex::BASE> facepoint(mesh.GetNP());

    if (mesh.GetDimension() == 3)
      {
	/*
	// check, if point has as least 3 different surfs:

	ARRAY<INDEX_3, PointIndex::BASE> surfonpoint(mesh.GetNP());
	surfonpoint = INDEX_3(0,0,0);

	for (SurfaceElementIndex sei = 0; sei < mesh.GetNSE(); sei++)
	  {
	    const Element2d & el = mesh[sei];
	    int ind = el.GetIndex();
	    for (int j = 0; j < el.GetNP(); j++)
	      {
		INDEX_3 & i3 = surfonpoint[el[j]];
		if (ind != i3.I1() && ind != i3.I2() && ind != i3.I3())
		  {
		    i3.I1() = i3.I2();
		    i3.I2() = i3.I3();
		    i3.I3() = ind;
		  }
	      }
	  }
	for (int i = 1; i <= mesh.GetNP(); i++)
	  if (surfonpoint.Get(i).I1())
	    cornerpoint.Set(i);
	*/
	cornerpoint.Clear();

	for (int i = 1; i <= mesh.GetNP(); i++)
	  {
	    if (mesh.Point(i).IsSingular())
	      cornerpoint.Set(i);
	  }


	for (int i = 1; i <= mesh.GetNSeg(); i++)
	  if (mesh.LineSegment(i).singedge_left)
	    {
	      INDEX_2 i2 (mesh.LineSegment(i).p1, 
			  mesh.LineSegment(i).p2);
	      i2.Sort();
	      
	      edges.Set (i2, 1);
	      INDEX_2 i2s(i2.I2(), i2.I1());
	      edges.Set (i2s, 1);
	      
	      edgepoint.Set (i2.I1());
	      edgepoint.Set (i2.I2());
	    }


	// if 2 adjacent edges of an element are singular, the 
	// commen point must be a singular point
	for (int i = 1; i <= mesh.GetNE(); i++)
	  {
	    const Element & el = mesh.VolumeElement(i);
	    const ELEMENT_EDGE * eledges = MeshTopology::GetEdges (el.GetType());
	    int nedges = MeshTopology::GetNEdges (el.GetType());
	    for (int j = 0; j < nedges; j++)
	      for (int k = 0; k < nedges; k++)
		if (j != k)
		  {
		    INDEX_2 ej(el.PNum(eledges[j][0]), el.PNum(eledges[j][1]));
		    ej.Sort();
		    INDEX_2 ek(el.PNum(eledges[k][0]), el.PNum(eledges[k][1]));
		    ek.Sort();
		    if (edges.Used(ej) && edges.Used(ek))
		      {
			if (ej.I1() == ek.I1()) cornerpoint.Set (ek.I1());
			if (ej.I1() == ek.I2()) cornerpoint.Set (ek.I2());
			if (ej.I2() == ek.I1()) cornerpoint.Set (ek.I1());
			if (ej.I2() == ek.I2()) cornerpoint.Set (ek.I2());
		      }
		  }
	  }

	
	edgepoint.Or (cornerpoint);
	
	(*testout) << "cornerpoint = " << endl << cornerpoint << endl;
	(*testout) << "edgepoint = " << endl << edgepoint << endl;

	facepoint = 0;
	for (SurfaceElementIndex sei = 0; sei < mesh.GetNSE(); sei++)
	  {
	    const Element2d & el = mesh[sei];
	    const FaceDescriptor & fd = mesh.GetFaceDescriptor (el.GetIndex());

	    if (!fd.domin_singular && !fd.domout_singular) continue;
	    int domnr;
	    if (fd.domin_singular) domnr = fd.DomainIn();
	    if (fd.domout_singular) domnr = fd.DomainOut();
	    if (fd.domin_singular && fd.domout_singular) domnr = -1;
	    

	    faces.Set (INDEX_3::Sort (el[0], el[1], el[2]), domnr);
	    face_edges.Set (INDEX_2::Sort (el[0], el[1]), domnr);
	    face_edges.Set (INDEX_2::Sort (el[0], el[2]), domnr);
	    face_edges.Set (INDEX_2::Sort (el[2], el[1]), domnr);
	    facepoint[el[0]] = domnr;
	    facepoint[el[1]] = domnr;
	    facepoint[el[2]] = domnr;
	  }
	
      }
    else
      {
	// 2D case

	// check, if point has as least 3 different surfs:
	ARRAY<INDEX_3, PointIndex::BASE> surfonpoint(mesh.GetNP());

	for (int i = 1; i <= mesh.GetNP(); i++)
	  surfonpoint.Elem(i) = INDEX_3(0,0,0);
      
	for (int i = 1; i <= mesh.GetNSeg(); i++)
	  {
	    const Segment & seg = mesh.LineSegment(i);
	    int ind = seg.edgenr;

	    if (seg.singedge_left)
	      {
		INDEX_2 i2 (mesh.LineSegment(i).p1, 
			    mesh.LineSegment(i).p2);
		edges.Set (i2, 1);
		edgepoint.Set(i2.I1());
		edgepoint.Set(i2.I2());
	      
		edgepoint_dom.Set (INDEX_2(mesh.LineSegment(i).domin, i2.I1()), 1);
		edgepoint_dom.Set (INDEX_2(mesh.LineSegment(i).domin, i2.I2()), 1);
	      }
	    if (seg.singedge_right)
	      {
		INDEX_2 i2 (mesh.LineSegment(i).p2, 
			    mesh.LineSegment(i).p1);
		edges.Set (i2, 1);
		edgepoint.Set(i2.I1());
		edgepoint.Set(i2.I2());

		edgepoint_dom.Set (INDEX_2(mesh.LineSegment(i).domout, i2.I1()), 1);
		edgepoint_dom.Set (INDEX_2(mesh.LineSegment(i).domout, i2.I2()), 1);
	      }
	    // (*testout) << "seg = " << ind << ", " << seg.p1 << "-" << seg.p2 << endl;


	    if (seg.singedge_left || seg.singedge_right)
	      {
		for (int j = 0; j < 2; j++)
		  {
		    int pi = (j == 0) ? seg.p1 : seg.p2;
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


	for (int i = 1; i <= mesh.GetNP(); i++)
	  {
	    // mark points for refinement that are in corners between two anisotropic edges 
	    if (surfonpoint.Get(i).I1())
	      {
		cornerpoint.Set(i);
		edgepoint.Set(i);
	      }
	
	    // mark points for refinement that are explicity specified in input file
	    if (mesh.Point(i).IsSingular())
	      {
		cornerpoint.Set(i);
		edgepoint.Set(i);
	      }
	  }

	edgepoint.Or (cornerpoint);

	(*testout) << "cornerpoints: " << endl << cornerpoint << endl
		   << "edgepoints: " << endl << edgepoint << endl;
      }




    int cnt_undef = 0, cnt_nonimplement = 0;
    ARRAY<int> misses(10000);
    misses = 0;

    for (ElementIndex i = 0; i < mesh.GetNE(); i++)
      {
	Element & el = mesh[i];
      
	HPREF_ELEMENT_TYPE type = HP_NONE;
	int pnums[8] = { 0 };
      
      
	switch (el.GetType())
	  {
	  case TET:
	    {
	      int ep1, ep2, ep3, ep4, cp1, cp2, cp3, cp4, fp1, fp2, fp3, fp4;
	      int isedge1, isedge2, isedge3, isedge4, isedge5, isedge6;
	      int isfedge1, isfedge2, isfedge3, isfedge4, isfedge5, isfedge6;
	      int isface1, isface2, isface3, isface4;

	      for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
		  {
		    if (j == k) continue;
		    if (type) break;
	    
		    int pi3 = 0;
		    while (pi3 == j || pi3 == k) pi3++;
		    int pi4 = 6 - j - k - pi3;

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

		    ep1 = edgepoint.Test (el[j]);
		    ep2 = edgepoint.Test (el[k]);
		    ep3 = edgepoint.Test (el[pi3]);
		    ep4 = edgepoint.Test (el[pi4]);

		    cp1 = cornerpoint.Test (el[j]);
		    cp2 = cornerpoint.Test (el[k]);
		    cp3 = cornerpoint.Test (el[pi3]);
		    cp4 = cornerpoint.Test (el[pi4]);
	    
		    isedge1 = edges.Used (INDEX_2::Sort (el[j], el[k]));
		    isedge2 = edges.Used (INDEX_2::Sort (el[j], el[pi3]));
		    isedge3 = edges.Used (INDEX_2::Sort (el[j], el[pi4]));
		    isedge4 = edges.Used (INDEX_2::Sort (el[k], el[pi3]));
		    isedge5 = edges.Used (INDEX_2::Sort (el[k], el[pi4]));
		    isedge6 = edges.Used (INDEX_2::Sort (el[pi3], el[pi4]));

		    isface1 = isface2 = isface3 = isface4 = 0;
		    for (int l = 0; l < 4; l++)
		      {
			INDEX_3 i3;
			switch (l)
			  {
			  case 0: i3 = INDEX_3 (el[k], el[pi3], el[pi4]); break;
			  case 1: i3 = INDEX_3 (el[j], el[pi3], el[pi4]); break;
			  case 2: i3 = INDEX_3 (el[j], el[k], el[pi4]); break;
			  case 3: i3 = INDEX_3 (el[j], el[k], el[pi3]); break;
			  }
			i3.Sort();
			if (faces.Used (i3))
			  {
			    int domnr = faces.Get(i3);
			    if (domnr == -1 || domnr == el.GetIndex())
			      {
				switch (l)
				  {
				  case 0: isface1 = 1; break;
				  case 1: isface2 = 1; break;
				  case 2: isface3 = 1; break;
				  case 3: isface4 = 1; break;
				  }
			      }
			  }
		      }
		    /*
		    isface1 = faces.Used (INDEX_3::Sort (el[k], el[pi3], el[pi4]));
		    isface2 = faces.Used (INDEX_3::Sort (el[j], el[pi3], el[pi4]));
		    isface3 = faces.Used (INDEX_3::Sort (el[j], el[k], el[pi4]));
		    isface4 = faces.Used (INDEX_3::Sort (el[j], el[k], el[pi3]));
		    */

		    isfedge1 = isfedge2 = isfedge3 = isfedge4 = isfedge5 = isfedge6 = 0;
		    for (int l = 0; l < 6; l++)
		      {
			INDEX_2 i2;
			switch (l)
			  {
			  case 0: i2 = INDEX_2 (el[j], el[k]); break;
			  case 1: i2 = INDEX_2 (el[j], el[pi3]); break;
			  case 2: i2 = INDEX_2 (el[j], el[pi4]); break;
			  case 3: i2 = INDEX_2 (el[k], el[pi3]); break;
			  case 4: i2 = INDEX_2 (el[k], el[pi4]); break;
			  case 5: i2 = INDEX_2 (el[pi3], el[pi4]); break;
			  }
			i2.Sort();
			if (face_edges.Used (i2))
			  {
			    int domnr = face_edges.Get(i2);
			    if (domnr == -1 || domnr == el.GetIndex())
			      {
				switch (l)
				  {
				  case 0: isfedge1 = 1; break;
				  case 1: isfedge2 = 1; break;
				  case 2: isfedge3 = 1; break;
				  case 3: isfedge4 = 1; break;
				  case 4: isfedge5 = 1; break;
				  case 5: isfedge6 = 1; break;
				  }
			      }
			  }
		      }
		    /*
		    isfedge1 = face_edges.Used (INDEX_2::Sort (el[j], el[k]));
		    isfedge2 = face_edges.Used (INDEX_2::Sort (el[j], el[pi3]));
		    isfedge3 = face_edges.Used (INDEX_2::Sort (el[j], el[pi4]));
		    isfedge4 = face_edges.Used (INDEX_2::Sort (el[k], el[pi3]));
		    isfedge5 = face_edges.Used (INDEX_2::Sort (el[k], el[pi4]));
		    isfedge6 = face_edges.Used (INDEX_2::Sort (el[pi3], el[pi4]));
		    */

		    fp1 = fp2 = fp3 = fp4 = 0;
		    for (int l = 0; l < 4; l++)
		      {
			int pi;
			switch (l)
			  {
			  case 0: pi = el[j]; break;
			  case 1: pi = el[k]; break;
			  case 2: pi = el[pi3]; break;
			  case 3: pi = el[pi4]; break;
			  }
			int domnr = facepoint[pi];
			if (domnr == -1 || domnr == el.GetIndex())
			  {
			    switch (l)
			      {
			      case 0: fp1 = 1; break;
			      case 1: fp2 = 1; break;
			      case 2: fp3 = 1; break;
			      case 3: fp4 = 1; break;
			      }
			  }
		      }

		    /*
		    fp1 = facepoint[el[j]] != 0;
		    fp2 = facepoint[el[k]] != 0;
		    fp3 = facepoint[el[pi3]] != 0;
		    fp4 = facepoint[el[pi4]] != 0;
		    */


		    switch (isface1+isface2+isface3+isface4)
		      {
		      case 0:
			{
			  isedge1 |= isfedge1;
			  isedge2 |= isfedge2;
			  isedge3 |= isfedge3;
			  isedge4 |= isfedge4;
			  isedge5 |= isfedge5;
			  isedge6 |= isfedge6;

			  ep1 |= fp1;
			  ep2 |= fp2;
			  ep3 |= fp3;
			  ep4 |= fp4;

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
				    if (cp2 && !cp3 && !cp4)
				      type = HP_TET_3EA_1V;
				    if (cp2 && cp3 && !cp4)
				      type = HP_TET_3EA_2V;
				    if (cp2 && cp3 && cp4)
				      type = HP_TET_3EA_3V;
				  }
				if (isedge1 && isedge3 && isedge4)
				  {
				    if (!cp3 && !cp4)
				      type = HP_TET_3EB_0V;
				    if (cp3 && !cp4)
				      type = HP_TET_3EB_1V;
				    if (cp3 && cp4)
				      type = HP_TET_3EB_2V;
				  }
				if (isedge1 && isedge2 && isedge5)
				  {
				    if (!cp3 && !cp4)
				      type = HP_TET_3EC_0V;
				    if (cp3 && !cp4)
				      type = HP_TET_3EC_1V;
				    if (cp3 && cp4)
				      type = HP_TET_3EC_2V;
				  }
				break;
			      }
			    }
			  break;
			}



		      case 1:  // one singular face
			{
			  if (!isface1) break;

			  switch (isfedge1+isfedge2+isfedge3+isedge4+isedge5+isedge6)
			    {
			    case 0:
			      {
				if (!fp1 && !ep2 && !ep3 && !ep4)
				  type = HP_TET_1F_0E_0V;
				if (fp1 && !ep2 && !ep3 && !ep4)
				  type = HP_TET_1F_0E_1VB;
				if (!fp1 && ep2 && !ep3 & !ep4)
				  type = HP_TET_1F_0E_1VA;
				break;
			      }
			    case 1:
			      {
				if (isfedge1)
				  {
				    if (!ep1 && !ep3 && !ep4)
				      type = HP_TET_1F_1EA_0V;
				  }
				if (isedge4) // V1-V3
				  {
				    if (!ep1 && !cp2 && !cp3 && !ep4)
				      type = HP_TET_1F_1EB_0V;
				  }
				break;
			      }
			    }
			  break;
			}


		      case 2:  // one singular face
			{
			  if (!isface1 || !isface2) break;

			  switch (isfedge1+isedge2+isedge3+isedge4+isedge5)
			    {
			    case 0:
			      {
				if (!ep1 && !ep2 && !cp3 && !cp4)
				  type = HP_TET_2F_0E_0V;
				break;
			      }
			    }
			  break;
			}


		      }

		    if (type != HP_NONE)
		      {
			pnums[0] = el[j];
			pnums[1] = el[k];
			pnums[2] = el[pi3];
			pnums[3] = el[pi4];
			break;
		      }
		  }

	      /*
		if (type != HP_TET_2EB_2VA)
		type = HP_NONE;
	      */

	      if (type == HP_NONE)
		{
		  cnt_undef++;
		  (*testout) << "undefined element" << endl
			     << "cp = " << cp1 << cp2 << cp3 << cp4 << endl
			     << "ep = " << ep1 << ep2 << ep3 << ep4 << endl
			     << "isedge = " << isedge1 << isedge2 << isedge3 
			     << isedge4 << isedge5 << isedge6 << endl;
		  cout << "undefined element !!! " << endl;
		}

	      break;
	    }

	  case PRISM:
	    {
	      int pi1, pi2, pi3, pi4, pi5, pi6;
	      int ep1, ep2, ep3, ep4, ep5, ep6, cp1, cp2, cp3, cp4, cp5, cp6;

	      int ishedge1, ishedge2, ishedge3, ishedge4, ishedge5, ishedge6;
	      int isvedge1, isvedge2, isvedge3;
	    
	      for (int j = 1; j <= 3; j++)
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
	    
		  INDEX_2 i2 = INDEX_2::Sort(el.PNum (pi1), el.PNum (pi4));
		  isvedge1 = edges.Used (i2) || ep1 || ep4;

		  i2 = INDEX_2::Sort(el.PNum (pi2), el.PNum (pi5));
		  isvedge2 = edges.Used (i2) || ep2 || ep5;

		  i2 = INDEX_2::Sort(el.PNum (pi3), el.PNum (pi6));
		  isvedge3 = edges.Used (i2) || ep3 || ep6;


		  ishedge1 = edges.Used (INDEX_2::Sort(el.PNum (pi1), el.PNum (pi2)));
		  ishedge2 = edges.Used (INDEX_2::Sort(el.PNum (pi2), el.PNum (pi3)));
		  ishedge3 = edges.Used (INDEX_2::Sort(el.PNum (pi3), el.PNum (pi1)));



		  switch (ishedge1 + ishedge2 + ishedge3)
		    {
		    case 0:
		      {
			if (!isvedge1 && !isvedge2 && !isvedge3)
			  type = HP_PRISM;
			else if (isvedge1 && !isvedge2 && !isvedge3)
			  type = HP_PRISM_SINGEDGE;
			else if (isvedge1 && isvedge2 && !isvedge3)
			  type = HP_PRISM_SINGEDGE_V12;
			break;
		      }
		    case 1:
		      {
			if (ishedge1)
			  type = HP_PRISM_SINGEDGE_H1;
			break;
		      }
		    case 2:
		      {
			if (ishedge1 && ishedge2)
			  type = HP_PRISM_SINGEDGE_H12;
			break;
		      }
		    }

		  if (type != HP_NONE)
		    {
		      cout << "classified element, type = " << type << ", el = "  << el << endl;
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


	if (type == HP_NONE)
	  {
	    cout << "element is HP_NONE: " << el << endl;
	  }

	if (!Get_HPRef_Struct (type)) 
	  {
	    (*testout) << "case " << type << " not implemented " << endl;
	    cnt_nonimplement++;
	    misses[type]++;
	  }
      
	HPRefElement hpel;
	hpel.type = type;
	for (int j = 0; j < 8; j++)
	  hpel.pnums[j] = pnums[j];
	hpel.index = el.GetIndex();
	hpel.level = 1;
	hpel.coarse_elnr = i;

	static const double points[4][3] = 
	  { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 } };
	for (int j = 0; j < 4; j++)
	  for (int k = 0; k < 4; k++)
	    if (pnums[j] == el[k])
	      {
		hpel.param[j][0] = points[k][0];
		hpel.param[j][1] = points[k][1];
		hpel.param[j][2] = points[k][2];
	      }

	elements.Append (hpel);
      }

    cout << "undefined elements: " << cnt_undef << endl;
    cout << "non-implemented: " << cnt_nonimplement << endl;

    for (int i = 0; i < misses.Size(); i++)
      if (misses[i])
	cout << "missing case " << i << " occured " << misses[i] << " times" << endl;

    for (int i = 1; i <= mesh.GetNSE(); i++)
      {
	int j, k, pi3, pi4;
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
		
		  if (mesh.GetDimension() == 2)
		    {
		      ep1 = edgepoint_dom.Used (INDEX_2 (mesh.SurfaceElement(i).GetIndex(), el.PNumMod(j)));
		      ep2 = edgepoint_dom.Used (INDEX_2 (mesh.SurfaceElement(i).GetIndex(), el.PNumMod(j+1)));
		      ep3 = edgepoint_dom.Used (INDEX_2 (mesh.SurfaceElement(i).GetIndex(), el.PNumMod(j+2)));
		    }

		  int cp1 = cornerpoint.Test (el.PNumMod (j));
		  int cp2 = cornerpoint.Test (el.PNumMod (j+1));
		  int cp3 = cornerpoint.Test (el.PNumMod (j+2));

		  ep1 |= cp1;
		  ep2 |= cp2;
		  ep3 |= cp3;
		
		  INDEX_2 i2;
		  i2 = INDEX_2(el.PNumMod (j), el.PNumMod (j+1));
		  // i2.Sort();
		  int isedge1 = edges.Used (i2);
		  i2 = INDEX_2(el.PNumMod (j+1), el.PNumMod (j+2));
		  // i2.Sort();
		  int isedge2 = edges.Used (i2);
		  i2 = INDEX_2(el.PNumMod (j+2), el.PNumMod (j+3));
		  // i2.Sort();
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
			{
			  if (mesh.GetDimension() == 2)
			    type = HP_TRIG_SINGCORNER123_2D;
			  else
			    type = HP_TRIG_SINGCORNER123;
			}
		    
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
	      int ep1, ep2, ep3, ep4, cp1, cp2, cp3, cp4;
	      int isedge1, isedge2, isedge3, isedge4;

	      for (j = 1; j <= 4; j++)
		{
		  ep1 = edgepoint.Test (el.PNumMod (j));
		  ep2 = edgepoint.Test (el.PNumMod (j+1));
		  ep3 = edgepoint.Test (el.PNumMod (j+2));
		  ep4 = edgepoint.Test (el.PNumMod (j+3));

		  if (mesh.GetDimension() == 2)
		    {
		      ep1 = edgepoint_dom.Used (INDEX_2 (mesh.SurfaceElement(i).GetIndex(), el.PNumMod(j)));
		      ep2 = edgepoint_dom.Used (INDEX_2 (mesh.SurfaceElement(i).GetIndex(), el.PNumMod(j+1)));
		      ep3 = edgepoint_dom.Used (INDEX_2 (mesh.SurfaceElement(i).GetIndex(), el.PNumMod(j+2)));
		      ep4 = edgepoint_dom.Used (INDEX_2 (mesh.SurfaceElement(i).GetIndex(), el.PNumMod(j+3)));
		    }

		  cp1 = cornerpoint.Test (el.PNumMod (j));
		  cp2 = cornerpoint.Test (el.PNumMod (j+1));
		  cp3 = cornerpoint.Test (el.PNumMod (j+2));
		  cp4 = cornerpoint.Test (el.PNumMod (j+3));

		  ep1 |= cp1;
		  ep2 |= cp2;
		  ep3 |= cp3;
		  ep4 |= cp4;
		

		  INDEX_2 i2;
		  i2 = INDEX_2(el.PNumMod (j), el.PNumMod (j+1));
		  // i2.Sort();
		  isedge1 = edges.Used (i2);
		  i2 = INDEX_2(el.PNumMod (j+1), el.PNumMod (j+2));
		  // i2.Sort();
		  isedge2 = edges.Used (i2);
		  i2 = INDEX_2(el.PNumMod (j+2), el.PNumMod (j+3));
		  // i2.Sort();
		  isedge3 = edges.Used (i2);
		  i2 = INDEX_2(el.PNumMod (j+3), el.PNumMod (j+4));
		  // i2.Sort();
		  isedge4 = edges.Used (i2);
		
		  int sumcp = cp1 + cp2 + cp3 + cp4;
		  int sumep = ep1 + ep2 + ep3 + ep4;
		  int sumedge = isedge1 + isedge2 + isedge3 + isedge4;

		  switch (sumedge)
		    {
		    case 0:
		      {
			switch (sumep)
			  {
			  case 0: 
			    type = HP_QUAD; 
			    break;
			  case 1: 
			    if (ep1) type = HP_QUAD_SINGCORNER;
			    break; 
			  case 2:
			    {
			      if (ep1 && ep2) type = HP_QUAD_0E_2VA;
			      if (ep1 && ep3) type = HP_QUAD_0E_2VB;
			      break;
			    }
			  case 3: 
			    if (!ep4) type = HP_QUAD_0E_3V; 
			    break; 
			  case 4: 
			    type = HP_QUAD_0E_4V; 
			    break; 
			  }
			break;
		      }
		    case 1:
		      {
			if (isedge1)
			  {
			    switch (cp1+cp2+ep3+ep4)
			      {
			      case 0: 
				type = HP_QUAD_SINGEDGE; 
				break;
			      case 1:
				{
				  if (cp1) type = HP_QUAD_1E_1VA;
				  if (cp2) type = HP_QUAD_1E_1VB;
				  if (ep3) type = HP_QUAD_1E_1VC;
				  if (ep4) type = HP_QUAD_1E_1VD; 
				  break; 
				}
			      case 2:
				{
				  if (cp1 && cp2) type = HP_QUAD_1E_2VA; 
				  if (cp1 && ep3) type = HP_QUAD_1E_2VB; 
				  if (cp1 && ep4) type = HP_QUAD_1E_2VC; 
				  if (cp2 && ep3) type = HP_QUAD_1E_2VD; 
				  if (cp2 && ep4) type = HP_QUAD_1E_2VE; 
				  if (ep3 && ep4) type = HP_QUAD_1E_2VF; 
				  break; 
				}
			      case 3:
				{
				  if (cp1 && cp2 && ep3) type = HP_QUAD_1E_3VA;
				  if (cp1 && cp2 && ep4) type = HP_QUAD_1E_3VB;
				  if (cp1 && ep3 && ep4) type = HP_QUAD_1E_3VC;
				  if (cp2 && ep3 && ep4) type = HP_QUAD_1E_3VD;
				  break;
				}
			      case 4:
				{
				  type = HP_QUAD_1E_4V; 
				  break;
				}
			      }
			  }
			break;
		      }
		    case 2:
		      {
			if (isedge1 && isedge4)
			  {
			    if (!cp2 && !ep3 && !cp4)
			      type = HP_QUAD_2E;
			  
			    if (cp2 && !ep3 && !cp4)
			      type = HP_QUAD_2E_1VA;
			    if (!cp2 && ep3 && !cp4)
			      type = HP_QUAD_2E_1VB;
			    if (!cp2 && !ep3 && cp4)
			      type = HP_QUAD_2E_1VC;

			    if (cp2 && ep3 && !cp4)
			      type = HP_QUAD_2E_2VA;
			    if (cp2 && !ep3 && cp4)
			      type = HP_QUAD_2E_2VB;
			    if (!cp2 && ep3 && cp4)
			      type = HP_QUAD_2E_2VC;

			    if (cp2 && ep3 && cp4)
			      type = HP_QUAD_2E_3V;
			  }
			if (isedge1 && isedge3)
			  {
			    switch (sumcp)
			      {
			      case 0: 
				type = HP_QUAD_2EB_0V; break;
			      case 1:
				{
				  if (cp1) type = HP_QUAD_2EB_1VA; 
				  if (cp2) type = HP_QUAD_2EB_1VB; 
				  break;
				}
			      case 2:
				{
				  if (cp1 && cp2) { type = HP_QUAD_2EB_2VA; }
				  if (cp1 && cp3) { type = HP_QUAD_2EB_2VB; }
				  if (cp1 && cp4) { type = HP_QUAD_2EB_2VC; }
				  if (cp2 && cp4) { type = HP_QUAD_2EB_2VD; }
				  break;
				}
			      case 3:
				{
				  if (cp1 && cp2 && cp3) { type = HP_QUAD_2EB_3VA; }
				  if (cp1 && cp2 && cp4) { type = HP_QUAD_2EB_3VB; }
				  break;
				}
			      case 4:
				{
				  type = HP_QUAD_2EB_4V; break;
				}
			      }
			  }
			break;
		      }

		    case 3:
		      {
			if (isedge1 && isedge2 && isedge4)
			  {
			    if (!cp3 && !cp4) type = HP_QUAD_3E;
			    if (cp3 && !cp4) type = HP_QUAD_3E_3VA;
			    if (!cp3 && cp4) type = HP_QUAD_3E_3VB;
			    if (cp3 && cp4) type = HP_QUAD_3E_4V;
			  }
			break;
		      }

		    case 4:
		      {
			type = HP_QUAD_4E;
			break;
		      }
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
	      if (type == HP_NONE)
		{
		  (*testout) << "undefined element" << endl
			     << "cp = " << cp1 << cp2 << cp3 << cp4 << endl
			     << "ep = " << ep1 << ep2 << ep3 << ep4 << endl
			     << "isedge = " << isedge1 << isedge2 << isedge3 
			     << isedge4 << endl;
		}
	      break;
	    }
	  }

	if (type == HP_NONE)
	  {
	    cerr << "undefined QUAD type" << endl;
	    for (j = 0; j < 4; j++)
	      pnums[j] = el[j];
	  }

	HPRefElement hpel;
	hpel.type = type;
	for (j = 0; j < 8; j++)
	  hpel.pnums[j] = pnums[j];
	hpel.index = el.GetIndex();
	hpel.level = 1;
	hpel.coarse_elnr = i-1;


	static const double points[3][2] = 
	  { { 1, 0 }, { 0, 1 }, { 0, 0 } };
	for (j = 0; j < 3; j++)
	  for (k = 0; k < 3; k++)
	    if (pnums[j] == el[k])
	      {
		hpel.param[j][0] = points[k][0];
		hpel.param[j][1] = points[k][1];
	      }
	elements.Append (hpel);
      }
  
  
  

  

    for (int i = 1; i <= mesh.GetNSeg(); i++)
      {
	Segment & seg = mesh.LineSegment(i);
      
	HPREF_ELEMENT_TYPE type = HP_NONE;

	int cp1 = cornerpoint.Test (seg.p1);
	int cp2 = cornerpoint.Test (seg.p2);

	INDEX_2 i2;
	i2 = INDEX_2(seg.p1, seg.p2);
	i2.Sort();
	if (!edges.Used (i2))
	  {
	    cp1 = edgepoint.Test (seg.p1);
	    cp2 = edgepoint.Test (seg.p2);
	  }

	HPRefElement hpel;
	hpel.index = seg.edgenr + 10000 * seg.si;
	hpel.level = 1;
      
	hpel.pnums[0] = seg.p1;
	hpel.pnums[1] = seg.p2;
	hpel.param[0][0] = seg.epgeominfo[0].dist;
	hpel.param[1][0] = seg.epgeominfo[1].dist;
      
	if (!cp1 && !cp2)
	  hpel.type = HP_SEGM;
	else if (cp1 && !cp2)
	  hpel.type = HP_SEGM_SINGCORNERL;
	else if (!cp1 && cp2)
	  hpel.type = HP_SEGM_SINGCORNERR;
	else
	  hpel.type = HP_SEGM_SINGCORNERS;

	(*testout) << "refine segment " << seg << ", hptype= " << hpel.type << endl;

	elements.Append (hpel);

	(*testout) << "add seg: " << endl << seg << endl;
	(*testout) << "param = " << elements.Last().param[0][0] << ", " << elements.Last().param[1][0] << endl;
      }
  }

  

  /* *******************************  DoRefinement *************************************** */

  // parameter "fine": false ... divide elements by a factor of 3/4 to 1/4
  //                   true  ... divide by 7/8 to 1/8

  void DoRefinement (Mesh & mesh, ARRAY<HPRefElement> & elements,
		     Refinement * ref, bool fine) 
  {
    INDEX_2_HASHTABLE<int> newpts(elements.Size()+1);
    INDEX_3_HASHTABLE<int> newfacepts(elements.Size()+1);
  
    // prepare new points
  
    int oldelsize = elements.Size();
    for (int i = 0; i < oldelsize; i++)
      {
	HPRefElement & el = elements[i];
	HPRef_Struct * hprs = Get_HPRef_Struct (el.type);

	if (!hprs)
	  {
	    cout << "Refinementstruct not defined for element " << el.type << endl;
	    continue;
	  }

	int j = 0;
	while (hprs->splitedges[j][0])
	  {
	    INDEX_2 i2(el.pnums[hprs->splitedges[j][0]-1],
		       el.pnums[hprs->splitedges[j][1]-1]);
	    if (!newpts.Used (i2))
	      {
		Point3d np = Center (mesh.Point (i2.I1()),
				     mesh.Point (i2.I2()));
		np = Center (mesh.Point (i2.I1()),np);
		if ( fine ) np = Center (mesh.Point (i2.I1()),np);

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

	      if (i3.I2() > i3.I3()) Swap (i3.I2(), i3.I3());

	      if (!newfacepts.Used (i3))
		{
		  Point3d np = Center (mesh.Point (i3.I2()),
				       mesh.Point (i3.I3()));
		  np = Center (mesh.Point (i3.I1()),np);
		  if ( fine ) np = Center (mesh.Point (i3.I1()),np);
		  int npi = mesh.AddPoint (np);
		  newfacepts.Set (i3, npi);
		}
	      j++;
	    }
      }
  
    for (int i = 0; i < oldelsize; i++)
      {
	HPRefElement & el = elements[i];
	HPRef_Struct * hprs = Get_HPRef_Struct (el.type);
	int newlevel = el.level + 1;

	if (el.type == HP_SEGM ||
	    el.type == HP_TRIG ||
	    el.type == HP_QUAD ||
	    el.type == HP_TET ||
	    el.type == HP_PRISM ||
	    el.type == HP_HEX)
	  newlevel = el.level;

	if (!hprs) continue;

	int newpnums[64];
	double newparam[64][3];

	int j;
	for (j = 0; j < 8; j++)
	  {
	    newpnums[j] = el.pnums[j];
	    for (int l = 0; l < 3; l++)
	      newparam[j][l] = el.param[j][l];
	  }


	// split edges, incl. transferring curvature
	j = 0;
	while (hprs->splitedges[j][0])
	  {
	    INDEX_2 i2(el.pnums[hprs->splitedges[j][0]-1],
		       el.pnums[hprs->splitedges[j][1]-1]);

	    int npi = newpts.Get(i2);
	    newpnums[hprs->splitedges[j][2]-1] = npi;

	    double fac1, fac2;
	    if ( fine ) { fac1 = 0.875; fac2 = 0.125; }
	    else { fac1 = 0.75; fac2 = 0.25; }

	    for (int l = 0; l < 3; l++)
	      newparam[hprs->splitedges[j][2]-1][l] =
		fac1 * el.param[hprs->splitedges[j][0]-1][l] + 
		fac2 * el.param[hprs->splitedges[j][1]-1][l];
	      
	    j++;
	  }

	// split faces
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

	      double fac1, fac2;
	      if ( fine ) { fac1 = 0.75; fac2 = 0.125; }
	      else { fac1 = 0.5; fac2 = 0.25; }

	      for (int l = 0; l < 3; l++)
		newparam[hprs->splitfaces[j][3]-1][l] =
		  fac1 * el.param[hprs->splitfaces[j][0]-1][l] + 
		  fac2 * el.param[hprs->splitfaces[j][1]-1][l] + 
		  fac2 * el.param[hprs->splitfaces[j][2]-1][l];
	      j++;
	    }

	// split elements
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
	      // divide once more, if fine subdivision is wanted
	      if ( fine ) np = Center (mesh.Point (pi1),np);
	      int npi = mesh.AddPoint (np);
	      newpnums[hprs->splitelements[j][4]-1] = npi;

	      double fac1, fac2;
	      if ( fine ) { fac1 = 0.625; fac2 = 0.125; }
	      else { fac1 = 0.25; fac2 = 0.25; }

	      for (int l = 0; l < 3; l++)
		newparam[hprs->splitelements[j][4]-1][l] =
		  fac1 * el.param[hprs->splitelements[j][0]-1][l] + 
		  fac2 * el.param[hprs->splitelements[j][1]-1][l] + 
		  fac2 * el.param[hprs->splitelements[j][2]-1][l] + 
		  fac2 * el.param[hprs->splitelements[j][3]-1][l];

	      j++;
	    }

	j = 0;
	while (hprs->neweltypes[j])
	  {
	    HPRefElement newel;
	    newel.type = hprs->neweltypes[j];
	    for (int k = 0; k < 8; k++)
	      newel.pnums[k] = newpnums[hprs->newels[j][k]-1];

	    newel.index = elements[i].index;
	    newel.coarse_elnr = elements[i].coarse_elnr;
	    newel.level = newlevel;

	    for (int k = 0; k < 8; k++)  
	      for (int l = 0; l < 3; l++)
		newel.param[k][l] = newparam[hprs->newels[j][k]-1][l];

	    if (j == 0) 
	      elements[i] = newel;
	    else        
	      elements.Append (newel);

	    j++;
	  }
      }
  }






  /* ************************** DoRefineDummies ******************************** */

  void DoRefineDummies (Mesh & mesh, ARRAY<HPRefElement> & elements,
			Refinement * ref)
  {
    int oldelsize = elements.Size();

    for (int i = 0; i < oldelsize; i++)
      {
	HPRefElement & el = elements[i];
	HPRef_Struct * hprs = Get_HPRef_Struct (el.type);
	if (!hprs) continue;

	if (el.type != HP_DUMMY_QUAD_SINGCORNER &&
	    el.type != HP_PYRAMID_EDGES &&
	    el.type != HP_PYRAMID_0E_1V &&
	    el.type != HP_HEX_0E_1V &&
	    el.type != HP_HEX_1E_1V &&
	    el.type != HP_HEX_1E_0V &&
	    el.type != HP_HEX_3E_0V
	    ) continue;

	int newlevel = el.level;

	int newpnums[8];
	int j;
	for (j = 0; j < 8; j++)
	  newpnums[j] = el.pnums[j];

	double newparam[8][3];
	for (j = 0; j < 8; j++)
	  for (int k = 0; k < 3; k++)
	    newparam[j][k] = el.param[j][k];

	j = 0;
	while (hprs->neweltypes[j])
	  {
	    HPRefElement newel;
	    newel.type = hprs->neweltypes[j];
	    for (int k = 0; k < 8; k++)
	      newel.pnums[k] = newpnums[hprs->newels[j][k]-1];
	    newel.index = el.index;
	    newel.coarse_elnr = el.coarse_elnr;
	    newel.level = newlevel;

	    for (int k = 0; k < 8; k++)
	      for (int l = 0; l < 3; l++)
		newel.param[k][l] = newparam[hprs->newels[j][k]-1][l];
		
	    if (j == 0)
	      elements[i] = newel;
	    else
	      elements.Append (newel);
	    j++;
	  }
      }
  }







  void SubdivideDegeneratedHexes (Mesh & mesh, ARRAY<HPRefElement> & elements)
  {
    int oldne = elements.Size();
    for (int i = 0; i < oldne; i++)
      if (Get_HPRef_Struct (elements[i].type)->geom == HP_HEX)
	{
	  bool common = 0;
	  for (int j = 0; j < 8; j++)
	    for (int k = 0; k < j; k++)
	      if (elements[i].pnums[j] == elements[i].pnums[k])
		common = 1;
	  if (common)
	    {
	      HPRefElement el = elements[i];

	      Point<3> center(0,0,0);
	      double newparam[3] = { 0, 0, 0 };

	      for (int j = 0; j < 8; j++)
		{
		  center += 0.125 * Vec<3> (mesh[el.pnums[j]]);
		  for (int l = 0; l < 3; l++)
		    newparam[l] += 0.125 * el.param[j][l];
		}

	      int npi = mesh.AddPoint (center);

	      const ELEMENT_FACE * faces = MeshTopology::GetFaces (HEX);

	      for (int j = 0; j < 6; j++)
		{
		  ARRAY<int> pts;
		  for (int k = 0; k < 4; k++)
		    {
		      bool same = 0;
		      for (int l = 0; l < pts.Size(); l++)
			if (el.pnums[pts[l]] == el.pnums[faces[j][k]-1])
			  same = 1;
		      if (!same)
			pts.Append (faces[j][k]-1);

		    }
		  
		  HPRefElement newel = el;
		  if (pts.Size() == 3)
		    {
		      for (int k = 0; k < 3; k++)
			{
			  newel.pnums[k] = el.pnums[pts[2-k]];
			  for (int l = 0; l < 3; l++)
			    newel.param[k][l] = el.param[pts[2-k]][l];
			}
		      newel.pnums[3] = npi;
		      for (int l = 0; l < 3; l++)
			newel.param[3][l] = newparam[l];

		      newel.type = HP_TET;
		    }
		  else
		    {
		      for (int k = 0; k < 4; k++)
			{
			  newel.pnums[k] = el.pnums[pts[3-k]];
			  for (int l = 0; l < 3; l++)
			    newel.param[k][l] = el.param[pts[3-k]][l];
			}

		      newel.pnums[4] = npi;
		      for (int l = 0; l < 3; l++)
			newel.param[4][l] = newparam[l];

		      newel.type = HP_PYRAMID;
		    }
		  
		  if (j == 0)
		    elements[i] = newel;
		  else
		    elements.Append (newel);
		}
	    }
	}
  }


  void CalcStatistics (ARRAY<HPRefElement> & elements)
  {
    return;
    
    int i, p;
    int nsegm = 0, ntrig = 0, nquad = 0;
    int nhex = 0, nprism = 0, npyramid = 0, ntet = 0;
    int maxlevel = 0;

    for (i = 1; i <= elements.Size(); i++)
      {
	const HPRefElement & el = elements.Get(i);
	maxlevel = max2 (el.level, maxlevel);
	switch (Get_HPRef_Struct (el.type)->geom)
	  {
	  case HP_SEGM:

	    {
	      nsegm++;
	      break;
	    }
	  case HP_TRIG:
	    {
	      ntrig ++;
	      break;
	    }
	  case HP_QUAD:
	    {
	      nquad++;
	      break;
	    }
	  case HP_TET:
	    {
	      ntet++;
	      break;
	    }

	  case HP_PRISM:
	    {
	      nprism++;
	      break;
	    }

	  case HP_PYRAMID:
	    {
	      npyramid++;
	      break;
	    }

	  case HP_HEX:
	    {	
	      nhex++;
	      break;
	    }

	  default:
	    {
	      cerr << "statistics error, unknown element type" << endl;
	    }
	  }
      }

    cout << "level = " << maxlevel << endl;
    cout << "nsegm = " << nsegm << endl;
    cout << "ntrig = " << ntrig << ", nquad = " << nquad << endl;
    cout << "ntet = " << ntet << ", npyr = " << npyramid
	 << ", nprism = " << nprism << ", nhex = " << nhex << endl;

    return;

    double memcost = 0, cpucost = 0;
    for (p = 1; p <= 20; p++)
      {
	memcost = (ntet + nprism + nhex) * pow (static_cast<double>(p), 6.0);
	cpucost = (ntet + nprism + nhex) * pow (static_cast<double>(p), 9.0);
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
	      (*testout) << "p1 = " << p1 << ", P1^6 = " << pow (static_cast<double>(p1), 6.0)
			 << " (p1-3)^6 = " << pow ( static_cast<double>(max2(p1-3, 0)), 6.0) 
			 << " p1^3 = " << pow ( static_cast<double>(p1), 3.0) 
			 << " (p1-3)^3 = " << pow ( static_cast<double>(p1-3), 3.0) 
			 << " [p1^3-(p1-3)^3]^2 = " << sqr (pow (static_cast<double>(p1),3.0) - pow ( static_cast<double>(p1-3), 3.0))
			 << endl;

	      p1 /= 2 +1;
	      memcosttet += pow (static_cast<double>(p1), 6.0);
	      memcostsctet += pow (static_cast<double>(p1), 6.0) - pow ( static_cast<double>(max2(p1-3, 1)), 6.0);
	      cpucosttet += pow (static_cast<double>(p1), 9.0);
	      break;
	    }
	  case HP_PRISM:
	  case HP_PRISM_SINGEDGE:
	    {
	      int p1 = maxlevel - el.level + 1;
	      p1 /= 2 +1;
	      memcostprism += pow (static_cast<double>(p1), 6.0);
	      memcostscprism += pow (static_cast<double>(p1), 6.0) - pow ( static_cast<double>(max2(p1-3, 1)), 6.0);
	      cpucostprism += pow (static_cast<double>(p1), 9.0);
	      break;
	    }
	  case HP_HEX:
	    {	
	      int p1 = maxlevel - el.level + 1;
	      int p2 = maxlevel;
	      p1 /= 2 +1;
	      p2 /= 2 +1;
	      memcosthex += pow (static_cast<double>(p1), 4.0) * pow (static_cast<double>(p2), 2.0);
	      memcostschex += pow (static_cast<double>(p1), 6.0) - pow ( static_cast<double>(max2(p1-2, 0)), 6.0);
	      cpucosthex += pow (static_cast<double>(p1), 6.0) * pow (static_cast<double>(p2), 3.0);
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







  /* ***************************** HPRefinement ********************************** */

  void HPRefinement (Mesh & mesh, Refinement * ref, int levels)
  {
    PrintMessage (1, "HP Refinement called, levels = ", levels);

    // ARRAY<HPRefElement> hpelements;

    delete mesh.hpelements;
    mesh.hpelements = new ARRAY<HPRefElement>;

    mesh.coarsemesh = new Mesh;
    *mesh.coarsemesh = mesh;

    ARRAY<HPRefElement> & hpelements = *mesh.hpelements;



    PrepareElements (mesh, hpelements);

    for (int j = 1; j <= levels; j++)
      {
	cout << "hp-refine level " << j << flush;
	// last parameter: true for fine subdivision (7/8 : 1/8), false for 3/4 : 1/4
	// Please check into CVS only with this parameter set to "true"!
	DoRefinement (mesh, hpelements, ref, true); // FB 
	DoRefineDummies (mesh, hpelements, ref);
	CalcStatistics (hpelements);
	cout << " done" << endl;
      }

    SubdivideDegeneratedHexes (mesh, hpelements);

    mesh.ClearSegments();
    mesh.ClearSurfaceElements();
    mesh.ClearVolumeElements();

    for (int i = 0; i < hpelements.Size(); i++)
      {
	HPRefElement & hpel = hpelements[i];
	if (Get_HPRef_Struct (hpel.type))
	  switch (Get_HPRef_Struct (hpel.type) -> geom)
	    {
	    case HP_SEGM:
	      {
		Segment seg;
		seg.p1 = hpel.pnums[0];
		seg.p2 = hpel.pnums[1];
		// NOTE: only for less than 10000 elements (HACK) !!!
		seg.edgenr = hpel.index % 10000;
		seg.si     = hpel.index / 10000;
		seg.epgeominfo[0].dist = hpel.param[0][0]; 
		seg.epgeominfo[1].dist = hpel.param[1][0];
		seg.epgeominfo[0].edgenr = seg.edgenr;
		seg.epgeominfo[1].edgenr = seg.edgenr;
		seg.hp_elnr = i;
		mesh.AddSegment (seg);
		break;
	      }
	    

	    case HP_TRIG:
	      {
		Element2d el(3);
		el.PNum(1) = hpel.pnums[0];
		el.PNum(2) = hpel.pnums[1];
		el.PNum(3) = hpel.pnums[2];
		el.SetIndex (hpel.index);
		el.hp_elnr = i;
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
		el.hp_elnr = i;
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
		el.hp_elnr = i;
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
		el.hp_elnr = i;
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
		el.hp_elnr = i;
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
		el.SetIndex (hpel.index);
		el.hp_elnr = i;
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
