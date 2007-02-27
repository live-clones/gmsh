// $Id: Attractors.cpp,v 1.3 2007-02-27 17:15:47 remacle Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Attractors.h"
#include "GeoInterpolation.h"

#define maxpts  1

std::list <Attractor *> Attractor::allAttractors;  

void Attractor::addPoint ( double X, double Y, double Z, double lc)
{
  attractorPoints.push_back(SPoint3(X,Y,Z));
  //  lcs.push_back(lc);
}

Attractor::~Attractor()
{
#ifdef HAVE_ANN_
  if(kdtree) delete kdtree;
  if(zeronodes) annDeallocPts(zeronodes);
  delete [] index;
  delete [] dist;
#endif
}

Attractor::Attractor()
#ifdef HAVE_ANN_
  : kdtree (0), zeronodes(0)
#endif
{
#ifdef HAVE_ANN_
  index = new ANNidx[maxpts];
  dist = new ANNdist[maxpts];
#endif
}

void Attractor::reset() 
{  
  for(std::list<Attractor *>::iterator it = allAttractors.begin();
      it != allAttractors.end(); ++it)
    delete *it;
  allAttractors.clear();
}

void Attractor::buildFastSearchStructures() 
{
#ifdef HAVE_ANN_
  if(zeronodes){
    annDeallocPts(zeronodes);
    delete kdtree;
  }
  int totpoints = 0;
  for(std::list <Attractor *>::iterator it = allAttractors.begin();
      it != allAttractors.end(); ++it)
    totpoints += (*it)->attractorPoints.size();
  if (totpoints)
    zeronodes = annAllocPts(totpoints, 4);
  int k = 0;
  for(std::list <Attractor *>::iterator it = allAttractors.begin();
      it != allAttractors.end(); ++it){
    for (std::list <SPoint3>::iterator it2 = (*it)->attractorPoints.begin();
	 it2 != (*it)->attractorPoints.end(); ++it2){
      zeronodes[k][0]=it2->x();
      zeronodes[k][1]=it2->y();
      zeronodes[k++][2]=it2->z();
    }
  }
  kdtree = new ANNkd_tree(zeronodes, totpoints, 3);
#endif
}

double Attractor::lc(double X, double Y, double Z)
{
  if(!allAttractors.size()) return 1.e22;
  double xyz[3] = {X, Y, Z};
  double minLc = 1.e22;

  for(std::list<Attractor *>::iterator it = allAttractors.begin();
      it != allAttractors.end(); ++it){
    if((*it)->attractorPoints.size() == 1){
      SPoint3 p = *((*it)->attractorPoints.begin());
      double dist = sqrt((p.x()-X)*(p.x()-X)+(p.y()-Y)*(p.y()-Y)+(p.z()-Z)*(p.z()-Z));
      Attractor *a = (*it);
      minLc = std::min((*a)(dist),minLc);	  
    }
    else{
#ifdef HAVE_ANN_
      (*it)->kdtree->annkSearch(xyz, maxpts, (*it)->index, (*it)->dist);
      double distHere = sqrt((*it)->dist[0]);
      Attractor *a = (*it);
      minLc = std::min((*a)(distHere), minLc);
#else
      Msg(GERROR,"GMSH should be compiled with ANN in order to enable attractors !");
#endif
    }
  }
  return minLc;  
}

void buildListOfPoints(Attractor * a, Curve *c, int N)
{
  for(int i = 0; i < N; i++){
    double u = (double)i / (N - 1);
    Vertex V = InterpolateCurve (c, u, 0);
    a->addPoint(V.Pos.X, V.Pos.Y, V.Pos.Z);
  }
}

void buildListOfPoints(Attractor * a, GEdge *c, int N)
{
  for(int i = 0; i < N; i++){
    double u = (double)i / (N - 1);
    Range<double> b = c->parBounds(0);
    double t = b.low() + u * (b.high() - b.low());
    GPoint gp = c->point(t);
    a->addPoint(gp.x(), gp.y(), gp.z());
  }
}

double tresholdAttractor::operator () (const double & distance) 
{
  double l;
  if(distance > factor * treshold) l = meshSizeOut;
  else if(distance > treshold) {
    const double t = (factor / (factor - 1.)) * (1. - treshold / distance);
    l =  1. / ((1. / meshSizeIn) * (1. - t) + (1. / meshSizeOut) * t);
  }  
  else l = meshSizeIn;

  return l;
}
