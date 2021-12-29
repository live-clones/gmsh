// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "PView.h"
#include "PViewDataList.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "BasisFactory.h"
#include "Numeric.h"
#include "SmoothData.h"
#include "Context.h"
#include "polynomialBasis.h"

PViewDataList::PViewDataList(bool isAdapted)
  : PViewData(), NbTimeStep(0), Min(VAL_INF), Max(-VAL_INF), NbSP(0), NbVP(0),
    NbTP(0), NbSL(0), NbVL(0), NbTL(0), NbST(0), NbVT(0), NbTT(0), NbSQ(0),
    NbVQ(0), NbTQ(0), NbSG(0), NbVG(0), NbTG(0), NbSS(0), NbVS(0), NbTS(0),
    NbSH(0), NbVH(0), NbTH(0), NbSI(0), NbVI(0), NbTI(0), NbSY(0), NbVY(0),
    NbTY(0), NbSR(0), NbVR(0), NbTR(0), NbSD(0), NbVD(0), NbTD(0), NbT2(0),
    NbT3(0), _lastElement(-1), _lastDimension(-1), _lastNumNodes(-1),
    _lastNumComponents(-1), _lastNumValues(-1), _lastNumEdges(-1),
    _lastType(-1), _lastXYZ(nullptr), _lastVal(nullptr), _isAdapted(isAdapted)
{
  for(int i = 0; i < 33; i++) _index[i] = 0;
  polyTotNumNodes[0] = 0.;
  polyTotNumNodes[1] = 0.;
  polyAgNumNodes[0].push_back(0.);
  polyAgNumNodes[1].push_back(0.);
}

void PViewDataList::setXY(std::vector<double> &x, std::vector<double> &y)
{
  NbSP = 0;
  SP.clear();
  for(std::size_t i = 0; i < std::min(x.size(), y.size()); i++) {
    SP.push_back(x[i]);
    SP.push_back(0.);
    SP.push_back(0.);
    SP.push_back(y[i]);
    NbSP++;
  }
  finalize();
}

void PViewDataList::setXYZV(std::vector<double> &x, std::vector<double> &y,
                            std::vector<double> &z, std::vector<double> &v)
{
  NbSP = 0;
  SP.clear();
  int n = std::min(std::min(std::min(x.size(), y.size()), z.size()), v.size());
  for(int i = 0; i < n; i++) {
    SP.push_back(x[i]);
    SP.push_back(y[i]);
    SP.push_back(z[i]);
    SP.push_back(v[i]);
    NbSP++;
  }
  finalize();
}

void PViewDataList::addStep(std::vector<double> &y)
{
  if(NbSP != (int)y.size()) {
    Msg::Error("Wrong number of values while adding step in list-based view");
    return;
  }
  // This is not very efficient, but well... ;-)
  std::vector<double> tmp;
  int stride = SP.size() / NbSP;
  for(int i = 0; i < NbSP; i++) {
    for(int j = 0; j < stride; j++) tmp.push_back(SP[i * stride + j]);
    tmp.push_back(y[i]);
  }
  SP = tmp;
  finalize();
}

bool PViewDataList::finalize(bool computeMinMax,
                             const std::string &interpolationScheme)
{
  BBox.reset();
  Min = VAL_INF;
  Max = -VAL_INF;

  // finalize text strings first, to get the max value of NbTimeStep
  // for strings-only views (strings are designed to degrade
  // gracefully when some have fewer time steps than others). If there
  // are any elements in the view, this value will be replaced by the
  // minimum number of time steps common to all elements.
  _stat(T2D, T2C, 4);
  _stat(T3D, T3C, 5);

  // compute min/max and other statistics for all element lists
  _stat(SP, 1, NbSP, 1, TYPE_PNT);
  _stat(VP, 3, NbVP, 1, TYPE_PNT);
  _stat(TP, 9, NbTP, 1, TYPE_PNT);
  _stat(SL, 1, NbSL, 2, TYPE_LIN);
  _stat(VL, 3, NbVL, 2, TYPE_LIN);
  _stat(TL, 9, NbTL, 2, TYPE_LIN);
  _stat(ST, 1, NbST, 3, TYPE_TRI);
  _stat(VT, 3, NbVT, 3, TYPE_TRI);
  _stat(TT, 9, NbTT, 3, TYPE_TRI);
  _stat(SQ, 1, NbSQ, 4, TYPE_QUA);
  _stat(VQ, 3, NbVQ, 4, TYPE_QUA);
  _stat(TQ, 9, NbTQ, 4, TYPE_QUA);
  _stat(SS, 1, NbSS, 4, TYPE_TET);
  _stat(VS, 3, NbVS, 4, TYPE_TET);
  _stat(TS, 9, NbTS, 4, TYPE_TET);
  _stat(SH, 1, NbSH, 8, TYPE_HEX);
  _stat(VH, 3, NbVH, 8, TYPE_HEX);
  _stat(TH, 9, NbTH, 8, TYPE_HEX);
  _stat(SI, 1, NbSI, 6, TYPE_PRI);
  _stat(VI, 3, NbVI, 6, TYPE_PRI);
  _stat(TI, 9, NbTI, 6, TYPE_PRI);
  _stat(SY, 1, NbSY, 5, TYPE_PYR);
  _stat(VY, 3, NbVY, 5, TYPE_PYR);
  _stat(TY, 9, NbTY, 5, TYPE_PYR);
  _stat(SY, 1, NbSR, 4, TYPE_TRIH);
  _stat(VY, 3, NbVR, 4, TYPE_TRIH);
  _stat(TY, 9, NbTR, 4, TYPE_TRIH);
  _stat(SG, 1, NbSG, 3, TYPE_POLYG);
  _stat(VG, 3, NbVG, 3, TYPE_POLYG);
  _stat(TG, 9, NbTG, 3, TYPE_POLYG);
  _stat(SD, 1, NbSD, 4, TYPE_POLYH);
  _stat(VD, 3, NbVD, 4, TYPE_POLYH);
  _stat(TD, 9, NbTD, 4, TYPE_POLYH);

  // add dummy time values if none (or too few) time values are
  // provided (e.g. using the old parsed format)
  if((int)Time.size() < NbTimeStep) {
    for(int i = Time.size(); i < NbTimeStep; i++) Time.push_back(i);
  }

  // compute starting element indices
  int nb[33] = {NbSP, NbVP, NbTP, NbSL, NbVL, NbTL, NbST, NbVT, NbTT,
                NbSQ, NbVQ, NbTQ, NbSS, NbVS, NbTS, NbSH, NbVH, NbTH,
                NbSI, NbVI, NbTI, NbSY, NbVY, NbTY, NbSR, NbVR, NbTR,
                NbSG, NbVG, NbTG, NbSD, NbVD, NbTD};
  for(int i = 0; i < 33; i++) {
    _index[i] = 0;
    for(int j = 0; j <= i; j++) _index[i] += nb[j];
  }

  if(CTX::instance()->post.smooth) smooth();

  return PViewData::finalize();
}

