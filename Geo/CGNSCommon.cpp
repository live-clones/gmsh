// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)


int cgnsError(const int cgIndexFile)
{
  Msg::Error("Error detected by CGNS library");
  Msg::Error(cg_get_error());
  if(cgIndexFile != -1) {
    if(cg_close(cgIndexFile)) {
      Msg::Error("Unable to close CGNS file");
    }
  }
  return 0;
}


void printProgress(const char *cstr, std::size_t i, std::size_t num)
{
  if(num > 100) {
    if(i % 100 == 1) {
      Msg::Info("%s %d/%d", cstr, i, num);
    }
  }
  else {
    Msg::Info("%s %d/%d", cstr, i, num);
  }
}

#endif // HAVE_LIBCGNS
