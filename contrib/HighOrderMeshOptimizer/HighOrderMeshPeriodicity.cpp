// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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
// Contributors: Amaury Johnen

#include "HighOrderMeshPeriodicity.h"
#include "GEntity.h"
#include "GFace.h"
#include "GEdge.h"
#include "MVertex.h"
#include "fullMatrix.h"

HighOrderMeshPeriodicity::HighOrderMeshPeriodicity(
  std::vector<GEntity *> &entities)
{
  for(std::size_t i = 0; i < entities.size(); ++i) {
    // MVertex on GVertex cannot move
    if(entities[i]->dim() == 0) continue;

    GEntity *master = entities[i]->getMeshMaster();
    if(master != entities[i]) {
      _master2slave.insert(std::make_pair(master, entities[i]));
    }
  }
}

void HighOrderMeshPeriodicity::fixPeriodicity()
{
  Msg::Debug("Correcting high order optimization for periodic connections");
  _relocateMasterVertices();
  _copyBackMasterVertices();
  Msg::Debug(
    "Finished correcting high order optimization for periodic connections");
}

void HighOrderMeshPeriodicity::_relocateMasterVertices()
{
  std::multimap<GEntity *, GEntity *>::iterator it;
  for(it = _master2slave.begin(); it != _master2slave.end(); ++it) {
    switch(it->first->dim()) {
    case 2: {
      GFace *master = dynamic_cast<GFace *>(it->first);
      GFace *slave = dynamic_cast<GFace *>(it->second);
      if(slave->affineTransform.size() < 16) break;

      std::vector<double> tfo = _inverse(slave->affineTransform);

      Msg::Info("Relocating nodes of master surface %i using slave %i",
                master->tag(), slave->tag());

      std::map<MVertex *, MVertex *> &vertS2M = slave->correspondingVertices;
      std::map<MVertex *, MVertex *>::iterator vit;
      for(vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
        MFaceVertex *v = dynamic_cast<MFaceVertex *>(vit->second);
        if(v && v->onWhat() == master) {
          SPoint3 p = _transform(vit->first, tfo);
          SPoint3 p3((v->x() + p.x()) / 2, (v->y() + p.y()) / 2,
                     (v->z() + p.z()) / 2);
          SPoint2 p2 = master->parFromPoint(p3);
          GPoint gp = master->point(p2);
          v->setXYZ(gp.x(), gp.y(), gp.z());
          v->setParameter(0, gp.u());
          v->setParameter(1, gp.v());
        }
      }

      std::map<MVertex *, MVertex *> &pointS2M =
        slave->correspondingHighOrderVertices;
      for(vit = pointS2M.begin(); vit != pointS2M.end(); ++vit) {
        MFaceVertex *v = dynamic_cast<MFaceVertex *>(vit->second);
        if(v && v->onWhat() == master) {
          SPoint3 p = _transform(vit->first, tfo);
          SPoint3 p3((v->x() + p.x()) / 2, (v->y() + p.y()) / 2,
                     (v->z() + p.z()) / 2);
          SPoint2 p2 = master->parFromPoint(p3);
          GPoint gp = master->point(p2);
          v->setXYZ(gp.x(), gp.y(), gp.z());
          v->setParameter(0, gp.u());
          v->setParameter(1, gp.v());
        }
      }
      break;
    }
    case 1: {
      GEdge *master = dynamic_cast<GEdge *>(it->first);
      int numSlave = _master2slave.count(master);

      for(int i = 0; i < numSlave; ++i) {
        if(i > 0) ++it;
        GEntity *slave = it->second;

        GEdge *me = dynamic_cast<GEdge *>(master);
        GEdge *se = dynamic_cast<GEdge *>(slave);
        if(slave->affineTransform.size() < 16) break;

        std::vector<double> tfo = _inverse(slave->affineTransform);

        Msg::Info("Relocating %d main and %d high order nodes for %d nodes "
                  "of master edge %i (%i-%i) using slave %i (%i-%i)",
                  slave->correspondingVertices.size(),
                  slave->correspondingHighOrderVertices.size(),
                  master->getNumMeshVertices(), me->tag(),
                  me->getBeginVertex() ? me->getBeginVertex()->tag() : -1,
                  me->getEndVertex() ? me->getEndVertex()->tag() : -1,
                  se->tag(),
                  se->getBeginVertex() ? se->getBeginVertex()->tag() : -1,
                  se->getEndVertex() ? se->getEndVertex()->tag() : -1);

        std::map<MVertex *, MVertex *>::iterator vit;

        std::map<MVertex *, MVertex *> &vertS2M = slave->correspondingVertices;
        for(vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
          MEdgeVertex *v = dynamic_cast<MEdgeVertex *>(vit->second);
          if(v && v->onWhat() == master) {
            SPoint3 gp = _transform(vit->first, tfo);
            v->setXYZ(v->x() + gp.x(), v->y() + gp.y(), v->z() + gp.z());
          }
        }
        std::map<MVertex *, MVertex *> &pointS2M =
          slave->correspondingHighOrderVertices;
        for(vit = pointS2M.begin(); vit != pointS2M.end(); ++vit) {
          MEdgeVertex *v = dynamic_cast<MEdgeVertex *>(vit->second);
          if(v && v->onWhat() == master) {
            SPoint3 gp = _transform(vit->first, tfo);
            v->setXYZ(v->x() + gp.x(), v->y() + gp.y(), v->z() + gp.z());
          }
        }
      }

      double coeff = 1. / (1 + numSlave);
      for(std::size_t k = 0; k < master->getNumMeshVertices(); ++k) {
        MEdgeVertex *v = dynamic_cast<MEdgeVertex *>(master->getMeshVertex(k));
        if(v && v->onWhat() == master) {
          SPoint3 p3(v->x() * coeff, v->y() * coeff, v->z() * coeff);
          double u;
          if(!master->XYZToU(p3.x(), p3.y(), p3.z(), u)) {
            Msg::Warning("Could not project average position of periodic "
                         "master %i on edge %i, "
                         " -> repositioning",
                         v->getNum(), master->tag());
          }
          GPoint gp = master->point(u);
          v->setXYZ(gp.x(), gp.y(), gp.z());
          v->setParameter(0, gp.u());
        }
      }
      break;
    }
    }
  }
}

