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
      for (auto it = indices.begin() ; it != indices.end() ; ++it)
	inv [it->second] = it->first;
      for (auto it = symmetrical_indices.begin() ; it != symmetrical_indices.end() ; ++it)
	inv [it->second] = it->first;
      structured_block_2D b;
      b.ni = maxIndexi - minIndexi + 1;
      b.nj = maxIndexj - minIndexj + 1;
      Msg::Info("Block %d x %d found\n",b.ni,b.nj);
      for (auto it = inv.begin() ; it != inv.end() ; ++it) b.block.push_back(it->second);
      
      blocks.push_back(b);
      
      // FILE *f = fopen("block1.pos","w");
      // for (int j=0;j<b.nj;j++) {
      //   fprintf(f,"View \"line_%i\" {\n",j);
      //   for (int i=0;i<b.ni;i++) fprintf(f,"SP(%g,%g,%g){%i};\n",
      //                                    b.block[b.idx(i,j)]->x(),
      //                                    b.block[b.idx(i,j)]->y(),
      //                                    b.block[b.idx(i,j)]->z(),i);
      //   fprintf(f,"};\n");
      // }
      // fclose(f); 
    }    
  }
}

// -----------------------------------------------------------------------------

bool structured_block_2D::getTopology()  {

  // --- need underlying face 
  
  face = dynamic_cast<GFace*>(block[idx(1,1)]->onWhat());
  if (!face) return false;
  
  for (int i=1;i<ni-1;i++) {
    for (int j=1;j<nj-1;j++) {
      if (dynamic_cast<GFace*>(block[idx(i,j)]->onWhat())!=face) return false;
    }
  }

  // --- check whether the grid is periodic 
  
  periodic = block[idx(0,0)] == block[idx(ni-1,0)];

  if (periodic) {
    for (int j=1;j<nj;j++) {
      if (block[idx(0,j)]!=block[idx(ni-1,j)]) periodic = false;
    }
    if (!periodic) Msg::Warning("Incomplete periodicity in boundary layer mesh");
  }

  // --- if not periodic, check whether points should conform to an edge or a node
  
  if (!periodic) {
    for (int j=0;j<nj;j++) {
      e0.push_back(dynamic_cast<GEdge*  >(block[idx(0   ,j)]->onWhat()));
      e1.push_back(dynamic_cast<GEdge*  >(block[idx(ni-1,j)]->onWhat()));
    }
  }
  
  return true;
}

// -----------------------------------------------------------------------------

struct Mat2 {

  Mat2() {*this = 0;}

  Mat2(double a11,double a12,double a21,double a22) {
    A[0] = a11; A[1] = a12; A[2] = a21; A[3] = a22;
  }
  
  inline Mat2& operator=(double a) {
    A[0] = A[1] = A[2] = A[3] = a;
    return *this;
  }

  inline Mat2& operator=(const Mat2& o) {
    std::copy_n(o.A,4,A);
    return *this;
  }
  
  inline Mat2& operator+=(const Mat2& o) {
    for (int i=0;i<4;i++) A[i] += o.A[i];
    return *this;
  }

  inline Mat2& operator-=(const Mat2& o) {
    for (int i=0;i<4;i++) A[i] -= o.A[i];
    return *this;
  }
  
  inline Mat2& operator*=(double a) {
    for (int i=0;i<4;i++) A[i] *= a;
    return *this;
  }

  SPoint2 eigen() const {
    double b = -(A[0]+A[3]);
    double c = determinant();
    double D = b*b - 4*c;
    return SPoint2((-b - std::sqrt(D))/2,(-b + std::sqrt(D))/2);
  }

  double specRad() const {
    SPoint2 eig = eigen();
    return std::max(std::abs(eig[0]),std::abs(eig[1]));
  }
  
  inline Mat2& operator/=(double a) {
    for (int i=0;i<4;i++) A[i] /= a;
    return *this;
  }

  inline double determinant() const {return A[0]*A[3]-A[1]*A[2];}
  
  inline double& operator()(int i,int j) {return A[i*2+j];}
  
  inline const double& operator()(int i,int j) const {return A[i*2+j];}

  inline Mat2& invert() {
    double det = 1./determinant();
    std::swap(A[0],A[3]);
    A[0] *= det;
    A[1] *= - det;
    A[2] *= - det;
    A[3] *= det;
    return *this;
  }

  inline void mult(const Mat2& A1,Mat2& A2,double a,double b) const {
    Mat2 tmp(A2);
    tmp *= b;
    tmp(0,0) += a*(A[0]*A1(0,0) + A[1]*A1(1,0));
    tmp(0,1) += a*(A[0]*A1(0,1) + A[1]*A1(1,1));
    tmp(1,0) += a*(A[2]*A1(0,0) + A[3]*A1(1,0));
    tmp(1,1) += a*(A[2]*A1(0,1) + A[3]*A1(1,1));
    A2 = tmp;
  }

  inline void mult(const SPoint2& v1,SPoint2& v2,double a,double b) const {
    SPoint2 tmp(b*v2[0],b*v2[1]);
    tmp[0] += a*(A[0]*v1[0] + A[1]*v1[1]);
    tmp[1] += a*(A[2]*v1[0] + A[3]*v1[1]);
    v2 = tmp;
  }

