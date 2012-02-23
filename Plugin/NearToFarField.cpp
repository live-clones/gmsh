// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "NearToFarField.h"

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


double GMSH_NearToFarFieldPlugin::getFarField(std::vector<element*> allElems,
                                              std::vector<std::vector<double> > js, std::vector<std::vector<double> > ms,
                                              double k0, double r_far, double theta, double phi)
{

  // theta in [0, pi] (elevation/polar angle)
  // phi in [0, 2*pi] (azimuthal angle)

  double sTheta = sin(theta) ; double cTheta = cos(theta) ;
  double sPhi = sin(phi) ; double cPhi = cos(phi) ;
  double r[3] = {sTheta*cPhi, sTheta*sPhi, cTheta}; // Unit vector position

  double Z0 = 120 * M_PI ; // free-space impedance

  int numComps = 3, numSteps = 2 ;
  std::vector<std::vector<double> > N(numSteps,numComps), Ns(numSteps,numComps) ;
  std::vector<std::vector<double> > L(numSteps,numComps), Ls(numSteps,numComps) ;

  int i = 0 ;
  for(unsigned int ele = 0; ele < allElems.size(); ele++){
    element* e = allElems[ele] ;
    int numNodes = e->getNumNodes() ;
    int numEdges = e->getNumEdges() ;

    std::vector<double > valN0(numNodes*numComps),valN1(numNodes*numComps), valL0(numNodes*numComps), valL1(numNodes*numComps) ;

    for(int nod = 0; nod < numNodes; nod++){
      double x, y, z;
      e->getXYZ(nod, x, y, z) ;
      double rr, r_nod[3] = {x, y, z};
      prosca(r_nod, r, &rr) ;
      double e_jk0rr[2] = {cos(k0*rr), sin(k0*rr)} ;

      for(int comp = 0; comp < numComps; comp++){
        if(i < js[0].size()){
          valN0[numComps * nod + comp] = js[0][i] * e_jk0rr[0] - js[1][i] * e_jk0rr[1];
          valN1[numComps * nod + comp] = js[0][i] * e_jk0rr[1] + js[1][i] * e_jk0rr[0];
          valL0[numComps * nod + comp] = ms[0][i] * e_jk0rr[0] - ms[1][i] * e_jk0rr[1];
          valL1[numComps * nod + comp] = ms[0][i] * e_jk0rr[1] + ms[1][i] * e_jk0rr[0];
          i++;
        }
      }
    }

    N[0][0] += e->integrate(&valN0[0], 3) ; N[1][0] += e->integrate(&valN1[0], 3) ;
    N[0][1] += e->integrate(&valN0[1], 3) ; N[1][1] += e->integrate(&valN1[1], 3) ;
    N[0][2] += e->integrate(&valN0[2], 3) ; N[1][2] += e->integrate(&valN1[2], 3) ;

    L[0][0] += e->integrate(&valL0[0], 3) ; L[1][0] += e->integrate(&valL1[0], 3) ;
    L[0][1] += e->integrate(&valL0[1], 3) ; L[1][1] += e->integrate(&valL1[1], 3) ;
    L[0][2] += e->integrate(&valL0[2], 3) ; L[1][2] += e->integrate(&valL1[2], 3) ;
 }

  // From Cartesian to spherical coordinates
  for(int step = 0; step < 2; step++){
    Ns[step][0] = N[step][0] * sTheta * cPhi + N[step][1] * sTheta * sPhi + N[step][2] *cTheta ;
    Ns[step][1] = N[step][0] * cTheta * cPhi + N[step][1] * cTheta * sPhi - N[step][2]* sTheta ;
    Ns[step][2] =-N[step][0] * sPhi          + N[step][1] * cPhi ;

    Ls[step][0] = L[step][0] * sTheta * cPhi + L[step][1] * sTheta * sPhi + L[step][2] *cTheta ;
    Ls[step][1] = L[step][0] * cTheta * cPhi + L[step][1] * cTheta * sPhi - L[step][2]* sTheta ;
    Ls[step][2] =-L[step][0] * sPhi          + L[step][1] * cPhi ;
   }

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

  double farF =  1./2./Z0 * ( (E_theta[0]*E_theta[0] + E_theta[1]*E_theta[1]) + (E_phi[0]*E_phi[0]+E_phi[1] *E_phi[1]) ) ;

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

  if(eData->getNumTimeSteps()!= 2 || hData->getNumTimeSteps() != 2){
    Msg::Error("Invalid number of steps for EView or HView, fields must be complex");
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

  std::vector<element*> allElems  ;
  std::vector<std::vector<double> > js ;
  std::vector<std::vector<double> > ms ;

  int numSteps = eData->getNumTimeSteps() ;
  js.resize(numSteps);
  ms.resize(numSteps);

  for(int ent = 0; ent < eData->getNumEntities(0); ent++){
    for(int ele = 0; ele < eData->getNumElements(0, ent); ele++){
      if(eData->skipElement(0, ent, ele)) continue;
      if(hData->skipElement(0, ent, ele)) continue;
      int numComp  = eData->getNumComponents(0, ent, ele);
      if(numComp != 3) continue ;

      int dim = eData->getDimension(0, ent, ele);
      int numNodes = eData->getNumNodes(0, ent, ele);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
        eData->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);

      elementFactory factory;
      allElems.push_back(factory.create(numNodes, dim, &x[0], &y[0], &z[0], true));

      double n[3] = {0.,0.,0.};
      if(numNodes>2)
        normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
      else
        normal2points(x[0], y[0], z[0], x[1], y[1], z[1], n);

      for(int step = 0; step < numSteps; step++){
        for(int nod = 0; nod < numNodes; nod++){
          double h[3], e[3];
          for(int comp = 0; comp < numComp; comp++){
            eData->getValue(step, ent, ele, nod, comp, e[comp]);
            hData->getValue(step, ent, ele, nod, comp, h[comp]);
          }
          double j[3], m[3] ;
          prodve(n, h, j) ; // Js =   n x H ; Surface electric current
          prodve(e, n, m) ; // Ms = - n x E ; Surface magnetic current
          js[step].push_back(j[0]) ; js[step].push_back(j[1]) ; js[step].push_back(j[2]) ;
          ms[step].push_back(m[0]) ; ms[step].push_back(m[1]) ; ms[step].push_back(m[2]) ;
        }
      }

    }
  }

  // -------------------------------------------------------------
  // Generating radiation pattern
  // -------------------------------------------------------------
  double phi,   dPhi   = 2*M_PI/_NbPhi ;
  double theta, dTheta =   M_PI/_NbThe ;
  double ffmax = 0.0 ;

  std::vector<std::vector<double> > allPhi(_NbPhi+1,_NbThe+1) ;
  std::vector<std::vector<double> > allThe(_NbPhi+1,_NbThe+1) ;
  std::vector<std::vector<double> > farF(_NbPhi+1,_NbThe+1) ;

  for (int i = 0; i <= _NbPhi; i++){
    phi = i*dPhi ;
    for (int j = 0; j <= _NbThe; j++){
      theta = j * dTheta ;
      allPhi[i][j] = phi ;
      allThe[i][j] = theta ;

      farF[i][j] = getFarField(allElems, js, ms, _k0, _r_far, theta, phi) ;

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
      double P1[3] = { x0 + r_sph * farF[i ][j ] * sin(allThe[i ][j ]) * cos(allPhi[i ][j ]),
                       y0 + r_sph * farF[i ][j ] * sin(allThe[i ][j ]) * sin(allPhi[i ][j ]),
                       z0 + r_sph * farF[i ][j ] * cos(allThe[i ][j ]) } ;
      double P2[3] = { x0 + r_sph * farF[i+1][j ] * sin(allThe[i+1][j ]) * cos(allPhi[i+1][j  ]),
                       y0 + r_sph * farF[i+1][j ] * sin(allThe[i+1][j ]) * sin(allPhi[i+1][j  ]),
                       z0 + r_sph * farF[i+1][j ] * cos(allThe[i+1][j ]) } ;
      double P3[3] = { x0 + r_sph * farF[i+1][j+1] * sin(allThe[i+1][j+1]) * cos(allPhi[i+1][j+1]),
                       y0 + r_sph * farF[i+1][j+1] * sin(allThe[i+1][j+1]) * sin(allPhi[i+1][j+1]),
                       z0 + r_sph * farF[i+1][j+1] * cos(allThe[i+1][j+1]) } ;
      double P4[3] = { x0 + r_sph * farF[i ][j+1] * sin(allThe[i ][j+1]) * cos(allPhi[i ][j+1]),
                       y0 + r_sph * farF[i ][j+1] * sin(allThe[i ][j+1]) * sin(allPhi[i ][j+1]),
                       z0 + r_sph * farF[i ][j+1] * cos(allThe[i ][j+1]) } ;

      dataFar->SQ.push_back(P1[0]); dataFar->SQ.push_back(P2[0]);  dataFar->SQ.push_back(P3[0]); dataFar->SQ.push_back(P4[0]);
      dataFar->SQ.push_back(P1[1]); dataFar->SQ.push_back(P2[1]);  dataFar->SQ.push_back(P3[1]); dataFar->SQ.push_back(P4[1]);
      dataFar->SQ.push_back(P1[2]); dataFar->SQ.push_back(P2[2]);  dataFar->SQ.push_back(P3[2]); dataFar->SQ.push_back(P4[2]);
      (dataFar->NbSQ)++;
      if(!_dB){
        dataFar->SQ.push_back(farF[i ][j  ]);
        dataFar->SQ.push_back(farF[i+1][j  ]);
        dataFar->SQ.push_back(farF[i+1][j+1]);
        dataFar->SQ.push_back(farF[i ][j+1]);
      }
      else{
        dataFar->SQ.push_back(10*log10(farF[i ][j]));
        dataFar->SQ.push_back(10*log10(farF[i+1][j ]));
        dataFar->SQ.push_back(10*log10(farF[i+1][j+1]));
        dataFar->SQ.push_back(10*log10(farF[i ][j+1]));
      }
    }
  }

  dataFar->setName("_NearToFarField");
  dataFar->setFileName("_NearToFarField.pos");
  dataFar->finalize();

  return vf;
}
