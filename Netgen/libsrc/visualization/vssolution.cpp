#include <mystdlib.h>
#include "incvis.hpp"


#include <myadt.hpp>
#include <meshing.hpp>
#include <csg.hpp>
#include <stlgeom.hpp>

#include <visual.hpp>


namespace netgen
{

  extern AutoPtr<Mesh> mesh;

  
  VisualSceneSolution :: VisualSceneSolution ()
    : VisualScene()
  {
    surfellist = 0;
    linelist = 0;
    clipplanelist = 0;
    isolinelist = 0;
    surface_vector_list = 0;
    cone_list = 0;

    surfeltimestamp = GetTimeStamp();
    clipplanetimestamp = GetTimeStamp();
    solutiontimestamp = GetTimeStamp();
    fieldlinestimestamp = GetTimeStamp();
    surface_vector_timestamp = GetTimeStamp();
    AddVisualizationScene ("solution", &vssolution);
  }
  
  VisualSceneSolution :: ~VisualSceneSolution ()
  {
    ;
  }

  void VisualSceneSolution :: AddSolutionData (SolData * sd)
  {
    int i, funcnr = -1;
    
    for (i = 0; i < soldata.Size(); i++)
      {
	if (strcmp (soldata[i]->name, sd->name) == 0)
	  {
	    soldata[i] = sd;
	    funcnr = i;
	    break;
	  }
      }
    if (funcnr == -1)
      {
	soldata.Append (sd);
	funcnr = soldata.Size()-1;
      }
    
    SolData * nsd = soldata[funcnr];

    nsd->size = 0;
    if (mesh)
      {
	switch (nsd->soltype)
	  {
	  case SOL_NODAL: nsd->size = mesh->GetNV(); break;
	  case SOL_ELEMENT: nsd->size = mesh->GetNE(); break;
	  case SOL_SURFACE_ELEMENT: nsd->size = mesh->GetNSE(); break;
	  case SOL_NONCONTINUOUS: 
	    {
	      switch (nsd->order)
		{
		case 0: nsd->size =      mesh->GetNE(); break;
		case 1: nsd->size =  6 * mesh->GetNE(); break;
		case 2: nsd->size = 18 * mesh->GetNE(); break;
		}
	      break;
	    }
	  case SOL_SURFACE_NONCONTINUOUS: 
	    {
	      switch (nsd->order)
		{
		case 0: nsd->size =     mesh->GetNSE(); break;
		case 1: nsd->size = 4 * mesh->GetNSE(); break;
		case 2: nsd->size = 9 * mesh->GetNSE(); break;
		}
	      break;
	    }
	  }
	solutiontimestamp = NextTimeStamp();
      }
    
    /*
      (*testout) << "set sol-data " << nsd->name
      << ", size = " << nsd->size << endl;
      if (nsd->data)
      for (i = 0; i < nsd->size; i++)
      (*testout) << i << ": " << nsd->data[i] << endl;
    */
  }
  
  void VisualSceneSolution :: ClearSolutionData ()
  {
    soldata.SetSize (0);
  }

  void VisualSceneSolution :: UpdateSolutionTimeStamp ()
  {
    solutiontimestamp = NextTimeStamp();
  }
  

    
  VisualSceneSolution::SolData * VisualSceneSolution :: GetSolData (int i)
  { 
    if (i >= 0 && i < soldata.Size())
      return soldata[i];
    else 
      return NULL;
  }
  



  void VisualSceneSolution :: SaveSolutionData (const char * filename)
  {
    PrintMessage (1, "Write solution data to file ", filename);
    int i, j, k;

    ofstream ost(filename);
    for (i = 0; i < soldata.Size(); i++)
    {
      const SolData & sol = *soldata[i];
      
      ost << "solution " 
	  << sol.name
	  << " -size=" << sol.size 
	  << " -components=" << sol.components
	  << " -order=" << sol.order;
      if (sol.iscomplex)
	ost << " -complex";
      
      switch (sol.soltype)
	{
	case SOL_NODAL:
	  ost << " -type=nodal"; break;
	case SOL_ELEMENT:
	  ost << " -type=element"; break;
	case SOL_SURFACE_ELEMENT:
	  ost << " -type=surfaceelement"; break;
	case SOL_NONCONTINUOUS:
	  ost << " -type=noncontinuous"; break;
	case SOL_SURFACE_NONCONTINUOUS:
	  ost << " -type=surfacenoncontinuous"; break;
	}
      
      ost << endl;
      for (j = 0; j < sol.size; j++)
	{
	  for (k = 0; k < sol.components; k++)
	    ost << sol.data[j*sol.dist+k] << " ";
	  ost << "\n";
	}
    }
  }
  



