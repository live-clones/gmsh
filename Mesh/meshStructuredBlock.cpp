#include <algorithm>
#include <set>
#include <stack>
#include "meshStructuredBlock.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MQuadrangle.h"

struct edgeNeigh {
  MQuadrangle* _q1, *_q2;
  edgeNeigh (MQuadrangle* q1 = nullptr) : _q1(q1), _q2(nullptr){
  }
};

static void numberAll (MQuadrangle *q, std::map<MVertex*,int> & indices_j,
		       std::map<MVertex*,std::pair<int,int>> &indices,
		       int &minIndexi, int &maxIndexi, int &minIndexj, int &maxIndexj){
  int i=0;
  for ( ; i<4 ; i++){
    MVertex *v0 = q->getVertex(i);
    MVertex *v1 = q->getVertex((i+1)%4);
    int index0 = indices_j[v0];
    int index1 = indices_j[v1];
    if (index1 > index0)break;
  }
  std::pair<int,int> p0 = std::make_pair(0,0);
  std::pair<int,int> p1 = std::make_pair(0,1);
  std::pair<int,int> p2 = std::make_pair(1,1);
  std::pair<int,int> p3 = std::make_pair(1,0);
  indices [q->getVertex(i)] = p0;
  indices [q->getVertex((i+1)%4)] = p1;
  indices [q->getVertex((i+2)%4)] = p2;
  indices [q->getVertex((i+3)%4)] = p3;
  minIndexi = minIndexj = 0;
  maxIndexi = maxIndexj = 1;
}

void number (MQuadrangle *q, std::map<MVertex*,std::pair<int,int>> &indices,
	     int &minIndexi, int &maxIndexi, int &minIndexj, int &maxIndexj){
  int i=0;
  for ( ; i<4 ; i++){
    MVertex *v0 = q->getVertex(i);
    MVertex *v1 = q->getVertex((i+1)%4);
    MVertex *v2 = q->getVertex((i+2)%4);
    MVertex *v3 = q->getVertex((i+3)%4);
    //    printf("Quad %lu %lu %lu %lu\n",v0->getNum(),v1->getNum(),v2->getNum(),v3->getNum());
    std::map<MVertex*,std::pair<int,int>>::iterator it0 = indices.find(v0);
    std::map<MVertex*,std::pair<int,int>>::iterator it1 = indices.find(v1);
    if (it0 != indices.end() && it1 != indices.end()){
      int i00 = it0->second.first;
      int i01 = it0->second.second;
      int i10 = it1->second.first;
      int i11 = it1->second.second;
      //      printf("%d --> %d %d %d %d\n",i, i00,i01,i10,i11);
      if (i00 == i10){
	// up edge
	if (i01 == i11 + 1){	  
	  std::pair<int,int> p2 = std::make_pair(i10-1,i11);
	  std::pair<int,int> p3 = std::make_pair(i10-1,i01);
	  minIndexi = std::min(i10-1,minIndexi);
	  //	  printf("up %d %d %d %d\n", i10-1,i11, i10-1,i01);
	  indices [v2] = p2;
	  indices [v3] = p3;	  
	}
	// down edge
	else if (i01 == i11 - 1){
	  std::pair<int,int> p2 = std::make_pair(i10+1,i11);
	  std::pair<int,int> p3 = std::make_pair(i10+1,i01);
	  //	  printf("down %d %d %d %d\n", i10+1,i11, i10+1,i01);
	  maxIndexi = std::max(i10+1,maxIndexi);
	  indices [v2] = p2;
	  indices [v3] = p3;	  
	}
	else Msg::Warning ("Error in indexing (%d %d) (%d %d)",i00,i01,i10,i11);
      }
      else if (i01 == i11){
	// right edge
	if (i10 == i00 + 1){
	  std::pair<int,int> p2 = std::make_pair(i10,i11-1);
	  std::pair<int,int> p3 = std::make_pair(i00,i11-1);
	  minIndexj = std::min(i11-1,minIndexj);
	  //	  printf("right %d %d %d %d\n", i10,i11-1, i00,i11-1);
	  indices [v2] = p2;
	  indices [v3] = p3;	  
	}
	// left edge
	else if (i10 == i00 - 1){
	  std::pair<int,int> p2 = std::make_pair(i10,i11+1);
	  std::pair<int,int> p3 = std::make_pair(i00,i11+1);
	  maxIndexj = std::max(i11+1,maxIndexj);
	  //	  printf("left %d %d %d %d\n", i10,i11+1, i00,i11+1);
	  indices [v2] = p2;
	  indices [v3] = p3;	  
	}
	else Msg::Warning ("Error in indexing (%d %d) (%d %d)",i00,i01,i10,i11);
      }      
      else Msg::Warning ("Error in indexing (%d %d) (%d %d)",i00,i01,i10,i11);
      //      getchar();
      return;
    }
  }
}


