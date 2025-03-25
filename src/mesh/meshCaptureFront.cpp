#include <set>
#include <vector>

#include "GModel.h"
#include "MEdge.h"
#include "MFace.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionDelaunayInsertion.h"
#include "meshCaptureFront.h"

static double faceQuality (MFace &mf, std::map<int,int> &n2p){
  MVertex *v0 = mf.getVertex(0);
  MVertex *v1 = mf.getVertex(1);
  MVertex *v2 = mf.getVertex(2);
  int p0 = n2p[v0->getNum()];
  int p1 = n2p[v1->getNum()];
  int p2 = n2p[v2->getNum()];
  double qual= -1;
  if (p0 == p1 && p0 == p2) qual = 10000;
  else if (p0*p2 >= 0 && p0*p1 >= 0 && p2*p1 >=0) qual = drand48()*1000;
  else qual = - drand48()*10000 ;

  //  printf("edge %lu %lu p %d %d -> qual %g\n",v0->getNum(),v1->getNum(),p0,p1,qual);

  return qual;
}

static double edgeQuality (MEdge &me, std::map<int,int> &n2p){
  MVertex *v0 = me.getVertex(0);
  MVertex *v1 = me.getVertex(1);
  int p0 = n2p[v0->getNum()];
  int p1 = n2p[v1->getNum()];
  double qual;
  if (p0 == p1) qual = 10000;
  else if (p0 * p1 == 0) qual = drand48()*1000;
  else qual = - drand48()*10000 ;

  //  printf("edge %lu %lu p %d %d -> qual %g\n",v0->getNum(),v1->getNum(),p0,p1,qual);

  return qual;
}


static double qualityFct (MVertex *v00, MVertex *v11, std::vector<MVertex*> &cavity, void *data) {
  std::set<MFace, MFaceLessThan> fcs;
  std::map<int,int> *n2p = (std::map<int,int> *) data;

  //  double qmin = 1.0;
  for (size_t i=0; i<cavity.size(); i+=4){
    MVertex *v0 = cavity[i];
    MVertex *v1 = cavity[i+1];
    MVertex *v2 = cavity[i+2];
    MVertex *v3 = cavity[i+3];
    fcs.insert(MFace(v0,v1,v2));
    fcs.insert(MFace(v0,v1,v3));
    fcs.insert(MFace(v0,v2,v3));
    fcs.insert(MFace(v1,v2,v3));
    double vol;
    double qi = qmTetrahedron::qm(v0,v1,v2,v3,qmTetrahedron::QMTET_GAMMA,&vol);
    //    qmin = std::min(qi,qmin);
  }
  
  {
    double qual = 0.0;
    for (auto f : fcs){
      qual += faceQuality (f, *n2p);
    }
    //  printf("nedges %lu quality %g\n",eds.size(),qual);
    return qual;///eds.size();  
  }
  

  std::set<MEdge, MEdgeLessThan> eds;
  for (size_t i=0; i<cavity.size(); i+=4){
    MVertex *v0 = cavity[i];
    MVertex *v1 = cavity[i+1];
    MVertex *v2 = cavity[i+2];
    MVertex *v3 = cavity[i+3];
    eds.insert(MEdge(v0,v1));
    eds.insert(MEdge(v0,v2));
    eds.insert(MEdge(v0,v3));
    eds.insert(MEdge(v1,v2));
    eds.insert(MEdge(v1,v3));
    eds.insert(MEdge(v2,v3));
    //    double qi = qmTetrahedron::qm(v0,v1,v2,v3,qmTetrahedron::QMTET_GAMMA);    
  }
  {
    double qual = 0.0;
    for (auto e : eds){
      qual += edgeQuality (e, *n2p);
    }
    //  printf("nedges %lu quality %g\n",eds.size(),qual);
    return qual;///eds.size();
  }
}

bool buildEdgeCavity(MTet4 *t, int iLocalEdge, MVertex **v1, MVertex **v2,
                     std::vector<MTet4 *> &cavity,
                     std::vector<MTet4 *> &outside,
                     std::vector<MVertex *> &ring);


