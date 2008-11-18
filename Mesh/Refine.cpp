/*
 *  refine.cpp
 *  GMSH
 *
 *  Created by Brian Helenbrook on 11/13/08.
 *  Copyright 2008 Clarkson University. All rights reserved.
 *
 */
#include "HighOrder.h"
#include "meshGFaceOptimize.h"
#include "MElement.h"
#include "GmshMessage.h"
#include "OS.h"
#include "Numeric.h"
#include "Context.h"
#include "GmshMatrix.h"
#include "FunctionSpace.h"

void Subdivide(GEdge *ge)
{
	std::vector<MLine *> lines2;
	for(unsigned int i = 0; i < ge->lines.size(); i++){
		MLine3 *l = dynamic_cast<MLine3 *>(ge->lines[i]);
		lines2.push_back(new MLine(l->getVertex(0), l->getVertex(2)));
		lines2.push_back(new MLine(l->getVertex(2), l->getVertex(1)));
		delete l;
	}
	ge->lines = lines2;
	ge->deleteVertexArrays();
}

void Subdivide(GFace *gf)
{
	std::vector<MTriangle*> triangles2;
	for(unsigned int i = 0; i < gf->triangles.size(); i++){
		MTriangle6 *t = dynamic_cast<MTriangle6 *>(gf->triangles[i]);
		triangles2.push_back
		(new MTriangle(t->getVertex(0), t->getVertex(3), t->getVertex(5)));
		triangles2.push_back
		(new MTriangle(t->getVertex(3), t->getVertex(4), t->getVertex(5)));
		triangles2.push_back
		(new MTriangle(t->getVertex(3), t->getVertex(1), t->getVertex(4)));
		triangles2.push_back
		(new MTriangle(t->getVertex(5), t->getVertex(4), t->getVertex(2)));
		delete t;
	}
	gf->triangles = triangles2;
	
	std::vector<MQuadrangle*> quadrangles2;
	for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
		MQuadrangle9 *q = dynamic_cast<MQuadrangle9 *>(gf->quadrangles[i]);
		quadrangles2.push_back
		(new MQuadrangle(q->getVertex(0), q->getVertex(4), q->getVertex(8), q->getVertex(7)));
		quadrangles2.push_back
		(new MQuadrangle(q->getVertex(4), q->getVertex(1), q->getVertex(5), q->getVertex(8)));
		quadrangles2.push_back
		(new MQuadrangle(q->getVertex(8), q->getVertex(5), q->getVertex(2), q->getVertex(6)));
		quadrangles2.push_back
		(new MQuadrangle(q->getVertex(7), q->getVertex(8), q->getVertex(6), q->getVertex(3)));
		
		delete q;
	}
	gf->quadrangles = quadrangles2;
	gf->deleteVertexArrays();
}

