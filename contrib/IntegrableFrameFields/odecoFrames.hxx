// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <IffTools.hxx>
#include <gmsh.h>

namespace IFF{
  class Frame{
  public:
    Frame(){}
    ~Frame(){}

    virtual std::vector<std::vector<double>> getDirections() const = 0;
    virtual void projectOnCrossManifold(){std::cout << "Frame::projectOnCrossManifold not implemented" << std::endl; exit(0);}
    std::vector<double > m_frame;
  };
  
  class OdecoAniso2Dplanar : public Frame{
  public:
    
    static std::vector<std::vector<double>> getAlignmentLinConstr(const std::vector<double> &dir);
    static size_t nUnknown;
    
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

  class OdecoIso2Dplanar : public Frame{
  public:

    // This function is providing coefficients of linear combination which has to be constant to ensure alignement constraint
    static std::vector<std::vector<double>> getAlignmentLinConstr(const std::vector<double> &dir);
    static size_t nUnknown;
    
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
    
    virtual std::vector<std::vector<double>> getDirections(const std::vector<double> &refDir, const std::vector<double> &normal) const {
      double theta = atan2(m_frame[1], m_frame[0])/4.0;
      double norm = tools::norm(m_frame);
      
      std::vector<std::vector<double>> d;
      d.resize(2);
      d[0] = tools::rotateAlongDirection(normal, theta, refDir);
      d[1] = tools::rotateAlongDirection(normal, theta+M_PI/2.0, refDir);
      return d;
    }
  
  };
}
