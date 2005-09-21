#ifndef FILE_MESHING
#define FILE_MESHING

#include <myadt.hpp>
#include <gprim.hpp>
#include <linalg.hpp>
#include <opti.hpp>

namespace netgen
{

  class CSGeometry;
  
  
#include "msghandler.hpp"

#include "meshtype.hpp"
#include "localh.hpp"
#include "meshclass.hpp"
#include "global.hpp"


#include "meshtool.hpp"
#include "ruler2.hpp"
#include "adfront2.hpp"
#include "meshing2.hpp"
#include "improve2.hpp"


#include "geomsearch.hpp"
#include "adfront3.hpp"
#include "ruler3.hpp"

#ifndef SMALLLIB
#define _INCLUDE_MORE
#endif
#ifdef LINUX
#define _INCLUDE_MORE
#endif

#ifdef _INCLUDE_MORE
#include "meshing3.hpp"
#include "improve3.hpp"
#endif
#include "findip.hpp"

#include "topology.hpp"
#include "curvedelems.hpp"
#include "clusters.hpp"

#ifdef _INCLUDE_MORE
#include "meshfunc.hpp"
#endif
#include "bisect.hpp"
#include "hprefinement.hpp"
#include "boundarylayer.hpp"
#include "specials.hpp"
}

#endif