  inline void setZero()     {A[0] = A[1] =    A[2] = A[3] = 0;}
  inline void setIdentity() {A[0] = A[3] = 1; A[1] = A[2] = 0;}
  
protected:
  
  double A[4];
  
};

Mat2 operator*(double a,Mat2 A) {
  A *= a;
  return A;
}

void decompose(std::vector<std::map<int,Mat2> >& mat) {
  
  for (size_t i=0;i<mat.size();i++) {

    auto AiiIt = mat[i].find(i);
    Mat2& Aii = AiiIt->second;
    Aii.invert();
    for (size_t j=i+1;j<mat.size();j++) {
      auto AjiIt = mat[j].find(i);
      if (AjiIt != mat[j].end()) {
        
        Mat2& Aji = AjiIt->second;
        Aji.mult(Aii,Aji,-1,0);
        auto AikIt = AiiIt;
        for (AikIt++;AikIt!=mat[i].end();AikIt++) {
          int k = AikIt->first;
          const Mat2& Aik = AikIt->second;
          Aji.mult(Aik,mat[j][k],1,1);
        }
      }
    }
  }
}

void solve(std::vector<std::map<int,Mat2> >& mat,
           const std::vector<SPoint2>& b,
           std::vector<SPoint2>& x) {
  
  x = b;
  
  for (size_t i=1;i<mat.size();i++) {
    std::map<int,Mat2>& row = mat[i];
    auto AiiIt = row.find(i);
    for (auto AijIt = row.begin();AijIt!=AiiIt;++AijIt) {
      int j = AijIt->first;
      const Mat2& Aij = AijIt->second;   
      Aij.mult(x[j],x[i],1,1);
    }
  }

  for (int i=mat.size()-1;i>=0;i--) {
    std::map<int,Mat2>& row = mat[i];
    auto AiiIt = row.find(i);
    auto AijIt = AiiIt;
    for (AijIt++;AijIt!=row.end();AijIt++) {
      int j = AijIt->first;
      const Mat2& Aij = AijIt->second;
      Aij.mult(x[j],x[i],-1,1);
    }
    const Mat2& Aii = AiiIt->second;
    
    Aii.mult(x[i],x[i],1,0);
  }
}

// -----------------------------------------------------------------------------

