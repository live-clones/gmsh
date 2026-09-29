// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "VisibilityList.h"

#include <regex>
#include <sstream>
#include <algorithm>
#include <string.h>

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "Context.h"
#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "partitionRegion.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

VisibilityList *VisibilityList::_instance = nullptr;
