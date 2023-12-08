// All libOL code is Copyright 2012-2018 - by Loïc Maréchal / INRIA.
// This program is a free software.
// You can redistribute it and/or modify it under the terms of the MIT License
// as published by the Open Source Initiative.
//  
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the MIT License for more details.
//  
// You should have received a copy of the MIT License along with this program
// as the file LICENSE.txt; if not, please see:
// https://opensource.org/licenses/MIT
//
//
// MIT License
// 
// Copyright (c) 2012-2018 Loïc Maréchal / INRIA
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                      LIB OCTREE LOCALISATION V1.70                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Description:         Octree for mesh localization                       */
/*    Author:              Loic MARECHAL                                      */
/*    Creation date:       mar 16 2012                                        */
/*    Last modification:   feb 03 2021                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* ANSI C headers                                                             */
/*----------------------------------------------------------------------------*/

#include <assert.h>
#include <fcntl.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "libol1.h"


/*----------------------------------------------------------------------------*/
/* Defines and macros                                                         */
/*----------------------------------------------------------------------------*/

#define MaxItmOct 20
#define MaxOctLvl 10
#define MinGrdLvl 5
#define ItmPerBuc 100
#define MemBlkSiz 100000
#define TngFlg    1
#define AniFlg    2
#define MaxThr    256
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
#define POW(a)    ((a)*(a))
#define CUB(a)    ((a)*(a)*(a))


/*----------------------------------------------------------------------------*/
/* Local structures                                                           */
/*----------------------------------------------------------------------------*/

typedef struct
{
   itg   idx;
   fpn   crd[3];
}VerSct;

typedef struct
{
   VerSct  *ver[2];
   fpn      tng[3], siz;
   itg      idx;
}EdgSct;

typedef struct
{
   EdgSct   edg[3];
   VerSct  *ver[3];
   fpn      nrm[3];
   itg      idx;
   float    ani;
}TriSct;

typedef struct
{
   VerSct  *ver[4];
   EdgSct   edg[4];
   TriSct   tri[2];
   fpn      nrm[3];
   itg      idx;
}QadSct;

typedef struct
{
   VerSct  *ver[4];
   EdgSct   edg[6];
   TriSct   tri[4];
   itg      idx;
   float    ani;
}TetSct;

typedef struct
{
   VerSct  *ver[5];
   EdgSct   edg[8];
   TriSct   tri[5][2];
   itg      idx;
}PyrSct;

typedef struct
{
   VerSct  *ver[6];
   EdgSct   edg[9];
   TriSct   tri[5][2];
   itg      idx;
}PriSct;

typedef struct
{
   VerSct  *ver[8];
   EdgSct   edg[12];
   QadSct   qad[6];
   itg      idx;
}HexSct;

typedef struct LnkSctPtr
{
   itg      typ, idx;
   struct   LnkSctPtr *nex;
}LnkSct;

typedef struct MemSctPtr
{
   size_t   siz;
   void    *adr;
   struct   MemSctPtr *nex;
}MemSct;

typedef struct
{
   VerSct   ver[8], BakVer[8];
   EdgSct   edg, BakEdg;
   TriSct   tri, BakTri;
   QadSct   qad, BakQad;
   TetSct   tet, BakTet;
   PyrSct   pyr, BakPyr;
   PriSct   pri, BakPri;
   HexSct   hex, BakHex;
   char    *FlgTab;
   itg     *TagTab, tag;
}MshThrSct;

typedef struct
{
   MshThrSct thr[ MaxThr ];
   size_t   UsrSiz[ LolNmbTyp ], NmbItm[ LolNmbTyp ];
   fpn      aniso, eps;
   itg      BasIdx;
   char    *UsrPtr[ LolNmbTyp ];
}MshSct;

typedef struct OctSctPtr
{
   union
   {
      LnkSct *lnk;
      struct OctSctPtr *son;
   };
   unsigned char NmbVer, NmbEdg, NmbFac, NmbVol, lvl, sub, ani, MaxItm;
}OctSct;

typedef struct
{
   OctSct  *oct;
   itg      idx;
   char     pos[3];
}BucSct;

typedef struct
{
   VerSct   ver[8];
   HexSct   hex;
   itg      tag, *ThrTag;
   BucSct **ThrStk;
}OctThrSct;

typedef struct
{
   OctThrSct thr[ MaxThr ];
   itg      MaxLvl, NmbFreOct, NmbOct, GrdLvl, NmbBuc, NmbThr;
   size_t   MemUse;
   fpn      eps, MaxSiz, MinSiz, BucSiz, bnd[2][3];
   OctSct   oct, *CurOctBlk;
   BucSct  *grd;
   LnkSct  *NexFreLnk;
   MemSct  *NexMem;
   MshSct  *msh;
}TreSct;


/*----------------------------------------------------------------------------*/
/* Prototypes of octree procedures                                            */
/*----------------------------------------------------------------------------*/

static void    SetMshBox   (TreSct *, MshSct *);
static void    AddVer      (MshSct *, TreSct *, OctSct *, fpn *, fpn *);
static void    AddEdg      (MshSct *, TreSct *, OctSct *, fpn *, fpn *);
static void    AddTri      (MshSct *, TreSct *, OctSct *, fpn *, fpn *);
static void    AddQad      (MshSct *, TreSct *, OctSct *, fpn *, fpn *);
static void    AddTet      (MshSct *, TreSct *, OctSct *, fpn *, fpn *);
static void    SubOct      (MshSct *, TreSct *, OctSct *, fpn *, fpn *);
static void    LnkItm      (TreSct *, OctSct *, itg, itg, char);
static OctSct *GetCrd      (OctSct *, itg, fpn *, fpn *, fpn *);
static void    GetBox      (TreSct *, OctSct *, itg, itg *, itg, itg *,
                           char *, fpn [2][3], fpn, fpn *, fpn *, itg );
static itg     BoxIntBox   (fpn [2][3], fpn [2][3], fpn);
static void    SetItm      (MshSct *, itg, itg, itg, itg);
static void    AniTri      (MshSct *, itg);
static void    SetSonCrd   (itg, fpn *, fpn *, fpn *, fpn *);
static void    GetOctLnk   (MshSct *, itg, fpn *, itg *, fpn *, OctSct *,
                           fpn *, fpn *, itg (void *, itg),  void *, itg);
static void    IntRayOct   (TreSct *, MshSct *, fpn *, fpn *, itg *, fpn *,
                            OctSct *, fpn *, fpn *, itg (void *, itg),  void *,
                            itg);
static void    GetBucBox   (TreSct *, BucSct *, fpn *, fpn *);
static BucSct *GetBucNgb   (TreSct *, BucSct *, itg);
static fpn     DisVerOct   (fpn *, fpn *, fpn *);
static itg     VerInsOct   (fpn *, fpn *, fpn *);
static char   *GetPtrItm   (MshSct *, itg, itg);
static void    BakMshItm   (MshSct *);
static void    RstMshItm   (MshSct *);


/*----------------------------------------------------------------------------*/
/* Prototypes of meshing procedures                                           */
/*----------------------------------------------------------------------------*/

static itg     EdgIntEdg   (EdgSct *, EdgSct *, VerSct *, fpn);
static fpn     DisVerTri   (MshSct *, fpn *, TriSct *);
static fpn     DisVerQad   (MshSct *, fpn *, QadSct *);
static fpn     DisVerTet   (MshSct *, fpn *, TetSct *);
static fpn     GetTriSrf   (TriSct *);
static fpn     GetVolTet   (TetSct *);
static fpn     DisVerEdg   (fpn *, EdgSct *);
static void    GetTriVec   (TriSct *, fpn *);
static void    SetTriNrm   (TriSct *);
static void    SetTmpHex   (HexSct *, fpn *, fpn *);
static itg     VerInsTet   (VerSct *, TetSct *, fpn);
static itg     VerInsHex   (VerSct *, HexSct *);
static itg     EdgIntHex   (EdgSct *, HexSct *, fpn);
static itg     TriIntHex   (TriSct *, HexSct *, fpn);
static itg     QadIntHex   (QadSct *, HexSct *, fpn);
static itg     TetIntHex   (TetSct *, HexSct *, fpn);
static itg     EdgIntQad   (HexSct *, itg, EdgSct *, VerSct *, fpn);
static itg     EdgIntTri   (TriSct *, EdgSct *, VerSct *, fpn);
static itg     VerInsTri   (TriSct *, VerSct *, fpn);
static itg     VerInsEdg   (EdgSct *, VerSct *, fpn);
static void    SetEdgTng   (EdgSct *);
static fpn     GetTriAni   (TriSct *);


/*----------------------------------------------------------------------------*/
/* Prototypes of geometric procedures                                         */
/*----------------------------------------------------------------------------*/

static void    PrjVerLin   (fpn *, fpn *, fpn *, fpn *);
static fpn     PrjVerPla   (fpn *, fpn *, fpn *, fpn *);
static void    LinCmbVec3  (fpn,   fpn *, fpn,   fpn *, fpn *);
static void    ClrVec      (fpn *);
static void    CpyVec      (fpn *, fpn *);
static void    AddVec2     (fpn *, fpn *);
static void    SubVec2     (fpn *, fpn *);
static void    SubVec3     (fpn *, fpn *, fpn *);
static void    AddScaVec1  (fpn,   fpn *);
static void    AddScaVec2  (fpn,   fpn *, fpn *);
static void    MulVec1     (fpn,   fpn *);
static void    MulVec2     (fpn,   fpn *, fpn *);
static void    NrmVec      (fpn *);
static void    CrsPrd      (fpn *, fpn *, fpn *);
static fpn     DotPrd      (fpn *, fpn *);
static fpn     dis         (fpn *, fpn *);
static fpn     DisPow      (fpn *, fpn *);
static fpn     DisVerPla   (fpn *, fpn *, fpn *);
static fpn     GetNrmVec   (fpn *);
static fpn     VerInsBox   (fpn *, fpn *, fpn *, fpn);
static itg     LinIntBox   (fpn *, fpn *, fpn *, fpn *, fpn);
static void    LinIntPla   (fpn *, fpn *, fpn *, fpn *, fpn *);


/*----------------------------------------------------------------------------*/
/* Prototypes of memory handling procedures                                   */
/*----------------------------------------------------------------------------*/

static void   *NewMem      (TreSct *, size_t);
static void    FreAllMem   (TreSct *);


/*----------------------------------------------------------------------------*/
/* Local mesh connectivity tables                                             */
/*----------------------------------------------------------------------------*/

static const itg TetEdg[6][2]    = { {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} };
static const itg TetFac[4][3]    = { {1,2,3}, {2,0,3}, {3,0,1}, {0,2,1} };
static const itg TetFacEdg[4][3] = { {5,4,3}, {2,5,1}, {0,4,2}, {3,1,0} };
static const itg tvpe[12][2]     = { {3,2}, {0,1}, {4,5}, {7,6}, {3,7}, {2,6},
                                     {1,5}, {0,4}, {3,0}, {7,4}, {6,5}, {2,1} };
static const itg tvpf[6][4]      = { {3,0,4,7}, {5,1,2,6}, {3,2,1,0},
                                     {5,6,7,4},{3,7,6,2}, {5,4,0,1} };


/*----------------------------------------------------------------------------*/
/* Allocate and build a new octree from user's data                           */
/*----------------------------------------------------------------------------*/

