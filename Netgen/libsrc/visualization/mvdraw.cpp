#include <mystdlib.h>
#include <myadt.hpp>
#include <meshing.hpp>
#include <csg.hpp>
#include <geometry2d.hpp>
#include <stlgeom.hpp>

#ifdef OCCGEOMETRY
#include <occgeom.hpp>
#include "TopoDS_Shape.hxx"
#include "TopoDS_Vertex.hxx"
#include "TopExp_Explorer.hxx"
#include "BRep_Tool.hxx"
#include "TopoDS.hxx"
#include "gp_Pnt.hxx"
#include "Geom_Curve.hxx"
#include "Poly_Triangulation.hxx"
#include "Poly_Array1OfTriangle.hxx"
#include "TColgp_Array1OfPnt2d.hxx"
#include "Poly_Triangle.hxx"
#include "BRepMesh.hxx"
#endif


#include "incvis.hpp"


#ifdef STEP
#include <stepgeom.hpp>
#endif

namespace netgen
{

#include "mvdraw.hpp"

Point3d VisualScene :: center;
double VisualScene :: rad;
double VisualScene :: backcolor;
GLuint VisualScene :: fontbase = 0;

// texture for color decoding
GLubyte * VisualScene :: colortexture = NULL;
GLuint VisualScene :: coltexname = 1;
int VisualScene :: ntexcols = -1;
  // bool VisualScene :: linear_colors = 1;

float VisualScene :: lookatmat[16];
float VisualScene :: transmat[16];
float VisualScene :: rotmat[16];
float VisualScene :: centermat[16];
float VisualScene :: transformationmat[16];



VisualizationParameters :: VisualizationParameters()
{
  lightamb = 0.3;
  lightdiff = 0.7;
  lightspec = 1;
  shininess = 50;
  transp = 0.3;
  locviewer = 0;
  showstltrias = 0;
  centerpoint = 0;
  usedispllists = 1;
  strcpy (selectvisual, "cross");
};
VisualizationParameters vispar;



double dist = 0;
  // double dist = 6;
// vorher: pnear = 2;
double pnear = 0.1;
double pfar = 10;



extern CSGeometry * geometry;
extern STLGeometry * stlgeometry;
extern SplineGeometry2d * geometry2d;

#ifdef OCCGEOMETRY
extern OCCGeometry * occgeometry;
#endif

#ifdef STEP
using STEP_AP203::STEPGeometry;
extern STEPGeometry * stepgeometry;
#endif // STEP
extern AutoPtr<Mesh> mesh;
extern ARRAY<SpecialPoint> specpoints;

//Tcl_Interp * hinterp;


VisualScene :: VisualScene ()
{
  changeval = -1;
  backcolor = 0;



}

VisualScene :: ~VisualScene()
{
  ;
}


void Render ()
{
  multithread.redraw = 1;
  //  while (multithread.redraw);
      //   Tcl_Eval (hinterp, ".ndraw render");
}

void VisualScene :: BuildScene (int zoomall)
{
  center = Point3d (0,0,0);
  rad = 1;

  CalcTransformationMatrices();

  glEnable(GL_DEPTH_TEST);
  glDisable (GL_DITHER);
  
  GLfloat ambvals[] = { 0.4f, 0.4f, 0.4f, 1.0f };
  GLfloat diffvals[] = { 0.5f, 0.5f, 0.5f, 1.0f };
  GLfloat specvals[] =  { 0.7f, 0.7f, 0.7f, 1.0f };
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambvals);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffvals);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specvals);
  
  GLfloat light_position[] = { 1, 3, 3, 0 };
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  
  glLightModeli (GL_LIGHT_MODEL_TWO_SIDE, 0);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}


void VisualScene :: DrawScene ()
{
  if (changeval == -1)
    BuildScene();
  changeval = 0;

  glClearColor(backcolor, backcolor, backcolor, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable (GL_COLOR_MATERIAL);
  glColor3f (1.0f, 1.0f, 1.0f);
  glLineWidth (1.0f);

  /*
  glPushMatrix();
  //  glLoadIdentity();
  glMultMatrixf (transformationmat);
  
  glBegin(GL_LINES);
  glVertex3f (0.0f, 0.0f, 0.0f);
  glVertex3f (1.0f, 0.0f, 0.0f);
  glVertex3f (0.0f, 0.0f, 0.0f);
  glVertex3f (0.0f, 1.0f, 0.0f);
  glVertex3f (0.0f, 0.0f, 0.0f);
  glVertex3f (0.0f, 0.0f, 1.0f);
  glEnd ();
  
  glPopMatrix();
  */

  DrawCoordinateCross ();
  DrawNetgenLogo ();
  glFinish();  
}


void VisualScene :: CalcTransformationMatrices()
{

  // prepare model view matrix
  
  glPushMatrix();

  glLoadIdentity();
  gluLookAt (0, 0, 6, 0, 0, 0, 0, 1, 0);
  glGetFloatv (GL_MODELVIEW_MATRIX, lookatmat);

  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -dist);
  glGetFloatv (GL_MODELVIEW_MATRIX, transmat);
  
  glLoadIdentity();
  glGetFloatv (GL_MODELVIEW_MATRIX, rotmat);

  glScalef (1/rad, 1/rad, 1/rad);
  glTranslated (-center.X(), -center.Y(), -center.Z());
  glGetFloatv (GL_MODELVIEW_MATRIX, centermat);

  glLoadIdentity();
  glMultMatrixf (lookatmat);
  glMultMatrixf (transmat);
  glMultMatrixf (rotmat);
  glMultMatrixf (centermat);
  glGetFloatv (GL_MODELVIEW_MATRIX, transformationmat);

  glPopMatrix();
}

