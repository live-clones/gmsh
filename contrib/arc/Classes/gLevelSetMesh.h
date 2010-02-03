//
// Description :
//
//
// Author:  <Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _GLEVELSET_MESH_H_
#define _GLEVELSET_MESH_H_

#include "DILevelset.h"
#include "MVertex.h"
#include "GModel.h"

class gLevelSetMesh : public gLevelsetPrimitive
{
    protected :

      std::map<int, double > *_LevelSetValue;
      GModel * _pModel;

    public :
      gLevelSetMesh(std::map<int, double > * LevelSetValue, GModel *p, int &tag) : gLevelsetPrimitive(tag)
      {
        _LevelSetValue = LevelSetValue;
        _pModel = p;
      };
      // return negative value inward and positive value outward
      virtual double operator() (const double &x, const double &y, const double &z) const
      {
        SPoint3 p(x,y,z);
        MElement *e = _pModel->getMeshElementByCoord(p);
        if (e->getParent()) e = e->getParent();
        int numV = e->getNumVertices();
        double xyz[3] = {x,y,z};
        double uvw[3];
        e->xyz2uvw(xyz,uvw);
        double s[20];
        e->getShapeFunctions(uvw[0],uvw[1],uvw[2],s);
        double ls = 0;

//        std::cout<<"xyz : "<< x << " "<<y <<" "<<z<<"\n";
        for (int i = 0;i<numV;i++)
        {
//           std::cout<<"Vertex xyz :"<< e->getVertex(i)->x() << " "<<e->getVertex(i)->y() <<" "<<e->getVertex(i)->z()<<"\n";
//           std::cout<<"Vertex LS : "<< getVertexValue(e->getVertex(i)) <<"\n";
           ls = ls + s[i]*getVertexValue(e->getVertex(i));
        }
//        std::cout<<"=> LS : "<< ls <<"\n";
        return ls;
      }
      virtual double getVertexValue(MVertex *v) const;
      int type() const {return LSMESH;}
};



#endif
