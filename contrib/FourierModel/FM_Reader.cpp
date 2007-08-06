#include <iostream>
#include <fstream>
#include "Message.h"
#include "FM_Reader.h"

FM_Reader::FM_Reader(const char* fn)
{
  char c;
  char Exact[8] = "Exact";
  char plane[16] = "plane";
  char cylinder[16] = "cylinder";
  char paraboloid[16] = "paraboloid";
  char revolvedParabola[32] = "revolvedParabola";

  std::ifstream InputFile(fn);
  if (!InputFile) {
    Msg::Info("Failed to open input file.");
    exit(EXIT_FAILURE);
  }
  InputFile >> _nPatches;
  _ps.resize(_nPatches, 0);
  std::cout << "npatches = " << _nPatches << std::endl;
  for (unsigned int i = 0; i < _nPatches; i++) {
    char psName[32];
    InputFile >> psName;
    std::cout << "psName = " << psName << std::endl;
    int psTag;
    InputFile >> psTag;
    std::cout << "psTag = " << psTag << std::endl;
    double origin[3];
    InputFile >> origin[0] >> origin[1] >> origin[2];
    std::cout << "o = "<<origin[0]<<" "<<origin[1]<<" "<<origin[2]<<std::endl;
    double E0[3];
    InputFile >> E0[0] >> E0[1] >> E0[2];
    std::cout << "E0 = " << E0[0] <<" "<< E0[1] <<" "<< E0[2] << std::endl;
    double E1[3];
    InputFile >> E1[0] >> E1[1] >> E1[2];
    std::cout << "E1 = " << E1[0] <<" "<< E1[1] <<" "<< E1[2] << std::endl;
    double scale[3];
    InputFile >> scale[0] >> scale[1] >> scale[2];
    std::cout << "s = " <<scale[0]<<" "<< scale[1]<<" "<<scale[2]<<std::endl;
    int psNumParams;
    InputFile >> psNumParams;
    std::cout << "psNumParams = " << psNumParams << std::endl;    
    double *psParams = new double [psNumParams];
    for (unsigned int j = 0; j < psNumParams; j++) {
      double tmp;
      InputFile >> psParams[j];
      std::cout << "psParams[" << j << "]  = " << psParams[j] << std::endl;
    }
    if (!strcmp(psName,plane))
      _ps[i] = new PlaneProjectionSurface(psTag,origin,E0,E1,scale);
    else if (!strcmp(psName,cylinder))
      _ps[i] = new CylindricalProjectionSurface
	(psTag,origin,E0,E1,scale,psParams[0],psParams[1]);
    else if (!strcmp(psName,paraboloid)) {
      double K[2];
      K[0] = psParams[0]; K[1] = psParams[1];
      _ps[i] = new ParaboloidProjectionSurface
	(psTag,origin,E0,E1,scale,K);
    }
    else if (!strcmp(psName,revolvedParabola)) {
      double R = psParams[0];
      double K[2];
      K[0] = psParams[1]; K[1] = psParams[2];
      printf("%d :: P : %g %g %g\n",i,R,K[0],K[1]);
      printf("%d :: O : %g %g %g\n",i,origin[0],origin[1],origin[2]);
      printf("%d :: E0 : %g %g %g\n",i,E0[0],E0[1],E0[2]);
      printf("%d :: E1 : %g %g %g\n",i,E1[0],E1[1],E1[2]);
      printf("%d :: s : %g %g %g\n",i,scale[0],scale[1],scale[2]);
      _ps[i] = new RevolvedParabolaProjectionSurface
	(psTag,origin,E0,E1,scale,R,K);
      printf("%d : here :: %g %g\n",i,K[0],K[1]);
    }
    else {
      _ps[i] = new CylindricalProjectionSurface(psTag,origin,E0,E1,scale);
      Msg::Error("Unknown projection surface. Replaced by Cylinder...");
    }
    delete [] psParams;
    InputFile >> psName;
    std::cout << "psName = " << psName << std::endl;
    _patchList.push_back(new PatchInfo);
    InputFile >> _patchList[i]->tag;
    std::cout << "pTag = " << _patchList[i]->tag << std::endl;
    InputFile >> _patchList[i]->derivative;
    std::cout << "pDerivative = " << _patchList[i]->derivative << std::endl;
    InputFile >> _patchList[i]->uMin >> _patchList[i]->uMax;
    std::cout <<"uLim = "<<_patchList[i]->uMin<<" "<<_patchList[i]->uMax << 
      std::endl;
    InputFile >> _patchList[i]->vMin >> _patchList[i]->vMax;
    std::cout <<"vLim = "<<_patchList[i]->vMin<<" "<<_patchList[i]->vMax << 
      std::endl;
    if (strcmp(psName,Exact)) {
      InputFile >> _patchList[i]->hardEdge[0] >> _patchList[i]->hardEdge[1] >>
	_patchList[i]->hardEdge[2] >> _patchList[i]->hardEdge[3];
      std::cout<<"HE : "<< _patchList[i]->hardEdge[0] << " " << 
	_patchList[i]->hardEdge[1] << " " << _patchList[i]->hardEdge[2] 
	       << " " << _patchList[i]->hardEdge[3] << std::endl;
      InputFile >> _patchList[i]->nModes[0] >> _patchList[i]->nModes[1];
      std::cout <<"Modes = "<<_patchList[i]->nModes[0] << " " <<
	_patchList[i]->nModes[1] << std::endl;     
      _patchList[i]->coeffFourier.resize(_patchList[i]->nModes[0]);
      for (int j=0;j<_patchList[i]->nModes[0];j++) {
	_patchList[i]->coeffFourier[j].resize(_patchList[i]->nModes[1]);
	for (int k=0;k<_patchList[i]->nModes[1];k++) {
	  double realCoeff, imagCoeff;
	  InputFile >> realCoeff >> imagCoeff;
	  _patchList[i]->coeffFourier[j][k] = 
	    std::complex<double>(realCoeff,imagCoeff);
	  std::cout << realCoeff << " " << imagCoeff << std::endl;
	}
      }
      InputFile >> _patchList[i]->nM[0] >> _patchList[i]->nM[1];
      std::cout <<"M = "<<_patchList[i]->nM[0] << " " <<
	_patchList[i]->nM[1] << std::endl;         
      InputFile >> _patchList[i]->recompute;
      std::cout << "pRecompute = " << _patchList[i]->recompute << std::endl; 
      if ((_patchList[i]->derivative) && (!_patchList[i]->recompute)) {
	_patchList[i]->coeffCheby.resize(_patchList[i]->nM[0]);
	for (int j=0;j<_patchList[i]->nM[0];j++) {
	  _patchList[i]->coeffCheby[j].resize(_patchList[i]->nM[1]);
	  for (int k=0;k<_patchList[i]->nM[1];k++) {
	    double realCoeff, imagCoeff;
	    InputFile >> realCoeff >> imagCoeff;
	    _patchList[i]->coeffCheby[j][k] = 
	      std::complex<double>(realCoeff,imagCoeff);
	    std::cout << realCoeff << " " << imagCoeff << std::endl;
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
	    std::cout << realCoeff << " " << imagCoeff << std::endl;
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
	    std::cout << realCoeff << " " << imagCoeff << std::endl;
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
	    std::cout << realCoeff << " " << imagCoeff << std::endl;
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
	    std::cout << realCoeff << " " << imagCoeff << std::endl;
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
	    std::cout << realCoeff << " " << imagCoeff << std::endl;
	  }
	}
      }
    }
    _patch.push_back(new ContinuationPatch(_patchList[i], _ps[i]));
  }
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