void VisualScene :: StandardRotation (const char * dir)
{
  glPushMatrix();

  glLoadIdentity();
  
  if (strcmp (dir, "xy") == 0)
    ;
  else if (strcmp (dir, "yx") == 0)
    glRotatef(180.0, 1.0f, 1.0f, 0.0f);    
  else if (strcmp (dir, "xz") == 0)
    glRotatef(-90.0, 1.0f, 0.0f, 0.0f);    
  else if (strcmp (dir, "zx") == 0)
    {
      glRotatef(180.0, 1.0f, 1.0f, 0.0f);    
      glRotatef(-90.0, 1.0f, 0.0f, 0.0f);    
    }
  else if (strcmp (dir, "yz") == 0)
    {
      glRotatef(-90.0, 0.0f, 0.0f, 1.0f);    
      glRotatef(-90.0, 0.0f, 1.0f, 0.0f);    
    }
  else if (strcmp (dir, "zy") == 0)
    glRotatef(90.0, 0.0f, 1.0f, 0.0f);    
    

  glGetFloatv (GL_MODELVIEW_MATRIX, rotmat);

  glLoadIdentity();
  glMultMatrixf (lookatmat);
  glMultMatrixf (transmat);
  glMultMatrixf (rotmat);
  glMultMatrixf (centermat);
  glGetFloatv (GL_MODELVIEW_MATRIX, transformationmat);
  
  glPopMatrix();
}

void VisualScene :: MouseMove(int oldx, int oldy,
			      int newx, int newy,
			      char mode)
{
  int deltax = newx - oldx;
  int deltay = newy - oldy;
  
  glPushMatrix();
  glLoadIdentity ();
  
  switch (mode)
    {
    case 'r':
      {	
	glRotatef(float(deltax)/2, 0.0f, 1.0f, 0.0f);
	glRotatef(float(deltay)/2, 1.0f, 0.0f, 0.0f);
	glMultMatrixf (rotmat);
	glGetFloatv (GL_MODELVIEW_MATRIX, rotmat);
	break;
      }
    case 'm':
      {
	GLdouble projmat[16], modelviewmat[16];
	GLint viewport[4];
	glGetDoublev (GL_PROJECTION_MATRIX, projmat);
	glGetDoublev (GL_MODELVIEW_MATRIX, modelviewmat);
	glGetIntegerv (GL_VIEWPORT, viewport);
	
	// vorher pvz1/2 = 0
	GLdouble pvx1 = 0, pvy1 = 0, pvz1 = 0.95;
	GLdouble pvx2 = deltax, pvy2 = -deltay, pvz2 = 0.95;

	GLdouble px1, py1, pz1;
	GLdouble px2, py2, pz2;
	
	gluUnProject (pvx1, pvy1, pvz1, 
		      modelviewmat, projmat, viewport,
		      &px1, &py1, &pz1);
	gluUnProject (pvx2, pvy2, pvz2, 
		      modelviewmat, projmat, viewport,
		      &px2, &py2, &pz2);
	/*
	gluUnProject (oldx, oldy, 1, 
		      modelviewmat, projmat, viewport,
		      &px1, &py1, &pz1);
	gluUnProject (newx, newy, 1, 
		      modelviewmat, projmat, viewport,
		      &px2, &py2, &pz2);
	*/

	/*	
	cout << "pv1 = " << pvx1 << ", " << pvy1 << ", " << pvz1 << endl;
	cout << "p1 = " << px1 << ", " << py1 << ", " << pz1 << endl;
	*/

	glTranslated (px2-px1, py2-py1, pz2-pz1);
	
	glMultMatrixf (transmat);
	glGetFloatv (GL_MODELVIEW_MATRIX, transmat);
	break;
      }
    case 'z':
      {
	// glTranslatef(0.0f, 0.0f, -dist);
	glScaled (exp (float (-deltay)/100), 
		  exp (float (-deltay)/100), 
		  exp (float (-deltay)/100));
	// glTranslatef(0.0f, 0.0f, dist);
	glMultMatrixf (transmat);
	glGetFloatv (GL_MODELVIEW_MATRIX, transmat);
	break;
      }
    }

  glLoadIdentity();
  glMultMatrixf (lookatmat);
  glMultMatrixf (transmat);
  glMultMatrixf (rotmat);
  glMultMatrixf (centermat);
  glGetFloatv (GL_MODELVIEW_MATRIX, transformationmat);
  
  glPopMatrix();
}