int64_t LolNewOctree(itg NmbVer, fpn *PtrCrd1, fpn *PtrCrd2,
                     itg NmbEdg, itg *PtrEdg1, itg *PtrEdg2,
                     itg NmbTri, itg *PtrTri1, itg *PtrTri2,
                     itg NmbQad, itg *PtrQad1, itg *PtrQad2,
                     itg NmbTet, itg *PtrTet1, itg *PtrTet2,
                     itg NmbPyr, itg *PtrPyr1, itg *PtrPyr2,
                     itg NmbPri, itg *PtrPri1, itg *PtrPri2,
                     itg NmbHex, itg *PtrHex1, itg *PtrHex2,
                     itg BasIdx, itg NmbThr)
{
   itg         i, j, k, t, EdgIdx, TotItmCnt = 0, MaxItmCnt, idx = 0;
   fpn         crd[3];
   BucSct     *buc;
   TreSct     *tre = NULL;
   MshSct     *msh;
   OctThrSct  *OctThr;
   MshThrSct  *MshThr;

   // Make sure we have a vertex table and a valid base index (0 or 1)
   if(!NmbVer || !PtrCrd1 || !PtrCrd2 || (BasIdx < 0) || (BasIdx > 1) )
      return(0);

   NmbThr = MAX(NmbThr, 1);
   NmbThr = MIN(NmbThr, MaxThr);
   MaxItmCnt = NmbVer;

   // Setup a single octant octree
   tre = calloc(1, sizeof(TreSct));
   assert(tre);

   // Setup the mesh structure
   msh = NewMem(tre, sizeof(MshSct));
   msh->BasIdx = BasIdx;

   msh->NmbItm[ LolTypVer ] = NmbVer;
   TotItmCnt               += NmbVer;
   msh->UsrPtr[ LolTypVer ] = (char *)PtrCrd1;
   msh->UsrSiz[ LolTypVer ] = (char *)PtrCrd2 - (char *)PtrCrd1;

   msh->NmbItm[ LolTypEdg ] = NmbEdg;
   MaxItmCnt                = MAX(MaxItmCnt, NmbEdg);
   TotItmCnt               += NmbEdg;
   msh->UsrPtr[ LolTypEdg ] = (char *)PtrEdg1;
   msh->UsrSiz[ LolTypEdg ] = (char *)PtrEdg2 - (char *)PtrEdg1;

   msh->NmbItm[ LolTypTri ] = NmbTri;
   MaxItmCnt                = MAX(MaxItmCnt, NmbTri);
   TotItmCnt               += NmbTri;
   msh->UsrPtr[ LolTypTri ] = (char *)PtrTri1;
   msh->UsrSiz[ LolTypTri ] = (char *)PtrTri2 - (char *)PtrTri1;

   msh->NmbItm[ LolTypQad ] = NmbQad;
   MaxItmCnt                = MAX(MaxItmCnt, NmbQad);
   TotItmCnt               += NmbQad;
   msh->UsrPtr[ LolTypQad ] = (char *)PtrQad1;
   msh->UsrSiz[ LolTypQad ] = (char *)PtrQad2 - (char *)PtrQad1;

   msh->NmbItm[ LolTypTet ] = NmbTet;
   MaxItmCnt                = MAX(MaxItmCnt, NmbTet);
   TotItmCnt               += NmbTet;
   msh->UsrPtr[ LolTypTet ] = (char *)PtrTet1;
   msh->UsrSiz[ LolTypTet ] = (char *)PtrTet2 - (char *)PtrTet1;

   for(t=0;t<NmbThr;t++)
   {
      MshThr = &msh->thr[t];

      MshThr->FlgTab = NewMem(tre, (MaxItmCnt + 1) * sizeof(char) );
      memset(MshThr->FlgTab, 0, (MaxItmCnt + 1) * sizeof(char));

      MshThr->TagTab = NewMem(tre, (MaxItmCnt + 1) * sizeof(itg) );
      memset(MshThr->TagTab, 0, (MaxItmCnt + 1) * sizeof(itg));

      MshThr->tag = 0;
   }

   // Setup the octree structure
   SetMshBox(tre, msh);
   tre->msh = msh;
   msh->eps = tre->eps;

   // Set the grid size depending on the number of entities in the mesh
   tre->GrdLvl = MAX(MinGrdLvl, log((TotItmCnt) / ItmPerBuc) / (3 * log(2)));
   tre->NmbBuc = 1<<tre->GrdLvl;
   tre->grd    = NewMem(tre, CUB(tre->NmbBuc) * sizeof(BucSct));
   tre->NmbThr = NmbThr;

   for(t=0;t<NmbThr;t++)
   {
      MshThr = &msh->thr[t];
      OctThr = &tre->thr[t];

      OctThr->ThrStk = NewMem(tre, CUB(tre->NmbBuc) * sizeof(void *));
      OctThr->ThrTag = NewMem(tre, CUB(tre->NmbBuc) * sizeof(itg));

      // Setup the temporary edge for local geometric calculations
      for(i=0;i<2;i++)
         MshThr->edg.ver[i] = &MshThr->ver[i];

      // Setup the temporary triangle for local geometric calculations
      for(i=0;i<3;i++)
      {
         MshThr->tri.ver[i] = &MshThr->ver[i];
         MshThr->tri.edg[i].ver[0] = &MshThr->ver[ (i+1)%3 ];
         MshThr->tri.edg[i].ver[1] = &MshThr->ver[ (i+2)%3 ];
      }

      // Setup the temporary quad for local geometric calculations
      for(i=0;i<4;i++)
      {
         MshThr->qad.ver[i] = &MshThr->ver[i];
         MshThr->qad.edg[i].ver[0] = &MshThr->ver[ i ];
         MshThr->qad.edg[i].ver[1] = &MshThr->ver[ (i+1)%4 ];
      }

      // The quad is made of two triangles
      MshThr->qad.tri[0].ver[0] = &MshThr->ver[0];
      MshThr->qad.tri[0].ver[1] = &MshThr->ver[1];
      MshThr->qad.tri[0].ver[2] = &MshThr->ver[2];

      MshThr->qad.tri[1].ver[0] = &MshThr->ver[3];
      MshThr->qad.tri[1].ver[1] = &MshThr->ver[2];
      MshThr->qad.tri[1].ver[2] = &MshThr->ver[1];

      for(i=0;i<2;i++)
         for(j=0;j<3;j++)
         {
            MshThr->qad.tri[i].edg[j].ver[0] = MshThr->qad.tri[i].ver[ (j+1)%3 ];
            MshThr->qad.tri[i].edg[j].ver[1] = MshThr->qad.tri[i].ver[ (j+2)%3 ];
         }

      // Setup the temporary tetrahedron for local geometric calculations
      for(i=0;i<4;i++)
         MshThr->tet.ver[i] = &MshThr->ver[i];

      for(i=0;i<4;i++)
      {
         for(j=0;j<3;j++)
            MshThr->tet.tri[i].ver[j] = MshThr->tet.ver[ TetFac[i][j] ];

         for(j=0;j<3;j++)
         {
            EdgIdx = TetFacEdg[i][j];
            MshThr->tet.tri[i].edg[j].ver[0] = MshThr->tet.ver[ TetEdg[ EdgIdx ][0] ];
            MshThr->tet.tri[i].edg[j].ver[1] = MshThr->tet.ver[ TetEdg[ EdgIdx ][1] ];
         }
      }

      for(i=0;i<6;i++)
         for(j=0;j<2;j++)
            MshThr->tet.edg[i].ver[j] = MshThr->tet.ver[ TetEdg[i][j] ];

      // Setup the temporary hex for local geometric calculations
      for(i=0;i<8;i++)
         OctThr->hex.ver[i] = &OctThr->ver[i];

      for(i=0;i<12;i++)
      {
         OctThr->hex.edg[i].ver[0] =  &OctThr->ver[ tvpe[i][0] ];
         OctThr->hex.edg[i].ver[1] =  &OctThr->ver[ tvpe[i][1] ];
      }

      for(i=0;i<6;i++)
         for(j=0;j<4;j++)
            OctThr->hex.qad[i].ver[j] =  &OctThr->ver[ tvpf[i][j] ];

      for(i=0;i<4;i++)
      {
         OctThr->hex.edg[i].tng[0] = 1;
         OctThr->hex.edg[i].tng[1] = 0;
         OctThr->hex.edg[i].tng[2] = 0;

         OctThr->hex.edg[i+4].tng[0] = 0;
         OctThr->hex.edg[i+4].tng[1] = 1;
         OctThr->hex.edg[i+4].tng[2] = 0;

         OctThr->hex.edg[i+8].tng[0] = 0;
         OctThr->hex.edg[i+8].tng[1] = 0;
         OctThr->hex.edg[i+8].tng[2] = 1;
      }

      OctThr->hex.qad[0].nrm[0] = 1;
      OctThr->hex.qad[0].nrm[1] = 0;
      OctThr->hex.qad[0].nrm[2] = 0;

      OctThr->hex.qad[1].nrm[0] = -1;
      OctThr->hex.qad[1].nrm[1] = 0;
      OctThr->hex.qad[1].nrm[2] = 0;

      OctThr->hex.qad[2].nrm[0] = 0;
      OctThr->hex.qad[2].nrm[1] = 1;
      OctThr->hex.qad[2].nrm[2] = 0;

      OctThr->hex.qad[3].nrm[0] = 0;
      OctThr->hex.qad[3].nrm[1] = -1;
      OctThr->hex.qad[3].nrm[2] = 0;

      OctThr->hex.qad[4].nrm[0] = 0;
      OctThr->hex.qad[4].nrm[1] = 0;
      OctThr->hex.qad[4].nrm[2] = 1;

      OctThr->hex.qad[5].nrm[0] = 0;
      OctThr->hex.qad[5].nrm[1] = 0;
      OctThr->hex.qad[5].nrm[2] = -1;
   }

   // Insert each vertex in the octree
   for(i=0;i<msh->NmbItm[ LolTypVer ];i++)
   {
      SetItm(msh, LolTypVer, i + BasIdx, 0, 0);
      AddVer(msh, tre, &tre->oct, tre->bnd[0], tre->bnd[1]);
   }

   // Insert each edge in the octree
   for(i=0;i<msh->NmbItm[ LolTypEdg ];i++)
   {
      SetItm(msh, LolTypEdg, i + BasIdx, 0, 0);
      AddEdg(msh, tre, &tre->oct, tre->bnd[0], tre->bnd[1]);
   }

   // Insert each triangle in the octree
   for(i=0;i<msh->NmbItm[ LolTypTri ];i++)
   {
      SetItm(msh, LolTypTri, i + BasIdx, TngFlg | AniFlg, 0);
      AddTri(msh, tre, &tre->oct, tre->bnd[0], tre->bnd[1]);
   }

   // Insert each quad in the octree
   for(i=0;i<msh->NmbItm[ LolTypQad ];i++)
   {
      SetItm(msh, LolTypQad, i + BasIdx, TngFlg | AniFlg, 0);
      AddQad(msh, tre, &tre->oct, tre->bnd[0], tre->bnd[1]);
   }

   // Insert each tetrahedron in the octree
   for(i=0;i<msh->NmbItm[ LolTypTet ];i++)
   {
      SetItm(msh, LolTypTet, i + BasIdx, TngFlg, 0);
      AddTet(msh, tre, &tre->oct, tre->bnd[0], tre->bnd[1]);
   }

   // Setup an acceleration grid whose buckets point to an octant
   tre->BucSiz = (tre->bnd[1][0] - tre->bnd[0][0]) / (fpn)tre->NmbBuc;
   crd[0] = tre->bnd[0][0] + tre->BucSiz / 2.;

   for(i=0;i<tre->NmbBuc;i++)
   {
      crd[1] = tre->bnd[0][1] + tre->BucSiz / 2.;

      for(j=0;j<tre->NmbBuc;j++)
      {
         crd[2] = tre->bnd[0][2] + tre->BucSiz / 2.;

         for(k=0;k<tre->NmbBuc;k++)
         {
            buc = &tre->grd[ i * POW(tre->NmbBuc) + j * tre->NmbBuc + k ];
            buc->oct = GetCrd(&tre->oct, tre->GrdLvl,
                              crd, tre->bnd[0], tre->bnd[1]);
            buc->pos[0] = i;
            buc->pos[1] = j;
            buc->pos[2] = k;
            buc->idx = idx++;
            crd[2] += tre->BucSiz;
         }

         crd[1] += tre->BucSiz;
      }

      crd[0] += tre->BucSiz;
   }

   // Return the octree's unique ID
   return((int64_t)tre);
}


/*----------------------------------------------------------------------------*/
/* Free the octants and the links                                             */
/*----------------------------------------------------------------------------*/

size_t LolFreeOctree(int64_t OctIdx)
{
   TreSct  *tre = (TreSct *)OctIdx;
   size_t   MemUse = tre->MemUse;

   FreAllMem(tre);
   memset(tre, 0, sizeof(TreSct));

   return(MemUse);
}


/*----------------------------------------------------------------------------*/
/* Search the octree for mesh entities included in this box                   */
/*----------------------------------------------------------------------------*/

itg LolGetBoundingBox(  int64_t OctIdx, itg typ, itg MaxItm, itg *ItmTab,
                        fpn MinCrd[3], fpn MaxCrd[3], itg ThrIdx )
{
   itg i, NmbItm = 0;
   fpn box[2][3] = { {MinCrd[0], MinCrd[1], MinCrd[2]},
                     {MaxCrd[0], MaxCrd[1], MaxCrd[2]} };
   TreSct *tre = (TreSct *)OctIdx;

   GetBox(  tre, &tre->oct, typ, &NmbItm, MaxItm, ItmTab,
            tre->msh->thr[ ThrIdx ].FlgTab, box, tre->eps,
            tre->bnd[0], tre->bnd[1], ThrIdx );

   for(i=0;i<NmbItm;i++)
      tre->msh->thr[ ThrIdx ].FlgTab[ ItmTab[i] ] = 0;

   return(NmbItm);
}


/*----------------------------------------------------------------------------*/
/* Recusrsive coordinates search                                              */
/*----------------------------------------------------------------------------*/

static OctSct *GetCrd(  OctSct *oct, itg MaxLvl, fpn VerCrd[3],
                        fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg SonIdx;
   fpn MidCrd[3], OctMin[3], OctMax[3], SonMin[3], SonMax[3];

   CpyVec(MinCrd, OctMin);
   CpyVec(MaxCrd, OctMax);

   // Search for the smallest octant containing
   // this vertex but stop at the grid level
   while(oct->sub && (oct->lvl < MaxLvl))
   {
      LinCmbVec3(.5, OctMin, .5, OctMax, MidCrd);

      SonIdx =    ((VerCrd[0] < MidCrd[0]) ? 0 : 1)
               |  ((VerCrd[1] < MidCrd[1]) ? 0 : 2)
               |  ((VerCrd[2] < MidCrd[2]) ? 0 : 4);

      SetSonCrd(SonIdx, SonMin, SonMax, OctMin, OctMax);
      CpyVec(SonMin, OctMin);
      CpyVec(SonMax, OctMax);
      oct = oct->son + SonIdx;
   }

   return(oct);
}


/*----------------------------------------------------------------------------*/
/* Recusrsive box search                                                      */
/*----------------------------------------------------------------------------*/

