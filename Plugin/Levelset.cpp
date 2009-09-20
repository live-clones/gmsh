// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Levelset.h"
#include "MakeSimplex.h"
#include "Numeric.h"
#include "Iso.h"
#include "adaptiveData.h"
#include "GmshDefines.h"

static const int exn[13][12][2] = {
  {{0,0}}, // point
  {{0,1}}, // line
  {{}}, // -
  {{0,1}, {0,2}, {1,2}}, // triangle
  {{0,1}, {0,3}, {1,2}, {2,3}}, // quad
  {{}}, // -
  {{0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3}}, // tetra
  {{}}, // -
  {{0,1}, {0,3}, {0,4}, {1,2}, {1,4}, {2,3}, {2,4}, {3,4}}, // pyramid
  {{0,1}, {0,2}, {0,3}, {1,2}, {1,4}, {2,5}, {3,4}, {3,5}, {4,5}}, // prism
  {{}}, {{}}, // -
  {{0,1}, {0,3}, {0,4}, {1,2}, {1,5}, {2,3}, 
   {2,6}, {3,7}, {4,5}, {4,7}, {5,6}, {6,7}} // hexa
};

static int numSimplexDec(int type)
{
  switch(type){
  case TYPE_QUA: return 2;
  case TYPE_HEX: return 6;
  case TYPE_PRI: return 3;
  case TYPE_PYR: return 2;
  default: return 1;
  }
}

static void getSimplexDec(int numNodes, int numEdges, int type, int i, 
                          int &n0, int &n1, int &n2, int &n3,
                          int &nn, int &ne)
{
  static const int qua[2][3] = {{0,1,2}, {0,2,3}};
  static const int hex[6][4] = {{0,1,3,7}, {0,4,1,7}, {1,4,5,7}, 
                                {1,2,3,7}, {1,6,2,7}, {1,5,6,7}};
  static const int pri[3][4] = {{0,1,2,4}, {0,2,4,5}, {0,3,4,5}};
  static const int pyr[2][4] = {{0,1,3,4}, {1,2,3,4}};
  switch(type){
  case TYPE_QUA:
    n0 = qua[i][0]; n1 = qua[i][1]; n2 = qua[i][2]; nn = 3; ne = 3; 
    break;
  case TYPE_HEX:
    n0 = hex[i][0]; n1 = hex[i][1]; n2 = hex[i][2]; n3 = hex[i][3]; nn = 4; ne = 6;
    break;
  case TYPE_PRI:
    n0 = pri[i][0]; n1 = pri[i][1]; n2 = pri[i][2]; n3 = pri[i][3]; nn = 4; ne = 6;
    break;
  case TYPE_PYR:
    n0 = pyr[i][0]; n1 = pyr[i][1]; n2 = pyr[i][2]; n3 = pyr[i][3]; nn = 4; ne = 6;
    break;
  default:
    n0 = 0; n1 = 1; n2 = 2; n3 = 3; nn = numNodes; ne = numEdges;
    break;
  }
}

static void affect(double *xpi, double *ypi, double *zpi,
                   double valpi[12][9], int epi[12], int i,
                   double *xp, double *yp, double *zp,
                   double valp[12][9], int ep[12], int j, int nb)
{
  xpi[i] = xp[j];
  ypi[i] = yp[j];
  zpi[i] = zp[j];
  for(int k = 0; k < nb; k++) valpi[i][k] = valp[j][k];
  epi[i] = ep[j];
}

static void removeIdenticalNodes(int *np, int numComp,
                                 double xp[12], double yp[12], double zp[12],
                                 double valp[12][9], int ep[12])
{
  double xpi[12], ypi[12], zpi[12], valpi[12][9];
  int epi[12];

  affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 0, numComp);
  int npi = 1;
  for(int j = 1; j < *np; j++) {
    for(int i = 0; i < npi; i++) {
      if(fabs(xp[j] - xpi[i]) < 1.e-12 &&
         fabs(yp[j] - ypi[i]) < 1.e-12 &&
         fabs(zp[j] - zpi[i]) < 1.e-12) {
        break;
      }
      if(i == npi-1) {
        affect(xpi, ypi, zpi, valpi, epi, npi, xp, yp, zp, valp, ep, j, numComp);
        npi++;
        break;
      }
    }
  }
  for(int i = 0; i < npi; i++)
    affect(xp, yp, zp, valp, ep, i, xpi, ypi, zpi, valpi, epi, i, numComp);
  *np = npi;
}

