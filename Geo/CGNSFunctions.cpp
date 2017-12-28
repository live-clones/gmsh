// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// GModelIO_CGNS.cpp - Copyright (C) 2008-2017 S. Guzik, B. Gorissen, K. Hillewaert, C. Geuzaine, J.-F. Remacle

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "CGNSOptions.h"

#if defined(HAVE_LIBCGNS)

#include "BasisFactory.h"
#include "SVector3.h"
#include "fullMatrix.h"
#include "GmshDefines.h"

namespace CGNS {
#include <cgnslib.h>
};

using namespace CGNS;

#include <vector>
// -----------------------------------------------------------------------------

int parentFromCGNSType(ElementType_t cgnsType) {
  
  switch(cgnsType) {
  case NODE:
    return TYPE_PNT;
    break;
  case BAR_2: case BAR_3: case BAR_4: case BAR_5:
    return TYPE_LIN;
    break;
  case TRI_3: case TRI_6: case TRI_9: case TRI_10: case TRI_12: case TRI_15:  
    return TYPE_TRI;
    break;
  case QUAD_4: case QUAD_9: case QUAD_16: case QUAD_25:
               case QUAD_8: case QUAD_12: case QUAD_P4_16: 
    return TYPE_QUA;
    break;
  case TETRA_4: case TETRA_10: case TETRA_20: case TETRA_35: 
                               case TETRA_16: case TETRA_22: 
                                              case TETRA_34: 
    return TYPE_TET;
    break;
  case PYRA_5: case PYRA_14: case PYRA_30: case PYRA_55:
               case PYRA_13: case PYRA_21: case PYRA_P4_29:  
                             case PYRA_29: case PYRA_50:  
    return TYPE_PYR;
    break;
   // pentahedra
  case PENTA_6:  case PENTA_18: case PENTA_40: case PENTA_75:   
                 case PENTA_15: case PENTA_24: case PENTA_33: 
                                case PENTA_38: case PENTA_66: 
    return TYPE_PRI;
    break;
    // hexahedra
  case HEXA_8: case HEXA_27: case HEXA_64: case HEXA_125:
               case HEXA_20: case HEXA_32: case HEXA_44: 
    // case HEXA_26: 
                             case HEXA_56: case HEXA_98:  
    return TYPE_HEX;
    break;
  case MIXED:
  case NGON_n:
  case NFACE_n:
  case ElementTypeUserDefined:
  case ElementTypeNull:
    Msg::Warning("Finding parent type for unsupported CGNS element type %i",cgnsType);
    return -1;
    break;
  } 
  return -1;
}

int orderFromCGNSType(ElementType_t cgnsType) {
  
  switch( cgnsType ) {
  case NODE:
    return 0;
    break;
  case BAR_2: case TRI_3:  case QUAD_4:     case TETRA_4:  case PYRA_5:  case PENTA_6:  case HEXA_8:
    return 1;
    break;
  case BAR_3: case TRI_6:  case QUAD_9:     case TETRA_10: case PYRA_14: case PENTA_18: case HEXA_27:
                           case QUAD_8:                    case PYRA_13: case PENTA_15: case HEXA_20:
    //                                                                           case HEXA_26: 
    return 2;
    break;
  case BAR_4: case TRI_10: case QUAD_16:    case TETRA_20: case PYRA_30: case PENTA_40: case HEXA_64:
              case TRI_9:  case QUAD_12:    case TETRA_16: case PYRA_21: case PENTA_24: case HEXA_32:
                                                           case PYRA_29: case PENTA_38: case HEXA_56: 
    return 3;
    break;
  case BAR_5: case TRI_15: case QUAD_25:    case TETRA_35: case PYRA_55:    case PENTA_75: case HEXA_125:
              case TRI_12: case QUAD_P4_16: case TETRA_22: case PYRA_P4_29: case PENTA_33: case HEXA_44:
                                            case TETRA_34: case PYRA_50:    case PENTA_66: case HEXA_98: 
    return 4;
    break;
  case MIXED:
  case NGON_n:
  case NFACE_n:
  case ElementTypeUserDefined:
  case ElementTypeNull:
    Msg::Warning("Finding order for unsupported CGNS element type %i",cgnsType);
    return -1;
    break;
  }
  return -1;
}

