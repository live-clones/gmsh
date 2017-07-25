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

#include <cgnslib.h>

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
    exit(1);
  }
  return false;
}

int tagFromCGNSType(ElementType_t cgnsType) {

  return ElementType::getTag(parentFromCGNSType(cgnsType),
                             orderFromCGNSType(cgnsType),
                             !completeCGNSType(cgnsType));
}

std::vector<SVector3> generatePointsCGNS(int,int,bool,bool);

void addHOEdgePointsCGNS(const SVector3 p0,
                         const SVector3 p1,
                         int order,
                         std::vector<SVector3>& points) {
  double ds = 1./order;
  for (int i=1;i<order;i++) {
    double f = ds*i;
    points.push_back(p0*(1.-f) + p1*f);
  }
}

void addHOTriPointsCGNS(const SVector3 p0,
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

void addHOQuaPointsCGNS(const SVector3 p0,
                        const SVector3 p1,
                        const SVector3 p2,
                        const SVector3 p3,
                        int order,
                        bool equidistant,
                        std::vector<SVector3>& points) {
  
  std::vector<SVector3> quaPoints = generatePointsCGNS(TYPE_QUA,
                                                       order-2,
                                                       true,
                                                       equidistant);
  
  double scale = double (order-2) / double(order);
  SVector3 offset(1./order,1./order,0); 
  
  for (size_t i=0;i<quaPoints.size();i++) {
    SVector3 ip = quaPoints[i];
    double u = ip[0] * scale;
    double v = ip[1] * scale;
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
  
  std::vector<SVector3> points;
  
  if (order == 0) points.push_back(SVector3(0,0,0));
  if (order > 0) {

    switch (parentType) {

    case TYPE_LIN:
      {
        
        // principal vertices
        
        points.push_back(SVector3(-1,0,0));
        points.push_back(SVector3(1,0,0));
        
        // ho points
        addHOEdgePointsCGNS(points[0],points[1],order,points);
        break;
      }
    case TYPE_TRI:
      {   

        // principal vertices
        points.push_back(SVector3(0,0,0));
        points.push_back(SVector3(1,0,0));
        points.push_back(SVector3(0,1,0));
      
        // edge points: rotate around plane
        for (int i=0;i<3;i++) addHOEdgePointsCGNS(points[i],points[(i+1)%3],order,points);
        
        // internal points
        if (complete && order > 2) {
          addHOTriPointsCGNS(points[0],
                             points[1],
                             points[2],
                             order,equidistant,points);
        }
      
        break;
      }
    case TYPE_QUA:
      {   
        points.push_back(SVector3(-1,-1,0));
        points.push_back(SVector3( 1,-1,0));
        points.push_back(SVector3( 1, 1,0));
        points.push_back(SVector3(-1, 1,0));
      
        for (int i=0;i<4;i++) {
          addHOEdgePointsCGNS(points[i],
                              points[(i+1)%4],
                              order,points);  
        }
        
        if (complete && order > 1) {
          
          addHOQuaPointsCGNS(points[0],
                             points[1],
                             points[2],
                             points[3],
                             order,equidistant,points);  
        }
        break;
      }
    case TYPE_TET:
      {
        points.push_back(SVector3(0,0,0));
        points.push_back(SVector3(1,0,0));
        points.push_back(SVector3(0,1,0));
        points.push_back(SVector3(0,0,1));
      
        // edges first run through base plane
      
        for (int i=0;i<3;i++) addHOEdgePointsCGNS(points[i],
                                                  points[(i+1)%3],
                                                  order,points);
        
        // then the upstanding edges follow
        
        for (int i=0;i<3;i++) addHOEdgePointsCGNS(points[i],
                                                  points[4],
                                                  order,points);
        
        if (complete && order > 2) {

          for (int face=0;face<4;face++) {
            
            SVector3 p0;
            SVector3 p1;
            SVector3 p2;

            // base plate
            if (face == 0) {
              p0 = points[0];
              p1 = points[1];
              p2 = points[2];
            }
            // run around the base plate ... 
            else {
              p0 = points[face-1];
              p1 = points[(face)%3];
              p2 = points[3];
            }
            addHOTriPointsCGNS(p0,p1,p2,order,equidistant,points);
          }

          // insert internal tet of order p-3

          if (order > 3) {
            std::vector<SVector3> tetPoints = generatePointsCGNS(TYPE_TET,order-4,
                                                                 true,true);
            
            double scale = (order-4)/order;
            SVector3 offset(1./order,1./order,1./order);
            for (size_t i=0;i<tetPoints.size();i++) {
              SVector3 volumePoint = tetPoints[i];
              volumePoint *= scale;
              volumePoint += offset;
              points.push_back(volumePoint);
            }
          }
        }
    
        break;
      }    
    case TYPE_HEX:
      {
        points.push_back(SVector3(-1,-1,-1));
        points.push_back(SVector3( 1,-1,-1));
        points.push_back(SVector3( 1, 1,-1));
        points.push_back(SVector3(-1, 1,-1));
        points.push_back(SVector3(-1,-1, 1));
        points.push_back(SVector3( 1,-1, 1));
        points.push_back(SVector3( 1, 1, 1));
        points.push_back(SVector3(-1, 1, 1));
        
        int start = points.size();
        
        // rotate around base plane
      
        for (int i=0;i<4;i++) addHOEdgePointsCGNS(points[i],
                                                  points[(i+1)%4],
                                                  order,points);
      
        // then mounting edges in sequence of base points
        
        for (int i=0;i<4;i++) addHOEdgePointsCGNS(points[i],
                                                  points[i+4],
                                                  order,points);
       
        // rotate around top plane
        
        for (int i=0;i<4;i++) addHOEdgePointsCGNS(points[i+4],
                                                  points[(i+1)%4+4],
                                                  order,points);
      

        // insert internal hex of order p-2
        if (complete && order > 2) {
          
          addHOQuaPointsCGNS(points[0],
                             points[1],
                             points[2],
                             points[3],
                             order,equidistant,points);
          
          for (int i=0;i<4;i++) {
            addHOQuaPointsCGNS(points[i],
                               points[(i+1)%4],
                               points[(i+1)%4+4],
                               points[i+4],
                               order,equidistant,points);
          }
          
          addHOQuaPointsCGNS(points[4],
                             points[5],
                             points[6],
                             points[7],
                             order,equidistant,points);
          
          std::vector<SVector3> ip = generatePointsCGNS(TYPE_HEX,order-2,true,true);
          
          double scale = double (order-2)/double (order);

          for (size_t i=0;i<ip.size();i++) {
            SVector3 hoPoint = ip[i];
            hoPoint *= scale;
            points.push_back(hoPoint);
          }
        }
    
        break;
      }
    default:
      Msg::Error("%s (%i) : Error CGNS element %i of order %i not yet implemented",
                 __FILE__,__LINE__,parentType,order);
    
    }
  }
  
  return points;
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
  
  int nbPoints = nb->getNumShapeFunctions();

  fullMatrix<double>  tfo(points.size(),points.size());
  
  nb->forwardTransformation(cgnsPoints,tfo);

  // tfo.print("Transformation matrix in transformation","%.1f");

  return tfo;
}

int* getRenumberingToGmsh(ElementType_t cgnsType) {
  
  int parent = parentFromCGNSType(cgnsType);
  int order  = orderFromCGNSType(cgnsType);
  bool complete = completeCGNSType(cgnsType);
  int gmshType = tagFromCGNSType(cgnsType);
  
  std::vector<SVector3> points = generatePointsCGNS(parent,order,complete,true);

  // std::cout << "Generate renumbering for an element of type " 
  //           << parent << " and order " << order;
  // if (complete) std::cout << " (complete) ";
  // std::cout << " - gmsh type " << gmshType << std::endl;
  
  // print(points,"Element points",0);
  
  
  fullMatrix<double> cgnsPoints(points.size(),3);
  
  for (size_t i=0;i<points.size();i++) {
    for (size_t d=0;d<3;d++) cgnsPoints(i,d) = points[i][d];
  }
  
  // cgnsPoints.print("Point location in renumberings","%.1f");

  const nodalBasis* nb = BasisFactory::getNodalBasis(gmshType);
  
  int nbPoints = nb->getNumShapeFunctions();
  
  int* renum = new int[points.size()];
  nb->forwardRenumbering(cgnsPoints,renum);
  return renum;
}


#endif
