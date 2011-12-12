// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ANALYSECURVEDMESH_H_
#define _ANALYSECURVEDMESH_H_

#include "Plugin.h"
#include "MElement.h"
#include <vector>

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin();
}

class GMSH_AnalyseCurvedMeshPlugin : public GMSH_PostPlugin
{
  private :
    int _dim;
    GModel *_m;
    int _maxDepth;
    double _jacBreak, _bezBreak, _tol;
    
    int _numAnalysedEl;
    int _numInvalid, _numValid, _numUncertain;
    double _min_Javg, _max_Javg, _avg_Javg;
    double _min_pJmin, _avg_pJmin;
    double _min_ratioJ, _avg_ratioJ;
    
  public :
    GMSH_AnalyseCurvedMeshPlugin(){}
    std::string getName() const { return "AnalyseCurvedMesh"; }
    std::string getShortHelp() const {
      return "Check validity of elements and/or compute min&max of the jacobian";
    }
    std::string getHelp() const;
    std::string getAuthor() const { return "Amaury Johnen"; }
    int getNbOptions() const;
    StringXNumber *getOption(int);  
    PView *execute(PView *);
    void checkValidity(MElement *const *, int numEl, std::vector<MElement*> &invalids);
    
    //void storeJMin(MElement *const *, int numEl, std::map<int, std::vector<double> > &data);
    
    
  private :
    void checkValidity(int toDo);
    void computeMinMax(std::map<int, std::vector<double> > *data = 0);
    void computeMinMax(MElement *const *, int numEl, std::map<int, std::vector<double> > *data = 0);
    int subDivision(const bezierBasis*, const fullVector<double>&, int depth);
    void hideValid_ShowInvalid(std::vector<MElement*> &invalids);
};

class BezierJacobian;
struct lessMinB {
  bool operator()(BezierJacobian*, BezierJacobian*) const;
};
struct lessMaxB {
  bool operator()(BezierJacobian*, BezierJacobian*) const;
};

class BezierJacobian
{
private:
  fullVector<double> _jacBez;
  double _minJ, _maxJ, _minB, _maxB; //Extremum of Jac at corners and of bezier values
  int _depthSub;
  const JacobianBasis *_jfs;
  
public:
  BezierJacobian(fullVector<double> &, const JacobianBasis *, int depth);
  void subDivisions(fullVector<double> &vect) const
    {_jfs->bezier->subDivisor.mult(_jacBez, vect);}
  
  inline int depth() const {return _depthSub;}
  inline double minJ() const {return _minJ;}
  inline double maxJ() const {return _maxJ;}
  inline double minB() const {return _minB;}
  inline double maxB() const {return _maxB;}
};

#endif