bool completeCGNSType(ElementType_t cgnsType) {

  switch( cgnsType ) {
    // complete elements
  case NODE:
  case BAR_2: case TRI_3:  case QUAD_4:     case TETRA_4:  case PYRA_5:  case PENTA_6:  case HEXA_8:
  case BAR_3: case TRI_6:  case QUAD_9:     case TETRA_10: case PYRA_14: case PENTA_18: case HEXA_27:
  case BAR_4: case TRI_10: case QUAD_16:    case TETRA_20: case PYRA_30: case PENTA_40: case HEXA_64:
  case BAR_5: case TRI_15: case QUAD_25:    case TETRA_35: case PYRA_55: case PENTA_75: case HEXA_125:
    return true;
    break;
    // serendipity edge elements
               case QUAD_8:                    case PYRA_13:    case PENTA_15: case HEXA_20:
               case QUAD_12:    case TETRA_16: case PYRA_21:    case PENTA_24: case HEXA_32:
  case TRI_12: case QUAD_P4_16: case TETRA_22: case PYRA_P4_29: case PENTA_33: case HEXA_44:
    return false;
    break;
    // serendipity elements
    //                       case HEXA_26: 
                 case PYRA_29:  case PENTA_38: case HEXA_56: 
  case TETRA_34: case PYRA_50:  case PENTA_66: case HEXA_98: 
                                                
  default:
    return false;
  }
  return false;
}

int tagFromCGNSType(ElementType_t cgnsType) {

  return ElementType::getTag(parentFromCGNSType(cgnsType),
                             orderFromCGNSType(cgnsType),
                             !completeCGNSType(cgnsType));
}

std::vector<SVector3> generatePointsCGNS(int,int,bool,bool);

void addEdgePointsCGNS(const SVector3 p0,
                         const SVector3 p1,
                         int order,
                         std::vector<SVector3>& points) {
  double ds = 1./order;
  for (int i=1;i<order;i++) {
    double f = ds*i;
    points.push_back(p0*(1.-f) + p1*f);
  }
}

void addTriPointsCGNS(const SVector3 p0,
                      const SVector3 p1,
                      const SVector3 p2,
                      int order,
                      bool equidistant,
                      std::vector<SVector3>& points) {
  
  std::vector<SVector3> triPoints = generatePointsCGNS(TYPE_TRI,
                                                       order-3,
                                                       true,true);
  
  double scale = double (order-3) / double(order);
  SVector3 offset(1./order,1./order,0); 
  
  for (size_t i=0;i<triPoints.size();i++) {
    SVector3 ip = triPoints[i];
    double u = ip[0] * scale + 1./order;
    double v = ip[1] * scale + 1./order;

    SVector3 pt = (1.-u-v) * p0 + u * p1 + v*p2;
    
    points.push_back(pt);
  }
}



void addQuaPointsCGNS(int order,std::vector<SVector3>& points) {
  
  if (order > 2) {
    
    double scale = double (order -2) / double(order);
    
    SVector3 corner[4] = {SVector3(-1,-1,0),
                          SVector3( 1,-1,0),
                          SVector3( 1, 1,0),
                          SVector3(-1, 1,0)};

    for (int i=0;i<4;i++) {
      SVector3 c1 = corner[i];
      SVector3 c2 = corner[(i+1)%4];
      double ds = 1./(order-2);
      for (int i=0;i<order-2;i++) points.push_back((c1*(1.-i*ds) + c2*(i*ds))*scale);
    }
  }
  if (order == 2 || order == 4) points.push_back(SVector3(0,0,0));
}

void addQuaPointsCGNS(const SVector3 p0,
                      const SVector3 p1,
                      const SVector3 p2,
                      const SVector3 p3,
                      int order,
                      std::vector<SVector3>& points) {
  
  std::vector<SVector3> quaPoints;

  addQuaPointsCGNS(order,quaPoints);
  
  for (size_t i=0;i<quaPoints.size();i++) {
    SVector3 ip = quaPoints[i];
    double u = ip[0];
    double v = ip[1];
    SVector3 pt = ((1.-u)*(1.-v)*p0 + 
                   (1.+u)*(1.-v)*p1 + 
                   (1.+u)*(1.+v)*p2 + 
                   (1.-u)*(1.+v)*p3)*0.25;
    points.push_back(pt);
  }
}

