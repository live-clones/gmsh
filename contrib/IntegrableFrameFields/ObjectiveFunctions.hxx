// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#pragma once

#include <IffTools.hxx>
#include <vector>

namespace IFF{
  class ObjectiveFunction{
    static std::vector<ObjectiveFunction*> objectiveFunctionsCollector;
  public:
    static void clearAll(){
      for(auto p: objectiveFunctionsCollector)
	delete p;
      objectiveFunctionsCollector.clear();
    }
    // constructor to be call in each child class.
    ObjectiveFunction(): m_useNodeData(false){objectiveFunctionsCollector.push_back(this);}

    // Methods to be defined for LBFGS solver
    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){std::cout << "OjectiveFunction::evaluateFunction not implemented" << std::endl; exit(0);}
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){std::cout << "OjectiveFunction::getGradient not implemented" << std::endl; exit(0);};
    // Methods to be defined for Newton solver
    virtual void getHessianAndGradient(Element *element, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){std::cout << "OjectiveFunction::getFEMHessianAndGradient not implemented" << std::endl; exit(0);}
    // Tools for new objective functions implementation check
    void checkGradient(Element *element, const std::vector<std::vector<double>> &solTri);


    // Set to true for objective functions needing extra data other than solution
    bool m_useNodeData;
  
  protected:
    // Forbid instanciation
    virtual ~ObjectiveFunction(){}
  };

  // ------------------------------- Dirichlet energy for CR GL framefield objective function
  class DirichletEnergieVectCR : public ObjectiveFunction{
  public:
    DirichletEnergieVectCR(int nFields, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &), void (*invertRotatedHessianAndGradient)(Element *, const std::vector<std::vector<double>> &, const std::vector<double> &, std::vector<std::vector<double>> &, std::vector<double> &)=NULL): ObjectiveFunction(), m_nFields(nFields), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient), _getInvertRotatedHessianAndGradient(invertRotatedHessianAndGradient){}
  
    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);
    virtual void getHessianAndGradient(Element *element, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &localHess, std::vector<double> &localRhs);
    
  protected:
    ~DirichletEnergieVectCR(){}

  private:
    void _getRotatedFEMOperators(Element *element, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs);
    size_t m_nFields;
    
    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTriRotated, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
    void (*_getInvertRotatedHessianAndGradient)(Element *, const std::vector<std::vector<double>> &, const std::vector<double> &, std::vector<std::vector<double>> &, std::vector<double> &);
  };

  // ------------------------------- Dirichlet energy for CR GL framefield objective function
  class DirichletEnergieVectCRIsoMormalized : public ObjectiveFunction{
  public:
    DirichletEnergieVectCRIsoMormalized(int nFields, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)): ObjectiveFunction(), m_nFields(nFields), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){}
  
    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);
    
  protected:
    ~DirichletEnergieVectCRIsoMormalized(){}

  private:
    size_t m_nFields;
    
    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTriRotated, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };

  // ------------------------------- Odeco isotrope 2D framefield constraint
  class OdecoIso2DConstraint : public ObjectiveFunction{
  public:
    OdecoIso2DConstraint(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(3), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoIso2DConstraint(){}
  private:
    size_t m_nFields;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized
  class OdecoIso2DConstraintNormalized : public ObjectiveFunction{
  public:
    OdecoIso2DConstraintNormalized(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(3), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoIso2DConstraintNormalized(){}
  private:
    size_t m_nFields;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized no area
  class OdecoIso2DConstraintNormalizedNoArea : public ObjectiveFunction{
  public:
    OdecoIso2DConstraintNormalizedNoArea(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(3), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoIso2DConstraintNormalizedNoArea(){}
  private:
    size_t m_nFields;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized with log smooth wieght
  class OdecoIso2DConstraintNormalizedWithLogSmoothWeight : public ObjectiveFunction{
  public:
    OdecoIso2DConstraintNormalizedWithLogSmoothWeight(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(3), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoIso2DConstraintNormalizedWithLogSmoothWeight(){}
  private:
    size_t m_nFields;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized with smooth wieght
  class OdecoIso2DConstraintNormalizedWithSmoothWeight : public ObjectiveFunction{
  public:
    OdecoIso2DConstraintNormalizedWithSmoothWeight(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(3), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoIso2DConstraintNormalizedWithSmoothWeight(){}
  private:
    size_t m_nFields;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized at edges
  class OdecoIso2DConstraintNormalizedEdge : public ObjectiveFunction{
  public:
    OdecoIso2DConstraintNormalizedEdge(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(3), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoIso2DConstraintNormalizedEdge(){}
  private:
    size_t m_nFields;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };
  
  // ------------------------------- Odeco anisotrope 2D framefield constraint
  class OdecoAniso2DConstraint : public ObjectiveFunction{
  public:
    OdecoAniso2DConstraint(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(5), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      m_weightsC.resize(3, 1.0);
      m_weightsC[1] = 10.0;
      m_weightsC[2] = 10.0;
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoAniso2DConstraint(){}
  private:
    size_t m_nFields;
    std::vector<double> m_weightsC;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };

  // ------------------------------- Odeco anisotrope 2D framefield constraint
  class OdecoAniso2DConstraintNormalized : public ObjectiveFunction{
  public:
    OdecoAniso2DConstraintNormalized(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(5), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      m_weightsC.resize(3, 1.0);
      m_weightsC[1] = 10.0;
      m_weightsC[2] = 10.0;
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  
  protected:
    ~OdecoAniso2DConstraintNormalized(){}
  private:
    size_t m_nFields;
    std::vector<double> m_weightsC;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };
  
  // ------------------------------- Integrability objective function for Odeco isotrope 2D framefield representation
  class LBOdecoIso2D : public ObjectiveFunction{
  public:
    LBOdecoIso2D(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(3), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  protected:
    ~LBOdecoIso2D(){}
  private:
    size_t m_nFields;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };
  
  // ------------------------------- Integrability objective function for Odeco anisotrope 2D framefield representation
  class LBOdecoAniso2D : public ObjectiveFunction{
  public:
    LBOdecoAniso2D(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)) : ObjectiveFunction(), m_penalty(penalty), m_nFields(5), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){
      _create_C();
    }

    void _create_C();

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    double m_penalty;
  protected:
    ~LBOdecoAniso2D(){}
  private:
    size_t m_nFields;
    std::vector<std::vector<std::vector<double>>> m_C0;
    std::vector<std::vector<std::vector<double>>> m_C1;
    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };
  
  // ------------------------------- GL framefield constraint
  class GLframeConstraint : public ObjectiveFunction{
  public:
    GLframeConstraint(double penalty, void (*rotSolElFunc)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &), void (*invertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &)): ObjectiveFunction(), m_nFields(2), m_penalty(penalty), _getRotatedSolEl(rotSolElFunc), _getInvertRotatedGradient(invertRotatedGradient){}
  
    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc);
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);
    
  protected:
    ~GLframeConstraint(){}

  private:
    size_t m_nFields;
    double m_penalty;

    void _getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs);

    void (*_getRotatedSolEl)(Element*, const std::vector<std::vector<double>> &, std::vector<std::vector<double>> &);
    void (*_getInvertRotatedGradient)(Element *, const std::vector<double> &, std::vector<double> &);
  };
  
  // ------------------------------- classes for objective functions linear combinations
  class SumObjectiveFunction : public ObjectiveFunction{
  public:
    SumObjectiveFunction(ObjectiveFunction *f1, ObjectiveFunction *f2): ObjectiveFunction(){
      m_f.push_back(f1);
      m_f.push_back(f2);
    }

    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solElem, double &valFunc){
      std::vector<double> valFuncs;
      valFunc = 0;
      for(auto f: m_f){
        double val=0.0;
        f->evaluateFunction(element, solElem, val);
        valFunc += val;
      }
    }
    
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
      m_f[0]->getGradient(element, solTri, localRhs);
      for(size_t k=1; k<m_f.size(); k++){
	std::vector<double> rhs;
	m_f[k]->getGradient(element, solTri, rhs);
	for(size_t l=0; l<localRhs.size(); l++){
	  localRhs[l] += rhs[l];
	}
      }
    }

  private:
    std::vector<ObjectiveFunction*> m_f;
  protected:
    ~SumObjectiveFunction(){}
  };

  class ScaledObjectiveFunction : public ObjectiveFunction{
  public:
    ScaledObjectiveFunction(ObjectiveFunction *f1, double s): ObjectiveFunction(), m_f(f1), m_scaling(s){}
    
    virtual void evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
      m_f->evaluateFunction(element, solTri, valFunc);
      valFunc *= m_scaling;
    }
    
    virtual void getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
      m_f->getGradient(element, solTri, localRhs);
      for(size_t l=0; l<localRhs.size(); l++){
	localRhs[l] *= m_scaling;
      }
    }
  
  private:
    ObjectiveFunction* m_f;
    double m_scaling;
  protected:
    ~ScaledObjectiveFunction(){}
  };
  
  // ------------------------------- Operator overloads objective functions linear combinations
  inline SumObjectiveFunction* operator+(ObjectiveFunction &f1, ObjectiveFunction &f2)
  {
    SumObjectiveFunction *f = new SumObjectiveFunction(&f1, &f2);
    return f;
  }

  inline ScaledObjectiveFunction* operator*(ObjectiveFunction &f1, double s)
  {
    ScaledObjectiveFunction *f = new ScaledObjectiveFunction(&f1, s);
    return f;
  }

  inline ScaledObjectiveFunction* operator*(double s, ObjectiveFunction &f1)
  {
    ScaledObjectiveFunction *f = new ScaledObjectiveFunction(&f1, s);
    return f;
  }
}
