#include "Gmsh.h"
#include "GmshUI.h"
#include "GModel.h"
#include "projectionFace.h"

extern GModel *GMODEL;

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  parabolicCylinder *p = new parabolicCylinder(GMODEL,10000);

  GMODEL->add( p );

  Msg(GERROR, "Model added: %d faces", GMODEL->numFace());
	
}
