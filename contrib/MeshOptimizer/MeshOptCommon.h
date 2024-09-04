// MeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef MESH_OPT_COMMON_H
#define MESH_OPT_COMMON_H

#include <vector>
#include <list>
#include "GmshMessage.h"
#include "MeshOptimizerConfig.h"

class MElement;
class GEntity;
class SPoint3;
class ObjContrib;

// ncurses shortcuts
void mvinit();
void mvterminate();
void mvpause();
void mvgetScreenSize(int &nbRow, int &nbCol);
void mvprintCenter(int row, const char *fmt, ...);
void mvprintLeft(int row, const char *fmt, ...);
void mvprintRight(int row, const char *fmt, ...);
void mvprintXY(int row, int col, const char *fmt, ...);
// color scheme: 0=default, 1=last in yellow back, others in white back, 2=even
// numbers in white back
void mvprintList(int row, int maxSize, std::list<char *> listStr,
                 int colorScheme = 0);
void mvfillRow(int row, char fillWith = ' ');
void mvbold(bool on);
void mvcolor(int colorScheme, bool on);

class redirectMessage : public GmshMessage {
private:
  std::string _logFileName;
  bool _console;

public:
  virtual void operator()(std::string level, std::string message);
  redirectMessage(std::string logFileName, bool console);
};

class MeshOptPatchDef {
public:
  enum { STRAT_DISJOINT, STRAT_ONEBYONE };
  int strategy; // Strategy: disjoint patches or adaptive one-by-one
  int minLayers,
    maxLayers; // Min. and max. nb. of layers around a bad element in patch
  union {
    struct { // If adaptive strategy:
      int maxPatchAdapt; // Max. nb. of adaptation iterations
      int maxLayersAdaptFact; // Growth rate in number of layers around a bad
                              // element
      double distanceAdaptFact; // Growth rate in max. distance from bad element
    };
    bool weakMerge; // If disjoint strategy: weak or strong merging of patches
  };
  virtual ~MeshOptPatchDef() {}
  virtual double elBadness(
    MElement *el, // Determine "badness" of a given element (for patch creation)
    GEntity *gEnt) const = 0;
  virtual double
  bndElBadness(MElement *el, // Determine "badness" of a given boundary element
                             // (for patch creation)
               GEntity *gEnt) const = 0;
  virtual double
  maxDistance(MElement *el) const = 0; // Compute max. distance to a given bad
                                       // element for elements in patch
  virtual int
  inPatch(const SPoint3 &badBary, // Determine whether a given element should be
                                  // included in the patch around a...
          double limDist, // ... given bad element barycenter, with a limit
                          // distance if needed. Output: ...
          MElement *el, // ... -1 = excluded, 0 = included only up to minLayers,
                        // 1 = included up to maxLayers
          GEntity *gEnt) const = 0;

protected:
  bool testElInDist(const SPoint3 &P,
                    double limDist, // Test whether an element is within a
                                    // certain distance from a point
                    MElement *el) const;
};

struct MeshOptPass { // Parameters controlling the optimization procedure in
                     // each pass
  std::vector<ObjContrib *>
    contrib; // Indices of contributions to objective function
  int
    maxOptIter; // Max. number of opt. iterations each time the barrier is moved
  int maxParamUpdates; // Max. number of times the obj. func. parameters are
                       // updated (i.e. the barrier is moved)
};

class MeshOptParameters { // Parameters controlling the strategy
public:
  int dim; // Which dimension to optimize
  bool onlyVisible; // Apply optimization to visible entities ONLY
  int fixBndNodes; // If points on all (1) or periodic (2) boundaries are fixed
  bool useGeomForPatches,
    useGeomForOpt; // Whether to use info from CAD for creation of patches and
                   // for optimization
  bool useBoundaries; // Whether to use boundary elements
  MeshOptPatchDef *patchDef;
  std::vector<MeshOptPass> pass;
  int displayInterv; // Sampling rate in opt. iterations for display
  int verbose; // Level of information displayed and written to disk
  int nCurses; // Enhanced text output (not affected by verbose)
  std::string logFileName; // External log file (affected by verbose)
  int success; // Success flag: -1 = fail, 0 = partial fail (target not
               // reached), 1 = success
  double CPU; // Time for optimization
};

#endif
