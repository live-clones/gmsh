// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

#include "HierarchicalBasisH1.h"

void HierarchicalBasisH1::addAllOrientedFaceFunctions(double const &u, double const &v, double const &w,
                                                      const std::vector<double> &faceFunctions,
                                                      std::vector<double> &quadFaceFunctionsAllOrientations,
                                                      std::vector<double> &triFaceFunctionsAllOrientations) {
    // quadrilateral faces
    int it = 0;
    if(_numQuadFaceFunction > 0) {
        for(int iOrientation = 0; iOrientation < 8; iOrientation++) {

            std::vector<double> orientedFaceFunction(_numQuadFaceFunction + _numTriFaceFunction);
            
            for(int r = 0; r < _numQuadFaceFunction + _numTriFaceFunction; r++) {
                orientedFaceFunction[r] = faceFunctions[r];
            }
            
            std::array<int, 3> quadFlags = getQuadFaceFlagsFromIndex(iOrientation);
            int flag1 = quadFlags[0];
            int flag2 = quadFlags[1];
            int flag3 = quadFlags[2];
            
            for(int iFace = 0; iFace < _numQuadFace; iFace++) {
                orientOneFace(u, v, w, flag1, flag2, flag3, iFace, orientedFaceFunction);
            }
            
            for(int r = 0; r < _numQuadFaceFunction; r++) {
                quadFaceFunctionsAllOrientations[it] = orientedFaceFunction[r];
                it++;
            }
        }
    }
    
    // Triangular faces
    it = 0;
    if(_numTriFaceFunction > 0) {
        for(int iOrientation = 0; iOrientation < 6; iOrientation++) {
            std::vector<double> orientedFaceFunction(_numQuadFaceFunction + _numTriFaceFunction);
            for(int r = 0; r < _numQuadFaceFunction + _numTriFaceFunction; r++) {
                orientedFaceFunction[r] = faceFunctions[r];
            }
            
            std::array<int, 2> triFlags = getTriFaceFlagsFromIndex(iOrientation);
            int flag1 = triFlags[0];
            int flag2 = triFlags[1];
            int flag3 = 1;
            
            for(int iFace = _numQuadFace; iFace < _numQuadFace + _numTriFace; iFace++) {
                orientOneFace(u, v, w, flag1, flag2, flag3, iFace, orientedFaceFunction); // flage3 no sense !!!
            }
            
            for(int r = 0; r < _numTriFaceFunction; r++) {
                triFaceFunctionsAllOrientations[it] = orientedFaceFunction[r + _numQuadFaceFunction];
                it++;
            }
        }
    }
}

void HierarchicalBasisH1::addAllOrientedFaceFunctions(double const &u, double const &v, double const &w,
                                                      const std::vector<std::vector<double> > &faceFunctions,
                                                      std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
                                                      std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
                                                      std::string typeFunction) {
    int it = 0;
    // quadrilateral faces
    if(_numQuadFaceFunction > 0) {
        for(int iOrientation = 0; iOrientation < 8; iOrientation++) {
            std::vector<std::vector<double> > orientedFaceFunction(_numQuadFaceFunction + _numTriFaceFunction, std::vector<double>(3, 0));
            
            for(int r = 0; r < _numQuadFaceFunction + _numTriFaceFunction; r++) {
                orientedFaceFunction[r][0] = faceFunctions[r][0];
                orientedFaceFunction[r][1] = faceFunctions[r][1];
                orientedFaceFunction[r][2] = faceFunctions[r][2];
            }
      
            std::array<int, 3> quadFlags = getQuadFaceFlagsFromIndex(iOrientation);
            int flag1 = quadFlags[0];
            int flag2 = quadFlags[1];
            int flag3 = quadFlags[2];
            
            for(int iFace = 0; iFace < _numQuadFace; iFace++) {
                orientOneFace(u, v, w, flag1, flag2, flag3, iFace, orientedFaceFunction);
            }
            
            for(int r = 0; r < _numQuadFaceFunction; r++) {
                quadFaceFunctionsAllOrientations[it][0] = orientedFaceFunction[r][0];
                quadFaceFunctionsAllOrientations[it][1] = orientedFaceFunction[r][1];
                quadFaceFunctionsAllOrientations[it][2] = orientedFaceFunction[r][2];
                it++;
            }
        }
    }
  
    // Triangular faces
    it = 0;
    if(_numTriFaceFunction > 0) {
        for(int iOrientation = 0; iOrientation < 6; iOrientation++) {
            std::vector<std::vector<double> > orientedFaceFunction(_numQuadFaceFunction + _numTriFaceFunction, std::vector<double>(3, 0));
            for(int r = 0; r < _numQuadFaceFunction + _numTriFaceFunction; r++) {
                orientedFaceFunction[r] = faceFunctions[r];
            }
    
            std::array<int, 2> triFlags = getTriFaceFlagsFromIndex(iOrientation);
            int flag1 = triFlags[0];
            int flag2 = triFlags[1];
            int flag3 = 1;
      
            for(int iFace = _numQuadFace; iFace < _numQuadFace + _numTriFace; iFace++) {
                orientOneFace(u, v, w, flag1, flag2, flag3, iFace, orientedFaceFunction);
            }
      
            for(int r = 0; r < _numTriFaceFunction; r++) {
                triFaceFunctionsAllOrientations[it][0] = orientedFaceFunction[r + _numQuadFaceFunction][0];
                triFaceFunctionsAllOrientations[it][1] = orientedFaceFunction[r + _numQuadFaceFunction][1];
                triFaceFunctionsAllOrientations[it][2] = orientedFaceFunction[r + _numQuadFaceFunction][2];
                it++;
            }
        }
    }
}
