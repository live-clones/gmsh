// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "meshGFaceBoundaryLayers.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MVertex.h"
#include "Field.h"


/*
               ^  ni
               |
               |
      +-----------------+
               bi      /
                 bj  /
                   /\
                 /    \   nj
               /        Z
             +
*/

static double solidAngle (SVector3 &ni, SVector3 &nj,
			  SPoint3  &bi, SPoint3  &bj)
{
  double cosa = dot (ni, nj);
  SVector3 bibj = bj - bi;
  SVector3 sina = crossprod ( ni , nj );
  double a = atan2(sina.norm(),cosa);
  double sign = dot (nj, bibj);
  return sign > 0 ? fabs (a) : -fabs(a);
}

BoundaryLayerColumns* buildAdditionalPoints3D_CAD_BASED (GRegion *gr)
{
  return 0;
}

BoundaryLayerColumns* buildAdditionalPoints3D (GRegion *gr)
{
#if !defined(HAVE_ANN)
  return 0;
#else
  FieldManager *fields = gr->model()->getFields();
  if(fields->getBoundaryLayerField() <= 0){
    return 0;
  }
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField*> (bl_field);

  if (!blf)return 0;

  double _treshold = blf->fan_angle * M_PI / 180 ;

  BoundaryLayerColumns * _columns = new BoundaryLayerColumns;

  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator itf = faces.begin();
  std::set<MVertex*> _vertices;
  std::map<MFace,SVector3,Less_Face> _normals;

  // filter vertices : belong to BL and are classified on FACES
  while(itf != faces.end()){
    if (blf->isFaceBL((*itf)->tag())){
      printf("FACE %d is a boundary layer face %d triangles\n",(*itf)->tag(),
             (int)(*itf)->triangles.size());
      for(unsigned int i = 0; i< (*itf)->triangles.size(); i++)
	for(unsigned int j = 0; j< 3; j++){
	  if ((*itf)->triangles[i]->getVertex(j)->onWhat()->dim() != 3){
	    _columns->_non_manifold_faces.insert(std::make_pair((*itf)->triangles[i]->getVertex(j),(*itf)->triangles[i]));
	    _vertices.insert((*itf)->triangles[i]->getVertex(j));
	    _normals [(*itf)->triangles[i]->getFace(0)] = SVector3(0,0,0);
	  }
	}
    }
    ++itf;
  }
  printf("%d vertices \n", (int)_vertices.size());

  // assume that the initial mesh has been created i.e. that there exist
  // tetrahedra inside the domain. Tetrahedra are used to define
  // exterior normals
  for (unsigned int i=0;i<gr->tetrahedra.size();i++){
    for (int j=0;j<4;j++){
      MFace f = gr->tetrahedra[i]->getFace(j);
      std::map<MFace,SVector3,Less_Face>::iterator it = _normals.find(f);
      if (it != _normals.end()){
	MVertex *v0 = f.getVertex(0);
	MVertex *v1 = f.getVertex(1);
	MVertex *v2 = f.getVertex(2);
	MVertex *v3 = 0;
	for (int k=0;k<4;k++){
	  if (gr->tetrahedra[i]->getVertex(k) != v0 &&
	      gr->tetrahedra[i]->getVertex(k) != v1 &&
	      gr->tetrahedra[i]->getVertex(k) != v2 ){
	    v3 = gr->tetrahedra[i]->getVertex(k);
	  }
	}
	SVector3 v01 (v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
	SVector3 v02 (v2->x()-v0->x(),v2->y()-v0->y(),v2->z()-v0->z());
	SVector3 v03 (v3->x()-v0->x(),v3->y()-v0->y(),v3->z()-v0->z());
	SVector3 n = crossprod (v01,v02);
	double sign = dot(n,v03);
	n.normalize();
	if (sign > 0)it->second = n;
	else it->second = n*(-1.0);
      }
    }
  }

  // for all boundry points
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    std::vector<MTriangle*> _connections;
    std::vector<SVector3> _dirs, _allDirs;
    for (std::multimap<MVertex*,MTriangle*>::iterator itm =
           _columns->_non_manifold_faces.lower_bound(*it);
         itm != _columns->_non_manifold_faces.upper_bound(*it); ++itm){
      _connections.push_back (itm->second);
      _allDirs.push_back (_normals[itm->second->getFace(0)]);
    }

    // a list of normals is associated to a given vertex
    SPoint3 p ((*it)->x(),(*it)->y(),(*it)->z());
    std::vector<std::vector<int> > groupsOfDirections;
    for (unsigned int i=0;i<_connections.size();i++){
      SPoint3 bi = _connections[i]->barycenter();
      SVector3 ni = _allDirs[i];
      bool found = false;
      for (unsigned int j=0;j<groupsOfDirections.size();j++){
	for (unsigned int k=0;k<groupsOfDirections[j].size();k++){
	  int iDir = groupsOfDirections[j][k];
	  SPoint3 bj = _connections[iDir]->barycenter();
	  SVector3 nj = _allDirs[iDir];
	  double angle = solidAngle (ni,nj,bi,bj);
	  // those two directions are
	  if (angle < _treshold){
	    found = true;
	    groupsOfDirections[j].push_back(i);
	    goto gotit;
	  }
	}
      }
    gotit:
      if (!found){
	std::vector<int> newDir;
	newDir.push_back(i);
	groupsOfDirections.push_back(newDir);
      }
    }


    std::vector<SVector3> shoot;
    for (unsigned int j=0;j<groupsOfDirections.size();j++){
      SVector3 n;
      for (unsigned int k=0;k<groupsOfDirections[j].size();k++){
	int iDir = groupsOfDirections[j][k];
	n += _allDirs[iDir];
      }
      n.normalize();
      shoot.push_back(n);
    }

    // now create the BL points
    for (unsigned int DIR=0;DIR<shoot.size();DIR++){
      SVector3 n = shoot[DIR];
      MVertex *current = *it;
      SVector3 basis (current->x(),current->y(),current->z());
      double H = blf->hwall_n;
      std::vector<MVertex*> _column;
      std::vector<SMetric3> _metrics;
      double dist = H;
      while(dist < blf->thickness){
	SVector3 newp = basis + n * H;
	MVertex *_current = new MVertex (newp.x(),newp.y(),newp.z());
	_column.push_back(_current);
	H *=  blf->ratio;
	dist += H;
	basis = newp;
      }
      _columns->addColumn(n,*it, _column, _metrics);
    }
  }
  // HERE WE SHOULD FILTER THE POINTS IN ORDER NOT TO HAVE POINTS THAT ARE TOO CLOSE

  // DEBUG STUFF

  FILE *f = fopen ("test3D.pos","w");
  fprintf(f,"View \"\" {\n");
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    MVertex *v = *it;
    for (int i=0;i<_columns->getNbColumns(v);i++){
      const BoundaryLayerData &data = _columns->getColumn(v,i);
      for (unsigned int j=0;j<data._column.size();j++){
	MVertex *blv = data._column[j];
	fprintf(f,"SP(%g,%g,%g){%d};\n",blv->x(),blv->y(),blv->z(),v->getNum());
      }
    }
  }
  fprintf(f,"};\n");
  fclose (f);

  // END OF DEBUG STUFF

  return _columns;
#endif
  return 0;
}
