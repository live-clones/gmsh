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
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include "MElement.h"
#include "MeshOptCommon.h"


namespace {


// Test intersection between sphere and segment
bool testSegSphereIntersect(SPoint3 A, SPoint3 B, const SPoint3& P, const double rr)
{
  // Test if separating plane between sphere and segment vertices
  // For each vertex, separation if vertex is outside sphere and P on opposite side
  // to other seg. vertex w.r.t plane of normal (vertex-P) through vertex
  const SVector3 PA(P, A), PB(P, B);
  const double aa = dot(PA, PA), ab = dot(PA, PB);
  if ((aa > rr) & (ab > aa)) return false;
  const double  bb = dot(PB, PB);
  if ((bb > rr) & (ab > bb)) return false;

  // Test if separating plane between sphere and line
  // For A, separation if projection Q of P on (AB) lies outside the sphere
  const SVector3 AB(A, B);
  const double d = ab - aa, e = dot(AB, AB);
  const SVector3 PQ = PA * e - d * AB;
  if (dot(PQ, PQ) > rr * e * e) return false;

  // Return true (intersection) if no separation at all
  return true;
}


// Test intersection between sphere and triangle
// Inspired by Christer Ericson, http://realtimecollisiondetection.net/blog/?p=103
bool testTriSphereIntersect(SPoint3 A, SPoint3 B, SPoint3 C, const SPoint3& P, const double rr)
{
  // Test if separating plane between sphere and triangle plane
  const SVector3 PA(P, A), AB(A, B), AC(A, C);
  const SVector3 V = crossprod(AB, AC);                               // Normal to triangle plane
  const double d = dot(PA, V);                                         // Dist. from P to triangle plane times norm of V
  const double e = dot(V, V);                                         // Norm of V
  if (d * d > rr * e) return false;                                   // Test if separating plane between sphere and triangle plane

  // Test if separating plane between sphere and triangle vertices
  const SVector3 PB(P, B), PC(P, B);
  const double aa = dot(PA, PA), ab = dot(PA, PB), ac = dot(PA, PC);
  const double bb = dot(PB, PB), bc = dot(PB, PC), cc = dot(PC, PC);
  if ((aa > rr) & (ab > aa) & (ac > aa)) return false;                    // For each triangle vertex, separation if vertex is outside sphere
  if ((bb > rr) & (ab > bb) & (bc > bb)) return false;                    // and P on opposite side to other two triangle vertices w.r.t
  if ((cc > rr) & (ac > cc) & (bc > cc)) return false;                    // plane of normal (vertex-P) through vertex

  // Test if separating plane between sphere and triangle edges
  const SVector3 BC(B, C);
  const double d1 = ab - aa, d2 = bc - bb, d3 = ac - cc;
  const double e1 = dot(AB, AB), e2 = dot(BC, BC), e3 = dot(AC, AC);
  const SVector3 PQ1 = PA * e1 - d1 * AB;                                 // Q1 projection of P on line (AB)
  const SVector3 PQ2 = PB * e2 - d2 * BC;                                 // Q2 projection of P on line (BC)
  const SVector3 PQ3 = PC * e3 + d3 * AC;                                 // Q3 projection of P on line (AC)
  const SVector3 PQC = PC * e1 - PQ1;
  const SVector3 PQA = PA * e2 - PQ2;
  const SVector3 PQB = PB * e3 - PQ3;
  if ((dot(PQ1, PQ1) > rr * e1 * e1) & (dot(PQ1, PQC) > 0)) return false; // For A, separation if Q lies outside the sphere and if P and C
  if ((dot(PQ2, PQ2) > rr * e2 * e2) & (dot(PQ2, PQA) > 0)) return false; // are on opposite sides of plane through AB with normal PQ
  if ((dot(PQ3, PQ3) > rr * e3 * e3) & (dot(PQ3, PQB) > 0)) return false; // Same for other two vertices

  // Return true (intersection) if no separation at all
  return true;
}


}


// Test of intersection element with circle/sphere
bool MeshOptPatchDef::testElInDist(const SPoint3 &P, double limDist,
                                   MElement *el) const
{
  const double limDistSq = limDist*limDist;

  if (el->getDim() == 2) {                                                // 2D?
    for (int iEd = 0; iEd < el->getNumEdges(); iEd++) {                   // Loop over edges of element
      std::vector<MVertex*> edgeVert;
      el->getEdgeVertices(iEd, edgeVert);
      const SPoint3 A = edgeVert[0]->point();
      const SPoint3 B = edgeVert[1]->point();
      if (testSegSphereIntersect(A, B, P, limDistSq)) return true;
    }
  }
  else {                                                                  // 3D
    for (int iFace = 0; iFace < el->getNumFaces(); iFace++) {             // Loop over faces of element
      std::vector<MVertex*> faceVert;
      el->getFaceVertices(iFace, faceVert);
      const SPoint3 A = faceVert[0]->point();
      const SPoint3 B = faceVert[1]->point();
      const SPoint3 C = faceVert[2]->point();
      if (faceVert.size() == 3)
        if (testTriSphereIntersect(A, B, C, P, limDistSq)) return true;
      else {
        const SPoint3 D = faceVert[3]->point();
        if (testTriSphereIntersect(A, B, C, P, limDistSq) ||
            testTriSphereIntersect(A, C, D, P, limDistSq)) return true;
      }
    }
  }

  return false;
}
