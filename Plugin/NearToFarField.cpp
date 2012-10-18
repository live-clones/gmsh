// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Ruth Sabariego
//

#include <complex>
#include "NearToFarField.h"

StringXNumber NearToFarFieldOptions_Number[] = {
  {GMSH_FULLRC, "Wavenumber",       NULL, 1.},
  {GMSH_FULLRC, "PhiStart",         NULL, 0.},
  {GMSH_FULLRC, "PhiEnd",           NULL, 2. * M_PI},
  {GMSH_FULLRC, "NumPointsPhi",     NULL, 60},
  {GMSH_FULLRC, "ThetaStart",       NULL, 0.},
  {GMSH_FULLRC, "ThetaEnd",         NULL, M_PI},
  {GMSH_FULLRC, "NumPointsTheta",   NULL, 30},
  {GMSH_FULLRC, "EView",            NULL, 0},
  {GMSH_FULLRC, "HView",            NULL, 1},
  {GMSH_FULLRC, "Normalize",        NULL, 1},
  {GMSH_FULLRC, "dB",               NULL, 1},
  {GMSH_FULLRC, "NegativeTime",     NULL, 0.},
};

StringXString NearToFarFieldOptions_String[] = {
  {GMSH_FULLRC, "MatlabOutputFile",       NULL, "farfield.m"},
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
    "from the near electric E and magnetic H fields on a surface "
    "enclosing the radiating device (antenna).\n\n"
    "Parameters: the wavenumber, the "
    "angular discretisation (phi in [0, 2*Pi] and theta in [0, Pi]) "
    "of the far field sphere and the indices of the views containing the "
    "complex-valued E and H fields. If `Normalize' is set, the far field "
    "is normalized to 1. If `dB' is set, the far field is computed in dB. "
    "If `NegativeTime' is set, E and H are assumed to have exp(-iwt) time "
    "dependency; otherwise they are assume to have exp(+iwt) time "
    "dependency. If `MatlabOutputFile' is given the raw far field data is "
    "also exported in Matlab format.\n\n"
    "Plugin(NearToFarField) creates one new view.";
}

int GMSH_NearToFarFieldPlugin::getNbOptions() const
{
  return sizeof(NearToFarFieldOptions_Number) / sizeof(StringXNumber);
}

int GMSH_NearToFarFieldPlugin::getNbOptionsStr() const
{
  return sizeof(NearToFarFieldOptions_String) / sizeof(StringXString);
}

StringXNumber *GMSH_NearToFarFieldPlugin::getOption(int iopt)
{
  return &NearToFarFieldOptions_Number[iopt];
}

StringXString *GMSH_NearToFarFieldPlugin::getOptionStr(int iopt)
{
  return &NearToFarFieldOptions_String[iopt];
}

