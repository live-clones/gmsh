// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Lambda2.h"
#include "Numeric.h"

StringXNumber Lambda2Options_Number[] = {
  {GMSH_FULLRC, "Eigenvalue", NULL, 2.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterLambda2Plugin()
  {
    return new GMSH_Lambda2Plugin();
  }
}

GMSH_Lambda2Plugin::GMSH_Lambda2Plugin()
{
  ;
}

void GMSH_Lambda2Plugin::getName(char *name) const
{
  strcpy(name, "Lambda2");
}

void GMSH_Lambda2Plugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "E. Marchandise");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(Lambda2) computes the eigenvalues\n"
         "Lambda(1,2,3) of the tensor (S_ik S_kj +\n"
         "Om_ik Om_kj), where S_ij = 0.5 (ui,j + uj,i)\n"
         "and Om_ij = 0.5 (ui,j - uj,i) are respectively\n"
         "the symmetric and antisymmetric parts of the\n"
         "velocity gradient tensor. Vortices are well\n"
         "represented by regions where Lambda(2) is\n"
         "negative. If `iView' contains tensor elements,\n"
         "the plugin directly uses the tensors as the\n"
         "values of the velocity gradient tensor; if\n"
         "`iView' contains vector elements, the plugin\n"
         "uses them as the velocities from which to derive\n"
         "the velocity gradient tensor. If `iView' < 0,\n"
         "the plugin is run on the current view.\n"
         "\n"
         "Plugin(Lambda2) creates one new view.\n");
}

int GMSH_Lambda2Plugin::getNbOptions() const
{
  return sizeof(Lambda2Options_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_Lambda2Plugin::getOption(int iopt)
{
  return &Lambda2Options_Number[iopt];
}

void GMSH_Lambda2Plugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Lambda2 failed...");
}

static int inv3x3tran(double mat[3][3], double inv[3][3], double *det)
{
  double ud;

  *det = det3x3(mat);

  if(*det == 0.0)
    return (0);

  ud = 1. / (*det);

  inv[0][0] = ud * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
  inv[0][1] = -ud * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
  inv[0][2] = ud * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
  inv[1][0] = -ud * (mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]);
  inv[1][1] = ud * (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]);
  inv[1][2] = -ud * (mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]);
  inv[2][0] = ud * (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]);
  inv[2][1] = -ud * (mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]);
  inv[2][2] = ud * (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
  return 1;
}

static void eigen(std::vector<double> &inList, int inNb, 
                  std::vector<double> &outList, int *outNb,
                  int nbTime, int nbNod, int nbComp, int lam)
{
  if(!inNb || (nbComp != 3 && nbComp != 9) || lam < 1 || lam > 3)
    return;

  // loop on elements  
  int nb = inList.size() / inNb;
  for(unsigned int i = 0; i < inList.size(); i += nb) {

    // copy node coordinates
    for(int j = 0; j < 3 * nbNod; j++)
      outList.push_back(inList[i + j]);
    
    // loop on time steps
    for(int j = 0; j < nbTime; j++){

      double *x = &inList[i];
      double *y = &inList[i + nbNod];
      double *z = &inList[i + 2 * nbNod];

      double GradVel[3][3];

      if(nbComp == 9){ 
        // val is the velocity gradient tensor: we assume that it is
        // constant per element
        double *v = &inList[i + 3 * nbNod + nbNod * nbComp * j + nbComp * 0];
        GradVel[0][0] = v[0]; GradVel[0][1] = v[1]; GradVel[0][2] = v[2];
        GradVel[1][0] = v[3]; GradVel[1][1] = v[4]; GradVel[1][2] = v[5];
        GradVel[2][0] = v[6]; GradVel[2][1] = v[7]; GradVel[2][2] = v[8];
      }
      else if(nbComp == 3){ 
        // FIXME: the following could be greatly simplified and
        // generalized by using the classes in shapeFunctions.h

        // val contains the velocities: compute the gradient tensor
        // from them
        const int MAX_NOD = 4; 
        double val[3][MAX_NOD];
        for(int k = 0; k < nbNod; k++){
          double *v = &inList[i + 3 * nbNod + nbNod * nbComp * j + nbComp * k];
          for(int l = 0; l < 3; l++){
            val[l][k] = v[l];
          }
        }
        // compute gradient of shape functions
        double GradPhi_x[MAX_NOD][3];
        double GradPhi_ksi[MAX_NOD][3];
        double dx_dksi[3][3];
        double dksi_dx[3][3];
        double det;
        if(nbNod == 3){ // triangles  
          double a[3], b[3], cross[3];
          a[0]= x[1]-x[0]; a[1]= y[1]-y[0]; a[2]= z[1]-z[0];
          b[0]= x[2]-x[0]; b[1]= y[2]-y[0]; b[2]= z[2]-z[0];
          prodve(a, b, cross);
          dx_dksi[0][0] = x[1] - x[0]; dx_dksi[0][1] = x[2]-x[0]; dx_dksi[0][2] = cross[0];
          dx_dksi[1][0] = y[1] - y[0]; dx_dksi[1][1] = y[2]-y[0]; dx_dksi[1][2] = cross[1];
          dx_dksi[2][0] = z[1] - z[0]; dx_dksi[2][1] = z[2]-z[0]; dx_dksi[2][2] = cross[2];
          inv3x3tran(dx_dksi, dksi_dx, &det);
          GradPhi_ksi[0][0]= -1;  GradPhi_ksi[0][1]= -1;  GradPhi_ksi[0][2]= 0;  
          GradPhi_ksi[1][0]=  1;  GradPhi_ksi[1][1]=  0;  GradPhi_ksi[1][2]= 0;
          GradPhi_ksi[2][0]=  0;  GradPhi_ksi[2][1]=  1;  GradPhi_ksi[2][2]= 0;
        }
        else if (nbNod == 4){ // tetrahedra
          dx_dksi[0][0] = x[1] - x[0]; dx_dksi[0][1] = x[2]-x[0]; dx_dksi[0][2] = x[3]-x[0];
          dx_dksi[1][0] = y[1] - y[0]; dx_dksi[1][1] = y[2]-y[0]; dx_dksi[1][2] = y[3]-y[0];
          dx_dksi[2][0] = z[1] - z[0]; dx_dksi[2][1] = z[2]-z[0]; dx_dksi[2][2] = z[3]-z[0];   
          inv3x3tran(dx_dksi, dksi_dx, &det);
          GradPhi_ksi[0][0]= -1;  GradPhi_ksi[0][1]= -1; GradPhi_ksi[0][2]= -1; 
          GradPhi_ksi[1][0]=  1;  GradPhi_ksi[1][1]=  0; GradPhi_ksi[1][2]=  0; 
          GradPhi_ksi[2][0]=  0;  GradPhi_ksi[2][1]=  1; GradPhi_ksi[2][2]=  0; 
          GradPhi_ksi[3][0]=  0;  GradPhi_ksi[3][1]=  0; GradPhi_ksi[3][2]=  1; 
        }
        else{
          Msg::Error("Lambda2 not ready for this type of element");
          return;
        }
        for(int k = 0; k < nbNod ; k++){
          for(int l = 0; l < 3; l++){
            GradPhi_x[k][l] = 0.0;
            for(int m = 0; m < 3; m++){
              GradPhi_x[k][l] += GradPhi_ksi[k][m] * dksi_dx[l][m];
            }
          }
        }
        // compute gradient of velocities
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            GradVel[k][l] = 0.0;
            for(int m = 0; m < nbNod; m++){
              GradVel[k][l] +=  val[k][m]* GradPhi_x[m][l];
            }
          }
        }
      }
        
      // compute the sym and antisymetric parts
      double sym[3][3];
      double asym[3][3];
      for(int m = 0; m < 3; m++){
        for(int n = 0; n < 3; n++){
          sym[m][n]  = 0.5 * (GradVel[m][n] + GradVel[n][m]);
          asym[m][n] = 0.5 * (GradVel[m][n] - GradVel[n][m]);
        }
      }
      double a[3][3];
      for(int m = 0; m < 3; m++){
        for(int n = 0; n < 3; n++){
          a[m][n] = 0.0;
          for(int l = 0; l < 3; l++)
            a[m][n] += sym[m][l] * sym[l][n] + asym[m][l] * asym[l][n];
        }
      }
      
      // compute the eigenvalues
      double lambda[3];
      eigenvalue(a, lambda);
      for(int k = 0; k < nbNod; k++)
        outList.push_back(lambda[lam-1]);
    }

    (*outNb)++;

  }
}