static void reorderQuad(int numComp, double xp[12], double yp[12], double zp[12], 
                        double valp[12][9], int ep[12])
{
  double xpi[1], ypi[1], zpi[1], valpi[1][9];
  int epi[12];
  affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 3, numComp);
  affect(xp, yp, zp, valp, ep, 3, xp, yp, zp, valp, ep, 2, numComp);
  affect(xp, yp, zp, valp, ep, 2, xpi, ypi, zpi, valpi, epi, 0, numComp);
}

static void reorderPrism(int numComp, double xp[12], double yp[12], double zp[12], 
                         double valp[12][9], int ep[12], int nbCut)
{
  double xpi[6], ypi[6], zpi[6], valpi[6][9];
  int epi[12];

  if(nbCut == 3){
    // 3 first nodes come from zero levelset intersection, next 3 are
    // endpoints of relative edges
    affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 3, numComp);
    affect(xpi, ypi, zpi, valpi, epi, 1, xp, yp, zp, valp, ep, 4, numComp);
    affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 5, numComp);
    for(int i = 0; i < 3; i++){
      int edgecut = ep[i]-1;
      for(int j = 0; j < 3; j++){
        int p = -epi[j]-1;
        if(exn[9][edgecut][0] == p || exn[9][edgecut][1] == p)
          affect(xp, yp, zp, valp, ep, 3+i, xpi, ypi, zpi, valpi, epi, j, numComp);       
      }
    }
  }
  else if(nbCut == 4){
    // 4 first nodes come from zero levelset intersection
    affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 0, numComp);
    int edgecut = ep[0]-1;
    int p0 = -ep[4]-1;

    if(exn[9][edgecut][0] == p0 || exn[9][edgecut][1] == p0){
      affect(xpi, ypi, zpi, valpi, epi, 1, xp, yp, zp, valp, ep, 4, numComp);
      if(exn[9][ep[1]-1][0] == p0 || exn[9][ep[1]-1][1] == p0){
        affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 1, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 3, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 5, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, numComp);
      }
      else{
        affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 3, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 1, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 5, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, numComp);
      }
    }
    else{
      affect(xpi, ypi, zpi, valpi, epi, 1, xp, yp, zp, valp, ep, 5, numComp);
      if(exn[9][ep[1]-1][0] == p0 || exn[9][ep[1]-1][1] == p0){
        affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 1, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 3, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 4, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, numComp);
      }
      else{
        affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 3, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 1, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 4, numComp);
        affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, numComp);
      }
    }
    for(int i = 0; i < 6; i++)
      affect(xp, yp, zp, valp, ep, i, xpi, ypi, zpi, valpi, epi, i, numComp);
  }
}
 
GMSH_LevelsetPlugin::GMSH_LevelsetPlugin()
{
  _invert = 0.;
  _ref[0] = _ref[1] = _ref[2] = 0.;
  _valueIndependent = 0; // "moving" levelset
  _valueView = -1; // use same view for levelset and field data
  _valueTimeStep = -1; // use same time step in levelset and field data views
  _recurLevel = 4;
  _targetError = 0.;
  _extractVolume = 0; // to create isovolumes (keep all elements < or > levelset)
  _orientation = GMSH_LevelsetPlugin::NONE;
}