static void GetBox(  TreSct *tre, OctSct *oct, itg typ, itg *NmbItm,
                     itg MaxItm, itg *ItmTab, char *FlgTab, fpn box[2][3],
                     fpn eps, fpn MinCrd[3], fpn MaxCrd[3], itg ThrIdx )
{
   itg i;
   LnkSct *lnk;
   HexSct hex;
   OctThrSct *ThrOct = &tre->thr[ ThrIdx ];
   MshThrSct *ThrMsh = &tre->msh->thr[ ThrIdx ];
   fpn xmid = (MinCrd[0] + MaxCrd[0])/2.;
   fpn ymid = (MinCrd[1] + MaxCrd[1])/2.;
   fpn zmid = (MinCrd[2] + MaxCrd[2])/2.;
   fpn son[8][2][3] = {
      { {MinCrd[0], MinCrd[1], MinCrd[2]}, {xmid, ymid, zmid} },
      { {xmid, MinCrd[1], MinCrd[2]}, {MaxCrd[0], ymid, zmid} },
      { {MinCrd[0], ymid, MinCrd[2]}, {xmid, MaxCrd[1], zmid} },
      { {xmid, ymid, MinCrd[2]}, {MaxCrd[0], MaxCrd[1], zmid} },
      { {MinCrd[0], MinCrd[1], zmid}, {xmid, ymid, MaxCrd[2]} },
      { {xmid, MinCrd[1], zmid}, {MaxCrd[0], ymid, MaxCrd[2]} },
      { {MinCrd[0], ymid, zmid}, {xmid, MaxCrd[1], MaxCrd[2]} },
      { {xmid, ymid, zmid}, {MaxCrd[0], MaxCrd[1], MaxCrd[2]} } };

   if(oct->sub)
   {
      // Recursively intersect the box with the octree
      for(i=0;i<8;i++)
         if(BoxIntBox(box, son[i], eps))
            GetBox(  tre, oct->son+i, typ, NmbItm, MaxItm, ItmTab,
                     FlgTab, box, eps, son[i][0], son[i][1], ThrIdx );
   }
   else if((lnk = oct->lnk) && (*NmbItm < MaxItm) )
   {
      SetTmpHex(&ThrOct->hex, box[0], box[1]);

      // When a terminal octant is reached, add its linked entities
      // to the table and flag them to avoid duplicates
      do
      {
         if(lnk->typ != typ)
            continue;

         if(lnk->typ == LolTypVer)
         {
            SetItm(tre->msh, LolTypVer, lnk->idx, 0, ThrIdx);

            if(!VerInsHex(&ThrMsh->ver[0], &ThrOct->hex))
               continue;
         }
         else if(lnk->typ == LolTypEdg)
         {
            SetItm(tre->msh, LolTypEdg, lnk->idx, 0, ThrIdx);

            if(!EdgIntHex(&ThrMsh->edg, &ThrOct->hex, tre->eps))
               continue;
         }
         else if(lnk->typ == LolTypTri)
         {
            SetItm(tre->msh, LolTypTri, lnk->idx, TngFlg, ThrIdx);

            if(!TriIntHex(&ThrMsh->tri, &ThrOct->hex, tre->eps))
               continue;
         }
         else if(lnk->typ == LolTypQad)
         {
            SetItm(tre->msh, LolTypQad, lnk->idx, TngFlg, ThrIdx);

            if(!QadIntHex(&ThrMsh->qad, &ThrOct->hex, tre->eps))
               continue;
         }
         else if(lnk->typ == LolTypTet)
         {
            SetItm(tre->msh, LolTypTet, lnk->idx, TngFlg, ThrIdx);

            if(!TetIntHex(&ThrMsh->tet, &ThrOct->hex, tre->eps))
               continue;
         }

         if(!FlgTab[ lnk->idx ])
         {
            ItmTab[ (*NmbItm)++ ] = lnk->idx;
            FlgTab[ lnk->idx ] = 1;
         }
      }while( (lnk = lnk->nex) && (*NmbItm < MaxItm) );
   }
}


/*----------------------------------------------------------------------------*/
/* Search for the nearest item from a vertex in the octree                    */
/*----------------------------------------------------------------------------*/

itg LolGetNearest(int64_t OctIdx, itg typ, fpn *VerCrd, fpn *MinDis, fpn MaxDis,
                  itg (UsrPrc)(void *, itg), void *UsrDat, itg ThrIdx)
{
   TreSct     *tre = (TreSct *)OctIdx;
   itg         i, ins = 0, out = 0, MinItm = 0, ini[3], *tag, len;
   fpn         MinCrd[3], MaxCrd[3], vec[3];
   MshSct     *msh = tre->msh;
   BucSct     *IniBuc, *buc, *ngb, **stk;
   OctThrSct  *ThrOct = &tre->thr[ ThrIdx ];
   MshThrSct  *ThrMsh = &tre->msh->thr[ ThrIdx ];

   if( (ThrIdx < 0) || (ThrIdx >= tre->NmbThr) )
      return(0);

   ThrOct->tag++;
   ThrMsh->tag = ThrOct->tag;
   tag = ThrOct->ThrTag;
   stk = ThrOct->ThrStk;
   len = tre->NmbBuc;
   *MinDis = (MaxDis > 0.) ? POW(MaxDis) : DBL_MAX;

   // Get the vertex's integer coordinates in the grid
   // and clip it if it stands outside the bounding box
   for(i=0;i<3;i++)
   {
      ini[i] = (VerCrd[i] - tre->bnd[0][i]) / tre->BucSiz;
      ini[i] = MAX(0, ini[i]);
      ini[i] = MIN(len-1, ini[i]);
   }

   IniBuc = &tre->grd[ ini[0] * POW(len) + ini[1] * len + ini[2] ];

   // Push the octant containing the starting point on the lifo stack
   stk[ ins++ ] = IniBuc;
   tag[ IniBuc->idx ] = ThrOct->tag;

   // Flood fill processing of the grid : 
   // check octant's contents distance against the closest item
   while(ins > out)
   {
      buc = stk[ out++ ];
      GetBucBox(  tre, buc, MinCrd, MaxCrd );
      GetOctLnk(  msh, typ, VerCrd, &MinItm, MinDis, buc->oct,
                  MinCrd, MaxCrd, UsrPrc, UsrDat, ThrIdx );

      // Push unprocessed neighbours on the stack as long as they are not too far
      for(i=0;i<6;i++)
      {
         if( !(ngb = GetBucNgb(tre, buc, i)) || (tag[ ngb->idx ] == ThrOct->tag) )
            continue;

         GetBucBox(tre, ngb, MinCrd, MaxCrd);

         if(DisVerOct(VerCrd, MinCrd, MaxCrd) < *MinDis)
         {
            stk[ ins++ ] = ngb;
            tag[ ngb->idx ] = ThrOct->tag;
         }
      }
   }

   *MinDis = sqrt(*MinDis);

   return(MinItm);
}


/*----------------------------------------------------------------------------*/
/* Find the closest intersected triangle along a line                         */
/*----------------------------------------------------------------------------*/

itg LolIntersectSurface(int64_t OctIdx, fpn *VerCrd, fpn *VerTng, fpn *MinDis,
                        fpn MaxDis, itg (UsrPrc)(void *, itg), void *UsrDat,
                        itg ThrIdx )
{
   TreSct     *tre = (TreSct *)OctIdx;
   OctThrSct  *ThrOct = &tre->thr[ ThrIdx ];
   MshThrSct  *ThrMsh = &tre->msh->thr[ ThrIdx ];
   itg         i, ins=0, out=0, MinItm = 0, ini[3], *tag, len;
   fpn         MinCrd[3], MaxCrd[3], vec[3];
   MshSct     *msh = tre->msh;
   BucSct     *IniBuc, *buc, *ngb, **stk;

   ThrOct->tag++;
   ThrMsh->tag = ThrOct->tag;
   tag = ThrOct->ThrTag;
   stk = ThrOct->ThrStk;
   len = tre->NmbBuc;
   *MinDis = (MaxDis > 0.) ? POW(MaxDis) : DBL_MAX;

   // Get the vertex's integer coordinates in the grid
   // and clip it if it stands outside the bounding box
   for(i=0;i<3;i++)
   {
      ini[i] = (VerCrd[i] - tre->bnd[0][i]) / tre->BucSiz;
      ini[i] = MAX(0, ini[i]);
      ini[i] = MIN(tre->NmbBuc-1, ini[i]);
   }

   IniBuc = &tre->grd[ ini[0] * POW(len) + ini[1] * len + ini[2] ];

   // Push the octant containing the starting point on the lifo stack
   stk[ ins++ ] = IniBuc;
   tag[ IniBuc->idx ] = ThrOct->tag;

   // Flood fill processing of the grid : 
   // check octant's contents distance against the closest item
   while(ins > out)
   {
      buc = stk[ out++ ];
      GetBucBox(  tre, buc, MinCrd, MaxCrd);
      IntRayOct(  tre, msh, VerCrd, VerTng, &MinItm, MinDis, buc->oct,
                  MinCrd, MaxCrd, UsrPrc, UsrDat, ThrIdx );

      // Push unprocessed neighbours intersected by the line
      // on the stack as long as they are not too far
      for(i=0;i<6;i++)
      {
         if( !(ngb = GetBucNgb(tre, buc, i)) || (tag[ ngb->idx ] == ThrOct->tag) )
            continue;

         GetBucBox(tre, ngb, MinCrd, MaxCrd);

         if(!LinIntBox(VerCrd, VerTng, MinCrd, MaxCrd, tre->eps))
            continue;

         if(DisVerOct(VerCrd, MinCrd, MaxCrd) < *MinDis)
         {
            stk[ ins++ ] = ngb;
            tag[ ngb->idx ] = ThrOct->tag;
         }
      }
   }

   *MinDis = sqrt(*MinDis);

   return(MinItm);
}


/*----------------------------------------------------------------------------*/
/* Project a vertex on a given enitity: vertex, edge, triangle or quad        */
/*----------------------------------------------------------------------------*/

itg LolProjectVertex(int64_t OctIdx, fpn *VerCrd, itg typ,
                     itg MinItm, fpn *MinCrd, itg ThrIdx)
{
   TreSct     *tre = (TreSct *)OctIdx;
   OctThrSct  *ThrOct = &tre->thr[ ThrIdx ];
   MshThrSct  *ThrMsh = &tre->msh->thr[ ThrIdx ];
   MshSct     *msh = tre->msh;
   VerSct      TmpVer;
   TriSct     *tri;
   itg         i, EdgFlg = 0;
   fpn         CurDis, MinDis = DBL_MAX;

   if(typ == LolTypVer)
   {
      // Vertex case, there is only one possible projection:
      // the target vertex itself
      CpyVec((fpn *)GetPtrItm(msh, LolTypVer, MinItm), MinCrd);
      return(1);
   }
   else if(typ == LolTypEdg)
   {
      // Edge case, the closest position may be on the edge itself
      SetItm(msh, LolTypEdg, MinItm, 0, ThrIdx);
      PrjVerLin(VerCrd, ThrMsh->edg.ver[0]->crd, ThrMsh->edg.tng, TmpVer.crd);

      if(VerInsEdg(&ThrMsh->edg, &TmpVer, tre->eps))
      {
         CpyVec(TmpVer.crd, MinCrd);
         return(2);
      }

      // Or one of its two vertices
      if(dis(VerCrd, ThrMsh->edg.ver[0]->crd) < dis(VerCrd, ThrMsh->edg.ver[1]->crd))
         CpyVec(ThrMsh->edg.ver[0]->crd, MinCrd);
      else
         CpyVec(ThrMsh->edg.ver[1]->crd, MinCrd);

      return(1);
   }
   else if(typ == LolTypTri)
   {
      // Triangle case, the closest position may be on the triangle itself
      SetItm(msh, LolTypTri, MinItm, TngFlg, ThrIdx);
      PrjVerPla(VerCrd, ThrMsh->tri.ver[0]->crd, ThrMsh->tri.nrm, TmpVer.crd);

      if(VerInsTri(&ThrMsh->tri, &TmpVer, tre->eps))
      {
         CpyVec(TmpVer.crd, MinCrd);
         return(3); // the closest projection is inside the triangle
      }

      // Or fall inside one of its three edges
      for(i=0;i<3;i++)
      {
         PrjVerLin(  VerCrd, ThrMsh->tri.edg[i].ver[0]->crd,
                     ThrMsh->tri.edg[i].tng, TmpVer.crd );

         if(VerInsEdg(&ThrMsh->tri.edg[i], &TmpVer, tre->eps)
         && (dis(VerCrd, TmpVer.crd) < MinDis) )
         {
            MinDis = dis(VerCrd, TmpVer.crd);
            CpyVec(TmpVer.crd, MinCrd);
            EdgFlg = 2;
         }
      }

      // Or one of the three vertices
      for(i=0;i<3;i++)
      {
         CurDis = dis(VerCrd, ThrMsh->tri.ver[i]->crd);

         if(CurDis < MinDis)
         {
            MinDis = CurDis;
            CpyVec(ThrMsh->tri.ver[i]->crd, MinCrd);
            EdgFlg = 0;
         }
      }

      if(EdgFlg)
         return(2); // the closest projection is on an edge
      else
         return(1); // the closest projection is on a vertex
   }
   else if(typ == LolTypQad)
   {
      SetItm(msh, LolTypQad, MinItm, TngFlg, ThrIdx);

      // Compute the projection on the two triangles
      for(i=0;i<2;i++)
      {
         tri = &ThrMsh->qad.tri[i];
         PrjVerPla(VerCrd, tri->ver[0]->crd, tri->nrm, TmpVer.crd);

         if(VerInsTri(tri, &TmpVer, tre->eps))
         {
            CpyVec(TmpVer.crd, MinCrd);
            return(3); // the closest projection is inside the quad
         }
      }

      // Check the projections on the four edges
      for(i=0;i<4;i++)
      {
         PrjVerLin(  VerCrd, ThrMsh->qad.edg[i].ver[0]->crd,
                     ThrMsh->qad.edg[i].tng, TmpVer.crd );

         if(VerInsEdg(&ThrMsh->qad.edg[i], &TmpVer, tre->eps)
         && (dis(VerCrd, TmpVer.crd) < MinDis) )
         {
            MinDis = dis(VerCrd, TmpVer.crd);
            CpyVec(TmpVer.crd, MinCrd);
            EdgFlg = 2;
         }
      }

      // Or one of the four vertices
      for(i=0;i<4;i++)
      {
         CurDis = dis(VerCrd, ThrMsh->qad.ver[i]->crd);

         if(CurDis < MinDis)
         {
            MinDis = CurDis;
            CpyVec(ThrMsh->qad.ver[i]->crd, MinCrd);
            EdgFlg = 0;
         }
      }

      if(EdgFlg)
         return(2); // the closest projection is on an edge
      else
         return(1); // the closest projection is on a vertex
   }
   else
      return(0);
}


