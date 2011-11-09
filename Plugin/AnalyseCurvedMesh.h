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
    double _min_Javg, _max_Javg;
    double _min_pJmin, _avg_pJmin;
    double _min_ratioJ, _avg_ratioJ;
    //
    
  public :
    GMSH_AnalyseCurvedMeshPlugin(){}
    std::string getName() const { return "AnalyseCurvedMesh"; }
    std::string getShortHelp() const
    {
      return "Check validity of elements and/or compute min&max of the jacobian";
    }
    std::string getHelp() const;
    std::string getAuthor() const { return "Amaury Johnen"; }
    int getNbOptions() const;
    StringXNumber *getOption(int);  
    PView *execute(PView *);
    void checkValidity(MElement *const *, int numEl, std::vector<MElement*> &invalids);
    void checkValidity_BLAS(MElement *const *, int numEl, std::vector<MElement*> &invalids);
    
  private :
    void checkValidity(int toDo);
    void computeMinMax();
    void computeMinMax(MElement *const *, int numEl);
    void hideValid_ShowInvalid(std::vector<MElement*> &invalids);
    int subDivision(const bezierBasis*, const fullVector<double>&, int depth);
    /*bool isJacPositive(MElement *);
    int method_1_1(MElement *, int depth);
    int method_1_2(MElement *, int depth);
    int method_1_3(MElement *, int depth);
    void method_2_2(MElement *const *, std::vector<int> &tags, int depth);
    void method_2_3(MElement *const *, std::vector<int> &tags, int depth);
    //int checkJacobian(MElement *, int depth);
    //int *checkJacobian2(MElement *const *, int numEl, int depth);
    int *checkJacobian(MElement *const *, int numEl, int depth, int method);
    int division(const bezierBasis *, const fullVector<double> &, int depth);
    */
};

class BezierJacobian
{
private:
  fullVector<double> _jacBez;
  double _minJ, _maxJ, _minB, _maxB; //Extremum of Jac at corners and of bezier values
  int _depthSub;
  int _num; // Used for map of minmaxB
  static int _globalNum;
  
public:
  BezierJacobian(fullVector<double> &, const JacobianBasis *, int depth);
  inline bool operator<(const BezierJacobian &other) const
    {return other._maxB - _maxB - other._minB + _minB < 0;}
  void partition(fullVector<double> &, const JacobianBasis *) const;
  inline bool isObsolet(double maxLB, double minUB, double tol) const
    {return _maxB - maxLB < tol &&  minUB - _minB < tol;}
  
  int num() const {return _num;}
  int depth() const {return _depthSub;}
  double minJ() const {return _minJ;}
  double minB() const {return _minB;}
  double maxJ() const {return _maxJ;}
  double maxB() const {return _maxB;}
  double setMinMaxBounds(double &minLB, double &minUB, double &maxLB, double &maxUB) const
  {
    /*Msg::Info("setminmax : %g = %g - %g",_minJ-_minB,_minJ,_minB);
    Msg::Info("setminmax : %g = %g - %g",_maxB-_maxJ,_maxB,_maxJ);Msg::Info(" ");
    
    int g;
    std::cin >> g;*/
      minUB = _minJ; minLB = _minB; maxUB = _maxB; maxLB = _maxJ;}
};

#endif