void VisualScene :: LookAt (const Point<3> & cam, const Point<3> & obj,
			    const Point<3> & camup)
{
  glPushMatrix();
  glLoadIdentity ();
  gluLookAt (cam(0), cam(1), cam(2), 
	     obj(0), obj(1), obj(2),
	     camup(0), camup(1), camup(2));
  glMultMatrixf (centermat);
  glGetFloatv (GL_MODELVIEW_MATRIX, transformationmat);
  glPopMatrix();
}

  
void VisualScene :: SetClippingPlane ()
{
  if (vispar.clipenable)
    {
      Vec3d n = vispar.clipnormal;
      n /= (n.Length()+1e-10);
      clipplane[0] = n.X();
      clipplane[1] = n.Y();
      clipplane[2] = n.Z();
      clipplane[3] = -(Vec3d(center) * n) + rad * vispar.clipdist;

      glClipPlane(GL_CLIP_PLANE0, clipplane);
      glEnable(GL_CLIP_PLANE0);
    }
  else
    glDisable (GL_CLIP_PLANE0);
}




void VisualScene :: MouseDblClick (int px, int py)
{
  ;
}



void VisualScene :: SetLight()
{
  GLfloat vals[3];
  double lightamb = vispar.lightamb;
  vals[0] = vals[1] = vals[2] = lightamb;
  glLightfv(GL_LIGHT0, GL_AMBIENT, vals);

  double lightdiff = vispar.lightdiff;
  vals[0] = vals[1] = vals[2] = lightdiff;
  glLightfv(GL_LIGHT0, GL_DIFFUSE, vals);

  double lightspec = vispar.lightspec;
  vals[0] = vals[1] = vals[2] = lightspec;
  glLightfv(GL_LIGHT0, GL_SPECULAR, vals);

  glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, vispar.shininess);
  glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, vispar.locviewer);

  float mat_spec_col[] = { 1, 1, 1, 1 };
  glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec_col);

  glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT0);
}




void VisualScene :: SetOpenGlColor(double h, double hmin, double hmax,
				   int logscale)
{
  double value;

  if (!logscale)
    value = (h - hmin) / (hmax - hmin);
  else
    {
      if (hmax <= 0) hmax = 1;
      if (hmin <= 0) hmin = 1e-4 * hmax;
      value = (log(fabs(h)) - log(hmin)) / (log(hmax) - log(hmin));
    }

  if (!invcolor)
    value = 1 - value;

  glTexCoord1f ( 0.999 * value + 0.001);

  if (value > 1) value = 1;
  if (value < 0) value = 0;

  value *= 4;

  const double colp[][3] =
  {
    { 1, 0, 0 },
    { 1, 1, 0 },
    { 0, 1, 0 },
    { 0, 1, 1 },
    { 0, 0, 1 },
    { 1, 0, 1 },
    { 1, 0, 0 },
  };
  
  int i = int(value);
  double r = value - i;

  GLdouble col[3];
  int j;
  for (j = 0; j < 3; j++)
    col[j] = (1-r) * colp[i][j] + r * colp[i+1][j];
  
  glColor3d (col[0], col[1], col[2]);
}


