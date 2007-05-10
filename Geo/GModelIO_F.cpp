#include <string>
#include "GModel.h"
#include "Message.h"
#include "Context.h"
#include "Views.h"
#include "FFace.h"
#include "meshGFace.h" 
#include "GModelIO_F.h"

#if defined(HAVE_FOURIER_MODEL)

extern Context_T CTX;

void F_Internals::loadF(const char *fn)
{
  _reader = new FM_Reader((char*)fn);
}

void F_Internals::buildGModel(GModel *model)
{
  // building geom vertices
  int nVertices = _reader->GetNumVertices();
  for (int i=0;i<nVertices;i++) {
    FVertex* v = new FVertex(model,i,_reader->GetVertex(i));
    model->add(v);
  }
  // building geom edges
  int nEdges = _reader->GetNumEdges();
  for (int i=0;i<nEdges;i++) {
    FM_Edge* edge = _reader->GetEdge(i);
    int i1 = edge->GetStartPoint()->GetTag();
    int i2 = edge->GetEndPoint()->GetTag();
    GVertex *v1 = model->vertexByTag(i1);
    GVertex *v2 = model->vertexByTag(i2);
    FEdge *e = new FEdge(model, edge, i, v1, v2);
    model->add(e);
  }
  // building geom faces
  int nFaces = _reader->GetNumFaces();
  for(int i=0;i<nFaces;i++){
    FM_Face* face = _reader->GetFace(i);
    std::list<GEdge*> l_edges;
    for (int j=0;j<face->GetNumEdges();j++) {
      int tag = face->GetEdge(j)->GetTag(); 
     l_edges.push_back(model->edgeByTag(tag));
    }
    FFace *f = new FFace(model, face, i, l_edges);
    model->add(f);
  }
}

int GModel::readF(const std::string &fn)
{
  f_internals = new F_Internals;
  f_internals->loadF(fn.c_str());
  f_internals->buildGModel(this);

  return 1;
}

#else

int GModel::readF(const std::string &fn)
{
  Msg(GERROR,"Gmsh has to be compiled with Fourier Model support to load %s",
      fn.c_str());
  return 0;
}

#endif