void Subdivide(GRegion *gr)
{
	
	std::vector<MTetrahedron*> tetrahedra2;
	for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
		MTetrahedron10 *t = dynamic_cast<MTetrahedron10 *>(gr->tetrahedra[i]);
		
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(0), t->getVertex(4), t->getVertex(7), t->getVertex(6)));
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(1), t->getVertex(4), t->getVertex(5), t->getVertex(9)));
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(2), t->getVertex(5), t->getVertex(6), t->getVertex(8)));
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(3), t->getVertex(7), t->getVertex(9), t->getVertex(8)));
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(5), t->getVertex(8), t->getVertex(7), t->getVertex(9)));
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(5), t->getVertex(7), t->getVertex(4), t->getVertex(9)));
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(7), t->getVertex(8), t->getVertex(5), t->getVertex(6)));
		tetrahedra2.push_back
		(new MTetrahedron(t->getVertex(4), t->getVertex(7), t->getVertex(5), t->getVertex(6)));
		delete t;
	}
	gr->tetrahedra = tetrahedra2;
	
	std::vector<MHexahedron*> hexahedra2;
	for(unsigned int i = 0; i < gr->hexahedra.size(); i++){
		MHexahedron27 *h = dynamic_cast<MHexahedron27 *>(gr->hexahedra[i]);
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(0), h->getVertex(8), h->getVertex(20), h->getVertex(9),
					     h->getVertex(10), h->getVertex(21), h->getVertex(26), h->getVertex(22)));
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(10), h->getVertex(21), h->getVertex(26), h->getVertex(22),
					     h->getVertex(4), h->getVertex(16), h->getVertex(25), h->getVertex(17)));
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(8), h->getVertex(1), h->getVertex(11), h->getVertex(20),
					     h->getVertex(21), h->getVertex(12), h->getVertex(23), h->getVertex(26)));
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(21), h->getVertex(12), h->getVertex(23), h->getVertex(26),
					     h->getVertex(16), h->getVertex(5), h->getVertex(18), h->getVertex(25)));
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(9), h->getVertex(20), h->getVertex(13), h->getVertex(3),
					     h->getVertex(22), h->getVertex(26), h->getVertex(24), h->getVertex(15)));
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(22), h->getVertex(26), h->getVertex(24), h->getVertex(15),
					     h->getVertex(17), h->getVertex(25), h->getVertex(19), h->getVertex(7)));
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(20), h->getVertex(11), h->getVertex(2), h->getVertex(13),
					     h->getVertex(26), h->getVertex(23), h->getVertex(14), h->getVertex(24)));
		hexahedra2.push_back
		(new MHexahedron(h->getVertex(26), h->getVertex(23), h->getVertex(14), h->getVertex(24),
					     h->getVertex(25), h->getVertex(18), h->getVertex(6), h->getVertex(19)));
		delete h;
	}
	gr->hexahedra = hexahedra2;
	
	std::vector<MPrism*> prisms2;
	for(unsigned int i = 0; i < gr->prisms.size(); i++){
		MPrism18 *p = dynamic_cast<MPrism18 *>(gr->prisms[i]);

		prisms2.push_back
		(new MPrism(p->getVertex(0), p->getVertex(6), p->getVertex(7), 
					p->getVertex(8), p->getVertex(15), p->getVertex(16)));
		prisms2.push_back
		(new MPrism(p->getVertex(8), p->getVertex(15), p->getVertex(16), 
					p->getVertex(3), p->getVertex(12), p->getVertex(13)));		
		prisms2.push_back
		(new MPrism(p->getVertex(6), p->getVertex(1), p->getVertex(9), 
					p->getVertex(15), p->getVertex(10), p->getVertex(17)));		
		prisms2.push_back
		(new MPrism(p->getVertex(15), p->getVertex(10), p->getVertex(17), 
					p->getVertex(12), p->getVertex(4), p->getVertex(14)));		
		prisms2.push_back
		(new MPrism(p->getVertex(7), p->getVertex(9), p->getVertex(2), 
					p->getVertex(16), p->getVertex(17), p->getVertex(11)));		
		prisms2.push_back
		(new MPrism(p->getVertex(16), p->getVertex(17), p->getVertex(11), 
					p->getVertex(13), p->getVertex(14), p->getVertex(5)));		
		prisms2.push_back
		(new MPrism(p->getVertex(9), p->getVertex(7), p->getVertex(6), 
					p->getVertex(17), p->getVertex(16), p->getVertex(15)));		
		prisms2.push_back
		(new MPrism(p->getVertex(17), p->getVertex(16), p->getVertex(15), 
					p->getVertex(14), p->getVertex(13), p->getVertex(12)));
			  
		delete p;
	}
	gr->prisms = prisms2;


	std::vector<MPyramid*> pyramids2;
	for(unsigned int i = 0; i < gr->pyramids.size(); i++){
		MPyramid14 *p = dynamic_cast<MPyramid14 *>(gr->pyramids[i]);
		
		/* BASE */
		pyramids2.push_back
		(new MPyramid(p->getVertex(0), p->getVertex(5), p->getVertex(13), p->getVertex(6), p->getVertex(7)));
		pyramids2.push_back
		(new MPyramid(p->getVertex(5), p->getVertex(1), p->getVertex(8), p->getVertex(13), p->getVertex(9)));
		pyramids2.push_back
		(new MPyramid(p->getVertex(13), p->getVertex(8), p->getVertex(2), p->getVertex(10), p->getVertex(11)));
		pyramids2.push_back
		(new MPyramid(p->getVertex(6), p->getVertex(13), p->getVertex(10), p->getVertex(3), p->getVertex(12)));

		/* Split remaining into tets */
		/* Top */
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(7), p->getVertex(9), p->getVertex(12), p->getVertex(4))));
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(9), p->getVertex(11), p->getVertex(12), p->getVertex(4))));		
		
		/* Upside down one */
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(9), p->getVertex(12), p->getVertex(11), p->getVertex(13))));
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(7), p->getVertex(12), p->getVertex(9), p->getVertex(13))));	
								  
								  
		 /* Four tets around bottom perimeter */
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(7), p->getVertex(9), p->getVertex(5), p->getVertex(13))));
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(9), p->getVertex(11), p->getVertex(8), p->getVertex(13))));	
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(12), p->getVertex(10), p->getVertex(11), p->getVertex(13))));
		gr->tetrahedra.push_back(
		(new MTetrahedron(p->getVertex(7), p->getVertex(6), p->getVertex(12), p->getVertex(13))));	
		delete p;
	}
	gr->pyramids = pyramids2;
	gr->deleteVertexArrays();
}






void Refine(GModel *m, bool linear)
{
	//   refine all edges in a mesh by inserting a point on the midpoint
	//   then recreate edge, face, and region definitions
	//
	// - if linear is set to true, new vertices are created by linear
	//   interpolation between existing ones. If not, new vertices are
	//   created on the exact geometry, provided that the geometrical
	//   edges/faces are discretized with 1D/2D elements. (I.e., if
	//   there are only 3D elements in the mesh then any new vertices on
	//   the boundary will always be created by linear interpolation,
	//   whether linear is set or not.)

	
#if !defined(HAVE_GSL)
	Msg::Error("Mesh refinement requires the GSL");
	return;
#endif
		
	Msg::StatusBar(1, true, "Generating refined mesh ...");
	double t1 = Cpu();
	
	// first, set order to 2 to generate vertex positions
	SetOrderN(m, 2, linear, false);
	
    // Now subdivide entities to create linear mesh
	for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
		Subdivide(*it);

	for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
		Subdivide(*it);
	
	for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
		Subdivide(*it);
		
	double t2 = Cpu();
	Msg::Info("Mesh refinement complete (%g s)", t2 - t1);
	Msg::StatusBar(1, true, "Mesh");
}