void VisualScene :: CreateTexture (int ncols, int linear)
{
  int i;

  if (ncols < 2) ncols = 2;
  ncols = 8;

  if (ntexcols != ncols)
    {
      if (colortexture) 
	{
	  glDeleteTextures (1, &coltexname);
	  delete colortexture;
	}
      
      ntexcols = ncols;
      
      colortexture = new GLubyte[4*ncols+4];

      const double colp[][3] =
      {
	{ 1, 0, 0 },
	{ 1, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 1 },
	{ 0, 0, 1 },
	{ 1, 0, 1 },
	{ 1, 0, 0 },
      };
  
      for (i = 0; i < ncols; i++)
	{
	  double value = 4.0 * i / (ncols-1);

	  int iv = int(value);
	  double r = value - iv;

	  GLdouble col[3];
	  int j;
	  for (j = 0; j < 3; j++)
	    col[j] = (1-r) * colp[iv][j] + r * colp[iv+1][j];
	  
	  glColor3d (col[0], col[1], col[2]);

	  colortexture[4*i] = GLubyte (255 * col[0]);
	  colortexture[4*i+1] = GLubyte (255 * col[1]);
	  colortexture[4*i+2] = GLubyte (255 * col[2]);
	  colortexture[4*i+3] = GLubyte(255);
	}

      //      glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

      
      glGenTextures (1, &coltexname);


      glBindTexture (GL_TEXTURE_1D, coltexname);

      glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP);
      glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

      glTexImage1D (GL_TEXTURE_1D, 0, 4, ncols, 0, GL_RGBA, GL_UNSIGNED_BYTE, colortexture);
      glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
 
    }


  glBindTexture (GL_TEXTURE_1D, coltexname);
  if (linear)
    {
      glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
  else
    {
      glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
}




void VisualScene :: DrawColorBar (double minval, double maxval,
				  int logscale)
{
  int i;

  if (!vispar.drawcolorbar) return;

  CreateTexture (8, 1);

  if (logscale && maxval <= 0) maxval = 1;
  if (logscale && minval <= 0) minval = 1e-4 * maxval;


  double minx = -1;
  double maxx = 1;
  double miny = 0.75;
  double maxy = 0.8;
      
  double x;

  glEnable (GL_COLOR_MATERIAL);
  glEnable (GL_TEXTURE_1D);
  glNormal3d (0, 0, 1);

  glBegin (GL_LINES);
  for (x = minx; x <= maxx; x += (maxx - minx) / 1000)
    {
      SetOpenGlColor (x, minx, maxx);
      glVertex3d (x, miny,-5);
      glVertex3d (x, maxy,-5);
    }
  glEnd();

  glDisable (GL_TEXTURE_1D);

  glEnable (GL_COLOR_MATERIAL);
  GLfloat textcol[3] = { 1 - backcolor,
			 1 - backcolor,
			 1 - backcolor };
  glColor3fv (textcol);
  glPushAttrib (GL_LIST_BIT);
  glListBase (fontbase);

  char buf[20];
  for (i = 0; i <= 4; i++)
    {
      x = minx + i * (maxx-minx) / 4;
      glRasterPos3d (x, 0.7,-5);
      
      double val;
      if (logscale)
	val = minval * pow (maxval / minval, i / 4.0);
      else
	val = minval + i * (maxval-minval) / 4;

      sprintf (buf, "%8.3e", val);
      glCallLists (strlen (buf), GL_UNSIGNED_BYTE, buf);
    }

  glPopAttrib ();
}


void VisualScene :: DrawCoordinateCross ()
{
  if (!vispar.drawcoordinatecross) return;

  glMatrixMode (GL_PROJECTION); 
  glPushMatrix();
  glLoadIdentity();

  glMatrixMode (GL_MODELVIEW); 
  glPushMatrix();
  glLoadIdentity();

  GLint viewport[4];
  glGetIntegerv (GL_VIEWPORT, viewport);

  glTranslatef (-1, -1, 0.0);
  glScalef (40.0 / viewport[2], 40.0 / viewport[3], 1);
  glTranslatef (2.0, 2.0, 0.0);
  glMultMatrixf (rotmat);

  glEnable (GL_COLOR_MATERIAL);
  glDisable (GL_LIGHTING);

  GLfloat textcol[3] = { 1 - backcolor,
			 1 - backcolor,
			 1 - backcolor };
  glColor3fv (textcol);

  glLineWidth (1.0f);

  float len = 1;
  glBegin(GL_LINES);
  glVertex3f (0.0f, 0.0f, 0.0f);
  glVertex3f (len, 0.0f, 0.0f);
  glVertex3f (0.0f, 0.0f, 0.0f);
  glVertex3f (0.0f, len, 0.0f);
  glVertex3f (0.0f, 0.0f, 0.0f);
  glVertex3f (0.0f, 0.0f, len);
  glEnd ();


  glPushAttrib (GL_LIST_BIT);
  glListBase (fontbase);

  char buf[20];

  glRasterPos3d (len, 0.0f, 0.0f);
  sprintf (buf, "x");
  glCallLists (strlen (buf), GL_UNSIGNED_BYTE, buf);
  glRasterPos3d (0.0f, len, 0.0f);
  sprintf (buf, "y");
  glCallLists (strlen (buf), GL_UNSIGNED_BYTE, buf);
  glRasterPos3d (0.0f, 0.0f, len);
  sprintf (buf, "z");
  glCallLists (strlen (buf), GL_UNSIGNED_BYTE, buf);

  glPopAttrib ();
  glEnable (GL_LIGHTING);

  glMatrixMode (GL_PROJECTION); 
  glPopMatrix();
  glMatrixMode (GL_MODELVIEW); 
  glPopMatrix();
}


void VisualScene :: DrawNetgenLogo ()
{
  if (!vispar.drawnetgenlogo) return;

  glMatrixMode (GL_PROJECTION); 
  glPushMatrix();
  glLoadIdentity();

  glMatrixMode (GL_MODELVIEW); 
  glPushMatrix();
  glLoadIdentity();

  GLint viewport[4];
  glGetIntegerv (GL_VIEWPORT, viewport);



  glTranslatef (1, -1, 0.0);
  glScalef (40.0 / viewport[2], 40.0 / viewport[3], 1);
  glTranslatef (-6.0, 2.0, 0.0);
  //  glMultMatrixf (rotmat);

  glEnable (GL_COLOR_MATERIAL);
  GLfloat textcol[3] = { 1 - backcolor,
			 1 - backcolor,
			 1 - backcolor };
  glColor3fv (textcol);

  glLineWidth (1.0f);

  glPushAttrib (GL_LIST_BIT);
  glListBase (fontbase);

  char buf[20];

  glRasterPos3d (0.0f, 0.0f, 0.0f);
  sprintf (buf, "Netgen 4.3.1");
  glCallLists (strlen (buf), GL_UNSIGNED_BYTE, buf);
  glPopAttrib ();

  glMatrixMode (GL_PROJECTION); 
  glPopMatrix();
  glMatrixMode (GL_MODELVIEW); 
  glPopMatrix();
}








VisualSceneGeometry2d :: VisualSceneGeometry2d ()
  : VisualScene()
{
  ;
}

VisualSceneGeometry2d :: ~VisualSceneGeometry2d ()
{
  ;
}






void VisualSceneGeometry2d :: DrawScene ()
{
  int i, j;

  if (changeval != geometry2d->GetSplines().Size())
    BuildScene();
  changeval = geometry2d->GetSplines().Size();

  
  glClearColor(backcolor, backcolor, backcolor, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  SetLight();

  //  glEnable (GL_LIGHT0);
  glDisable (GL_LIGHTING);
  glPushMatrix();
  glMultMatrixf (transformationmat);

  //  SetClippingPlane ();

  glShadeModel (GL_SMOOTH);
  glEnable (GL_COLOR_MATERIAL);
  glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
  
  //  float mat_col[] = { 0, 0, 1, 1 };
  //  glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_col);
  glColor3f (0, 0, 1);
  

  ARRAY<Point<2> > points, otherpoints;

  for (i = 1; i <= geometry2d->GetSplines().Size(); i++)
    {
      geometry2d->GetSplines().Get(i)->GetPoints (20, points);
      
      glBegin (GL_LINE_STRIP);
      for (j = 0; j < points.Size(); j++)
	glVertex3f (points[j](0), points[j](1), 0);
      glEnd(); 
    }

  glColor3f (1, 0, 0);

  for (i = 1; i <= geometry2d->GetSplines().Size(); i++)
    {
      int other = geometry2d->GetSplines().Get(i)->copyfrom;
      if (other != -1)
	{
	  geometry2d->GetSplines().Get(i)->GetPoints (6, points);
	  geometry2d->GetSplines().Get(other)->GetPoints (6, otherpoints);
	  glBegin (GL_LINES);
	  for (j = 1; j < 5; j++)
	    {
	      glVertex3f (points[j](0), points[j](1), 0);
	      glVertex3f (otherpoints[j](0), otherpoints[j](1), 0);
	    }
	  glEnd ();
	}
    }



  glPopMatrix();
  
  DrawCoordinateCross ();
  DrawNetgenLogo ();

  glFinish();  
}


void VisualSceneGeometry2d :: BuildScene (int zoomall)
{
  Box<2> bbox;

  geometry2d->GetBoundingBox (bbox);
  
  Point<2> c = Center (bbox.PMin(), bbox.PMax());

  center = Point3d (c(0), c(1), 0);
  rad = Dist (bbox.PMin(), bbox.PMax()) / 2;

  CalcTransformationMatrices();
}










/* *********************** Draw STL Geometry **************** */


VisualSceneSTLGeometry :: VisualSceneSTLGeometry ()
  : VisualScene()
{
  ;
}

VisualSceneSTLGeometry :: ~VisualSceneSTLGeometry ()
{
  ;
}

void VisualSceneSTLGeometry :: DrawScene ()
{
  int i, j, k;

  if (changeval != stlgeometry->GetNT())
    BuildScene();

  changeval = stlgeometry->GetNT();


  glClearColor(backcolor, backcolor, backcolor, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  SetLight();


  glPushMatrix();
  glMultMatrixf (transformationmat);




  glShadeModel (GL_SMOOTH);
  glDisable (GL_COLOR_MATERIAL);
  glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


  double shine = vispar.shininess;
  double transp = vispar.transp;

  glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, shine);
  glLogicOp (GL_COPY);


  float mat_col[] = { 0.2, 0.2, 0.8, 1 };
  glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_col);

  glPolygonOffset (1, 1);
  glEnable (GL_POLYGON_OFFSET_FILL);

  glCallList (trilists.Get(1));

  glDisable (GL_POLYGON_OFFSET_FILL);


  int showtrias = vispar.showstltrias;

  if (showtrias)
    {
      float mat_coll[] = { 0.2, 0.2, 0.2, 1 };
      glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_coll);
      glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
      
      glCallList (trilists.Get(1));
    }

  /*

  glBegin (GL_TRIANGLES);
  for (j = 1; j <= stlgeometry -> GetNT(); j++)
    {
      const STLTriangle & tria = stlgeometry -> GetTriangle(j);
      glNormal3f (tria.normal.X(),
		  tria.normal.Y(),
		  tria.normal.Z());
		  
      for (k = 0; k < 3; k++)
	{
	  glVertex3f (tria.pts[k].X(),
		      tria.pts[k].Y(),
		      tria.pts[k].Z());
	}
    }    
  glEnd ();
  */  



 
  glPopMatrix();
  glFinish();  
}