int PViewDataList::getNumScalars(int step)
{
  return NbSP + NbSL + NbST + NbSQ + NbSS + NbSH + NbSI + NbSY + NbSR + NbSG +
         NbSD;
}

int PViewDataList::getNumVectors(int step)
{
  return NbVP + NbVL + NbVT + NbVQ + NbVS + NbVH + NbVI + NbVY + NbVR + NbVG +
         NbVD;
}

int PViewDataList::getNumTensors(int step)
{
  return NbTP + NbTL + NbTT + NbTQ + NbTS + NbTH + NbTI + NbTY + NbTR + NbTG +
         NbTD;
}

int PViewDataList::getNumElements(int step, int ent)
{
  return getNumScalars() + getNumVectors() + getNumTensors();
}

double PViewDataList::getTime(int step)
{
  if(step < 0 || step >= (int)Time.size()) return 0.;
  return Time[step];
}

double PViewDataList::getMin(int step, bool onlyVisible, int tensorRep,
                             int forceNumComponents, int componentMap[9])
{
  if(step >= (int)TimeStepMin.size()) return Min;

  if(forceNumComponents || tensorRep) {
    double vmin = VAL_INF;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double val;
          getScalarValue(step, ent, ele, nod, val, tensorRep,
                         forceNumComponents, componentMap);
          vmin = std::min(vmin, val);
        }
      }
    }
    return vmin;
  }

  if(step < 0) return Min;
  return TimeStepMin[step];
}

double PViewDataList::getMax(int step, bool onlyVisible, int tensorRep,
                             int forceNumComponents, int componentMap[9])
{
  if(step >= (int)TimeStepMax.size()) return Max;

  if(forceNumComponents || tensorRep) {
    double vmax = -VAL_INF;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double val;
          getScalarValue(step, ent, ele, nod, val, tensorRep,
                         forceNumComponents, componentMap);
          vmax = std::max(vmax, val);
        }
      }
    }
    return vmax;
  }

  if(step < 0) return Max;
  return TimeStepMax[step];
}

void PViewDataList::_stat(std::vector<double> &D, std::vector<char> &C, int nb)
{
  // compute statistics for text lists
  for(std::size_t i = 0; i < D.size(); i += nb) {
    double beg = D[i + nb - 1];
    double end;
    if(i + 2 * nb > D.size())
      end = C.size();
    else
      end = D[i + nb + nb - 1];
    char *c = &C[(int)beg];
    int nbtime = 0;
    for(int j = 0; j < (int)(end - beg); j++)
      if(c[j] == '\0') nbtime++;
    if(nbtime > NbTimeStep) NbTimeStep = nbtime;
  }
  if(nb == 5) {
    for(std::size_t i = 0; i < D.size(); i += nb)
      BBox += SPoint3(D[i], D[i + 1], D[i + 2]);
  }
}

void PViewDataList::_stat(std::vector<double> &list, int nbcomp, int nbelm,
                          int nbnod, int type)
{
  // compute statistics for element lists
  if(!nbelm) return;

  int nbval = nbcomp * nbnod;

  if(haveInterpolationMatrices()) {
    std::vector<fullMatrix<double> *> im;
    int nim = getInterpolationMatrices(type, im);
    if(nim == 4) nbnod = im[2]->size1();
    if(nim) nbval = nbcomp * im[0]->size1();
  }

  int nb = list.size() / nbelm;
  for(int ele = 0; ele < nbelm; ele++) {
    int i = ele * nb;
    if(type == TYPE_POLYG || type == TYPE_POLYH) {
      int t = (type == TYPE_POLYG) ? 0 : 1;
      nbnod = polyNumNodes[t][ele];
      nb = list.size() / polyTotNumNodes[t] * nbnod;
      i = polyAgNumNodes[t][ele] * nb / nbnod;
      nbval = nbcomp * nbnod;
    }
    int N = nb - 3 * nbnod;
    double *X = &list[i];
    double *Y = &list[i + 1 * nbnod];
    double *Z = &list[i + 2 * nbnod];
    double *V = &list[i + 3 * nbnod];

    // update bounding box
    for(int j = 0; j < nbnod; j++) BBox += SPoint3(X[j], Y[j], Z[j]);

    // update num time steps
    if(Min == VAL_INF || Max == -VAL_INF) {
      NbTimeStep = N / nbval;
      TimeStepMin.clear();
      TimeStepMax.clear();
      for(int j = 0; j < NbTimeStep; j++) {
        TimeStepMin.push_back(VAL_INF);
        TimeStepMax.push_back(-VAL_INF);
      }
    }
    else if(N / nbval < NbTimeStep) {
      // if some elts have less steps, reduce the total number!
      NbTimeStep = N / nbval;
    }

    // update min/max
    int tensorRep = 0; // Von-Mises: we could/should be able to choose this
    for(int j = 0; j < N; j += nbcomp) {
      double l0 = ComputeScalarRep(nbcomp, &V[j], tensorRep);
      Min = std::min(l0, Min);
      Max = std::max(l0, Max);
      int ts = j / nbval;
      if(ts < NbTimeStep) { // security
        TimeStepMin[ts] = std::min(l0, TimeStepMin[ts]);
        TimeStepMax[ts] = std::max(l0, TimeStepMax[ts]);
      }
    }
  }
}

