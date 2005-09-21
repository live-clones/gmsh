#include <mystdlib.h>
#include "incvis.hpp"

#include <myadt.hpp>
#include <meshing.hpp>
#include <csg.hpp>
#include <stlgeom.hpp>


namespace netgen
{
#include "mvdraw.hpp"

/* *********************** Draw Geometry **************** */




extern AutoPtr<CSGeometry> geometry;


VisualSceneGeometry :: VisualSceneGeometry ()
  : VisualScene()
{
  selsurf = 0;
}

VisualSceneGeometry :: ~VisualSceneGeometry ()
{
  ;
}

void VisualSceneGeometry :: SelectSurface (int aselsurf)
{
  selsurf = aselsurf;
  DrawScene();
}


void VisualSceneGeometry :: DrawScene ()
{
  int i;

  if (changeval != geometry->GetChangeVal())
    BuildScene();
  changeval = geometry->GetChangeVal();

  glClearColor(backcolor, backcolor, backcolor, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  SetLight();


  glPushMatrix();
  glMultMatrixf (transformationmat);

  SetClippingPlane ();

  glShadeModel (GL_SMOOTH);
  glDisable (GL_COLOR_MATERIAL);
  glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  /*
  float mat_spec_col[] = { 1, 1, 1, 1 };
  glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec_col);
  */

  double shine = vispar.shininess;
  double transp = vispar.transp;

  glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, shine);
  glLogicOp (GL_COPY);

  glEnable (GL_NORMALIZE);

  for (i = 0; i < geometry->GetNTopLevelObjects(); i++)
    {
      const TopLevelObject * tlo = geometry -> GetTopLevelObject (i);
      if (tlo->GetVisible() && !tlo->GetTransparent())
	{
	  float mat_col[] = { tlo->GetRed(), tlo->GetGreen(), tlo->GetBlue(), 1 };
	  glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_col);
	  
	  glCallList (trilists[i]);
	}
    }


  glPolygonOffset (1, 1);
  glEnable (GL_POLYGON_OFFSET_FILL);

  glLogicOp (GL_NOOP);
  for (i = 0; i < geometry->GetNTopLevelObjects(); i++)
    {
      const TopLevelObject * tlo = geometry -> GetTopLevelObject (i);
      if (tlo->GetVisible() && tlo->GetTransparent())
	{
	  float mat_col[] = { tlo->GetRed(), tlo->GetGreen(), tlo->GetBlue(), transp };

	  glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_col);
	  
	  glCallList (trilists[i]);
	}
    }

  glDisable (GL_POLYGON_OFFSET_FILL);

  glPopMatrix();

  glDisable(GL_CLIP_PLANE0);

  DrawCoordinateCross ();
  DrawNetgenLogo ();  

  glFinish();  

}


void VisualSceneGeometry :: BuildScene (int zoomall)
{
  int i, j, k;
  
  Box<3> box;
  int hasp = 0;
  for (i = 0; i < geometry->GetNTopLevelObjects(); i++)
    {
      const TriangleApproximation & ta =
	*geometry->GetTriApprox(i);
      if (!&ta) continue;

      for (j = 0; j < ta.GetNP(); j++)      
	{
	  if (hasp)
	    box.Add (ta.GetPoint(j));
	  else
	    {
	      hasp = 1;
	      box.Set (ta.GetPoint(j));
	    }
	}
    }
  if (hasp)
    {
      center = box.Center();
      rad = box.Diam() / 2;
    }
  else
    {
      center = Point3d(0,0,0);
      rad = 1;
    }

  CalcTransformationMatrices();

  for (i = 0; i < trilists.Size(); i++)
    glDeleteLists (trilists[i], 1);
  trilists.SetSize(0);

  for (i = 0; i < geometry->GetNTopLevelObjects(); i++)
    {
      trilists.Append (glGenLists (1));
      glNewList (trilists.Last(), GL_COMPILE);

      glEnable (GL_NORMALIZE);
      const TriangleApproximation & ta =
	*geometry->GetTriApprox(i);
      if (&ta) 
	{
	  glBegin (GL_TRIANGLES);
	  for (j = 0; j < ta.GetNT(); j++)
	    {
	      
	      for (k = 0; k < 3; k++)
		{
		  int pi = ta.GetTriangle(j)[k];
		  glNormal3f (ta.GetNormal (pi)(0),
			      ta.GetNormal (pi)(1),
			      ta.GetNormal (pi)(2));
		  glVertex3f (ta.GetPoint(pi)(0),
			      ta.GetPoint(pi)(1),
			      ta.GetPoint(pi)(2));
		}
	    }
	  glEnd ();
	}
      glEndList ();
    }

}





}