void VisualSceneSTLGeometry :: BuildScene (int zoomall)
{
  int i, j, k;
  
  // cout << "rebuild stl geometry scene" << endl;

  center = stlgeometry -> GetBoundingBox().Center();
  rad = stlgeometry -> GetBoundingBox().Diam() / 2;


  CalcTransformationMatrices();

  for (i = 1; i <= trilists.Size(); i++)
    glDeleteLists (trilists.Elem(i), 1);
  trilists.SetSize(0);


  trilists.Append (glGenLists (1));
  glNewList (trilists.Last(), GL_COMPILE);

  glEnable (GL_NORMALIZE);


  glBegin (GL_TRIANGLES);
  for (j = 1; j <= stlgeometry -> GetNT(); j++)
    {
      const Vec3d & n = stlgeometry->GetTriangle(j).Normal();
      glNormal3f (n.X(), n.Y(), n.Z());
      
      for (k = 1; k <= 3; k++)
	{
	  const Point3d & p = 
	    stlgeometry->GetPoint (stlgeometry -> GetTriangle(j).PNum(k));
	  glVertex3f (p.X(),p.Y(), p.Z());
 
	  //	  int pi = ta.GetTriangle(j).PNum(k);
	  //	  glNormal3f (ta.GetNormal (pi).X(),
	  //	      ta.GetNormal (pi).Y(),
	  //	      ta.GetNormal (pi).Z());
	  //	  glVertex3f (ta.GetPoint(pi).X(),
	  //	      ta.GetPoint(pi).Y(),
	  //	      ta.GetPoint(pi).Z());
	}
    }    
  glEnd ();
      
  glEndList ();
}



