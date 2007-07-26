#include <iostream>
#include <fstream>
#include "Message.h"
#include "FM_Reader.h"

FM_Reader::FM_Reader(const char* fn)
{
  char c;
  char continuation[16] = "continuation";
  char cylinder[16] = "cylinder";
  char revolvedParabola[32] = "revolvedParabola";
  std::ifstream InputFile(fn);
  if (!InputFile) {
    Msg::Info("Failed to open input file.");
    exit(EXIT_FAILURE);
  }
  InputFile >> _nPS;
  for (int i=0;i<_nPS;i++) {
    char projection[32];
    InputFile >> projection;
    double origin[3];
    InputFile >> origin[0] >> origin[1] >> origin[2];
    double normal[3];
    InputFile >> normal[0] >> normal[1] >> normal[2];
    double tangent[3];
    InputFile >> tangent[0] >> tangent[1] >> tangent[2];
    double scale[3];
    InputFile >> scale[0] >> scale[1] >> scale[2];
    if (!strcmp(projection,cylinder))
      _ps.push_back
	(new CylindricalProjectionSurface(i,origin,normal,tangent,scale));
    else if (!strcmp(projection,revolvedParabola)) {
      double R, K[2];
      InputFile >> R;
      InputFile >> K[0] >> K[1];
      _ps.push_back(new RevolvedParabolaProjectionSurface
		    (i,origin,normal,tangent,scale,R,K));
    }
    else {
      _ps.push_back
	(new CylindricalProjectionSurface(i,origin,normal,tangent,scale));
      Msg::Error("Unknown projection surface. Replaced by Cylinder...");
    }
  }

  InputFile >> _nPatches;

  for (int i=0;i<_nPatches;i++) {
    _patchList.push_back(new PatchInfo);
    InputFile >> _patchList[i]->type;
    InputFile >> _patchList[i]->projectionSurfaceTag;
    if (!strcmp(_patchList[i]->type,continuation)) {
      InputFile >> _patchList[i]->periodic[0] >> _patchList[i]->periodic[1];
      InputFile >> _patchList[i]->uMin >> _patchList[i]->uMax;
      InputFile >> _patchList[i]->vMin >> _patchList[i]->vMax;
      InputFile >> _patchList[i]->hardEdge[0] >> _patchList[i]->hardEdge[1] >>
	_patchList[i]->hardEdge[2] >> _patchList[i]->hardEdge[3];
      InputFile >> _patchList[i]->nM[0] >> _patchList[i]->nM[1];
      InputFile >> _patchList[i]->nModes[0] >> _patchList[i]->nModes[1];
      _patchList[i]->coeff.resize(_patchList[i]->nModes[0]);
      for (int j=0;j<_patchList[i]->nModes[0];j++) {
	_patchList[i]->coeff[j].resize(_patchList[i]->nModes[1]);
	for (int k=0;k<_patchList[i]->nModes[1];k++) {
	  double realCoeff, imagCoeff;
	  InputFile >> realCoeff >> imagCoeff;
	  _patchList[i]->coeff[j][k] = 
	    std::complex<double>(realCoeff,imagCoeff);
	}
      }
    }
  }

  InputFile >> _nIntersections;

  for (int i=0;i<_nIntersections;i++) {
    _intersectionList.push_back(new IntersectionInfo);
    InputFile >> _intersectionList[i]->tag;
    InputFile >> _intersectionList[i]->SP[0] >> _intersectionList[i]->SP[1] 
	      >> _intersectionList[i]->SP[2];
    InputFile >> _intersectionList[i]->EP[0] >> _intersectionList[i]->EP[1] 
	      >> _intersectionList[i]->EP[2];
    InputFile >> _intersectionList[i]->intersectingPatches[0].patchTag;
    InputFile >> _intersectionList[i]->intersectingPatches[1].patchTag;
    InputFile >> _intersectionList[i]->along;
    if ((_intersectionList[i]->intersectingPatches[0].patchTag < 0) ||
	(_intersectionList[i]->intersectingPatches[1].patchTag < 0))
      InputFile >> _intersectionList[i]->edgeInfo.edgeType >>
	_intersectionList[i]->edgeInfo.constValue >>
	_intersectionList[i]->edgeInfo.startValue >>
	_intersectionList[i]->edgeInfo.endValue >>
	_intersectionList[i]->edgeInfo.acrossDiscontinuity;
  }
  _overlapChart.resize(_nPatches);
  for (int i=0;i<_nPatches;i++) {
    _overlapChart[i].resize(_nPatches);
    for (int j=0;j<_nPatches;j++) {
      _overlapChart[i][j] = new OverlapInfo;
      InputFile >> _overlapChart[i][j]->doesIntersect >> 
	_overlapChart[i][j]->xMin >> _overlapChart[i][j]->xMax >>
	_overlapChart[i][j]->yMin >> _overlapChart[i][j]->yMax >>
	_overlapChart[i][j]->zMin >> _overlapChart[i][j]->zMax >>
	_overlapChart[i][j]->psTag;
    }
  }

  _intersection.resize(_nIntersections,0);

  for (int i=0;i<_nPatches;i++) {
    _patchList[i]->tag = i;
    PatchInfo* PI = _patchList[i];

    if (!strcmp(PI->type,continuation))
      _patch.push_back
	(new ContinuationPatch(PI,_ps[PI->projectionSurfaceTag],3));
    else
      _patch.push_back(new ExactPatch(PI,_ps[PI->projectionSurfaceTag]));
  }

  _blendOperator = new BlendOperator(_patch,_ps,_overlapChart);

  for (int i=0;i<_nPatches;i++)
    _blendedPatch.push_back(new BlendedPatch(_patch[i],_blendOperator));

  for (int i=0;i<_nIntersections;i++) {
    IntersectionInfo* II = _intersectionList[i];
    _intersection[II->tag] = new Curve(II,_patch);
  }

  InputFile >> _nVertices;
  for (int i=0;i<_nVertices;i++) {
    double x,y,z;
    InputFile >> x >> y >> z;
    _vertex.push_back(new FM_Vertex(i,x,y,z));
  }

  InputFile >> _nEdges;
  for (int i=0;i<_nEdges;i++) {
    int edgeTag, svTag, evTag;
    InputFile >> edgeTag >> svTag >> evTag;
    if (edgeTag < 0)
      _edge.push_back(new FM_Edge(i,0,_vertex[svTag],_vertex[evTag]));
    else
      _edge.push_back(new FM_Edge(i,GetIntersection(edgeTag),
				  _vertex[svTag],_vertex[evTag]));
  }

  InputFile >> _nFaces;
  for (int i=0;i<_nFaces;i++) {
    int faceTag, nEdges;
    InputFile >> faceTag;
    _face.push_back(new FM_Face(i,GetPatch(faceTag)));
    InputFile >> nEdges;
    for (int j=0;j<nEdges;j++) {
      int edgeTag;
      InputFile >> edgeTag;
      _face[i]->AddEdge(_edge[edgeTag]);
    }
  }
}

Patch* FM_Reader::GetPatch(int tag)
{
  for (int i=0;i<_patch.size();i++)
    if (_patch[i]->GetTag() == tag)
      return _patch[i];
}

Curve* FM_Reader::GetIntersection(int tag)
{
  Curve* curve = 0;
  for (int i=0;i<_intersection.size();i++) {
    if (_intersection[i]->GetTag() == tag) {
      curve = _intersection[i];
      break;
    }
  }
  return curve;
}

ProjectionSurface* FM_Reader::GetProjectionSurface(int tag)
{
  ProjectionSurface* ps = 0;
  for (int i=0;i<_ps.size();i++) {
    if (_ps[i]->GetTag() == tag) {
      ps = _ps[i];
      break;
    }
  }
  return ps;
}

BlendedPatch* FM_Reader::GetBlendedPatch(int tag)
{
  for (int i=0;i<_blendedPatch.size();i++)
    if (_blendedPatch[i]->GetTag() == tag)
      return _blendedPatch[i];
}