static bool fanQuad (MQuadrangle *q, std::map<MVertex*,MVertex*> & indices_i){
  int i=0;
  for ( ; i<4 ; i++){
    MVertex *v0 = q->getVertex(i);
    MVertex *v1 = q->getVertex((i+1)%4);
    MVertex* origin0 = indices_i[v0];
    MVertex* origin1 = indices_i[v1];
    if (origin0 != origin1)return false;
  }
  //  printf("fanquad found\n");
  return true;
}


void computeStructuredBlocks (std::vector<MQuadrangle *> &blquads,
			      std::map<MVertex*,MVertex*> & indices_i,
			      std::map<MVertex*,int> & indices_j,
			      std::vector<structured_block_2D> &blocks){
  std::map<MEdge, edgeNeigh, MEdgeLessThan> ens;
  for (auto q : blquads){
    for (size_t i = 0 ; i<4 ; i++){
      MEdge e = q->getEdge(i);
      std::map<MEdge, edgeNeigh, MEdgeLessThan> :: iterator it = ens.find(e);
      if (it == ens.end()){
	edgeNeigh en (q);
	ens[e] = en;
      }
      else it->second._q2 = q;
    }
  }


  /*  printf("%lu quads %lu edges\n",blquads.size(), ens.size());
  for (auto q : blquads){
    MVertex *v0 = q->getVertex(0);
    MVertex *v1 = q->getVertex(1);
    MVertex *v2 = q->getVertex(2);
    MVertex *v3 = q->getVertex(3);
    printf("%d %d %d %d\n",indices_j[v0],indices_j[v1],indices_j[v2],indices_j[v3]);
  }
  */
  
  // ---------------------------------------
  // Orient all quads topologically
  // ---------------------------------------
  
  std::set<MQuadrangle*> touched;
  std::map<MVertex*,std::pair<int,int>> indices;

  for (auto q : blquads){
    if (touched.find(q) == touched.end() && !fanQuad(q,indices_i)){
      int minIndexi, maxIndexi, minIndexj, maxIndexj;
      std::stack<MQuadrangle*> _s;
      _s.push(q);
      numberAll (q, indices_j,indices, minIndexi, maxIndexi, minIndexj, maxIndexj);
      while (!_s.empty()){
	MQuadrangle *_q = _s.top();
	touched.insert(_q);
	_s.pop();
	for (size_t i = 0 ; i<4 ; i++){
	  MEdge e = _q->getEdge(i);
	  std::map<MEdge, edgeNeigh, MEdgeLessThan> :: iterator it = ens.find(e);
	  MQuadrangle *_neigh = it->second._q1 == _q ? it->second._q2 : it->second._q1 ;
	  if (_neigh && touched.find(_neigh) == touched.end() && !fanQuad(_neigh,indices_i)){
	    _s.push(_neigh);
	    for (size_t j = 0 ; j<4 ; j++){	      
	      MEdge e_neigh = _neigh->getEdge(j);
	      if (e == e_neigh){
		if (e.getVertex(0) == e_neigh.getVertex(0)){
		  _neigh->reverse();
		  j  = 4;
		}
	      }
	    }
	    number (_neigh, indices, minIndexi, maxIndexi, minIndexj, maxIndexj);	    
	  }
	}
      }
      std::map<std::pair<int,int>, MVertex*> inv;
      for (std::map<MVertex*,std::pair<int,int>>::iterator it = indices.begin() ; it != indices.end() ; ++it)
	inv [it->second] = it->first;
      structured_block_2D b;
      b.ni = maxIndexi - minIndexi;
      b.nj = maxIndexj - minIndexj;
      Msg::Info("Block %d x %d found\n",b.ni,b.nj);
      for (std::map<std::pair<int,int>, MVertex*>::iterator it = inv.begin() ; it != inv.end() ; ++it)
	b.block.push_back(it->second);
      blocks.push_back(b);
    }    
  }
}
