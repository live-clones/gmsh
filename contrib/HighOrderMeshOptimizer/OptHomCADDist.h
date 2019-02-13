// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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

#ifndef OPTHOMCADDIST_H_
#define OPTHOMCADDIST_H_

class GradientBasis;
class GModel;
class MElement;
class MLine;
class MTriangle;
class GEdge;
class GFace;

double MFaceGFaceDistanceOld(MTriangle *t, GFace *gf,
                             std::vector<std::vector<SVector3> > *gsfT = 0,
                             std::map<MVertex *, SVector3> *normalsToCAD = 0);

double distToCAD1D(const GradientBasis *gb, const fullMatrix<double> &nodesXYZ,
                   const std::vector<SVector3> &tanCAD, double edLength);
double distToCAD2D(const GradientBasis *gb, const fullMatrix<double> &nodesXYZ,
                   const std::vector<SVector3> &normCAD);
double MLineGEdgeDistance(MLine *l, GEdge *ge);
double MFaceGFaceDistance(MElement *el, GFace *gf);

#endif /* OPTHOMCADDIST_H_ */