#ifdef OCCGEOMETRY
/* *********************** Draw OCC Geometry **************** */


VisualSceneOCCGeometry :: VisualSceneOCCGeometry ()
  : VisualScene()
{
  trilists.SetSize(0);
  linelists.SetSize(1);
}

VisualSceneOCCGeometry :: ~VisualSceneOCCGeometry ()
{
  ;
}

void VisualSceneOCCGeometry :: DrawScene ()
{
  int i, j, k;


  if ( occgeometry->changed )
    {
      BuildScene();
      occgeometry -> changed = 0;
    }

  glClearColor(backcolor, backcolor, backcolor, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  SetLight();

  //  glEnable (GL_COLOR_MATERIAL);

  //  glDisable (GL_SHADING);
  //  glColor3f (0.0f, 1.0f, 1.0f);
  //  glLineWidth (1.0f);
  //  glShadeModel (GL_SMOOTH);

  //  glCallList (linelists.Get(1));

  //  SetLight();

  glPushMatrix();
  glMultMatrixf (transformationmat);

  glShadeModel (GL_SMOOTH);
  glDisable (GL_COLOR_MATERIAL);
  glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  //  glEnable (GL_LIGHTING);

  double shine = vispar.shininess;
  double transp = vispar.transp;

  glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, shine);
  glLogicOp (GL_COPY);


  float mat_col[] = { 0.2, 0.2, 0.8, 1 };
  glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_col);

  glPolygonOffset (1, 1);
  glEnable (GL_POLYGON_OFFSET_FILL);

  glCallList (linelists.Get(1));

  glDisable (GL_POLYGON_OFFSET_FILL);
 
  glPopMatrix();
  DrawCoordinateCross ();
  DrawNetgenLogo ();
  glFinish();  

  glDisable (GL_POLYGON_OFFSET_FILL);

}


void VisualSceneOCCGeometry :: BuildScene (int zoomall)
{
  int i = 0, j, k;
  
  Box3d box;

  TopExp_Explorer ex, ex_edge;

  for (ex.Init(occgeometry -> shape, TopAbs_VERTEX); ex.More(); ex.Next())
    {
      i++;
      gp_Pnt p = BRep_Tool::Pnt (TopoDS::Vertex(ex.Current()));

      if (i == 1) 
	box.SetPoint (Point<3>(p.X(), p.Y(), p.Z()));
      else
	box.AddPoint (Point<3>(p.X(), p.Y(), p.Z()));
    }

  center = box.CalcCenter();
  rad = box.CalcDiam() / 2;
  
  CalcTransformationMatrices();


  linelists.Elem(1) = glGenLists (1);
  glNewList (linelists.Last(), GL_COMPILE);

  for (ex_edge.Init(occgeometry -> shape, TopAbs_EDGE);
       ex_edge.More(); ex_edge.Next())
    {
      if (BRep_Tool::Degenerated(TopoDS::Edge(ex_edge.Current()))) continue;

      glBegin (GL_LINE_STRIP);

      double s0, s1, s;
      Handle(Geom_Curve) c = BRep_Tool::Curve(TopoDS::Edge(ex_edge.Current()), s0, s1);
      double d = s1-s0;
      int i;
      
      for (i = 0; i<=50; i++)
	{
	  s = s0 + i*d/50;
	  gp_Pnt p = c->Value (s);
	  glVertex3f (p.X(),p.Y(), p.Z());
	}

      glEnd ();
    }

  //    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

  glBegin (GL_TRIANGLES);
  //  int nfaces = occgeometry -> fmap.Extent();

  i = 0;

  TopExp_Explorer exp0, exp1, exp2, exp3;

  //  BRepMesh::Mesh (occgeometry -> shape, occgeometry -> MaxSize()/100);

  for (exp0.Init(occgeometry -> shape, TopAbs_SOLID); exp0.More(); exp0.Next())
    for (exp1.Init(exp0.Current(), TopAbs_SHELL); exp1.More(); exp1.Next())
      for (exp2.Init(exp1.Current().Composed(exp0.Current().Orientation()), TopAbs_FACE); exp2.More(); exp2.Next())
	{
	  TopoDS_Face face = TopoDS::Face (exp2.Current().Composed(exp1.Current().Orientation()));

	  TopLoc_Location loc;
	  Handle(Geom_Surface) surf = BRep_Tool::Surface (face);
	  BRepAdaptor_Surface sf(face, Standard_False);
	  BRepLProp_SLProps prop(sf, 1, 1e-5);

	  //	  BRepMesh::Mesh (face, 1e-3);
	  (*testout) << "meshing face " << ++i << endl;
	  {
	    int edges = 0;
	    for (exp3.Init (face, TopAbs_EDGE); exp3.More(); exp3.Next())
	      {
		edges++;
		(*testout) << "edge " << edges;
		if (BRep_Tool::Degenerated(TopoDS::Edge(exp3.Current())))
		  (*testout) << " degenerated";
		(*testout) << endl;
	      }
	  }
	  BRepMesh::Mesh (face, occgeometry -> MaxSize()/100);
	  (*testout) << "done" << endl;
	  //	  cout << "Warning: mvdraw fixed meshing size for visualization" << endl;
	  // cout << "face " << ++i << endl;

	  Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation (face, loc);
	  if (!triangulation) continue;
	  
	  int ntriangles = triangulation -> NbTriangles();
	  //	  cout << "nbtriangles = " << ntriangles << endl;
	  for (j = 1; j <= ntriangles; j++)
	    {
	      // (*testout) << "drawing trig " << j << "/" << ntriangles << " " << flush;
	      //	      cout << "j = " << j << endl;
	      Poly_Triangle triangle = (triangulation -> Triangles())(j);
	      for (k = 1; k <= 3; k++)
		{
		  (*testout) << "." << flush;
		  gp_Pnt2d uv = (triangulation -> UVNodes())(triangle(k));
		  gp_Pnt pnt;
		  gp_Vec du, dv;
		  prop.SetParameters (uv.X(), uv.Y());
		  surf->D0 (uv.X(), uv.Y(), pnt);
		  gp_Vec n;

		  if (prop.IsNormalDefined())
		    {
		      n = prop.Normal();
		    }
		  else
		    n = gp_Vec (0,0,0);


		  //		  surf->D1 (uv.X(), uv.Y(), pnt, du, dv);
		  //		  gp_Vec n = du.Crossed(dv).Normalized();
		  if (face.Orientation() == TopAbs_REVERSED) n *= -1;
		  glNormal3f (n.X(), n.Y(), n.Z());
		  glVertex3f (pnt.X(), pnt.Y(), pnt.Z());
		}
	      (*testout) << endl;
	    }
	}
  
  glEnd ();



  glEndList ();

}

