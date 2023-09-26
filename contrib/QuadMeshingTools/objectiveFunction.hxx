#ifndef CFMB_OBJECTIVEFUNCTION_H
#define CFMB_OBJECTIVEFUNCTION_H

#include "mesh.hxx"
#include <vector>
#include "timer.hxx"

namespace IFF{
  
  class ObjectiveFunction{
  public:
  
    static std::vector<ObjectiveFunction*> allpFuncContainer;
    static void clearAll(){
      for(auto p: allpFuncContainer)
	delete p;
      allpFuncContainer.clear();
    }
  
    ObjectiveFunction(): m_useNodeData(false) {allpFuncContainer.push_back(this);}
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){std::cout << "OjectiveFunction::getFEMOperators not implemented" << std::endl; exit(0);}
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, void *data){std::cout << "OjectiveFunction::getFEMOperators not implemented" << std::endl; exit(0);}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){std::cout << "OjectiveFunction::evaluateFunction not implemented" << std::endl; exit(0);}
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){std::cout << "OjectiveFunction::getFEMGradient not implemented" << std::endl; exit(0);}
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){std::cout << "OjectiveFunction::getFEMHessianAndGradient not implemented" << std::endl; exit(0);}
    virtual double testEvaluate(){return 1.0;}

    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;


    bool m_useNodeData;
  
  protected:
    virtual ~ObjectiveFunction(){}
  };

  class DirichletEnergie : public ObjectiveFunction{
  public:
    DirichletEnergie(): ObjectiveFunction(), m_nFields(1){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss1", m_localIntegrationPoint, m_integrationWeights);
    }
    DirichletEnergie(size_t nFields): ObjectiveFunction(), m_nFields(nFields){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss1", m_localIntegrationPoint, m_integrationWeights);
    }
  
    virtual double testEvaluate(){return 1.0;}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri);
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs);
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
      GlobalTimer::tic("DIR_FUNC_GRADFEM");
      std::vector<std::vector<double>> localMat;
      getFEMOperators(triangle, localMat, localRhs);
      std::vector<double> solOrdered;
      solOrdered.resize(triangle->m_vertices.size() * m_nFields, 0.0);
      for(size_t k=0; k<triangle->m_vertices.size(); k++)
	for(size_t l=0; l<m_nFields; l++){
	  size_t locIndexKL = m_nFields*k + l;
	  solOrdered[locIndexKL] = solTri[k][l];
	}
      std::vector<double> KU;
      KU.resize(triangle->m_vertices.size() * m_nFields, 0.0);
      for(size_t k=0; k<localMat.size(); k++){
	for(size_t l=0; l<localMat[k].size(); l++){
	  KU[k] += localMat[k][l]*solOrdered[l];
	}
      }
      for(size_t l=0; l<localRhs.size(); l++)
	localRhs[l] = KU[l] - localRhs[l];
      GlobalTimer::toc();
    }
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
      GlobalTimer::tic("DIR_FUNC_GETFEMHESSIANANDGRADIENT");
      getFEMOperators(triangle, localMat, localRhs);
      std::vector<double> solOrdered;
      solOrdered.resize(triangle->m_vertices.size() * m_nFields, 0.0);
      for(size_t k=0; k<triangle->m_vertices.size(); k++)
	for(size_t l=0; l<m_nFields; l++){
	  size_t locIndexKL = m_nFields*k + l;
	  solOrdered[locIndexKL] = solTri[k][l];
	}
      std::vector<double> KU;
      KU.resize(triangle->m_vertices.size() * m_nFields, 0.0);
      for(size_t k=0; k<localMat.size(); k++){
	for(size_t l=0; l<localMat[k].size(); l++){
	  KU[k] += localMat[k][l]*solOrdered[l];
	}
      }
      for(size_t l=0; l<localRhs.size(); l++)
	localRhs[l] = KU[l] - localRhs[l];
      GlobalTimer::toc();
    }

    size_t m_nFields;
  
  protected:
    ~DirichletEnergie(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
  };

  class Potential : public ObjectiveFunction{
  public:
    Potential(): ObjectiveFunction(), m_nFields(1){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss1", m_localIntegrationPoint, m_integrationWeights);
      m_useNodeData = true;
    }
  
    virtual double testEvaluate(){return 1.0;}

    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, void *data);

    size_t m_nFields;
  
  protected:
    ~Potential(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
  };

  class DoublePotential : public ObjectiveFunction{
  public:
    DoublePotential(): ObjectiveFunction(), m_nFields(2){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss1", m_localIntegrationPoint, m_integrationWeights);
      m_useNodeData = true;
    }
  
    virtual double testEvaluate(){return 1.0;}

    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, void *data);

    size_t m_nFields;
  
  protected:
    ~DoublePotential(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
  };

  class GLconstraintPlanar : public ObjectiveFunction{
  public:
    GLconstraintPlanar() : ObjectiveFunction(), m_penalty(1.0){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
    }
    GLconstraintPlanar(double penalty) : ObjectiveFunction(), m_penalty(penalty){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
    }

    virtual double testEvaluate(){return 1.0*m_penalty;}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri);
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){}
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri);
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri);

    double m_penalty;
  
  protected:
    ~GLconstraintPlanar(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
  };

  class OdecoIso2DplanarConstraint : public ObjectiveFunction{
  public:
    OdecoIso2DplanarConstraint() : ObjectiveFunction(), m_penalty(1.0){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
    }
    OdecoIso2DplanarConstraint(double penalty) : ObjectiveFunction(), m_penalty(penalty){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
    }

    virtual double testEvaluate(){return 1.0*m_penalty;}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri);
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){}
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri);
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){}

    double m_penalty;
  
  protected:
    ~OdecoIso2DplanarConstraint(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
  };

  class OdecoAniso2DplanarConstraint : public ObjectiveFunction{
  public:
    OdecoAniso2DplanarConstraint() : ObjectiveFunction(), m_penalty(1.0){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
      m_weightsC.resize(3, 1.0);
      m_weightsC[1] = 10.0;
      m_weightsC[2] = 10.0;
    }
    OdecoAniso2DplanarConstraint(double penalty) : ObjectiveFunction(), m_penalty(penalty){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
      m_weightsC.resize(3, 1.0);
      m_weightsC[1] = 10.0;
      m_weightsC[2] = 10.0;
    }

    virtual double testEvaluate(){return 1.0*m_penalty;}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri);
    // virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){}
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri);
    // virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){}

    double m_penalty;
    
  protected:
    ~OdecoAniso2DplanarConstraint(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
    std::vector<double> m_weightsC;
  };

  class LBOdecoIso2Dplanar : public ObjectiveFunction{
  public:
    LBOdecoIso2Dplanar() : ObjectiveFunction(){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
      // std::cout << "npoints: " << m_integrationWeights.size() << std::endl;
      // exit(0);
    }
    LBOdecoIso2Dplanar(double penalty) : ObjectiveFunction(){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
    }

    virtual double testEvaluate(){return 1.0;}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri);
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){}
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri);
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){}

  protected:
    ~LBOdecoIso2Dplanar(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
  };
  
  class LBOdecoIso2DplanarUnnormalized : public ObjectiveFunction{
  public:
    LBOdecoIso2DplanarUnnormalized() : ObjectiveFunction(){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
      // std::cout << "npoints: " << m_integrationWeights.size() << std::endl;
      // exit(0);
    }
    LBOdecoIso2DplanarUnnormalized(double penalty) : ObjectiveFunction(){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
    }

    virtual double testEvaluate(){return 1.0;}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri);
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){}
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri);
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){}

  protected:
    ~LBOdecoIso2DplanarUnnormalized(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
  };
  
  class LBOdecoAniso2Dplanar : public ObjectiveFunction{
  public:
    LBOdecoAniso2Dplanar() : ObjectiveFunction(){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
      // std::cout << "npoints: " << m_integrationWeights.size() << std::endl;
      _create_C();
      // exit(0);
    }
    LBOdecoAniso2Dplanar(double penalty) : ObjectiveFunction(){
      gmsh::model::mesh::getIntegrationPoints(2, "Gauss2", m_localIntegrationPoint, m_integrationWeights);
      _create_C();
    }

    void _create_C();
    virtual double testEvaluate(){return 1.0;}
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri);
    virtual void getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){}
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri);
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){}

  protected:
    ~LBOdecoAniso2Dplanar(){}
  private:
    std::vector<double> m_localIntegrationPoint;
    std::vector<double> m_integrationWeights;
    std::vector<std::vector<std::vector<double>>> m_C0;
    std::vector<std::vector<std::vector<double>>> m_C1;
  };

  class SumObjectiveFunction : public ObjectiveFunction{
  public:
    SumObjectiveFunction(ObjectiveFunction *f1, ObjectiveFunction *f2): ObjectiveFunction(){
      m_f.push_back(f1);
      m_f.push_back(f2);
    }

    virtual double testEvaluate(){
      double v = 0.0;
      for(auto f: m_f)
	v += f->testEvaluate();
      return v;
    }
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
      valFunc = 0.0;
      for(auto f: m_f){
	double v=0.0;
	f->evaluateFunction(triangle, v, solTri);
	valFunc += v;
      }
    }
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
      m_f[0]->getFEMGradient(triangle, localRhs, solTri);
      for(size_t k=1; k<m_f.size(); k++){
	std::vector<double> rhs;
	m_f[k]->getFEMGradient(triangle, rhs, solTri);
	for(size_t l=0; l<localRhs.size(); l++){
	  localRhs[l] += rhs[l];
	}
      }
    }
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
      m_f[0]->getFEMHessianAndGradient(triangle, localMat, localRhs, solTri);
      for(size_t k=1; k<m_f.size(); k++){
	std::vector<std::vector<double>> mat;
	std::vector<double> rhs;
	m_f[k]->getFEMHessianAndGradient(triangle, mat, rhs, solTri);
	for(size_t l=0; l<localMat.size(); l++){
	  localRhs[l] += rhs[l];
	  for(size_t m=0; m<localMat[l].size(); m++)
	    localMat[l][m] += mat[l][m];
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

    virtual double testEvaluate(){
      return m_f->testEvaluate()*m_scaling;
    }
    virtual void evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
      m_f->evaluateFunction(triangle, valFunc, solTri);
      valFunc *= m_scaling;
    }
    virtual void getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
      m_f->getFEMGradient(triangle, localRhs, solTri);
      for(size_t l=0; l<localRhs.size(); l++){
	localRhs[l] *= m_scaling;
      }
    }
  
    virtual void getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
      m_f->getFEMHessianAndGradient(triangle, localMat, localRhs, solTri);
      for(size_t l=0; l<localMat.size(); l++){
	localRhs[l] *= m_scaling;
	for(size_t m=0; m<localMat[l].size(); m++)
	  localMat[l][m] *= m_scaling;
      }
    }
  
  private:
    ObjectiveFunction* m_f;
    double m_scaling;
  protected:
    ~ScaledObjectiveFunction(){}
  };

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
#endif