void PViewDataList::_setLast(int ele, int dim, int nbnod, int nbcomp, int nbedg,
                             int type, std::vector<double> &list, int nblist)
{
  if(haveInterpolationMatrices()) {
    std::vector<fullMatrix<double> *> im;
    if(getInterpolationMatrices(type, im) == 4) nbnod = im[2]->size1();
  }

  _lastDimension = dim;
  _lastNumNodes = nbnod;
  _lastNumComponents = nbcomp;
  _lastNumEdges = nbedg;
  _lastType = type;
  int nb = list.size() / nblist; // number of coords and values for the element
  int nbAg =
    ele * nb; // number of coords and values before the ones of the element
  if(type == TYPE_POLYG || type == TYPE_POLYH) {
    int t = (type == TYPE_POLYG) ? 0 : 1;
    nb = list.size() / polyTotNumNodes[t] * nbnod;
    nbAg = polyAgNumNodes[t][ele] * nb / nbnod;
  }
  _lastNumValues = (nb - 3 * nbnod) / NbTimeStep;
  _lastXYZ = &list[nbAg];
  _lastVal = &list[nbAg + 3 * _lastNumNodes];
}

void PViewDataList::_setLast(int ele)
{
  _lastElement = ele;
  if(ele < _index[2]) { // points
    if(ele < _index[0])
      _setLast(ele, 0, 1, 1, 0, TYPE_PNT, SP, NbSP);
    else if(ele < _index[1])
      _setLast(ele - _index[0], 0, 1, 3, 0, TYPE_PNT, VP, NbVP);
    else
      _setLast(ele - _index[1], 0, 1, 9, 0, TYPE_PNT, TP, NbTP);
  }
  else if(ele < _index[5]) { // lines
    if(ele < _index[3])
      _setLast(ele - _index[2], 1, 2, 1, 1, TYPE_LIN, SL, NbSL);
    else if(ele < _index[4])
      _setLast(ele - _index[3], 1, 2, 3, 1, TYPE_LIN, VL, NbVL);
    else
      _setLast(ele - _index[4], 1, 2, 9, 1, TYPE_LIN, TL, NbTL);
  }
  else if(ele < _index[8]) { // triangles
    if(ele < _index[6])
      _setLast(ele - _index[5], 2, 3, 1, 3, TYPE_TRI, ST, NbST);
    else if(ele < _index[7])
      _setLast(ele - _index[6], 2, 3, 3, 3, TYPE_TRI, VT, NbVT);
    else
      _setLast(ele - _index[7], 2, 3, 9, 3, TYPE_TRI, TT, NbTT);
  }
  else if(ele < _index[11]) { // quadrangles
    if(ele < _index[9])
      _setLast(ele - _index[8], 2, 4, 1, 4, TYPE_QUA, SQ, NbSQ);
    else if(ele < _index[10])
      _setLast(ele - _index[9], 2, 4, 3, 4, TYPE_QUA, VQ, NbVQ);
    else
      _setLast(ele - _index[10], 2, 4, 9, 4, TYPE_QUA, TQ, NbTQ);
  }
  else if(ele < _index[14]) { // tetrahedra
    if(ele < _index[12])
      _setLast(ele - _index[11], 3, 4, 1, 6, TYPE_TET, SS, NbSS);
    else if(ele < _index[13])
      _setLast(ele - _index[12], 3, 4, 3, 6, TYPE_TET, VS, NbVS);
    else
      _setLast(ele - _index[13], 3, 4, 9, 6, TYPE_TET, TS, NbTS);
  }
  else if(ele < _index[17]) { // hexahedra
    if(ele < _index[15])
      _setLast(ele - _index[14], 3, 8, 1, 12, TYPE_HEX, SH, NbSH);
    else if(ele < _index[16])
      _setLast(ele - _index[15], 3, 8, 3, 12, TYPE_HEX, VH, NbVH);
    else
      _setLast(ele - _index[16], 3, 8, 9, 12, TYPE_HEX, TH, NbTH);
  }
  else if(ele < _index[20]) { // prisms
    if(ele < _index[18])
      _setLast(ele - _index[17], 3, 6, 1, 9, TYPE_PRI, SI, NbSI);
    else if(ele < _index[19])
      _setLast(ele - _index[18], 3, 6, 3, 9, TYPE_PRI, VI, NbVI);
    else
      _setLast(ele - _index[19], 3, 6, 9, 9, TYPE_PRI, TI, NbTI);
  }
  else if(ele < _index[23]) { // pyramids
    if(ele < _index[21])
      _setLast(ele - _index[20], 3, 5, 1, 8, TYPE_PYR, SY, NbSY);
    else if(ele < _index[22])
      _setLast(ele - _index[21], 3, 5, 3, 8, TYPE_PYR, VY, NbVY);
    else
      _setLast(ele - _index[22], 3, 5, 9, 8, TYPE_PYR, TY, NbTY);
  }
  else if(ele < _index[26]) { // trihedra
    if(ele < _index[24])
      _setLast(ele - _index[23], 3, 4, 1, 5, TYPE_TRIH, SR, NbSR);
    else if(ele < _index[25])
      _setLast(ele - _index[24], 3, 4, 3, 5, TYPE_TRIH, VR, NbVR);
    else
      _setLast(ele - _index[25], 3, 4, 9, 5, TYPE_TRIH, TR, NbTR);
  }
  else if(ele < _index[29]) { // polygons
    int nN = polyNumNodes[0][ele - _index[26]];
    if(ele < _index[27])
      _setLast(ele - _index[26], 2, nN, 1, nN, TYPE_POLYG, SG, NbSG);
    else if(ele < _index[28])
      _setLast(ele - _index[27], 2, nN, 3, nN, TYPE_POLYG, VG, NbVG);
    else
      _setLast(ele - _index[28], 2, nN, 9, nN, TYPE_POLYG, TG, NbTG);
  }
  else if(ele < _index[32]) { // polyhedra
    int nN = polyNumNodes[1][ele - _index[29]];
    if(ele < _index[30])
      _setLast(ele - _index[29], 3, nN, 1, nN * 1.5, TYPE_POLYH, SD, NbSD);
    else if(ele < _index[32])
      _setLast(ele - _index[30], 3, nN, 3, nN * 1.5, TYPE_POLYH, VD, NbVD);
    else
      _setLast(ele - _index[31], 3, nN, 9, nN * 1.5, TYPE_POLYH, TD, NbTD);
  }
}