#endif



#ifdef STEP

/* *********************** Draw STEP Geometry **************** */


VisualSceneSTEPGeometry :: VisualSceneSTEPGeometry ()
  : VisualScene ()
{
  gllists.SetSize(0);
}


VisualSceneSTEPGeometry :: ~VisualSceneSTEPGeometry ()
{
  cout << "VisualSceneSTEPGeometry::~VisualSceneSTEPGeometry called "
       << "but not implemented" << endl;
}
  

void VisualSceneSTEPGeometry :: BuildScene (int zoomall)
{
  cout << "VisualSceneSTEPGeometry::BuildScene called" << endl;

  const VisualApproximation & visapprox = 
    stepgeometry->GetVisualApproximation();

  INDEX i, k, pi;

  Box3d box;
  int hasp = 0;

  for (i = 1; i <= visapprox.GetNP(); i++)      
    {
      if (hasp)
	box.AddPoint (visapprox.GetPoint(i));
      else
	{
	  hasp = 1;
	  box.SetPoint (visapprox.GetPoint(i));
	}
    }
  if (hasp)
    {
      center = box.CalcCenter();
      rad = box.CalcDiam() / 2;
    }

  cout << "center " << center << endl
       << "radius " << rad << endl;

  CalcTransformationMatrices();

  for (i = 1; i <= gllists.Size(); i++)
    glDeleteLists (gllists.Elem(i), 1);
  gllists.SetSize(0);

  // build list of points
  gllists.Append (glGenLists (1));
  glNewList (gllists.Last(), GL_COMPILE);
   
  glPointSize( 3.0 );

  glBegin( GL_POINTS );
    for (i = 1; i <= visapprox.GetNP(); i++)
      {
	const Point3d & p = visapprox.GetPoint(i);
        glVertex3f( p.X(), p.Y(), p.Z());
      }
  glEnd();

  glEndList();

  // build list of segments
  gllists.Append (glGenLists (1));
  glNewList (gllists.Last(), GL_COMPILE);
   
  glLineWidth( 1.0f );

  glBegin(GL_LINES);
    for (i = 1; i <= visapprox.GetNSeg(); i++)
      {
	for (k = 1; k <= 2; k++)
	  {
	    pi = visapprox.GetSegment(i).PNum(k);
	    glVertex3f(visapprox.GetPoint(pi).X(),
		       visapprox.GetPoint(pi).Y(),
		       visapprox.GetPoint(pi).Z());
	  }
      }    
  glEnd();

  glEndList();
}