void GMSH_LevelsetPlugin::_addElement(int step, int np, int numEdges, int numComp,
                                      double xp[12], double yp[12], double zp[12],
                                      double valp[12][9], PViewDataList *out)
{
  std::vector<double> *list;
  int *nbPtr;
  switch(np){
  case 1:
    if(numComp == 1)      { list = &out->SP; nbPtr = &out->NbSP; }
    else if(numComp == 3) { list = &out->VP; nbPtr = &out->NbVP; }
    else                  { list = &out->TP; nbPtr = &out->NbTP; }
    break;
  case 2:
    if(numComp == 1)      { list = &out->SL; nbPtr = &out->NbSL; }
    else if(numComp == 3) { list = &out->VL; nbPtr = &out->NbVL; }
    else                  { list = &out->TL; nbPtr = &out->NbTL; }
    break;
  case 3:
    if(numComp == 1)      { list = &out->ST; nbPtr = &out->NbST; }
    else if(numComp == 3) { list = &out->VT; nbPtr = &out->NbVT; }
    else                  { list = &out->TT; nbPtr = &out->NbTT; }
    break;
  case 4:
    if(!_extractVolume || numEdges <= 4){
      if(numComp == 1)      { list = &out->SQ; nbPtr = &out->NbSQ; }
      else if(numComp == 3) { list = &out->VQ; nbPtr = &out->NbVQ; }
      else                  { list = &out->TQ; nbPtr = &out->NbTQ; }
    }
    else{
      if(numComp == 1)      { list = &out->SS; nbPtr = &out->NbSS; }
      else if(numComp == 3) { list = &out->VS; nbPtr = &out->NbVS; }
      else                  { list = &out->TS; nbPtr = &out->NbTS; }
    }
    break;
  case 5:
    if(numComp == 1)      { list = &out->SY; nbPtr = &out->NbSY; }
    else if(numComp == 3) { list = &out->VY; nbPtr = &out->NbVY; }
    else                  { list = &out->TY; nbPtr = &out->NbTY; }
    break;
  case 6:
    if(numComp == 1)      { list = &out->SI; nbPtr = &out->NbSI; }
    else if(numComp == 3) { list = &out->VI; nbPtr = &out->NbVI; }
    else                  { list = &out->TI; nbPtr = &out->NbTI; }
    break;
  case 8:
    if(numComp == 1)      { list = &out->SH; nbPtr = &out->NbSH; }
    else if(numComp == 3) { list = &out->VH; nbPtr = &out->NbVH; }
    else                  { list = &out->TH; nbPtr = &out->NbTH; }
    break;
  default:
    return;
  }

  // copy the elements in the output data
  if(!step || !_valueIndependent) {
    for(int k = 0; k < np; k++) 
      list->push_back(xp[k]);
    for(int k = 0; k < np; k++)
      list->push_back(yp[k]);
    for(int k = 0; k < np; k++)
      list->push_back(zp[k]);
    (*nbPtr)++;
  }
  for(int k = 0; k < np; k++)
    for(int l = 0; l < numComp; l++)
      list->push_back(valp[k][l]);
}

