




  // HP_PRISM  ... no refinement
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



  // HP_PRISM_SINGEDGE  ... vertical edge 1-4 is singular
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






  // HP_PRISM_SINGEDGE_V12  vertical edges 1-4 and 2-5 are singular 
  int refprism_singedge_v12_splitedges[][3] =
    {
      { 1, 2, 7 },
      { 1, 3, 8 },
      { 2, 1, 9 },
      { 2, 3, 10 },
      { 4, 5, 11 },
      { 4, 6, 12 },
      { 5, 4, 13 },
      { 5, 6, 14},
      { 0, 0, 0 }
    };
  HPREF_ELEMENT_TYPE refprism_singedge_v12_newelstypes[] =
    {
      HP_HEX,
      HP_PRISM,
      HP_PRISM,
      HP_PRISM,
      HP_NONE,
    };
  int refprism_singedge_v12_newels[][8] =
    {
      { 7, 9, 10, 8, 11, 13, 14, 12 },
      { 1, 7, 8, 4, 11, 12 },
      { 2, 10, 9, 5, 14, 13 },
      { 3, 8, 10, 6, 12, 14 },
    };
  HPRef_Struct refprism_singedge_v12 =
    {
      HP_PRISM,
      refprism_singedge_v12_splitedges, 
      0, 0,
      refprism_singedge_v12_newelstypes, 
      refprism_singedge_v12_newels
    };






  // HP_PRISM_SINGEDGE_H12
  int refprism_singedge_h12_splitedges[][3] =
    {
      { 1, 3, 7 },
      { 2, 1, 8 },
      { 2, 3, 9 },
      { 3, 1, 10 },

      { 4, 6, 12 },
      { 5, 4, 13 },
      { 5, 6, 14 },
      { 6, 4, 15 },

      { 0, 0, 0 }
    };

  int refprism_singedge_h12_splitfaces[][4] =
    {
      { 2, 1, 3, 11 },
      { 5, 4, 6, 16 },
      { 0, 0, 0, 0 },
    };

  HPREF_ELEMENT_TYPE refprism_singedge_h12_newelstypes[] =
    {
      HP_HEX,
      HP_HEX,
      HP_PRISM,
      HP_PRISM,
      HP_PRISM,
      HP_NONE,
    };
  int refprism_singedge_h12_newels[][8] =
    {
      { 1, 8, 11, 7, 4, 13, 16, 12 },
      { 9, 3, 10, 11, 14, 6, 15, 16 },
      { 7, 11, 10, 12, 16, 15 },
      { 2, 9, 11, 5, 14, 16 },
      { 8, 2, 11, 13, 5, 16 }
    };
  HPRef_Struct refprism_singedge_h12 =
    {
      HP_PRISM,
      refprism_singedge_h12_splitedges, 
      refprism_singedge_h12_splitfaces, 
      0,
      refprism_singedge_h12_newelstypes, 
      refprism_singedge_h12_newels
    };






  // HP_PRISM_SINGEDGE_H1
  int refprism_singedge_h1_splitedges[][3] =
    {
      { 1, 3, 7 },
      { 2, 3, 8 },
      { 4, 6, 9 },
      { 5, 6, 10 },
      { 0, 0, 0 }
    };
  HPREF_ELEMENT_TYPE refprism_singedge_h1_newelstypes[] =
    {
      HP_HEX,
      HP_PRISM,
      HP_NONE,
    };
  int refprism_singedge_h1_newels[][8] =
    {
      { 1, 2, 8, 7, 4, 5, 10, 9 },
      { 3, 7, 8, 6, 9, 10 }
    };
  HPRef_Struct refprism_singedge_h1 =
    {
      HP_PRISM,
      refprism_singedge_h1_splitedges, 
      0, 0,
      refprism_singedge_h1_newelstypes, 
      refprism_singedge_h1_newels
    };







//  HP_PRISM_1FA_0E_0V
  int refprism_1fa_0e_0v_splitedges[][3] =
    {
      { 1, 4, 7 },
      { 2, 5, 8 },
      { 3, 6, 9 },
      { 0, 0, 0 }
    };
  HPREF_ELEMENT_TYPE refprism_1fa_0e_0v_newelstypes[] =
    {
      HP_PRISM_1FA_0E_0V,
      HP_PRISM,
      HP_NONE,
    };
  int refprism_1fa_0e_0v_newels[][8] =
    {
      { 1, 2, 3, 7, 8, 9 },
      { 7, 8, 9, 4, 5, 6 }
    };
  HPRef_Struct refprism_1fa_0e_0v =
    {
      HP_PRISM,
      refprism_1fa_0e_0v_splitedges, 
      0, 0,
      refprism_1fa_0e_0v_newelstypes, 
      refprism_1fa_0e_0v_newels
    };






//  HP_PRISM_1FB_0E_0V   ... quad face 1-2-4-5
  int refprism_1fb_0e_0v_splitedges[][3] =
    {
      { 1, 3, 7 },
      { 2, 3, 8 },
      { 4, 6, 9 },
      { 5, 6, 10 },
      { 0, 0, 0 }
    };
  HPREF_ELEMENT_TYPE refprism_1fb_0e_0v_newelstypes[] =
    {
      HP_HEX_1F_0E_0V,
      HP_PRISM,
      HP_NONE,
    };
  int refprism_1fb_0e_0v_newels[][8] =
    {
      { 1, 4, 5, 2, 7, 9, 10, 8  },
      { 7, 8, 3, 9, 10, 6 }
    };
  HPRef_Struct refprism_1fb_0e_0v =
    {
      HP_PRISM,
      refprism_1fb_0e_0v_splitedges, 
      0, 0,
      refprism_1fb_0e_0v_newelstypes, 
      refprism_1fb_0e_0v_newels
    };






//  HP_PRISM_1FB_1EA_0V   ... quad face 1-2-4-5
  int refprism_1fb_1ea_0v_splitedges[][3] =
    {
      { 1, 3, 7 },
      { 2, 3, 8 },
      { 4, 6, 9 },
      { 5, 6, 10 },
      { 1, 2, 11 },
      { 4, 5, 12 },
      { 0, 0, 0 }
    };
  HPREF_ELEMENT_TYPE refprism_1fb_1ea_0v_newelstypes[] =
    {
      HP_HEX_1F_0E_0V,
      HP_PRISM_1FB_1EA_0V,
      HP_PRISM,
      HP_NONE,
    };
  int refprism_1fb_1ea_0v_newels[][8] =
    {
      { 11, 12, 5, 2, 7, 9, 10, 8  },
      { 1, 11, 7, 4, 12, 9 },
      { 7, 8, 3, 9, 10, 6 }
    };
  HPRef_Struct refprism_1fb_1ea_0v =
    {
      HP_PRISM,
      refprism_1fb_1ea_0v_splitedges, 
      0, 0,
      refprism_1fb_1ea_0v_newelstypes, 
      refprism_1fb_1ea_0v_newels
    };





