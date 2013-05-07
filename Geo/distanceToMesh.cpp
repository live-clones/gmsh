#include "distanceToMesh.h"
#include "MElement.h"
#include "Numeric.h"

distanceToMesh::distanceToMesh(GModel *gm, std::string physical, int nbClose)
  : _computed (false) , _gm(gm), _nbClose(nbClose)
{
  std::map<int, std::vector<GEntity*> > groups [4];
  gm->getPhysicalGroups(groups);
  for (GModel::piter it = gm->firstPhysicalName() ;
       it != gm->lastPhysicalName() ; ++it){
    if (it->second == physical){
      _entities = groups[it->first.first][it->first.second];
    }
  }
}


#if defined(HAVE_ANN)
distanceToMesh::~distanceToMesh()
{
  if (_computed){
    delete [] _index;
    delete [] _dist;
    delete _kdtree;
    annDeallocPts (_nodes);    
  }
}

void distanceToMesh::setup()
{
  _computed = true;
  std::set<MVertex *> _all;
  for (unsigned int i=0;i<_entities.size();i++){
    for (unsigned int k = 0; k < _entities[i]->getNumMeshElements(); k++) {
      for (int j = 0; j<  _entities[i]->getMeshElement(k)->getNumVertices();j++){
	_all.insert(_entities[i]->getMeshElement(k)->getVertex(j));
	_v2e.insert (std::make_pair(_entities[i]->getMeshElement(k)->getVertex(j),
			       _entities[i]->getMeshElement(k)));
      }
    }
  }
  _nodes = annAllocPts(_all.size(), 3);
  std::set<MVertex*>::iterator itp = _all.begin();
  int ind = 0;
  while (itp != _all.end()){
    MVertex* pt = *itp;
    _nodes[ind][0] = pt->x();
    _nodes[ind][1] = pt->y();
    _nodes[ind][2] = pt->z();
    _vertices.push_back(pt);
    itp++; ind++;
  }
  _kdtree = new ANNkd_tree(_nodes, _all.size(), 3);  
  _index = new ANNidx[_nbClose];
  _dist  = new ANNdist[_nbClose];
}

double distanceToMesh::operator () (double x, double y, double z)
{
  if (!_computed) setup();
  double point[3] = {x,y,z};
  _kdtree->annkSearch(point, _nbClose, _index, _dist);
  std::set<MElement*> elements;
  for (int i=0;i<_nbClose;i++){
    int iVertex = _index [i];
    MVertex *v = _vertices[iVertex];
    for (std::multimap<MVertex*,MElement*>::iterator itm =
           _v2e.lower_bound(v); itm != _v2e.upper_bound(v); ++itm)
      elements.insert (itm->second);    
  }
  double minDistance = 1.e22;
  SPoint3 closest;
  for (std::set<MElement*>::iterator it = elements.begin();
       it != elements.end();++it){
    double distance;
    MVertex *v1 = (*it)->getVertex(0);
    MVertex *v2 = (*it)->getVertex(1);
    SPoint3 p1(v1->x(), v1->y(), v1->z());
    SPoint3 p2(v2->x(), v2->y(), v2->z());
    if ((*it)->getDim() == 1){
      SPoint3 pt;
      signedDistancePointLine(p1, p2,SPoint3(x,y,z),distance,pt);
      if (fabs(distance) < fabs(minDistance)){
	minDistance=distance;
      }
    }
  }
  return minDistance;
}
#else
double distanceToMesh::operator () (double x, double y, double z)
{
  Msg::Fatal ("impossible to compute distance to a mesh without ANN");  
}
#endif