/*----------------------------------------------------------------------------*/
/* Extract the bounding box from a grid's bucket                              */
/*----------------------------------------------------------------------------*/

static void GetBucBox(  TreSct *tre, BucSct *buc,
                        fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg i;

   for(i=0;i<3;i++)
   {
      MinCrd[i] = tre->bnd[0][i] + buc->pos[i] * tre->BucSiz;
      MaxCrd[i] = tre->bnd[0][i] + (buc->pos[i]+1) * tre->BucSiz;
   }

}


/*----------------------------------------------------------------------------*/
/* Get a bucket's neighbour from the grid                                     */
/*----------------------------------------------------------------------------*/

static BucSct *GetBucNgb(TreSct *tre, BucSct *buc, itg dir)
{
   if( (dir == 0) && (buc->pos[0] > 0) )
      return(&tre->grd[ (buc->pos[0]-1) * POW(tre->NmbBuc)
            + buc->pos[1] * tre->NmbBuc + buc->pos[2] ]);

   if( (dir == 1) && (buc->pos[0] < tre->NmbBuc-1) )
      return(&tre->grd[ (buc->pos[0]+1) * POW(tre->NmbBuc)
            + buc->pos[1] * tre->NmbBuc + buc->pos[2] ]);

   if( (dir == 2) && (buc->pos[1] > 0) )
      return(&tre->grd[ buc->pos[0] * POW(tre->NmbBuc)
            + (buc->pos[1]-1) * tre->NmbBuc + buc->pos[2] ]);

   if( (dir == 3) && (buc->pos[1] < tre->NmbBuc-1) )
      return(&tre->grd[ buc->pos[0] * POW(tre->NmbBuc)
            + (buc->pos[1]+1) * tre->NmbBuc + buc->pos[2] ]);

   if( (dir == 4) && (buc->pos[2] > 0) )
      return(&tre->grd[ buc->pos[0] * POW(tre->NmbBuc)
            + buc->pos[1] * tre->NmbBuc + buc->pos[2]-1 ]);

   if( (dir == 5) && (buc->pos[2] < tre->NmbBuc-1) )
      return(&tre->grd[ buc->pos[0] * POW(tre->NmbBuc)
            + buc->pos[1] * tre->NmbBuc + buc->pos[2]+1 ]);

   return(NULL);
}


/*----------------------------------------------------------------------------*/
/* Compute the distance between a point and an octant                         */
/*----------------------------------------------------------------------------*/

static fpn DisVerOct(fpn VerCrd[3], fpn MinCrd[3], fpn MaxCrd[3])
{
   itg i;
   fpn ClpCrd[3];

   // Project the vertex on the octant's surface
   for(i=0;i<3;i++)
   {
      ClpCrd[i] = MAX(VerCrd[i], MinCrd[i]);
      ClpCrd[i] = MIN(ClpCrd[i], MaxCrd[i]);
   }

   // The distance between the projection and the vertex is the shortest
   // if this latter stands OUTSIDE the octant
   return(DisPow(ClpCrd, VerCrd));
}


/*----------------------------------------------------------------------------*/
/* Search for the nearest item from a vertex from an octant                   */
/*----------------------------------------------------------------------------*/

static void GetOctLnk(  MshSct *msh, itg typ, fpn VerCrd[3], itg *MinItm,
                        fpn *MinDis, OctSct *oct, fpn MinCrd[3], fpn MaxCrd[3],
                        itg (UsrPrc)(void *, itg), void *UsrDat, itg ThrIdx )
{
   itg         i, *IdxTab;
   fpn         CurDis, SonMin[3], SonMax[3];
   LnkSct     *lnk;
   MshThrSct  *ThrMsh = &msh->thr[ ThrIdx ];

   if(oct->sub)
   {
      // Check each sons recursively as long as the minimum distance
      // between the vertex and the octant is lower than
      // the current distance from the closest entity
      for(i=0;i<8;i++)
      {
         SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);

         if(DisVerOct(VerCrd, SonMin, SonMax) <= *MinDis)
            GetOctLnk(  msh, typ, VerCrd, MinItm, MinDis, oct->son + i,
                        SonMin, SonMax, UsrPrc, UsrDat, ThrIdx );
      }
   }
   else if((lnk = oct->lnk))
   {
      // When a leaf octant is reached, compute the distance
      // between its linked enities and the vertex
      do
      {
         if(lnk->typ != typ)
            continue;

         if(lnk->typ == LolTypVer)
            CurDis = DisPow(VerCrd, (fpn *)GetPtrItm(msh, LolTypVer, lnk->idx));
         else if(lnk->typ == LolTypEdg)
         {
            SetItm(msh, LolTypEdg, lnk->idx, 0, ThrIdx);
            CurDis = DisVerEdg(VerCrd, &ThrMsh->edg);
         }
         else if(lnk->typ == LolTypTri)
         {
            if(ThrMsh->TagTab[ lnk->idx ] == ThrMsh->tag)
               continue;

            ThrMsh->TagTab[ lnk->idx ] = ThrMsh->tag;

            if(UsrPrc && !UsrPrc(UsrDat, lnk->idx))
               continue;

            SetItm(msh, LolTypTri, lnk->idx, 0, ThrIdx);
            CurDis = DisVerTri(msh, VerCrd, &ThrMsh->tri);
         }
         else if(lnk->typ == LolTypQad)
         {
            if(ThrMsh->TagTab[ lnk->idx ] == ThrMsh->tag)
               continue;

            ThrMsh->TagTab[ lnk->idx ] = ThrMsh->tag;

            if(UsrPrc && !UsrPrc(UsrDat, lnk->idx))
               continue;

            SetItm(msh, LolTypQad, lnk->idx, 0, ThrIdx);
            CurDis = DisVerQad(msh, VerCrd, &ThrMsh->qad);
         }
         else if(lnk->typ == LolTypTet)
         {
            SetItm(msh, LolTypTet, lnk->idx, 0, ThrIdx);
            CurDis = DisVerTet(msh, VerCrd, &ThrMsh->tet);
         }

         if(CurDis < *MinDis)
         {
            *MinItm = lnk->idx;
            *MinDis = CurDis;
         }
      }while((lnk = lnk->nex));
   }
}


/*----------------------------------------------------------------------------*/
/* Search for the nearest triangle instersected by a line                     */
/*----------------------------------------------------------------------------*/

static void IntRayOct(  TreSct *tre, MshSct *msh, fpn *crd, fpn *tng,
                        itg *MinItm, fpn *MinDis, OctSct *oct, fpn MinCrd[3],
                        fpn MaxCrd[3], itg (UsrPrc)(void *, itg), void *UsrDat,
                        itg ThrIdx )
{
   itg         i, *IdxTab;
   fpn         CurDis, SonMin[3], SonMax[3];
   VerSct      IntVer;
   LnkSct     *lnk;
   MshThrSct  *ThrMsh = &tre->msh->thr[ ThrIdx ];

   if(oct->sub)
   {
      // Check each sons recursively as long as the minimum distance
      // between the vertex and the octant is lower than
      // the current distance from the closest entity
      for(i=0;i<8;i++)
      {
         SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);

         if(!LinIntBox(crd, tng, SonMin, SonMax, msh->eps))
            continue;

         IntRayOct(  tre, msh, crd, tng, MinItm, MinDis, oct->son+i,
                     SonMin, SonMax, UsrPrc, UsrDat, ThrIdx );
      }
   }
   else if((lnk = oct->lnk))
   {
      // When a leaf octant is reached, compute the intersection
      // between its linked triangles and the line
      do
      {
         if(lnk->typ != LolTypTri)
            continue;

         if(ThrMsh->TagTab[ lnk->idx ] == ThrMsh->tag)
            continue;

         ThrMsh->TagTab[ lnk->idx ] = ThrMsh->tag;
         SetItm(msh, LolTypTri, lnk->idx, 0, ThrIdx);

         if(UsrPrc && !UsrPrc(UsrDat, lnk->idx))
            continue;

         if(DotPrd(tng, ThrMsh->tri.nrm) != 0.)
         {
            LinIntPla(  crd, tng, ThrMsh->tri.ver[0]->crd,
                        ThrMsh->tri.nrm, IntVer.crd );

            if(VerInsTri(&ThrMsh->tri, &IntVer, msh->eps))
            {
               CurDis = DisPow(IntVer.crd, crd);

               if(CurDis < *MinDis)
               {
                  *MinItm = lnk->idx;
                  *MinDis = CurDis;
               }
            }
         }
      }while((lnk = lnk->nex));
   }
}


/*----------------------------------------------------------------------------*/
/* Setup an arbitrary geometrical item structure from its index               */
/*----------------------------------------------------------------------------*/

static void SetItm(MshSct *msh, itg typ, itg idx, itg flg, itg ThrIdx)
{
   itg         i, j, *IdxTab;
   const itg   TetEdgFac[6][2] = { {2,3}, {1,3}, {1,2}, {0,3}, {0,2}, {0,1} };
   MshThrSct  *ThrMsh = &msh->thr[ ThrIdx ];

   if(typ == LolTypVer)
   {
      ThrMsh->ver[0].idx = idx;
      CpyVec((fpn *)GetPtrItm(msh, typ, idx), ThrMsh->ver[0].crd);
   }
   else if(typ == LolTypEdg)
   {
      // Setup the temporary edge structure with this edge's ID
      ThrMsh->edg.idx = idx;
      IdxTab = (itg *)GetPtrItm(msh, typ, idx);

      for(i=0;i<2;i++)
         CpyVec((fpn *)GetPtrItm(msh, LolTypVer, IdxTab[i]), ThrMsh->edg.ver[i]->crd);

      SetEdgTng(&ThrMsh->edg);
   }
   else if(typ == LolTypTri)
   {
      // Setup the temporary triangle structure with this triangle's ID
      ThrMsh->tri.idx = idx;
      IdxTab = (itg *)GetPtrItm(msh, typ, idx);

      for(i=0;i<3;i++)
         CpyVec((fpn *)GetPtrItm(msh, LolTypVer, IdxTab[i]), ThrMsh->tri.ver[i]->crd);

      SetTriNrm(&ThrMsh->tri);

      // Set triangle edge tangents only on request
      if(flg & TngFlg)
         for(i=0;i<3;i++)
            SetEdgTng(&ThrMsh->tri.edg[i]);

      // Compute the aspect ratio on demand
      if(flg & AniFlg)
         ThrMsh->tri.ani = GetTriAni(&ThrMsh->tri);
   }
   else if(typ == LolTypQad)
   {
      // Setup the temporary triangle structure with this triangle's ID
      ThrMsh->qad.idx = idx;
      IdxTab = (itg *)GetPtrItm(msh, typ, idx);

      for(i=0;i<4;i++)
         CpyVec((fpn *)GetPtrItm(msh, LolTypVer, IdxTab[i]), ThrMsh->qad.ver[i]->crd);

      // Set quad edge tangents only on request
      if(flg & TngFlg)
         for(i=0;i<4;i++)
            SetEdgTng(&ThrMsh->qad.edg[i]);

      for(i=0;i<2;i++)
      {
         SetTriNrm(&ThrMsh->qad.tri[i]);

         // Set triangle edge tangents only on request
         if(flg & TngFlg)
            for(j=0;j<3;j++)
               SetEdgTng(&ThrMsh->qad.tri[i].edg[j]);

         // Compute the aspect ratio on demand
         if(flg & AniFlg)
            ThrMsh->tri.ani = GetTriAni(&ThrMsh->qad.tri[i]);
      }
   }
   else if(typ == LolTypTet)
   {
      // Setup the temporary tetrahedron structure with this tet ID
      ThrMsh->tet.idx = idx;
      IdxTab = (itg *)GetPtrItm(msh, typ, idx);

      for(i=0;i<4;i++)
         CpyVec((fpn *)GetPtrItm(msh, LolTypVer, IdxTab[i]), ThrMsh->tet.ver[i]->crd);

      for(i=0;i<4;i++)
         SetTriNrm(&ThrMsh->tet.tri[i]);

      // Set tet edge tangents only on request
      if(flg & TngFlg)
         for(i=0;i<6;i++)
         {
            SetEdgTng(&ThrMsh->tet.edg[i]);
            CpyVec(ThrMsh->tet.edg[i].tng, ThrMsh->tet.tri[ TetEdgFac[i][0] ].edg[0].tng);
            CpyVec(ThrMsh->tet.edg[i].tng, ThrMsh->tet.tri[ TetEdgFac[i][1] ].edg[1].tng);
         }
   }
}


/*----------------------------------------------------------------------------*/
/* Save the local mesh entities into their backup position                    */
/*----------------------------------------------------------------------------*/

static void BakMshItm(MshSct *msh)
{
   memcpy(&msh->thr[0].BakEdg, &msh->thr[0].edg, sizeof(EdgSct));
   memcpy(&msh->thr[0].BakTri, &msh->thr[0].tri, sizeof(TriSct));
   memcpy(&msh->thr[0].BakQad, &msh->thr[0].qad, sizeof(QadSct));
   memcpy(&msh->thr[0].BakTet, &msh->thr[0].tet, sizeof(TetSct));
   memcpy( msh->thr[0].BakVer,  msh->thr[0].ver, 4 * sizeof(VerSct));
}


