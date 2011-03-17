// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MakeSimplex.h"

StringXNumber MakeSimplexOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterMakeSimplexPlugin()
  {
    return new GMSH_MakeSimplexPlugin();
  }
}

std::string GMSH_MakeSimplexPlugin::getHelp() const
{
  return "Plugin(MakeSimplex) decomposes all non-simplectic "
    "elements (quadrangles, prisms, hexahedra, pyramids) in the "
    "view `View' into simplices (triangles, tetrahedra).\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(MakeSimplex) is executed in-place.";
}

int GMSH_MakeSimplexPlugin::getNbOptions() const
{
  return sizeof(MakeSimplexOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MakeSimplexPlugin::getOption(int iopt)
{
  return &MakeSimplexOptions_Number[iopt];
}

static void decomposeList(PViewDataList *data, int nbNod, int nbComp,
                          std::vector<double> &listIn, int *nbIn, 
                          std::vector<double> &listOut, int *nbOut)
{
  double xNew[4], yNew[4], zNew[4];
  double *valNew = new double[data->getNumTimeSteps() * nbComp * nbNod];
  MakeSimplex dec(nbNod, nbComp, data->getNumTimeSteps());

  if(!(*nbIn))
    return;

  int nb = listIn.size() / (*nbIn);
  for(unsigned int i = 0; i < listIn.size(); i += nb){
    double *x = &listIn[i];
    double *y = &listIn[i + nbNod];
    double *z = &listIn[i + 2 * nbNod];
    double *val = &listIn[i + 3 * nbNod]; 
    for(int j = 0; j < dec.numSimplices(); j++){
      dec.decompose(j, x, y, z, val, xNew, yNew, zNew, valNew);
      for(int k = 0; k < dec.numSimplexNodes(); k++)
        listOut.push_back(xNew[k]);
      for(int k = 0; k < dec.numSimplexNodes(); k++)
        listOut.push_back(yNew[k]);
      for(int k = 0; k < dec.numSimplexNodes(); k++)
        listOut.push_back(zNew[k]);
      for(int k = 0; k < dec.numSimplexNodes() * data->getNumTimeSteps() * nbComp; k++)
        listOut.push_back(valNew[k]);
      (*nbOut)++;
    }
  }

  delete [] valNew;

  listIn.clear();
  *nbIn = 0;
}

PView *GMSH_MakeSimplexPlugin::execute(PView *v)
{
  int iView = (int)MakeSimplexOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  // quads
  decomposeList(data1, 4, 1, data1->SQ, &data1->NbSQ, data1->ST, &data1->NbST);
  decomposeList(data1, 4, 3, data1->VQ, &data1->NbVQ, data1->VT, &data1->NbVT);
  decomposeList(data1, 4, 9, data1->TQ, &data1->NbTQ, data1->TT, &data1->NbTT);
                          
  // hexas                
  decomposeList(data1, 8, 1, data1->SH, &data1->NbSH, data1->SS, &data1->NbSS);
  decomposeList(data1, 8, 3, data1->VH, &data1->NbVH, data1->VS, &data1->NbVS);
  decomposeList(data1, 8, 9, data1->TH, &data1->NbTH, data1->TS, &data1->NbTS);
                          
  // prisms               
  decomposeList(data1, 6, 1, data1->SI, &data1->NbSI, data1->SS, &data1->NbSS);
  decomposeList(data1, 6, 3, data1->VI, &data1->NbVI, data1->VS, &data1->NbVS);
  decomposeList(data1, 6, 9, data1->TI, &data1->NbTI, data1->TS, &data1->NbTS);
                          
  // pyramids             
  decomposeList(data1, 5, 1, data1->SY, &data1->NbSY, data1->SS, &data1->NbSS);
  decomposeList(data1, 5, 3, data1->VY, &data1->NbVY, data1->VS, &data1->NbVS);
  decomposeList(data1, 5, 9, data1->TY, &data1->NbTY, data1->TS, &data1->NbTS);

  data1->finalize();
  v1->setChanged(true);

  return v1;
}

// Utility class 

MakeSimplex::MakeSimplex(int numNodes, int numComponents, int numTimeSteps)
  : _numNodes(numNodes), _numComponents(numComponents), _numTimeSteps(numTimeSteps) 
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

void MakeSimplex::reorder(int map[4], int n,
                          double *x, double *y, double *z, double *val,
                          double *xn, double *yn, double *zn, double *valn)
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
        valn[ts*n*_numComponents + i*_numComponents + j] = 
          val[ts*_numNodes*_numComponents + map2[i]*_numComponents + j];
  }
}

void MakeSimplex::decompose(int num, 
                            double *x, double *y, double *z, double *val,
                            double *xn, double *yn, double *zn, double *valn)
{
  int quadTri[2][4] = {{0,1,2,-1}, {0,2,3,-1}};
  int hexaTet[6][4] = {{0,1,3,7}, {0,4,1,7}, {1,4,5,7}, {1,2,3,7}, {1,6,2,7}, {1,5,6,7}};
  int prisTet[3][4] = {{0,1,2,4}, {0,2,4,5}, {0,3,4,5}};
  int pyraTet[2][4] = {{0,1,3,4}, {1,2,3,4}};

  if(num < 0 || num > numSimplices()-1) {
    Msg::Error("Invalid decomposition");
    num = 0;
  }
    
  switch(_numNodes) {
  case 4: reorder(quadTri[num], 3, x, y, z, val, xn, yn, zn, valn); break ;
  case 8: reorder(hexaTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  case 6: reorder(prisTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  case 5: reorder(pyraTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  }
}
