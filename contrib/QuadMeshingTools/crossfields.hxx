#ifndef CFMB_CROSSFIELDS_H
#define CFMB_CROSSFIELDS_H

#include <vector>
#include "tools.hxx"
#include "mesh.hxx"
#include <cstddef>
#include <iostream>
#include <cmath>
#include "solver.hxx"

#include <Eigen/Dense>

namespace IFF{
  
  class Frame{
  public:
    Frame(){}
    ~Frame(){}

    virtual std::vector<std::vector<double>> getDirections() const = 0;
    virtual void projectOnCrossManifold(){std::cout << "Frame::projectOnCrossManifold not implemented" << std::endl; exit(0);}
    std::vector<double > m_frame;
  };

  class ThetaIso2D : public Frame{
  public:
    ThetaIso2D(const std::vector<double> &f){
      if(f.size()!=2){
	std::cout << "Wrong argument for ThetaIso2D instantiation" << std::endl;
	exit(0);
      }
      m_frame = f;
    }

    virtual std::vector<std::vector<double>> getDirections() const {
      double theta = atan2(m_frame[1], m_frame[0])/4.0;
      double norm = tools::norm(m_frame);
      std::vector<std::vector<double>> d;
      d.resize(2);
      d[0].resize(3, 0.0);
      d[1].resize(3, 0.0);
      d[0][0] = norm*cos(theta); d[0][1] = norm*sin(theta);
      d[1][0] = norm*cos(theta + M_PI/2.0); d[1][1] = norm*sin(theta + M_PI/2.0);
      return d;
    }
  
  };

  class OdecoIso2Dplanar : public Frame{
  public:

    static std::vector<std::vector<double>> getAlignmentLinConstr(const std::vector<double> &dir);
    static size_t nUnkown;
    
    OdecoIso2Dplanar(const std::vector<double> &f){
      if(f.size()!=3){
	std::cout << "Wrong argument for OdecoIso2D instantiation from frame" << std::endl;
	exit(0);
      }
      m_frame = f;
    }

    OdecoIso2Dplanar(const std::vector<std::vector<double>> &dir){
      if(dir.size()==1){
	double theta = atan2(dir[0][1], dir[0][0]);
	double norm = tools::norm(dir[0]);
	m_frame.resize(3, 0.0);
	m_frame[0] = norm*2*3*sqrt(2*M_PI)/8.0;
	m_frame[1] = norm*2*cos(4*theta)*sqrt(M_PI)/8.0;
	m_frame[2] = norm*2*sin(4*theta)*sqrt(M_PI)/8.0;
      }
      else if(dir.size()==2){
	if(fabs(tools::dotprod(dir[0], dir[1])) > 1e-12){
	  gmsh::logger::write("Invalid OdecoIso2Dplanar instantiation from directions. Directions are not orthogonal", "error");
	}
	double theta = atan2(dir[0][1], dir[0][0]);
	double norm = 0.5*(tools::norm(dir[0]) + tools::norm(dir[1]));
	m_frame.resize(3, 0.0);
	m_frame[0] = norm*2*3*sqrt(2*M_PI)/8.0;
	m_frame[1] = norm*2*cos(4*theta)*sqrt(M_PI)/8.0;
	m_frame[2] = norm*2*sin(4*theta)*sqrt(M_PI)/8.0;
      }
      else{
	std::cout << "Wrong argument for OdecoIso2D instantiation from directions" << std::endl;
	exit(0);
      }
    }

    virtual std::vector<std::vector<double>> getDirections() const { //WARNING: this is an approximation!!
      double theta = atan2(m_frame[2], m_frame[1])/4.0;
      std::vector<double> fProjUnit{2*3*sqrt(2*M_PI)/8.0, 2*cos(4*theta)*sqrt(M_PI)/8.0, 2*sin(4*theta)*sqrt(M_PI)/8.0};
      double norm = tools::dotprod(fProjUnit, m_frame)/tools::dotprod(fProjUnit, fProjUnit);
      std::vector<std::vector<double>> d;
      d.resize(2);
      d[0].resize(3, 0.0);
      d[1].resize(3, 0.0);
      d[0][0] = norm*cos(theta); d[0][1] = norm*sin(theta);
      d[1][0] = norm*cos(theta + M_PI/2.0); d[1][1] = norm*sin(theta + M_PI/2.0);
      return d;
    }

    virtual void projectOnCrossManifold(){
      std::vector<std::vector<double>> directions = getDirections();
      double theta = atan2(directions[0][1], directions[0][0]);
      double norm = tools::norm(directions[0]);
      if(norm > 1e-12){
	m_frame[0] = norm*2*3*sqrt(2*M_PI)/8.0;
	m_frame[1] = norm*2*cos(4*theta)*sqrt(M_PI)/8.0;
	m_frame[2] = norm*2*sin(4*theta)*sqrt(M_PI)/8.0;
      }
    }
  };

  class OdecoAniso2Dplanar : public Frame{
  public:
    
    static std::vector<std::vector<double>> getAlignmentLinConstr(const std::vector<double> &dir);
    static size_t nUnkown;
    
    OdecoAniso2Dplanar(const std::vector<double> &f){
      if(f.size()!=5){
	std::cout << "Wrong argument for OdecoAniso2D instantiation from frame" << std::endl;
	exit(0);
      }
      m_frame = f;
    }