/*----------------------------------------------------------------------------*/
/* Restore the local entities from the backup to the current position         */
/*----------------------------------------------------------------------------*/

static void RstMshItm(MshSct *msh)
{
   memcpy(&msh->thr[0].edg, &msh->thr[0].BakEdg, sizeof(EdgSct));
   memcpy(&msh->thr[0].tri, &msh->thr[0].BakTri, sizeof(TriSct));
   memcpy(&msh->thr[0].qad, &msh->thr[0].BakQad, sizeof(QadSct));
   memcpy(&msh->thr[0].tet, &msh->thr[0].BakTet, sizeof(TetSct));
   memcpy( msh->thr[0].ver,  msh->thr[0].BakVer, 4 * sizeof(VerSct));
}


/*----------------------------------------------------------------------------*/
/* Get a geometric item adress in the user's table                            */
/*----------------------------------------------------------------------------*/

static char *GetPtrItm(MshSct *msh, itg typ, itg idx)
{
   return(msh->UsrPtr[ typ ] + (idx - msh->BasIdx) * msh->UsrSiz[ typ ]);
}


/*----------------------------------------------------------------------------*/
/* Create a mesh with one hexa enclosing the whole surface                    */
/*----------------------------------------------------------------------------*/

static void SetMshBox(TreSct *box, MshSct *msh)
{
   itg i, j;
   fpn MinCrd[3], MaxCrd[3], MidCrd[3], *CrdTab, siz;

   // Compute the bounding box (rectangular)
   CpyVec((fpn *)GetPtrItm(msh, LolTypVer, msh->BasIdx), MinCrd);
   CpyVec((fpn *)GetPtrItm(msh, LolTypVer, msh->BasIdx), MaxCrd);

   for(i=1;i<msh->NmbItm[ LolTypVer ];i++)
   {
      CrdTab = (fpn *)GetPtrItm(msh, LolTypVer, i + msh->BasIdx);

      for(j=0;j<3;j++)
      {
         MinCrd[j] = MIN(MinCrd[j], CrdTab[j]);
         MaxCrd[j] = MAX(MaxCrd[j], CrdTab[j]);
      }
   }

   // Compute the bounding box
   siz = MAX(MaxCrd[0] - MinCrd[0], MaxCrd[1] - MinCrd[1]);
   siz = MAX(siz, MaxCrd[2] - MinCrd[2]);
   box->eps = siz * FLT_EPSILON;
   box->MinSiz = box->MaxSiz = siz;

   // Move the center 1/1000th away
   LinCmbVec3(.5, MinCrd, .5, MaxCrd, MidCrd);
   AddScaVec1(siz * FLT_EPSILON, MidCrd);
   AddScaVec2(-1.02 * siz / 2., MidCrd, box->bnd[0]);
   AddScaVec2( 1.02 * siz / 2., MidCrd, box->bnd[1]);
}


/*----------------------------------------------------------------------------*/
/* Add a vertex to leaf octants                                               */
/*----------------------------------------------------------------------------*/

static void AddVer(  MshSct *msh, TreSct *tre, OctSct *oct,
                     fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg i;
   fpn SonMin[3], SonMax[3];

   if(oct->sub)
   {
      for(i=0;i<8;i++)
      {
         SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);

         if(VerInsOct(msh->thr[0].ver[0].crd, SonMin, SonMax))
            AddVer(msh, tre, oct->son+i, SonMin, SonMax);
      }
   }
   else
   {
      LnkItm(tre, oct, LolTypVer, msh->thr[0].ver[0].idx, 0);

      if((oct->lvl < tre->GrdLvl)
      || ((oct->NmbVer >= oct->MaxItm) && (oct->lvl < MaxOctLvl)) )
      {
         SubOct(msh, tre, oct, MinCrd, MaxCrd);
      }
   }
}


/*----------------------------------------------------------------------------*/
/* Add an edge to leaf octants                                                */
/*----------------------------------------------------------------------------*/

static void AddEdg(  MshSct *msh, TreSct *tre, OctSct *oct,
                     fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg i;
   fpn SonMin[3], SonMax[3];

   if(oct->sub)
   {
      for(i=0;i<8;i++)
      {
         SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
         SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

         if(EdgIntHex(&msh->thr[0].edg, &tre->thr[0].hex, tre->eps))
            AddEdg(msh, tre, oct->son+i, SonMin, SonMax);
      }
   }
   else
   {
      LnkItm(tre, oct, LolTypEdg, msh->thr[0].edg.idx, 0);

      if( (oct->lvl < tre->GrdLvl)
      || ((oct->NmbEdg >= oct->MaxItm) && (oct->lvl < MaxOctLvl)) )
      {
         SubOct(msh, tre, oct, MinCrd, MaxCrd);
      }
   }
}


/*----------------------------------------------------------------------------*/
/* Add a triangle to leaf octants                                             */
/*----------------------------------------------------------------------------*/

static void AddTri(  MshSct *msh, TreSct *tre, OctSct *oct,
                     fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg i;
   fpn SonMin[3], SonMax[3];

   if(oct->sub)
   {
      for(i=0;i<8;i++)
      {
         SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
         SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

         if(TriIntHex(&msh->thr[0].tri, &tre->thr[0].hex, tre->eps))
            AddTri(msh, tre, oct->son+i, SonMin, SonMax);
      }
   }
   else
   {
      LnkItm(tre, oct, LolTypTri, msh->thr[0].tri.idx, msh->thr[0].tri.ani);

      if( (oct->lvl < tre->GrdLvl)
      || ((oct->NmbFac >= oct->MaxItm) && (oct->lvl < MaxOctLvl)) )
      {
         SubOct(msh, tre, oct, MinCrd, MaxCrd);
      }
   }
}


/*----------------------------------------------------------------------------*/
/* Add a quad to leaf octants                                                 */
/*----------------------------------------------------------------------------*/

static void AddQad(  MshSct *msh, TreSct *tre, OctSct *oct,
                     fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg i;
   fpn SonMin[3], SonMax[3];

   if(oct->sub)
   {
      for(i=0;i<8;i++)
      {
         SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
         SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

         if(QadIntHex(&msh->thr[0].qad, &tre->thr[0].hex, tre->eps))
            AddQad(msh, tre, oct->son+i, SonMin, SonMax);
      }
   }
   else
   {
      LnkItm(tre, oct, LolTypQad, msh->thr[0].qad.idx, 0);

      if( (oct->lvl < tre->GrdLvl)
      || ((oct->NmbFac >= oct->MaxItm) && (oct->lvl < MaxOctLvl)) )
      {
         SubOct(msh, tre, oct, MinCrd, MaxCrd);
      }
   }
}


/*----------------------------------------------------------------------------*/
/* Add a tetrahedron to leaf octants                                          */
/*----------------------------------------------------------------------------*/

static void AddTet(  MshSct *msh, TreSct *tre, OctSct *oct,
                     fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg i;
   fpn SonMin[3], SonMax[3];

   if(oct->sub)
   {
      for(i=0;i<8;i++)
      {
         SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
         SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

         if(TetIntHex(&msh->thr[0].tet, &tre->thr[0].hex, tre->eps))
            AddTet(msh, tre, oct->son+i, SonMin, SonMax);
      }
   }
   else
   {
      LnkItm(tre, oct, LolTypTet, msh->thr[0].tet.idx, msh->thr[0].tet.ani);

      if( (oct->lvl < tre->GrdLvl)
      || ((oct->NmbFac >= oct->MaxItm) && (oct->lvl < MaxOctLvl)) )
      {
         SubOct(msh, tre, oct, MinCrd, MaxCrd);
      }
   }
}


/*----------------------------------------------------------------------------*/
/* Subdivide an octant and its content to its sons                            */
/*----------------------------------------------------------------------------*/

static void SubOct(  MshSct *msh, TreSct *tre, OctSct *oct,
                     fpn MinCrd[3], fpn MaxCrd[3] )
{
   itg i, j, *IdxTab;
   fpn SonMin[3], SonMax[3];
   LnkSct *lnk , *OctLnk = oct->lnk;
   OctSct *son;

   // If there is no more free octants, allocate a new bloc
   if(!tre->NmbFreOct)
   {
      tre->CurOctBlk = NewMem(tre, MemBlkSiz * 8 * sizeof(OctSct));
      tre->NmbFreOct = MemBlkSiz;
   }

   // The octant points on its first son, the other are consectutive in memory
   oct->son = &tre->CurOctBlk[ (MemBlkSiz - tre->NmbFreOct--) * 8 ];
   oct->sub = 1;
   tre->NmbOct+=8;

   // Initialize each sons
   for(i=0;i<8;i++)
   {
      son = oct->son+i;
      son->lnk = NULL;
      son->son = NULL;
      son->NmbVer = son->NmbEdg = son->NmbFac = son->NmbVol = 0;
      son->ani = 1;
      son->MaxItm = MaxItmOct;
      son->sub = 0;
      son->lvl = oct->lvl + 1;
   }

   // Update octree min octant size and max level
   tre->MinSiz = MIN(tre->MinSiz, (MaxCrd[0] - MinCrd[0])/2.);
   tre->MaxLvl = MAX(tre->MaxLvl, oct->lvl+1);

   // Backup the curent mesh local entities that are being tested
   // as the propagation process will call SetItm an all linked items
   BakMshItm(msh);

   // Now unlink every items from the father and add them to its sons
   while((lnk = OctLnk))
   {
      if(lnk->typ == LolTypVer)
      {
         // Check inclusion of vertices among the 8 sons
         SetItm(msh, LolTypVer, lnk->idx, 0, 0);

         for(i=0;i<8;i++)
         {
            SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);

            if(VerInsOct(msh->thr[0].ver[0].crd, SonMin, SonMax))
               LnkItm(tre, oct->son+i, LolTypVer, lnk->idx, 0);
         }
      }
      else if(lnk->typ == LolTypEdg)
      {
         // Check the intersection between edge and the 8 sons
         SetItm(msh, LolTypEdg, lnk->idx, 0, 0);

         for(i=0;i<8;i++)
         {
            SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
            SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

            if(EdgIntHex(&msh->thr[0].edg, &tre->thr[0].hex, tre->eps))
               LnkItm(tre, oct->son+i, LolTypEdg, lnk->idx, 0);
         }
      }
      else if(lnk->typ == LolTypTri)
      {
         // Check the intersection between the triangle and the 8 sons
         SetItm(msh, LolTypTri, lnk->idx, TngFlg | AniFlg, 0);

         for(i=0;i<8;i++)
         {
            SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
            SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

            if(TriIntHex(&msh->thr[0].tri, &tre->thr[0].hex, tre->eps))
               LnkItm(tre, oct->son+i, LolTypTri, lnk->idx, oct->ani);
         }
      }
      else if(lnk->typ == LolTypQad)
      {
         // Check the intersection between the quad and the 8 sons
         SetItm(msh, LolTypQad, lnk->idx, TngFlg | AniFlg, 0);

         for(i=0;i<8;i++)
         {
            SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
            SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

            if(QadIntHex(&msh->thr[0].qad, &tre->thr[0].hex, tre->eps))
               LnkItm(tre, oct->son+i, LolTypQad, lnk->idx, oct->ani);
         }
      }
      else if(lnk->typ == LolTypTet)
      {
         // Check the intersection between the tet and the 8 sons
         SetItm(msh, LolTypTet, lnk->idx, TngFlg, 0);

         for(i=0;i<8;i++)
         {
            SetSonCrd(i, SonMin, SonMax, MinCrd, MaxCrd);
            SetTmpHex(&tre->thr[0].hex, SonMin, SonMax);

            if(TetIntHex(&msh->thr[0].tet, &tre->thr[0].hex, tre->eps))
               LnkItm(tre, oct->son+i, LolTypTet, lnk->idx, oct->ani);
         }
      }

      OctLnk = lnk->nex;
      lnk->nex = tre->NexFreLnk;
      tre->NexFreLnk = lnk;
   }

   // Put back the current mesh enities that are being inserted
   RstMshItm(msh);
}


/*----------------------------------------------------------------------------*/
/* Add an entity to an octant linked list                                     */
/*----------------------------------------------------------------------------*/

static void LnkItm(TreSct *tre, OctSct *oct, itg typ, itg idx, char ani)
{
   itg i;
   LnkSct *lnk;


   lnk = oct->lnk;
   while(lnk)
   {
      if(lnk->typ == typ && lnk->idx == idx)
         return;
      lnk = lnk->nex;
   }


   // In case nore more link container are availbable, allocate a new bloc
   if(!tre->NexFreLnk)
   {
      tre->NexFreLnk = NewMem(tre, MemBlkSiz * sizeof(LnkSct));

      for(i=0;i<MemBlkSiz;i++)
         tre->NexFreLnk[i].nex = &tre->NexFreLnk[ i+1 ];

      tre->NexFreLnk[ MemBlkSiz - 1 ].nex = NULL;
   }

   // Get the next free link container and set it with the given item
   lnk = tre->NexFreLnk;
   tre->NexFreLnk = lnk->nex;
   lnk->typ = typ;
   lnk->idx = idx;
   lnk->nex = oct->lnk;
   oct->lnk = lnk;

   // Update the octant local counters
   if(typ == LolTypVer)
      oct->NmbVer++;
   else if(typ == LolTypEdg)
      oct->NmbEdg++;
   else if( (typ == LolTypTri) || (typ == LolTypQad) )
   {
      // Update the octant mean anisotropic factor
      // and deduce a max number of item form it
      if(typ == LolTypTri)
      {
         oct->ani = (oct->ani * oct->NmbFac + ani) / (oct->NmbFac + 1);
         oct->MaxItm = MIN(MaxItmOct * ani, 255);
      }

      oct->NmbFac++;
   }
   else
      oct->NmbVol++;
}


