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
  }

  _patch.resize(_nPatches);
  _intersection.resize(_nIntersections);

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

  InputFile >> _nFaces;
  for (int i=0;i<_nFaces;i++) {
    int faceTag, nEdges;
    InputFile >> faceTag;
    _face.push_back(new FM_Face(GetPatch(faceTag)));
    InputFile >> nEdges;
    for (int j=0;j<nEdges;j++) {
      int edgeTag;
      double SPx,SPy,SPz;
      double EPx,EPy,EPz;
      InputFile >> edgeTag;
      InputFile >> SPx >> SPy >> SPz;
      InputFile >> EPx >> EPy >> EPz;
      if (edgeTag < 0)
	_face[i]->AddEdge(new FM_Edge(0,
				      new FM_Vertex(SPx,SPy,SPz),
				      new FM_Vertex(EPx,EPy,EPz)));
      else
	_face[i]->AddEdge(new FM_Edge(GetIntersection(edgeTag),
				      new FM_Vertex(SPx,SPy,SPz),
				      new FM_Vertex(EPx,EPy,EPz)));
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
  for (int i=0;i<_intersection.size();i++)
    if (_intersection[i]->GetTag() == tag)
      return _intersection[i];
}