void GMSH_LevelsetPlugin::_cutAndAddElements(PViewData *vdata, PViewData *wdata,
                                             int ent, int ele, int step, int wstep, 
                                             double x[8], double y[8], double z[8],
                                             double levels[8], double scalarValues[8],
                                             PViewDataList* out)
{
  int numNodes = vdata->getNumNodes(step, ent, ele);
  int numEdges = vdata->getNumEdges(step, ent, ele);
  int numComp = wdata->getNumComponents(wstep, ent, ele);
  int type = vdata->getType(step, ent, ele);

  for(int simplex = 0; simplex < numSimplexDec(type); simplex++){
    double xp[12], yp[12], zp[12], valp[12][9];
    int n[4], np = 0, ep[12], nsn, nse;
    getSimplexDec(numNodes, numEdges, type, simplex, n[0], n[1], n[2], n[3], nsn, nse);

    for(int i = 0; i < nse; i++){
      int n0 = exn[nse][i][0], n1 = exn[nse][i][1];
      if(levels[n[n0]] * levels[n[n1]] <= 0.) {
        double c = InterpolateIso(x, y, z, levels, 0., n[n0], n[n1], 
                                  &xp[np], &yp[np], &zp[np]);
        for(int comp = 0; comp < numComp; comp++){
          double v0, v1;
          wdata->getValue(wstep, ent, ele, n[n0], comp, v0);
          wdata->getValue(wstep, ent, ele, n[n1], comp, v1);
          valp[np][comp] = v0 + c * (v1 - v0);
        }
        ep[np++] = i + 1;
      }
    }

    // Remove identical nodes (this can happen if an edge actually
    // belongs to the zero levelset, i.e., if levels[] * levels[] == 0)
    if(np > 1) removeIdenticalNodes(&np, numComp, xp, yp, zp, valp, ep);

    // if there are no cuts and we extract the volume, save the full
    // element if it is on the correct side of the levelset
    if(np <= 1 && _extractVolume){
      bool add = true;
      for(int nod = 0; nod < nsn; nod++){
        if((_extractVolume < 0. && levels[n[nod]] > 0.) ||
           (_extractVolume > 0. && levels[n[nod]] < 0.)){
          add = false;
          break;
        }
      }
      if(add){
        double xp[12], yp[12], zp[12], valp[12][9];
        for(int nod = 0; nod < nsn; nod++){
          xp[nod] = x[n[nod]];
          yp[nod] = y[n[nod]];
          zp[nod] = z[n[nod]];
          for(int comp = 0; comp < numComp; comp++)
            wdata->getValue(wstep, ent, ele, nod, comp, valp[n[nod]][comp]);
        }
        _addElement(step, nsn, nse, numComp, xp, yp, zp, valp, out);
      }
      continue;
    }

    if(numEdges > 4 && np < 3) // 3D input should only lead to 2D output
      continue;
    else if(numEdges > 1 && np < 2) // 2D input should only lead to 1D output
      continue;
    else if(np < 1 || np > 4) // can't deal with this
      continue;

    // avoid "butterflies"
    if(np == 4) reorderQuad(numComp, xp, yp, zp, valp, ep);

    // orient the triangles and the quads to get the normals right
    if(!_extractVolume && (np == 3 || np == 4)) {
      if(!step || !_valueIndependent) {
        // test this only once for spatially-fixed views
        double v1[3] = {xp[2] - xp[0], yp[2] - yp[0], zp[2] - zp[0]};
        double v2[3] = {xp[1] - xp[0], yp[1] - yp[0], zp[1] - zp[0]};
        double gr[3], normal[3];
        prodve(v1, v2, normal);
        switch (_orientation) {
        case MAP:
          gradSimplex(x, y, z, scalarValues, gr);
          prosca(gr, normal, &_invert);
          break;
        case PLANE:
          prosca(normal, _ref, &_invert);
          break;
        case SPHERE:
          gr[0] = xp[0] - _ref[0];
          gr[1] = yp[0] - _ref[1];
          gr[2] = zp[0] - _ref[2];
          prosca(gr, normal, &_invert);
        case NONE:
        default:
          break;
        }
      }
      if(_invert > 0.) {
        double xpi[12], ypi[12], zpi[12], valpi[12][9];
        int epi[12];
        for(int k = 0; k < np; k++)
          affect(xpi, ypi, zpi, valpi, epi, k, xp, yp, zp, valp, ep, k, numComp);
        for(int k = 0; k < np; k++)
          affect(xp, yp, zp, valp, ep, k, xpi, ypi, zpi, valpi, epi, np - k - 1, numComp);
      }
    }

    // if we compute isovolumes, add the nodes on the chosen side
    // (FIXME: when cutting 2D views, the elts can have the wrong
    // orientation)
    if(_extractVolume){
      int nbCut = np;
      for(int nod = 0; nod < nsn; nod++){
        if((_extractVolume < 0. && levels[n[nod]] < 0.) ||
           (_extractVolume > 0. && levels[n[nod]] > 0.)){
          xp[np] = x[n[nod]];
          yp[np] = y[n[nod]];
          zp[np] = z[n[nod]];
          for(int comp = 0; comp < numComp; comp++)
            wdata->getValue(wstep, ent, ele, n[nod], comp, valp[np][comp]);
          ep[np] = -(nod + 1); // store node num!
          np++;
        }
      }
      removeIdenticalNodes(&np, numComp, xp, yp, zp, valp, ep);
      if(np == 4 && numEdges <= 4)
        reorderQuad(numComp, xp, yp, zp, valp, ep);
      if(np == 6)
        reorderPrism(numComp, xp, yp, zp, valp, ep, nbCut);
      if(np > 8) // can't deal with this
        continue;
    }

    _addElement(step, np, numEdges, numComp, xp, yp, zp, valp, out);
  }
}