void print(std::vector<SVector3>& points,const char* title,int iStart,int iEnd=-1) {

  iEnd = iEnd == -1 ? points.size() : iEnd;

  std::cout << title << std::endl;
  for (int i=iStart;i<iEnd;i++) {
    std::cout << i << " :";
    for (int d=0;d<3;d++) std::cout << " " << points[i][d];
    std::cout << std::endl;
  }
}


std::vector<SVector3> generatePointsCGNS(int parentType,
                                         int order,
                                         bool complete,
                                         bool equidistant) {
  
  std::vector<SVector3> pp;
  
  if (order == 0) pp.push_back(SVector3(0,0,0));
  if (order > 0) {

    switch (parentType) {

    case TYPE_LIN:
      {
        // principal vertices
        pp.push_back(SVector3(-1,0,0));
        pp.push_back(SVector3(1,0,0));
        
        // internal points
        addEdgePointsCGNS(pp[0],pp[1],order,pp);
        
        break;
      }
    case TYPE_TRI:
      {   
        // principal vertices
        pp.push_back(SVector3(0,0,0));
        pp.push_back(SVector3(1,0,0));
        pp.push_back(SVector3(0,1,0));
      
        // internal points of edges
        for (int i=0;i<3;i++) addEdgePointsCGNS(pp[i],pp[(i+1)%3],order,pp);
        
        // internal points
        if (complete && order > 2) {
          addTriPointsCGNS(pp[0],pp[1],pp[2],order,equidistant,pp);
        }
        
        break;
      }
    case TYPE_QUA:
      {   
        // principal vertices
        pp.push_back(SVector3(-1,-1,0));
        pp.push_back(SVector3( 1,-1,0));
        pp.push_back(SVector3( 1, 1,0));
        pp.push_back(SVector3(-1, 1,0));
      
        // internal points of edges
        for (int i=0;i<4;i++) {
          addEdgePointsCGNS(pp[i],pp[(i+1)%4],order,pp);  
        }
        
        // internal points
        if (complete && order > 1) {
          addQuaPointsCGNS(pp[0],pp[1],pp[2],pp[3],order,pp);  
        }
        break;
      }
    case TYPE_TET:
      {
        // principal vertices
        pp.push_back(SVector3(0,0,0));
        pp.push_back(SVector3(1,0,0));
        pp.push_back(SVector3(0,1,0));
        pp.push_back(SVector3(0,0,1));
      
        // internal points in edges of base triangle 
        for (int i=0;i<3;i++) addEdgePointsCGNS(pp[i],pp[(i+1)%3],order,pp);
        
        // internal points in upstanding edges
        for (int i=0;i<3;i++) addEdgePointsCGNS(pp[i],pp[3],order,pp);
        
        if (complete && order > 2) {

          // internal points of base triangle
          addTriPointsCGNS(pp[0],pp[1],pp[2],order,equidistant,pp);

          // internal points of upstanding triangles
          for (int i=0;i<3;i++) {
            addTriPointsCGNS(pp[i],pp[(i+1)%3],pp[3],order,equidistant,pp);
          }

          // internal points as a tet of order p-3
          if (order > 3) {
            std::vector<SVector3> tetPp = generatePointsCGNS(TYPE_TET,order-4,
                                                                 true,true);
            
            double scale = (order-4)/order;
            SVector3 offset(1./order,1./order,1./order);
            for (size_t i=0;i<tetPp.size();i++) {
              SVector3 volumePoint = tetPp[i];
              volumePoint *= scale;
              volumePoint += offset;
              pp.push_back(volumePoint);
            }
          }
        }
    
        break;
      }    
    case TYPE_HEX:
      {
        
        // principal vertices    
        pp.push_back(SVector3(-1,-1,-1));
        pp.push_back(SVector3( 1,-1,-1));
        pp.push_back(SVector3( 1, 1,-1));
        pp.push_back(SVector3(-1, 1,-1));
        pp.push_back(SVector3(-1,-1, 1));
        pp.push_back(SVector3( 1,-1, 1));
        pp.push_back(SVector3( 1, 1, 1));
        pp.push_back(SVector3(-1, 1, 1));
        
        // internal points of base quadrangle edges
        for (int i=0;i<4;i++) addEdgePointsCGNS(pp[i],pp[(i+1)%4],order,pp);
      
        std::vector<SVector3> up[4];
        // internal points of mounting edges
        for (int i=0;i<4;i++) {
          addEdgePointsCGNS(pp[i],pp[i+4],order,up[i]);
          pp.insert(pp.end(),up[i].begin(),up[i].end());
        }
       
        // internal points of top quadrangle edges
        for (int i=0;i<4;i++) addEdgePointsCGNS(pp[i+4],pp[(i+1)%4+4],order,pp);
          
        if (complete && order > 1) {
          
          // internal points of base quadrangle
          addQuaPointsCGNS(pp[0],pp[1],pp[2],pp[3],order,pp);
          
          // internal points of upstanding faces
          for (int i=0;i<4;i++) {
            addQuaPointsCGNS(pp[i],pp[(i+1)%4],pp[(i+1)%4+4],pp[i+4],order,pp);
          }
          
          // internal points of top quadrangle
          addQuaPointsCGNS(pp[4],pp[5],pp[6],pp[7],order,pp);
          
          // internal volume points as a succession of internal planes
          for (int i=0;i<=order-2;i++) {
            addQuaPointsCGNS(up[0][i],up[1][i],up[2][i],up[3][i],order,pp);
          }  
        }
        
        break;
      }
    case TYPE_PRI:
      {
        
        // principal vertices
        pp.push_back(SVector3(0,0,-1));
        pp.push_back(SVector3(1,0,-1));
        pp.push_back(SVector3(0,1,-1));
        pp.push_back(SVector3(0,0,1));
        pp.push_back(SVector3(1,0,1));
        pp.push_back(SVector3(0,1,1));

        // internal points in edges of base triangle 
        for (int i=0;i<3;i++) addEdgePointsCGNS(pp[i],pp[(i+1)%3],order,pp);
        
        // internal points in upstanding edges
        std::vector<SVector3> edge[3]; // keep for definition of volume pp
        for (int i=0;i<3;i++) {
          addEdgePointsCGNS(pp[i],pp[i+3],order,edge[i]);
          pp.insert(pp.end(),edge[i].begin(),edge[i].end());
        }
        
        // internal points in edges of top triangle
        for (int i=0;i<3;i++) addEdgePointsCGNS(pp[i+3],pp[(i+1)%3+3],order,pp);
        
        if (complete) {
          
          // internal vertices for base triangle
          addTriPointsCGNS(pp[0],pp[1],pp[2],order,true,pp);
          
          // internal vertices for upstanding quadrilaterals
          for (int i=0;i<3;i++) {
            addQuaPointsCGNS(pp[i],pp[(i+1)%3],pp[(i+1)%3+3],pp[i+3],order,pp);
          }
          
          // internal points for top triangle
          addTriPointsCGNS(pp[3],pp[4],pp[5],order,true,pp);

          // internal points in the volume as a succession of "triangles"
          for (int o=0;o<order-1;o++) {
            addTriPointsCGNS(edge[0][o],edge[1][o],edge[2][o],order,true,pp);
          }
        }
        break;
      }
    case TYPE_PYR:
      {
        // principal vertices
        pp.push_back(SVector3(-1,-1,0));
        pp.push_back(SVector3( 1,-1,0));
        pp.push_back(SVector3( 1, 1,0));
        pp.push_back(SVector3(-1, 1,0));
        pp.push_back(SVector3( 0, 0,1));
        
        // internal points in edges of base quadrilateral
        for (int i=0;i<4;i++) addEdgePointsCGNS(pp[i],pp[(i+1)%4],order,pp);
        
        // internal points in upstanding edges
        for (int i=0;i<4;i++) addEdgePointsCGNS(pp[i],pp[4],order,pp);
        
        // internal points in base quadrilateral
        addQuaPointsCGNS(pp[0],pp[1],pp[2],pp[3],order,pp);
        
        // internal points in upstanding triangles
        for (int i=0;i<4;i++) addTriPointsCGNS(pp[i],pp[(i+1)%4],pp[4],order,true,pp);

        // internal points as an internal pyramid of order p-3
        std::vector<SVector3> pyr = generatePointsCGNS(TYPE_PYR,order-3,true,true);
        
        SVector3 offset(0,0,1./order);
        double scale = double (order-3) / double(order);
        
        for (size_t i=0;i<pyr.size();++i) pp.push_back((pyr[i]*scale)+offset);
        

        break;
      }
    default:
      Msg::Error("%s (%i) : Error CGNS element %i of order %i not yet implemented",
                 __FILE__,__LINE__,ElementType::nameOfParentType(parentType).c_str(),order);
    
    }
  }
  
  return pp;
}