int PViewDataList::getDimension(int step, int ent, int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastDimension;
}

int PViewDataList::getNumNodes(int step, int ent, int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastNumNodes;
}

int PViewDataList::getNode(int step, int ent, int ele, int nod, double &x,
                           double &y, double &z)
{
  if(ele != _lastElement) _setLast(ele);
  x = _lastXYZ[nod];
  y = _lastXYZ[_lastNumNodes + nod];
  z = _lastXYZ[2 * _lastNumNodes + nod];
  return 0;
}

void PViewDataList::setNode(int step, int ent, int ele, int nod, double x,
                            double y, double z)
{
  if(step) return;
  if(ele != _lastElement) _setLast(ele);
  _lastXYZ[nod] = x;
  _lastXYZ[_lastNumNodes + nod] = y;
  _lastXYZ[2 * _lastNumNodes + nod] = z;
}

int PViewDataList::getNumComponents(int step, int ent, int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastNumComponents;
}

int PViewDataList::getNumValues(int step, int ent, int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastNumValues;
}

void PViewDataList::getValue(int step, int ent, int ele, int idx, double &val)
{
  if(ele != _lastElement) _setLast(ele);
  if(step >= NbTimeStep) step = 0;
  val = _lastVal[step * _lastNumValues + idx];
}

void PViewDataList::getValue(int step, int ent, int ele, int nod, int comp,
                             double &val)
{
  if(ele != _lastElement) _setLast(ele);
  if(step >= NbTimeStep) step = 0;
  val = _lastVal[step * _lastNumNodes * _lastNumComponents +
                 nod * _lastNumComponents + comp];
}

void PViewDataList::setValue(int step, int ent, int ele, int nod, int comp,
                             double val)
{
  if(ele != _lastElement) _setLast(ele);
  if(step >= NbTimeStep) step = 0;
  _lastVal[step * _lastNumNodes * _lastNumComponents +
           nod * _lastNumComponents + comp] = val;
}

int PViewDataList::getNumEdges(int step, int ent, int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastNumEdges;
}

int PViewDataList::getType(int step, int ent, int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastType;
}

void PViewDataList::_getString(int dim, int i, int step, std::string &str,
                               double &x, double &y, double &z, double &style)
{
  // 3D: T3D is a list of double: x,y,z,style,index,x,y,z,style,index,...
  //     T3C is a list of chars: string\0,string\0,string\0,string\0,...
  //     Parser format is: T3(x,y,z,style){"str","str",...};
  // 2D: T2D is a list of double: x,y,style,index,x,y,style,index,...
  //     T2C is a list of chars: string\0,string\0,string\0,string\0,...
  //     Parser format is: T2(x,y,style){"str","str",...};

  std::vector<double> &td = (dim == 2) ? T2D : T3D;
  std::vector<char> &tc = (dim == 2) ? T2C : T3C;
  int nbd = (dim == 2) ? 4 : 5;

  int index, nbchar;
  double *d1 = &td[i * nbd];
  double *d2 = ((i + 1) * nbd < (int)td.size()) ? &td[(i + 1) * nbd] : nullptr;

  if(dim == 2) {
    x = d1[0];
    y = d1[1];
    z = 0.;
    style = d1[2];
    index = (int)d1[3];
    if(d2)
      nbchar = (int)d2[3] - index;
    else
      nbchar = tc.size() - index;
  }
  else {
    x = d1[0];
    y = d1[1];
    z = d1[2];
    style = d1[3];
    index = (int)d1[4];
    if(d2)
      nbchar = (int)d2[4] - index;
    else
      nbchar = tc.size() - index;
  }

  char *c = &tc[index];
  int k = 0, l = 0;
  while(k < nbchar && l != step) {
    if(c[k++] == '\0') l++;
  }
  if(k < nbchar && l == step)
    str = std::string(&c[k]);
  else
    str = std::string(c);
}

void PViewDataList::getString2D(int i, int step, std::string &str, double &x,
                                double &y, double &style)
{
  double z;
  _getString(2, i, step, str, x, y, z, style);
}

void PViewDataList::getString3D(int i, int step, std::string &str, double &x,
                                double &y, double &z, double &style)
{
  _getString(3, i, step, str, x, y, z, style);
}

void PViewDataList::reverseElement(int step, int ent, int ele)
{
  if(step) return;
  if(ele != _lastElement) _setLast(ele);

  // copy data
  std::vector<double> XYZ(3 * _lastNumNodes);
  for(std::size_t i = 0; i < XYZ.size(); i++) XYZ[i] = _lastXYZ[i];

  std::vector<double> V(_lastNumNodes * _lastNumComponents * getNumTimeSteps());
  for(std::size_t i = 0; i < V.size(); i++) V[i] = _lastVal[i];

  // reverse node order
  for(int i = 0; i < _lastNumNodes; i++) {
    _lastXYZ[i] = XYZ[_lastNumNodes - i - 1];
    _lastXYZ[_lastNumNodes + i] = XYZ[2 * _lastNumNodes - i - 1];
    _lastXYZ[2 * _lastNumNodes + i] = XYZ[3 * _lastNumNodes - i - 1];
  }

  for(int step = 0; step < getNumTimeSteps(); step++)
    for(int i = 0; i < _lastNumNodes; i++)
      for(int k = 0; k < _lastNumComponents; k++)
        _lastVal[_lastNumComponents * _lastNumNodes * step +
                 _lastNumComponents * i + k] =
          V[_lastNumComponents * _lastNumNodes * step +
            _lastNumComponents * (_lastNumNodes - i - 1) + k];
}

