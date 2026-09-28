// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Ruth Sabariego
//

#include <complex>
#include "NearToFarField.h"
#include "Context.h"
#include "OS.h"

GMSH_NearToFarFieldPlugin::GMSH_NearToFarFieldPlugin()
  : GMSH_PostPlugin(
      {
        {GMSH_FULLRC, "Wavenumber", nullptr, 1., ""},
        {GMSH_FULLRC, "PhiStart", nullptr, 0., ""},
        {GMSH_FULLRC, "PhiEnd", nullptr, 2. * M_PI, ""},
        {GMSH_FULLRC, "NumPointsPhi", nullptr, 60, ""},
        {GMSH_FULLRC, "ThetaStart", nullptr, 0., ""},
        {GMSH_FULLRC, "ThetaEnd", nullptr, M_PI, ""},
        {GMSH_FULLRC, "NumPointsTheta", nullptr, 30, ""},
        {GMSH_FULLRC, "EView", nullptr, 0, ""},
        {GMSH_FULLRC, "HView", nullptr, 1, ""},
        {GMSH_FULLRC, "Normalize", nullptr, 1, ""},
        {GMSH_FULLRC, "dB", nullptr, 1, ""},
        {GMSH_FULLRC, "NegativeTime", nullptr, 0., ""},
        {GMSH_FULLRC, "RFar", nullptr, 0, ""},
      },
      {
        {GMSH_FULLRC, "MatlabOutputFile", nullptr, "farfield.m", ""},
      })
{
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

// Compute field using e^{j\omega t} time dependency, following Jin in "Finite
// Element Analysis of Antennas and Arrays", p. 176. This is not the usual `far
// field', as it still contains the e^{ikr}/r factor.
double GMSH_NearToFarFieldPlugin::getFarFieldJin(
  const std::vector<SurfaceElement> &elems,
  std::vector<std::vector<double>> &js, std::vector<std::vector<double>> &ms,
  double k0, double rFar, double theta, double phi)
{
  // theta in [0, pi] (elevation/polar angle)
  // phi in [0, 2*pi] (azimuthal angle)

  double sTheta = sin(theta);
  double cTheta = cos(theta);
  double sPhi = sin(phi);
  double cPhi = cos(phi);
  double r[3] = {sTheta * cPhi, sTheta * sPhi, cTheta}; // Unit vector position

  double Z0 = 120 * M_PI; // free-space impedance

  int numComps = 3, numSteps = 2;
  std::vector<std::vector<double> > N;
  std::vector<std::vector<double> > Ns;
  std::vector<std::vector<double> > L;
  std::vector<std::vector<double> > Ls;

  N.resize(numSteps);
  Ns.resize(numSteps);
  L.resize(numSteps);
  Ls.resize(numSteps);
  for(int step = 0; step < numSteps; step++) {
    N[step].resize(numComps, 0.);
    Ns[step].resize(numComps);
    L[step].resize(numComps, 0.);
    Ls[step].resize(numComps);
  }

  int i = 0;
  for(auto &e : elems) {
    // the integrals over the element, added to the sums element by element
    double n[2][3] = {{0., 0., 0.}, {0., 0., 0.}};
    double l[2][3] = {{0., 0., 0.}, {0., 0., 0.}};
    for(std::size_t nod = 0; nod < e.w.size(); nod++) {
      double r_nod[3] = {e.x[nod], e.y[nod], e.z[nod]};
      double rr = prosca(r_nod, r);
      double e_jk0rr[2] = {cos(k0 * rr), sin(k0 * rr)};
      for(int comp = 0; comp < numComps; comp++) {
        if(i < (int)js[0].size()) {
          n[0][comp] +=
            e.w[nod] * (js[0][i] * e_jk0rr[0] - js[1][i] * e_jk0rr[1]);
          n[1][comp] +=
            e.w[nod] * (js[0][i] * e_jk0rr[1] + js[1][i] * e_jk0rr[0]);
          l[0][comp] +=
            e.w[nod] * (ms[0][i] * e_jk0rr[0] - ms[1][i] * e_jk0rr[1]);
          l[1][comp] +=
            e.w[nod] * (ms[0][i] * e_jk0rr[1] + ms[1][i] * e_jk0rr[0]);
          i++;
        }
      }
    }
    for(int s = 0; s < 2; s++) {
      for(int comp = 0; comp < numComps; comp++) {
        N[s][comp] += n[s][comp];
        L[s][comp] += l[s][comp];
      }
    }
  }

  // From Cartesian to spherical coordinates
  for(int step = 0; step < 2; step++) {
    Ns[step][0] = N[step][0] * sTheta * cPhi + N[step][1] * sTheta * sPhi +
                  N[step][2] * cTheta;
    Ns[step][1] = N[step][0] * cTheta * cPhi + N[step][1] * cTheta * sPhi -
                  N[step][2] * sTheta;
    Ns[step][2] = -N[step][0] * sPhi + N[step][1] * cPhi;

    Ls[step][0] = L[step][0] * sTheta * cPhi + L[step][1] * sTheta * sPhi +
                  L[step][2] * cTheta;
    Ls[step][1] = L[step][0] * cTheta * cPhi + L[step][1] * cTheta * sPhi -
                  L[step][2] * sTheta;
    Ls[step][2] = -L[step][0] * sPhi + L[step][1] * cPhi;
  }

  // E_r radial component is negligible in far field
  double E_theta[2];
  double E_phi[2];
  double k0_over_4pir = k0 / (4 * M_PI * rFar);
  double cos_k0r = cos(k0 * rFar);
  double sin_k0r = sin(k0 * rFar);

  // Elevation component
  E_theta[0] = -k0_over_4pir * ((Ls[0][2] + Z0 * Ns[0][1]) * sin_k0r -
                                (Ls[1][2] + Z0 * Ns[1][1]) * cos_k0r);
  E_theta[1] = -k0_over_4pir * ((Ls[0][2] + Z0 * Ns[0][1]) * cos_k0r +
                                (Ls[1][2] + Z0 * Ns[1][1]) * sin_k0r);
  // Azimuthal component
  E_phi[0] = k0_over_4pir * ((Ls[0][1] - Z0 * Ns[0][2]) * sin_k0r -
                             (Ls[1][1] - Z0 * Ns[1][2]) * cos_k0r);
  E_phi[1] = k0_over_4pir * ((Ls[0][1] - Z0 * Ns[0][2]) * cos_k0r +
                             (Ls[1][1] - Z0 * Ns[1][2]) * sin_k0r);

  double farF = 1. / 2. / Z0 *
                ((E_theta[0] * E_theta[0] + E_theta[1] * E_theta[1]) +
                 (E_phi[0] * E_phi[0] + E_phi[1] * E_phi[1]));

  return farF;
}

// Compute far field using e^{-i\omega t} time dependency, following Monk in
// "Finite Element Methods for Maxwell's equations", p. 233
double GMSH_NearToFarFieldPlugin::getFarFieldMonk(
  const std::vector<SurfaceElement> &elems,
  std::vector<std::vector<double>> &ffvec, std::vector<std::vector<double>> &js,
  std::vector<std::vector<double>> &ms, double k0, double theta, double phi)
{
  double sTheta = sin(theta);
  double cTheta = cos(theta);
  double sPhi = sin(phi);
  double cPhi = cos(phi);
  double xHat[3] = {sTheta * cPhi, sTheta * sPhi, cTheta};
  std::complex<double> I(0., 1.);
  double Z0 = 120 * M_PI; // free-space impedance

  double integral_r[3] = {0., 0., 0.}, integral_i[3] = {0., 0., 0.};
  int i = 0;
  for(auto &e : elems) {
    // the integrals over the element, added to the sums element by element
    double ir[3] = {0., 0., 0.}, ii[3] = {0., 0., 0.};
    for(std::size_t nod = 0; nod < e.w.size(); nod++) {
      double y[3] = {e.x[nod], e.y[nod], e.z[nod]};
      double const xHat_dot_y = prosca(xHat, y);
      double n_x_e_r[3] = {-ms[0][i], -ms[0][i + 1], -ms[0][i + 2]};
      double n_x_e_i[3] = {-ms[1][i], -ms[1][i + 1], -ms[1][i + 2]};
      double n_x_h_r[3] = {js[0][i], js[0][i + 1], js[0][i + 2]};
      double n_x_h_i[3] = {js[1][i], js[1][i + 1], js[1][i + 2]};
      double n_x_h_x_xHat_r[3], n_x_h_x_xHat_i[3];
      prodve(n_x_h_r, xHat, n_x_h_x_xHat_r);
      prodve(n_x_h_i, xHat, n_x_h_x_xHat_i);
      for(int comp = 0; comp < 3; comp++) {
        std::complex<double> n_x_e(n_x_e_r[comp], n_x_e_i[comp]);
        std::complex<double> n_x_h_x_xHat(n_x_h_x_xHat_r[comp],
                                          n_x_h_x_xHat_i[comp]);
        // Warning: Z0 == 1 in Monk
        std::complex<double> integrand =
          (n_x_e + Z0 * n_x_h_x_xHat) *
          (cos(-k0 * xHat_dot_y) + I * sin(-k0 * xHat_dot_y));
        ir[comp] += e.w[nod] * integrand.real();
        ii[comp] += e.w[nod] * integrand.imag();
      }
      i += 3;
    }
    for(int comp = 0; comp < 3; comp++) {
      integral_r[comp] += ir[comp];
      integral_i[comp] += ii[comp];
    }
  }

  double xHat_x_integral_r[3], xHat_x_integral_i[3];
  prodve(xHat, integral_r, xHat_x_integral_r);
  prodve(xHat, integral_i, xHat_x_integral_i);
  std::complex<double> coef = I * k0 / 4. / M_PI;
  std::complex<double> einf[3] = {
    coef * (xHat_x_integral_r[0] + I * xHat_x_integral_i[0]),
    coef * (xHat_x_integral_r[1] + I * xHat_x_integral_i[1]),
    coef * (xHat_x_integral_r[2] + I * xHat_x_integral_i[2])};

  double coef1 = k0 / 4. / M_PI;
  for(int comp = 0; comp < 3; comp++) {
    ffvec[comp][0] = -coef1 * xHat_x_integral_i[comp];
    ffvec[comp][1] = coef1 * xHat_x_integral_r[comp];
  }

  return (norm(einf[0]) + norm(einf[1]) + norm(einf[2]));
}

static void printVector(FILE *fp, const std::string &name,
                        std::vector<std::vector<double> > &vec)
{
  fprintf(fp, "%s = [", name.c_str());
  for(std::size_t i = 0; i < vec.size(); i++)
    for(std::size_t j = 0; j < vec[i].size(); j++)
      fprintf(fp, "%.16g ", vec[i][j]);
  fprintf(fp, "];\n");
}

PView *GMSH_NearToFarFieldPlugin::execute(PView *v)
{
  double _k0 = (double)option(0);
  double _phiStart = (double)option(1);
  double _phiEnd = (double)option(2);
  int _nbPhi = (int)option(3);
  double _thetaStart = (double)option(4);
  double _thetaEnd = (double)option(5);
  int _nbThe = (int)option(6);
  int _eView = (int)option(7);
  int _hView = (int)option(8);
  bool _normalize = (bool)option(9);
  bool _dB = (bool)option(10);
  int _negativeTime = (int)option(11);
  double _rfar = option(12);

  std::string _outFile = optionStr(0);

  if(_nbPhi < 1 || _nbThe < 1) {
    Msg::Error("NearToFarField plugin needs at least one interval in phi and "
               "theta");
    return v;
  }

  PView *ve = getView(_eView, v);
  if(!ve) {
    Msg::Error("NearToFarField plugin could not find EView %i", _eView);
    return v;
  }
  PView *vh = getView(_hView, v);
  if(!vh) {
    Msg::Error("NearToFarField plugin could not find HView %i", _hView);
    return v;
  }
  PViewData *eData = ve->getData();
  PViewData *hData = vh->getData();

  if(eData->getNumEntities() != hData->getNumEntities() ||
     eData->getNumElements() != hData->getNumElements() ||
     eData->getNumTimeSteps() != hData->getNumTimeSteps()) {
    Msg::Error("Incompatible views for E field and H field");
    return v;
  }

  if(eData->getNumTimeSteps() != 2 || hData->getNumTimeSteps() != 2) {
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
     z0 != hData->getBoundingBox().center().z()) {
    Msg::Error("E and H fields must be given on the same grid");
    return v;
  }

  // compute surface currents on all input elements
  std::vector<SurfaceElement> allElems;
  std::vector<std::vector<double> > js(2);
  std::vector<std::vector<double> > ms(2);

  for(int ent = 0; ent < eData->getNumEntities(0); ent++) {
    for(int ele = 0; ele < eData->getNumElements(0, ent); ele++) {
      if(eData->skipElement(0, ent, ele)) continue;
      if(hData->skipElement(0, ent, ele)) continue;
      int numComp = eData->getNumComponents(0, ent, ele);
      if(numComp != 3) continue;
      int dim = eData->getDimension(0, ent, ele);
      if(dim != 1 && dim != 2) continue;
      int numNodes = eData->getNumNodes(0, ent, ele);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
        eData->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);

      elementFactory factory;
      element *el = factory.create(numNodes, dim, &x[0], &y[0], &z[0]);
      SurfaceElement se{x, y, z, std::vector<double>(numNodes, 0.)};
      for(int g = 0; g < el->getNumGaussPoints(); g++) {
        double u, v, w, weight, jac[3][3];
        el->getGaussPoint(g, u, v, w, weight);
        double det = el->getJacobian(u, v, w, jac);
        for(int nod = 0; nod < numNodes; nod++) {
          double sf;
          el->getShapeFunction(nod, u, v, w, sf);
          se.w[nod] += sf * weight * det;
        }
      }
      delete el;
      allElems.push_back(se);

      double n[3] = {0., 0., 0.};
      if(numNodes > 2)
        normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
      else
        normal2points(x[0], y[0], z[0], x[1], y[1], z[1], n);

      for(int step = 0; step < 2; step++) {
        for(int nod = 0; nod < numNodes; nod++) {
          double h[3], e[3];
          for(int comp = 0; comp < numComp; comp++) {
            eData->getValue(step, ent, ele, nod, comp, e[comp]);
            hData->getValue(step, ent, ele, nod, comp, h[comp]);
          }
          double j[3], m[3];
          prodve(n, h, j); // Js =   n x H ; Surface electric current
          prodve(e, n, m); // Ms = - n x E ; Surface magnetic current
          js[step].push_back(j[0]);
          js[step].push_back(j[1]);
          js[step].push_back(j[2]);
          ms[step].push_back(m[0]);
          ms[step].push_back(m[1]);
          ms[step].push_back(m[2]);
        }
      }
    }
  }

  if(allElems.empty()) {
    Msg::Error("No valid elements found to compute far field");
    return v;
  }

  // view for far field that will contain the radiation pattern
  PView *vf = new PView();
  PViewDataList *dataFar = getDataList(vf);

  std::vector<std::vector<double> > phi(_nbPhi + 1), theta(_nbPhi + 1);
  std::vector<std::vector<double> > x(_nbPhi + 1), y(_nbPhi + 1), z(_nbPhi + 1);
  std::vector<std::vector<double> > farField(_nbPhi + 1);
  std::vector<std::vector<double> > farField1r(_nbPhi + 1);
  std::vector<std::vector<double> > farField2r(_nbPhi + 1);
  std::vector<std::vector<double> > farField3r(_nbPhi + 1);
  std::vector<std::vector<double> > farField1i(_nbPhi + 1);
  std::vector<std::vector<double> > farField2i(_nbPhi + 1);
  std::vector<std::vector<double>> farField3i(_nbPhi + 1);

  for(int i = 0; i <= _nbPhi; i++) {
    phi[i].resize(_nbThe + 1);
    theta[i].resize(_nbThe + 1);
    x[i].resize(_nbThe + 1);
    y[i].resize(_nbThe + 1);
    z[i].resize(_nbThe + 1);
    farField[i].resize(_nbThe + 1);

    farField1r[i].resize(_nbThe + 1);
    farField2r[i].resize(_nbThe + 1);
    farField3r[i].resize(_nbThe + 1);
    farField1i[i].resize(_nbThe + 1);
    farField2i[i].resize(_nbThe + 1);
    farField3i[i].resize(_nbThe + 1);
  }

  double dPhi = (_phiEnd - _phiStart) / _nbPhi;
  double dTheta = (_thetaEnd - _thetaStart) / _nbThe;
  double ffmin = 1e200, ffmax = -1e200;
  // the directions, in parallel
  int numDirs = (_nbPhi + 1) * (_nbThe + 1);
  int nthreads = CTX::instance()->numThreadsFor(
    (std::size_t)numDirs * allElems.size(), 100000);
#pragma omp parallel for num_threads(nthreads) schedule(dynamic, 1)
  for(int d = 0; d < numDirs; d++) {
    int i = d / (_nbThe + 1), j = d % (_nbThe + 1);
    phi[i][j] = _phiStart + i * dPhi;
    theta[i][j] = _thetaStart + j * dTheta;
    if(_negativeTime) {
      std::vector<std::vector<double>> ffvec(3, std::vector<double>(2));
      farField[i][j] =
        getFarFieldMonk(allElems, ffvec, js, ms, _k0, theta[i][j], phi[i][j]);
      farField1r[i][j] = ffvec[0][0];
      farField2r[i][j] = ffvec[1][0];
      farField3r[i][j] = ffvec[2][0];
      farField1i[i][j] = ffvec[0][1];
      farField2i[i][j] = ffvec[1][1];
      farField3i[i][j] = ffvec[2][1];
    }
    else {
      double rfar = (_rfar ? _rfar : 10 * lc);
      farField[i][j] =
        getFarFieldJin(allElems, js, ms, _k0, rfar, theta[i][j], phi[i][j]);
    }
  }
  for(int i = 0; i <= _nbPhi; i++) {
    for(int j = 0; j <= _nbThe; j++) {
      ffmin = std::min(ffmin, farField[i][j]);
      ffmax = std::max(ffmax, farField[i][j]);
    }
  }

  if(_normalize) {
    if(!ffmax)
      Msg::Warning("Cannot normalize far field (max = 0)");
    else
      for(int i = 0; i <= _nbPhi; i++)
        for(int j = 0; j <= _nbThe; j++) farField[i][j] /= ffmax;
  }

  if(_dB) {
    ffmin = 1e200;
    ffmax = -1e200;
    for(int i = 0; i <= _nbPhi; i++) {
      for(int j = 0; j <= _nbThe; j++) {
        farField[i][j] = 10 * log10(farField[i][j]);
        ffmin = std::min(ffmin, farField[i][j]);
        ffmax = std::max(ffmax, farField[i][j]);
      }
    }
  }

  for(int i = 0; i <= _nbPhi; i++) {
    for(int j = 0; j <= _nbThe; j++) {
      double df = (ffmax - ffmin);
      if(!df) {
        Msg::Warning("zero far field range");
        df = 1.;
      }
      double f = (farField[i][j] - ffmin) / df; // in [0,1]
      x[i][j] = x0 + r_sph * f * sin(theta[i][j]) * cos(phi[i][j]);
      y[i][j] = y0 + r_sph * f * sin(theta[i][j]) * sin(phi[i][j]);
      z[i][j] = z0 + r_sph * f * cos(theta[i][j]);
    }
  }

  if(_outFile.size()) {
    FILE *fp = Fopen(_outFile.c_str(), "w");
    if(fp) {
      printVector(fp, "phi", phi);
      printVector(fp, "theta", theta);
      printVector(fp, "farField", farField);

      if(_negativeTime) {
        printVector(fp, "farField1r", farField1r);
        printVector(fp, "farField2r", farField2r);
        printVector(fp, "farField3r", farField3r);
        printVector(fp, "farField1i", farField1i);
        printVector(fp, "farField2i", farField2i);
        printVector(fp, "farField3i", farField3i);
      }

      printVector(fp, "x", x);
      printVector(fp, "y", y);
      printVector(fp, "z", z);
      fclose(fp);
    }
    else
      Msg::Error("Could not open file '%s'", _outFile.c_str());
  }

  // points (all of them) if there is a single interval in phi or theta,
  // quadrangles otherwise
  int points = (_nbPhi == 1 || _nbThe == 1) ? 1 : 0;
  for(int i = 0; i < _nbPhi + points; i++) {
    for(int j = 0; j < _nbThe + points; j++) {
      if(points) {
        std::vector<double> *l = dataFar->incrementList(1, TYPE_PNT);
        l->insert(l->end(), {x[i][j], y[i][j], z[i][j], farField[i][j]});
      }
      else {
        double P1[3] = {x[i][j], y[i][j], z[i][j]};
        double P2[3] = {x[i + 1][j], y[i + 1][j], z[i + 1][j]};
        double P3[3] = {x[i + 1][j + 1], y[i + 1][j + 1], z[i + 1][j + 1]};
        double P4[3] = {x[i][j + 1], y[i][j + 1], z[i][j + 1]};
        std::vector<double> *l = dataFar->incrementList(1, TYPE_QUA);
        for(int k = 0; k < 3; k++)
          l->insert(l->end(), {P1[k], P2[k], P3[k], P4[k]});
        l->insert(l->end(), {farField[i][j], farField[i + 1][j],
                             farField[i + 1][j + 1], farField[i][j + 1]});
      }
    }
  }

  dataFar->setName("_NearToFarField");
  dataFar->setFileName("_NearToFarField.pos");
  dataFar->finalize();

  return vf;
}
