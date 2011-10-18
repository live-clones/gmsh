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
    
  private :
    void checkValidity(int toDo);
    void computeMinMax();
    void checkValidity(MElement *const *, int numEl, std::vector<MElement*> &invalids);
    void computeMinMax(MElement *const *, int numEl);
    void hideValid_ShowInvalid(std::vector<MElement*> &invalids);
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

#endif
