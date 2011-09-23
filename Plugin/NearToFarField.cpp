// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "NearToFarField.h"
#include "Numeric.h"
#include "PViewOptions.h"
#include "MElement.h"
#include "GModel.h"

StringXNumber NearToFarFieldOptions_Number[] = {
  {GMSH_FULLRC, "Wavenumber",     NULL, 1.},
  {GMSH_FULLRC, "FarDistance",    NULL, 1.},
  {GMSH_FULLRC, "NumPointsPhi",   NULL, 120},
  {GMSH_FULLRC, "NumPointsTheta", NULL,  60},
  {GMSH_FULLRC, "EView", NULL, 0},
  {GMSH_FULLRC, "HView", NULL, 1},
  {GMSH_FULLRC, "Normalize", NULL, 1},
  {GMSH_FULLRC, "dB", NULL, 1},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterNearToFarFieldPlugin()
  {
    return new GMSH_NearToFarFieldPlugin();
  }
}

std::string GMSH_NearToFarFieldPlugin::getHelp() const
{
  return "Plugin(NearToFarField) computes the far field pattern "
    "from the near electric and magnetic fields on a surface (regular grid) "
    "enclosing the radiating device (antenna).\n\n"
    "Parameters: the wavenumber, the far field distance (radious) and "
    "angular discretisation, i.e. the number of divisions for "
    "phi in [0, 2*Pi] and theta in [0, Pi].\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(NearToFarField) creates one new view.";
}