static void generateConnectivities(std::vector<double> &list, int nbList,
                                   int nbTimeStep, int nbVert, int nbComp,
                                   smooth_data &data)
{
  if(!nbList) return;
  double *vals = new double[nbTimeStep * nbComp];
  int nb = list.size() / nbList;
  for(std::size_t i = 0; i < list.size(); i += nb) {
    double *x = &list[i];
    double *y = &list[i + nbVert];
    double *z = &list[i + 2 * nbVert];
    double *v = &list[i + 3 * nbVert];
    for(int j = 0; j < nbVert; j++) {
      for(int ts = 0; ts < nbTimeStep; ts++)
        for(int k = 0; k < nbComp; k++)
          vals[nbComp * ts + k] = v[nbVert * nbComp * ts + nbComp * j + k];
      data.add(x[j], y[j], z[j], nbTimeStep * nbComp, vals);
    }
  }
  delete[] vals;
}

static void smoothList(std::vector<double> &list, int nbList, int nbTimeStep,
                       int nbVert, int nbComp, smooth_data &data)
{
  if(!nbList) return;
  double *vals = new double[nbTimeStep * nbComp];
  int nb = list.size() / nbList;
  for(std::size_t i = 0; i < list.size(); i += nb) {
    double *x = &list[i];
    double *y = &list[i + nbVert];
    double *z = &list[i + 2 * nbVert];
    double *v = &list[i + 3 * nbVert];
    for(int j = 0; j < nbVert; j++) {
      if(data.get(x[j], y[j], z[j], nbTimeStep * nbComp, vals)) {
        for(int ts = 0; ts < nbTimeStep; ts++)
          for(int k = 0; k < nbComp; k++)
            v[nbVert * nbComp * ts + nbComp * j + k] = vals[nbComp * ts + k];
      }
    }
  }
  delete[] vals;
}

void PViewDataList::smooth()
{
  double old_eps = xyzv::eps;
  xyzv::eps = CTX::instance()->lc * 1.e-8;
  smooth_data data;

  std::vector<double> *list = nullptr;
  int *nbe = nullptr, nbc, nbn;
  for(int i = 0; i < 27; i++) {
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    if(nbn > 1) generateConnectivities(*list, *nbe, NbTimeStep, nbn, nbc, data);
  }
  for(int i = 0; i < 27; i++) {
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    if(nbn > 1) smoothList(*list, *nbe, NbTimeStep, nbn, nbc, data);
  }
  xyzv::eps = old_eps;
  finalize();
}

double PViewDataList::getMemoryInMb()
{
  double b = 0.;
  b += (TimeStepMin.size() + TimeStepMax.size() + Time.size()) * sizeof(double);
  b += (SP.size() + VP.size() + TP.size()) * sizeof(double);
  b += (SL.size() + VL.size() + TL.size()) * sizeof(double);
  b += (ST.size() + VT.size() + TT.size()) * sizeof(double);
  b += (SQ.size() + VQ.size() + TQ.size()) * sizeof(double);
  b += (SG.size() + VG.size() + TG.size()) * sizeof(double);
  b += (SS.size() + VS.size() + TS.size()) * sizeof(double);
  b += (SH.size() + VH.size() + TH.size()) * sizeof(double);
  b += (SI.size() + VI.size() + TI.size()) * sizeof(double);
  b += (SY.size() + VY.size() + TY.size()) * sizeof(double);
  b += (SR.size() + VR.size() + TR.size()) * sizeof(double);
  b += (SD.size() + VD.size() + TD.size()) * sizeof(double);
  b += (T2D.size() + T3D.size()) * sizeof(double);
  return b / 1024. / 1024.;
}

static void dVecMerge(std::vector<double> &v, std::vector<double> &dest)
{
  for(std::size_t i = 0; i < v.size(); i++) dest.push_back(v[i]);
}

