// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MakeSimplex.h"

GMSH_MakeSimplexPlugin::GMSH_MakeSimplexPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_MakeSimplexPlugin::getHelp() const
{
  return "Plugin(MakeSimplex) decomposes all non-simplectic "
         "elements (quadrangles, prisms, hexahedra, pyramids) in the "
         "view `View' into simplices (triangles, tetrahedra).\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(MakeSimplex) is executed in-place.";
}

// replace the elements of the list idx (see getListPointers()) by simplices
static void decomposeList(PViewDataList *data, int idx)
{
  int N[24];
  std::vector<double> *V[24];
  data->getListPointers(N, V);
  if(!N[idx]) return;
  const PViewDataList::listKind &kind = PViewDataList::listKinds[idx];
  int nbNod = kind.numNodes, nbComp = kind.numComp;
  int typeOut = (kind.dim == 2) ? TYPE_TRI : TYPE_TET;

  double xNew[4], yNew[4], zNew[4];
  double *valNew = new double[data->getNumTimeSteps() * nbComp * nbNod];
  MakeSimplex dec(nbNod, nbComp, data->getNumTimeSteps());

  std::vector<double> &listIn = *V[idx];
  int nb = listIn.size() / N[idx];
  for(std::size_t i = 0; i < listIn.size(); i += nb) {
    double *x = &listIn[i];
    double *y = &listIn[i + nbNod];
    double *z = &listIn[i + 2 * nbNod];
    double *val = &listIn[i + 3 * nbNod];
    for(int j = 0; j < dec.numSimplices(); j++) {
      dec.decompose(j, x, y, z, val, xNew, yNew, zNew, valNew);
      std::vector<double> &listOut = *data->incrementList(nbComp, typeOut);
      for(int k = 0; k < dec.numSimplexNodes(); k++) listOut.push_back(xNew[k]);
      for(int k = 0; k < dec.numSimplexNodes(); k++) listOut.push_back(yNew[k]);
      for(int k = 0; k < dec.numSimplexNodes(); k++) listOut.push_back(zNew[k]);
      for(int k = 0;
          k < dec.numSimplexNodes() * data->getNumTimeSteps() * nbComp; k++)
        listOut.push_back(valNew[k]);
    }
  }

  delete[] valNew;

  data->clearList(nbComp, kind.type);
}

PView *GMSH_MakeSimplexPlugin::execute(PView *v)
{
  int iView = (int)option(0);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  // quadrangles, hexahedra, prisms and pyramids
  for(int i = 0; i < 24; i++) {
    int type = PViewDataList::listKinds[i].type;
    if(type == TYPE_QUA || type == TYPE_HEX || type == TYPE_PRI ||
       type == TYPE_PYR)
      decomposeList(data1, i);
  }

  data1->finalize();
  v1->setChanged(true);

  return v1;
}

// Utility class

MakeSimplex::MakeSimplex(int numNodes, int numComponents, int numTimeSteps)
  : _numNodes(numNodes), _numComponents(numComponents),
    _numTimeSteps(numTimeSteps)
{
  ;
}

int MakeSimplex::numSimplices()
{
  switch(_numNodes) {
  case 4: return 2; // quad -> 2 tris
  case 5: return 2; // pyramid -> 2 tets
  case 6: return 3; // prism -> 3 tets
  case 8: return 6; // hexa -> 6 tets
  }
  return 0;
}

int MakeSimplex::numSimplexNodes()
{
  if(_numNodes == 4)
    return 3; // quad -> tris
  else
    return 4; // all others -> tets
}

void MakeSimplex::reorder(int map[4], int n, double *x, double *y, double *z,
                          double *val, double *xn, double *yn, double *zn,
                          double *valn)
{
  for(int i = 0; i < n; i++) {
    xn[i] = x[map[i]];
    yn[i] = y[map[i]];
    zn[i] = z[map[i]];
  }

  int map2[4] = {map[0], map[1], map[2], map[3]};
  for(int ts = 0; ts < _numTimeSteps; ts++)
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < _numComponents; j++)
        valn[ts * n * _numComponents + i * _numComponents + j] =
          val[ts * _numNodes * _numComponents + map2[i] * _numComponents + j];
    }
}

void MakeSimplex::decompose(int num, double *x, double *y, double *z,
                            double *val, double *xn, double *yn, double *zn,
                            double *valn)
{
  int quadTri[2][4] = {{0, 1, 2, -1}, {0, 2, 3, -1}};
  int hexaTet[6][4] = {{0, 1, 3, 7}, {0, 4, 1, 7}, {1, 4, 5, 7},
                       {1, 2, 3, 7}, {1, 6, 2, 7}, {1, 5, 6, 7}};
  int prisTet[3][4] = {{0, 1, 2, 4}, {0, 2, 4, 5}, {0, 3, 4, 5}};
  int pyraTet[2][4] = {{0, 1, 3, 4}, {1, 2, 3, 4}};

  if(num < 0 || num > numSimplices() - 1) {
    Msg::Error("Invalid decomposition");
    num = 0;
  }

  switch(_numNodes) {
  case 4: reorder(quadTri[num], 3, x, y, z, val, xn, yn, zn, valn); break;
  case 8: reorder(hexaTet[num], 4, x, y, z, val, xn, yn, zn, valn); break;
  case 6: reorder(prisTet[num], 4, x, y, z, val, xn, yn, zn, valn); break;
  case 5: reorder(pyraTet[num], 4, x, y, z, val, xn, yn, zn, valn); break;
  }
}