/*----------------------------------------------------------------------------*/
/* Build an octant strucutre from the two corner points                       */
/*----------------------------------------------------------------------------*/

static void SetSonCrd(  itg SonIdx, fpn SonMin[3], fpn SonMax[3],
                        fpn MinCrd[3], fpn MaxCrd[3] )
{
   fpn MidCrd[3];

   LinCmbVec3(.5, MinCrd, .5, MaxCrd, MidCrd);

   switch(SonIdx)
   {
      case 0 : {
         SonMin[0] = MinCrd[0];
         SonMin[1] = MinCrd[1];
         SonMin[2] = MinCrd[2];
         SonMax[0] = MidCrd[0];
         SonMax[1] = MidCrd[1];
         SonMax[2] = MidCrd[2];
      }return;

      case 1 : {
         SonMin[0] = MidCrd[0];
         SonMin[1] = MinCrd[1];
         SonMin[2] = MinCrd[2];
         SonMax[0] = MaxCrd[0];
         SonMax[1] = MidCrd[1];
         SonMax[2] = MidCrd[2];
      }return;

      case 2 : {
         SonMin[0] = MinCrd[0];
         SonMin[1] = MidCrd[1];
         SonMin[2] = MinCrd[2];
         SonMax[0] = MidCrd[0];
         SonMax[1] = MaxCrd[1];
         SonMax[2] = MidCrd[2];
      }return;

      case 3 : {
         SonMin[0] = MidCrd[0];
         SonMin[1] = MidCrd[1];
         SonMin[2] = MinCrd[2];
         SonMax[0] = MaxCrd[0];
         SonMax[1] = MaxCrd[1];
         SonMax[2] = MidCrd[2];
      }return;

      case 4 : {
         SonMin[0] = MinCrd[0];
         SonMin[1] = MinCrd[1];
         SonMin[2] = MidCrd[2];
         SonMax[0] = MidCrd[0];
         SonMax[1] = MidCrd[1];
         SonMax[2] = MaxCrd[2];
      }return;

      case 5 : {
         SonMin[0] = MidCrd[0];
         SonMin[1] = MinCrd[1];
         SonMin[2] = MidCrd[2];
         SonMax[0] = MaxCrd[0];
         SonMax[1] = MidCrd[1];
         SonMax[2] = MaxCrd[2];
      }return;

      case 6 : {
         SonMin[0] = MinCrd[0];
         SonMin[1] = MidCrd[1];
         SonMin[2] = MidCrd[2];
         SonMax[0] = MidCrd[0];
         SonMax[1] = MaxCrd[1];
         SonMax[2] = MaxCrd[2];
      }return;

      case 7 : {
         SonMin[0] = MidCrd[0];
         SonMin[1] = MidCrd[1];
         SonMin[2] = MidCrd[2];
         SonMax[0] = MaxCrd[0];
         SonMax[1] = MaxCrd[1];
         SonMax[2] = MaxCrd[2];
      }return;
   }
}


/*----------------------------------------------------------------------------*/
/* Test if a vertex is inside an octant                                       */
/*----------------------------------------------------------------------------*/

static itg VerInsOct(fpn VerCrd[3], fpn MinCrd[3], fpn MaxCrd[3])
{
   itg i;

   for(i=0;i<3;i++)
      if( (VerCrd[i] > MaxCrd[i]) || (VerCrd[i] < MinCrd[i]) )
         return(0);

   return(1);
}


/*----------------------------------------------------------------------------*/
/* Setup a temporary test hex from the bounding box limits                    */
/*----------------------------------------------------------------------------*/

static void SetTmpHex(HexSct *hex, fpn MinCrd[3], fpn MaxCrd[3])
{
   hex->ver[0]->crd[0] = MinCrd[0];
   hex->ver[0]->crd[1] = MinCrd[1];
   hex->ver[0]->crd[2] = MaxCrd[2];
   hex->ver[1]->crd[0] = MaxCrd[0];
   hex->ver[1]->crd[1] = MinCrd[1];
   hex->ver[1]->crd[2] = MaxCrd[2];
   hex->ver[2]->crd[0] = MaxCrd[0];
   hex->ver[2]->crd[1] = MinCrd[1];
   hex->ver[2]->crd[2] = MinCrd[2];
   hex->ver[3]->crd[0] = MinCrd[0];
   hex->ver[3]->crd[1] = MinCrd[1];
   hex->ver[3]->crd[2] = MinCrd[2];
   hex->ver[4]->crd[0] = MinCrd[0];
   hex->ver[4]->crd[1] = MaxCrd[1];
   hex->ver[4]->crd[2] = MaxCrd[2];
   hex->ver[5]->crd[0] = MaxCrd[0];
   hex->ver[5]->crd[1] = MaxCrd[1];
   hex->ver[5]->crd[2] = MaxCrd[2];
   hex->ver[6]->crd[0] = MaxCrd[0];
   hex->ver[6]->crd[1] = MaxCrd[1];
   hex->ver[6]->crd[2] = MinCrd[2];
   hex->ver[7]->crd[0] = MinCrd[0];
   hex->ver[7]->crd[1] = MaxCrd[1];
   hex->ver[7]->crd[2] = MinCrd[2];
}


/*----------------------------------------------------------------------------*/
/* Compute/test the intersection between a line and a cube                    */
/*----------------------------------------------------------------------------*/

