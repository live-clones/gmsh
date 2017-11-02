// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <fstream>
#include "GModel.h"
#include "OS.h"
#include "GmshDefines.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "StringUtils.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"

int _readMSH4(const std::string &name)
{
  
}

int _writeMSH4(const std::string &name, double version=4.0, bool binary=false,
               bool saveAll=false, bool saveParametric=false,
               double scalingFactor=1.0, int elementStartNum=0,
               int saveSinglePartition=0, bool multipleView=false,
               bool renumberVertices=true)
{
  
}


