// Copyright (C) 2013 ULg-UCL
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
// Please report all bugs and problems to the public mailing list
// <gmsh@geuz.org>.
//
// Contributor: Thomas Toulorge

#include <iostream>
#include <sstream>
#include "GEdge.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "SuperEl.h"



SuperEl::SuperEl(int order, double dist, int type, const std::vector<MVertex*> &baseVert,
                 const std::vector<SVector3> &normals) {

//  std::cout << "DBGTT: badEl = " << badEl->getNum() << ", _superEl = " << _superEl << std::endl;

  switch (type) {
    case TYPE_LIN:
      createSuperElQuad(order, dist, baseVert, normals[0], normals[1]);
      break;
    case TYPE_TRI:
      createSuperElPrism(order, dist, baseVert, normals[0], normals[1], normals[2]);
      break;
    case TYPE_QUA:
      createSuperElHex(order, dist, baseVert, normals[0], normals[1], normals[2], normals[3]);
      break;
    default:
      std::cout << "ERROR: SuperEl not implemented for element of type " << type << std::endl;
      _superEl = 0;
      break;
  }

  if (!_superEl) std::cout << "ERROR: SuperEl not created" << std::endl;

}



void SuperEl::createSuperElQuad(int order, double dist, const std::vector<MVertex*> &baseVert,
                                  const SVector3 &n0, const SVector3 &n1) {


  if (baseVert.empty()) {
    std::cout << "ERROR: Base edge not given for SuperEl\n";
    _superEl = 0;
    return;
  }

  // First-order vertices for super-element
  MVertex *v0 = new MVertex(*baseVert[0]);
  MVertex *v1 = new MVertex(*baseVert[1]);
//  double dist = distFactor*distMaxStraight(badEl);
  double v2x = v1->x()+n1.x()*dist, v2y = v1->y()+n1.y()*dist;
  MVertex *v2 = new MVertex(v2x,v2y,0.);
  double v3x = v0->x()+n0.x()*dist, v3y = v0->y()+n0.y()*dist;
  MVertex *v3 = new MVertex(v3x,v3y,0.);
//  std::cout << "DBGTT: createSuperElQuad: v0 = (" << v0->x() << "," << v0->y()
//              << "), v1 = (" << v1->x() << "," << v1->y()
//              << "), v2 = (" << v2->x() << "," << v2->y()
//              << "), v3 = (" << v3->x() << "," << v3->y() << ")" << std::endl;

  // Get basis functions
  MQuadrangle quad1(v0,v1,v2,v3);
  const nodalBasis *quadBasis = quad1.getFunctionSpace(order,true);           // Get HO serendip nodal basis
  const int Nv = quadBasis->getNumShapeFunctions();

  // Store/create all vertices for super-element
  _superVert.resize(Nv);
  _superVert[0] = v0;                                                         // First-order vertices
  _superVert[1] = v1;
  _superVert[2] = v2;
  _superVert[3] = v3;
  for (int i=2; i<order+1; ++i) _superVert[2+i] = new MVertex(*baseVert[i]);  // HO vertices on base edge
  for (int i=3+order; i<Nv; ++i) {                                            // Additional HO vertices
    SPoint3 p;
    quad1.pnt(quadBasis->points(i,0),quadBasis->points(i,1),0.,p);
    _superVert[i] = new MVertex(p.x(),p.y(),0.);
//    std::cout << "DBGTT: createSuperElQuad: add vertex (" << _superVert[i]->x()
//                << "," << _superVert[i]->y()<< "," << _superVert[i]->z() << ")" << std::endl;
  }

  _superEl = new MQuadrangleN(_superVert,order);
  _superEl0 = new MQuadrangle(_superVert[0],_superVert[1],_superVert[2],_superVert[3]);
//  std::cout << "Created SuperEl at address " << _superEl << std::endl;

}



void SuperEl::createSuperElPrism(int order, double dist, const std::vector<MVertex*> &baseVert,
                                 const SVector3 &n0, const SVector3 &n1, const SVector3 &n2) {


  if (baseVert.empty()) {
    std::cout << "ERROR: Base edge not given for SuperEl\n";
    _superEl = 0;
    return;
  }

  // First-order vertices for super-element
  MVertex *v0 = new MVertex(*baseVert[0]);
  MVertex *v1 = new MVertex(*baseVert[1]);
  MVertex *v2 = new MVertex(*baseVert[2]);
  double v3x = v0->x()+n0.x()*dist, v3y = v0->y()+n0.y()*dist,  v3z = v0->z()+n0.z()*dist;
  MVertex *v3 = new MVertex(v3x,v3y,v3z);
  double v4x = v1->x()+n1.x()*dist, v4y = v1->y()+n1.y()*dist,  v4z = v1->z()+n1.z()*dist;
  MVertex *v4 = new MVertex(v4x,v4y,v4z);
  double v5x = v2->x()+n2.x()*dist, v5y = v2->y()+n2.y()*dist,  v5z = v2->z()+n2.z()*dist;
  MVertex *v5 = new MVertex(v5x,v5y,v5z);

  // Get basis functions
  MPrism prism1(v0,v1,v2,v3,v4,v5);
  const nodalBasis *prismBasis = prism1.getFunctionSpace(order,true);       // Get HO serendip nodal basis
  const int Nv = prismBasis->getNumShapeFunctions();                        // Number of vertices in HO prism

  // Store/create all vertices for super-element
  if (order == 2) {
    _superVert.resize(18);
    _superVert[0] = v0;                                                     // First-order vertices
    _superVert[1] = v1;
    _superVert[2] = v2;
    _superVert[3] = v3;
    _superVert[4] = v4;
    _superVert[5] = v5;
    _superVert[6] = new MVertex(*baseVert[3]);                              // HO vertices on base face
    _superVert[9] = new MVertex(*baseVert[4]);
    _superVert[7] = new MVertex(*baseVert[5]);
    const int indAddVerts[6] = {8,10,11,12,13,14};                          // Additional HO vertices
    SPoint3 p;
    for (int i=0; i<6; ++i) {
      const int &ind = indAddVerts[i];
      prism1.pnt(prismBasis->points(ind,0),prismBasis->points(ind,1),prismBasis->points(ind,2),p);
      _superVert[ind] = new MVertex(p.x(),p.y(),p.z());
    }
    _superEl = new MPrism15(_superVert);
  }
  else {
    std::cout << "ERROR: Prismatic superEl. of order " << order << " not supported\n";
    _superEl = 0;
    _superEl0 = 0;
    return;
  }

  _superEl0 = new MPrism(_superVert[0],_superVert[1],_superVert[2],
                         _superVert[3],_superVert[4],_superVert[5]);

}



