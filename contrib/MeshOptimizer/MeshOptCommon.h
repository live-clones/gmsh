// Copyright (C) 2014 ULg-UCL
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
// <gmsh@geuz.org>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef _MESHOPTCOMMON_H_
#define _MESHOPTCOMMON_H_

#include <vector>


class MElement;
class ObjContrib;


struct MeshOptParameters {                             // Parameters controlling the strategy
  enum { STRAT_CONNECTED, STRAT_ONEBYONE };
  struct PassParameters {                              // Parameters controlling the optimization procedure in each pass
    std::vector<ObjContrib*> contrib;                  // Indices of contributions to objective function
    int optIterMax;                                    // Max. number of opt. iterations each time the barrier is moved
    int barrierIterMax;                                // Max. number of times the barrier is moved
  };
  struct PatchDefParameters {
    int strategy;                                      // Strategy: connected patches or adaptive one-by-one
    int minLayers, maxLayers;                          // Min. and max. nb. of layers around a bad element in patch
    union {
      struct {                                         // If adaptive strategy:
        int maxAdaptPatch;                             // Max. nb. of adaptation iterations
        int maxLayersAdaptFact;                        // Growth rate in number of layers around a bad element
        double distanceAdaptFact;                      // Growth rate in max. distance from bad element
      };
      bool weakMerge;                                   // If connected strategy: weak or strong merging of patches
    };
    virtual double elBadness(MElement *el) = 0;         // Pointer to function returning "badness" of element (for patch creation)
    virtual double maxDistance(MElement *el) = 0; // Pointer to function checking the patch distance criterion for a given bad element
  };
  int dim ;                                             // Which dimension to optimize
  bool onlyVisible ;                                    // Apply optimization to visible entities ONLY
  bool fixBndNodes;                                     // If points can move on boundaries
  PatchDefParameters *patchDef;
  std::vector<PassParameters> pass;
  int optDisplay;                                       // Sampling rate in opt. iterations for display
  int verbose;                                          // Level of information displayed and written to disk
  int success;                                          // Success flag: -1 = fail, 0 = partial fail (target not reached), 1 = success
  double CPU;                                           // Time for optimization
};


#endif
