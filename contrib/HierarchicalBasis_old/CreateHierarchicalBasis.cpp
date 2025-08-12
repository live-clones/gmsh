// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.


#include "CreateHierarchicalBasis.h"

#include "ElementType.h"
#include "GmshDefines.h"
#include "GmshMessage.h"

#include "HierarchicalBasis.h"
#include "HierarchicalBasisH1Quad.h"
#include "HierarchicalBasisH1Tria.h"
#include "HierarchicalBasisH1Line.h"
#include "HierarchicalBasisH1Brick.h"
#include "HierarchicalBasisH1Tetra.h"
#include "HierarchicalBasisH1Pri.h"
#include "HierarchicalBasisH1Point.h"
#include "HierarchicalBasisHcurlLine.h"
#include "HierarchicalBasisHcurlQuad.h"
#include "HierarchicalBasisHcurlBrick.h"
#include "HierarchicalBasisHcurlTria.h"
#include "HierarchicalBasisHcurlTetra.h"
#include "HierarchicalBasisHcurlPri.h"

HierarchicalBasis* CreateHierarchicalBasis(const std::string &fsName, int familyType, int fsOrder) {
    HierarchicalBasis *basis(nullptr);
    if(fsName == "H1Legendre" || fsName == "GradH1Legendre")
    {
        switch(familyType)
        {
            case TYPE_PNT:
                basis = new HierarchicalBasisH1Point();
                break;
            case TYPE_LIN:
                basis = new HierarchicalBasisH1Line(fsOrder);
                break;
            case TYPE_TRI:
                basis = new HierarchicalBasisH1Tria(fsOrder);
                break;
            case TYPE_QUA:
                basis = new HierarchicalBasisH1Quad(fsOrder);
                break;
            case TYPE_TET:
                basis = new HierarchicalBasisH1Tetra(fsOrder);
                break;
            case TYPE_PRI:
                basis = new HierarchicalBasisH1Pri(fsOrder);
                break;
            case TYPE_HEX:
                basis = new HierarchicalBasisH1Brick(fsOrder);
                break;
            default:
                Msg::Error("Unknown familyType %i for basis function type %s",familyType, fsName.c_str());
                return nullptr;
        }
    }
    else if(fsName == "HcurlLegendre" || fsName == "CurlHcurlLegendre")
    {
        switch(familyType)
        {
            case TYPE_LIN:
                basis = new HierarchicalBasisHcurlLine(fsOrder);
                break;
            case TYPE_TRI:
                basis = new HierarchicalBasisHcurlTria(fsOrder);
                break;
            case TYPE_QUA:
                basis = new HierarchicalBasisHcurlQuad(fsOrder);
                break;
            case TYPE_TET:
                basis = new HierarchicalBasisHcurlTetra(fsOrder);
                break;
            case TYPE_PRI:
                basis = new HierarchicalBasisHcurlPri(fsOrder);
                break;
            case TYPE_HEX:
                basis = new HierarchicalBasisHcurlBrick(fsOrder);
                break;
            default:
                Msg::Error("Unknown familyType %i for basis function type %s", familyType, fsName.c_str());
                return nullptr;
        }
    }
    else
    {
        Msg::Error("Unknown function space named '%s'", fsName.c_str());
        return nullptr;
    }
    return basis;
}