fullMatrix<double> getTransformationToGmsh(ElementType_t cgnsType) {


  int parent = parentFromCGNSType(cgnsType);
  int order  = orderFromCGNSType(cgnsType);
  bool complete = completeCGNSType(cgnsType);
  int gmshType = tagFromCGNSType(cgnsType);
  
  std::vector<SVector3> points = generatePointsCGNS(parent,order,complete,true);
  
  fullMatrix<double> cgnsPoints(points.size(),3);
  
  for (size_t i=0;i<points.size();i++) {
    for (size_t d=0;d<3;d++) cgnsPoints(i,d) = points[i][d];
  }
  
  // cgnsPoints.print("Point locations in transformation","%.1f");

  static const nodalBasis* nb = BasisFactory::getNodalBasis(gmshType);
  
  fullMatrix<double>  tfo(points.size(),points.size());
  
  nb->forwardTransformation(cgnsPoints,tfo);

  // tfo.print("Transformation matrix in transformation","%.1f");

  return tfo;
}

#include <sstream>
#include <fstream>
#include <iomanip>

int* getRenumberingToGmsh(ElementType_t cgnsType) {
  
  int parent = parentFromCGNSType(cgnsType);
  int order  = orderFromCGNSType(cgnsType);
  bool complete = completeCGNSType(cgnsType);
  int gmshType = tagFromCGNSType(cgnsType);
  
  std::vector<SVector3> points = generatePointsCGNS(parent,order,complete,true);  
  fullMatrix<double> cgnsPoints(points.size(),3);
  
  for (size_t i=0;i<points.size();i++) {
    for (size_t d=0;d<3;d++) cgnsPoints(i,d) = points[i][d];
  }
  
  // cgnsPoints.print("Point location in renumberings","%.1f");

  const nodalBasis* nb = BasisFactory::getNodalBasis(gmshType);
  
  int* renum = new int[points.size()];
  nb->forwardRenumbering(cgnsPoints,renum);

  
  // std::ostringstream filename;
  // filename << ElementType::nameOfParentType(parent) << "_p" << order << ".dat";
  // std::ofstream checkFile(filename.str().c_str());
  
  // checkFile << "CGNS Control points in a " << ElementType::nameOfParentType(parent) 
  //           << " of order " << order << std::endl;
  // for (size_t i=0;i<points.size();i++) {
  //   checkFile << std::setw(2) << i+1 
  //             << " -> "  << std::setw(2) << renum[i] 
  //             << " - "
  //             << "(" << std::setw(4) << points[i][0] 
  //             << "," << std::setw(4) << points[i][1] 
  //             << "," << std::setw(4) << points[i][2] << ")" << std::endl;
  // }
  // checkFile.close();
  
  return renum;
}

int gridLocationDimCGNS(GridLocation_t lt) {
  
  switch (lt) {
  case CellCenter:
    return 3;
    break;
  case FaceCenter:
  case IFaceCenter:
  case JFaceCenter:
  case KFaceCenter:
    return 2;
    break;
  case EdgeCenter:
    return 1;
    break;
  case Vertex:
    return 0;
    break;
  case GridLocationNull:
  case GridLocationUserDefined:
    return -1;
    break;
  }
  return -1;
}


GridLocation_t unstructuredGridLocationCGNS(int dim) {

  switch (dim) {
  case 3:
    return CellCenter;
    break;
  case 2:
    return FaceCenter;
    break;
  case 1:
    return EdgeCenter;
    break;
  case 0:
    return Vertex;
    break;
  }
  
  return GridLocationNull;
}  


#endif
