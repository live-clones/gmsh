// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "DiscretizationError.h"
#include "Numeric.h"
#include <GEntity.h>
#include <GModel.h>
#include <Context.h>

// only temp for syntax higlighting
#include <MQuadrangle.h>
#include <MTriangle.h>

StringXNumber DiscretizationErrorOptions_Number[] = {
  {GMSH_FULLRC, "SuperSamplingNodes", NULL, 10.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDiscretizationErrorPlugin() {
    return new GMSH_DiscretizationErrorPlugin();
  }
}

std::string GMSH_DiscretizationErrorPlugin::getHelp() const
{
  return "Plugin(DiscretizationError) computes the error between the mesh "
    "and the geometry. It does so by supersampling the elements and computing "
    "the distance between the supersampled points dans their projection on "
    "the geometry.";
}

int GMSH_DiscretizationErrorPlugin::getNbOptions() const
{
  return sizeof(DiscretizationErrorOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DiscretizationErrorPlugin::getOption(int iopt)
{
  return &DiscretizationErrorOptions_Number[iopt];
}

PView *GMSH_DiscretizationErrorPlugin::execute(PView *v)
{
  double tol = CTX::instance()->geom.tolerance;
  int nEdgeNodes = (int)DiscretizationErrorOptions_Number[0].def;
  double paramQuandt = 1.0 / (nEdgeNodes -1) - 10*tol;
  double paramQuandtQuad = 2.0 / (nEdgeNodes - 1) - 10*tol;
  int i, j, k, counter;
  // used as a start estimate for u,v when performing an orthogonal projection
  double startEstimate[2] = {0.5, 0.5}; 
  double dx,dy,dz,distance;

  std::vector< std::pair<SPoint3,double> > quadDist(nEdgeNodes*nEdgeNodes);
  std::vector< std::pair<SPoint3,double> > triDist((nEdgeNodes + 1)*nEdgeNodes / 2);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  for (GModel::fiter itFace = GModel::current()->firstFace();
       itFace != GModel::current()->lastFace(); ++itFace) {

    // sample quadrangles
    /* 13 14 15 16
     * 9  10 11 12
     * 5  6  7  8
     * 1  2  3  4
     */
    for (std::vector<MQuadrangle*>::iterator itQuad = (*itFace)->quadrangles.begin();
         itQuad != (*itFace)->quadrangles.end(); ++itQuad) {
      for (j = 0; j < nEdgeNodes; j++) { // u
        for (i = 0; i < nEdgeNodes; i++) { // v
          (*itQuad)->pnt(-1+5*tol+paramQuandtQuad*i, -1+5*tol+paramQuandtQuad*j, 
                         0.0, quadDist[j*(nEdgeNodes) + i].first);
          SPoint3 *point = &quadDist[j*(nEdgeNodes) + i].first;
          GPoint closest = (*itFace)->closestPoint(*point,startEstimate);
          dx = closest.x() - point->x();
          dy = closest.y() - point->y();
          dz = closest.z() - point->z();
          quadDist[j*(nEdgeNodes) + i].second = sqrt(dx*dx + dy*dy + dz*dz);
        }
      }
      for (j = 0; j < nEdgeNodes - 1; j++) {
        for (i = 0; i < nEdgeNodes - 1; i++) {
          std::vector<double> *out = data2->incrementList(1, TYPE_QUA);
          int indices[4] = {i+j*nEdgeNodes, i+j*nEdgeNodes+1, i+(j+1)*nEdgeNodes+1,
                            i+(j+1)*nEdgeNodes};
          for (k = 0; k < 4; k++) out->push_back(quadDist[indices[k]].first.x());
          for (k = 0; k < 4; k++) out->push_back(quadDist[indices[k]].first.y());
          for (k = 0; k < 4; k++) out->push_back(quadDist[indices[k]].first.z());
          for (k = 0; k < 4; k++) out->push_back(quadDist[indices[k]].second);
        }
      }
    }

    // sample triangles
    /* 10
     * 6  9
     * 3  5  8
     * 1  2  4  7
     */
    for (std::vector<MTriangle*>::iterator itTri = (*itFace)->triangles.begin(); 
         itTri != (*itFace)->triangles.end(); ++itTri) {
      counter = 0;
      for (i = 0; i < nEdgeNodes; i++) {
        for (j = 0; j < (i + 1); j++) {
          (*itTri)->pnt(5*tol + paramQuandt*(i - j), 5*tol + paramQuandt*j, 0.0,
                        triDist[counter].first);
          SPoint3 *point = &triDist[counter].first; // Check : the points are good
          GPoint closest = (*itFace)->closestPoint(*point,startEstimate);
          dx = (closest.x() - point->x());
          dy = (closest.y() - point->y());
          dz = (closest.z() - point->z());
          triDist[counter].second = sqrt(dx*dx + dy*dy + dz*dz);
          counter++;
        }
      }
      
      int indices[3];
      for (j = 0; j < nEdgeNodes - 1; j++) { // row in the triangle
        bool odd = false;
        for (i = 0; i < j*2 + 1; i ++) { // small tri in the row
          if (!odd) {
            indices[0] = i / 2 + (j+1)*j/2;
            indices[1] = i / 2 + (j+1)*j/2 + j+1;
            indices[2] = i / 2 + (j+1)*j/2 + j+2;
          } 
          else {
            indices[0] = (i-1)/2 + (j+1)*j/2;
            indices[1] = (i-1)/2 + (j+1)*j/2 + j+2;
            indices[2] = (i-1)/2 + (j+1)*j/2 + 1;
          }
          std::vector<double> *out = data2->incrementList(1, TYPE_TRI);
          for (k = 0; k < 3; k++) out->push_back(triDist[indices[k]].first.x());
          for (k = 0; k < 3; k++) out->push_back(triDist[indices[k]].first.y());
          for (k = 0; k < 3; k++) out->push_back(triDist[indices[k]].first.z());
          for (k = 0; k < 3; k++) out->push_back(triDist[indices[k]].second);
          odd = !odd;
        }
      }
    }
    
    //viusalize stuff
  }
  
  data2->setName("Discretization Error");
  data2->setFileName("discretization_err.pos");
  data2->finalize();

  return v2;
}
