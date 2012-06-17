// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "Gmsh.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "Distance.h"
#include "distanceTerm.h"
#include "Context.h"
#include "Numeric.h"
#include "dofManager.h"
#include "linearSystemGMM.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "orthogonalTerm.h"
#include "laplaceTerm.h"
#include "crossConfTerm.h"

template <class scalar> class simpleFunction;

StringXNumber DistanceOptions_Number[] = {
  {GMSH_FULLRC, "PhysPoint", NULL, 0.},
  {GMSH_FULLRC, "PhysLine", NULL, 0.},
  {GMSH_FULLRC, "PhysSurface", NULL, 0.},
  {GMSH_FULLRC, "Computation", NULL, -1},
  {GMSH_FULLRC, "MinScale", NULL, -1},
  {GMSH_FULLRC, "MaxScale", NULL, -1},
  {GMSH_FULLRC, "Orthogonal", NULL, -1}
};

StringXString DistanceOptions_String[] = {
  {GMSH_FULLRC, "Filename", NULL, "distance.pos"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDistancePlugin()
  {
    return new GMSH_DistancePlugin();
  }
}

GMSH_DistancePlugin::GMSH_DistancePlugin()
{
  _fileName = "text";
  _minScale = 0.0;
  _maxScale = 0.0;
  _maxDim = 0;
  _data = NULL;
}

std::string GMSH_DistancePlugin::getHelp() const
{
  return "Plugin(Distance) computes distances to physical entities in "
    "a mesh.\n\n"
    "Define the physical entities to which the distance is computed. "
    "If Point=0, Line=0, and Surface=0, then the distance is computed "
    "to all the boundaries of the mesh (edges in 2D and faces in 3D).\n\n"
    "Computation<0. computes the geometrical euclidian distance "
    "(warning: different than the geodesic distance), and  Computation=a>0.0 "
    "solves a PDE on the mesh with the diffusion constant mu = a*bbox, with "
    "bbox being the max size of the bounding box of the mesh (see paper "
    "Legrand 2006).\n\n"
    "Min Scale and max Scale, scale the distance function. If min Scale<0 "
    "and max Scale<0, then no scaling is applied to the distance function.\n\n"
    "Plugin(Distance) creates a new distance view and also saves the view "
    "in the fileName.pos file.";
}

int GMSH_DistancePlugin::getNbOptions() const
{
  return sizeof(DistanceOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DistancePlugin::getOption(int iopt)
{
  return &DistanceOptions_Number[iopt];
}

int GMSH_DistancePlugin::getNbOptionsStr() const
{
  return sizeof(DistanceOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_DistancePlugin::getOptionStr(int iopt)
{
  return &DistanceOptions_String[iopt];
}

void GMSH_DistancePlugin::printView(std::vector<GEntity*> _entities,
                                    std::map<MVertex*, double > _distance_map)
{
  _fileName = DistanceOptions_String[0].def;
  _minScale = (double) DistanceOptions_Number[4].def;
  _maxScale = (double) DistanceOptions_Number[5].def;

  double minDist=1.e4;
  double maxDist=0.0;
  for (std::map<MVertex*,double >::iterator itv=_distance_map.begin();
       itv != _distance_map.end(); ++itv){
    double dist = itv->second;
    if (dist>maxDist) maxDist = dist;
    if (dist<minDist) minDist = dist;
    itv->second = dist;
  }

  Msg::Info("Writing %s", _fileName.c_str());
  FILE *fName = fopen(_fileName.c_str(),"w");
  fprintf(fName, "View \"distance \"{\n");

  for (unsigned int ii=0; ii<_entities.size(); ii++) {
    if (_entities[ii]->dim() == _maxDim) {
      for (unsigned int i=0; i<_entities[ii]->getNumMeshElements(); i++) {
        MElement *e = _entities[ii]->getMeshElement(i);
        int numNodes = e->getNumVertices();
        if (e->getNumChildren())
          numNodes = e->getNumChildren() * e->getChild(0)->getNumVertices();
        std::vector<double> x(numNodes), y(numNodes), z(numNodes);
        std::vector<double> *out = _data->incrementList(1, e->getType(), numNodes);
        std::vector<MVertex*> nods;

        if (!e->getNumChildren())
          for(int i = 0; i < numNodes; i++)
            nods.push_back(e->getVertex(i));
        else
          for(int i = 0; i < e->getNumChildren(); i++)
            for(int j = 0; j < e->getChild(i)->getNumVertices(); j++)
              nods.push_back(e->getChild(i)->getVertex(j));

        for (int nod = 0; nod < numNodes; nod++) out->push_back((nods[nod])->x());
        for (int nod = 0; nod < numNodes; nod++) out->push_back((nods[nod])->y());
        for (int nod = 0; nod < numNodes; nod++) out->push_back((nods[nod])->z());

        if (_maxDim == 2)
          switch (numNodes) {
            case 2: fprintf(fName,"SL("); break;
            case 3: fprintf(fName,"ST("); break;
            case 4: fprintf(fName,"SQ("); break;
            default: Msg::Error("Error in Plugin 'Distance' (numNodes=%d)",
                                numNodes); break;
          }
        else if (_maxDim == 3)
          switch (numNodes) {
            case 4: fprintf(fName,"SS("); break;
            case 8: fprintf(fName,"SH("); break;
            case 6: fprintf(fName,"SI("); break;
            case 5: fprintf(fName,"SY("); break;
            default: Msg::Error("Error in Plugin 'Distance' (numNodes=%d)",
                                numNodes); break;
          }

        std::vector<double> dist;
        for (int j=0; j<numNodes; j++) {
          MVertex *v =  nods[j];
          if (j)
            fprintf(fName, ",%.16g,%.16g,%.16g", v->x(), v->y(), v->z());
          else
            fprintf(fName, "%.16g,%.16g,%.16g", v->x(), v->y(), v->z());
          std::map<MVertex*, double>::iterator it = _distance_map.find(v);
          dist.push_back(it->second);
        }

        fprintf(fName,"){");
        for (unsigned int i=0; i<dist.size(); i++) {
          if (_minScale>0 && _maxScale>0)
            dist[i] = _minScale + ((dist[i] - minDist) / (maxDist - minDist)) *
              (_maxScale - _minScale);
          else if (_minScale>0 && _maxScale<0)
            dist[i] = _minScale + dist[i];
          out->push_back(dist[i]);
          if (i)
            fprintf(fName, ",%.16g", dist[i]);
          else
            fprintf(fName, "%.16g", dist[i]);
        }
        fprintf(fName,"};\n");

      }
    }
  }
  fprintf(fName,"};\n");

  fclose(fName);
}

PView *GMSH_DistancePlugin::execute(PView *v)
{
  int id_pt   = (int) DistanceOptions_Number[0].def;
  int id_line = (int) DistanceOptions_Number[1].def;
  int id_face = (int) DistanceOptions_Number[2].def;
  double type = (double) DistanceOptions_Number[3].def;
  int ortho   = (int) DistanceOptions_Number[6].def;

  PView *view = new PView();
  _data = getDataList(view);
#if defined(HAVE_SOLVER)
#if defined(HAVE_TAUCS)
  linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#else
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
  lsys->setNoisy(1);
  lsys->setGmres(1);
  lsys->setPrec(5.e-8);
#endif
  dofManager<double> * dofView = new dofManager<double>(lsys);
#endif

  std::vector<GEntity*> _entities;
  GModel::current()->getEntities(_entities);
  if (!_entities.size() || !_entities[_entities.size()-1]->getMeshElement(0)) {
    Msg::Error("This plugin needs a mesh !");
    return view;
  }

  GEntity* ge = _entities[_entities.size()-1];
  int integrationPointTetra[2] = {0,0};

  int numnodes = 0;
  for (unsigned int i = 0; i < _entities.size()-1; i++)
    numnodes += _entities[i]->mesh_vertices.size();
  int totNodes = numnodes + _entities[_entities.size()-1]->mesh_vertices.size();
  int order = ge->getMeshElement(0)->getPolynomialOrder();
  int totNumNodes = totNodes + ge->getNumMeshElements()*integrationPointTetra[order-1];

  std::vector<SPoint3> pts;
  std::vector<double> distances;
  std::vector<MVertex* > pt2Vertex;
  pts.clear();
  distances.clear();
  pt2Vertex.clear();
  pts.reserve(totNumNodes);
  distances.reserve(totNumNodes);
  pt2Vertex.reserve(totNumNodes);

  std::map<MVertex*,double> _distanceE_map;
  std::map<MVertex*,int> _isInYarn_map;
  std::vector<int> index;
  std::vector<double> distancesE;
  std::vector<double> distances2;
  std::vector<double> distancesE2;
  std::vector<int> isInYarn;
  std::vector<int> isInYarn2;
  std::vector<SPoint3> closePts;
  std::vector<SPoint3> closePts2;

  for (int i=0; i<totNumNodes; i++) {
    distances.push_back(1.e22);
  }

  int k = 0;
  for (unsigned int i=0; i<_entities.size(); i++){
    GEntity* ge = _entities[i];
    _maxDim = std::max(_maxDim, ge->dim());
    for (unsigned int j=0; j<ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      pts.push_back(SPoint3(v->x(), v->y(), v->z()));
      _distance_map.insert(std::make_pair(v, 0.0));
/* TO DO (by AM)
      SPoint3 p_empty();
      _closePts_map.insert(std::make_pair(v, p_empty));
*/
      pt2Vertex[k] = v;
      k++;
    }
  }

  // Compute geometrical distance to mesh boundaries
  //------------------------------------------------------
  if (type < 0.0 ) {

    bool existEntity = false;

    for (unsigned int i=0; i<_entities.size(); i++) {
      GEntity* g2 = _entities[i];
      int gDim = g2->dim();
      std::vector<int> phys = g2->getPhysicalEntities();
      bool computeForEntity = false;
      for(unsigned int k = 0; k<phys.size(); k++) {
        int tagp = phys[k];
        if (id_pt == 0 && id_line == 0 && id_face == 0 && gDim == _maxDim - 1)
          computeForEntity = true;
        else if ((tagp == id_pt && gDim == 0) || (tagp == id_line && gDim == 1) ||
                 (tagp == id_face && gDim == 2))
          computeForEntity = true;
      }
      if (computeForEntity) {
        existEntity = true;
        for (unsigned int k = 0; k < g2->getNumMeshElements(); k++) {
          std::vector<double> iDistances;
          std::vector<SPoint3> iClosePts;
          std::vector<double> iDistancesE;
          std::vector<int> iIsInYarn;
          MElement *e = g2->getMeshElement(k);
          MVertex *v1 = e->getVertex(0);
          MVertex *v2 = e->getVertex(1);
          SPoint3 p1(v1->x(), v1->y(), v1->z());
          SPoint3 p2(v2->x(), v2->y(), v2->z());
          if ((e->getNumVertices() == 2 && order == 1) ||
              (e->getNumVertices() == 3 && order == 2)) {
            signedDistancesPointsLine(iDistances, iClosePts, pts, p1, p2);
          }
          else if ((e->getNumVertices() == 3 && order == 1) ||
                   (e->getNumVertices() == 6 && order == 2)) {
            MVertex *v3 = e->getVertex(2);
            SPoint3 p3 (v3->x(),v3->y(),v3->z());
            signedDistancesPointsTriangle(iDistances, iClosePts, pts, p1, p2, p3);
          }
          for (unsigned int kk=0; kk<pts.size(); kk++) {
            if (std::abs(iDistances[kk]) < distances[kk]) {
              distances[kk] = std::abs(iDistances[kk]);
              MVertex *v = pt2Vertex[kk];
              _distance_map[v] = distances[kk];
              /* TO DO (by AM)
              _closePts_map[v] = iClosePts[kk];
              */
            }
          }
        }
      }
    }
    if (!existEntity){
      if (id_pt != 0)   Msg::Error("The Physical Point does not exist !");
      if (id_line != 0) Msg::Error("The Physical Line does not exist !");
      if (id_face != 0) Msg::Error("The Physical Surface does not exist !");
      return view;
    }

    printView(_entities, _distance_map);

    /* TO DO (by AM)
    printView(_entities, _closePts_map);
    */
  }

  // Compute PDE for distance function
  //-----------------------------------
  else if (type > 0.0) {

#if defined(HAVE_SOLVER)

    bool existEntity = false;
    SBoundingBox3d bbox;
    for(unsigned int i = 0; i < _entities.size(); i++){
      GEntity* ge = _entities[i];
      int gDim = ge->dim();
      bool fixForEntity = false;
      std::vector<int> phys = ge->getPhysicalEntities();
      for(unsigned int k = 0; k < phys.size(); k++) {
        int tagp = phys[k];
        if (id_pt == 0 && id_line == 0 && id_face == 0 && gDim == _maxDim - 1)
          fixForEntity = true;
        else if ((tagp == id_pt && gDim == 0) || (tagp == id_line && gDim == 1) ||
                 (tagp == id_face && gDim == 2) )
          fixForEntity = true;
      }
      if (fixForEntity) {
        existEntity = true;
        for (unsigned int i = 0; i < ge->getNumMeshElements(); ++i) {
          MElement *t = ge->getMeshElement(i);
          for (int k=0; k<t->getNumVertices(); k++) {
            MVertex *v = t->getVertex(k);
            dofView->fixVertex(v, 0, 1, 0.);
            bbox += SPoint3(v->x(), v->y(), v->z());
          }
        }
      }
    }

    if (!existEntity){
      if (id_pt != 0)   Msg::Error("The Physical Point does not exist !");
      if (id_line != 0) Msg::Error("The Physical Line does not exist !");
      if (id_face != 0) Msg::Error("The Physical Surface does not exist !");
      return view;
    }

    std::vector<MElement *> allElems;
    for(unsigned int ii = 0; ii < _entities.size(); ii++){
      if(_entities[ii]->dim() == _maxDim) {
        GEntity *ge = _entities[ii];
        for(unsigned int i = 0; i < ge->getNumMeshElements(); ++i) {
          MElement *t = ge->getMeshElement(i);
          allElems.push_back(t);
          for (int k = 0; k < t->getNumVertices(); k++)
            dofView->numberVertex(t->getVertex(k), 0, 1);
        }
      }
    }

    double L = norm(SVector3(bbox.max(), bbox.min()));
    double mu = type*L;

    simpleFunction<double> DIFF(mu*mu), ONE(1.0);
    distanceTerm distance(GModel::current(), 1, &DIFF, &ONE);

    for (std::vector<MElement* >::iterator it = allElems.begin();
         it != allElems.end(); it++){
      SElement se((*it));
      distance.addToMatrix(*dofView, &se);
    }
    groupOfElements gr(allElems);
    distance.addToRightHandSide(*dofView, gr);

    Msg::Info("Distance Computation: Assembly done");
    lsys->systemSolve();
    Msg::Info("Distance Computation: System solved");

    for (std::map<MVertex*,double >::iterator itv = _distance_map.begin();
         itv != _distance_map.end() ; ++itv) {
      MVertex *v = itv->first;
      double value;
      dofView->getDofValue(v, 0, 1, value);
      value = std::min(0.9999, value);
      double dist = -mu * log(1. - value);
      itv->second = dist;
    }

    printView(_entities, _distance_map);

#endif
  }

  _data->setName("distance");
  _data->Time.push_back(0);
  _data->setFileName(_fileName.c_str());
  _data->finalize();

  // compute also orthogonal vector to distance field
  // A Uortho = -C DIST
  //------------------------------------------------
  if (ortho > 0) {
#if defined(HAVE_SOLVER)

#ifdef HAVE_TAUCS
    linearSystemCSRTaucs<double> *lsys2 = new linearSystemCSRTaucs<double>;
#else
    linearSystemCSRGmm<double> *lsys2 = new linearSystemCSRGmm<double>;
    lsys->setNoisy(1);
    lsys->setGmres(1);
    lsys->setPrec(5.e-8);
#endif
    dofManager<double> myAssembler(lsys2);
    simpleFunction<double> ONE(1.0);

    double dMax = 1.0; //EMI TO CHANGE

    std::vector<MElement *> allElems;
    for(unsigned int ii = 0; ii < _entities.size(); ii++){
      if (_entities[ii]->dim() == _maxDim) {
        GEntity *ge = _entities[ii];
        for (unsigned int i=0; i<ge->getNumMeshElements(); ++i) {
          MElement *t = ge->getMeshElement(i);
          double vMean = 0.0;
          for (int k = 0; k < t->getNumVertices(); k++) {
            std::map<MVertex*, double>::iterator it = _distance_map.find(t->getVertex(k));
            vMean += it->second;
          }
          vMean /= t->getNumVertices();
          if (vMean < dMax)
            allElems.push_back(ge->getMeshElement(i));
        }
      }
    }

    int mid = (int)floor(allElems.size() / 2.);
    MElement *e = allElems[mid];
    MVertex *vFIX = e->getVertex(0);
    myAssembler.fixVertex(vFIX, 0, 1, 0.0);

    for (std::vector<MElement* >::iterator it = allElems.begin();
         it != allElems.end(); it++){
      MElement *t = *it;
      for(int k = 0; k < t->getNumVertices(); k++)
        myAssembler.numberVertex(t->getVertex(k), 0, 1);
    }

    orthogonalTerm *ortho;
    ortho  = new orthogonalTerm(GModel::current(), 1, &ONE, &_distance_map);
    // if (type  < 0)
    //   ortho  = new orthogonalTerm(GModel::current(), 1, &ONE, view);
    // else
    //   ortho  = new orthogonalTerm(GModel::current(), 1, &ONE, dofView);

    for (std::vector<MElement* >::iterator it = allElems.begin();
         it != allElems.end(); it++){
      SElement se((*it));
      ortho->addToMatrix(myAssembler, &se);
    }
    groupOfElements gr(allElems);
    ortho->addToRightHandSide(myAssembler, gr);

    Msg::Info("Orthogonal Computation: Assembly done");
    lsys2->systemSolve();
    Msg::Info("Orthogonal Computation: System solved");

    PView *view2 = new PView();
    PViewDataList *data2 = getDataList(view2);
    data2->setName("ortogonal field");

    Msg::Info("Writing  orthogonal.pos");
    FILE * f5 = fopen("orthogonal.pos","w");
    fprintf(f5,"View \"orthogonal\"{\n");
    for (std::vector<MElement* >::iterator it = allElems.begin();
         it != allElems.end(); it++){
      MElement *e = *it;

    int numNodes = e->getNumVertices();
    if (e->getType() == TYPE_POLYG)
      numNodes = e->getNumChildren() * e->getChild(0)->getNumVertices();
    std::vector<double> x(numNodes), y(numNodes), z(numNodes);
    std::vector<double> *out2 = data2->incrementList(1, e->getType(), numNodes);
    std::vector<MVertex*> nods;
    std::vector<double> orth;

    if(!e->getNumChildren())
      for(int i=0; i<numNodes; i++)
        nods.push_back(e->getVertex(i));
    else
      for(int i = 0; i < e->getNumChildren(); i++)
        for(int j = 0; j < e->getChild(i)->getNumVertices(); j++)
          nods.push_back(e->getChild(i)->getVertex(j));

    for(int nod = 0; nod < numNodes; nod++) out2->push_back((nods[nod])->x());
    for(int nod = 0; nod < numNodes; nod++) out2->push_back((nods[nod])->y());
    for(int nod = 0; nod < numNodes; nod++) out2->push_back((nods[nod])->z());

    if (_maxDim == 2)
      switch (numNodes) {
        case 2: fprintf(f5,"SL("); break;
        case 3: fprintf(f5,"ST("); break;
        case 4: fprintf(f5,"SQ("); break;
        default: Msg::Fatal("Error in Plugin 'Distance' (numNodes=%g).",numNodes); break;
      }
    else if (_maxDim == 3)
      switch (numNodes) {
        case 4: fprintf(f5,"SS("); break;
        case 8: fprintf(f5,"SH("); break;
        case 6: fprintf(f5,"SI("); break;
        case 5: fprintf(f5,"SY("); break;
        default: Msg::Fatal("Error in Plugin 'Distance' (numNodes=%g).",numNodes); break;
      }

    for (int j=0; j<numNodes; j++) {
      MVertex *v =  nods[j];
      if (j)
        fprintf(f5, ",%g,%g,%g", v->x(), v->y(), v->z());
      else
        fprintf(f5, "%g,%g,%g", v->x(), v->y(), v->z());
      double value;
      myAssembler.getDofValue(v, 0, 1, value);
      orth.push_back(value);
    }
    fprintf(f5,"){");
    for (unsigned int i=0; i<orth.size(); i++) {
      out2->push_back(orth[i]);
      if (i)
        fprintf(f5,",%g", orth[i]);
      else
        fprintf(f5,"%g", orth[i]);
    }
    fprintf(f5,"};\n");

  }
  fprintf(f5,"};\n");
  fclose(f5);

  lsys->clear();
  lsys2->clear();

  data2->Time.push_back(0);
  data2->setFileName("orthogonal.pos");
  data2->finalize();

#endif
  }

  return view;
}