#include <iostream>

// remark : points are not replaced by their reparametrisations on the
// face/edges to avoid small errors in periodicity (they are on the CAD on the
// master side) !!

void HighOrderMeshPeriodicity::_copyBackMasterVertices()
{
  std::multimap<GEntity *, GEntity *>::iterator it;
  for(it = _master2slave.begin(); it != _master2slave.end(); ++it) {
    switch(it->first->dim()) {
    case 2: {
      GFace *master = dynamic_cast<GFace *>(it->first);
      GFace *slave = dynamic_cast<GFace *>(it->second);

      Msg::Info("Copying master nodes from surface %d to %d", master->tag(),
                slave->tag());

      const std::vector<double> &tfo = slave->affineTransform;
      if(tfo.size() < 16) break;

      std::map<MVertex *, MVertex *>::iterator vit;

      std::map<MVertex *, MVertex *> &vertS2M = slave->correspondingVertices;
      for(vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
        MFaceVertex *sv = dynamic_cast<MFaceVertex *>(vit->first);
        MFaceVertex *mv = dynamic_cast<MFaceVertex *>(vit->second);
        if(mv && sv && mv->onWhat() == master) {
          SPoint3 xyz = _transform(mv, tfo);
          SPoint2 uv = master->parFromPoint(xyz);
          sv->setXYZ(xyz.x(), xyz.y(), xyz.z());
          sv->setParameter(0, uv.x());
          sv->setParameter(1, uv.y());
        }
      }

      int idx = 0;

      std::map<MVertex *, MVertex *> &pointS2M =
        slave->correspondingHighOrderVertices;
      for(vit = pointS2M.begin(); vit != pointS2M.end(); ++vit) {
        MFaceVertex *sv = dynamic_cast<MFaceVertex *>(vit->first);
        MFaceVertex *mv = dynamic_cast<MFaceVertex *>(vit->second);

        if(mv && sv && mv->onWhat() == master) {
          SPoint3 xyz = _transform(mv, tfo);
          SPoint2 uv = master->parFromPoint(xyz);
          sv->setXYZ(xyz.x(), xyz.y(), xyz.z());
          sv->setParameter(0, uv.x());
          sv->setParameter(1, uv.y());
        }
      }
      break;
    }
    case 1: {
      GEdge *master = dynamic_cast<GEdge *>(it->first);
      GEdge *slave = dynamic_cast<GEdge *>(it->second);

      Msg::Info("Copying master nodes from curve %d to %d", master->tag(),
                slave->tag());

      const std::vector<double> tfo = slave->affineTransform;
      if(tfo.size() < 16) break;

      std::map<MVertex *, MVertex *>::iterator vit;

      std::map<MVertex *, MVertex *> &vertS2M = slave->correspondingVertices;
      for(vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
        MEdgeVertex *sv = dynamic_cast<MEdgeVertex *>(vit->first);
        MEdgeVertex *mv = dynamic_cast<MEdgeVertex *>(vit->second);

        if(mv && mv->onWhat() == master) {
          SPoint3 p = _transform(mv, tfo);
          double u;
          if(!slave->XYZToU(p.x(), p.y(), p.z(), u)) {
            Msg::Warning("Could not position slave periodic point %i on edge "
                         "%i within tolerance ",
                         sv->getNum(), slave->tag());
          }
          sv->setXYZ(p.x(), p.y(), p.z());
          sv->setParameter(0, u);
        }
      }

      std::map<MVertex *, MVertex *> &pointS2M =
        slave->correspondingHighOrderVertices;
      for(vit = pointS2M.begin(); vit != pointS2M.end(); ++vit) {
        MEdgeVertex *sv = dynamic_cast<MEdgeVertex *>(vit->first);
        MEdgeVertex *mv = dynamic_cast<MEdgeVertex *>(vit->second);
        if(mv && mv->onWhat() == master) {
          SPoint3 p = _transform(mv, tfo);
          double u;
          if(!slave->XYZToU(p.x(), p.y(), p.z(), u)) {
            Msg::Warning("Could not position slave periodic point %i on edge "
                         "%i within tolerance",
                         sv->getNum(), slave->tag());
          }
          sv->setXYZ(p.x(), p.y(), p.z());
          sv->setParameter(0, u);
        }
      }
      break;
    }
    }
  }
}

SPoint3 HighOrderMeshPeriodicity::_transform(MVertex *vsource,
                                             const std::vector<double> &tfo)
{
  double ps[4] = {vsource->x(), vsource->y(), vsource->z(), 1.};
  double res[4] = {0., 0., 0., 0.};
  int idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) res[i] += tfo[idx++] * ps[j];

  return SPoint3(res[0], res[1], res[2]);
}

std::vector<double>
HighOrderMeshPeriodicity::_inverse(const std::vector<double> &tfo)
{
  std::vector<double> result(16, 0.);
  if(tfo.size() < 16) {
    Msg::Error("Wrong size of affine transformation matrix");
    return result;
  }
  // Note that the last row of tfo must be (0 0 0 1)...
  fullMatrix<double> mat(4, 4), inv;
  int idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) mat(i, j) = tfo[idx++];
  mat.invert(inv);
  idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) result[idx++] = inv(i, j);
  return result;
}