PView *GMSH_LevelsetPlugin::execute(PView *v)
{
  if(v->getData()->isAdaptive()){
    v->getData()->getAdaptiveData()->changeResolution(0, _recurLevel, _targetError, this);
    v->setChanged(true);
  }

  // get adaptive data is available
  PViewData *vdata = v->getData(true), *wdata;
  if(_valueView < 0) {
    wdata = vdata;
  }
  else if(_valueView > (int)PView::list.size() - 1){
    Msg::Error("View[%d] does not exist: reverting to View[%d]", 
               _valueView, v->getIndex());
    wdata = vdata;
  }
  else{
    wdata = PView::list[_valueView]->getData();
  }

  // sanity checks
  if(vdata->getNumEntities() != wdata->getNumEntities() ||
     vdata->getNumElements() != wdata->getNumElements()){
    Msg::Error("Incompatible views");
    return v;
  }
  if(_valueTimeStep >= wdata->getNumTimeSteps()) {
    Msg::Error("Wrong time step %d in view", _valueTimeStep);
    return v;
  }

  // Force creation of one view per time step if we have multi meshes
  if(vdata->hasMultipleMeshes()) _valueIndependent = 0;

  double x[8], y[8], z[8], levels[8];
  double scalarValues[8] = {0., 0., 0., 0., 0., 0., 0., 0.};

  if(_valueIndependent) {
    // create a single output view containing the (possibly
    // multi-step) levelset
    PViewDataList *out = getDataList(new PView());
    for(int ent = 0; ent < vdata->getNumEntities(0); ent++){
      for(int ele = 0; ele < vdata->getNumElements(0, ent); ele++){
        if(vdata->skipElement(0, ent, ele)) continue;
        for(int nod = 0; nod < vdata->getNumNodes(0, ent, ele); nod++){
          vdata->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
          levels[nod] = levelset(x[nod], y[nod], z[nod], 0.);
        }
        for(int step = 0; step < vdata->getNumTimeSteps(); step++){
          int wstep = (_valueTimeStep < 0) ? step : _valueTimeStep;
          _cutAndAddElements(vdata, wdata, ent, ele, step, wstep, x, y, z,
                             levels, scalarValues, out);
        }
      }
    }
    out->setName(vdata->getName() + "_Levelset");
    out->setFileName(vdata->getFileName() + "_Levelset.pos");
    out->finalize();
  }
  else{
    // create one view per timestep
    for(int step = 0; step < vdata->getNumTimeSteps(); step++){
      PViewDataList *out = getDataList(new PView());
      for(int ent = 0; ent < vdata->getNumEntities(step); ent++){
        for(int ele = 0; ele < vdata->getNumElements(step, ent); ele++){
          if(vdata->skipElement(step, ent, ele)) continue;
          for(int nod = 0; nod < vdata->getNumNodes(step, ent, ele); nod++){
            vdata->getNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
            vdata->getScalarValue(step, ent, ele, nod, scalarValues[nod]);
            levels[nod] = levelset(x[nod], y[nod], z[nod], scalarValues[nod]);
          }
          int wstep = (_valueTimeStep < 0) ? step : _valueTimeStep;
          _cutAndAddElements(vdata, wdata, ent, ele, step, wstep, x, y, z,
                             levels, scalarValues, out);
        }
      }
      char tmp[246];
      sprintf(tmp, "_Levelset_%d", step);
      out->setName(vdata->getName() + tmp);
      out->setFileName(vdata->getFileName() + tmp + ".pos");
      out->finalize();
    }
  }
  
  return 0;
}

// On high order maps, we draw only the elements that have a cut with
// the levelset, this is as accurate as it should be