void SuperEl::createSuperElHex(int order, double dist, const std::vector<MVertex*> &baseVert,
                               const SVector3 &n0, const SVector3 &n1, const SVector3 &n2, const SVector3 &n3) {


  if (baseVert.empty()) {
    std::cout << "ERROR: Base edge not given for SuperEl\n";
    _superEl = 0;
    return;
  }

  // First-order vertices for super-element
  MVertex *v0 = new MVertex(*baseVert[0]);
  MVertex *v1 = new MVertex(*baseVert[1]);
  MVertex *v2 = new MVertex(*baseVert[2]);
  MVertex *v3 = new MVertex(*baseVert[3]);
  double v4x = v0->x()+n0.x()*dist, v4y = v0->y()+n0.y()*dist,  v4z = v0->z()+n0.z()*dist;
  MVertex *v4 = new MVertex(v4x,v4y,v4z);
  double v5x = v1->x()+n1.x()*dist, v5y = v1->y()+n1.y()*dist,  v5z = v1->z()+n1.z()*dist;
  MVertex *v5 = new MVertex(v5x,v5y,v5z);
  double v6x = v2->x()+n2.x()*dist, v6y = v2->y()+n2.y()*dist,  v6z = v2->z()+n2.z()*dist;
  MVertex *v6 = new MVertex(v6x,v6y,v6z);
  double v7x = v3->x()+n3.x()*dist, v7y = v3->y()+n3.y()*dist,  v7z = v3->z()+n3.z()*dist;
  MVertex *v7 = new MVertex(v7x,v7y,v7z);

  // Get basis functions
  MHexahedron *hex1 = new MHexahedron(v0,v1,v2,v3,v4,v5,v6,v7);
  const nodalBasis *prismBasis = hex1->getFunctionSpace(order,true);         // Get HO serendip nodal basis
  const int Nv = prismBasis->getNumShapeFunctions();                         // Number of vertices in HO hex

  // Store/create all vertices for super-element
  if (order == 2) {
    _superVert.resize(27);
    _superVert[0] = v0;                                                      // First-order vertices
    _superVert[1] = v1;
    _superVert[2] = v2;
    _superVert[3] = v3;
    _superVert[4] = v4;
    _superVert[5] = v5;
    _superVert[6] = v6;
    _superVert[7] = v7;
    _superVert[8] = new MVertex(*baseVert[4]);                                // HO vertices on base face
    _superVert[11] = new MVertex(*baseVert[5]);                               // HO vertices on base face
    _superVert[13] = new MVertex(*baseVert[6]);                               // HO vertices on base face
    _superVert[9] = new MVertex(*baseVert[7]);
    _superVert[20] = new MVertex(*baseVert[8]);
    const int indAddVerts[8] = {10,12,14,15,16,17,18,19};                     // Additional HO vertices
    SPoint3 p;
    for (int i=0; i<8; ++i) {
      const int &ind = indAddVerts[i];
      hex1->pnt(prismBasis->points(ind,0),prismBasis->points(ind,1),prismBasis->points(ind,2),p);
      _superVert[ind] = new MVertex(p.x(),p.y(),p.z());
    }
    _superEl = new MHexahedron20(_superVert);
  }
  else {
    std::cout << "ERROR: Hex. superEl. of order " << order << " not supported\n";
    _superEl = 0;
    _superEl0 = 0;
    return;
  }

  _superEl0 = hex1;

}



bool SuperEl::isPointIn(const SPoint3 p) const {

  double xyz[3] = {p.x(), p.y(), p.z()}, uvw[3];
  _superEl0->xyz2uvw(xyz,uvw);
  return _superEl0->isInside(uvw[0],uvw[1],uvw[2]);

}



bool SuperEl::straightToCurved(double *xyzS, double *xyzC) const {

  double uvw[3];
  _superEl0->xyz2uvw(xyzS,uvw);
  if (!_superEl0->isInside(uvw[0],uvw[1],uvw[2])) return false;

  SPoint3 pC;
  _superEl->pnt(uvw[0],uvw[1],uvw[2],pC);
  xyzC[0] = pC[0];
  xyzC[1] = pC[1];
  xyzC[2] = pC[2];

  return true;

}



std::string SuperEl::printPOS() {

  std::vector<MVertex*> verts;
  _superEl0->getVertices(verts);
  std::string posStr(_superEl0->getStringForPOS());
  int n = _superEl0->getNumVertices();

  std::ostringstream oss;

  oss << posStr << "(";
  for(int i = 0; i < n; i++){
    if(i) oss << ",";
    oss << _superVert[i]->x() << "," <<  _superVert[i]->y() << "," <<  _superVert[i]->z();
  }
  oss << "){0";
  for(int i = 0; i < n; i++) oss << ",0.";
  oss << "};\n";

  return oss.str();

}