bool PViewDataList::combineSpace(nameData &nd)
{
  // sanity checks
  if(nd.data.size() < 2) return false;
  int ts = nd.data[0]->getNumTimeSteps();
  for(std::size_t i = 1; i < nd.data.size(); i++) {
    if(!nd.data[i]->empty() && nd.data[i]->getNumTimeSteps() != ts) {
      Msg::Error("Cannot combine views having different number of time steps");
      return false;
    }
  }

  for(std::size_t i = 0; i < nd.data.size(); i++) {
    PViewDataList *l = dynamic_cast<PViewDataList *>(nd.data[i]);
    if(!l) {
      Msg::Error("Cannot combine hybrid data");
      return false;
    }

    // copy interpolation matrices
    for(auto it = l->_interpolation.begin(); it != l->_interpolation.end();
        it++)
      if(_interpolation[it->first].empty())
        for(std::size_t i = 0; i < it->second.size(); i++)
          _interpolation[it->first].push_back(
            new fullMatrix<double>(*it->second[i]));

    // copy time values

    if(!i) Time = l->Time;

    // merge elememts
    dVecMerge(l->SP, SP);
    NbSP += l->NbSP;
    dVecMerge(l->VP, VP);
    NbVP += l->NbVP;
    dVecMerge(l->TP, TP);
    NbTP += l->NbTP;
    dVecMerge(l->SL, SL);
    NbSL += l->NbSL;
    dVecMerge(l->VL, VL);
    NbVL += l->NbVL;
    dVecMerge(l->TL, TL);
    NbTL += l->NbTL;
    dVecMerge(l->ST, ST);
    NbST += l->NbST;
    dVecMerge(l->VT, VT);
    NbVT += l->NbVT;
    dVecMerge(l->TT, TT);
    NbTT += l->NbTT;
    dVecMerge(l->SQ, SQ);
    NbSQ += l->NbSQ;
    dVecMerge(l->VQ, VQ);
    NbVQ += l->NbVQ;
    dVecMerge(l->TQ, TQ);
    NbTQ += l->NbTQ;
    dVecMerge(l->SS, SS);
    NbSS += l->NbSS;
    dVecMerge(l->VS, VS);
    NbVS += l->NbVS;
    dVecMerge(l->TS, TS);
    NbTS += l->NbTS;
    dVecMerge(l->SH, SH);
    NbSH += l->NbSH;
    dVecMerge(l->VH, VH);
    NbVH += l->NbVH;
    dVecMerge(l->TH, TH);
    NbTH += l->NbTH;
    dVecMerge(l->SI, SI);
    NbSI += l->NbSI;
    dVecMerge(l->VI, VI);
    NbVI += l->NbVI;
    dVecMerge(l->TI, TI);
    NbTI += l->NbTI;
    dVecMerge(l->SY, SY);
    NbSY += l->NbSY;
    dVecMerge(l->VY, VY);
    NbVY += l->NbVY;
    dVecMerge(l->TY, TY);
    NbTY += l->NbTY;
    dVecMerge(l->VR, VR);
    NbVR += l->NbVR;
    dVecMerge(l->TR, TR);
    NbTR += l->NbTR;

    // merge strings
    for(std::size_t i = 0; i < l->T2D.size(); i += 4) {
      T2D.push_back(l->T2D[i]);
      T2D.push_back(l->T2D[i + 1]);
      T2D.push_back(l->T2D[i + 2]);
      T2D.push_back(T2C.size());
      double beg = l->T2D[i + 3];
      double end;
      if(i > l->T2D.size() - 8)
        end = l->T2C.size();
      else
        end = l->T2D[i + 3 + 4];
      char *c = &l->T2C[(int)beg];
      for(int j = 0; j < (int)(end - beg); j++) T2C.push_back(c[j]);
      NbT2++;
    }
    for(std::size_t i = 0; i < l->T3D.size(); i += 5) {
      T3D.push_back(l->T3D[i]);
      T3D.push_back(l->T3D[i + 1]);
      T3D.push_back(l->T3D[i + 2]);
      T3D.push_back(l->T3D[i + 3]);
      T3D.push_back(T3C.size());
      double beg = l->T3D[i + 4];
      double end;
      if(i > l->T3D.size() - 10)
        end = l->T3C.size();
      else
        end = l->T3D[i + 4 + 5];
      char *c = &l->T3C[(int)beg];
      for(int j = 0; j < (int)(end - beg); j++) T3C.push_back(c[j]);
      NbT3++;
    }
  }

  std::string tmp;
  if(nd.name == "__all__")
    tmp = "all";
  else if(nd.name == "__vis__")
    tmp = "visible";
  else
    tmp = nd.name;
  char name[256];
  sprintf(name, "%s_Combine", tmp.c_str());
  setName(name);
  setFileName(std::string(name) + ".pos");

  return finalize();
}

bool PViewDataList::combineTime(nameData &nd)
{
  // sanity checks
  if(nd.data.size() < 2) return false;
  std::vector<PViewDataList *> data(nd.data.size());
  for(std::size_t i = 0; i < nd.data.size(); i++) {
    data[i] = dynamic_cast<PViewDataList *>(nd.data[i]);
    if(!data[i]) {
      Msg::Error("Cannot combine hybrid data");
      return false;
    }
  }

  int *nbe = nullptr, *nbe2 = nullptr, nbn, nbn2, nbc, nbc2;
  std::vector<double> *list = nullptr, *list2 = nullptr;

  // use the first data set as the reference
  for(int i = 0; i < 27; i++) {
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    data[0]->_getRawData(i, &list2, &nbe2, &nbc2, &nbn2);
    *nbe = *nbe2;
  }
  NbT2 = data[0]->NbT2;
  NbT3 = data[0]->NbT3;
  for(auto it = data[0]->_interpolation.begin();
      it != data[0]->_interpolation.end(); it++)
    if(_interpolation[it->first].empty())
      for(std::size_t i = 0; i < it->second.size(); i++)
        _interpolation[it->first].push_back(
          new fullMatrix<double>(*it->second[i]));

  // merge values for all element types
  for(int i = 0; i < 27; i++) {
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    for(int j = 0; j < *nbe; j++) {
      for(std::size_t k = 0; k < data.size(); k++) {
        data[k]->_getRawData(i, &list2, &nbe2, &nbc2, &nbn2);
        if(*nbe && *nbe == *nbe2) {
          int nb2 = list2->size() / *nbe2;
          if(!k) {
            // copy coordinates of elm j (we are always here as
            // expected, since the ref view is the first one)
            for(int l = 0; l < 3 * nbn2; l++)
              list->push_back((*list2)[j * nb2 + l]);
          }
          // copy values of elm j
          for(int l = 0; l < nb2 - 3 * nbn2; l++)
            list->push_back((*list2)[j * nb2 + 3 * nbn2 + l]);
        }
      }
    }
  }

  // merge 2d strings
  for(int j = 0; j < NbT2; j++) {
    for(std::size_t k = 0; k < data.size(); k++) {
      if(NbT2 == data[k]->NbT2) {
        if(!k) {
          // copy coordinates
          T2D.push_back(data[k]->T2D[j * 4]);
          T2D.push_back(data[k]->T2D[j * 4 + 1]);
          T2D.push_back(data[k]->T2D[j * 4 + 2]);
          // index
          T2D.push_back(T2C.size());
        }
        // copy char values
        double beg = data[k]->T2D[j * 4 + 3];
        double end;
        if(j == NbT2 - 1)
          end = data[k]->T2C.size();
        else
          end = data[k]->T2D[j * 4 + 4 + 3];
        char *c = &data[k]->T2C[(int)beg];
        for(int l = 0; l < (int)(end - beg); l++) T2C.push_back(c[l]);
      }
    }
  }

  // merge 3d strings
  for(int j = 0; j < NbT3; j++) {
    for(std::size_t k = 0; k < data.size(); k++) {
      if(NbT3 == data[k]->NbT3) {
        if(!k) {
          // copy coordinates
          T3D.push_back(data[k]->T3D[j * 5]);
          T3D.push_back(data[k]->T3D[j * 5 + 1]);
          T3D.push_back(data[k]->T3D[j * 5 + 2]);
          T3D.push_back(data[k]->T3D[j * 5 + 3]);
          // index
          T3D.push_back(T3C.size());
        }
        // copy char values
        double beg = data[k]->T3D[j * 5 + 4];
        double end;
        if(j == NbT3 - 1)
          end = data[k]->T3C.size();
        else
          end = data[k]->T3D[j * 5 + 5 + 4];
        char *c = &data[k]->T3C[(int)beg];
        for(int l = 0; l < (int)(end - beg); l++) T3C.push_back(c[l]);
      }
    }
  }

  // create the time data
  for(std::size_t i = 0; i < data.size(); i++) dVecMerge(data[i]->Time, Time);

  // if all the time values are the same, it probably means that the
  // original views didn't have any time data: then we'll just use
  // time step values
  if(Time.size()) {
    double t0 = Time[0], ti;
    bool allTheSame = true;
    for(std::size_t i = 1; i < Time.size(); i++) {
      ti = Time[i];
      if(ti != t0) {
        allTheSame = false;
        break;
      }
    }
    if(allTheSame) Time.clear();
  }

  std::string tmp;
  if(nd.name == "__all__")
    tmp = "all";
  else if(nd.name == "__vis__")
    tmp = "visible";
  else
    tmp = nd.name;
  char name[256];
  sprintf(name, "%s_Combine", tmp.c_str());

  setName(name);
  setFileName(std::string(name) + ".pos");
  return finalize();
}

