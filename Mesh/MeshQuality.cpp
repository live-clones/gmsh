/* $Id: MeshQuality.cpp,v 1.2 2000-11-23 14:11:35 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Mesh.h"
#include "Numeric.h"

/* Fonctions calculant differents parametres donnant la qualite
   d'un maillage (surtout 3-D)   */

/* Fonction calculant le facteur gamma pour un element tetraedrique :
               12       rho(in)
   gamma = --------   ---------
             sqrt(6)    max(lij)
 */

double GAMMAMAX, GAMMAMIN, GAMMA;
int NbCalcGamma;

void CalculateGamma (void *a, void *b){
  Simplex *s = *(Simplex **) a;
  double gamma = s->GammaShapeMeasure ();
  NbCalcGamma++;
  GAMMAMAX = DMAX (GAMMAMAX, gamma);
  GAMMA += gamma;
  GAMMAMIN = DMIN (GAMMAMIN, gamma);
}

void CalculateEta (void *a, void *b){
  Simplex *s = *(Simplex **) a;
  double gamma = s->EtaShapeMeasure ();
  NbCalcGamma++;
  GAMMAMAX = DMAX (GAMMAMAX, gamma);
  GAMMA += gamma;
  GAMMAMIN = DMIN (GAMMAMIN, gamma);
}

void CalculateR (void *a, void *b){
  Simplex *s = *(Simplex **) a;
  double gamma = s->RhoShapeMeasure ();
  NbCalcGamma++;
  GAMMAMAX = DMAX (GAMMAMAX, gamma);
  GAMMA += gamma;
  GAMMAMIN = DMIN (GAMMAMIN, gamma);
}

void Gamma_Maillage (Volume * v, double *gamma, double *gammamax, double *gammamin){
  GAMMA = 0.0;
  GAMMAMAX = 0.0;
  GAMMAMIN = 1.0;
  NbCalcGamma = 0;
  Tree_Action (v->Simplexes, CalculateGamma);
  if (!NbCalcGamma)
    NbCalcGamma = 1;
  *gamma = GAMMA / (double) NbCalcGamma;
  *gammamax = GAMMAMAX;
  *gammamin = GAMMAMIN;
}

void Eta_Maillage (Volume * v, double *gamma, double *gammamax, double *gammamin){
  GAMMA = 0.0;
  GAMMAMAX = 0.0;
  GAMMAMIN = 1.0;
  NbCalcGamma = 0;
  Tree_Action (v->Simplexes, CalculateEta);
  if (!NbCalcGamma)
    NbCalcGamma = 1;
  *gamma = GAMMA / (double) NbCalcGamma;
  *gammamax = GAMMAMAX;
  *gammamin = GAMMAMIN;
}

void R_Maillage (Volume * v, double *gamma, double *gammamax, double *gammamin){
  GAMMA = 0.0;
  GAMMAMAX = 0.0;
  GAMMAMIN = 1.0;
  NbCalcGamma = 0;
  Tree_Action (v->Simplexes, CalculateR);
  if (!NbCalcGamma)
    NbCalcGamma = 1;
  *gamma = GAMMA / (double) NbCalcGamma;
  *gammamax = GAMMAMAX;
  *gammamin = GAMMAMIN;
}
