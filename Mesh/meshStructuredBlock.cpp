#include <algorithm>
#include <set>
#include <stack>
#include "meshStructuredBlock.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MQuadrangle.h"

#include "GFace.h"
#include "GEdge.h"

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
	     int &minIndexi, int &maxIndexi, int &minIndexj, int &maxIndexj,
	     std::map<MVertex*,std::pair<int,int>> &symmetrical_indices){
  int i=0;
  for ( ; i<4 ; i++){
    MVertex *v0 = q->getVertex(i);
    MVertex *v1 = q->getVertex((i+1)%4);
    MVertex *v2 = q->getVertex((i+2)%4);
    MVertex *v3 = q->getVertex((i+3)%4);
    //    printf("Quad %lu %lu %lu %lu\n",v0->getNum(),v1->getNum(),v2->getNum(),v3->getNum());
    std::map<MVertex*,std::pair<int,int>>::iterator it0 = indices.find(v0);
    std::map<MVertex*,std::pair<int,int>>::iterator it1 = indices.find(v1);
    std::map<MVertex*,std::pair<int,int>>::iterator it2 = indices.find(v2);
    std::map<MVertex*,std::pair<int,int>>::iterator it3 = indices.find(v3);
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
	  if (it2 != indices.end() && p2 != it2->second)symmetrical_indices[v2] = it2->second;
	  if (it3 != indices.end() && p3 != it3->second)symmetrical_indices[v3] = it3->second;
	  indices [v2] = p2;
	  indices [v3] = p3;	  
	}
	// down edge
	else if (i01 == i11 - 1){
	  std::pair<int,int> p2 = std::make_pair(i10+1,i11);
	  std::pair<int,int> p3 = std::make_pair(i10+1,i01);
	  //	  printf("down %d %d %d %d\n", i10+1,i11, i10+1,i01);
	  maxIndexi = std::max(i10+1,maxIndexi);
	  if (it2 != indices.end() && p2 != it2->second)symmetrical_indices[v2] = it2->second;
	  if (it3 != indices.end() && p3 != it3->second)symmetrical_indices[v3] = it3->second;
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
	  if (it2 != indices.end() && p2 != it2->second)symmetrical_indices[v2] = it2->second;
	  if (it3 != indices.end() && p3 != it3->second)symmetrical_indices[v3] = it3->second;
	  indices [v2] = p2;
	  indices [v3] = p3;	  
	}
	// left edge
	else if (i10 == i00 - 1){
	  std::pair<int,int> p2 = std::make_pair(i10,i11+1);
	  std::pair<int,int> p3 = std::make_pair(i00,i11+1);
	  maxIndexj = std::max(i11+1,maxIndexj);
	  //	  printf("left %d %d %d %d\n", i10,i11+1, i00,i11+1);
	  if (it2 != indices.end() && p2 != it2->second)symmetrical_indices[v2] = it2->second;
	  if (it3 != indices.end() && p3 != it3->second)symmetrical_indices[v3] = it3->second;
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
    if (!fanQuad(q,indices_i)){
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

  for (auto q : blquads){
    if (touched.find(q) == touched.end() && !fanQuad(q,indices_i)){
      std::map<MVertex*,std::pair<int,int>> indices;
      std::map<MVertex*,std::pair<int,int>> symmetrical_indices;
      int minIndexi, maxIndexi, minIndexj, maxIndexj;
      std::set<MQuadrangle*> _s;
      _s.insert(q);
      numberAll (q, indices_j,indices, minIndexi, maxIndexi, minIndexj, maxIndexj);
      while (!_s.empty()){
        MQuadrangle *_q = *(_s.begin());
	touched.insert(_q);
	for (size_t i = 0 ; i<4 ; i++){
	  MEdge e = _q->getEdge(i);
	  std::map<MEdge, edgeNeigh, MEdgeLessThan> :: iterator it = ens.find(e);
	  MQuadrangle *_neigh = it->second._q1 == _q ? it->second._q2 : it->second._q1 ;
	  if (_neigh && touched.find(_neigh) == touched.end()
              && _s.find(_neigh) == _s.end()
              && !fanQuad(_neigh,indices_i)){
            _s.insert(_neigh);
	    for (size_t j = 0 ; j<4 ; j++){	      
	      MEdge e_neigh = _neigh->getEdge(j);
	      if (e == e_neigh){
		if (e.getVertex(0) == e_neigh.getVertex(0)){
		  _neigh->reverse();
		  j  = 4;
		}
	      }
	    }
	    number (_neigh, indices, minIndexi, maxIndexi, minIndexj, maxIndexj, symmetrical_indices);	    
	  }
	}
        _s.erase(_q);
      }
      std::map<std::pair<int,int>, MVertex*> inv;
      for (std::map<MVertex*,std::pair<int,int>>::iterator it = indices.begin() ; it != indices.end() ; ++it)
	inv [it->second] = it->first;
      for (std::map<MVertex*,std::pair<int,int>>::iterator it = symmetrical_indices.begin() ; it != symmetrical_indices.end() ; ++it)
	inv [it->second] = it->first;
      structured_block_2D b;
      b.ni = maxIndexi - minIndexi + 1;
      b.nj = maxIndexj - minIndexj + 1;
      Msg::Info("Block %d x %d found\n",b.ni,b.nj);
      for (std::map<std::pair<int,int>, MVertex*>::iterator it = inv.begin() ; it != inv.end() ; ++it)
	b.block.push_back(it->second);

      //      if (b.block[0] == b.block[0]
      blocks.push_back(b);
      
      char name[256];
      sprintf(name,"block%lu.pos",blocks.size());
      FILE *f = fopen(name,"w");
      for (int j=0;j<b.nj;j++) {
        fprintf(f,"View \"%s_%i\" {\n",name,j);
        for (int i=0;i<b.ni;i++) fprintf(f,"SP(%g,%g,%g){%i};\n",
                                         b.block[b.index(i,j)]->x(),
                                         b.block[b.index(i,j)]->y(),
                                         b.block[b.index(i,j)]->z(),i);
        fprintf(f,"};\n");
      }
      fclose(f); 
    }    
  }
}

// -----------------------------------------------------------------------------

bool structured_block_2D::getTopology()  {

  // --- need underlying face 
  
  face = dynamic_cast<GFace*>(block[index(1,1)]->onWhat());
  if (!face) return false;
  
  for (int i=1;i<ni-1;i++) {
    for (int j=1;j<nj-1;j++) {
      if (dynamic_cast<GFace*>(block[index(i,j)]->onWhat())!=face) return false;
    }
  }

  Msg::Info("Computing hyperbolic grid on %i",face->tag());

  // // --- get boundaries 
  
  // GEdge* south = dynamic_cast<GEdge*>(block[index(1,0   )]->onWhat());
  // GEdge* north = dynamic_cast<GEdge*>(block[index(1,nj-1)]->onWhat());
  
  // if (!south) return false; // require south base

  // for (int i=1;i<ni-1;i++) {
  //   if (dynamic_cast<GEdge*>(block[index(i,   0)]->onWhat())!=south) return false;
  //   if (dynamic_cast<GEdge*>(block[index(i,nj-1)]->onWhat())!=north) return false;
  // }

  // GEdge* east = dynamic_cast<GEdge*>(block[index(0,1)]->onWhat());
  // GEdge* west = dynamic_cast<GEdge*>(block[index(ni-1,1)]->onWhat());
  
  // for (int j=1;j<nj-1;j++) {
  //   if (dynamic_cast<GEdge*>(block[index(0   ,j)]->onWhat())!=east) return false;
  //   if (dynamic_cast<GEdge*>(block[index(ni-1,j)]->onWhat())!=west) return false;
  // }
  
  // edges[0] = south;
  // edges[1] = east;
  // edges[2] = north;
  // edges[3] = west;

  // // --- get corners
  
  // nodes[0] = dynamic_cast<GVertex*>(block[index(0   ,0   )]->onWhat());
  // nodes[1] = dynamic_cast<GVertex*>(block[index(ni-1,0   )]->onWhat());
  // nodes[2] = dynamic_cast<GVertex*>(block[index(ni-1,nj-1)]->onWhat());
  // nodes[3] = dynamic_cast<GVertex*>(block[index(0   ,nj-1)]->onWhat());

  return true;
}

// -----------------------------------------------------------------------------

struct Mat2 {

  Mat2() {*this = 0;}

  inline Mat2& operator=(double a) {
    mat[0] = mat[1] = mat[2] = mat[3] = a;
    return *this;
  }

  inline Mat2& operator=(const Mat2& o) {
    std::copy_n(o.mat,4,mat);
    return *this;
  }

  inline Mat2& operator*=(double a) {
    for (int i=0;i<4;i++) mat[i] *= a;
    return *this;
  }

  inline double& operator()(int i,int j) {return mat[j*2+i];}
  
  inline const double& operator()(int i,int j) const {return mat[j*2+i];}

  inline Mat2& invert() {
    double det = 1./(mat[0]*mat[2] - mat[1]*mat[3]);
    std::swap(mat[0],mat[3]);
    mat[0] *= det;
    mat[1] *= - det;
    mat[2] *= - det;
    mat[3] *= det;
    return *this;
  }

  inline void mult(const Mat2& A1,Mat2& A2,double a,double b) const {
    Mat2 tmp(A2);
    tmp *= b;
    tmp(0,0) += a*(mat[0]*A1(0,0) + mat[1]*A1(1,0));
    tmp(0,1) += a*(mat[0]*A1(0,1) + mat[1]*A1(1,1));
    tmp(1,0) += a*(mat[2]*A1(0,0) + mat[3]*A1(1,0));
    tmp(1,1) += a*(mat[2]*A1(0,1) + mat[3]*A1(1,1));
    A2 = tmp;
  }

  inline void mult(const SPoint2 v1,SPoint2 v2,double a,double b) const {
    SPoint2 tmp(b*v2[0],b*v2[1]);
    tmp[0] += a*(mat[0]*v1[0] + mat[1]*v1[1]);
    tmp[1] += a*(mat[2]*v1[0] + mat[3]*v1[1]);
    v2 = tmp;
  }

  inline void setZero()     {mat[0] = mat[1] =    mat[2] = mat[3] = 0;}
  inline void setIdentity() {mat[0] = mat[3] = 1; mat[1] = mat[2] = 0;}
  
protected:
  
  double mat[4];
  
};

// -----------------------------------------------------------------------------

void decompose(std::vector<Mat2>& D, // diagonal         (k,k)   k = 0,n
               std::vector<Mat2>& L, // lower diagonal   (k,k-1) k = 0,n-1
               std::vector<Mat2>& U, // upper diagonal   (k-1,k) k = 0,n-1
               std::vector<Mat2>& pL, // periodic row    (k,n-1) k = 0,n-2
               std::vector<Mat2>& pU, // periodic column (n-1,k) k = 0,n-2
               bool periodic) {

  int n = D.size();

  for (int i=0;i<n-1;i++) {
  
    D[i].invert(); // invert pivot
    L[i].mult(D[i],L[i],-1,0); // reduction factor line i+1
    L[i].mult(U[i],D[i+1],1,1); // upper diagonal contributes to diagonal
    
    if (periodic && i < n-2) {
      
      L[i].mult(pU[i],pU[i+1],1,1); // reduction on periodic column

      pL[i].mult(D[i] ,pL[i],-1,0); // reduction factor periodic row      
      pL[i].mult(U[i],pL[i+1],1,1); // upper diagonal impact on lower periodic
      
      pL[i].mult(pU[i],D[n-1],1,1); // upper periodic reduction diagonal
    }
  }
  D[n-1].invert();
}

// -----------------------------------------------------------------------------

void solve(const std::vector<Mat2>& D, // diagonal         (k,k)   k = 1,n
           const std::vector<Mat2>& L, // lower diagonal   (k+1,k) k = 1,n-1
           const std::vector<Mat2>& U, // upper diagonal   (k,k+1) k = 1,n-1
           const std::vector<Mat2>& pL, // periodic row    (k,n) k = 1,n-1
           const std::vector<Mat2>& pU, // periodic column (n,k) k = 1,n-1
           const std::vector<SPoint2>& b, // right hand side
           std::vector<SPoint2>& x,
           bool periodic) {

  int n = D.size();
  
  std::copy_n(b.begin(),n,x.begin());
  
  // forward substitution
  
  for (int i=1;i<n-1;i++)          L[i-1].mult(x[i-1],x[i],1,1);
  if (periodic) for (int i=0;i<n-2;i++) pL[i].mult(x[i],x[n-1],1,1);

  // find last entry
  
  D[n-1].mult(x[n-1],x[n-1],1,0);

  // backward substitution
  
  for (int i=n-2;i>=0;i--) {
    U[i].mult(x[i+1],x[i],1,1);
    if (periodic && i<n-2) pU[i].mult(x[n-1],x[i],1,1);
    D[i].mult(x[i],x[i],1,0);
  }
}

// -----------------------------------------------------------------------------

bool structured_block_2D::hyperbolic_smooth() {
  
  // // --- get topological information 
  
  // if (!getTopology()) {
  //   Msg::Error("Incoherent topology for hyperbolic smoothing");
  //   return false;
  // }

  // // --- allocate and initialise coordinates
  
  // std::vector<SPoint2> par(ni*nj);
  // std::vector<SPoint3> xyz(ni*nj);

  // int idx = 0;
  // for (int j=0;j<nj;j++) {
  //   for (int i=0;i<ni;i++,idx++) {
  //     xyz[idx] = block[idx]->point();
  //     par[idx]  = face->parFromPoint(xyz[idx]);
  //   }
  // }

  // Msg::Info("Computed parametrisation of hyperbolic grid");

  // // --- compute normal spacing 
  
  // std::vector<double> dn(ni*(nj-1),0);

  // idx = 0;
  // for (int j=0;j<nj-1;j++) {
  //   for (int i=0;i<ni;i++,idx++) {
  //     dn[i] = xyz[idx].distance(xyz[idx+ni]);
  //   }
  // }
  
  // Msg::Info("Computed distance in hyperbolic grid");
  
  // // --- smooth each layer

  // periodic = true;
  // int nbPts = periodic ? ni-1:ni;

  // Msg::Info("Have %i points",nbPts);
  
  // std::vector<Mat2> D(nbPts);  // diagonal 
  // std::vector<Mat2> L(nbPts);  // one below the diagonal
  // std::vector<Mat2> U(nbPts);  // one above the diagonal 
  // std::vector<Mat2> pL(nbPts); // periodic row at n-1
  // std::vector<Mat2> pU(nbPts); // periodic column n-1
  
  // std::vector<SPoint2> h(nbPts);
  // std::vector<SPoint2> uv0(ni);
  // std::vector<SPoint2> uv1(ni);

  // std::vector<double> J0(ni);
  // std::vector<double> A0(ni);

  // std::vector<SVector3> uvEta0(ni);
  // std::vector<SVector3> uvXi0(ni);

  // for (int i=0;i<nbPts;i++) uv0[i] = par[index(i,0)];
  
  // Msg::Info("Initialised derivatives on first line of hyperbolic grid");

  // int nbIterations = 1;
  
  // for (int j=1;j<nj-1;j++) { 
    
  //   // --- compute solver
    
  //   for (int i=0;i<nbPts;i++) uv1[i] = par[index(i,j)];
    
  //   for (int i=0;i<nbPts;i++) {
      
  //     Pair<SVector3,SVector3> rUV = face->firstDer(uv0[i]);
      
  //     SVector3 ru = rUV.first();
  //     SVector3 rv = rUV.second();

  //     J0[i] = crossprod(ru,rv).norm();
      
  //     int ip = periodic ? (i+1)%(nbPts-1)           : std::max(i-1,0);
  //     int im = periodic ? ((i-1)+nbPts-1)%(nbPts-1) : std::min(i+1,nbPts-1);
  //     int di = std::min(std::abs(ip-im),2);
      
  //     SPoint2 uvXi(uv0[ip],uv0[im]);
  //     uvXi0[i]  = uv0[ip] - uv0[im];
  //     uvXi0[i] /= di;

  //     ru *= uvXi[0];
  //     rv *= uvXi[1];
      
  //     rXi0[i] = ru + rv;

  //     F0[i] = rxi.norm()*dn[i*nj+(j-1)];
      
  //   }
    
  //   for (int iter=0;iter<nbIterations;++iter) {

  //     for (int i=0;i<nbPts;i++) D[i] = L[i] = U[i] = pL[i] = pU[i] = 0;
      
  //     for (int i=0;i<nbPts;i++) {
        
  //       Pair<SVector3,SVector3> rUV = face->firstDer(uv1[i]);

  //       SVector3 ru = rUV.first();
  //       SVector3 rv = rUV.second();

  //       double J = crossprod(ru,rv).norm();
        
  //       double guu = dot(ru,rv);
  //       double guv = dot(ru,rv);
  //       double gvv = dot(rv,rv);
        
  //       Mat2 B;
  //       B(0,0) = guu*uvEta0[i][0] + guv*uvEta0[i][1];
  //       B(0,1) = guv*uvEta0[i][0] + gvv*uvEta0[i][1];
  //       B(1,0) =   J*uvEta0[i][1];
  //       B(1,1) = - J*uvEta0[i][0];
        
  //       SPoint2& uvXi0  = metric0[i].uvXi;
        
  //       Mat2 A;
  //       A(0,0) = guu*uvXi0[i][0] + guv*uvXi0[i][1];
  //       A(0,1) = guv*uvXi0[i][0] + gvv*uvXi0[i][1];
  //       A(1,0) = - J*uvXi0[i][1];
  //       A(1,1) =   J*uvXi0[i][0];

  //       // 
        
  //       B.mult(A,A,1,0);
        
  //       // --- general treatment 
        
  //       L[i].setIdentity();
  //       U[i].setIdentity();
  //       D[i] = A;

  //       // --- periodicity
        
  //       if (periodic) {
  //         pU[0] = L[0];
  //         pL[0] = U[0];
  //         pU[nbPts-2] = U[nbPts-1];
  //       }
        
  //       h[i][0] = 0;
  //       h[i][1] = F * J + F0[i]*J0[i]/J;
  //     }
      
  //     // solve

  //     Msg::Info("Composed the system");
      
  //     decompose(L,D,U,pL,pU,periodic);

  //     Msg::Info("Decomposed the matrix");

  //     solve(L,D,U,pL,pU,h,uv1,periodic);

  //     Msg::Info("Solved the system");

  //   }

  //   if (periodic) uv1[ni-1] = uv1[0];
    
  //   for (int i=0;i<ni;i++) {
  //     MVertex* v = block[index(i,j)];
  //     GPoint p = face->point(uv1[i]);
  //     v->setXYZ(p.x(),p.y(),p.z());
  //   }
    
  //   uv0 = uv1;
  //   metric0 = metric1;    
  // }
  // return true;
}

// -----------------------------------------------------------------------------
