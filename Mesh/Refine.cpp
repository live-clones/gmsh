// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Brian Helenbrook
//

#include "HighOrder.h"
#include "MElement.h"
#include "GmshMessage.h"
#include "OS.h"

static void Subdivide(GEdge *ge)
{
  std::vector<MLine*> lines2;
  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MLine *l = ge->lines[i];
    if(l->getNumVertices() == 3){
      lines2.push_back(new MLine(l->getVertex(0), l->getVertex(2)));
      lines2.push_back(new MLine(l->getVertex(2), l->getVertex(1)));
    }
    delete l;
  }
  ge->lines = lines2;

  for(unsigned int i = 0; i < ge->mesh_vertices.size(); i++)
    ge->mesh_vertices[i]->setPolynomialOrder(1);
  ge->deleteVertexArrays();
}

static void Subdivide(GFace *gf)
{
  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    if(t->getNumVertices() == 6){
      triangles2.push_back
        (new MTriangle(t->getVertex(0), t->getVertex(3), t->getVertex(5)));
      triangles2.push_back
        (new MTriangle(t->getVertex(3), t->getVertex(4), t->getVertex(5)));
      triangles2.push_back
        (new MTriangle(t->getVertex(3), t->getVertex(1), t->getVertex(4)));
      triangles2.push_back
        (new MTriangle(t->getVertex(5), t->getVertex(4), t->getVertex(2)));
    }
    delete t;
  }
  gf->triangles = triangles2;
  
  std::vector<MQuadrangle*> quadrangles2;
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    if(q->getNumVertices() == 9){
      quadrangles2.push_back
        (new MQuadrangle(q->getVertex(0), q->getVertex(4), q->getVertex(8), q->getVertex(7)));
      quadrangles2.push_back
        (new MQuadrangle(q->getVertex(4), q->getVertex(1), q->getVertex(5), q->getVertex(8)));
      quadrangles2.push_back
        (new MQuadrangle(q->getVertex(8), q->getVertex(5), q->getVertex(2), q->getVertex(6)));
      quadrangles2.push_back
        (new MQuadrangle(q->getVertex(7), q->getVertex(8), q->getVertex(6), q->getVertex(3)));
    }
    delete q;
  }
  gf->quadrangles = quadrangles2;

  for(unsigned int i = 0; i < gf->mesh_vertices.size(); i++)
    gf->mesh_vertices[i]->setPolynomialOrder(1);
  gf->deleteVertexArrays();
}

static void Subdivide(GRegion *gr)
{
  std::vector<MTetrahedron*> tetrahedra2;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTetrahedron *t = gr->tetrahedra[i];
    if(t->getNumVertices() == 10){
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
    }
    delete t;
  }
  gr->tetrahedra = tetrahedra2;
  
  std::vector<MHexahedron*> hexahedra2;
  for(unsigned int i = 0; i < gr->hexahedra.size(); i++){
    MHexahedron *h = gr->hexahedra[i];
    if(h->getNumVertices() == 27){
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
    }
    delete h;
  }
  gr->hexahedra = hexahedra2;
  
  std::vector<MPrism*> prisms2;
  for(unsigned int i = 0; i < gr->prisms.size(); i++){
    MPrism *p = gr->prisms[i];
    if(p->getNumVertices() == 18){
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
    }      
    delete p;
  }
  gr->prisms = prisms2;
  
  std::vector<MPyramid*> pyramids2;
  for(unsigned int i = 0; i < gr->pyramids.size(); i++){
    MPyramid *p = gr->pyramids[i];
    if(p->getNumVertices() == 14){
      // BASE
      pyramids2.push_back
        (new MPyramid(p->getVertex(0), p->getVertex(5), p->getVertex(13), 
                      p->getVertex(6), p->getVertex(7)));
      pyramids2.push_back
        (new MPyramid(p->getVertex(5), p->getVertex(1), p->getVertex(8), 
                      p->getVertex(13), p->getVertex(9)));
      pyramids2.push_back
        (new MPyramid(p->getVertex(13), p->getVertex(8), p->getVertex(2), 
                      p->getVertex(10), p->getVertex(11)));
      pyramids2.push_back
        (new MPyramid(p->getVertex(6), p->getVertex(13), p->getVertex(10),
                      p->getVertex(3), p->getVertex(12)));
      
      // Split remaining into tets
      // Top
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(7), p->getVertex(9), p->getVertex(12), p->getVertex(4))));
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(9), p->getVertex(11), p->getVertex(12), p->getVertex(4))));
      
      // Upside down one
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(9), p->getVertex(12), p->getVertex(11), p->getVertex(13))));
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(7), p->getVertex(12), p->getVertex(9), p->getVertex(13))));
      
      // Four tets around bottom perimeter
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(7), p->getVertex(9), p->getVertex(5), p->getVertex(13))));
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(9), p->getVertex(11), p->getVertex(8), p->getVertex(13))));
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(12), p->getVertex(10), p->getVertex(11), p->getVertex(13))));
      gr->tetrahedra.push_back
        ((new MTetrahedron(p->getVertex(7), p->getVertex(6), p->getVertex(12), p->getVertex(13))));
    }
    delete p;
  }
  gr->pyramids = pyramids2;

  for(unsigned int i = 0; i < gr->mesh_vertices.size(); i++)
    gr->mesh_vertices[i]->setPolynomialOrder(1);
  gr->deleteVertexArrays();
}

void RefineMesh(GModel *m, bool linear)
{
  Msg::StatusBar(1, true, "Refining mesh...");
  double t1 = Cpu();
	
  // Create 2nd order mesh (using "2nd order complete" elements) to
  // generate vertex positions
  SetOrderN(m, 2, linear, false);
	
  // Subdivide the second order elements to create the refined linear
  // mesh
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    Subdivide(*it);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    Subdivide(*it);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    Subdivide(*it);

  double t2 = Cpu();
  Msg::Info("Mesh refinement complete (%g s)", t2 - t1);
  Msg::StatusBar(1, false, "Mesh");
}