int GMSH_NearToFarFieldPlugin::getNbOptions() const
{
  return sizeof(NearToFarFieldOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_NearToFarFieldPlugin::getOption(int iopt)
{
  return &NearToFarFieldOptions_Number[iopt];
}

void GMSH_NearToFarFieldPlugin::CartesianToSpherical(int numSteps, double theta, double phi, double **Fc, double **Fsp)
{
  double sTheta = sin(theta) ;
  double cTheta = cos(theta) ;
  double sPhi   = sin(phi) ;
  double cPhi   = cos(phi) ;

   for(int step = 0; step < numSteps; step++){
     Fsp[step][0] = Fc[step][0] * sTheta * cPhi + Fc[step][1] * sTheta * sPhi + Fc[step][2] *cTheta ; 
     Fsp[step][1] = Fc[step][0] * cTheta * cPhi + Fc[step][1] * cTheta * sPhi - Fc[step][2]* sTheta ; 
     Fsp[step][2] =-Fc[step][0] * sPhi          + Fc[step][1] * cPhi ;  
   }
}

double GMSH_NearToFarFieldPlugin::getFarField(PViewData *eData, PViewData *hData, double k0, double r_far, double theta, double phi)
{

  // theta in [0, pi] (elevation/polar angle)  
  // phi in [0, 2*pi] (azimuthal angle)
 
  double r[3] = { sin(theta)*cos(phi), sin(theta)*sin(phi), cos(theta) }; // Unit vector position
  double Z0 = 120 * M_PI ; // free-space impedance

  int numSteps = eData->getNumTimeSteps() ;
  int numEntities = eData->getNumEntities(0) ;

  double **N  = new double * [numSteps] ;
  double **Ns = new double * [numSteps] ;
  double **L  = new double * [numSteps] ;
  double **Ls = new double * [numSteps] ;
  for(int step = 0; step < numSteps; step++){
    N [step] = new double[3] ;
    Ns[step] = new double[3] ;
    L [step] = new double[3] ;
    Ls[step] = new double[3] ;
  }

  for (int step = 0; step < numSteps; step++)
    for(int comp = 0; comp < 3; comp++){
      N[step][comp]= Ns[step][comp]= 0. ; 
      L[step][comp]= Ls[step][comp]= 0. ;
    }
 
  // tag all the nodes with "0" (the default tag)
  for(int step = 0; step < numSteps; step++){
    for(int ent = 0; ent < numEntities; ent++){
      for(int ele = 0; ele < eData->getNumElements(step, ent); ele++){
        if(eData->skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < eData->getNumNodes(step, ent, ele); nod++)
          eData->tagNode(step, ent, ele, nod, 0);
      }
    }
  }

  for(int ent = 0; ent < eData->getNumEntities(0); ent++){
    for(int ele = 0; ele < eData->getNumElements(0, ent); ele++){
      if(eData->skipElement(0, ent, ele)) continue;
      int numComp  = eData->getNumComponents(0, ent, ele);
      if(numComp != 3) continue ;
      int numNodes = eData->getNumNodes(0, ent, ele);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      std::vector<int> tag(numNodes);

      for(int nod = 0; nod < numNodes; nod++)
        tag[nod] = eData->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
      double n[3] = {0.,0.,0.};
      normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n); 

      Msg::Error("FIXME JS and MS computation need to be recoded");
      // cannot allocate like this + fix numSteps
      /* 
      double Js[numSteps][numNodes*numComp], Ms[numSteps][numNodes*numComp] ;

      for(int step = 0; step < numSteps; step++){
        for(int nod = 0; nod < numNodes; nod++){
          if(tag[nod]) continue ; // already condisered in integration
          for(int comp = 0; comp < numComp; comp++){
            eData->getValue(step, ent, ele, nod, comp, Ms[numSteps][numComp*nod + comp ]);
            hData->getValue(step, ent, ele, nod, comp, Js[numSteps][numComp * nod + comp]);
          }
        }
      }

      // Integration 
      double P0[3] = {x[0], y[0], z[0]} ;
      double P1[3] = {x[1], y[1], z[1]} ;
      double P2[3] = {x[2], y[2], z[2]} ;
      double quad_area = triangle_area(P0,P1,P2);
      
      for(int nod = 0; nod < numNodes; nod++){
        double rr, r_nod[3] = {x[nod], y[nod], z[nod]}; 
        prosca(r_nod, r, &rr) ;
        double cos_k0rr = quad_area*cos(k0*rr) ; 
        double sin_k0rr = quad_area*sin(k0*rr) ;
        
        N[0][0] += Js[0][numComp*nod + 0] * cos_k0rr - Js[1][numComp*nod + 0] * sin_k0rr  ;   
        N[0][1] += Js[0][numComp*nod + 1] * cos_k0rr - Js[1][numComp*nod + 1] * sin_k0rr  ;   
        N[0][2] += Js[0][numComp*nod + 2] * cos_k0rr - Js[1][numComp*nod + 2] * sin_k0rr  ;   

        N[1][0] += Js[0][numComp*nod + 0] * sin_k0rr + Js[1][numComp*nod + 0] * cos_k0rr  ;   
        N[1][1] += Js[0][numComp*nod + 1] * sin_k0rr + Js[1][numComp*nod + 1] * cos_k0rr  ;   
        N[1][2] += Js[0][numComp*nod + 2] * sin_k0rr + Js[1][numComp*nod + 2] * cos_k0rr  ;   

        L[0][0] += Ms[0][numComp*nod + 0] * cos_k0rr - Ms[1][numComp*nod + 0] * sin_k0rr  ;   
        L[0][1] += Ms[0][numComp*nod + 1] * cos_k0rr - Ms[1][numComp*nod + 1] * sin_k0rr  ;   
        L[0][2] += Ms[0][numComp*nod + 2] * cos_k0rr - Ms[1][numComp*nod + 2] * sin_k0rr  ;   

        L[1][0] += Ms[0][numComp*nod + 0] * sin_k0rr + Ms[1][numComp*nod + 0] * cos_k0rr  ;   
        L[1][1] += Ms[0][numComp*nod + 1] * sin_k0rr + Ms[1][numComp*nod + 1] * cos_k0rr  ;   
        L[1][2] += Ms[0][numComp*nod + 2] * sin_k0rr + Ms[1][numComp*nod + 2] * cos_k0rr  ;   

        eData->tagNode(0, ent, ele, nod, 1);
      }
      */

    }
  }
  

  CartesianToSpherical(numSteps, theta, phi, N, Ns) ;
  CartesianToSpherical(numSteps, theta, phi, L, Ls) ;

  // E_r radial component is negligible in far field
  double E_theta[2] ;
  double E_phi[2] ;
  double k0_over_4pir = k0/(4*M_PI*r_far) ;
  double cos_k0r = cos(k0*r_far) ;
  double sin_k0r = sin(k0*r_far) ;

  // Elevation component
  E_theta[0] = -k0_over_4pir * ( (Ls[0][2] + Z0 * Ns[0][1]) * sin_k0r -  
                                 (Ls[1][2] + Z0 * Ns[1][1]) * cos_k0r ) ;
  E_theta[1] = -k0_over_4pir * ( (Ls[0][2] + Z0 * Ns[0][1]) * cos_k0r +  
                                 (Ls[1][2] + Z0 * Ns[1][1]) * sin_k0r ) ;
  // Azimuthal component 
  E_phi[0]   =  k0_over_4pir * ( (Ls[0][1] - Z0 * Ns[0][2]) * sin_k0r -  
                                 (Ls[1][1] - Z0 * Ns[1][2]) * cos_k0r ) ;
  E_phi[1]   =  k0_over_4pir * ( (Ls[0][1] - Z0 * Ns[0][2]) * cos_k0r +  
                                 (Ls[1][1] - Z0 * Ns[1][2]) * sin_k0r ) ;


  //printf("Ephi %g %g \n ", E_phi[0], E_phi[1]) ;
  //printf("Etheta %g %g\n ", E_theta[0], E_theta[1]) ;

 double farF =  1./2./Z0 * ( (E_theta[0]*E_theta[0] + E_theta[1]*E_theta[1]) + (E_phi[0]*E_phi[0]+E_phi[1] *E_phi[1]) ) ;

  for (int step = 0; step < numSteps; step++){
      delete [] N [step]  ; 
      delete [] Ns[step] ; 
      delete [] L [step]  ; 
      delete [] Ls[step] ; 
  }
  delete [] N  ; 
  delete [] Ns ; 
  delete [] L  ; 
  delete [] Ls ;   

  return farF ;

}


PView *GMSH_NearToFarFieldPlugin::execute(PView * v)
{

  double _k0 = (double)NearToFarFieldOptions_Number[0].def;
  double _r_far = (double)NearToFarFieldOptions_Number[1].def;
  int _NbPhi = (int)NearToFarFieldOptions_Number[2].def;
  int _NbThe = (int)NearToFarFieldOptions_Number[3].def;
  int _eView = (int)NearToFarFieldOptions_Number[4].def;
  int _hView = (int)NearToFarFieldOptions_Number[5].def;
  bool _normalize = (bool)NearToFarFieldOptions_Number[6].def;
  bool _dB = (bool)NearToFarFieldOptions_Number[7].def;

  PView *ve = getView(_eView, v);
  if(!ve){
     Msg::Error("NearToFarField plugin could not find EView %i", _eView);
    return v; 
  } 
  PView *vh = getView(_hView, v);
  if(!vh){
    Msg::Error("NearToFarField plugin could not find HView %i", _hView);
    return v;
  }
  PViewData *eData = ve->getData() ;
  PViewData *hData = vh->getData() ;

  if(eData->getNumEntities() != hData->getNumEntities() ||
     eData->getNumElements() != hData->getNumElements() ||
     eData->getNumTimeSteps()!= hData->getNumTimeSteps()){
    Msg::Error("Incompatible views for e-field and h-field");
    return v;
  }

  if(eData->getNumTimeSteps()!= 2){
    Msg::Error("NearToFarField Plugin only implemented for frequency domain, fields must be complex");
    return v;
  }

  // Center of the Far Field sphere
  double x0 = eData->getBoundingBox().center().x();
  double y0 = eData->getBoundingBox().center().y();
  double z0 = eData->getBoundingBox().center().z();
  if(x0 != hData->getBoundingBox().center().x() ||
     y0 != hData->getBoundingBox().center().y() ||
     z0 != hData->getBoundingBox().center().z()){
    Msg::Error("EView %i and HView %i must be given on the same grid", _eView, _hView);
    return v;
  }
  

  // View for far field: represented on a sphere of radious determined by the size of the BoundingBox
  PView *vf = new PView();
  PViewDataList *dataFar = getDataList(vf);
   
  double phi,   dPhi   = 2*M_PI/_NbPhi ;
  double theta, dTheta =   M_PI/_NbThe ;
  double ffmax = 0.0 ;

  double **allPhi = new double *[_NbPhi+1] ;
  double **allThe = new double *[_NbPhi+1] ;
  double **farF   = new double *[_NbPhi+1] ;
  for (int i = 0; i <= _NbPhi; i++){
    allPhi[i] = new double [_NbThe+1] ;
    allThe[i] = new double [_NbThe+1] ;
    farF[i]   = new double [_NbThe+1] ;
  }

 ve->setChanged(true);
 vh->setChanged(true);

 for(int step = 0; step < eData->getNumTimeSteps(); step++){
   // tag all the nodes with "0" (the default tag)
   for(int ent = 0; ent < eData->getNumEntities(step); ent++){
     for(int ele = 0; ele < eData->getNumElements(step, ent); ele++){
       if(eData->skipElement(step, ent, ele)) continue;
       if(hData->skipElement(step, ent, ele)) continue;
       for(int nod = 0; nod < eData->getNumNodes(step, ent, ele); nod++){
         eData->tagNode(step, ent, ele, nod, 0);
         hData->tagNode(step, ent, ele, nod, 0);
       }
     }
   }
   
   for(int ent = 0; ent < eData->getNumEntities(step); ent++){
     for(int ele = 0; ele < eData->getNumElements(step, ent); ele++){
       if(eData->skipElement(0, ent, ele)) continue;
       if(hData->skipElement(0, ent, ele)) continue;
       int numComp  = eData->getNumComponents(0, ent, ele);
       if(numComp != 3) continue ;
       int numNodes = eData->getNumNodes(0, ent, ele);
       double x[numNodes], y[numNodes], z[numNodes] ;
       int tag[numNodes];
       
       for(int nod = 0; nod < numNodes; nod++)
         tag[nod] = eData->getNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
       double n[3] = {0.,0.,0.};
       normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n); 
       double valE[numNodes*numComp], valH[numNodes*numComp] ;      
       
       for(int nod = 0; nod < numNodes; nod++){
         if(tag[nod]) continue ; // already considered 
         for(int comp = 0; comp < numComp; comp++){
           eData->getValue(step, ent, ele, nod, comp, valE[numComp * nod + comp]);
           hData->getValue(step, ent, ele, nod, comp, valH[numComp * nod + comp]);
         }
         double H[3] = { valH[numComp * nod + 0], valH[numComp * nod + 1], valH[numComp * nod + 2] } ;
         double E[3] = { valE[numComp * nod + 0], valE[numComp * nod + 1], valE[numComp * nod + 2] } ;
         double J[3], M[3] ;
         prodve(n, H, J) ; // Js =  n x H ;  Surface electric current
         prodve(E, n, M) ; // Ms = - n x E ; Surface magnetic current

         for(int comp = 0; comp < numComp; comp++){
           eData->setValue(step, ent, ele, nod, comp, M[comp]);
           hData->setValue(step, ent, ele, nod, comp, J[comp]);
           eData->tagNode(step, ent, ele, nod, 1);
           hData->tagNode(step, ent, ele, nod, 1);
         }
       }
     }
   }
 }

 eData->finalize(); 
 hData->finalize(); 
 
//****************************************
  for (int i = 0; i <= _NbPhi; i++){
    phi = i*dPhi ;
    for (int j = 0; j <= _NbThe; j++){
      theta = j * dTheta ;
      allPhi[i][j] = phi ;
      allThe[i][j] = theta ;
      farF[i][j] = getFarField(eData, hData, _k0, _r_far, theta, phi) ; 
      ffmax = (ffmax < farF[i][j]) ? farF[i][j] : ffmax ;
    }
  }
    
  if(_normalize){
      for (int i = 0; i <= _NbPhi; i++)
        for (int j = 0; j <= _NbThe; j++)
          if(ffmax!=0.0)
            farF[i][j] /= ffmax ;
          else
            Msg::Warning("Far field pattern not normalized, max value = %g", ffmax);
  }

  // Constructing sphere for visualization
  // centered at center of bb and with radious relative to the bb size
  double r_bb[3] = { eData->getBoundingBox().max().x()-eData->getBoundingBox().min().x(), 
                     eData->getBoundingBox().max().y()-eData->getBoundingBox().min().y(), 
                     eData->getBoundingBox().max().z()-eData->getBoundingBox().min().z() };
  double r_sph = norm3(r_bb) ;
  r_sph = (r_sph) ? r_sph/2 : 1./2. ; // radious of sphere for visu

  for (int i = 0; i < _NbPhi; i++){
    for (int j = 0; j < _NbThe; j++){
      double P1[3] = { x0 + r_sph * farF[i  ][j  ] * sin(allThe[i  ][j  ]) * cos(allPhi[i  ][j  ]),
                       y0 + r_sph * farF[i  ][j  ] * sin(allThe[i  ][j  ]) * sin(allPhi[i  ][j  ]),
                       z0 + r_sph * farF[i  ][j  ] * cos(allThe[i  ][j  ]) } ;
      double P2[3] = { x0 + r_sph * farF[i+1][j  ] * sin(allThe[i+1][j  ]) * cos(allPhi[i+1][j  ]),
                       y0 + r_sph * farF[i+1][j  ] * sin(allThe[i+1][j  ]) * sin(allPhi[i+1][j  ]),
                       z0 + r_sph * farF[i+1][j  ] * cos(allThe[i+1][j  ]) } ;
      double P3[3] = { x0 + r_sph * farF[i+1][j+1] * sin(allThe[i+1][j+1]) * cos(allPhi[i+1][j+1]),
                       y0 + r_sph * farF[i+1][j+1] * sin(allThe[i+1][j+1]) * sin(allPhi[i+1][j+1]),
                       z0 + r_sph * farF[i+1][j+1] * cos(allThe[i+1][j+1]) } ;
      double P4[3] = { x0 + r_sph * farF[i  ][j+1] * sin(allThe[i  ][j+1]) * cos(allPhi[i  ][j+1]),
                       y0 + r_sph * farF[i  ][j+1] * sin(allThe[i  ][j+1]) * sin(allPhi[i  ][j+1]),
                       z0 + r_sph * farF[i  ][j+1] * cos(allThe[i  ][j+1]) } ;     

      dataFar->SQ.push_back(P1[0]); dataFar->SQ.push_back(P2[0]);  dataFar->SQ.push_back(P3[0]); dataFar->SQ.push_back(P4[0]); 
      dataFar->SQ.push_back(P1[1]); dataFar->SQ.push_back(P2[1]);  dataFar->SQ.push_back(P3[1]); dataFar->SQ.push_back(P4[1]); 
      dataFar->SQ.push_back(P1[2]); dataFar->SQ.push_back(P2[2]);  dataFar->SQ.push_back(P3[2]); dataFar->SQ.push_back(P4[2]); 
      (dataFar->NbSQ)++;      
      if(!_dB){
        dataFar->SQ.push_back(farF[i  ][j  ]); 
        dataFar->SQ.push_back(farF[i+1][j  ]); 
        dataFar->SQ.push_back(farF[i+1][j+1]); 
        dataFar->SQ.push_back(farF[i  ][j+1]);
      }
      else{
        dataFar->SQ.push_back(log10(farF[i  ][j  ])); 
        dataFar->SQ.push_back(log10(farF[i+1][j  ])); 
        dataFar->SQ.push_back(log10(farF[i+1][j+1])); 
        dataFar->SQ.push_back(log10(farF[i  ][j+1]));
      }
    }
  }

  for (int i = 0; i <= _NbPhi; i++){
    delete[] allPhi[i] ;
    delete[] allThe[i] ;
    delete[] farF[i];
  }
  delete [] allPhi ;
  delete [] allThe ;
  delete [] farF ;

  dataFar->setName("_NearToFarField");
  dataFar->setFileName("_NearToFarField.pos");
  dataFar->finalize();
  
  return vf;
}
