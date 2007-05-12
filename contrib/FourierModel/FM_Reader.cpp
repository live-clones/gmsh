#include <iostream>
#include <fstream>
#include "Message.h"
#include "FM_Reader.h"

FM_Reader::FM_Reader(const char* fn)
{
  char c;
  char continuation[16] = "continuation";
  std::ifstream InputFile(fn);
  if (!InputFile) {
    Msg::Info("Failed to open input file.");
    exit(EXIT_FAILURE);
  }
  InputFile >> _nPatches;
  InputFile >> _nIntersections;

  for (int i=0;i<_nPatches;i++) {
    _patchList.push_back(new PatchInfo);;
    InputFile >> _patchList[i]->tag;
    InputFile >> _patchList[i]->type;
    InputFile >> _patchList[i]->projection;
    InputFile >> _patchList[i]->normal[0] >> _patchList[i]->normal[1] >> 
      _patchList[i]->normal[2];
    InputFile >> _patchList[i]->origin[0] >> _patchList[i]->origin[1] >> 
      _patchList[i]->origin[2];
    InputFile >> _patchList[i]->tangent[0] >> _patchList[i]->tangent[1] >> 
      _patchList[i]->tangent[2];
    InputFile >> _patchList[i]->scale[0] >> _patchList[i]->scale[1];
    if (!strcmp(_patchList[i]->type,continuation)) {
      InputFile >> _patchList[i]->periodic[0] >> _patchList[i]->periodic[1];
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

  for (int i=0;i<_nIntersections;i++) {
    _intersectionList.push_back(new IntersectionInfo);
    InputFile >> _intersectionList[i]->tag;
    InputFile >> _intersectionList[i]->SP[0] >> _intersectionList[i]->SP[1] 
	      >> _intersectionList[i]->SP[2];
    InputFile >> _intersectionList[i]->EP[0] >> _intersectionList[i]->EP[1] 
	      >> _intersectionList[i]->EP[2];
    InputFile >> _intersectionList[i]->intersectingPatches[0].patchTag;
    InputFile >> _intersectionList[i]->intersectingPatches[1].patchTag;
    if ((_intersectionList[i]->intersectingPatches[0].patchTag < 0) ||
	(_intersectionList[i]->intersectingPatches[1].patchTag < 0))
      InputFile >> _intersectionList[i]->edgeNumber;
  }

  _patch.resize(_nPatches);
  _intersection.resize(_nIntersections,0);

  for (int i=0;i<_nPatches;i++) {
    PatchInfo* PI = _patchList[i];
    if (!strcmp(PI->type,continuation))
     _patch[PI->tag] = new ContinuationPatch(PI,2);
    else
      _patch[PI->tag] = new ExactPatch(PI);
  }
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