static bool recur_sign_change(adaptiveTriangle *t, 
                              const GMSH_LevelsetPlugin *plug)
{
  if(!t->e[0] || t->visible){
    double v1 = plug->levelset(t->p[0]->X, t->p[0]->Y, t->p[0]->Z, t->p[0]->val);
    double v2 = plug->levelset(t->p[1]->X, t->p[1]->Y, t->p[1]->Z, t->p[1]->val);
    double v3 = plug->levelset(t->p[2]->X, t->p[2]->Y, t->p[2]->Z, t->p[2]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0 && v2 * v3 > 0)
      t->visible = false;
    else
      t->visible = true;
    return t->visible;
  }
  else{
    bool sc1 = recur_sign_change(t->e[0], plug);
    bool sc2 = recur_sign_change(t->e[1], plug);
    bool sc3 = recur_sign_change(t->e[2], plug);
    bool sc4 = recur_sign_change(t->e[3], plug);
    if(sc1 || sc2 || sc3 || sc4){
      if(!sc1) t->e[0]->visible = true;
      if(!sc2) t->e[1]->visible = true;
      if(!sc3) t->e[2]->visible = true;
      if(!sc4) t->e[3]->visible = true;
      return true;
    }
    t->visible = false;
    return false;
  }      
}

static bool recur_sign_change(adaptiveQuadrangle *q, 
                              const GMSH_LevelsetPlugin *plug)
{
  if(!q->e[0] || q->visible){
    double v1 = plug->levelset(q->p[0]->X, q->p[0]->Y, q->p[0]->Z, q->p[0]->val);
    double v2 = plug->levelset(q->p[1]->X, q->p[1]->Y, q->p[1]->Z, q->p[1]->val);
    double v3 = plug->levelset(q->p[2]->X, q->p[2]->Y, q->p[2]->Z, q->p[2]->val);
    double v4 = plug->levelset(q->p[3]->X, q->p[3]->Y, q->p[3]->Z, q->p[3]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0 && v1 * v4 > 0)
      q->visible = false;
    else
      q->visible = true;
    return q->visible;
  }
  else{
    bool sc1 = recur_sign_change(q->e[0], plug);
    bool sc2 = recur_sign_change(q->e[1], plug);
    bool sc3 = recur_sign_change(q->e[2], plug);
    bool sc4 = recur_sign_change(q->e[3], plug);
    if(sc1 || sc2 || sc3 || sc4 ){
      if(!sc1) q->e[0]->visible = true;
      if(!sc2) q->e[1]->visible = true;
      if(!sc3) q->e[2]->visible = true;
      if(!sc4) q->e[3]->visible = true;
      return true;
    }
    q->visible = false;
    return false;
  }      
}

static bool recur_sign_change(adaptiveTetrahedron *t, 
                              const GMSH_LevelsetPlugin *plug)
{
  if(!t->e[0] || t->visible){
    double v1 = plug->levelset(t->p[0]->X, t->p[0]->Y, t->p[0]->Z, t->p[0]->val);
    double v2 = plug->levelset(t->p[1]->X, t->p[1]->Y, t->p[1]->Z, t->p[1]->val);
    double v3 = plug->levelset(t->p[2]->X, t->p[2]->Y, t->p[2]->Z, t->p[2]->val);
    double v4 = plug->levelset(t->p[3]->X, t->p[3]->Y, t->p[3]->Z, t->p[3]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0 && v1 * v4 > 0)
      t->visible = false;
    else
      t->visible = true;
    return t->visible;
  }
  else{
    bool sc1 = recur_sign_change(t->e[0], plug);
    bool sc2 = recur_sign_change(t->e[1], plug);
    bool sc3 = recur_sign_change(t->e[2], plug);
    bool sc4 = recur_sign_change(t->e[3], plug);
    bool sc5 = recur_sign_change(t->e[4], plug);
    bool sc6 = recur_sign_change(t->e[5], plug);
    bool sc7 = recur_sign_change(t->e[6], plug);
    bool sc8 = recur_sign_change(t->e[7], plug);
    if(sc1 || sc2 || sc3 || sc4 || sc5 || sc6 || sc7 || sc8){
      if(!sc1) t->e[0]->visible = true;
      if(!sc2) t->e[1]->visible = true;
      if(!sc3) t->e[2]->visible = true;
      if(!sc4) t->e[3]->visible = true;
      if(!sc5) t->e[4]->visible = true;
      if(!sc6) t->e[5]->visible = true;
      if(!sc7) t->e[6]->visible = true;
      if(!sc8) t->e[7]->visible = true;
      return true;
    }
    t->visible = false;
    return false;
  }      
}