    OdecoAniso2Dplanar(const std::vector<std::vector<double>> &dir){
      if(dir.size()==1){
	double theta = atan2(dir[0][1], dir[0][0]);
	double norm = tools::norm(dir[0]);
	m_frame.resize(5, 0.0);
	m_frame[0] = norm*2*3*sqrt(2*M_PI)/8.0;
	m_frame[1] = 0.0;
	m_frame[2] = 0.0;
	m_frame[3] = norm*2*cos(4*theta)*sqrt(M_PI)/8.0;
	m_frame[4] = norm*2*sin(4*theta)*sqrt(M_PI)/8.0;
      }
      else if(dir.size()==2){
	if(fabs(tools::dotprod(dir[0], dir[1])) > 1e-12){
	  gmsh::logger::write("Invalid OdecoIso2Dplanar instantiation from directions. Directions are not orthogonal", "error");
	}
	double theta = atan2(dir[0][1], dir[0][0]);
	double norm0 = tools::norm(dir[0]);
	double norm1 = tools::norm(dir[1]);
	m_frame.resize(5, 0.0);
	m_frame[0] = (norm0 + norm1)*3*sqrt(2*M_PI)/8.0;
	m_frame[1] = (norm0 - norm1)*cos(2*theta)*sqrt(M_PI)/2.0;
	m_frame[2] = (norm0 - norm1)*sin(2*theta)*sqrt(M_PI)/2.0;
	m_frame[3] = (norm0 + norm1)*cos(4*theta)*sqrt(M_PI)/8.0;
	m_frame[4] = (norm0 + norm1)*sin(4*theta)*sqrt(M_PI)/8.0;
      }
      else{
	std::cout << "Wrong argument for OdecoIso2D instantiation from directions" << std::endl;
	exit(0);
      }
    }

    virtual std::vector<std::vector<double>> getDirections() const { //WARNING: this is an approximation!!
      double theta = atan2(m_frame[4], m_frame[3])/4.0;
      std::vector<double> fIsoProjUnit{3*sqrt(2*M_PI)/8.0, cos(4*theta)*sqrt(M_PI)/8.0, sin(4*theta)*sqrt(M_PI)/8.0};
      std::vector<double> subFrameIso{m_frame[0], m_frame[3], m_frame[4]};
      double sumNorms = tools::dotprod(fIsoProjUnit, subFrameIso)/tools::dotprod(fIsoProjUnit, fIsoProjUnit);
      std::vector<double> fAnisoProjUnit{cos(2*theta)*sqrt(M_PI)/2.0, sin(2*theta)*sqrt(M_PI)/2.0};
      std::vector<double> subFrameAniso{m_frame[1], m_frame[2]};
      double diffNorms = tools::dotprod(fAnisoProjUnit, subFrameAniso)/tools::dotprod(fAnisoProjUnit, fAnisoProjUnit);
      double norm0 = 0.5*(sumNorms+diffNorms);
      double norm1 = 0.5*(sumNorms-diffNorms);
      std::vector<std::vector<double>> d;
      d.resize(2);
      d[0].resize(3, 0.0);
      d[1].resize(3, 0.0);
      d[0][0] = norm0*cos(theta); d[0][1] = norm0*sin(theta);
      d[1][0] = norm1*cos(theta + M_PI/2.0); d[1][1] = norm1*sin(theta + M_PI/2.0);
      return d;
    }

    virtual void projectOnCrossManifold(){ //WARNING: approximation
      std::vector<std::vector<double>> dir = getDirections();
      OdecoAniso2Dplanar projF(dir);
      m_frame = projF.m_frame;
    }
  };

  class Cross{
  public:
    Cross(){}
    ~Cross(){}

    virtual std::vector<double> getClosestDirection(const std::vector<double> &dir) const = 0;
    virtual std::vector<std::vector<double>> getDirections(){return m_directions;}
    std::vector<std::vector<double>> m_directions;
  };

  class Cross2D : public Cross{
  public:
    Cross2D(){}
    Cross2D(const Frame &f){m_directions = f.getDirections();}
    Cross2D(const std::vector<std::vector<double>> &dirs){m_directions = dirs;}
    ~Cross2D(){}

    virtual std::vector<double> getClosestDirection(const std::vector<double> &dir) const;

  };

  class CrossField2D{
  public:
    CrossField2D(Mesh *m, std::map<Vertex *, Cross2D> &cf): m_mesh(m), m_crossfield(cf){}
    ~CrossField2D(){}

    Mesh * m_mesh;
    std::map<Vertex*, Cross2D> m_crossfield;
    std::vector<Vertex *> m_singularities;
    std::vector<Triangle *> m_singularTriangles;
    std::vector<Vertex *> m_verticesSingularTriangles;
    std::map<Triangle* , std::vector<double>> m_potU;
    std::map<Triangle* , std::vector<double>> m_potV;

    double m_rangePotU[2];
    double m_rangePotV[2];

    std::vector<std::map<Triangle* , std::vector<double>>> getPotentials();
    std::vector<std::pair<std::vector<Vertex *>, int>> _getConstantPotBC(std::vector<std::map<Vertex*, std::vector<double>>> &crossLifting, Mesh &cm);
    void _addCGcompatibilityConditions(Solver &solver, Mesh &cm, std::vector<std::map<Vertex*, std::vector<double>>> &crossLifting);
    void _computePotentials();
    void _computePotentialsOld();
    void _detectSingularities();
    std::vector<std::map<Vertex*, std::vector<double>>> _getLifting(Mesh &cm);

  
  private:
  };

}
#endif
