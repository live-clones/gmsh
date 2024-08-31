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

    virtual std::vector<std::vector<double>> getDirections(){std::cout << "Frame::getDirections not implemented" << std::endl; exit(0); std::vector<std::vector<double>> d; return d;}
    virtual std::vector<std::vector<double>> getDirectionsFromRef(const std::vector<double> &refDir, const std::vector<double> &normal){std::cout << "Frame::getDirections(refDir, normal) not implemented" << std::endl; exit(0); std::vector<std::vector<double>> d; return d;}
    virtual double getTangentialLength(){std::cout << "Frame::getTangentialLength() not implemented" << std::endl; exit(0); double d=0; return d;}

    virtual void projectOnCrossManifold(){std::cout << "Frame::projectOnCrossManifold not implemented" << std::endl; exit(0);}
    std::vector<double > m_frame;
  };
  
  class OdecoAniso2D : public Frame{
  public:
    
    static std::vector<std::vector<double>> getAlignmentLinConstr(const std::vector<double> &dir);
    static std::vector<std::vector<double>> getAlignmentPlusTangentSizeLinConstr(const std::vector<double> &dir);
    static size_t nUnknown;
    static void getCRRotOperator(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp);
    static void getRotatedSol(const std::vector<double> &sol, std::vector<double> &solRotated, double alpha);
    static void getRotatedSolEl(Element *e, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &solRotated);
    static void getInvertRotatedGradient(Element *e, const std::vector<double> &localRhsRotated, std::vector<double> &localRhs);
    static void getInvertRotatedHessianAndGradient(Element *e, const std::vector<std::vector<double>> &localHessRotated, const std::vector<double> &localRhsRotated, std::vector<std::vector<double>> &localHess, std::vector<double> &localRhs);

    OdecoAniso2D(): Frame(){}
    OdecoAniso2D(const std::vector<double> &f){
      if(f.size()!=5){
	std::cout << "Wrong argument for OdecoAniso2D instantiation from frame" << std::endl;
	exit(0);
      }
      m_frame = f;
    }

    OdecoAniso2D(const std::vector<std::vector<double>> &dir){
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
      else if(dir.size()<=4 && dir.size()>0){
	if(fabs(tools::dotprod(dir[0], dir[1])) > 1e-12){
	  gmsh::logger::write("Invalid OdecoAniso2D instantiation from directions. Directions are not orthogonal", "error");
          exit(0);
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
	std::cout << "Wrong argument for OdecoAniso2D instantiation from directions" << std::endl;
	exit(0);
      }
    }

    virtual std::vector<std::vector<double>> getDirections() const { //WARNING: this is an approximation!!
      double theta = atan2(m_frame[4], m_frame[3])/4.0;
      std::vector<double> subFrameIso{m_frame[0], m_frame[3], m_frame[4]};
      std::vector<double> subFrameAniso{m_frame[1], m_frame[2]};
      if(tools::norm(subFrameAniso) > 1e-2)
        theta = atan2(subFrameAniso[1], subFrameAniso[0])/2.0;
      
      std::vector<double> fIsoProjUnit{3*sqrt(2*M_PI)/8.0, cos(4*theta)*sqrt(M_PI)/8.0, sin(4*theta)*sqrt(M_PI)/8.0};

      double sumNorms = tools::dotprod(fIsoProjUnit, subFrameIso)/tools::dotprod(fIsoProjUnit, fIsoProjUnit);
      std::vector<double> fAnisoProjUnit{cos(2*theta)*sqrt(M_PI)/2.0, sin(2*theta)*sqrt(M_PI)/2.0};

      double diffNorms = tools::dotprod(fAnisoProjUnit, subFrameAniso)/tools::dotprod(fAnisoProjUnit, fAnisoProjUnit);

      // double norm0 = 0.5*(sumNorms+diffNorms);
      // double norm1 = 0.5*(sumNorms-diffNorms);
      std::vector<double> norm{0.5*(sumNorms+diffNorms), 0.5*(sumNorms-diffNorms)};
      // std::vector<double> norm{1.0, 5.0};
      std::vector<std::vector<double>> d;
      d.resize(4);
      // d.resize(2);
      // d[0].resize(3, 0.0);
      // d[1].resize(3, 0.0);
      // d[0][0] = norm0*cos(theta); d[0][1] = norm0*sin(theta);
      // d[1][0] = norm1*cos(theta + M_PI/2.0); d[1][1] = norm1*sin(theta + M_PI/2.0);
      for(size_t k=0; k<4; k++){
        d[k].resize(3, 0.0);
        d[k][0] = norm[k%2]*cos(theta + k*M_PI/2.0); d[k][1] = norm[k%2]*sin(theta + k*M_PI/2.0);
      }
      return d;
    }

    virtual std::vector<std::vector<double>> getDirectionsFromRef(const std::vector<double> &refDir, const std::vector<double> &normal){
      std::vector<std::vector<double>> dLoc = getDirections();
      std::vector<double> refDirNorm = tools::getNormalizedVector(refDir);
      std::vector<double> nNorm = tools::getNormalizedVector(normal);
      std::vector<double> t = tools::crossprod(nNorm, refDirNorm);

      std::vector<std::vector<double>> d;
      d.resize(dLoc.size());
      for(auto &v: d)
        v.resize(refDir.size(), 0.0);
      for(size_t k=0; k<dLoc.size(); k++){
        for(size_t i=0; i<refDirNorm.size(); i++){
          d[k][i] = dLoc[k][0]*refDirNorm[i] + dLoc[k][1]*t[i];
        }
      }
      return d;
    }

    virtual double getLengthAlongDir(const std::vector<double> &dir){
      if(dir.size() != 2){
        throw std::invalid_argument("Wrong argument for OdecoAniso2D::getLengthAlongDir(const std::vector<double> &dir). dir size should be 2. For 3D directions, use OdecoAniso2D::getLengthAlongDir(const std::vector<double> &dir, const std::vector<double> &normal)");
      }
      else{
        double alpha = atan2(dir[1], dir[0]);
        std::vector<double> v1 = {3*sqrt(2*M_PI)/8.0, sqrt(M_PI)/2.0*cos(2*alpha), sqrt(M_PI)/2.0*sin(2*alpha), sqrt(M_PI)/8.0*cos(4*alpha), sqrt(M_PI)/8.0*sin(4*alpha)};
        std::vector<double> v2 = {3*sqrt(2*M_PI)/8.0, -sqrt(M_PI)/2.0*cos(2*alpha), -sqrt(M_PI)/2.0*sin(2*alpha), sqrt(M_PI)/8.0*cos(4*alpha), sqrt(M_PI)/8.0*sin(4*alpha)};
        return (tools::dotprod(m_frame, v1)*tools::norm2(v2)-tools::dotprod(m_frame, v2)*tools::dotprod(v1, v2))/(tools::norm2(v1)*tools::norm2(v2) - tools::dotprod(v1, v2)*tools::dotprod(v1, v2));
      }
    }

    virtual void projectOnCrossManifold(){ //WARNING: approximation
      std::vector<std::vector<double>> dir = getDirections();
      OdecoAniso2D projF(dir);
      m_frame = projF.m_frame;
    }
  };

  // ------------------------------- Odeco isotrope 2D frame representation
  class OdecoIso2D : public Frame{
  public:

    // This function is providing coefficients of linear combination which has to be constant to ensure alignement constraint
    static std::vector<std::vector<double>> getAlignmentLinConstr(const std::vector<double> &dir);
    static std::vector<std::vector<double>> getAlignmentPlusTangentSizeLinConstr(const std::vector<double> &dir);
    static std::vector<std::vector<double>> getSizeLinConstr(double sizeFrame);
    static size_t nUnknown;
    static void getCRRotOperator(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp);
    static void getCRRotOperatorWithDefinedRef(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp, int indLocEdgeRef);
    static void getRotatedSol(const std::vector<double> &sol, std::vector<double> &solRotated, double alpha);
    static void getRotatedSolEl(Element *e, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &solRotated);
    static void getInvertRotatedGradient(Element *e, const std::vector<double> &localRhsRotated, std::vector<double> &localRhs);
    static void getInvertRotatedHessianAndGradient(Element *e, const std::vector<std::vector<double>> &localHessRotated, const std::vector<double> &localRhsRotated, std::vector<std::vector<double>> &localHess, std::vector<double> &localRhs);

    OdecoIso2D(): Frame(){}
    OdecoIso2D(const std::vector<double> &f){
      if(f.size()!=3){
	std::cout << "Wrong argument for OdecoIso2D instantiation from frame" << std::endl;
	exit(0);
      }
      m_frame = f;
    }

    OdecoIso2D(const std::vector<std::vector<double>> &dir){
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
	  gmsh::logger::write("Invalid OdecoIso2D instantiation from directions. Directions are not orthogonal", "error");
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
      d.resize(4);
      // d[0].resize(3, 0.0);
      // d[1].resize(3, 0.0);
      // d[0][0] = norm*cos(theta); d[0][1] = norm*sin(theta);
      // d[1][0] = norm*cos(theta + M_PI/2.0); d[1][1] = norm*sin(theta + M_PI/2.0);
      for(size_t k=0; k<4; k++){
        d[k].resize(3, 0.0);
        d[k][0] = norm*cos(theta + k*M_PI/2.0); d[k][1] = norm*sin(theta + k*M_PI/2.0);
      }
      return d;
    }

    virtual std::vector<std::vector<double>> getDirectionsFromRef(const std::vector<double> &refDir, const std::vector<double> &normal){
      std::vector<std::vector<double>> dLoc = getDirections();
      std::vector<double> refDirNorm = tools::getNormalizedVector(refDir);
      std::vector<double> nNorm = tools::getNormalizedVector(normal);
      std::vector<double> t = tools::crossprod(nNorm, refDirNorm);

      std::vector<std::vector<double>> d;
      d.resize(dLoc.size());
      for(auto &v: d)
        v.resize(refDir.size(), 0.0);
      for(size_t k=0; k<dLoc.size(); k++){
        for(size_t i=0; i<refDirNorm.size(); i++){
          d[k][i] = dLoc[k][0]*refDirNorm[i] + dLoc[k][1]*t[i];
        }
      }
      return d;
    }

    virtual double getLengthAlongDir(const std::vector<double> &dir){
      if(dir.size() != 2){
        throw std::invalid_argument("Wrong argument for OdecoAniso2D::getLengthAlongDir(const std::vector<double> &dir). dir size should be 2. For 3D directions, use OdecoAniso2D::getLengthAlongDir(const std::vector<double> &dir, const std::vector<double> &normal)");
      }
      else{
        double alpha = atan2(dir[1], dir[0]);
        std::vector<double> v1 = {3*sqrt(2*M_PI)/4.0, sqrt(M_PI)/4.0*cos(4*alpha), sqrt(M_PI)/4.0*sin(4*alpha)};
        return tools::dotprod(m_frame, v1)/tools::norm2(v1);
      }
    }
    
    virtual void projectOnCrossManifold(){
      std::vector<std::vector<double>> directions = getDirections();
      double theta = atan2(directions[0][1], directions[0][0]);
      double norm = tools::norm(directions[0]);
      // if(norm > 1e-12){
      m_frame[0] = norm*2*3*sqrt(2*M_PI)/8.0;
      m_frame[1] = norm*2*cos(4*theta)*sqrt(M_PI)/8.0;
      m_frame[2] = norm*2*sin(4*theta)*sqrt(M_PI)/8.0;
      // }
    }
  };

  // ------------------------------- Classic 2D frame representation (cos(4*theta), sin(4*theta))
  class GLIso2D : public Frame{
  public:
    static size_t nUnknown;
    static void getCRRotOperator(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp);
    static void getRotatedSolEl(Element *e, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &solRotated);
    static void getInvertRotatedGradient(Element *e, const std::vector<double> &localRhsRotated, std::vector<double> &localRhs);

    GLIso2D(): Frame(){}
    GLIso2D(const std::vector<double> &f): Frame(){
      if(f.size()!=2){
	std::cout << "Wrong argument for GLIso2D instantiation" << std::endl;
	exit(0);
      }
      m_frame = f;
    }
    GLIso2D(const std::vector<std::vector<double>> &dir){
      if(dir.size()==1){
	double theta = atan2(dir[0][1], dir[0][0]);
	m_frame.resize(2, 0.0);
	m_frame[0] = cos(4*theta);
	m_frame[1] = sin(4*theta);
      }
      else if(dir.size()==2){
	if(fabs(tools::dotprod(dir[0], dir[1])) > 1e-12){
	  gmsh::logger::write("Invalid OdecoIso2D instantiation from directions. Directions are not orthogonal", "error");
	}
	double theta = atan2(dir[0][1], dir[0][0]);
	m_frame.resize(2, 0.0);
	m_frame[0] = cos(4*theta);
	m_frame[1] = sin(4*theta);
      }
      else{
	std::cout << "Wrong argument for OdecoIso2D instantiation from directions" << std::endl;
	exit(0);
      }
    }
    
    virtual std::vector<std::vector<double>> getDirections() const {
      double theta = atan2(m_frame[1], m_frame[0])/4.0;
      double norm = tools::norm(m_frame);
      std::vector<std::vector<double>> d;
      d.resize(4);
      // d[0].resize(3, 0.0);
      // d[1].resize(3, 0.0);
      // d[0][0] = norm*cos(theta); d[0][1] = norm*sin(theta);
      // d[1][0] = norm*cos(theta + M_PI/2.0); d[1][1] = norm*sin(theta + M_PI/2.0);
      for(size_t k=0; k<4; k++){
        d[k].resize(3, 0.0);
        d[k][0] = norm*cos(theta + k*M_PI/2.0); d[k][1] = norm*sin(theta + k*M_PI/2.0);
      }
      return d;
    }

    virtual std::vector<std::vector<double>> getDirectionsFromRef(const std::vector<double> &refDir, const std::vector<double> &normal){
      std::vector<std::vector<double>> dLoc = getDirections();
      std::vector<double> refDirNorm = tools::getNormalizedVector(refDir);
      std::vector<double> nNorm = tools::getNormalizedVector(normal);
      std::vector<double> t = tools::crossprod(nNorm, refDirNorm);

      std::vector<std::vector<double>> d;
      d.resize(dLoc.size());
      for(auto &v: d)
        v.resize(refDir.size(), 0.0);
      for(size_t k=0; k<dLoc.size(); k++){
        for(size_t i=0; i<refDirNorm.size(); i++){
          d[k][i] = dLoc[k][0]*refDirNorm[i] + dLoc[k][1]*t[i];
        }
      }
      return d;
    }

    virtual void projectOnCrossManifold(){
      std::vector<std::vector<double>> directions = getDirections();
      double theta = atan2(directions[0][1], directions[0][0]);
      double norm = tools::norm(directions[0]);
      // if(norm > 1e-12){
      m_frame[0] = norm*cos(4*theta);
      m_frame[1] = norm*sin(4*theta);
      // }
    }
  };
}