int PViewDataList::_getRawData(int idxtype, std::vector<double> **l, int **ne,
                               int *nc, int *nn)
{
  int type = 0;
  // No constant nn for polygons!
  if(idxtype > 26 && idxtype < 33)
    Msg::Warning("No constant number of nodes for polygons and polyhedra");
  switch(idxtype) {
  case 0:
    *l = &SP;
    *ne = &NbSP;
    *nc = 1;
    *nn = 1;
    type = TYPE_PNT;
    break;
  case 1:
    *l = &VP;
    *ne = &NbVP;
    *nc = 3;
    *nn = 1;
    type = TYPE_PNT;
    break;
  case 2:
    *l = &TP;
    *ne = &NbTP;
    *nc = 9;
    *nn = 1;
    type = TYPE_PNT;
    break;
  case 3:
    *l = &SL;
    *ne = &NbSL;
    *nc = 1;
    *nn = 2;
    type = TYPE_LIN;
    break;
  case 4:
    *l = &VL;
    *ne = &NbVL;
    *nc = 3;
    *nn = 2;
    type = TYPE_LIN;
    break;
  case 5:
    *l = &TL;
    *ne = &NbTL;
    *nc = 9;
    *nn = 2;
    type = TYPE_LIN;
    break;
  case 6:
    *l = &ST;
    *ne = &NbST;
    *nc = 1;
    *nn = 3;
    type = TYPE_TRI;
    break;
  case 7:
    *l = &VT;
    *ne = &NbVT;
    *nc = 3;
    *nn = 3;
    type = TYPE_TRI;
    break;
  case 8:
    *l = &TT;
    *ne = &NbTT;
    *nc = 9;
    *nn = 3;
    type = TYPE_TRI;
    break;
  case 9:
    *l = &SQ;
    *ne = &NbSQ;
    *nc = 1;
    *nn = 4;
    type = TYPE_QUA;
    break;
  case 10:
    *l = &VQ;
    *ne = &NbVQ;
    *nc = 3;
    *nn = 4;
    type = TYPE_QUA;
    break;
  case 11:
    *l = &TQ;
    *ne = &NbTQ;
    *nc = 9;
    *nn = 4;
    type = TYPE_QUA;
    break;
  case 12:
    *l = &SS;
    *ne = &NbSS;
    *nc = 1;
    *nn = 4;
    type = TYPE_TET;
    break;
  case 13:
    *l = &VS;
    *ne = &NbVS;
    *nc = 3;
    *nn = 4;
    type = TYPE_TET;
    break;
  case 14:
    *l = &TS;
    *ne = &NbTS;
    *nc = 9;
    *nn = 4;
    type = TYPE_TET;
    break;
  case 15:
    *l = &SH;
    *ne = &NbSH;
    *nc = 1;
    *nn = 8;
    type = TYPE_HEX;
    break;
  case 16:
    *l = &VH;
    *ne = &NbVH;
    *nc = 3;
    *nn = 8;
    type = TYPE_HEX;
    break;
  case 17:
    *l = &TH;
    *ne = &NbTH;
    *nc = 9;
    *nn = 8;
    type = TYPE_HEX;
    break;
  case 18:
    *l = &SI;
    *ne = &NbSI;
    *nc = 1;
    *nn = 6;
    type = TYPE_PRI;
    break;
  case 19:
    *l = &VI;
    *ne = &NbVI;
    *nc = 3;
    *nn = 6;
    type = TYPE_PRI;
    break;
  case 20:
    *l = &TI;
    *ne = &NbTI;
    *nc = 9;
    *nn = 6;
    type = TYPE_PRI;
    break;
  case 21:
    *l = &SY;
    *ne = &NbSY;
    *nc = 1;
    *nn = 5;
    type = TYPE_PYR;
    break;
  case 22:
    *l = &VY;
    *ne = &NbVY;
    *nc = 3;
    *nn = 5;
    type = TYPE_PYR;
    break;
  case 23:
    *l = &TY;
    *ne = &NbTY;
    *nc = 9;
    *nn = 5;
    type = TYPE_PYR;
    break;
  case 24:
    *l = &SR;
    *ne = &NbSR;
    *nc = 1;
    *nn = 4;
    type = TYPE_TRIH;
    break;
  case 25:
    *l = &VR;
    *ne = &NbVR;
    *nc = 3;
    *nn = 4;
    type = TYPE_TRIH;
    break;
  case 26:
    *l = &TR;
    *ne = &NbTR;
    *nc = 9;
    *nn = 4;
    type = TYPE_TRIH;
    break;
  case 27:
    *l = &SG;
    *ne = &NbSG;
    *nc = 1;
    *nn = 3;
    type = TYPE_POLYG;
    break;
  case 28:
    *l = &VG;
    *ne = &NbVG;
    *nc = 3;
    *nn = 3;
    type = TYPE_POLYG;
    break;
  case 29:
    *l = &TG;
    *ne = &NbTG;
    *nc = 9;
    *nn = 3;
    type = TYPE_POLYG;
    break;
  case 30:
    *l = &SD;
    *ne = &NbSD;
    *nc = 1;
    *nn = 4;
    type = TYPE_POLYH;
    break;
  case 31:
    *l = &VD;
    *ne = &NbVD;
    *nc = 3;
    *nn = 4;
    type = TYPE_POLYH;
    break;
  case 32:
    *l = &TD;
    *ne = &NbTD;
    *nc = 9;
    *nn = 4;
    type = TYPE_POLYH;
    break;
  default: Msg::Error("Wrong type in PViewDataList"); break;
  }

  if(haveInterpolationMatrices()) {
    std::vector<fullMatrix<double> *> im;
    int nim = getInterpolationMatrices(type, im);
    if(nim == 4) *nn = im[2]->size1();
  }
  return type;
}

