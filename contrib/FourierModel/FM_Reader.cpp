#include <iostream>
#include <fstream>
#include "Message.h"
#include "FM_Reader.h"

FM_Reader::FM_Reader(const char* fn)
{
  char c;
  char Exact[8] = "Exact";
  char cylinder[16] = "cylinder";
  char revolvedParabola[32] = "revolvedParabola";

  std::ifstream InputFile(fn);
  if (!InputFile) {
    Msg::Info("Failed to open input file.");
    exit(EXIT_FAILURE);
  }
  //InputFile >> _nPatches;
  //for (unsigned int i = 0; i < _nPatches; i++) {
  unsigned int i = 0;
  while (!InputFile.eof()) {
    std::cout << "here\n";
    char psName[32];
    InputFile >> psName;
    std::cout << psName;
    int psTag;
    InputFile >> psTag;
    double origin[3];
    InputFile >> origin[0] >> origin[1] >> origin[2];
    double E0[3];
    InputFile >> E0[0] >> E0[1] >> E0[2];
    double E1[3];
    InputFile >> E1[0] >> E1[1] >> E1[2];
    double scale[3];
    InputFile >> scale[0] >> scale[1] >> scale[2];
    int psNumParams;
    InputFile >> psNumParams;
    std::vector<double> psParams;
    for (unsigned int j = 0; j < psNumParams; j++) {
      double tmp;
      InputFile >> tmp;
      psParams.push_back(tmp);
    }
    if (!strcmp(psName,cylinder))
      _ps.push_back
	(new CylindricalProjectionSurface
	 (psTag,origin,E0,E1,scale,psParams[0],psParams[1]));
    else if (!strcmp(psName,revolvedParabola)) {
      double K[2];
      K[0] = psParams[1]; K[1] = psParams[2];
      _ps.push_back(new RevolvedParabolaProjectionSurface
		    (i,origin,E0,E1,scale,psParams[0],K));
    }
    else {
      _ps.push_back
	(new CylindricalProjectionSurface(i,origin,E0,E1,scale));
      Msg::Error("Unknown projection surface. Replaced by Cylinder...");
    }
    InputFile >> psName;
    _patchList.push_back(new PatchInfo);
    InputFile >> _patchList[i]->tag;
    InputFile >> _patchList[i]->tag;
    InputFile >> _patchList[i]->uMin >> _patchList[i]->uMax;
    InputFile >> _patchList[i]->vMin >> _patchList[i]->vMax;
    if (strcmp(psName,Exact)) {
      InputFile >> _patchList[i]->hardEdge[0] >> _patchList[i]->hardEdge[1] >>
	_patchList[i]->hardEdge[2] >> _patchList[i]->hardEdge[3];
      InputFile >> _patchList[i]->nModes[0] >> _patchList[i]->nModes[1];
      _patchList[i]->coeffFourier.resize(_patchList[i]->nModes[0]);
      for (int j=0;j<_patchList[i]->nModes[0];j++) {
	_patchList[i]->coeffFourier[j].resize(_patchList[i]->nModes[1]);
	for (int k=0;k<_patchList[i]->nModes[1];k++) {
	  double realCoeff, imagCoeff;
	  InputFile >> realCoeff >> imagCoeff;
	  _patchList[i]->coeffFourier[j][k] = 
	    std::complex<double>(realCoeff,imagCoeff);
	}
      }
      InputFile >> _patchList[i]->nM[0] >> _patchList[i]->nM[1];
      InputFile >> _patchList[i]->recompute;
      if ((_patchList[i]->derivative) && (!_patchList[i]->recompute)) {
	_patchList[i]->coeffCheby.resize(_patchList[i]->nM[0]);
	for (int j=0;j<_patchList[i]->nM[0];j++) {
	  _patchList[i]->coeffCheby[j].resize(_patchList[i]->nM[1]);
	  for (int k=0;k<_patchList[i]->nM[1];k++) {
	    double realCoeff, imagCoeff;
	    InputFile >> realCoeff >> imagCoeff;
	    _patchList[i]->coeffCheby[j][k] = 
	      std::complex<double>(realCoeff,imagCoeff);
	  }
	}
	_patchList[i]->coeffDerivU.resize(_patchList[i]->nM[0]);
	for (int j=0;j<_patchList[i]->nM[0];j++) {
	  _patchList[i]->coeffDerivU[j].resize(_patchList[i]->nM[1]);
	  for (int k=0;k<_patchList[i]->nM[1];k++) {
	    double realCoeff, imagCoeff;
	    InputFile >> realCoeff >> imagCoeff;
	    _patchList[i]->coeffDerivU[j][k] = 
	      std::complex<double>(realCoeff,imagCoeff);
	  }
	}
	_patchList[i]->coeffDerivV.resize(_patchList[i]->nM[0]);
	for (int j=0;j<_patchList[i]->nM[0];j++) {
	  _patchList[i]->coeffDerivV[j].resize(_patchList[i]->nM[1]);
	  for (int k=0;k<_patchList[i]->nM[1];k++) {
	    double realCoeff, imagCoeff;
	    InputFile >> realCoeff >> imagCoeff;
	    _patchList[i]->coeffDerivV[j][k] = 
	      std::complex<double>(realCoeff,imagCoeff);
	  }
	}
	_patchList[i]->coeffDerivUU.resize(_patchList[i]->nM[0]);
	for (int j=0;j<_patchList[i]->nM[0];j++) {
	  _patchList[i]->coeffDerivUU[j].resize(_patchList[i]->nM[1]);
	  for (int k=0;k<_patchList[i]->nM[1];k++) {
	    double realCoeff, imagCoeff;
	    InputFile >> realCoeff >> imagCoeff;
	    _patchList[i]->coeffDerivUU[j][k] = 
	      std::complex<double>(realCoeff,imagCoeff);
	  }
	}
	_patchList[i]->coeffDerivUV.resize(_patchList[i]->nM[0]);
	for (int j=0;j<_patchList[i]->nM[0];j++) {
	  _patchList[i]->coeffDerivUV[j].resize(_patchList[i]->nM[1]);
	  for (int k=0;k<_patchList[i]->nM[1];k++) {
	    double realCoeff, imagCoeff;
	    InputFile >> realCoeff >> imagCoeff;
	    _patchList[i]->coeffDerivUV[j][k] = 
	      std::complex<double>(realCoeff,imagCoeff);
	  }
	}
	_patchList[i]->coeffDerivVV.resize(_patchList[i]->nM[0]);
	for (int j=0;j<_patchList[i]->nM[0];j++) {
	  _patchList[i]->coeffDerivVV[j].resize(_patchList[i]->nM[1]);
	  for (int k=0;k<_patchList[i]->nM[1];k++) {
	    double realCoeff, imagCoeff;
	    InputFile >> realCoeff >> imagCoeff;
	    _patchList[i]->coeffDerivVV[j][k] = 
	      std::complex<double>(realCoeff,imagCoeff);
	  }
	}
      }
    }
    _patch.push_back(new ContinuationPatch(_patchList[i], _ps[i]));
    i++;
  }
  _nPatches = _patch.size();
}

Patch* FM_Reader::GetPatch(int tag)
{
  for (int i=0;i<_patch.size();i++)
    if (_patch[i]->GetTag() == tag)
      return _patch[i];
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