void VisualSceneSTEPGeometry :: DrawScene ()
{
  if (! stepgeometry)
    {
      cerr << "VisualSceneSTEPGeometry::DrawScene: no STEP geometry" << endl;
      return;
    }

  const VisualApproximation & visapprox = 
    stepgeometry -> GetVisualApproximation();
  if (changeval != visapprox.GetNP())
    BuildScene();

  changeval = visapprox.GetNP();

  glClearColor(backcolor, backcolor, backcolor, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  glMultMatrixf (transformationmat);

  // draw segments
//   float mat_coll[] = { 0.2, 0.2, 0.2, 1 };
//   glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_coll);
//   glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

  glEnable (GL_COLOR_MATERIAL);
  glColor3f(0.0, 1.0, 0.0);
  glCallList (gllists.Get(2));
  glColor3f (1.0, 0.0, 0.0);
  glCallList (gllists.Get(1));

  glPopMatrix();
  glFinish();
}

#endif










VisualSceneSpecPoints :: VisualSceneSpecPoints ()
  : VisualScene()
{
  ;
}

VisualSceneSpecPoints :: ~VisualSceneSpecPoints ()
{
  ;
}


void VisualSceneSpecPoints :: DrawScene ()
{
  int i, j, k;


  if (!mesh) 
    {
      VisualScene::DrawScene();
      return;
    }

  if (changeval != specpoints.Size())
    BuildScene();
  changeval = specpoints.Size();



  glClearColor(backcolor, backcolor, backcolor, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable (GL_COLOR_MATERIAL);
  glColor3f (1.0f, 1.0f, 1.0f);
  glLineWidth (1.0f);

  glPushMatrix();
  glMultMatrixf (transformationmat);

  //  glEnable (GL_COLOR);
  //  glDisable (GL_COLOR_MATERIAL);
  if (vispar.drawedtangents)
    {
      glColor3d (1, 0, 0);
      glBegin (GL_LINES);
      for (i = 1; i <= specpoints.Size(); i++)
	{
	  const Point3d p1 = specpoints.Get(i).p;
	  const Point3d p2 = specpoints.Get(i).p + len * specpoints.Get(i).v;
	  glVertex3d (p1.X(), p1.Y(), p1.Z());
	  glVertex3d (p2.X(), p2.Y(), p2.Z());
	}
      glEnd();
    }

  if (vispar.drawededges)
    {
      glColor3d (1, 0, 0);
      glBegin (GL_LINES);
      for (i = 1; i <= mesh->GetNSeg(); i++)
	{
	  const Segment & seg = mesh -> LineSegment (i);
	  const Point3d p1 = mesh -> Point (seg.p1);
	  const Point3d p2 = mesh -> Point (seg.p2);
	  glVertex3d (p1.X(), p1.Y(), p1.Z());
	  glVertex3d (p2.X(), p2.Y(), p2.Z());
	}
      glEnd();
    }

  if (vispar.drawededgenrs)
    {
      glEnable (GL_COLOR_MATERIAL);
      GLfloat textcol[3] = { 1 - backcolor,
			       1 - backcolor,
			       1 - backcolor };
      glColor3fv (textcol);
      glNormal3d (0, 0, 1);
      glPushAttrib (GL_LIST_BIT);
      glListBase (fontbase);

      char buf[20];
      for (i = 1; i <= mesh->GetNSeg(); i++)
	{
	  const Segment & seg = mesh -> LineSegment (i);
	  const Point3d p1 = mesh -> Point (seg.p1);
	  const Point3d p2 = mesh -> Point (seg.p2);

	  const Point3d p = Center (p1, p2);
	  glRasterPos3d (p.X(), p.Y(), p.Z());
	  
	  sprintf (buf, "%d", seg.edgenr);
	  glCallLists (strlen (buf), GL_UNSIGNED_BYTE, buf);
	}
      
      glPopAttrib ();
      glDisable (GL_COLOR_MATERIAL);
    }


  if (vispar.drawedpoints)
    {
      glColor3d (0, 0, 1);
      glPointSize( 3.0 );

      glBegin( GL_POINTS );
      for (i = 1; i <= mesh -> GetNP(); i++)
	{
	  const Point3d & p = mesh -> Point(i);
	  glVertex3f( p.X(), p.Y(), p.Z());
	}
      glEnd();
    }

  if (vispar.drawedpointnrs)
    {
      glEnable (GL_COLOR_MATERIAL);
      GLfloat textcol[3] = { 1 - backcolor,
			       1 - backcolor,
			       1 - backcolor };
      glColor3fv (textcol);
      glNormal3d (0, 0, 1);
      glPushAttrib (GL_LIST_BIT);
      glListBase (fontbase);
      
      char buf[20];
      for (i = 1; i <= mesh->GetNP(); i++)
	{
	  const Point3d & p = mesh->Point(i);
	  glRasterPos3d (p.X(), p.Y(), p.Z());
	  
	  sprintf (buf, "%d", i);
	  glCallLists (strlen (buf), GL_UNSIGNED_BYTE, buf);
	}
      
      glPopAttrib ();
      glDisable (GL_COLOR_MATERIAL);
    }


  glPopMatrix();

  if (vispar.drawcoordinatecross)
    DrawCoordinateCross ();
  DrawNetgenLogo ();

  glFinish();  
}


void VisualSceneSpecPoints :: BuildScene (int zoomall)
{
  int i, j, k;
  
  if (!mesh) 
    {
      VisualScene::BuildScene(zoomall);
      return;
    }

  Box3d box;

  if (mesh->GetNSeg())
    {
      box.SetPoint (mesh->Point (mesh->LineSegment(1).p1));
      for (i = 1; i <= mesh->GetNSeg(); i++)
	{
	  box.AddPoint (mesh->Point (mesh->LineSegment(i).p1));
	  box.AddPoint (mesh->Point (mesh->LineSegment(i).p2));
	}
    }
  else if (specpoints.Size() >= 2)
    {
      box.SetPoint (specpoints.Get(1).p);
      for (i = 2; i <= specpoints.Size(); i++)
	box.AddPoint (specpoints.Get(i).p);
    }
  else
    {
      box = Box3d (Point3d (0,0,0), Point3d (1,1,1));
    }
  
  if (zoomall == 2 && vispar.centerpoint >= 1 && vispar.centerpoint <= mesh->GetNP())
    center = mesh->Point (vispar.centerpoint);
  else
    center = Center (box.PMin(), box.PMax());

  rad = 0.5 * Dist (box.PMin(), box.PMax());
  

  CalcTransformationMatrices();
}

}