PView *GMSH_Lambda2Plugin::execute(PView *v)
{
  int ev = (int)Lambda2Options_Number[0].def;
  int iView = (int)Lambda2Options_Number[1].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView();

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;
  
  // assume that the tensors contain the velocity gradient tensor
  int nts = data1->getNumTimeSteps();
  eigen(data1->TP, data1->NbTP, data2->SP, &data2->NbSP, nts, 1, 9, ev);
  eigen(data1->TL, data1->NbTL, data2->SL, &data2->NbSL, nts, 2, 9, ev);
  eigen(data1->TT, data1->NbTT, data2->ST, &data2->NbST, nts, 3, 9, ev);
  eigen(data1->TQ, data1->NbTQ, data2->SQ, &data2->NbSQ, nts, 4, 9, ev);
  eigen(data1->TS, data1->NbTS, data2->SS, &data2->NbSS, nts, 4, 9, ev);
  eigen(data1->TH, data1->NbTH, data2->SH, &data2->NbSH, nts, 8, 9, ev);
  eigen(data1->TI, data1->NbTI, data2->SI, &data2->NbSI, nts, 6, 9, ev);
  eigen(data1->TY, data1->NbTY, data2->SY, &data2->NbSY, nts, 5, 9, ev);

  // assume that the vectors contain the velocities
  // FIXME: only implemented for tri/tet at the moment
  //eigen(data1->VP, data1->NbVP, data2->SP, &data2->NbSP, nts, 1, 3, ev);
  //eigen(data1->VL, data1->NbVL, data2->SL, &data2->NbSL, nts, 2, 3, ev);
  eigen(data1->VT, data1->NbVT, data2->ST, &data2->NbST, nts, 3, 3, ev);
  //eigen(data1->VQ, data1->NbVQ, data2->SQ, &data2->NbSQ, nts, 4, 3, ev);
  eigen(data1->VS, data1->NbVS, data2->SS, &data2->NbSS, nts, 4, 3, ev);
  //eigen(data1->VH, data1->NbVH, data2->SH, &data2->NbSH, nts, 8, 3, ev);
  //eigen(data1->VI, data1->NbVI, data2->SI, &data2->NbSI, nts, 6, 3, ev);
  //eigen(data1->VY, data1->NbVY, data2->SY, &data2->NbSY, nts, 5, 3, ev);

  data2->Time = data1->Time;
  data2->setName(data1->getName() + "_Lambda2");
  data2->setFileName(data1->getName() + "_Lambda2.pos");
  data2->finalize();

  return v2;
}