static bool recur_sign_change(adaptiveHexahedron *t,
                              const GMSH_LevelsetPlugin *plug)
{
  if (!t->e[0] || t->visible){
    double v1 = plug->levelset(t->p[0]->X, t->p[0]->Y, t->p[0]->Z, t->p[0]->val);
    double v2 = plug->levelset(t->p[1]->X, t->p[1]->Y, t->p[1]->Z, t->p[1]->val);
    double v3 = plug->levelset(t->p[2]->X, t->p[2]->Y, t->p[2]->Z, t->p[2]->val);
    double v4 = plug->levelset(t->p[3]->X, t->p[3]->Y, t->p[3]->Z, t->p[3]->val);
    double v5 = plug->levelset(t->p[4]->X, t->p[4]->Y, t->p[4]->Z, t->p[4]->val);
    double v6 = plug->levelset(t->p[5]->X, t->p[5]->Y, t->p[5]->Z, t->p[5]->val);
    double v7 = plug->levelset(t->p[6]->X, t->p[6]->Y, t->p[6]->Z, t->p[6]->val);
    double v8 = plug->levelset(t->p[7]->X, t->p[7]->Y, t->p[7]->Z, t->p[7]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0 && v1 * v4 > 0 && v1 * v5 > 0 && 
       v1 * v6 > 0 && v1 * v7 > 0 && v1 * v8 > 0)
      t->visible = false;
    else
      t->visible = true;
    return t->visible;
  }
  else{
    bool sc1 = recur_sign_change(t->e[0], plug);
    bool sc2 = recur_sign_change(t->e[1], plug);
    bool sc3 = recur_sign_change(t->e[2], plug);
    bool sc4 = recur_sign_change(t->e[3], plug);
    bool sc5 = recur_sign_change(t->e[4], plug);
    bool sc6 = recur_sign_change(t->e[5], plug);
    bool sc7 = recur_sign_change(t->e[6], plug);
    bool sc8 = recur_sign_change(t->e[7], plug);
    if(sc1 || sc2 || sc3 || sc4 || sc5 || sc6 || sc7 || sc8){
      if (!sc1) t->e[0]->visible = true;
      if (!sc2) t->e[1]->visible = true;
      if (!sc3) t->e[2]->visible = true;
      if (!sc4) t->e[3]->visible = true;
      if (!sc5) t->e[4]->visible = true;
      if (!sc6) t->e[5]->visible = true;
      if (!sc7) t->e[6]->visible = true;
      if (!sc8) t->e[7]->visible = true;
      return true;
    }
    t->visible = false;
    return false;
  }      
}

void GMSH_LevelsetPlugin::assignSpecificVisibility() const
{
  if(adaptiveTriangle::all.size()){
    adaptiveTriangle *t = *adaptiveTriangle::all.begin();
    if(!t->visible) t->visible = !recur_sign_change(t, this);
  }
  if(adaptiveQuadrangle::all.size()){
    adaptiveQuadrangle *qe = *adaptiveQuadrangle::all.begin();
    if(!qe->visible) qe->visible = !recur_sign_change(qe, this);
  }
  if(adaptiveTetrahedron::all.size()){
    adaptiveTetrahedron *te = *adaptiveTetrahedron::all.begin();
    if(!te->visible) te->visible = !recur_sign_change(te, this);
  }
  if(adaptiveHexahedron::all.size()){
    adaptiveHexahedron *he = *adaptiveHexahedron::all.begin();
    if(!he->visible) he->visible = !recur_sign_change(he, this);
  }
}
