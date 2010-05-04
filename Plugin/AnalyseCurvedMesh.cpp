// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include <stdlib.h>
#include "Gmsh.h"
#include "MTriangle.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "polynomialBasis.h"
#include "AnalyseCurvedMesh.h"


extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin()
  {
    return new GMSH_AnalyseCurvedMeshPlugin();
  }
}

std::string GMSH_AnalyseCurvedMeshPlugin::getHelp() const
{
  return "Plugin(AnalyseCurvedMesh) computes AnalyseCurvedMeshs to boundaries in "
    "a mesh.\n\n"
    "Plugin(AnalyseCurvedMesh) creates a bunch of files.";
}

PView *GMSH_AnalyseCurvedMeshPlugin::execute(PView *v)
{
	Msg::Info("Hello !");
	
	GModel *m = GModel::current();

	for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++) {
		GFace *f = *it;
		Msg::Info("Je suis dans la surface %d", f->tag());
		
		for(int i = 0; i < (int) f->triangles.size(); i++) {
			MTriangle *t = f->triangles[i];
			const polynomialBasis *p = t->getFunctionSpace();
			Msg::Info("Taille de la matrice P : %dx%d", p->monomials.size1(), p->monomials.size2());
		}
	}
  return 0;
}