bool structured_block_2D::hyperbolic_smooth() {
  
  // --- get topological information 
  
  if (!getTopology()) {
    Msg::Error("Incoherent topology for hyperbolic smoothing");
    return false;
  }

  // --- allocate and initialise coordinates
  
  std::vector<SPoint2> par(ni*nj);
  std::vector<SPoint3> xyz(ni*nj);
  
  for (int j=0;j<nj;j++) {
    for (int i=0;i<ni;i++) {
      xyz[idx(i,j)] = block[idx(i,j)]->point();
      par[idx(i,j)]  = face->parFromPoint(xyz[idx(i,j)]);
    }
  }
  
  // --- compute normal spacing 
  
  std::vector<double> dn(ni*nj,0);
  
  for (int i=0;i<ni;i++) {
    for (int j=0;j<nj-1;j++) {
      dn[idx(i,j)] = xyz[idx(i,j)].distance(xyz[idx(i,j+1)])/2;
    }
  }
    
  // --- smooth each layer

  int nbPts = periodic ? ni-1:ni;

  std::vector<std::map<int,Mat2> > mat(nbPts);
  
  std::vector<SPoint2> h(nbPts);
  std::vector<SPoint2> uv0(ni);
  std::vector<SPoint2> uv1(ni);

  std::vector<double> J0(ni);
  std::vector<double> F0(ni);

  std::vector<SPoint2> uvXi0(ni);
  std::vector<SPoint2> uvEta0(ni);

  Mat2 I;
  I.setIdentity();

  for (int i=0;i<nbPts;i++) uv0[i] = par[idx(i,0)];

  int nbIterations = 3;
  
  for (int j=1;j<nj;j++) { 
    
    // --- compute solver
    
    for (int i=0;i<nbPts;i++) uv1[i] = par[idx(i,j)];
    
    for (int i=0;i<nbPts;i++) {
      
      Pair<SVector3,SVector3> rUV = face->firstDer(uv0[i]);
      
      const SVector3& ru = rUV.first();
      const SVector3& rv = rUV.second();

      double J = J0[i] = crossprod(ru,rv).norm(); 

      double guu = dot(ru,ru);
      double guv = dot(ru,rv);
      double gvv = dot(rv,rv);
      
      SPoint2& uvXi = uvXi0[i];
      uvXi  = uv0[iP(i)] - uv0[iM(i)];
      uvXi /= dI(i);
      
      SVector3 rxi = uvXi[0]*ru + uvXi[1]*rv;
      
      double F = F0[i] = 2*rxi.norm()*dn[idx(i,j-1)];
      
      SPoint2& uvEta = uvEta0[i];
      
      uvEta[0] = - F/J*(guv*uvXi[0] + gvv*uvXi[1])/rxi.normSq();
      uvEta[1] =   F/J*(guu*uvXi[0] + guv*uvXi[1])/rxi.normSq();     
    }
    
    for (int iter=0;iter<nbIterations;++iter) {
      
      for (int i=0;i<nbPts;i++) {

        std::map<int,Mat2>& row = mat[i];
        for (auto it=row.begin();it!=row.end();++it) it->second = 0;
        
        // --- compute metrics 
        
        Pair<SVector3,SVector3> rUV = face->firstDer(uv1[i]);

        const SVector3& ru = rUV.first();
        const SVector3& rv = rUV.second();

        double J = crossprod(ru,rv).norm();
        
        double guu = dot(ru,ru);
        double guv = dot(ru,rv);
        double gvv = dot(rv,rv);

        const SPoint2& uvXiM  = uvXi0[i];
        const SPoint2& uvEtaM = uvEta0[i];

        // --- main system
        
        Mat2 A;
        A(0,0) = guu*uvEtaM[0] + guv*uvEtaM[1];
        A(0,1) = guv*uvEtaM[0] + gvv*uvEtaM[1];
        A(1,0) =   J*uvEtaM[1];
        A(1,1) = - J*uvEtaM[0];
        A /= dI(i);

        Mat2 B;
        B(0,0) = guu*uvXiM[0] + guv*uvXiM[1];
        B(0,1) = guv*uvXiM[0] + gvv*uvXiM[1];
        B(1,0) = - J*uvXiM[1];
        B(1,1) =   J*uvXiM[0];

        B.invert();
        B.mult(A,A,1,0);

        row[i] = I;
        row[iP(i)] += A;
        row[iM(i)] -= A;

        // --- add diffusion 
        
        if (periodic || i%(ni-1) == 0) {
          double lambda = A.specRad();
          row[iP(i)] -= lambda*I;
          row[iM(i)] -= lambda*I;
          row[i]     += 2*lambda*I;
        }
        
        // --- compute right hand side

        SPoint2 uvEta = uv1[i] - uv0[i];
        SPoint2 uvXi  = uv1[iP(i)] - uv1[iM(i)];
        uvXi /= dI(i);

        SVector3 rxi = uvXi[0]*ru + uvXi[1]*rv;
        
        double F = F0[i]; // 2*rxi.norm() * dn[idx(i,j-1)];
        
        h[i][0] = (guu*uvXiM[0]*uvEtaM[0] +
                   guv*uvXiM[0]*uvEtaM[1] +
                   guv*uvXiM[1]*uvEtaM[0] +
                   gvv*uvXiM[1]*uvEtaM[1]);
        
        h[i][1] = (F + J*F0[i]/J0[i]);
        
        B.mult(h[i],h[i],1,0);

        h[i][0] += uv0[i][0];
        h[i][1] += uv0[i][1];

        // --- boundary conditions 
        
        if (!periodic && i%(ni-1) == 0) {
          
          GEdge* ge = i == 0 ? e0[j]:e1[j];

          if (!ge) {
            row[iP(i)] = row[iM(i)] = 0;
            row[i] = I;
            h[i] = uv1[i];
          }
          
          else {
            
            Mat2 g(guu,guv,guv,gvv);
            g.invert();
            double s = ge->parFromPoint(xyz[idx(i,j)]);
            SVector3 rs = ge->firstDer(s);
            SPoint2  uvs(dot(ru,rs),dot(rv,rs));
            g.mult(uvs,uvs,1,0);
            
            Mat2 P(uvs[0],uvs[1],0,0);
            P.mult(row[i],row[i],1,0);
            
            row[i](1,0) = - uvs[1];
            row[i](1,1) =   uvs[0];
            
            if (row.find(i+1)!=row.end()) P.mult(row[i+1],row[i+1],1,0);
            if (row.find(i-1)!=row.end()) P.mult(row[i-1],row[i-1],1,0);
            
            P.mult(h[i],h[i],1,0);
            h[i][1] = - uvs[1]*uv0[i][0] + uvs[0]*uv0[i][1];
          }
            
        }
      }
      
      // --- solve
      
      decompose(mat);
      solve(mat,h,uv1);
    }

    // --- did not solve for ni-1
    
    if (periodic) uv1[ni-1] = uv1[0];

    // --- update the coordinates
    
    for (int i=0;i<ni;i++) {
      MVertex* v = block[idx(i,j)];
      GPoint p = face->point(uv1[i]);
      v->setXYZ(p.x(),p.y(),p.z());
    }
    
    uv0 = uv1;
  }
  
  // FILE *f = fopen("block2.pos","w");
  // for (int j=0;j<nj;j++) {
  //   fprintf(f,"View \"line_%i\" {\n",j);
  //   for (int i=0;i<ni;i++) fprintf(f,"SP(%g,%g,%g){%i};\n",
  //                                    block[idx(i,j)]->x(),
  //                                    block[idx(i,j)]->y(),
  //                                    block[idx(i,j)]->z(),i);
  //   fprintf(f,"};\n");
  // }
  // fclose(f); 
  
  return true;
}

// -----------------------------------------------------------------------------