  void VisualSceneSolution :: DrawScene ()
  {
    /*
    if (multithread.running) 
      {
	VisualScene::DrawScene();      
	return;
      }
    */
    int i, j, k;
    
    if (!mesh) 
      {
	VisualScene::DrawScene();      
	return;
      }

    static NgLock mem_lock(mem_mutex);
    mem_lock.Lock();

    /*    
    lock = NULL;
    if (!lock)
      {
	lock = new NgLock (mesh->Mutex());
	lock -> Lock();
      }
    */

    BuildScene();

    // either continuous, or discrete coloring
    CreateTexture (numtexturecols, lineartexture);

    glClearColor(backcolor, backcolor, backcolor, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    SetLight();
    
    glPushMatrix();
    glMultMatrixf (transformationmat);

  

    glMatrixMode (GL_MODELVIEW); 
    
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    
    glPolygonOffset (1, 1);
    glEnable (GL_POLYGON_OFFSET_FILL);

    glEnable (GL_COLOR_MATERIAL);


    if (usetexture)
      glEnable (GL_TEXTURE_1D);


    if (vispar.drawfilledtrigs)
      {
	SetClippingPlane ();
	
	glCallList (surfellist);
	glCallList (surface_vector_list);
      
	glDisable(GL_CLIP_PLANE0);
      }

    if (showclipsolution)
      glCallList (clipplanelist);
  

    if (draw_fieldlines)
      {
	BuildFieldLinesPlot ();

	if (num_fieldlineslists <= 1)
	  glCallList (fieldlineslist);
	else
	  {
	    int start = int (time / 10 * num_fieldlineslists);
	    for (int ln = 0; ln < 10; ln++)
	      {
		int nr = fieldlineslist + (start + ln) % num_fieldlineslists;
		glCallList (nr);
	      }
	  }
      }

    if (usetexture)
      glDisable (GL_TEXTURE_1D);



    glDisable (GL_POLYGON_OFFSET_FILL);
    
    glDisable (GL_COLOR_MATERIAL);
    
    
    GLfloat matcol0[] = { 0, 0, 0, 1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matcol0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, matcol0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matcol0);
    
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth (1.0f);
    glColor3f (0.0f, 0.0f, 0.0f);
    glDisable (GL_LINE_SMOOTH);
    
    if (vispar.drawoutline || numisolines)
      {
	SetClippingPlane ();
	
	if (numisolines)
	  {
	    glCallList (isolinelist);
	  }
	else
	  {
	    glCallList (linelist);
	  }
	
	glDisable(GL_CLIP_PLANE0);
      }
    
   

    glPopMatrix();
    
    glDisable(GL_CLIP_PLANE0);
    DrawColorBar (minval, maxval, logscale);
    
    if (vispar.drawcoordinatecross)
      DrawCoordinateCross ();
    DrawNetgenLogo ();
    
    glFinish();  
    
    /*
    if (lock)
      {
	lock -> UnLock();
	delete lock;
      }
    */
    mem_lock.UnLock();
  }
  


  static void RealVec3d (const double * values, Vec3d & v, 
		  bool iscomplex, bool imag)
  {
    if (!iscomplex)
      {
	v.X() = values[0];
	v.Y() = values[1];
	v.Z() = values[2];
      }
    else
      {
	if (!imag)
	  {
	    v.X() = values[0];
	    v.Y() = values[2];
	    v.Z() = values[4];
	  }
	else
	  {
	    v.X() = values[1];
	    v.Y() = values[3];
	    v.Z() = values[5];
	  }
      }
  }


  static void RealVec3d (const double * values, Vec3d & v, 
			 bool iscomplex, double phaser, double phasei)
  {
    if (!iscomplex)
      {
	v.X() = values[0];
	v.Y() = values[1];
	v.Z() = values[2];
      }
    else
      {
	for (int i = 0; i < 3; i++)
	  v.X(i+1) = phaser * values[2*i] + phasei * values[2*i+1];
      }
  }


  

  void VisualSceneSolution :: BuildScene (int zoomall)
  {
    int i, j, k;
 
    if (!mesh)
      {
	VisualScene::BuildScene (zoomall);
	return;
      }
    
    if (!cone_list)
      {
	cone_list = glGenLists (1);
	glNewList (cone_list, GL_COMPILE);
	DrawCone (Point<3> (0,0,0), Point<3> (0,0,1), 0.4);
	glEndList();
      }



    
    vispar.colormeshsize = 1;
    
    // recalc clipping plane
    SetClippingPlane ();
    glDisable(GL_CLIP_PLANE0);
    
    
    const SolData * sol = NULL;
    const SolData * vsol = NULL;
  
    if (scalfunction != -1) 
      sol = soldata[scalfunction];
    if (vecfunction != -1)
      vsol = soldata[vecfunction];
    
  if (mesh->GetTimeStamp () > solutiontimestamp)
    {
      sol = NULL;
      vsol = NULL;
    }

  if (!autoscale || scalfunction == -1)
    {
      minval = mminval;
      maxval = mmaxval;
    }
  else
    {
      if (mesh->GetTimeStamp () > surfeltimestamp ||
	  vispar.clipplanetimestamp > clipplanetimestamp ||
	  solutiontimestamp > surfeltimestamp)
	{
	  GetMinMax (scalfunction, scalcomp, minval, maxval);
	}
    }
 

  if (mesh->GetTimeStamp() > surfeltimestamp ||
      solutiontimestamp > surfeltimestamp ||
      zoomall)
    {
      if (mesh->GetTimeStamp() > surfeltimestamp ||
	  zoomall)
	{
	  // mesh has changed
	  
	  Point3d pmin, pmax;
	  static double oldrad = 0;
	  
	  mesh->GetBox (pmin, pmax, -1);
	  center = Center (pmin, pmax);
	  rad = 0.5 * Dist (pmin, pmax);
	  
	  glEnable (GL_NORMALIZE);
	  
	  if (rad > 1.5 * oldrad ||
	      mesh->GetMajorTimeStamp() > surfeltimestamp ||
	      zoomall)
	    {
	      CalcTransformationMatrices();
	      oldrad = rad;
	    }
	}

      
      if (surfellist)
	glDeleteLists (surfellist, 1);
      
      surfellist = glGenLists (1);
      glNewList (surfellist, GL_COMPILE);
      
      DrawSurfaceElements();
      
      glEndList ();
      
      
      if (linelist)
	glDeleteLists (linelist, 1);
      
      linelist = glGenLists (1);
      glNewList (linelist, GL_COMPILE);
      
      DrawSurfaceElementLines();
      
      glEndList ();

      surfeltimestamp = max2 (solutiontimestamp, mesh->GetTimeStamp());

      //      cout << "minval = " << minval << " maxval = " << maxval << endl;
    }
  


  
  if (mesh->GetTimeStamp() > surface_vector_timestamp ||
      solutiontimestamp > surface_vector_timestamp ||
      zoomall)
    {
      if (surface_vector_list)
	glDeleteLists (surface_vector_list, 1);
      
      surface_vector_list = glGenLists (1);
      glNewList (surface_vector_list, GL_COMPILE);

      glEnable (GL_NORMALIZE);
      DrawSurfaceVectors();

      glEndList ();

      surface_vector_timestamp = 
	max2 (mesh->GetTimeStamp(), solutiontimestamp);
    }


  if (clipplanetimestamp < vispar.clipplanetimestamp ||
      clipplanetimestamp < solutiontimestamp)
    {

      //      cout << "clipsolution = " << clipsolution << endl;
      if (vispar.clipenable && clipsolution)      
	{
	  // lock->UnLock();
	  mesh->BuildElementSearchTree();
	  // lock->Lock();
	}

      if (clipplanelist)
	glDeleteLists (clipplanelist, 1);
      

      clipplanelist = glGenLists (1);
      glNewList (clipplanelist, GL_COMPILE);
      
      if (vispar.clipenable && clipsolution == 1 && sol)
	{
	  glDisable(GL_CLIP_PLANE0);
	  
	  ARRAY<ClipPlaneTrig> cpt;
	  GetClippingPlaneTrigs (cpt);
	  
	  glNormal3d (-clipplane[0], -clipplane[1], -clipplane[2]);
	  
	  glBegin (GL_TRIANGLES);
	  for (i = 0; i < cpt.Size(); i++)
	    DrawClipPlaneTrig (sol, scalcomp, cpt[i], 2*subdivisions);
	  glEnd();

	  glEnable(GL_CLIP_PLANE0);
	}
      
      
      if (vispar.clipenable && clipsolution == 2 && vsol)
	{
	  if (autoscale)
	    GetMinMax (vecfunction, 0, minval, maxval);


	  ARRAY<ClipPlanePoint> cpp;
	  GetClippingPlaneGrid (cpp);

	  for (i = 0; i < cpp.Size(); i++)
	    {
	      const ClipPlanePoint & p = cpp[i];
	      double values[6];
	      Vec3d v;

	      GetValues (vsol, p.elnr, p.lam1, p.lam2, p.lam3, values);
	      RealVec3d (values, v, vsol->iscomplex, imag_part);

	      double val = v.Length();

	      if (val > 1e-10 * maxval)
		{
		  v *= (rad / val / gridsize * 0.5);
		  
		  SetOpenGlColor  (val, minval, maxval, logscale);
		  DrawCone (p.p, p.p+v, rad / gridsize * 0.2);
		}
	    }
	}

      glEndList ();
    }

  
  

  if (
      numisolines && 
      (clipplanetimestamp < vispar.clipplanetimestamp ||
       clipplanetimestamp < solutiontimestamp) 
      )
    {
      if (isolinelist) glDeleteLists (isolinelist, 1);
      
      isolinelist = glGenLists (1);
      glNewList (isolinelist, GL_COMPILE);

      Point<3> points[1100];
      double values[1100];
      
      SurfaceElementIndex sei;
      glBegin (GL_LINES);
      int nse = mesh->GetNSE();
      if (sol)
	for (sei = 0; sei <= nse; sei++)
	  {
	    const Element2d & el = (*mesh)[sei];
	    
	    if (el.GetType() == TRIG || el.GetType() == TRIG6)
	      {
		Point<3> lp1, lp2, lp3;
		if (!mesh->GetCurvedElements().IsHighOrder())
		  {
		    GetPointDeformation (el[0]-1, lp1);
		    GetPointDeformation (el[1]-1, lp2);
		    GetPointDeformation (el[2]-1, lp3);
		  }


		
		int n = 1 << subdivisions;
		int ii = 0;
		int ix, iy;
		for (iy = 0; iy <= n; iy++)
		  for (ix = 0; ix <= n-iy; ix++)
		    {
		      double x = double(ix) / n;
		      double y = double(iy) / n;
		  
		      values[ii] = GetSurfValue (sol, sei, x, y, scalcomp);
		      Point<2> xref(x,y);
		      
		      if (mesh->GetCurvedElements().IsHighOrder())
			mesh->GetCurvedElements().
			  CalcSurfaceTransformation (xref, sei, points[ii]);
		      else
			points[ii] = lp3 + x * (lp1-lp3) + y * (lp2-lp3);
		  
		      if (deform)
			{
			  Vec<3> def;
			  GetSurfDeformation (sei, x, y, def);
			  points[ii] += def;
			}
		      ii++;
		    }

		ii = 0;
		for (iy = 0; iy < n; iy++)
		  {
		    for (ix = 0; ix < n-iy; ix++)
		      {
			double x = double(ix) / n;
			double y = double(iy) / n;
			
			int index[] = { ii, ii+1, ii+n-iy+1,
					ii+1, ii+n-iy+2, ii+n-iy+1 };
			
			int np = (ix == n-iy-1) ? 3 : 6;

			DrawIsoLines (points[index[0]], points[index[1]], points[index[2]],
				      values[index[0]], values[index[1]], values[index[2]],
				      minval, maxval, numisolines);
			if (np == 6)
			  DrawIsoLines (points[index[3]], points[index[4]], points[index[5]],
					values[index[3]], values[index[4]], values[index[5]],
					minval, maxval, numisolines);
			ii++;
		      }	
		    ii++;
		  }    
		/*
		double val1, val2, val3;
		val1 = GetSurfValue (sol, sei, 1, 0, scalcomp);
		val2 = GetSurfValue (sol, sei, 0, 1, scalcomp);
		val3 = GetSurfValue (sol, sei, 0, 0, scalcomp);
		*/
	      }
	  }
      
      if (vispar.clipenable && clipsolution == 1 && sol)
	{
	  glDisable(GL_CLIP_PLANE0);
	  
	  ARRAY<ClipPlaneTrig> cpt;
	  GetClippingPlaneTrigs (cpt);
	  
	  glNormal3d (-clipplane[0], -clipplane[1], -clipplane[2]);
	  
	  if (numisolines)
	  for (i = 0; i < cpt.Size(); i++)
	    {
	      const ClipPlaneTrig & trig = cpt[i];
	      double vali[3];
	      for (j = 0; j < 3; j++)
		vali[j] = GetValue (sol, trig.elnr, 
				    trig.points[j].lami(0),
				    trig.points[j].lami(1),
				    trig.points[j].lami(2), scalcomp);
	      
	      DrawIsoLines (trig.points[0].p,
			    trig.points[1].p,
			    trig.points[2].p,
			    vali[0], vali[1], vali[2], minval, maxval, numisolines);
	    }
	  glEnable(GL_CLIP_PLANE0);
	}
      glEnd();
      
      glEndList ();
    }
  
  clipplanetimestamp = max2 (vispar.clipplanetimestamp, solutiontimestamp);
  }
  

  void VisualSceneSolution :: BuildFieldLinesPlot ()
  {
    if (fieldlinestimestamp >= solutiontimestamp) 
      return;
    fieldlinestimestamp = solutiontimestamp;
    

    if (fieldlineslist)
      glDeleteLists (fieldlineslist, num_fieldlineslists);

    if (vecfunction == -1)
      return;


    const SolData * vsol = soldata[vecfunction];

    num_fieldlineslists = (vsol -> iscomplex) ? 100 : 1;

    Point3d pmin, pmax;
    mesh->GetBox (pmin, pmax);
    double lami[3];
    int i;


    fieldlineslist = glGenLists (num_fieldlineslists);

    for (int ln = 0; ln < num_fieldlineslists; ln++)
      {
	glNewList (fieldlineslist + ln, GL_COMPILE);      

	double phi = 2*M_PI*ln / num_fieldlineslists;
	double phaser = cos(phi);
	double phasei = sin(phi);

	for (i = 1; i <= num_fieldlines / num_fieldlineslists+1; i++)
	  {
	    Point3d p (pmin.X() + double (rand()) / RAND_MAX * (pmax.X()-pmin.X()),
		       pmin.Y() + double (rand()) / RAND_MAX * (pmax.Y()-pmin.Y()),
		       pmin.Z() + double (rand()) / RAND_MAX * (pmax.Z()-pmin.Z()));
	    
	    ElementIndex elnr = mesh->GetElementOfPoint (p, lami)-1;
	    (*testout) << "p = " << p << "; elnr = " << elnr << endl;
	    if (elnr != -1)
	      {
		Vec3d v;
		double values[6];
		GetValues (vsol, elnr, lami[0], lami[1], lami[2], values);
		RealVec3d (values, v, vsol->iscomplex, phaser, phasei);
		
		double val = v.Length();
		
		if (!fieldlines_randomstart ||
		    (double (rand()) / RAND_MAX) < (val / maxval))
		  {
		    int i;
		    Point3d p0 = p; 
		    v *= (rad / val * 0.02);
		    SetOpenGlColor  (val, minval, maxval, logscale);
		    
		    Point3d p2 = p + v; 
		    cout << " p " << p << endl; 
		    DrawCylinder (p, p2, rad * 0.003);
		    p = p2;  		
		    
		    for(i=0;i<20;i++) 
		      {
			ElementIndex elnr = mesh->GetElementOfPoint (p, lami)-1;
			
			if (elnr != -1)
			  {
			    GetValues (vsol, elnr, lami[0], lami[1], lami[2], values);
			    RealVec3d (values, v, vsol->iscomplex, phaser, phasei);
			    val = v.Length();
			    v *= (rad / val * 0.02);
			    
			    SetOpenGlColor  (val, minval, maxval, logscale);
			    p2 = p +v; 
			    DrawCylinder (p, p2, rad * 0.003);
			    p = p2;  	
			  }
			else break; 
		      } 
		    p=p0; 
		    for(i=0;i<20;i++) 
		      {
			ElementIndex elnr = mesh->GetElementOfPoint (p, lami)-1;

			if (elnr != -1)
			  {
			    GetValues (vsol, elnr, lami[0], lami[1], lami[2], values);
			    RealVec3d (values, v, vsol->iscomplex, phaser, phasei);
			    
			    val = v.Length();
			    v *= (rad / val * 0.02);
			    
			    SetOpenGlColor  (val, minval, maxval, logscale);
			    p2 = p - v; 
			    DrawCylinder (p, p2, rad * 0.003);
			    p = p2;  	
			  }
			else break; 
		      } 
		  }		  
	      }
	  }
	glEndList ();
      }
  }
  


  void  VisualSceneSolution :: DrawSurfaceElements ()
  {
    int j, k;
    SurfaceElementIndex sei;

    const SolData * sol = NULL;
    const SolData * vsol = NULL;
    
    if (scalfunction != -1)
      sol = soldata[scalfunction];
    if (vecfunction != -1)
      vsol = soldata[vecfunction];
    
    if (mesh->GetTimeStamp () > solutiontimestamp)
      {
	sol = NULL;
	vsol = NULL;
      }
    
    glLineWidth (1.0f);

    if (!sol || !sol->draw_surface)
      glDisable (GL_TEXTURE_1D);

    
    Point<3> points[1100];
    Vec<3> nvs[1100];
    double values[1100];

    glBegin (GL_TRIANGLES);
    int nse = mesh->GetNSE();

    glColor3f (0.4, 0.4, 0.4);

    for (sei = 0; sei < nse; sei++)
      {
	Element2d & el = (*mesh)[sei];

	if (el.GetType() == TRIG || el.GetType() == TRIG6)
	  {
	    Point<3> p1, p2, p3;
	    if (!mesh->GetCurvedElements().IsHighOrder())
	      {
		GetPointDeformation (el[0]-1, p1, sei);
		GetPointDeformation (el[1]-1, p2, sei);
		GetPointDeformation (el[2]-1, p3, sei);
	      }
	    
	    int n = 1 << subdivisions;
	    int ii = 0;
	    int ix, iy;
	    for (iy = 0; iy <= n; iy++)
	      for (ix = 0; ix <= n-iy; ix++)
		{
		  double x = double(ix) / n;
		  double y = double(iy) / n;
		  
		  if (sol && sol->draw_surface) 
		    values[ii] = GetSurfValue (sol, sei, x, y, scalcomp);

		  Point<2> xref(x,y);
		  Mat<3,2> dxdxi;

		  if (mesh->GetCurvedElements().IsHighOrder())
		    {
		      mesh->GetCurvedElements().
			CalcSurfaceTransformation (xref, sei, points[ii], dxdxi);
		      nvs[ii] = Cross (dxdxi.Col(0), dxdxi.Col(1));
		      nvs[ii].Normalize();
		    }
		  else
		    {
		      points[ii] = p3 + x * (p1-p3) + y * (p2-p3);
		      nvs[ii] = Cross (p2-p1, p3-p1);
		      nvs[ii].Normalize();
		    }
		  
		  if (deform)
		    {
		      Vec<3> def;
		      GetSurfDeformation (sei, x, y, def);
		      points[ii] += def;
		    }
		  ii++;
		}

	    ii = 0;
	    
	    for (iy = 0; iy < n; iy++)
	      {
		for (ix = 0; ix < n-iy; ix++)
		  {
		    double x = double(ix) / n;
		    double y = double(iy) / n;
		    
		    int index[] = { ii, ii+1, ii+n-iy+1,
				    ii+1, ii+n-iy+2, ii+n-iy+1 };
		    
		    int np = (ix == n-iy-1) ? 3 : 6;
		    for (int j = 0; j < np; j++)
		      {
			if (sol && sol->draw_surface)
			  SetOpenGlColor  (values[index[j]], minval, maxval, logscale);
			glNormal3dv (&nvs[index[j]](0));
			glVertex3dv (points[index[j]]);
		      }
		    ii++;
		  }	
		ii++;
	      }    
	  }
      }
    glEnd ();
    
    
  
    
  
    
    glBegin (GL_QUADS);
    for (sei = 0; sei < nse; sei++)
    {
      const Element2d & el = (*mesh)[sei];
      
      if (el.GetType() == QUAD || el.GetType() == QUAD6)
	{
	  Point<3> lpi[4];
	  for (k = 0; k < 4; k++)
	    GetPointDeformation (el[k]-1, lpi[k]);
	  Vec<3> vx = lpi[1]-lpi[0];
	  Vec<3> vy = lpi[3]-lpi[0];
	  Vec<3> vtwist = (lpi[0]-lpi[1]) + (lpi[2]-lpi[3]);
	  Vec<3> nv = Cross (lpi[1]-lpi[0], Center (lpi[2],lpi[3]) - lpi[0]);
	  nv.Normalize();
	  glNormal3dv (nv);
	  

	  int n = 1 << subdivisions;
	  int ii = 0;
	  int ix, iy;
	  for (iy = 0; iy <= n; iy++)
	    for (ix = 0; ix <= n; ix++)
	      {
		double x = double(ix) / n;
		double y = double(iy) / n;
		
		Point<2> xref(x,y);
		Mat<3,2> dxdxi;

		if (sol && sol->draw_surface) 
		  values[ii] = GetSurfValue (sol, sei, x, y, scalcomp);


		if (mesh->GetCurvedElements().IsHighOrder())
		  {
		    mesh->GetCurvedElements().
		      CalcSurfaceTransformation (xref, sei, points[ii], dxdxi);
		    nvs[ii] = Cross (dxdxi.Col(0), dxdxi.Col(1));
		    nvs[ii].Normalize();
		  }
		else
		  {
		    points[ii] = lpi[0] + x * vx + y * vy + x*y * vtwist;
		    nvs[ii] = Cross (vx, vy);
		    nvs[ii].Normalize();
		  }
		  
		if (deform)
		  {
		    Vec<3> def;
		    GetSurfDeformation (sei, x, y, def);
		    points[ii] += def;
		  }

		// points[ii] = lpi[0] + x * vx + y * vy;
		ii++;
	      }
	  
	  ii = 0;
	  for (iy = 0; iy < n; iy++)
	    {
	      for (ix = 0; ix < n; ix++)
		{
		  double x = double(ix) / n;
		  double y = double(iy) / n;
		    
		  int index[] = { ii, ii+1, ii+n+2, ii+n+1 };

		  for (int j = 0; j < 4; j++)
		    {
		      if (sol && sol->draw_surface)
			SetOpenGlColor  (values[index[j]], minval, maxval, logscale);
		      glNormal3dv (&nvs[index[j]](0));
		      glVertex3dv (points[index[j]]);
		    }
		  ii++;
		}	
	      ii++;
	    }    
	}
    }
  glEnd();

  if (usetexture)
    glEnable (GL_TEXTURE_1D);

  }


  // Bernstein Pol B_{n,i}(x) = n! / i! / (n-i)! (1-x)^{n-i} x^i
  static  double Bernstein (int n, int i, double x)
  {
    int j;
    double val = 1;
    for (j = 1; j <= i; j++)
      val *= x / j;
    for (j = 1; j <= n-i; j++)
      val *= (1-x) / j;
    for (j = 1; j <= n; j++)
      val *= j;
    return val;
  }

  void  VisualSceneSolution :: DrawSurfaceElementLines ()
  {
    int i, j, k, l;
    SurfaceElementIndex sei;

    /*
    int p = 4;
    DenseMatrix mat(p+1,p+1), invmat(p+1,p+1);
    for (i = 0; i <= p; i++)
      for (j = 0; j <= p; j++)
	mat.Elem(i+1,j+1) = Bernstein(p, i, double(j)/p);
    CalcIo
nverse (mat, invmat);
    */

    glLineWidth (1.0f);
    glNormal3d (1, 0, 0);

    int nse = mesh->GetNSE();

    for (sei = 0; sei < nse; sei++)
      {
	Element2d & el = (*mesh)[sei];

	int nv;
	if (el.GetType() == TRIG || el.GetType() == TRIG6)
	  nv = 3;
	else 
	  nv = 4;
	
	Point<3> p1, p2, p3, p4;
	GetPointDeformation (el[0]-1, p1, sei);
	GetPointDeformation (el[1]-1, p2, sei);
	GetPointDeformation (el[2]-1, p3, sei);
	if (nv == 4)
	  GetPointDeformation (el[3]-1, p4, sei);


	// glBegin (GL_LINE_LOOP);
	int n = 1 << subdivisions;
	// n = p;

	int ii = 0;
	int ix, iy;
	Point<3> pnt;
	
	for (k = 0; k < nv; k++)
	  {
	    Point<2> p0;
	    Vec<2> vtau;
	    if (nv == 3)
	      switch (k)
		{
		case 0:
		  p0 = Point<2> (0,0);
		  vtau = Vec<2> (1,0);
		  break;
		case 1:
		  p0 = Point<2> (1,0);
		  vtau = Vec<2> (-1,1);
		  break;
		case 2:
		  p0 = Point<2> (0,1);
		  vtau = Vec<2> (0,-1);
		  break;
		}
	    else
	      switch (k)
		{
		case 0:
		  p0 = Point<2> (0,0);
		  vtau = Vec<2> (1,0);
		  break;
		case 1:
		  p0 = Point<2> (1,0);
		  vtau = Vec<2> (0,1);
		  break;
		case 2:
		  p0 = Point<2> (1,1);
		  vtau = Vec<2> (-1,0);
		  break;
		case 3:
		  p0 = Point<2> (0,1);
		  vtau = Vec<2> (0,-1);
		  break;
		}

	    
	    glBegin (GL_LINE_STRIP);
	    Point<3> pts[33], pts2[33];
	    if (n > 32) cerr << "too many subdivisions, code 433425" << endl;

	    for (ix = 0; ix <= n; ix++)
	      {
		Point<2> p = p0 + (double(ix) / n) * vtau;
		double x = p(0);
		double y = p(1);
		Point<2> xref(x,y);

		if (mesh->GetCurvedElements().IsHighOrder())
		  mesh->GetCurvedElements().
		    CalcSurfaceTransformation (xref, sei, pnt);
		else
		  {
		    if (nv == 3)
		      pnt = p3 + x * (p1-p3) + y * (p2-p3);
		    else
		      pnt = p1 + x * (p2-p1) + y * (p4-p1) + x*y * ( (p1-p2)+(p3-p4) );
		  }
		
		if (deform)
		  {
		    Vec<3> def;
		    GetSurfDeformation (sei, x, y, def);
		    pnt += def;
		  }
		
		glVertex3dv (pnt);

		pts[ix] = pnt;
	      }
	    glEnd ();



	    /*
	    // convert from point-values to Bernstein basis
	    for (i = 0; i < 3; i++)
	      for (j = 0; j <= p; j++)
		{
		  pts2[j](i) = 0;
		  for (l = 0; l <= p; l++)
		    pts2[j](i) += invmat(l,j) * pts[l](i);
		}


	    glMap1d(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, n+1, &pts2[0](0));
	    glEnable(GL_MAP1_VERTEX_3);

	    int steps = 1 << subdivisions;

// 	    glBegin (GL_LINE_STRIP);
// 	    for (int hi = 0; hi <= 10; hi++)
// 	      glEvalCoord1d (double(hi)/10.0);
// 	    glEnd ();

	    glMapGrid1d (steps, 0.0, 1.0);
	    glEvalMesh1(GL_LINE, 0, steps);
	    glDisable(GL_MAP1_VERTEX_3);
	    */
	  }
	
      }
    
  }




















void  VisualSceneSolution :: DrawSurfaceVectors ()
{
  int j, k;
  int dir, dir1, dir2;
  SurfaceElementIndex sei;

  const SolData * vsol = NULL;

  if (vecfunction != -1)
    vsol = soldata[vecfunction];

  if (mesh->GetTimeStamp () > solutiontimestamp)
    {
      vsol = NULL;
    }

  if (!vsol) return;


  Point<3> pmin = center - Vec3d (rad, rad, rad);
  Point<3> pmax = center - Vec3d (rad, rad, rad);

  double s, t;

  // draw surface cones
  //  if (0)
  /*
  if (vsol->soltype==SOL_SURFACE_ELEMENT ||
      vsol->soltype==SOL_SURFACE_NONCONTINUOUS ||
      vsol->soltype==SOL_VIRTUALFUNCTION)
  */
  if (vsol->draw_surface && showsurfacesolution)
    {
      int nse = mesh->GetNSE();
      for (sei = 0; sei < nse; sei++)
	{
	  const Element2d & el = (*mesh)[sei];
	  
	  if (el.GetType() != TRIG && el.GetType() != TRIG6) continue;
	  
	  Point<3> lp[3];
	  Point<2> p2d[3];
	  /*
	  for (k = 0; k < 3; k++)
	    lp[k] = mesh->Point (el[k]);
	  */
	  lp[0] = mesh->Point(el[2]);
	  lp[1] = mesh->Point(el[0]);
	  lp[2] = mesh->Point(el[1]);


	  Vec<3> n = Cross (lp[1]-lp[0], lp[2]-lp[0]);
	  Vec<3> na (fabs (n(0)), fabs(n(1)), fabs(n(2)));
	  if (na(0) > na(1) && na(0) > na(2))
	    dir = 1;
	  else if (na(1) > na(2))
	    dir = 2;
	  else 
	    dir = 3;

	  dir1 = (dir % 3) + 1;
	  dir2 = (dir1 % 3) + 1;
	  
	  for (k = 0; k < 3; k++)
	    {
	      p2d[k] = Point<2> ((lp[k](dir1-1) - pmin(dir1-1)) / (2*rad),
				 (lp[k](dir2-1) - pmin(dir2-1)) / (2*rad));
	    }
	  
	  double minx2d, maxx2d, miny2d, maxy2d;
	  minx2d = maxx2d = p2d[0](0);
	  miny2d = maxy2d = p2d[0](1);
	  for (k = 1; k < 3; k++)
	    {
	      minx2d = min2 (minx2d, p2d[k](0));
	      maxx2d = max2 (maxx2d, p2d[k](0));
	      miny2d = min2 (miny2d, p2d[k](1));
	      maxy2d = max2 (maxy2d, p2d[k](1));
	    }

	  double mat11 = p2d[1](0) - p2d[0](0);
	  double mat21 = p2d[1](1) - p2d[0](1);
	  double mat12 = p2d[2](0) - p2d[0](0);
	  double mat22 = p2d[2](1) - p2d[0](1);

	  double det = mat11*mat22-mat21*mat12;
	  double inv11 = mat22/det;
	  double inv21 = -mat21/det;
	  double inv12 = -mat12/det;
	  double inv22 = mat11/det;
	  
      
	  
	  for (s = 0; s <= 1; s += 1.0 / gridsize)
	    if (s >= minx2d && s <= maxx2d)
	      for (t = 0; t <= 1; t += 1.0 / gridsize)
		if (t >= miny2d && t <= maxy2d)
		  {
		    double lam1 = inv11 * (s - p2d[0](0)) + inv12 * (t-p2d[0](1));
		    double lam2 = inv21 * (s - p2d[0](0)) + inv22 * (t-p2d[0](1));
		    
		    if (lam1 >= 0 && lam2 >= 0 && lam1+lam2 <= 1)
		      {
			Point<3> cp;
			for (k = 0; k < 3; k++)
			  cp(k) = lp[0](k) + 
			    lam1 * (lp[1](k)-lp[0](k)) + 
			    lam2 * (lp[2](k)-lp[0](k));

			Vec<3> v;
			double values[6];
			GetSurfValues (vsol, sei, lam1, lam2, values);

			if (!vsol->iscomplex)
			  for (k = 0; k < 3; k++)
			    v(k) = values[k];
			else
			  {
			    if (!imag_part)
			      for (k = 0; k < 3; k++)
				v(k) = values[2*k];
			    else
			      for (k = 0; k < 3; k++)
				v(k) = values[2*k+1];
			  }
			
			if (mesh->GetDimension() == 2)
			  v(2) = 0;
			
			double val = v.Length();
			SetOpenGlColor  (val, minval, maxval, logscale);

			if (val > 1e-10 * maxval)
			  v *= (rad / val / gridsize * 0.5);
			DrawCone (cp, cp+4*v, 0.8*rad / gridsize);

			/*
			v /= val;
			
			glPushMatrix();
			glTranslated (cp(0), cp(1), cp(2));

			double l = 2*rad/gridsize;
			double r = 0.8*rad/gridsize;
			glScaled (l, l, l);
			
			double phi = acos (v(2));
			glRotated (-180/M_PI*phi, v(1), -v(0), 0);

			glCallList (cone_list);
			glPopMatrix();
			*/
		      }
		  }
	}
    }
}




void VisualSceneSolution :: 
DrawIsoLines (const Point3d & p1, 
	      const Point3d & p2, 
	      const Point3d & p3,
	      double val1, double val2, double val3,
	      double minval, double maxval, int n)
{
  DrawIsoLines2 (p1, p2, p1, p3, val1, val2, val1, val3, minval, maxval, n);
  DrawIsoLines2 (p2, p1, p2, p3, val2, val1, val2, val3, minval, maxval, n);
  DrawIsoLines2 (p3, p1, p3, p2, val3, val1, val3, val2, minval, maxval, n);
}

void VisualSceneSolution :: 
DrawIsoLines2 (const Point3d & p1, 
	       const Point3d & p2, 
	       const Point3d & p3,
	       const Point3d & p4,
	       double val1, double val2, double val3, double val4,
	       double minval, double maxval, int n)
{
  if (val1 > val2) 
    DrawIsoLines2 (p2, p1, p3, p4, val2, val1, val3, val4, minval, maxval, n);
  if (val3 > val4) 
    DrawIsoLines2 (p1, p2, p4, p3, val1, val2, val4, val3, minval, maxval, n);

  val2 += 1e-10;
  val4 += 1e-10;

  double fac = (maxval-minval) / n;
  double idelta1 = 1.0 / (val2 - val1);
  double idelta2 = 1.0 / (val4 - val3);

  int mini = int ((max2 (val1, val3) - minval) / fac);
  int maxi = int ((min2 (val2, val4) - minval) / fac);
  if (mini < 0) mini = 0;
  if (maxi > n-1) maxi = n-1;

  for (int i = mini; i <= maxi+1; i++)
    {
      double val = minval + i * fac;
      double lam1 = (val - val1) * idelta1;
      double lam2 = (val - val3) * idelta2;
      if (lam1 >= 0 && lam1 <= 1 && lam2 >= 0 && lam2 <= 1)
	{
	  Point3d lp1 = p1 + lam1 * Vec3d (p1, p2);
	  Point3d lp2 = p3 + lam2 * Vec3d (p3, p4);
	  glVertex3d (lp1.X(), lp1.Y(), lp1.Z());
	  glVertex3d (lp2.X(), lp2.Y(), lp2.Z());
	  glVertex3d (lp2.X(), lp2.Y(), lp2.Z());
	  glVertex3d (lp1.X(), lp1.Y(), lp1.Z());
	}
    }
}







void VisualSceneSolution :: 
GetMinMax (int funcnr, int comp, double & minv, double & maxv) const
{
  int i, j;
  const SolData * sol;
  double val;

  bool hasit = 0;
  minv = 0; maxv = 1;
  if (funcnr != -1)
    {
      sol = soldata[funcnr];
      if (sol->draw_volume)
	{
	  int ne = mesh->GetNE();
	  for (int i = 0; i < ne; i++)
	    {
	      double val = GetValue (sol, i, 0.333, 0.333, 0.333, comp);
	      if (val > maxv || !hasit)
		maxv = val;
	      if (val < minv || !hasit)
		minv = val;
	      hasit = 1;
	    }
	}
      if (sol->draw_surface)
	{
	  int nse = mesh->GetNSE();
	  for (int i = 0; i < nse; i++)
	    {
	      double val = GetSurfValue (sol, i, 0.333, 0.333, comp);
	      if (val > maxv || !hasit)
		maxv = val;
	      if (val < minv || !hasit)
		minv = val;
	      hasit = 1;
	    }
	}
    }
}





void VisualSceneSolution :: 
GetValues (const SolData * data, ElementIndex elnr, 
	   double lam1, double lam2, double lam3,
	   double * values) const
{
  switch (data->soltype)
    {
    case SOL_VIRTUALFUNCTION:
      {
	bool ok =
	  data->solclass->GetValue (elnr, lam1, lam2, lam3, values);
	break;
      }
    default:
      {
	for (int i = 0; i < data->components; i++)
	  values[i] = GetValue (data, elnr, lam1, lam2, lam3, i+1);
      }
    }
}


double VisualSceneSolution :: 
GetValue (const SolData * data, ElementIndex elnr, 
	  double lam1, double lam2, double lam3,
	  int comp) const
{
  if (comp == 0)
    {
      double val = 0;
      ArrayMem<double,20> values(data->components);
      GetValues (data, elnr, lam1, lam2, lam3, &values[0]);

      switch (evalfunc)
	{
	case FUNC_ABS:
	  {
	    for (int ci = 0; ci < data->components; ci++)
	      val += sqr (values[ci]);
	    val = sqrt (val);
	    break;
	  }
	case FUNC_ABS_TENSOR:
	  {
	    int d;
	    switch (data->components)
	      {
	      case 1: d = 1; break;
	      case 3: d = 2; break;
	      case 6: d = 3; break;
	      }
	    int ci;
	    for (ci = 0; ci < d; ci++)
	      val += sqr (values[ci]);
	    for (ci = d; ci < data->components; ci++)
	      val += 2*sqr (values[ci]);
	    val = sqrt (val);
	    break;
	  }

	case FUNC_MISES:
	{
	    int d;
	    switch(data->components)
	      {
	      case 1: d = 1; break;
	      case 3: d = 2; break;
	      case 6: d = 3; break;
	      }
	    int ci;
	    double trace = 0.;
	    for (ci = 0; ci < d; ci++)
	      trace += 1./3.*(values[ci]);
	    for (ci = 0; ci < d; ci++)
	      val += sqr (values[ci]-trace);
	    for (ci = d; ci < data->components; ci++)
	      val += 2.*sqr (values[ci]);
	    val = sqrt (val);
	    break;
	}
	case FUNC_MAIN:
	 {
	    int d;
	    switch(data->components)
	      {
	      case 1: d = 1; break;
	      case 3: d = 2; break;
	      case 6: d = 3; break;
	      }
	    Mat<3,3> m ;
	    Vec<3> ev;
	    int ci;
            for (ci = 0; ci < d; ci++)
	      m(ci,ci) = (values[ci]);
	    m(0,1) = m(1,0) = values[3];
	    m(0,2) = m(2,0) = values[4];
	    m(1,2) = m(2,1) = values[5];

	    EigenValues (m, ev);
	    double help;
            for (int i=0; i<d; i++)
            {
               for (int j=d-1; i<j; j--)
               {
                   if ( abs(ev(j)) > abs(ev(j-1)) )
	           {
	              help = ev(j);
                      ev(j) = ev(j-1);
	              ev(j-1) = help;
	           }
       		}
  	    }
            val = (ev(0));
	    break;
         }
      }

      return val;	
    }


  switch (data->soltype)
    {
    case SOL_VIRTUALFUNCTION:
      {
	double values[20];
	bool ok = data->solclass->GetValue (elnr, lam1, lam2, lam3, values);

	if (ok) 
	  return values[comp-1];
	else
	  return 0;
      }
    case SOL_NODAL:
      {
	const Element & el = (*mesh)[elnr];

	double lami[8];
	int np, i;
	double val = 0;
	
	switch (el.GetType())
	  {
	  case TET:
	  case TET10:
	    {
	      lami[1] = lam1;
	      lami[2] = lam2;
	      lami[3] = lam3;
	      lami[0] = 1-lam1-lam2-lam3;
	      np = 4;
	      break;
	    }
	  case PRISM:
	  case PRISM12:
	    {
	      lami[0] = (1-lam3) * (1-lam1-lam2);
	      lami[1] = (1-lam3) * lam1;
	      lami[2] = (1-lam3) * lam2;
	      lami[3] = (lam3) * (1-lam1-lam2);
	      lami[4] = (lam3) * lam1;
	      lami[5] = (lam3) * lam2;
	      np = 6;
	      break;
	    }	    
	  }

	for (i = 0; i < np; i++)
	  val += lami[i] * data->data[(el[i]-1) * data->dist + comp-1];

	return val;
      }

    case SOL_ELEMENT:
      {
	return data->data[elnr * data->dist + comp-1];
      }

    case SOL_SURFACE_ELEMENT:
      return 0;

    case SOL_NONCONTINUOUS:
      {
	const Element & el = (*mesh)[elnr];

	double lami[8];
	int np, i;
	double val = 0;

	switch (el.GetType())
	  {
	  case TET:
	  case TET10:
	    {
	      lami[1] = lam1;
	      lami[2] = lam2;
	      lami[3] = lam3;
	      lami[0] = 1-lam1-lam2-lam3;
	      np = 4;
	      break;
	    }
	  case PRISM:
	  case PRISM12:
	    {
	      lami[0] = (1-lam3) * (1-lam1-lam2);
	      lami[1] = (1-lam3) * lam1;
	      lami[2] = (1-lam3) * lam2;
	      lami[3] = (lam3) * (1-lam1-lam2);
	      lami[4] = (lam3) * lam1;
	      lami[5] = (lam3) * lam2;
	      np = 6;
	      break;
	    }
	  case PYRAMID:
	    {
	      if (lam3 > 1-1e-5)
		{
		  lami[0] = lami[1] = lami[2] = lami[3] = 0;
		  lami[4] = 1;
		}
	      else
		{
		  double x0 = lam1 / (1-lam3);
		  double y0 = lam2 / (1-lam3);
		  lami[0] = (1-x0) * (1-y0) * (1-lam3);
		  lami[1] = (  x0) * (1-y0) * (1-lam3);
		  lami[2] = (  x0) * (  y0) * (1-lam3);
		  lami[3] = (1-x0) * (  y0) * (1-lam3);
		  lami[4] = lam3;
		  np = 5;
		}
	      break;
	    }
	  default:
	    np = 0;
	  }

	int base;
	if (data->order == 1)
	  base = 6 * elnr;
	else
	  base = 10 * elnr;


	for (i = 0; i < np; i++)
	  val += lami[i] * data->data[(base+i) * data->dist + comp-1];

	return val;
      }

    case SOL_MARKED_ELEMENTS:
      return (*mesh)[elnr].TestRefinementFlag();
      
    case SOL_ELEMENT_ORDER:
      return (*mesh)[elnr].GetOrder();
    }
  return 0;
}




void VisualSceneSolution :: 
GetSurfValues (const SolData * data, SurfaceElementIndex selnr, 
	       double lam1, double lam2, 
	       double * values) const
{
  switch (data->soltype)
    {
    case SOL_VIRTUALFUNCTION:
      {
	bool ok =
	  data->solclass->GetSurfValue (selnr, lam1, lam2, values);
	break;
      }
    default:
      {
	for (int i = 0; i < data->components; i++)
	  values[i] = GetSurfValue (data, selnr, lam1, lam2, i+1);
      }
    }
}



double VisualSceneSolution :: 
GetSurfValue (const SolData * data, SurfaceElementIndex selnr, 
	      double lam1, double lam2, 
	      int comp) const
{
  if (comp == 0)
    {
      double val = 0;
      ArrayMem<double,20> values(data->components);
      GetSurfValues (data, selnr, lam1, lam2, &values[0]);

      switch (evalfunc)
	{
	case FUNC_ABS:
	  {
	    for (int ci = 0; ci < data->components; ci++)
	      val += sqr (values[ci]);
	    val = sqrt (val);
	    break;
	  }
	case FUNC_ABS_TENSOR:
	  {
	    int d;
	    switch (data->components)
	      {
	      case 1: d = 1; break;
	      case 3: d = 2; break;
	      case 6: d = 3; break;
	      }
	    int ci;
	    for (ci = 0; ci < d; ci++)
	      val += sqr (values[ci]);
	    for (ci = d; ci < data->components; ci++)
	      val += 2*sqr (values[ci]);
	    val = sqrt (val);
	    break;
	  }

	case FUNC_MISES:
	{
	    int d;
	    switch(data->components)
	      {
	      case 1: d = 1; break;
	      case 3: d = 2; break;
	      case 6: d = 3; break;
	      }
	    int ci;
	    double trace = 0.;
	    for (ci = 0; ci < d; ci++)
	      trace += 1./3.*(values[ci]);
	    for (ci = 0; ci < d; ci++)
	      val += sqr (values[ci]-trace);
	    for (ci = d; ci < data->components; ci++)
	      val += 2.*sqr (values[ci]);
	    val = sqrt (val);
	    break;
	}
	case FUNC_MAIN:
	 {
	    int d;
	    switch(data->components)
	      {
	      case 1: d = 1; break;
	      case 3: d = 2; break;
	      case 6: d = 3; break;
	      }
	    Mat<3,3> m ;
	    Vec<3> ev;
	    int ci;
            for (ci = 0; ci < d; ci++)
	      m(ci,ci) = (values[ci]);
	    m(0,1) = m(1,0) = values[3];
	    m(0,2) = m(2,0) = values[4];
	    m(1,2) = m(2,1) = values[5];

	    EigenValues (m, ev);
	    double help;
            for (int i=0; i<d; i++)
            {
               for (int j=d-1; i<j; j--)
               {
                   if ( abs(ev(j)) > abs(ev(j-1)) )
	           {
	              help = ev(j);
                      ev(j) = ev(j-1);
	              ev(j-1) = help;
	           }
       		}
  	    }
            val = (ev(0));
	    break;
         }
      }

      return val;	


      /*
      int ci;
      double val = 0;
      for (ci = 1; ci <= data->components; ci++)
	val += sqr (GetSurfValue (data, selnr, lam1, lam2, ci));
      return sqrt (val);
      */
    }


  switch (data->soltype)
    {
   case SOL_VIRTUALFUNCTION:
      {
	double values[20];
	bool ok =
	  data->solclass->GetSurfValue (selnr, lam1, lam2, values);
	if (ok)
	  return values[comp-1];
	else 
	  return 0;
      }


    case SOL_NODAL:
      {
	const Element2d & el = (*mesh)[selnr];

	double lami[8];
	int np, i;
	double val = 0;
	double lam3 = 1-lam1-lam2;

	switch (el.GetType())
	  {
	  case TRIG:
	    /*
	    lami[0] = lam3;
	    lami[1] = lam1;
	    lami[2] = lam2;
	    */
	    lami[0] = lam1;
	    lami[1] = lam2;
	    lami[2] = lam3;
	    np = 3;
	    break;

	  case TRIG6:
	    /*
	    lami[0] = lam3*(2*lam3-1);
	    lami[1] = lam1*(2*lam1-1);
	    lami[2] = lam2*(2*lam2-1);
	    */
	    // hierarchical basis:
	    lami[0] = lam3;
	    lami[1] = lam1;
	    lami[2] = lam2;
	    lami[3] = 4*lam1*lam2;
	    lami[4] = 4*lam2*lam3;
	    lami[5] = 4*lam1*lam3;
	    np = 6;
	    break;

	  case QUAD:
	  case QUAD6:
	    lami[0] = (1-lam1)*(1-lam2);
	    lami[1] = lam1 * (1-lam2);
	    lami[2] = lam1 * lam2;
	    lami[3] = (1-lam1) * lam2;
	    np = 4;
	    break;

	  default:
	    np = 0;
	  }

	for (i = 0; i < np; i++)
	  val += lami[i] * data->data[(el[i]-1) * data->dist + comp-1];

	return val;
      }

    case SOL_ELEMENT:
      {
	int el1, el2;
	mesh->GetTopology().GetSurface2VolumeElement (selnr+1, el1, el2);
	el1--;

	return data->data[el1 * data->dist+comp-1];
      }

    case SOL_NONCONTINUOUS:
      {
	return 0;
      }

    case SOL_SURFACE_ELEMENT:
      {
	return data->data[selnr * data->dist + comp-1];
      }

    case SOL_SURFACE_NONCONTINUOUS:
      {
	const Element2d & el = (*mesh)[selnr];

	double lami[8];
	int np, i;
	double val = 0;
	int order = data->order;

	switch (order)
	  {
	  case 0:
	    return data->data[selnr * data->dist + comp-1];
	  case 1:
	    {
	      switch (el.GetType())
		{
		case TRIG:
		case TRIG6:
		  {
		    lami[1] = lam1;
		    lami[2] = lam2;
		    lami[0] = 1-lam1-lam2;
		    np = 3;
		    break;
		  }
		}
	      break;
	    }
	  case 2:
	    {
	      switch (el.GetType())
		{
		case TRIG:
		  {
		    lami[1] = lam1;
		    lami[2] = lam2;
		    lami[0] = 1-lam1-lam2;
		    np = 3;
		    break;
		  }
		case TRIG6:
		  {
		    double lam3 = 1-lam1-lam2;
		    lami[1] = 2*lam1 * (lam1-0.5);
		    lami[2] = 2*lam2 * (lam2-0.5);
		    lami[0] = 2*lam3 * (lam3-0.5);
		    lami[3] = 4*lam1*lam2;
		    lami[4] = 4*lam2*lam3;
		    lami[5] = 4*lam1*lam3;
		    np = 6;
		    break;
		  }
		}
	      break;
	    }
	  }
	
	int base;
	if (order == 1)
	  base = 4 * selnr;
	else 
	  base = 9 * selnr;

	for (i = 0; i < np; i++)
	  {
	    val += lami[i] * data->data[(base+i) * data->dist + comp-1];
	  }
	return val;
      }

    case SOL_MARKED_ELEMENTS:
      return (*mesh)[selnr].TestRefinementFlag();
      
    case SOL_ELEMENT_ORDER:
      return (*mesh)[selnr].GetOrder();

    }
  return 0;
}


void VisualSceneSolution :: 
GetDeformation (ElementIndex elnr, double lam1, double lam2, double lam3,
		Vec<3> & def) const
{
  if (deform && vecfunction != -1)
    {
      GetValues (soldata[vecfunction], elnr, lam1, lam2, lam3, &def(0));
      def *= scaledeform;

      if (soldata[vecfunction]->dist == 2) def(2) = 0;
    }
  else
    def = 0;
}


void VisualSceneSolution :: 
GetSurfDeformation (SurfaceElementIndex elnr, double lam1, double lam2, 
		    Vec<3> & def) const
{
  if (deform && vecfunction != -1)
    {
      GetSurfValues (soldata[vecfunction], elnr, lam1, lam2,  &def(0));
      def *= scaledeform;

      if (soldata[vecfunction]->dist == 2) def(2) = 0;
    }
  else
    def = 0;
}

void VisualSceneSolution :: GetPointDeformation (int pnum, Point<3> & p, 
						 SurfaceElementIndex elnr) const
{
  p = mesh->Point (pnum+1);

  if (deform && vecfunction != -1)
    {
      const SolData * vsol = soldata[vecfunction];
      
      Vec<3> v(0,0,0);
      if (vsol->soltype == SOL_NODAL)
	{
	  v = Vec3d(vsol->data[pnum * vsol->dist],
		    vsol->data[pnum * vsol->dist+1],
		    vsol->data[pnum * vsol->dist+2]);
	}
      else if (vsol->soltype == SOL_SURFACE_NONCONTINUOUS)
	{
	  const Element2d & el = (*mesh)[elnr];
	  for (int j = 0; j < el.GetNP(); j++)
	    if (el[j] == pnum+1)
	      {
		int base = (4*elnr+j-1) * vsol->dist;
		v = Vec3d(vsol->data[base],
			  vsol->data[base+1],
			  vsol->data[base+2]);
	      }
	}

      if (vsol->dist == 2) v(2) = 0;
      
      v *= scaledeform;
      p += v;
    }
}








void VisualSceneSolution :: GetClippingPlaneTrigs (ARRAY<ClipPlaneTrig> & trigs)
{
  //  cout << "get clipplane trigs" << endl;

  int ii, j, k, l;
  ElementIndex ei;
  // int np = mesh->GetNV();
  int np = mesh->GetNP();
  int ne = mesh->GetNE();

  ARRAY<double> nodevals(np);
  
  for (int i = 0; i < np; i++)
    {
      Point<3> p;
      GetPointDeformation(i, p);
      nodevals[i] =
	p(0) * clipplane[0] +
	p(1) * clipplane[1] +
	p(2) * clipplane[2] +
	clipplane[3];
    }

  const int edgei[6][2] =
  { 
    { 0, 1 },
    { 0, 2 },
    { 0, 3 },
    { 1, 2 },
    { 1, 3 },
    { 2, 3 }
  };
  double edgelam[6];
  Point<3> edgep[6];
  double nodevali[4];

  int cntce;
  int cpe1 = 0, cpe2 = 0, cpe3 = 0;

  ARRAY<Element> loctets;
  ARRAY<Element> loctetsloc;
  ARRAY<Point3d> pointsloc;

  for (ei = 0; ei < ne; ei++)
    {
      // const Element & el = mesh->VolumeElement(i);

      (*mesh)[ei].GetTets (loctets);
      (*mesh)[ei].GetTetsLocal (loctetsloc);
      // (*mesh)[ei].GetNodesLocal (pointsloc);
      (*mesh)[ei].GetNodesLocalNew (pointsloc);

      for (ii = 0; ii < loctets.Size(); ii++)
	{
	  const Element & el = loctets[ii];
	  
	  for (j = 0; j < 4; j++)
	    nodevali[j] = nodevals.Get(el[j]);
	  
	  cntce = 0;
	  for (j = 0; j < 6; j++)
	    {
	      int lpi1 = edgei[j][0];
	      int lpi2 = edgei[j][1];
	      if ( (nodevali[lpi1] > 0) !=
		   (nodevali[lpi2] > 0) )
		{
		  edgelam[j] = nodevali[lpi2] / (nodevali[lpi2] - nodevali[lpi1]);
		  Point<3> p1, p2;
		  GetPointDeformation (el[lpi1]-1, p1);
		  GetPointDeformation (el[lpi2]-1, p2);
		  
		  edgep[j] = p1 + (1-edgelam[j]) * (p2-p1);
		  
		  cntce++;
		  cpe3 = cpe2;
		  cpe2 = cpe1;
		  cpe1 = j;
		  if (cntce >= 3)
		    {
		      ClipPlaneTrig cpt;
		      cpt.elnr = ei;

		      for (k = 0; k < 3; k++)
			{
			  int ednr;
			  switch (k)
			    {
			    case 0: ednr = cpe1; break;
			    case 1: ednr = cpe2; break;
			    case 2: ednr = cpe3; break;
			    }
			  cpt.points[k].p = edgep[ednr];

			  int pi1 = edgei[ednr][0];
			  int pi2 = edgei[ednr][1];
			  Point<3> p1 = pointsloc.Get (loctetsloc[ii][pi1]);
			  Point<3> p2 = pointsloc.Get (loctetsloc[ii][pi2]);
			  for (l = 0; l < 3; l++)
			    cpt.points[k].lami(l) = 
			      edgelam[ednr]     * p1(l) + 
			      (1-edgelam[ednr]) * p2(l);
			}

		      trigs.Append (cpt);
		    }
		}
	    }
	}
      
    }
}

void VisualSceneSolution :: GetClippingPlaneGrid (ARRAY<ClipPlanePoint> & pts)
{
  int i, j, k;
  int np = mesh->GetNV();
  int ne = mesh->GetNE();
  
  Vec3d n(clipplane[0], clipplane[1], clipplane[2]);

  double mu = -clipplane[3] / n.Length2();
  Point3d p(mu*n.X(), mu * n.Y(), mu * n.Z());

  n /= n.Length();
  Vec3d t1, t2;
  n.GetNormal (t1);
  t2 = Cross (n, t1);

  double xi1, xi2;

  double xi1mid = (center - p) * t1;
  double xi2mid = (center - p) * t2;

  pts.SetSize(0);

  int elnr;
  double lami[3];

  for (xi1 = xi1mid-rad; xi1 <= xi1mid+rad; xi1 += rad / gridsize)
    for (xi2 = xi2mid-rad; xi2 <= xi2mid+rad; xi2 += rad / gridsize)
      {
	Point3d hp = p + xi1 * t1 + xi2 * t2;

	elnr = mesh->GetElementOfPoint (hp, lami)-1;

	if (elnr != -1)
	  {
	    ClipPlanePoint cpp;
	    cpp.p = hp;
	    cpp.elnr = elnr;
	    cpp.lam1 = lami[0];
	    cpp.lam2 = lami[1];
	    cpp.lam3 = lami[2];
	    pts.Append (cpp);
	  }
      }
};



void VisualSceneSolution ::
SetOpenGlColor(double h, double hmin, double hmax, int logscale)
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

  if (usetexture)
    {
      glTexCoord1f ( 0.999 * value + 0.001);
      return;
    };

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




void VisualSceneSolution ::
DrawCone (const Point<3> & p1, const Point<3> & p2, double r)
{
  int n = 10, i;
  Vec<3> p1p2 = p2 - p1;

  p1p2.Normalize();
  Vec<3> p2p1 = -p1p2;

  Vec<3> t1 = p1p2.GetNormal();
  Vec<3> t2 = Cross (p1p2, t1);

  Point<3> oldp = p1 + r * t1;
  Vec<3> oldn = t1;

  Point<3> p;
  Vec<3> normal;

  Mat<2> rotmat;
  Vec<2> cs, newcs;
  cs(0) = 1;
  cs(1) = 0;
  rotmat(0,0) = rotmat(1,1) = cos(2*M_PI/n);
  rotmat(1,0) = sin(2*M_PI/n);
  rotmat(0,1) = -rotmat(1,0);

  glBegin (GL_TRIANGLES);
  double phi;
  for (i = 1; i <= n; i++)
    {
      /*
      phi = 2 * M_PI * i / n;
      normal = cos(phi) * t1 + sin(phi) * t2;
      */
      newcs = rotmat * cs;
      cs = newcs;
      normal = cs(0) * t1 + cs(1) * t2;

      p = p1 + r * normal;

      // cone
      glNormal3dv (normal);
      glVertex3dv (p);
      glVertex3dv (p2);
      glNormal3dv (oldn);
      glVertex3dv (oldp);

      // base-circle
      glNormal3dv (p2p1);
      glVertex3dv (p);
      glVertex3dv (p1);
      glVertex3dv (oldp);

      oldp = p;
      oldn = normal;
    }
  glEnd ();
}



void VisualSceneSolution ::
DrawCylinder (const Point<3> & p1, const Point<3> & p2, double r)
{
  int n = 10, i;
  Vec<3> p1p2 = p2 - p1;

  p1p2.Normalize();
  Vec<3> p2p1 = -p1p2;

  Vec<3> t1 = p1p2.GetNormal();
  Vec<3> t2 = Cross (p1p2, t1);

  Point<3> oldhp1 = p1 + r * t1;
  Point<3> oldhp2 = p2 + r * t1;
  Vec<3> oldn = t1;

  Point<3> hp1, hp2;
  Vec<3> normal;

  Mat<2> rotmat;
  Vec<2> cs, newcs;
  cs(0) = 1;
  cs(1) = 0;
  rotmat(0,0) = rotmat(1,1) = cos(2*M_PI/n);
  rotmat(1,0) = sin(2*M_PI/n);
  rotmat(0,1) = -rotmat(1,0);

  glBegin (GL_QUADS);
  double phi;
  for (i = 1; i <= n; i++)
    {
      newcs = rotmat * cs;
      cs = newcs;
      normal = cs(0) * t1 + cs(1) * t2;

      hp1 = p1 + r * normal;
      hp2 = p2 + r * normal;

      // cylinder
      glNormal3dv (normal);

      glVertex3dv (hp1);
      glVertex3dv (hp2);
      glVertex3dv (oldhp2);
      glVertex3dv (oldhp1);

      oldhp1 = hp1;
      oldhp2 = hp2;
      oldn = normal;
    }
  glEnd ();
}













void VisualSceneSolution :: MouseDblClick (int px, int py)
{
  ;
}


void VisualSceneSolution :: 
DrawClipPlaneTrig (const SolData * sol, 
		   int comp,
		   const ClipPlaneTrig & trig, 
		   int level)
{
  int j;
  if (level <= 0)
    for (j = 0; j < 3; j++)
      {
	Point<3> p;
	if (mesh->GetCurvedElements().IsHighOrder())
	  {
	    mesh->GetCurvedElements().
	      CalcElementTransformation (trig.points[j].lami, trig.elnr, p);
	  }
	else
	  p = trig.points[j].p;
	
	if (deform)
	  {
	    Vec<3> def;
	    GetDeformation (trig.elnr, 		    
			    trig.points[j].lami(0),
			    trig.points[j].lami(1),
			    trig.points[j].lami(2), def);
	    p += def;
	  }

	double val = 
	  GetValue (sol, trig.elnr, 
		    trig.points[j].lami(0),
		    trig.points[j].lami(1),
		    trig.points[j].lami(2), scalcomp);
      
	SetOpenGlColor  (val, minval, maxval, logscale);
	glVertex3dv (p);
      }
  else
    {
      Point<3> newp = Center (trig.points[1].p, trig.points[2].p);
      Point<3> newlami = Center (trig.points[1].lami, trig.points[2].lami);
      ClipPlaneTrig t1, t2;
      t1.elnr = t2.elnr = trig.elnr;
      t1.points[0].p = newp;
      t1.points[0].lami = newlami;
      t1.points[1] = trig.points[2];
      t1.points[2] = trig.points[0];
      t2.points[0].p = newp;
      t2.points[0].lami = newlami;
      t2.points[1] = trig.points[0];
      t2.points[2] = trig.points[1];
      DrawClipPlaneTrig (sol, comp, t1, level-1);
      DrawClipPlaneTrig (sol, comp, t2, level-1);
    }
}





int Ng_Vis_Set (ClientData clientData,
		Tcl_Interp * interp,
		int argc, tcl_const char *argv[])

{
  int i;
  if (argc >= 2)
    {
      if (strcmp (argv[1], "parameters") == 0)
	{
	  vssolution.imag_part = 
	    atoi (Tcl_GetVar (interp, "visoptions.imaginary", 0));	  
	  vssolution.usetexture = 
	    atoi (Tcl_GetVar (interp, "visoptions.usetexture", 0));	  
	  vssolution.invcolor = 
	    atoi (Tcl_GetVar (interp, "visoptions.invcolor", 0));	  

	  vssolution.clipsolution = 0;

	  if (strcmp (Tcl_GetVar (interp, "visoptions.clipsolution", 0), 
		      "scal") == 0)
	    vssolution.clipsolution = 1;
	  if (strcmp (Tcl_GetVar (interp, "visoptions.clipsolution", 0), 
		      "vec") == 0)
	    vssolution.clipsolution = 2;
	    
	  const char * scalname = 
	    Tcl_GetVar (interp, "visoptions.scalfunction", 0);
	  const char * vecname = 
	    Tcl_GetVar (interp, "visoptions.vecfunction", 0);
	  
	  vssolution.scalfunction = -1;
	  vssolution.vecfunction = -1;

	  for (i = 0; i < vssolution.soldata.Size(); i++)
	    {
	      if (strlen (vssolution.soldata[i]->name) ==
		  strlen (scalname)-2 &&
		  strncmp (vssolution.soldata[i]->name, scalname,
			   strlen (scalname)-2) == 0)
		{
		  vssolution.scalfunction = i;
		  vssolution.scalcomp = atoi (scalname + strlen(scalname)-1);
		}
	      if (strcmp (vssolution.soldata[i]->name, vecname) == 0)
		vssolution.vecfunction = i;
	    }


	  const char * evalname = 
	    Tcl_GetVar (interp, "visoptions.evaluate", 0);
	  
	  if (strcmp(evalname, "abs") == 0) vssolution.evalfunc = VisualSceneSolution::FUNC_ABS;
	  if (strcmp(evalname, "abstens") == 0) vssolution.evalfunc = VisualSceneSolution::FUNC_ABS_TENSOR;
	  if (strcmp(evalname, "mises") == 0) vssolution.evalfunc = VisualSceneSolution::FUNC_MISES;
	  if (strcmp(evalname, "main") == 0) vssolution.evalfunc = VisualSceneSolution::FUNC_MAIN;

	  vssolution.gridsize = 
	    atoi (Tcl_GetVar (interp, "visoptions.gridsize", 0));

	  vssolution.autoscale = 
	    atoi (Tcl_GetVar (interp, "visoptions.autoscale", 0));

	  /*
	  vssolution.linear_colors = 
	    atoi (Tcl_GetVar (interp, "visoptions.lineartexture", 0));
	  */
	  vssolution.logscale = 
	    atoi (Tcl_GetVar (interp, "visoptions.logscale", 0));

	  vssolution.mminval = 
	    atof (Tcl_GetVar (interp, "visoptions.mminval", 0));
	  vssolution.mmaxval = 
	    atof (Tcl_GetVar (interp, "visoptions.mmaxval", 0));

	  vssolution.showclipsolution = 
	    atoi (Tcl_GetVar (interp, "visoptions.showclipsolution", 0));
	  vssolution.showsurfacesolution = 
	    atoi (Tcl_GetVar (interp, "visoptions.showsurfacesolution", 0));
	  vssolution.lineartexture = 
	    atoi (Tcl_GetVar (interp, "visoptions.lineartexture", 0));
	  vssolution.numtexturecols = 
	    atoi (Tcl_GetVar (interp, "visoptions.numtexturecols", 0));

	  vssolution.draw_fieldlines = 
	    atoi (Tcl_GetVar (interp, "visoptions.drawfieldlines", 0));
	  vssolution.num_fieldlines = 
	    atoi (Tcl_GetVar (interp, "visoptions.numfieldlines", 0));
	  vssolution.fieldlines_randomstart =
	    atoi (Tcl_GetVar (interp, "visoptions.fieldlinesrandomstart", 0));
	    
	  
	  vssolution.deform =
	    atoi (Tcl_GetVar (interp, "visoptions.deformation", 0));
	  vssolution.scaledeform =
	    atof (Tcl_GetVar (interp, "visoptions.scaledeform1", 0)) *
	    atof (Tcl_GetVar (interp, "visoptions.scaledeform2", 0));


	  if (atoi (Tcl_GetVar (interp, "visoptions.isolines", 0)))
	    vssolution.numisolines = atoi (Tcl_GetVar (interp, "visoptions.numiso", 0));
	  else
	    vssolution.numisolines = 0;

	  vssolution.subdivisions = 
	    atoi (Tcl_GetVar (interp, "visoptions.subdivisions", 0));
	  vssolution.UpdateSolutionTimeStamp();
	}
      
      if (argc >= 3 && strcmp (argv[1], "time") == 0)
	{
	  vssolution.time = double (atoi (argv[2])) / 1000;
	  // cout << "time = " << vssolution.time << endl;
	}

    }
  return TCL_OK;
}

int Ng_Vis_Field (ClientData clientData,
		  Tcl_Interp * interp,
		  int argc, tcl_const char *argv[])
{
  int i;
  static char buf[1000];
  buf[0] = 0;

  if (argc >= 2)
    {
      if (strcmp (argv[1], "setfield") == 0)
	{
	  if (argc < 3)
	    return TCL_ERROR;

	  for (i = 0; i < vssolution.GetNSolData(); i++)
	    if (strcmp (vssolution.GetSolData(i)->name, argv[2]) == 0)
	      {
		cout << "found soldata " << i << endl;
	      }
	}

      if (strcmp (argv[1], "getnfieldnames") == 0)
	{
	  sprintf (buf, "%d", vssolution.GetNSolData());
	}
      
      if (strcmp (argv[1], "getfieldname") == 0)
	{
	  sprintf (buf, "%s", vssolution.GetSolData(atoi(argv[2])-1)->name);
	}

      if (strcmp (argv[1], "iscomplex") == 0)
	{
	  sprintf (buf, "%d", vssolution.GetSolData(atoi(argv[2])-1)->iscomplex);
	}

      if (strcmp (argv[1], "getfieldcomponents") == 0)
	{
	  sprintf (buf, "%d", vssolution.GetSolData(atoi(argv[2])-1)->components);
	}

      
      if (strcmp (argv[1], "getfieldnames") == 0)
	{
	  for (i = 0; i < vssolution.GetNSolData(); i++)
	    {
	      strcat (buf, vssolution.GetSolData(i)->name);
	      strcat (buf, " ");
	    }
	  strcat (buf, "var1 var2 var3");
	  Tcl_SetResult (interp, buf, TCL_STATIC);
	}

      if (strcmp (argv[1], "setcomponent") == 0)
	{
	  cout << "set component " << argv[2] << endl;
	}

      if (strcmp (argv[1], "getactivefield") == 0)
	{
	  sprintf (buf, "1");
	}

      if (strcmp (argv[1], "getdimension") == 0)
	{
	  sprintf (buf, "%d", mesh->GetDimension());
	}
    }

  Tcl_SetResult (interp, buf, TCL_STATIC);
  return TCL_OK;
}


extern "C" int Ng_Vis_Init (Tcl_Interp * interp);

int Ng_Vis_Init (Tcl_Interp * interp)
{
  Tcl_CreateCommand (interp, "Ng_Vis_Set", Ng_Vis_Set,
		     (ClientData)NULL,
		     (Tcl_CmdDeleteProc*) NULL);

  Tcl_CreateCommand (interp, "Ng_Vis_Field", Ng_Vis_Field,
		     (ClientData)NULL,
		     (Tcl_CmdDeleteProc*) NULL);


  return TCL_OK;
}
}
