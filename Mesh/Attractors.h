#ifndef _ATTRACTORS_H_
#define _ATTRACTORS_H_

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

// an attractor is a functor that returns a mesh size when you give it
// a distance
#include <list>
#include "SPoint3.h"
#include "Geo.h"
#include "Message.h"
#include "GEdge.h"
#ifdef HAVE_ANN_
#include "ANN/ANN.h"
#endif

class Attractor {
 protected :
#ifdef HAVE_ANN_
  ANNkd_tree* kdtree;
  ANNpointArray zeronodes;
  ANNidxArray index;
  ANNdistArray dist;
#endif
  std::list <SPoint3> attractorPoints;  
  std::list <SPoint3> lcs;  
  static std::list <Attractor *>  allAttractors;  
public :
  Attractor();
  virtual ~Attractor();
  virtual double operator () ( const double & distance ) = 0;
  // adds a point in the attractor.
  void addPoint ( double X, double Y, double Z, double lc = -1.0);
  void buildFastSearchStructures() ;
  static void reset (); 
  static double lc (double X, double Y, double Z) ;
  static bool size () {return allAttractors.size();}
};

class tresholdAttractor : public Attractor
{
  double treshold, meshSizeIn, meshSizeOut, factor;
  tresholdAttractor(double _tres, double _In, double _Out, double _fact) 
    : treshold(_tres), meshSizeIn(_In), meshSizeOut(_Out), factor(_fact) {}
 public:
  static Attractor* New(double _tres, double _In, double _Out, double _fact)
  {
    if(_fact == 1){
      Msg(WARNING,"tresholdAttractor factor should be greater than 1");
      _fact = 3;
    }
    tresholdAttractor *a = new tresholdAttractor(_tres, _In, _Out, _fact);
    allAttractors.push_back(a);
    return a;
  }
  virtual double operator () (const double & distance);
};

// this attractor uses the 1D mesh for propagating the edge lengths
// inside the 2D and 3D domain. This attra

class mesh1DAttractor : public Attractor
{  
};


// build a list of points for the attractor on a model edge
// presently, the function is duplicated (internals of gmsh and GMODEL)
void buildListOfPoints(Attractor*, GEdge*, int);
void buildListOfPoints(Attractor*, Curve*, int);

#endif