// Compute field using e^{j\omega t} time dependency, following Jin in "Finite
// Element Analysis of Antennas and Arrays", p. 176. This is not the usual `far
// field', as it still contains the e^{ikr}/r factor.
double GMSH_NearToFarFieldPlugin::getFarFieldJin(std::vector<element*> &allElems,
                                                 std::vector<std::vector<double> > &farfieldvector,
                                                 std::vector<std::vector<double> > &js,
                                                 std::vector<std::vector<double> > &ms,
                                                 double k0, double rFar, double theta,
                                                 double phi)
{
  // theta in [0, pi] (elevation/polar angle)
  // phi in [0, 2*pi] (azimuthal angle)

  double sTheta = sin(theta) ; double cTheta = cos(theta) ;
  double sPhi = sin(phi) ; double cPhi = cos(phi) ;
  double r[3] = {sTheta*cPhi, sTheta*sPhi, cTheta}; // Unit vector position

  double Z0 = 120 * M_PI ; // free-space impedance

  int numComps = 3, numSteps = 2 ;
  std::vector<std::vector<double> > N  ;
  std::vector<std::vector<double> > Ns ;
  std::vector<std::vector<double> > L  ;
  std::vector<std::vector<double> > Ls ;

  N.resize(numSteps); Ns.resize(numSteps);
  L.resize(numSteps); Ls.resize(numSteps);
  for (int step = 0; step < numSteps; step++){
    N[step].resize(numComps, 0.); Ns[step].resize(numComps);
    L[step].resize(numComps, 0.); Ls[step].resize(numComps);
  }

  int i = 0 ;
  for(unsigned int ele = 0; ele < allElems.size(); ele++){
    element* e = allElems[ele] ;
    int numNodes = e->getNumNodes() ;

    std::vector<double > valN0(numNodes*numComps), valN1(numNodes*numComps);
    std::vector<double > valL0(numNodes*numComps), valL1(numNodes*numComps) ;

    for(int nod = 0; nod < numNodes; nod++){
      double x, y, z;
      e->getXYZ(nod, x, y, z) ;
      double rr, r_nod[3] = {x, y, z};
      prosca(r_nod, r, &rr) ;
      double e_jk0rr[2] = {cos(k0*rr), sin(k0*rr)} ;

      for(int comp = 0; comp < numComps; comp++){
        if(i < (int)js[0].size()){
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
  double k0_over_4pir = k0/(4*M_PI*rFar) ;
  double cos_k0r = cos(k0*rFar) ;
  double sin_k0r = sin(k0*rFar) ;

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

  double farF =  1./2./Z0 * ( (E_theta[0]*E_theta[0] + E_theta[1]*E_theta[1]) +
                              (E_phi[0]*E_phi[0]+E_phi[1] *E_phi[1]) ) ;

  return farF ;
}

// Compute far field using e^{-i\omega t} time dependency, following Monk in
// "Finite Element Methods for Maxwell's equations", p. 233
double GMSH_NearToFarFieldPlugin::getFarFieldMonk(std::vector<element*> &allElems,
                                                  std::vector<std::vector<double> > &farfieldvector,
                                                  std::vector<std::vector<double> > &js,
                                                  std::vector<std::vector<double> > &ms,
                                                  double k0, double theta, double phi)
{
  double sTheta = sin(theta) ; double cTheta = cos(theta) ;
  double sPhi = sin(phi) ; double cPhi = cos(phi) ;
  double xHat[3] = {sTheta * cPhi, sTheta * sPhi, cTheta};
  std::complex<double> I(0., 1.);
  double Z0 = 120 * M_PI ; // free-space impedance

  double integral_r[3] = {0., 0., 0.}, integral_i[3] = {0., 0., 0.};
  int i = 0 ;
  for(unsigned int ele = 0; ele < allElems.size(); ele++){
    element* e = allElems[ele] ;
    int numNodes = e->getNumNodes() ;
    std::vector<double> integrand_r(numNodes * 3), integrand_i(numNodes * 3);
    for(int nod = 0; nod < numNodes; nod++){
      double y[3], xHat_dot_y;
      e->getXYZ(nod, y[0], y[1], y[2]) ;
      prosca(xHat, y, &xHat_dot_y) ;
      double n_x_e_r[3] = {-ms[0][i], -ms[0][i + 1], -ms[0][i + 2]};
      double n_x_e_i[3] = {-ms[1][i], -ms[1][i + 1], -ms[1][i + 2]};
      double n_x_h_r[3] = {js[0][i], js[0][i + 1], js[0][i + 2]};
      double n_x_h_i[3] = {js[1][i], js[1][i + 1], js[1][i + 2]};
      double n_x_h_x_xHat_r[3], n_x_h_x_xHat_i[3];
      prodve(n_x_h_r, xHat, n_x_h_x_xHat_r);
      prodve(n_x_h_i, xHat, n_x_h_x_xHat_i);
      for(int comp = 0; comp < 3; comp++){
        std::complex<double> n_x_e(n_x_e_r[comp], n_x_e_i[comp]);
        std::complex<double> n_x_h_x_xHat(n_x_h_x_xHat_r[comp], n_x_h_x_xHat_i[comp]);
        // Warning: Z0 == 1 in Monk
        std::complex<double> integrand = (n_x_e + Z0 * n_x_h_x_xHat) *
          (cos(-k0 * xHat_dot_y) + I * sin(-k0 * xHat_dot_y));
        integrand_r[3 * nod + comp] = integrand.real();
        integrand_i[3 * nod + comp] = integrand.imag();
      }
      i += 3;
    }
    for(int comp = 0; comp < 3; comp++){
      integral_r[comp] += e->integrate(&integrand_r[comp], 3);
      integral_i[comp] += e->integrate(&integrand_i[comp], 3);
    }
  }

  double xHat_x_integral_r[3], xHat_x_integral_i[3];
  prodve(xHat, integral_r, xHat_x_integral_r);
  prodve(xHat, integral_i, xHat_x_integral_i);
  std::complex<double> coef = I * k0 / 4. / M_PI;
  double  coef1 =  k0 / 4. / M_PI;
  std::complex<double> einf[3] = {coef * (xHat_x_integral_r[0] + I * xHat_x_integral_i[0]),
                                  coef * (xHat_x_integral_r[1] + I * xHat_x_integral_i[1]),
                                  coef * (xHat_x_integral_r[2] + I * xHat_x_integral_i[2])};

   for(int comp = 0; comp < 3; comp++){
      farfieldvector[comp][0] = -coef1 * xHat_x_integral_i[comp];
      farfieldvector[comp][1] =  coef1 * xHat_x_integral_r[comp]; 
     }

  return (norm(einf[0]) + norm(einf[1]) + norm(einf[2]));
}

static void printVector(FILE *fp, const std::string &name,
                        std::vector<std::vector<double> > &vec)
{
  fprintf(fp, "%s = [", name.c_str());
  for (unsigned int i = 0; i < vec.size(); i++)
    for (unsigned int j = 0; j < vec[i].size(); j++)
      fprintf(fp, "%.16g ", vec[i][j]);
  fprintf(fp, "];\n");
}

PView *GMSH_NearToFarFieldPlugin::execute(PView * v)
{
  double _k0 = (double)NearToFarFieldOptions_Number[0].def;
  double _phiStart = (double)NearToFarFieldOptions_Number[1].def;
  double _phiEnd = (double)NearToFarFieldOptions_Number[2].def;
  int _NbPhi = (int)NearToFarFieldOptions_Number[3].def;
  double _thetaStart = (double)NearToFarFieldOptions_Number[4].def;
  double _thetaEnd = (double)NearToFarFieldOptions_Number[5].def;
  int _NbThe = (int)NearToFarFieldOptions_Number[6].def;
  int _eView = (int)NearToFarFieldOptions_Number[7].def;
  int _hView = (int)NearToFarFieldOptions_Number[8].def;
  bool _normalize = (bool)NearToFarFieldOptions_Number[9].def;
  bool _dB = (bool)NearToFarFieldOptions_Number[10].def;
  int _negativeTime = (int)NearToFarFieldOptions_Number[11].def;

  std::string _outFile = NearToFarFieldOptions_String[0].def;

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
    Msg::Error("Incompatible views for E field and H field");
    return v;
  }

  if(eData->getNumTimeSteps() != 2 || hData->getNumTimeSteps() != 2){
    Msg::Error("Invalid number of steps for E or H fields (must be complex)");
    return v;
  }

  // center and radius of the visualization sphere
  SBoundingBox3d bbox = eData->getBoundingBox();
  double x0 = bbox.center().x();
  double y0 = bbox.center().y();
  double z0 = bbox.center().z();
  double lc = norm(SVector3(bbox.max(), bbox.min()));
  double r_sph = lc ? lc / 2. : 1;

  if(x0 != hData->getBoundingBox().center().x() ||
     y0 != hData->getBoundingBox().center().y() ||
     z0 != hData->getBoundingBox().center().z()){
    Msg::Error("E and H fields must be given on the same grid");
    return v;
  }

  // compute surface currents on all input elements
  std::vector<element*> allElems  ;
  std::vector<std::vector<double> > js(2) ;
  std::vector<std::vector<double> > ms(2) ;

  for(int ent = 0; ent < eData->getNumEntities(0); ent++){
    for(int ele = 0; ele < eData->getNumElements(0, ent); ele++){
      if(eData->skipElement(0, ent, ele)) continue;
      if(hData->skipElement(0, ent, ele)) continue;
      int numComp = eData->getNumComponents(0, ent, ele);
      if(numComp != 3) continue ;
      int dim = eData->getDimension(0, ent, ele);
      if(dim != 1 && dim != 2) continue;
      int numNodes = eData->getNumNodes(0, ent, ele);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
        eData->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);

      elementFactory factory;
      allElems.push_back(factory.create(numNodes, dim, &x[0], &y[0], &z[0], true));

      double n[3] = {0., 0., 0.};
      if(numNodes > 2)
        normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
      else
        normal2points(x[0], y[0], z[0], x[1], y[1], z[1], n);

      for(int step = 0; step < 2; step++){
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

  if(allElems.empty()){
    Msg::Error("No valid elements found to compute far field");
    return v;
  }

  // view for far field that will contain the radiation pattern
  PView *vf = new PView();
  PViewDataList *dataFar = getDataList(vf);

  std::vector<std::vector<double> > phi(_NbPhi + 1), theta(_NbPhi + 1);
  std::vector<std::vector<double> > x(_NbPhi + 1), y(_NbPhi + 1), z(_NbPhi + 1);
  std::vector<std::vector<double> > farField(_NbPhi + 1);
  std::vector<std::vector<double> > farField1r(_NbPhi + 1);
  std::vector<std::vector<double> > farField2r(_NbPhi + 1);
  std::vector<std::vector<double> > farField3r(_NbPhi + 1);
  std::vector<std::vector<double> > farField1i(_NbPhi + 1);
  std::vector<std::vector<double> > farField2i(_NbPhi + 1);
  std::vector<std::vector<double> > farField3i(_NbPhi + 1);
  std::vector<std::vector<double> > farfieldvector(3);

  for(int comp = 0; comp < 3; comp++){
      farfieldvector[comp].resize(2);
     }

  for (int i = 0; i <= _NbPhi; i++){
    phi[i].resize(_NbThe + 1);
    theta[i].resize(_NbThe + 1);
    x[i].resize(_NbThe + 1);
    y[i].resize(_NbThe + 1);
    z[i].resize(_NbThe + 1);
    farField[i].resize(_NbThe + 1);

    farField1r[i].resize(_NbThe + 1);
    farField2r[i].resize(_NbThe + 1);
    farField3r[i].resize(_NbThe + 1);
    farField1i[i].resize(_NbThe + 1);
    farField2i[i].resize(_NbThe + 1);
    farField3i[i].resize(_NbThe + 1);
  }

  double dPhi = (_phiEnd - _phiStart) / _NbPhi;
  double dTheta = (_thetaEnd - _thetaStart) / _NbThe;
  double ffmin = 1e200, ffmax = -1e200;
  Msg::ResetProgressMeter();
  for (int i = 0; i <= _NbPhi; i++){
    for (int j = 0; j <= _NbThe; j++){
      phi[i][j] = _phiStart + i * dPhi ;
      theta[i][j] = _thetaStart + j * dTheta ;
      if(_negativeTime){
        farField[i][j] = getFarFieldMonk(allElems, farfieldvector, js, ms, _k0,
                                         theta[i][j], phi[i][j]);
        farField1r[i][j] =  farfieldvector[1][0];
        farField2r[i][j] =  farfieldvector[2][0];
        farField3r[i][j] =  farfieldvector[3][0];
        farField1i[i][j] =  farfieldvector[1][1];
        farField2i[i][j] =  farfieldvector[2][1];
        farField3i[i][j] =  farfieldvector[3][1];}       
      else {
        farField[i][j] = getFarFieldJin(allElems, farfieldvector, js, ms, _k0, 10 * lc,
                                        theta[i][j], phi[i][j]);
        farField1r[i][j] =  farfieldvector[1][0];
        farField2r[i][j] =  farfieldvector[2][0];
        farField3r[i][j] =  farfieldvector[3][0];
        farField1i[i][j] =  farfieldvector[1][1];
        farField2i[i][j] =  farfieldvector[2][1];
        farField3i[i][j] =  farfieldvector[3][1];}

        ffmin = std::min(ffmin, farField[i][j]);
        ffmax = std::max(ffmax, farField[i][j]);
     }
      
    Msg::ProgressMeter(i, _NbPhi, true, "Computing far field");
  }
  for(unsigned int i = 0; i < allElems.size(); i++)
    delete allElems[i];

  if(_normalize){
    if(!ffmax)
      Msg::Warning("Cannot normalize far field (max = 0)");
    else
      for (int i = 0; i <= _NbPhi; i++)
        for (int j = 0; j <= _NbThe; j++)
          farField[i][j] /= ffmax ;
  }

  if(_dB){
    ffmin = 1e200;
    ffmax = -1e200;
    for (int i = 0; i <= _NbPhi; i++){
      for (int j = 0; j <= _NbThe; j++){
        farField[i][j] = 10 * log10(farField[i][j]);
        ffmin = std::min(ffmin, farField[i][j]);
        ffmax = std::max(ffmax, farField[i][j]);
      }
    }
  }

  for (int i = 0; i <= _NbPhi; i++){
    for (int j = 0; j <= _NbThe; j++){
      double df = (ffmax - ffmin);
      if(!df){
        Msg::Warning("zero far field range");
        df = 1.;
      }
      double f = (farField[i][j] - ffmin) / df; // in [0,1]
      x[i][j] = x0 + r_sph * f * sin(theta[i][j]) * cos(phi[i][j]);
      y[i][j] = y0 + r_sph * f * sin(theta[i][j]) * sin(phi[i][j]);
      z[i][j] = z0 + r_sph * f * cos(theta[i][j]);
    }
  }

  if(_outFile.size()){
    FILE *fp = fopen(_outFile.c_str(), "w");
    if(fp){
      printVector(fp, "phi", phi);
      printVector(fp, "theta", theta);
      printVector(fp, "farField", farField);

      printVector(fp, "farField1r", farField1r);
      printVector(fp, "farField2r", farField2r);
      printVector(fp, "farField3r", farField3r);
      printVector(fp, "farField1i", farField1i);
      printVector(fp, "farField2i", farField2i);
      printVector(fp, "farField3i", farField3i);

      printVector(fp, "x", x);
      printVector(fp, "y", y);
      printVector(fp, "z", z);
      fclose(fp);
    }
    else
      Msg::Error("Could not open file '%s'", _outFile.c_str());
  }

  for (int i = 0; i < _NbPhi; i++){
    for (int j = 0; j < _NbThe; j++){
      if(_NbPhi == 1 || _NbThe == 1){
        dataFar->NbSP++;
        dataFar->SP.push_back(x[i][j]); dataFar->SP.push_back(y[i][j]);
        dataFar->SP.push_back(z[i][j]); dataFar->SP.push_back(farField[i][j]);
      }
      else{
        double P1[3] = {x[i][j], y[i][j], z[i][j]};
        double P2[3] = {x[i+1][j], y[i+1][j], z[i+1][j]};
        double P3[3] = {x[i+1][j+1], y[i+1][j+1], z[i+1][j+1]};
        double P4[3] = {x[i][j+1], y[i][j+1], z[i][j+1]};
        dataFar->NbSQ++;
        dataFar->SQ.push_back(P1[0]); dataFar->SQ.push_back(P2[0]);
        dataFar->SQ.push_back(P3[0]); dataFar->SQ.push_back(P4[0]);
        dataFar->SQ.push_back(P1[1]); dataFar->SQ.push_back(P2[1]);
        dataFar->SQ.push_back(P3[1]); dataFar->SQ.push_back(P4[1]);
        dataFar->SQ.push_back(P1[2]); dataFar->SQ.push_back(P2[2]);
        dataFar->SQ.push_back(P3[2]); dataFar->SQ.push_back(P4[2]);
        dataFar->SQ.push_back(farField[i][j]);
        dataFar->SQ.push_back(farField[i+1][j]);
        dataFar->SQ.push_back(farField[i+1][j+1]);
        dataFar->SQ.push_back(farField[i][j+1]);
      }
    }
  }

  dataFar->setName("_NearToFarField");
  dataFar->setFileName("_NearToFarField.pos");
  dataFar->finalize();

  return vf;
}
