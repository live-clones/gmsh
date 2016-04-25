// Copyright (C) 2013 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Amaury Johnen

#include "OptHomPeriodicity.h"
#include "GEntity.h"
#include "GFace.h"
#include "GEdge.h"
#include "MVertex.h"
#include "fullMatrix.h"

OptHomPeriodicity::OptHomPeriodicity(std::vector<GEntity*> &entities)
{
  for (unsigned int i = 0; i < entities.size(); ++i) {
    // MVertex on GVertex cannot move
    if (entities[i]->dim() == 0) continue;

    GEntity *master = entities[i]->meshMaster();
    if (master != entities[i]) {
      _master2slave.insert(std::make_pair(master, entities[i]));
    }
  }
}

void OptHomPeriodicity::fixPeriodicity()
{
  _relocateMasterVertices();
  _copyBackMasterVertices();
}

void OptHomPeriodicity::_relocateMasterVertices()
{
  std::multimap<GEntity*, GEntity*>::iterator it;
  for (it = _master2slave.begin(); it != _master2slave.end(); ++it) {
    if (it->first->dim() == 2) {
      GFace *master = dynamic_cast<GFace*>(it->first);
      GFace *slave = dynamic_cast<GFace*>(it->second);
      std::vector<double> tfo = _inverse(slave->affineTransform);

      std::map<MVertex*, MVertex*> &vertS2M = slave->correspondingVertices;
      std::map<MVertex*, MVertex*>::iterator vit;
      for (vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
        GPoint p = _transform(vit->first, master, tfo);
        MFaceVertex *v = dynamic_cast<MFaceVertex*>(vit->second);
        SPoint3 p3 ((v->x()+p.x())/2, (v->y()+p.y())/2, (v->z()+p.z())/2);
        SPoint2 p2 = master->parFromPoint(p3);
        GPoint gp = master->point(p2);
        v->setXYZ(gp.x(), gp.y(), gp.z());
        v->setParameter(0, gp.u());
        v->setParameter(1, gp.v());
      }
    }
    else {
      GEdge *master = dynamic_cast<GEdge*>(it->first);
      int numSlave = _master2slave.count(master);

      for (int i = 0; i < numSlave; ++i) {
        if (i > 0) ++it;
        GEntity *slave = it->second;
        std::vector<double> tfo = _inverse(slave->affineTransform);

        std::map<MVertex*, MVertex*> &vertS2M = slave->correspondingVertices;
        std::map<MVertex*, MVertex*>::iterator vit;
        for (vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
          GPoint p = _transform(vit->first, master, tfo);
          MVertex *v = vit->second;
          v->setXYZ(v->x()+p.x(), v->y()+p.y(), v->z()+p.z());
        }
      }

      double coeff = 1./(1+numSlave);
      for (unsigned int k = 0; k < master->getNumMeshVertices(); ++k) {
        MEdgeVertex *v = dynamic_cast<MEdgeVertex*>(master->getMeshVertex(k));
        SPoint3 p3 (v->x()*coeff, v->y()*coeff, v->z()*coeff);
        double u = master->parFromPoint(p3);
        GPoint gp = master->point(u);
        v->setXYZ(gp.x(), gp.y(), gp.z());
        v->setParameter(0, gp.u());
      }
    }
  }
}

void OptHomPeriodicity::_copyBackMasterVertices()
{
  std::multimap<GEntity*, GEntity*>::iterator it;
  for (it = _master2slave.begin(); it != _master2slave.end(); ++it) {
    if (it->first->dim() == 2) {
      GFace *master = dynamic_cast<GFace*>(it->first);
      GFace *slave = dynamic_cast<GFace*>(it->second);
      std::vector<double> tfo = slave->affineTransform;

      std::map<MVertex*, MVertex*> &vertS2M = slave->correspondingVertices;
      std::map<MVertex*, MVertex*>::iterator vit;
      for (vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
        GPoint p = _transform(vit->second, slave, tfo);
        MFaceVertex *v = dynamic_cast<MFaceVertex*>(vit->first);
        v->setXYZ(p.x(), p.y(), p.z());
        v->setParameter(0, p.u());
        v->setParameter(1, p.v());
      }
    }
    else {
      GEdge *master = dynamic_cast<GEdge*>(it->first);
      GEdge *slave = dynamic_cast<GEdge*>(it->second);
      std::vector<double> tfo = slave->affineTransform;

      std::map<MVertex*, MVertex*> &vertS2M = slave->correspondingVertices;
      std::map<MVertex*, MVertex*>::iterator vit;
      for (vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
        GPoint p = _transform(vit->second, slave, tfo);
        MEdgeVertex *v = dynamic_cast<MEdgeVertex*>(vit->first);
        v->setXYZ(p.x(), p.y(), p.z());
        v->setParameter(0, p.u());
      }
    }
  }
}

GPoint OptHomPeriodicity::_transform(MVertex *vsource, GEntity *target, std::vector<double> &tfo)
{
  double ps[4] = {vsource->x(), vsource->y(), vsource->z(), 1.};
  double res[4] = {0., 0., 0., 0.};
  int idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      res[i] +=  tfo[idx++] * ps[j];

  SPoint3 p3 (res[0], res[1], res[2]);
  if (target->dim() == 2) {
    SPoint2 p2 = dynamic_cast<GFace*>(target)->parFromPoint(p3);
    return dynamic_cast<GFace*>(target)->point(p2);
  }
  else if (target->dim() == 1) {
    double u = dynamic_cast<GEdge*>(target)->parFromPoint(p3);
    return dynamic_cast<GEdge*>(target)->point(u);
  }
  else {
    Msg::Error("Expected a face or an edge for computing "
               "periodicity transformation.");
    return GPoint();
  }
}

std::vector<double> OptHomPeriodicity::_inverse(std::vector<double> &tfo)
{
  // Note that the last row of tfo must be (0 0 0 1)...
  std::vector<double> result(16);
  fullMatrix<double> mat(4, 4), inv;
  int idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      mat(i, j) = tfo[idx++];
  mat.invert(inv);

  idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      result[idx++] = inv(i, j);
  return result;
}
