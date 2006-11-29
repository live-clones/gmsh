#include "Gmsh.h"
#include "GmshUI.h"
#include "GModel.h"
#include "projectionFace.h"

extern GModel *GMODEL;

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{

  Msg(GERROR, "Reparameterize not implemented yet: %d faces", GMODEL->numFace());

}
