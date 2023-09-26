#ifndef CFMB_INTEGRABLEFRAMEFIELD_H
#define CFMB_INTEGRABLEFRAMEFIELD_H

#include <gmsh.h>
#include "mesh.hxx"

namespace IFF{
  typedef std::map<size_t, std::vector<std::vector<double>>> mapVertTagCf;
  typedef std::map<Vertex *, std::vector<double>> mapVertDir;

  enum cftype {ISO, ANISO};
  
  class IntegrableFrameField{
  public:
    IntegrableFrameField(cftype cft = ISO){
      if(!gmsh::isInitialized())
	gmsh::initialize();
      m_m = new Mesh(true);
      m_sizesSet = false;
      m_bcSet = false;
      m_triSet = false;
      m_initSolExists = false;
      m_anistropic = false;
      m_gradPrec = 1e-10;
      m_funcPrec = 0.0;
      m_XPrec = 0.0;
      m_cftype = cft;
    }
    void clear(){
      m_sizesSet = false;
      m_bcSet = false;
      m_triSet = false;
      m_tri.clear();
      m_imposedSizes.clear();
      m_bc.clear();
      m_solution.clear();
      m_initSolExists = false;
      m_initDir.clear();
    }
    void setGradPrec(double prec){m_gradPrec = prec;};
    void setFuncPrec(double prec){m_funcPrec = prec;};
    void setXPrec(double prec){m_XPrec = prec;};
    void setTriangles(const std::vector<size_t> &triTags);
    void setBC(const std::vector<size_t> &vertTags, const std::vector<std::vector<std::vector<double>>> &imposedDir);
    void setSizes(const std::vector<size_t> &vertTags, const std::vector<double> &imposedSize);
    mapVertTagCf computeInitialCrossfield();
    mapVertTagCf computeIntegrableCrossfield();
    void setInitCrossField(const std::vector<size_t> &vertTags, const std::vector<std::vector<std::vector<double>>> &initDir);
    void setCftype(cftype type){m_cftype = type;}
    ~IntegrableFrameField();

  private:
    Mesh *m_m;
    bool m_sizesSet;
    bool m_bcSet;
    bool m_triSet;
    bool m_initSolExists;
    bool m_anistropic;
    double m_gradPrec;
    double m_funcPrec;
    double m_XPrec;
    cftype m_cftype;
    std::vector<Triangle *> m_tri;
    std::map<Vertex *, double> m_imposedSizes;
    mapVertDir m_bc;
    std::map<Vertex *, std::vector<std::vector<double>>> m_initDir;
    std::map<Vertex *, std::vector<double>> m_solution;
    
    void _computeLBOdeco2DisoCrossfield(std::map<Vertex *, std::vector<double>> &solution);
    void _computeLBOdeco2DanisoCrossfield(std::map<Vertex *, std::vector<double>> &solution);
    mapVertTagCf _computeInitialIsoCrossfield();
    mapVertTagCf _computeInitialAnisoCrossfield();
  };
  
}

#endif