void PViewDataList::setOrder2(int type)
{
  int typeMSH = 0;
  switch(type) {
  case TYPE_LIN: typeMSH = MSH_LIN_3; break;
  case TYPE_TRI: typeMSH = MSH_TRI_6; break;
  case TYPE_QUA: typeMSH = MSH_QUA_9; break;
  case TYPE_TET: typeMSH = MSH_TET_10; break;
  case TYPE_HEX: typeMSH = MSH_HEX_27; break;
  case TYPE_PRI: typeMSH = MSH_PRI_18; break;
  case TYPE_PYR: typeMSH = MSH_PYR_14; break;
  }
  const polynomialBasis *fs =
    (polynomialBasis *)BasisFactory::getNodalBasis(typeMSH);
  if(!fs) {
    Msg::Error("Could not find polynomial function space for element type %d",
               typeMSH);
    return;
  }
  setInterpolationMatrices(type, fs->coefficients, fs->monomials,
                           fs->coefficients, fs->monomials);
}

std::vector<double> *PViewDataList::incrementList(int numComp, int type,
                                                  int numNodes)
{
  int nb;
  switch(type) {
  case TYPE_PNT:
    if(numComp == 1) {
      NbSP++;
      return &SP;
    }
    else if(numComp == 3) {
      NbVP++;
      return &VP;
    }
    else if(numComp == 9) {
      NbTP++;
      return &TP;
    }
    break;
  case TYPE_LIN:
    if(numComp == 1) {
      NbSL++;
      return &SL;
    }
    else if(numComp == 3) {
      NbVL++;
      return &VL;
    }
    else if(numComp == 9) {
      NbTL++;
      return &TL;
    }
    break;
  case TYPE_TRI:
    if(numComp == 1) {
      NbST++;
      return &ST;
    }
    else if(numComp == 3) {
      NbVT++;
      return &VT;
    }
    else if(numComp == 9) {
      NbTT++;
      return &TT;
    }
    break;
  case TYPE_QUA:
    if(numComp == 1) {
      NbSQ++;
      return &SQ;
    }
    else if(numComp == 3) {
      NbVQ++;
      return &VQ;
    }
    else if(numComp == 9) {
      NbTQ++;
      return &TQ;
    }
    break;
  case TYPE_TET:
    if(numComp == 1) {
      NbSS++;
      return &SS;
    }
    else if(numComp == 3) {
      NbVS++;
      return &VS;
    }
    else if(numComp == 9) {
      NbTS++;
      return &TS;
    }
    break;
  case TYPE_HEX:
    if(numComp == 1) {
      NbSH++;
      return &SH;
    }
    else if(numComp == 3) {
      NbVH++;
      return &VH;
    }
    else if(numComp == 9) {
      NbTH++;
      return &TH;
    }
    break;
  case TYPE_PRI:
    if(numComp == 1) {
      NbSI++;
      return &SI;
    }
    else if(numComp == 3) {
      NbVI++;
      return &VI;
    }
    else if(numComp == 9) {
      NbTI++;
      return &TI;
    }
    break;
  case TYPE_PYR:
    if(numComp == 1) {
      NbSY++;
      return &SY;
    }
    else if(numComp == 3) {
      NbVY++;
      return &VY;
    }
    else if(numComp == 9) {
      NbTY++;
      return &TY;
    }
    break;
  case TYPE_TRIH:
    if(numComp == 1) {
      NbSR++;
      return &SR;
    }
    else if(numComp == 3) {
      NbVR++;
      return &VR;
    }
    else if(numComp == 9) {
      NbTR++;
      return &TR;
    }
    break;
  case TYPE_POLYG:
    polyNumNodes[0].push_back(numNodes);
    nb = (polyAgNumNodes[0].size()) ? polyAgNumNodes[0].back() : 0;
    polyAgNumNodes[0].push_back(numNodes + nb);
    polyTotNumNodes[0] += numNodes;
    if(numComp == 1) {
      NbSG++;
      return &SG;
    }
    else if(numComp == 3) {
      NbVG++;
      return &VG;
    }
    else if(numComp == 9) {
      NbTG++;
      return &TG;
    }
    break;
  case TYPE_POLYH:
    polyNumNodes[1].push_back(numNodes);
    nb = (polyAgNumNodes[1].size()) ? polyAgNumNodes[1].back() : 0;
    polyAgNumNodes[1].push_back(numNodes + nb);
    polyTotNumNodes[1] += numNodes;
    if(numComp == 1) {
      NbSD++;
      return &SD;
    }
    else if(numComp == 3) {
      NbVD++;
      return &VD;
    }
    else if(numComp == 9) {
      NbTD++;
      return &TD;
    }
    break;
  }
  return nullptr;
}