static void swapEdgesForCapturingTheFront (std::vector<MTet4 *> &allTets, std::map<int,int> &n2p,
					   int &nb_swaps, int &nb_invalid, bool debug = false) {
  std::vector<MTet4 *> newTets;
  static int edges[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};

  FILE *f = nullptr;

  if (debug){
    f = fopen("sw.pos","w");
    fprintf(f,"View\"\"{\n");
  }
  
  nb_swaps=0;
  nb_invalid=0;
  std::set<std::pair<int,int> > eds;
  for(auto it = allTets.begin(); it != allTets.end(); ++it) {    
    if(!(*it)->isDeleted()) {
      for(int i = 0; i < 6; i++) {

	std::vector<MTet4 *> cavity;
	std::vector<MTet4 *> outside;
	std::vector<MVertex *> ring;
	MVertex *v1, *v2;
	bool closed = buildEdgeCavity((*it), i, &v1, &v2, cavity, outside, ring);
	
	int p0 = n2p[(*it)->tet()->getVertex(edges[i][0])->getNum()];
	int p1 = n2p[(*it)->tet()->getVertex(edges[i][1])->getNum()];
	std::pair<int,int> pp = std::make_pair(std::min((*it)->tet()->getVertex(edges[i][0])->getNum(),
							(*it)->tet()->getVertex(edges[i][1])->getNum()),
					       std::max((*it)->tet()->getVertex(edges[i][0])->getNum(),
							(*it)->tet()->getVertex(edges[i][1])->getNum()));	
	if (eds.find(pp) == eds.end() && closed && p1*p0 < 0){
	  if (!closed) printf("Error -- invlaid bndry edge\n");
	  eds.insert(pp);
	  //	  printf("edge swap custom -- %d %d\n",(*it)->tet()->getVertex(edges[i][0])->getNum(),
	  //		 (*it)->tet()->getVertex(edges[i][1])->getNum());
	  if (p1*p0 < 0) {
	    nb_invalid++;
	    if (debug){
	      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",v1->x(),v1->y(),v1->z(),v2->x(),v2->y(),v2->z());
	      printf("ring size %lu closed %d\n",ring.size(),closed);
	      for (size_t k=0;k<ring.size();k++){
		fprintf(f,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){2,2,2,2};\n",
			v1->x(),v1->y(),v1->z(),v2->x(),v2->y(),v2->z(),
			ring[k]->x(),ring[k]->y(),ring[k]->z(),
			ring[(k+1)%ring.size()]->x(),ring[(k+1)%ring.size()]->y(),ring[(k+1)%ring.size()]->z());
	      }
	    }
	  }
	  if(edgeSwapCustom(newTets, *it, i, &n2p, qualityFct)) {
	    nb_swaps++;
	    //	    printf("swap done\n");
	    break;
	  }
	}
      }
    }
  }

  if (debug){
    fprintf(f,"};\n");
    fclose(f);
  }

  
  std::set<MTetrahedron*> to_delete;
  for(std::size_t i = 0; i < newTets.size(); i++) {
    if(!newTets[i]->isDeleted()) { allTets.push_back(newTets[i]); }
    else {
      to_delete.insert(newTets[i]->tet());
      delete newTets[i];
    }
  }
  for(auto t : to_delete) delete t;
}


static void meshCaptureFront2D (GFace *gf, std::map<int,int> &n2p)
{
}

static void meshCaptureFront3D (GRegion *gr, std::map<int,int> &n2p)
{
  const qmTetrahedron::Measures qm = qmTetrahedron::QMTET_GAMMA;
  std::vector<MTet4 *> allTets;
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    MTet4 *t = new MTet4(gr->tetrahedra[i], qm);
    t->setOnWhat(gr);
    allTets.push_back(t);
  }
  gr->tetrahedra.clear();
  connectTets(allTets,nullptr);

  int iter = 0;
  int ns, ninv;
  while(1){
    iter ++;
    swapEdgesForCapturingTheFront (allTets, n2p,ns,ninv);
    printf("ITER %d %d %d\n",iter,ns,ninv);
    if (ns == 0){
      if (ninv == 0)Msg::Info("Front captured for region %d",gr->tag());
      if (ninv != 0)Msg::Info("Front not totally captured for region %d -- %d invalid edges",gr->tag(),ninv);
      break;
    }
    if (iter == 160){
      Msg::Info("Front not captured for region %d -- %d illegal edges remain",gr->tag(),ns);
      break;
    }
  }


  if (ninv) {
    swapEdgesForCapturingTheFront (allTets, n2p,ns,ninv,true);
  }
  
  for(auto it = allTets.begin(); it != allTets.end(); ++it) {
    if(!(*it)->isDeleted()) {
      gr->tetrahedra.push_back((*it)->tet());
      delete *it;
    }
    else {
      delete(*it)->tet();
      delete *it;
    }
  }
}

void meshCaptureFront (const std::vector<int> &nodes, const std::vector<int> &phases)
{
  std::map<int,int> n2p;
  for (size_t i=0;i<nodes.size();i++)n2p[nodes[i]] = phases [i];
  GModel *gm = GModel::current()->current();  
  
  for (GModel::riter rit = gm->firstRegion() ; rit != gm->lastRegion() ; ++rit) {
    meshCaptureFront3D (*rit, n2p);
  }
  
  for (GModel::fiter fit = gm->firstFace() ; fit != gm->lastFace() ; ++fit) {
    meshCaptureFront2D (*fit, n2p);
  }    
}