static itg LinIntBox(fpn *LinCrd, fpn *LinTng,
                     fpn *BoxMin, fpn *BoxMax, fpn eps)
{
   itg i;
   fpn IntCrd[3], NrmTab[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };

   // Compute the intersections between the edge and the cube's faces
   for(i=0;i<3;i++)
   {
      if(LinTng[i] == 0.)
         continue;

      LinIntPla(LinCrd, LinTng, BoxMin, NrmTab[i], IntCrd);

      if(VerInsBox(IntCrd, BoxMin, BoxMax, eps))
         return(1);

      LinIntPla(LinCrd, LinTng, BoxMax, NrmTab[i], IntCrd);

      if(VerInsBox(IntCrd, BoxMin, BoxMax, eps))
         return(1);
   }

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Compute the intersection between a line and a plane                        */
/*----------------------------------------------------------------------------*/

static void LinIntPla(  fpn *LinCrd, fpn *LinTng,
                        fpn *PlaCrd, fpn *PlaNrm, fpn *IntCrd)
{
   fpn u[3];

   SubVec3(LinCrd, PlaCrd, u);
   LinCmbVec3( 1., LinCrd, -DotPrd(PlaNrm, u) / DotPrd(PlaNrm, LinTng),
               LinTng, IntCrd);
}


/*----------------------------------------------------------------------------*/
/* Test if a vertex stands inside a bounding box + epsilon                    */
/*----------------------------------------------------------------------------*/

static fpn VerInsBox(fpn *VerCrd, fpn *BoxMin, fpn *BoxMax, fpn eps)
{
   if((VerCrd[0] < BoxMin[0] - eps) || (VerCrd[1] < BoxMin[1] - eps)
   || (VerCrd[2] < BoxMin[2] - eps) || (VerCrd[0] > BoxMax[0] + eps)
   || (VerCrd[1] > BoxMax[1] + eps) || (VerCrd[2] > BoxMax[2] + eps) )
   {
      return(0);
   }

   return(1);
}


/*----------------------------------------------------------------------------*/
/* Compute/test the intersection between an edge and a hex                    */
/*----------------------------------------------------------------------------*/

static itg EdgIntHex(EdgSct *edg, HexSct *hex, fpn eps)
{
   itg i;
   VerSct IntVer;

   // Test if an edge's vertex is included in the octant
   if(VerInsHex(edg->ver[0], hex) || VerInsHex(edg->ver[1], hex))
      return(1);

   // Compute the intersections between the edge and the hex's faces
   for(i=0;i<6;i++)
      if(EdgIntQad(hex, i, edg, &IntVer, eps))
         return(1);

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if an octant is intersected by a triangle                             */
/*----------------------------------------------------------------------------*/

static itg TriIntHex(TriSct *tri, HexSct *hex, fpn eps)
{
   itg i, j, pos, neg;
   fpn CurDis;
   VerSct IntVer;

   // If there is no intersection between the bounding box
   // of the triangle and the octant it is no use to test,
   // the triangle doesn't intersect the octant
   if((  (tri->ver[0]->crd[0] < hex->ver[3]->crd[0])
      && (tri->ver[1]->crd[0] < hex->ver[3]->crd[0])
      && (tri->ver[2]->crd[0] < hex->ver[3]->crd[0]) )
   || (  (tri->ver[0]->crd[0] > hex->ver[5]->crd[0])
      && (tri->ver[1]->crd[0] > hex->ver[5]->crd[0])
      && (tri->ver[2]->crd[0] > hex->ver[5]->crd[0]) )
   || (  (tri->ver[0]->crd[1] < hex->ver[3]->crd[1])
      && (tri->ver[1]->crd[1] < hex->ver[3]->crd[1])
      && (tri->ver[2]->crd[1] < hex->ver[3]->crd[1]) )
   || (  (tri->ver[0]->crd[1] > hex->ver[5]->crd[1])
      && (tri->ver[1]->crd[1] > hex->ver[5]->crd[1])
      && (tri->ver[2]->crd[1] > hex->ver[5]->crd[1]) )
   || (  (tri->ver[0]->crd[2] < hex->ver[3]->crd[2])
      && (tri->ver[1]->crd[2] < hex->ver[3]->crd[2])
      && (tri->ver[2]->crd[2] < hex->ver[3]->crd[2]) )
   || (  (tri->ver[0]->crd[2] > hex->ver[5]->crd[2])
      && (tri->ver[1]->crd[2] > hex->ver[5]->crd[2])
      && (tri->ver[2]->crd[2] > hex->ver[5]->crd[2]) ) )
   {
      return(0);
   }

   // Test if a triangle's vertex is included in the octant
   for(i=0;i<3;i++)
      if(VerInsHex(tri->ver[i], hex))
         return(1);

   // Check whether the triangle plane intersects the octant
   pos = neg = 0;

   for(i=0;i<8;i++)
   {
      CurDis = DisVerPla(hex->ver[i]->crd, tri->ver[0]->crd, tri->nrm);

      if(CurDis < -eps)
         neg = 1;
      else if(CurDis > eps)
         pos = 1;
      else
         pos = neg = 1;
   }

   if(!pos || !neg)
      return(0);

   // Compute the intersections between the triangle edges and the hex faces
   for(i=0;i<6;i++)
      for(j=0;j<3;j++)
         if(EdgIntQad(hex, i, &tri->edg[j], &IntVer, eps))
            return(1);

   // Compute the intersections between the triangle and the hex edges
   for(i=0;i<12;i++)
      if(EdgIntTri(tri, &hex->edg[i], &IntVer, eps))
         return(1);

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if an octant is intersected by a quad                                 */
/*----------------------------------------------------------------------------*/

static itg QadIntHex(QadSct *qad, HexSct *hex, fpn eps)
{
   if(TriIntHex(&qad->tri[0], hex, eps) || TriIntHex(&qad->tri[1], hex, eps))
      return(1);
   else
      return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if an octant is intersected by a tetrahedron                          */
/*----------------------------------------------------------------------------*/

static itg TetIntHex(TetSct *tet, HexSct *hex, fpn eps)
{
   itg i, j, pos, neg;
   fpn CurDis;
   VerSct IntVer;

   // If there is no intersection between the bounding box
   // of the tet and the octant it is no use to test,
   // the tet doesn't intersect the octant
   if((  (tet->ver[0]->crd[0] < hex->ver[3]->crd[0])
      && (tet->ver[1]->crd[0] < hex->ver[3]->crd[0])
      && (tet->ver[2]->crd[0] < hex->ver[3]->crd[0])
      && (tet->ver[3]->crd[0] < hex->ver[3]->crd[0]) )
   || (  (tet->ver[0]->crd[0] > hex->ver[5]->crd[0])
      && (tet->ver[1]->crd[0] > hex->ver[5]->crd[0])
      && (tet->ver[2]->crd[0] > hex->ver[5]->crd[0])
      && (tet->ver[3]->crd[0] > hex->ver[5]->crd[0]) )
   || (  (tet->ver[0]->crd[1] < hex->ver[3]->crd[1])
      && (tet->ver[1]->crd[1] < hex->ver[3]->crd[1])
      && (tet->ver[2]->crd[1] < hex->ver[3]->crd[1])
      && (tet->ver[3]->crd[1] < hex->ver[3]->crd[1]) )
   || (  (tet->ver[0]->crd[1] > hex->ver[5]->crd[1])
      && (tet->ver[1]->crd[1] > hex->ver[5]->crd[1])
      && (tet->ver[2]->crd[1] > hex->ver[5]->crd[1])
      && (tet->ver[3]->crd[1] > hex->ver[5]->crd[1]) )
   || (  (tet->ver[0]->crd[2] < hex->ver[3]->crd[2])
      && (tet->ver[1]->crd[2] < hex->ver[3]->crd[2])
      && (tet->ver[2]->crd[2] < hex->ver[3]->crd[2])
      && (tet->ver[3]->crd[2] < hex->ver[3]->crd[2]) )
   || (  (tet->ver[0]->crd[2] > hex->ver[5]->crd[2])
      && (tet->ver[1]->crd[2] > hex->ver[5]->crd[2])
      && (tet->ver[2]->crd[2] > hex->ver[5]->crd[2])
      && (tet->ver[3]->crd[2] > hex->ver[5]->crd[2]) ) )
   {
      return(0);
   }

   // Test if a tet's vertex is included in the octant
   for(i=0;i<4;i++)
      if(VerInsHex(tet->ver[i], hex))
         return(1);

   // Test if a oct's vertex is included in the octant
   for(i=0;i<8;i++)
      if(VerInsTet(hex->ver[i], tet, eps))
         return(1);

   // Compute the intersections between the tet edges and the hex faces
   for(i=0;i<6;i++)
      for(j=0;j<6;j++)
         if(EdgIntQad(hex, i, &tet->edg[j], &IntVer, eps))
            return(1);

   // Compute the intersections between the tet's face and the hex's edges
   for(i=0;i<12;i++)
      for(j=0;j<4;j++)
         if(EdgIntTri(&tet->tri[j], &hex->edg[i], &IntVer, eps))
            return(1);

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if a vertex is included in an inflated tet                            */
/*----------------------------------------------------------------------------*/

itg VerInsTet(VerSct *ver, TetSct *tet, fpn eps)
{
   const itg TetEdg[6][2] = { {0,1}, {1,2}, {2,0}, {3,0}, {3,1}, {3,2} };
   const itg TetFac[4][3] = { {3,2,1}, {0,2,3}, {3,1,0}, {0,1,2} };
   itg i, j, ins = 1;
   TetSct SubTet;

   // Create 4 subtets from the vertex and a face of the tet.
   // Compute the volume of each subtet, if all of them are positive,
   // it means that the vertex is indide the tet
   SubTet.ver[3] = ver;

   for(i=0;i<4;i++)
   {
      for(j=0;j<3;j++)
         SubTet.ver[j] = tet->ver[ TetFac[i][j] ];

      if(GetVolTet(&SubTet) <= 0)
      {
         ins = 0;
         break;
      }
   }

   if(ins)
      return(1);

   // If the vertex is not inside the tet, it may be close to one of its faces
   for(i=0;i<4;i++)
      if(VerInsTri(&tet->tri[i], ver, eps))
         return(1);

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if a vertex is inside a hex                                           */
/*----------------------------------------------------------------------------*/

static itg VerInsHex(VerSct *ver, HexSct *hex)
{
   itg i;

   for(i=0;i<3;i++)
      if( (ver->crd[i] > hex->ver[5]->crd[i])
      ||  (ver->crd[i] < hex->ver[3]->crd[i]) )
      {
         return(0);
      }

   return(1);
}


/*----------------------------------------------------------------------------*/
/* Test if an edge intersects a quad                                          */
/*----------------------------------------------------------------------------*/

static itg EdgIntQad(HexSct *hex, itg FacIdx, EdgSct *edg,
                     VerSct *IntVer, fpn eps)
{
   itg i, NmbVer = 0;
   fpn sgn[2];
   VerSct *ver=NULL;
   EdgSct edg2;
   QadSct *qad = &hex->qad[ FacIdx ];

   // Compute the distance between the edge's vertices and the quad's plane
   for(i=0;i<2;i++)
   {
      sgn[i] = DisVerPla(edg->ver[i]->crd, qad->ver[0]->crd, qad->nrm);

      if(fabs(sgn[i]) < eps)
      {
         ver = edg->ver[i];
         NmbVer++;
      }
   }

   // This leads to 3 possible cases
   switch(NmbVer)
   {
      // Both vertices are far from the plane : 
      // if they stand in the same side of the plane, there is no intersection,
      // otherwise we compute the intersection between the edge and the plane
      // and test wether it falls inside the quad or not
      case 0 :
      {
         // Test if both vertices stand on opposite sides of the plane
         if(sgn[0] * sgn[1] < 0)
         {
            LinCmbVec3( fabs(sgn[0]) / (fabs(sgn[0])
                     +  fabs(sgn[1])), edg->ver[1]->crd,
                        fabs(sgn[1]) / (fabs(sgn[0])
                     +  fabs(sgn[1])), edg->ver[0]->crd, IntVer->crd);

            return(VerInsHex(IntVer, hex));
         }
      }break;

      case 1 :
      {
         if(VerInsHex(ver, hex))
         {
            CpyVec(ver->crd, IntVer->crd);
            return(1);
         }
      }break;

      case 2 :
      {
         for(i=0;i<4;i++)
         {
            edg2.ver[0] = qad->ver[i];
            edg2.ver[1] = qad->ver[ (i+1)%4 ];
            SetEdgTng(&edg2);

            if(EdgIntEdg(edg, &edg2, IntVer, eps))
               return(1);
         }
      }break;
   }

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if an edge intersects a triangle                                      */
/*----------------------------------------------------------------------------*/

static itg EdgIntTri(TriSct *tri, EdgSct *edg, VerSct *IntVer, fpn eps)
{
   itg i, NmbVer = 0;
   fpn sgn[2];
   VerSct *ver=NULL;
   EdgSct edg2;

   // Compute the distance between the edge's vertices and the triangle's plane
   for(i=0;i<2;i++)
   {
      sgn[i] = DisVerPla(edg->ver[i]->crd, tri->ver[0]->crd, tri->nrm);

      if(fabs(sgn[i]) < eps)
      {
         ver = edg->ver[i];
         NmbVer++;
      }
   }

   // This leads to 3 possible cases
   switch(NmbVer)
   {
      // Both vertices are far from the plane : 
      // if they stand in the same side of the plane, there is no intersection,
      // otherwise we compute the intersection between the edge and the plane
      // and test wether it falls inside the triangle or not
      case 0 :
      {
         // Test if both vertices stand on opposite sides of the plane
         if(sgn[0] * sgn[1] < 0)
         {
            LinCmbVec3( fabs(sgn[0]) / (fabs(sgn[0])
                     +  fabs(sgn[1])), edg->ver[1]->crd,
                        fabs(sgn[1]) / (fabs(sgn[0])
                     +  fabs(sgn[1])), edg->ver[0]->crd, IntVer->crd);

            return(VerInsTri(tri, IntVer, eps));
         }
      }break;

      case 1 :
      {
         if(VerInsTri(tri, ver, eps))
         {
            CpyVec(ver->crd, IntVer->crd);
            return(1);
         }
      }break;

      case 2 :
      {
         for(i=0;i<3;i++)
         {
            edg2.ver[0] = tri->ver[i];
            edg2.ver[1] = tri->ver[ (i+1)%3 ];
            SetEdgTng(&edg2);

            if(EdgIntEdg(edg, &edg2, IntVer, eps))
               return(1);
         }
      }break;
   }

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if a vertex is included in an inflated triangle                       */
/*----------------------------------------------------------------------------*/

static itg VerInsTri(TriSct *tri, VerSct *ver, fpn eps)
{
   itg i, ins = 1;
   fpn vec[3][3], nrm[3];
   VerSct img;
   EdgSct edg;

   // Project the vertex on the triangle's plane and check the distance
   if(PrjVerPla(ver->crd, tri->ver[0]->crd, tri->nrm, img.crd) > eps)
      return(0);

   // Compare the normals of the three sub triangles against
   // the original triangle's normal. If one of them is opposite,
   // the vertex does not belong to the triangle
   for(i=0;i<3;i++)
      SubVec3(tri->ver[i]->crd, img.crd, vec[i]);

   for(i=0;i<3;i++)
   {
      CrsPrd(vec[ (i+1)%3 ], vec[i], nrm);

      if(DotPrd(nrm, tri->nrm) <= 0)
      {
         ins = 0;
         break;
      }
   }

   if(ins)
      return(1);

   // If the vertex is not inside the triangle,
   // it may be close to one of its edges
   for(i=0;i<3;i++)
   {
      edg.ver[0] = tri->ver[i];
      edg.ver[1] = tri->ver[ (i+1)%3 ];
      SetEdgTng(&edg);

      if(VerInsEdg(&edg, &img, eps))
         return(1);
   }

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Compute the intersection between coplanar edges                            */
/*----------------------------------------------------------------------------*/

static itg EdgIntEdg(EdgSct *edg1, EdgSct *edg2, VerSct *IntVer, fpn eps)
{
   itg i, NmbVer = 0;
   fpn siz[2];
   VerSct img, *ver=NULL;

   // Compute the distance between the edge1's vertices
   // and the edge2 support line
   for(i=0;i<2;i++)
   {
      PrjVerLin(edg2->ver[i]->crd, edg1->ver[0]->crd, edg1->tng, img.crd);
      siz[i] = dis(edg2->ver[i]->crd, img.crd);

      if(siz[i] < eps)
         NmbVer++;
   }

   // This leads to 3 possible cases
   if(NmbVer < 2)
   {
      LinCmbVec3( siz[0]/(siz[0]+siz[1]), edg2->ver[1]->crd,
                  siz[1]/(siz[0]+siz[1]), edg2->ver[0]->crd, IntVer->crd);

      return(VerInsEdg(edg1, IntVer, eps));
   }
   else
   {
      ver = NULL;

      if(VerInsEdg(edg2, edg1->ver[0], eps))
         ver = edg1->ver[0];
      else if(VerInsEdg(edg2, edg1->ver[1], eps))
         ver = edg1->ver[1];
      else if(VerInsEdg(edg1, edg2->ver[0], eps))
         ver = edg2->ver[0];
      else if(VerInsEdg(edg1, edg2->ver[1], eps))
         ver = edg2->ver[1];

      if(ver)
      {
         CpyVec(ver->crd, IntVer->crd);
         return(1);
      }
   }

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Test if a vertex belongs to an edge                                        */
/*----------------------------------------------------------------------------*/

static itg VerInsEdg(EdgSct *edg, VerSct *ver, fpn eps)
{
   itg i;
   fpn u[3], v[3];
   VerSct img;

   // Project the vertex on the edge's support line
   PrjVerLin(ver->crd, edg->ver[0]->crd, edg->tng, img.crd);

   if(DisPow(ver->crd, img.crd) > POW(eps))
      return(0);

   // Check if the image belongs to the edge
   SubVec3(img.crd, edg->ver[0]->crd, u);
   SubVec3(img.crd, edg->ver[1]->crd, v);

   if(DotPrd(u, v) < 0)
      return(1);

   // If the vertex does not belong to the edge,
   // it may be close to one of its vertices
   for(i=0;i<2;i++)
      if(DisPow(img.crd, edg->ver[i]->crd) < POW(eps))
         return(1);

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Compute the distance between a vertex and a triangle                       */
/*----------------------------------------------------------------------------*/

static fpn DisVerTri(MshSct *msh, fpn VerCrd[3], TriSct *tri)
{
   fpn ImgCrd[3], TmpCrd[3], u[3], v[3], w[3], nrm[3], SubVol[3], TotVol;

   // Project the vertex on the triangle's plane
   PrjVerPla(VerCrd, tri->ver[0]->crd, tri->nrm, ImgCrd);

   // Compute the vectors stemming from the projection to the triangle's nodes
   SubVec3(tri->ver[0]->crd, ImgCrd, u);
   SubVec3(tri->ver[1]->crd, ImgCrd, v);
   SubVec3(tri->ver[2]->crd, ImgCrd, w);

   // Compute the three tets' volumes
   CrsPrd(v, w, nrm);
   SubVol[0] = -DotPrd(nrm, tri->nrm);
   SubVol[0] = MAX(SubVol[0], 0.);

   CrsPrd(w, u, nrm);
   SubVol[1] = -DotPrd(nrm, tri->nrm);
   SubVol[1] = MAX(SubVol[1], 0.);

   CrsPrd(u, v, nrm);
   SubVol[2] = -DotPrd(nrm, tri->nrm);
   SubVol[2] = MAX(SubVol[2], 0.);

   // Compute the closest position with the barycentric coordinates
   TotVol = SubVol[0] + SubVol[1] + SubVol[2];
   MulVec2(SubVol[0] / TotVol, tri->ver[0]->crd, ImgCrd);
   MulVec2(SubVol[1] / TotVol, tri->ver[1]->crd, TmpCrd);
   AddVec2(TmpCrd, ImgCrd);
   MulVec2(SubVol[2] / TotVol, tri->ver[2]->crd, TmpCrd);
   AddVec2(TmpCrd, ImgCrd);

   // Return the square of the distance
   return(DisPow(VerCrd, ImgCrd));
}


/*----------------------------------------------------------------------------*/
/* Compute the distance between a vertex and a quad                           */
/*----------------------------------------------------------------------------*/

static fpn DisVerQad(MshSct *msh, fpn VerCrd[3], QadSct *qad)
{
   return( MIN(DisVerTri(msh, VerCrd, &qad->tri[0]),
               DisVerTri(msh, VerCrd, &qad->tri[1])) );
}


/*----------------------------------------------------------------------------*/
/* Compute the distance between a vertex and a tetrahedron                    */
/*----------------------------------------------------------------------------*/

static fpn DisVerTet(MshSct *msh, fpn *VerCrd, TetSct *tet)
{
   itg i;
   fpn CurDis, MinDis = DBL_MAX;
   VerSct TmpVer;

   CpyVec(VerCrd, TmpVer.crd);

   if(VerInsTet(&TmpVer, tet, msh->eps))
      return(0.);

   for(i=0;i<4;i++)
   {
      CurDis = DisPow(VerCrd, tet->ver[i]->crd);

      if(CurDis < MinDis)
         MinDis = CurDis;
   }

   return(MinDis);
}


/*----------------------------------------------------------------------------*/
/* Compute the triangle's surface                                             */
/*----------------------------------------------------------------------------*/

static fpn GetTriSrf(TriSct *tri)
{
   fpn nrm[3];

   // Compute the cross-product vector and get its size
   GetTriVec(tri, nrm);
   return(GetNrmVec(nrm) / 2.);
}


/*----------------------------------------------------------------------------*/
/* fpn precision computed volume on fpn coordinates                     */
/*----------------------------------------------------------------------------*/

static fpn GetVolTet(TetSct *tet)
{
   fpn c[9];

   // Create the linear system, each column is filled with a vector
   c[0] = tet->ver[1]->crd[0] - tet->ver[0]->crd[0];
   c[1] = tet->ver[2]->crd[0] - tet->ver[0]->crd[0];
   c[2] = tet->ver[3]->crd[0] - tet->ver[0]->crd[0];

   c[3] = tet->ver[1]->crd[1] - tet->ver[0]->crd[1];
   c[4] = tet->ver[2]->crd[1] - tet->ver[0]->crd[1];
   c[5] = tet->ver[3]->crd[1] - tet->ver[0]->crd[1];

   c[6] = tet->ver[1]->crd[2] - tet->ver[0]->crd[2];
   c[7] = tet->ver[2]->crd[2] - tet->ver[0]->crd[2];
   c[8] = tet->ver[3]->crd[2] - tet->ver[0]->crd[2];

   // Return the "determinant" of the matrix
   return(  c[0] * (c[4]*c[8] - c[5]*c[7])
         +  c[1] * (c[5]*c[6] - c[3]*c[8])
         +  c[2] * (c[3]*c[7] - c[4]*c[6]) );
}


/*----------------------------------------------------------------------------*/
/* Compute the distance between a vertex and an edge                          */
/*----------------------------------------------------------------------------*/

static fpn DisVerEdg(fpn VerCrd[3], EdgSct *edg)
{
   fpn dis0, dis1, TotSiz = 0.;
   VerSct img;

   PrjVerLin(VerCrd, edg->ver[0]->crd, edg->tng, img.crd);
   TotSiz = dis(edg->ver[0]->crd, img.crd) + dis(edg->ver[1]->crd, img.crd);

   if( (TotSiz - edg->siz) < .00001 * (TotSiz + edg->siz))
      return(DisPow(VerCrd, img.crd));

   dis0 = DisPow(VerCrd, edg->ver[0]->crd);
   dis1 = DisPow(VerCrd, edg->ver[1]->crd);

   return(MIN(dis0, dis1));
}


/*----------------------------------------------------------------------------*/
/* Compute the triangle's normal vector                                       */
/*----------------------------------------------------------------------------*/

static void GetTriVec(TriSct *tri, fpn w[3])
{
   fpn u[3], v[3];

   // Compute the vector product
   SubVec3(tri->ver[1]->crd, tri->ver[0]->crd, u);
   SubVec3(tri->ver[2]->crd, tri->ver[0]->crd, v);
   CrsPrd(v, u, w);
}


/*----------------------------------------------------------------------------*/
/* Compute and set the triangle normal vector                                 */
/*----------------------------------------------------------------------------*/

static void SetTriNrm(TriSct *tri)
{
   // Compute the cross-product vector and normalize it
   GetTriVec(tri, tri->nrm);
   NrmVec(tri->nrm);
}


/*----------------------------------------------------------------------------*/
/* Compute and store the edge's unit tangent                                  */
/*----------------------------------------------------------------------------*/

static void SetEdgTng(EdgSct *edg)
{
   SubVec3(edg->ver[1]->crd, edg->ver[0]->crd, edg->tng);
   edg->siz = GetNrmVec(edg->tng);

   if(edg->siz)
      MulVec1(1./edg->siz, edg->tng);
}


/*----------------------------------------------------------------------------*/
/* Compute the normal projection of a point on a line                         */
/*----------------------------------------------------------------------------*/

static void PrjVerLin(  fpn VerCrd[3], fpn LinCrd[3],
                        fpn LinTng[3], fpn ImgCrd[3] )
{
   fpn dp, u[3];

   // Compute the scalar product of the projected vector and the edge's vector
   SubVec3(VerCrd, LinCrd, u);
   dp = DotPrd(u, LinTng);
   LinCmbVec3(1., LinCrd, dp, LinTng, ImgCrd);
}


/*----------------------------------------------------------------------------*/
/* Compute the normal projection of a vertex on a plane                       */
/*----------------------------------------------------------------------------*/

static fpn PrjVerPla(fpn VerCrd[3], fpn PlaCrd[3],
                     fpn PlaNrm[3], fpn ImgCrd[3] )
{
   fpn DisPla, u[3];

   // Compute the scalar product between the unit normal N and a vector V 
   // defined by the vertex to project and the base plane vertex
   SubVec3(PlaCrd, VerCrd, u);
   DisPla = DotPrd(u, PlaNrm);
   MulVec2(DisPla, PlaNrm, ImgCrd);
   AddVec2(VerCrd, ImgCrd);

   // Return the absolute ditance on the fly
   return(fabs(DisPla));
}


/*----------------------------------------------------------------------------*/
/* Compute the distance between a vertex and a plane                          */
/*----------------------------------------------------------------------------*/

static fpn DisVerPla(fpn VerCrd[3], fpn PlaCrd[3], fpn PlaNrm[3])
{
   fpn vec[3];

   SubVec3(VerCrd, PlaCrd, vec);
   return(DotPrd(vec, PlaNrm));
}


/*----------------------------------------------------------------------------*/
/* Test the intersection of two bounding boxex + epsilon                      */
/*----------------------------------------------------------------------------*/

static itg BoxIntBox(fpn box1[2][3], fpn box2[2][3], fpn eps)
{
   if((  ((box1[0][0] > box2[0][0] - eps) && (box1[0][0] < box2[1][0] + eps))
      || ((box1[1][0] > box2[0][0] - eps) && (box1[1][0] < box2[1][0] + eps))
      || ((box1[0][0] < box2[0][0]      ) && (box1[1][0] > box2[1][0]      )))
   && (  ((box1[0][1] > box2[0][1] - eps) && (box1[0][1] < box2[1][1] + eps))
      || ((box1[1][1] > box2[0][1] - eps) && (box1[1][1] < box2[1][1] + eps))
      || ((box1[0][1] < box2[0][1]      ) && (box1[1][1] > box2[1][1]      )))
   && (  ((box1[0][2] > box2[0][2] - eps) && (box1[0][2] < box2[1][2] + eps))
      || ((box1[1][2] > box2[0][2] - eps) && (box1[1][2] < box2[1][2] + eps))
      || ((box1[0][2] < box2[0][2]      ) && (box1[1][2] > box2[1][2]      ))) )
   {
      return(1);
   }

   return(0);
}


/*----------------------------------------------------------------------------*/
/* Compute a triangle aspect ration                                           */
/*----------------------------------------------------------------------------*/

static fpn GetTriAni(TriSct *tri)
{
   fpn srf, len, MaxLen;

   srf = GetTriSrf(tri);
   MaxLen = len = DisPow(tri->ver[0]->crd, tri->ver[1]->crd);
   len = DisPow(tri->ver[1]->crd, tri->ver[2]->crd);
   MaxLen = MAX(len, MaxLen);
   len = DisPow(tri->ver[2]->crd, tri->ver[0]->crd);
   MaxLen = MAX(len, MaxLen);

   return(sqrt(MaxLen / srf));
}


/*----------------------------------------------------------------------------*/
/* Various basic operations on vectors                                        */
/*----------------------------------------------------------------------------*/

// Euclidian distance
static fpn dis(fpn a[3], fpn b[3])
{
   itg i;
   fpn siz = 0;

   for(i=0;i<3;i++)
      siz += POW(b[i] - a[i]);

   return(sqrt(siz));
}

// Euclidian distance to the power of two
static fpn DisPow(fpn a[3], fpn b[3])
{
   itg i;
   fpn siz = 0;

   for(i=0;i<3;i++)
      siz += POW(b[i] - a[i]);

   return(siz);
}

// V = V - U
static void SubVec2(fpn u[3], fpn v[3])
{
   itg i;

   for(i=0;i<3;i++)
      v[i] -= u[i];
}

// W = U - V
static void SubVec3(fpn u[3], fpn v[3], fpn w[3])
{
   itg i;

   for(i=0;i<3;i++)
      w[i] = u[i] - v[i];
}

// Euclidian norm
static void NrmVec(fpn u[3])
{
   itg i;
   fpn dp = 0;

   for(i=0;i<3;i++)
      dp += u[i] * u[i];

   if(dp < DBL_MIN)
      return;

   dp = 1. / sqrt(dp);

   for(i=0;i<3;i++)
      u[i] *= dp;
}

// Dot Product
static fpn DotPrd(fpn u[3], fpn v[3])
{
   itg i;
   fpn dp = 0;

   for(i=0;i<3;i++)
      dp += u[i] * v[i];

   return(dp);
}

// Cross product
static void CrsPrd(fpn u[3], fpn v[3], fpn w[3])
{
   w[0] = u[1] * v[2] - u[2] * v[1];
   w[1] = u[2] * v[0] - u[0] * v[2];
   w[2] = u[0] * v[1] - u[1] * v[0];
}

// Linear combinaison: W = a*U + b*V
static void LinCmbVec3(fpn w1, fpn v1[3], fpn w2, fpn v2[3], fpn v3[3])
{
   itg i;

   for(i=0;i<3;i++)
      v3[i] = w1 * v1[i] + w2 * v2[i];
}

// U = 0
static void ClrVec(fpn u[3])
{
   itg i;

   for(i=0;i<3;i++)
      u[i] = 0.;
}

// V = U
static void CpyVec(fpn u[3], fpn v[3])
{
   itg i;

   for(i=0;i<3;i++)
      v[i] = u[i];
}

// V = V + U
static void AddVec2(fpn u[3], fpn v[3])
{
   itg i;

   for(i=0;i<3;i++)
      v[i] += u[i];
}

// U = U + [s;s;s]
static void AddScaVec1(fpn s, fpn u[3])
{
   itg i;

   for(i=0;i<3;i++)
      u[i] += s;
}

// V = U + [s;s;s]
static void AddScaVec2(fpn s, fpn u[3], fpn v[3])
{
   itg i;

   for(i=0;i<3;i++)
      v[i] = u[i] + s;
}

// U = w*U
static void MulVec1(const fpn w, fpn u[3])
{
   u[0] *= w;
   u[1] *= w;
   u[2] *= w;
}

// V = w*U
static void MulVec2(fpn w, fpn u[3], fpn v[3])
{
   itg i;

   for(i=0;i<3;i++)
      v[i] = w * u[i];
}

// Return Euclidian norm
static fpn GetNrmVec(fpn u[3])
{
   return(sqrt(POW(u[0]) + POW(u[1]) + POW(u[2])));
}


/*----------------------------------------------------------------------------*/
/* Allocate a chunk of memory and link it to memory allocator's list          */
/*----------------------------------------------------------------------------*/

static void *NewMem(TreSct *tre, size_t siz)
{
   MemSct *mem;

   mem = malloc(sizeof(MemSct));
   assert(mem);
   mem->adr = malloc(siz);
   assert(mem->adr);
   mem->siz = siz;
   mem->nex = tre->NexMem;
   tre->NexMem = mem;
   tre->MemUse += siz;

   return(mem->adr);
}


/*----------------------------------------------------------------------------*/
/* Cylct through the linked list of allocated block and free them all         */
/*----------------------------------------------------------------------------*/

static void FreAllMem(TreSct *tre)
{
   MemSct *mem = tre->NexMem, *nex;

   while(mem)
   {
      tre->MemUse -= mem->siz;
      nex = mem->nex;
      free(mem->adr);
      free(mem);
      mem = nex;
   }
}


/*----------------------------------------------------------------------------*/
/* Fortran 77 API                                                             */
/*----------------------------------------------------------------------------*/

int64_t call(lolnewoctree)(itg *NmbVer, fpn *VerTab1, fpn *VerTab2,
                           itg *NmbEdg, itg *EdgTab1, itg *EdgTab2,
                           itg *NmbTri, itg *TriTab1, itg *TriTab2,
                           itg *NmbQad, itg *QadTab1, itg *QadTab2,
                           itg *NmbTet, itg *TetTab1, itg *TetTab2,
                           itg *NmbPyr, itg *PyrTab1, itg *PyrTab2,
                           itg *NmbPri, itg *PriTab1, itg *PriTab2,
                           itg *NmbHex, itg *HexTab1, itg *HexTab2,
                           itg *BasIdx, itg *NmbThr)
{
   return(LolNewOctree( *NmbVer, VerTab1, VerTab2, *NmbEdg, EdgTab1, EdgTab2,
                        *NmbTri, TriTab1, TriTab2, *NmbQad, QadTab1, QadTab2,
                        *NmbTet, TetTab1, TetTab2, *NmbPyr, PyrTab1, PyrTab2,
                        *NmbPri, PriTab1, PriTab2, *NmbHex, HexTab1, HexTab2,
                        *BasIdx, *NmbThr ));
}

int64_t call(lolfreeoctree)(int64_t *OctIdx)
{
   return(LolFreeOctree(*OctIdx));
}   

itg call(lolgetboundingbox)(  int64_t *OctIdx, itg *typ, itg *MaxItm,
                              itg *ItmTab, fpn *MinCrd, fpn *MaxCrd, itg *ThrIdx )
{
   return(LolGetBoundingBox(*OctIdx, *typ, *MaxItm, ItmTab, MinCrd, MaxCrd, *ThrIdx));
}

itg call(lolgetnearest)(int64_t *OctIdx, itg *typ, fpn *MinCrd, fpn *MinDis,
                        fpn *MaxDis, void *UsrPrc, void *UsrDat, itg *ThrIdx)
{
   return(LolGetNearest(*OctIdx, *typ, MinCrd, MinDis,
                        *MaxDis, UsrPrc, UsrDat, *ThrIdx));
}
