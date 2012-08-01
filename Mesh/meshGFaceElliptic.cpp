// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stack>
#include "GmshConfig.h"
#include "meshGFaceElliptic.h"
#include "qualityMeasures.h"
#include "GFace.h"
#include "GEdge.h"
#include "GEdgeCompound.h"
#include "GVertex.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Generator.h"
#include "Context.h"
#include "OS.h"
#include "SVector3.h"
#include "SPoint3.h"
#include "fullMatrix.h"
#include "CenterlineField.h"
#if defined(HAVE_ANN)
#include <ANN/ANN.h>
#endif

#define TRAN_QUAD(c1,c2,c3,c4,s1,s2,s3,s4,u,v) \
    (1.-u)*c4+u*c2+(1.-v)*c1+v*c3-((1.-u)*(1.-v)*s1+u*(1.-v)*s2+u*v*s3+(1.-u)*v*s4)


static void printQuads(GFace *gf, fullMatrix<SPoint2> uv, std::vector<MQuadrangle*> quads,  int iter){

  char name[234];
  sprintf(name,"quadUV_%d_%d.pos", gf->tag(), iter);
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"%s\" {\n",name);

  for (int i = 1; i < uv.size1()-1; i++)
    for (int j = 0; j < uv.size2(); j++)
      fprintf(f,"SP(%g,%g,%g) {%d};\n", uv(i,j).x(), uv(i,j).y(), 0.0, i);

  fprintf(f,"};\n");
  fclose(f);

  char name3[234];
  sprintf(name3,"quadXYZ_%d_%d.pos", gf->tag(), iter);
  FILE *f3 = fopen(name3,"w");
  fprintf(f3,"View \"%s\" {\n",name3);
  for (unsigned int i = 0; i < quads.size(); i++){
    quads[i]->writePOS(f3,true,false,false,false,false,false);
  }
  fprintf(f3,"};\n");
  fclose(f3);

}

static void printParamGrid(GFace *gf, std::vector<MVertex*> vert1, std::vector<MVertex*> vert2,
			   std::vector<MVertex*> e01, std::vector<MVertex*> e10,
			   std::vector<MVertex*> e23, std::vector<MVertex*> e32,
			   std::vector<MVertex*> e02, std::vector<MVertex*> e13,
			   std::vector<MQuadrangle*> quads)
{

  std::vector<SPoint2> p1,p2;
  for (unsigned int i = 0; i< vert1.size(); i++){
    SPoint2 pi;
    reparamMeshVertexOnFace(vert1[i], gf, pi);
    p1.push_back(pi);
  }
  for (unsigned int j = 0; j< vert2.size(); j++){
    SPoint2 pj;
    reparamMeshVertexOnFace(vert2[j], gf, pj);
    p2.push_back(pj);
  }


  char name[234];
  sprintf(name,"paramGrid_%d.pos", gf->tag());
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"%s\" {\n",name);

  // for (unsigned int i = 0; i < p1.size(); i++)
  //   fprintf(f,"SP(%g,%g,%g) {%d};\n", p1[i].x(), p1[i].y(), 0.0, i);
  // for (unsigned int j = 0; j < p2.size(); j++)
  //   fprintf(f,"SP(%g,%g,%g) {%d};\n", p2[j].x(), p2[j].y(), 0.0, 100+j);

   for (unsigned int i = 0; i < p1.size()-1; i++)
     fprintf(f,"SL(%g,%g,%g,%g,%g,%g) {%d,%d};\n", p1[i].x(), p1[i].y(), 0.0, p1[i+1].x(), p1[i+1].y(), 0.0, 1, 1);
   for (unsigned int i = 0; i < p2.size()-1; i++)
     fprintf(f,"SL(%g,%g,%g,%g,%g,%g) {%d,%d};\n", p2[i].x(), p2[i].y(), 0.0, p2[i+1].x(), p2[i+1].y(), 0.0, 1, 1);
   fprintf(f,"SL(%g,%g,%g,%g,%g,%g) {%d,%d};\n", p1[p1.size()-1].x(), p1[ p1.size()-1].y(), 0.0, p1[0].x(), p1[0].y(), 0.0, 1, 1);
   fprintf(f,"SL(%g,%g,%g,%g,%g,%g) {%d,%d};\n", p2[p2.size()-1].x(), p2[ p2.size()-1].y(), 0.0, p2[0].x(), p2[0].y(), 0.0, 1, 1);

  fprintf(f,"};\n");
  fclose(f);

  char name2[234];
  sprintf(name2,"paramEdges_%d.pos", gf->tag());
  FILE *f2 = fopen(name2,"w");
  fprintf(f2,"View \"%s\" {\n",name2);

  for (unsigned int i = 0; i < e01.size(); i++){
     SPoint2 pi; reparamMeshVertexOnFace(e01[i], gf, pi);
    fprintf(f2,"SP(%g,%g,%g) {%d};\n", pi.x(), pi.y(), 0.0, 1);
  }

  for (unsigned int i = 0; i < e10.size(); i++){
    SPoint2 pi; reparamMeshVertexOnFace(e10[i], gf, pi);
    fprintf(f2,"SP(%g,%g,%g) {%d};\n", pi.x(), pi.y(), 0.0, 10);
  }

  for (unsigned int i = 0; i < e23.size(); i++){
    SPoint2 pi; reparamMeshVertexOnFace(e23[i], gf, pi);
    fprintf(f2,"SP(%g,%g,%g) {%d};\n", pi.x(), pi.y(), 0.0, 23);
  }

  for (unsigned int i = 0; i < e32.size(); i++){
    SPoint2 pi; reparamMeshVertexOnFace(e32[i], gf, pi);
    fprintf(f2,"SP(%g,%g,%g) {%d};\n", pi.x(), pi.y(), 0.0, 32);
  }

  for (unsigned int i = 0; i < e02.size(); i++){
    SPoint2 pi; reparamMeshVertexOnFace(e02[i], gf, pi);
    fprintf(f2,"SP(%g,%g,%g) {%d};\n", pi.x(), pi.y(), 0.0, 2);
  }

  for (unsigned int i = 0; i < e13.size(); i++){
    SPoint2 pi; reparamMeshVertexOnFace(e13[i], gf, pi);
    fprintf(f2,"SP(%g,%g,%g) {%d};\n", pi.x(), pi.y(), 0.0, 13);
  }
  fprintf(f2,"};\n");
  fclose(f2);

  char name3[234];
  sprintf(name3,"quadXYZ_%d.pos", gf->tag());
  FILE *f3 = fopen(name3,"w");
  fprintf(f3,"View \"%s\" {\n",name3);
  for (unsigned int i = 0; i < quads.size(); i++){
    quads[i]->writePOS(f3,true,false,false,false,false,false);
  }
  fprintf(f3,"};\n");
  fclose(f3);

  return;

}

static void createQuadsFromUV(GFace *gf, fullMatrix<SPoint2> &uv, 
			      std::vector<std::vector<MVertex*> > &tab, 
			      std::vector<MQuadrangle*> &newq,  std::vector<MVertex*> &newv){

  newq.clear();
  newv.clear();

  int M = uv.size1();
  int N = uv.size2();
 
  for (int i = 1; i < M-1; i++){
    for (int j = 0; j < N-1; j++){
      GPoint gp = gf->point(uv(i,j));
      if (!gp.succeeded()){ 
  	printf("** QUADS FROM UV new vertex not created p=%g %g \n", uv(i,j).x(), uv(i,j).y()); //exit(1);
      }
      tab[i][j] = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
    }
  }
  for (int i = 1; i < M-1; i++) tab[i][N-1] =  tab[i][0]; 

  //create vertices
  for (int i = 1; i < M-1; i++)
    for (int j = 0; j < N-1; j++)
      newv.push_back(tab[i][j]);

  // create quads
  for (int i=0;i<M-1;i++){
    for (int j=0;j<N-1;j++){
      MQuadrangle *qnew = new MQuadrangle (tab[i][j],tab[i][j+1],tab[i+1][j+1],tab[i+1][j]);
      newq.push_back(qnew);
    }
  }
  
  return;

}
static std::vector<MVertex*> saturateEdgeRegular (GFace *gf, SPoint2 p1, SPoint2 p2,
						  int M, std::vector<SPoint2> &pe){

  std::vector<MVertex*> pts;
  for (int i=1;i<M;i++){
    double s = ((double)i/((double)(M)));
    SPoint2 p = p1 + (p2-p1)*s;
    pe.push_back(p);

    GPoint gp = gf->point(p);
    if (!gp.succeeded()) printf("** SATURATE EDGE new vertex not created p=%g %g \n", p.x(), p.y());
    MVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());

    if (!v){ pts.clear(); pts.resize(0); return pts;}
    pts.push_back(v);
  }
  return pts;
}
static std::vector<MVertex*> saturateEdgeHarmonic (GFace *gf, SPoint2 p1, SPoint2 p2,
						  double H,  double L,
						  int M, std::vector<SPoint2> &pe){

  std::vector<MVertex*> pts;
  for (int i=1;i<M;i++){
    double y = ((double)(i))*H/M;
    double Yy = cosh(M_PI*y/L) - tanh(M_PI*H/L)*sinh(M_PI*y/L);
    double YyH = cosh(M_PI*H/L) - tanh(M_PI*H/L)*sinh(M_PI*H/L);
    double s = (1 - Yy)/(1.-YyH);

    SPoint2 p = p1 + (p2-p1)*s;
    pe.push_back(p);

    GPoint gp = gf->point(p);
    if (!gp.succeeded()) printf("** SATURATE EDGE new vertex not created p=%g %g \n", p.x(), p.y());
    MVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());

    if (!v){ pts.clear(); pts.resize(0); return pts;}
    pts.push_back(v);
  }
  return pts;
}

static void transfiniteSmoother(GFace* gf,
				fullMatrix<SPoint2> &uv, 
				std::vector<std::vector<MVertex*> > &tab,
				std::vector<MQuadrangle*> &newq,
				std::vector<MVertex*> &newv, 
				bool isPeriodic=false){

   int M = uv.size1();
   int N = uv.size2();
   int jStart = isPeriodic ? 0 : 1;

   int numSmooth = 150;
  fullMatrix<SPoint2> uvold = uv;
  for(int k = 0; k < numSmooth; k++){
    double norm = 0.0;
    for (int i=1; i<M-1; i++){
      for (int j = jStart; j<N-1; j++){
  	int jm1 = (j==0) ? N-2: j-1;
  	int jp1 = (isPeriodic ) ? (j+1)%(N-1) : j+1;
  	double alpha = 0.25 * (SQU(uv(i,jp1).x() - uv(i,jm1).x()) +
  			       SQU(uv(i,jp1).y() - uv(i,jm1).y())) ;
  	double gamma = 0.25 * (SQU(uv(i+1,j).x() - uv(i-1,j).x()) +
  			       SQU(uv(i+1,j).y() - uv(i-1,j).y()));
  	double beta = 0.0625 * 
  	  ((uv(i+1,j).x() - uv(i-1,j).x()) * (uv(i,jp1).x() - uv(i,jm1).x()) +
  	   (uv(i+1,j).y() - uv(i-1,j).y()) * (uv(i,jp1).y() - uv(i,jm1).y()));
  	double uk = 0.5 * 
  	  (alpha * (uv(i+1,j).x() + uv(i-1,j).x()) + 
  	   gamma * (uv(i,jp1).x() + uv(i,jm1).x()) -
  	   2. * beta * (uv(i+1,jp1).x() - uv(i-1,jp1).x() - 
  			uv(i+1,jm1).x() + uv(i-1,jm1).x())) / (alpha + gamma);
  	double vk = 0.5 * 
  	  (alpha * (uv(i+1,j).y() + uv(i-1,j).y()) + 
  	   gamma * (uv(i,jp1).y()+ uv(i,jm1).y()) -
  	   2. * beta * (uv(i+1,jp1).y() - uv(i-1,jp1).y() - 
  			uv(i+1,jm1).y() + uv(i-1,jm1).y())) / (alpha + gamma);
  	uvold(i,j) = uv(i,j);
  	norm += sqrt((uv(i,j).x()-uk)*(uv(i,j).x()-uk)+(uv(i,j).y()-vk)*(uv(i,j).y()-vk));
  	uv(i,j) = SPoint2(uk,vk);
        }
      }
    if (isPeriodic){
      for (int i = 1; i<M-1; i++) {
  	uv(i,N-1) = uv(i,0);
  	uvold(i,N-1) = uvold(i,0);
      }
    }

    if(k%20==0){
      printf("Transfinite smoother iter (%d) = %g \n", k, norm);
      createQuadsFromUV(gf, uv, tab, newq, newv);
      printQuads(gf, uv, newq, k+1);
    }

  }

  //final print
  createQuadsFromUV(gf, uv, tab, newq, newv);
  printQuads(gf, uv, newq, numSmooth);
 
}

//elliptic surface grid generator
//see eq. 9.26 page 9-24 in handbook of grid generation
static void ellipticSmoother( GFace* gf,
			      fullMatrix<SPoint2> &uv,
			      std::vector<std::vector<MVertex*> > &tab,
			      std::vector<MQuadrangle*> &newq,
			      std::vector<MVertex*> &newv, 
			      bool isPeriodic=false){

  printQuads(gf, uv, newq, 0);

  int nbSmooth = 70;
  int M = uv.size1();
  int N = uv.size2();
  int jStart = isPeriodic ? 0 : 1;
  int jEnd   = N-1;

  fullMatrix<SPoint2> uvold = uv;
  for (int k = 0; k< nbSmooth; k++){
    double norm = 0.0;
    for (int i=1; i<M-1; i++){
      for (int j = jStart; j<jEnd; j++){
	int jm1 = (j==0) ? N-2: j-1;
	int jp1 = (isPeriodic ) ? (j+1)%(N-1) : j+1;
	Pair<SVector3, SVector3> der = gf->firstDer(uv(i,j));
	SVector3 xu = der.first();
	SVector3 xv = der.second();
	// double g11 = dot(xu,xu);
	// double g12 = dot(xu,xv);
	// double g22 = dot(xv,xv);
	SVector3 xuu = SVector3();
	SVector3 xvv = SVector3();
	SVector3 xuv = SVector3();
	gf->secondDer(uv(i,j), &xuu, &xvv, &xuv);
	double g11_bar = dot(xu,xu);
	double g12_bar = dot(xu,xv);
	double g22_bar = dot(xv,xv);
	double dxsi = 1.; 
	double deta = 1.; 
	double u_xsi = (uv(i,jp1).x()-uv(i,j).x())/dxsi;
	double u_eta = (uv(i+1,j).x()-uv(i,j).x())/deta;
	double v_xsi = (uv(i,jp1).y()-uv(i,j).y())/dxsi;
	double v_eta = (uv(i+1,j).y()-uv(i,j).y())/deta;
	double g11 = g11_bar*u_xsi*u_xsi+2.*g12_bar*u_xsi*v_xsi+g22_bar*v_xsi*v_xsi;
	double g12 = g11_bar*u_xsi*u_eta+g12_bar*(u_xsi*v_eta+u_eta*v_xsi)+g22_bar*v_xsi*v_eta;
	double g22 = g11_bar*u_eta*u_eta+2.*g12_bar*u_eta*v_eta+g22_bar*v_eta*v_eta;
	double jac = u_xsi*v_eta-u_eta*v_xsi; //sqrt(g11*g22-g12*g12);	
	double jac_bar = sqrt(g11_bar*g22_bar-g12_bar*g12_bar);
	double g11_bar_u = 2.*dot(xu,xuu);
	double g11_bar_v = 2.*dot(xu,xuv);
	double g22_bar_u = 2.*dot(xv,xuv);
	double g22_bar_v = 2.*dot(xv,xvv);
	double g12_bar_u = dot(xu,xuv)+dot(xv,xuu);
	double g12_bar_v = dot(xu,xvv)+dot(xv,xuv);
	double jac_bar_u = 1./(2.*jac_bar)*(g11_bar*g22_bar_u+g22_bar*g11_bar_u-2.*g12_bar*g12_bar_u);
	double jac_bar_v = 1./(2.*jac_bar)*(g11_bar*g22_bar_v+g22_bar*g11_bar_v-2.*g12_bar*g12_bar_v);
	double lapl_u = 1./jac_bar*(jac_bar*(g22_bar_u-g12_bar_v)-(g22_bar*jac_bar_u-g12_bar*jac_bar_v));
	double lapl_v = 1./jac_bar*(jac_bar*(g11_bar_v-g12_bar_u)-(g11_bar*jac_bar_v-g12_bar*jac_bar_u));
	double over =  1./(4.*(g11+g22));
	double uk = over*(2.*g22*(uv(i+1,j).x()+uv(i-1,j).x())+
			  2.*g11*(uv(i,jp1).x()+uv(i,jm1).x())-
			  2*g12*(uv(i+1,jp1).x()-uv(i-1,jp1).x()-uv(i+1,jm1).x()+uv(i-1,jm1).x())-
			  2.*jac*jac*lapl_u);
	double vk = over*(2.*g22*(uv(i+1,j).y()+uv(i-1,j).y())+
			  2.*g11*(uv(i,jp1).y()+uv(i,jm1).y())-
			  2.*g12*(uv(i+1,jp1).y()-uv(i-1,jp1).y()-uv(i+1,jm1).y()+uv(i-1,jm1).y())-
			  2.*jac*jac*lapl_v);
	uvold(i,j) = uv(i,j);
	norm += sqrt((uv(i,j).x()-uk)*(uv(i,j).x()-uk)+(uv(i,j).y()-vk)*(uv(i,j).y()-vk));
	uv(i,j) = SPoint2(uk,vk);
      }
    }
    if (isPeriodic){
      for (int i = 1; i<M-1; i++) {
	uv(i,N-1) = uv(i,0);
	uvold(i,N-1) = uvold(i,0);
      }
    }
    
    //under-relaxation
    // double omega = 0.8;
    // for (int i=0; i<M; i++){
    //   for (int j = 0; j<N; j++){
    // 	uv(i,j) = SPoint2(omega*uv(i,j).x() + (1.-omega)*uvold(i,j).x(), 
    // 			  omega*uv(i,j).y() + (1.-omega)*uvold(i,j).y());
    //   }
    // }


    if(k%10==0){
      printf("Elliptic smoother iter (%d) = %g \n", k, norm);
      createQuadsFromUV(gf, uv, tab, newq, newv);
      printQuads(gf, uv, newq, k+1);
    }

  }

  createQuadsFromUV(gf, uv, tab, newq, newv);
  printQuads(gf, uv, newq, nbSmooth);

  //exit(1);

}

//create initial grid points MxN using transfinite interpolation
/*
  c4          N              c3
  +--------------------------+
  |       |      |    |      |
  |       |      |    |      |
  +--------------------------+  M
  |       |      |    |      |
  |       |      |    |      |
  +--------------------------+
 c1                          c2
             N
*/
static void createRegularGrid (GFace *gf,
			       MVertex *v1, SPoint2 &c1,
			       std::vector<MVertex*> &e12, std::vector<SPoint2> &pe12, int sign12,
			       MVertex *v2, SPoint2 &c2,
			       std::vector<MVertex*> &e23, std::vector<SPoint2> &pe23, int sign23,
			       MVertex *v3, SPoint2 &c3,
			       std::vector<MVertex*> &e34,std::vector<SPoint2> &pe34, int sign34,
			       MVertex *v4, SPoint2 &c4,
			       std::vector<MVertex*> &e41, std::vector<SPoint2> &pe41,int sign41,
			       std::vector<MQuadrangle*> &q,
			       std::vector<MVertex*> &newv,
			       fullMatrix<SPoint2> &uv, 
			       std::vector<std::vector<MVertex*> > &tab)
{
 
  int M = e23.size();
  int N = e12.size();

  uv.resize(M+2,N+2);
 
  char name3[234];
  sprintf(name3,"quadParam_%d.pos", gf->tag());
  FILE *f3 = fopen(name3,"w");
  fprintf(f3,"View \"%s\" {\n",name3);

  //std::vector<std::vector<MVertex*> > tab(M+2);
  tab.resize(M+2);
  for(int i = 0; i <= M+1; i++) tab[i].resize(N+2);

  tab[0][0] = v1;      uv(0,0) = c1;
  tab[0][N+1] = v2;    uv(0,N+1) = c2;
  tab[M+1][N+1] = v3;  uv(M+1,N+1) = c3;
  tab[M+1][0] = v4;    uv(M+1,0) = c4;
 
  for (int i=0;i<N;i++){
    tab[0][i+1]   = sign12 > 0 ? e12 [i] : e12 [N-i-1];
    tab[M+1][i+1] = sign34 < 0 ? e34 [i] : e34 [N-i-1];
    uv(0,i+1)   = sign12 > 0 ? pe12 [i] : pe12 [N-i-1];
    uv(M+1,i+1) = sign34 < 0 ? pe34 [i] : pe34 [N-i-1];
  }
  for (int i=0;i<M;i++){
    tab[i+1][N+1] = sign23 > 0 ? e23 [i] : e23 [M-i-1];
    tab[i+1][0]   = sign41 < 0 ? e41 [i] : e41 [M-i-1];
    uv(i+1,N+1) = sign23 > 0 ? pe23 [i] : pe23 [M-i-1];
    uv(i+1,0)   = sign41 < 0 ? pe41 [i] : pe41 [M-i-1];
  }

  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      double u = (double) (i+1)/ ((double)(N+1));
      double v = (double) (j+1)/ ((double)(M+1));
      SPoint2 p12 = (sign12 >0) ? pe12[i] : pe12 [N-1-i];
      SPoint2 p23 = (sign23 >0) ? pe23[j] : pe23 [M-1-j];
      SPoint2 p34 = (sign34 <0) ? pe34[i] : pe34 [N-1-i];
      SPoint2 p41 = (sign41 <0) ? pe41[j] : pe41 [M-1-j];
      double Up = TRAN_QUAD(p12.x(), p23.x(), p34.x(), p41.x(),
			   c1.x(),c2.x(),c3.x(),c4.x(),u,v);
      double Vp = TRAN_QUAD(p12.y(), p23.y(), p34.y(), p41.y(),
			   c1.y(),c2.y(),c3.y(),c4.y(),u,v);
      if ((p12.x() && p12.y() == -1.0) || (p23.x() && p23.y() == -1.0) ||
          (p34.x() && p34.y() == -1.0) || (p41.x() && p41.y() == -1.0)) {
        Msg::Error("Wrong param -1");
        return;
      }

      SPoint2 pij(Up,Vp);

      GPoint gp = gf->point(pij);
      if (!gp.succeeded()) printf("** INITIAL GRID new vertex not created p=%g %g \n", Up, Vp);
      MVertex *vnew = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
      newv.push_back(vnew);

      uv(j+1,i+1) = pij;
      tab[j+1][i+1] = vnew;
    }
  }

  // create quads
  for (int i=0;i<=N;i++){
    for (int j=0;j<=M;j++){
      MQuadrangle *qnew = new MQuadrangle (tab[j][i],tab[j][i+1],tab[j+1][i+1],tab[j+1][i]);
      q.push_back(qnew);
    }
  }

  fprintf(f3,"};\n");
  fclose(f3);

}

//create initial grid points MxN using transfinite interpolation
/*
  c2           N              c2
  +--------------------------+
  |       |      |    |      |
  |       |      |    |      |
  +--------------------------+  M
  |       |      |    |      |
  |       |      |    |      |
  +--------------------------+
 c0                          c0
              N
*/
static void createRegularGridPeriodic  (GFace *gf,int sign2,
					MVertex *v0, SPoint2 &c0,
					MVertex *v2, SPoint2 &c2,
					std::vector<MVertex*> &e02, std::vector<SPoint2> &pe02, 
					std::vector<MVertex*> &e00, std::vector<SPoint2> &pe00, 
					std::vector<MVertex*> &e22, std::vector<SPoint2> &pe22, 
					std::vector<MQuadrangle*> &q,
					std::vector<MVertex*> &newv,
					fullMatrix<SPoint2> &uv, 
					std::vector<std::vector<MVertex*> > &tab)
{
 
  int M = e02.size();
  int N = e00.size();

  uv.resize(M+2,N+2);

  char name3[234];
  sprintf(name3,"quadParam_%d.pos", gf->tag());
  FILE *f3 = fopen(name3,"w");
  fprintf(f3,"View \"%s\" {\n",name3);

  tab.resize(M+2);
  for(int i = 0; i < M+2; i++) tab[i].resize(N+2);

  //periodic boundary mesh vertices
  tab[0][0] = v0;      uv(0,0) = c0;
  tab[0][N+1] = v0;    uv(0,N+1) = c0;
  tab[M+1][N+1] = v2;  uv(M+1,N+1) = c2;
  tab[M+1][0] = v2;    uv(M+1,0) = c2;
  for (int i=0;i<N;i++){
    tab[0][i+1]   =   e00 [i];  uv(0,i+1) = pe00 [i]  ; 
    tab[M+1][i+1] = (sign2 > 0) ?    e22 [i]  : e22 [N-i-1]  ;  
    uv(M+1,i+1)  =  (sign2 > 0) ?    pe22 [i] : pe22 [N-i-1] ;
  }
  for (int i=0;i<M;i++){
    tab[i+1][N+1] =  e02 [i];      uv(i+1,N+1)   =  pe02 [i] ;
    tab[i+1][0]   =  e02 [i];      uv(i+1,0)     =  pe02 [i];
  }

  //interior mesh_vertices
  for (int i=0;i<N;i++){
    SPoint2 p0 =  pe00[i]  ; 
    SPoint2 p2 =  (sign2>0) ?    pe22[i] : pe22 [N-i-1] ;
    std::vector<SPoint2> pei;
    std::vector<MVertex*> ei = saturateEdgeRegular(gf,p0,p2,M+1,pei);//M+1
    for (int j=0;j<M;j++){
      SPoint2 pij = pei[j]; 
      GPoint gp = gf->point(pij);
      if (!gp.succeeded()) printf("** INITIAL GRID new vertex not created p=%g %g \n", pij.x(), pij.y());
      tab[j+1][i+1] = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
      uv(j+1,i+1) = pij;
    }
  }

  //create vertices
  for (int i=0;i<N+1;i++)
    for (int j=1;j<M+1;j++)
      newv.push_back(tab[j][i]);
      
  // create quads
  for (int i=0;i<=N;i++){
    for (int j=0;j<=M;j++){
      MQuadrangle *qnew = new MQuadrangle (tab[j][i],tab[j][i+1],tab[j+1][i+1],tab[j+1][i]);
      q.push_back(qnew);
    }
  }

  //print
  for (int i=0;i<N+2;i++)
    for (int j=0;j<M+2;j++)
      fprintf(f3,"SP(%g,%g,%g) {%d};\n",   uv(j,i).x(), uv(j,i).y(), 0.0, j);

  fprintf(f3,"};\n");
  fclose(f3);

}

static void updateFaceQuads(GFace *gf, std::vector<MQuadrangle*> &quads, std::vector<MVertex*> &newv){

  for (unsigned int i = 0; i < quads.size(); i++){
    gf->quadrangles.push_back(quads[i]);
  }
  for(unsigned int i = 0; i < newv.size(); i++){
    gf->mesh_vertices.push_back(newv[i]);
  }
  
}

static bool computeRingVertices(GFace *gf, Centerline *center, 
				std::vector<MVertex*> &vert1, std::vector<MVertex*> &vert2, 
				int &N, int &M, int &close_ind, int &sign2, 
				double &arc, double &length){

#if defined(HAVE_ANN)
  std::list<GEdge*> bedges = gf->edges();
  std::list<GEdge*>::iterator itb = bedges.begin();
  std::list<GEdge*>::iterator ite = bedges.end(); ite--;
  GEdge *ge1 =  (*itb)->getCompound();
  GEdge *ge2 =  (*ite)->getCompound();
  N = ge1->mesh_vertices.size() + 1;
  int N2 = ge2->mesh_vertices.size() + 1;
  if (N != N2 || N%2 != 0){
    Msg::Error("You should have an equal pair number of points in centerline field N=%d N2=%d ", N, N2);
    return false;
  }

  vert1.push_back(ge1->getBeginVertex()->mesh_vertices[0]);
  vert2.push_back(ge2->getBeginVertex()->mesh_vertices[0]);
  for(int i = 0; i < N-1; i++) {
    vert1.push_back(ge1->mesh_vertices[i]);
    vert2.push_back(ge2->mesh_vertices[i]);
  }
  SPoint2 pv1; reparamMeshVertexOnFace(vert1[0], gf, pv1);
  SPoint2 pv2; reparamMeshVertexOnFace(vert2[0], gf, pv2);
  SPoint2 pv1b; reparamMeshVertexOnFace(vert1[1], gf, pv1b);
  SPoint2 pv2b; reparamMeshVertexOnFace(vert2[1], gf, pv2b);
  SPoint2 pv1c; reparamMeshVertexOnFace(vert1[2], gf, pv1c);
  SPoint2 pv2c; reparamMeshVertexOnFace(vert2[2], gf, pv2c);
  SVector3 vec1(pv1b.x()-pv1.x(),pv1b.y()-pv1.y() , 0.0);
  SVector3 vec1b(pv1c.x()-pv1b.x(),pv1c.y()-pv1b.y() ,0.0);
  SVector3 vec2(pv2b.x()-pv2.x(),pv2b.y()-pv2.y() ,0.0);
  SVector3 vec2b(pv2c.x()-pv2b.x(),pv2c.y()-pv2b.y() , 0.0);
  sign2 =  (dot(crossprod(vec1,vec1b),crossprod(vec2,vec2b)) < 0)  ?   -1 : +1 ;
  double n1 = sqrt(pv1.x()*pv1.x()+pv1.y()*pv1.y());
  double n2 = sqrt(pv2.x()*pv2.x()+pv2.y()*pv2.y());
  std::vector<MVertex*> vert_temp;
  if (n2 > n1) {
    vert_temp = vert1;
    vert1.clear();
    vert1 = vert2;
    vert2.clear();
    vert2 = vert_temp;
  }
  double rad = center->operator()(vert1[0]->x(), vert1[0]->y(), vert1[0]->z());

  ANNpointArray nodes = annAllocPts(N, 3);
  ANNidxArray index  = new ANNidx[1];
  ANNdistArray dist = new ANNdist[1];
  for (int ind = 0; ind < N; ind++){
    SPoint2 pp2; reparamMeshVertexOnFace(vert2[ind], gf, pp2);
    nodes[ind][0] =  pp2.x();
    nodes[ind][1] =  pp2.y();
    nodes[ind][2] =  0.0;
  }
  ANNkd_tree *kdtree = new ANNkd_tree(nodes, N, 3);
  SPoint2 pp1; reparamMeshVertexOnFace(vert1[0], gf, pp1);
  double xyz[3] = {pp1.x(), pp1.y(),0.0};
  kdtree->annkSearch(xyz, 1, index, dist);
  close_ind = index[0];

  SPoint2 p1; reparamMeshVertexOnFace(vert1[0], gf, p1);
  SPoint2 p2; reparamMeshVertexOnFace(vert2[close_ind], gf, p2);
  GPoint gp_i(vert1[0]->x(), vert1[0]->y(), vert1[0]->z()); 
  SPoint2 p1b; reparamMeshVertexOnFace(vert1[N/2], gf, p1b);
  SPoint2 p2b; reparamMeshVertexOnFace(vert2[(close_ind+N/2)%N], gf, p2b);
  GPoint gp_ib(vert1[N/2]->x(), vert1[N/2]->y(), vert1[N/2]->z()); 
  length = 0.0;
  double lengthb = 0.0;
  int nb = 100;
  for (int i = 0; i< nb; i++){
    SPoint2 pii(p1.x() + (double)(i+1)/nb*(p2.x()-p1.x()), p1.y() + (double)(i+1)/nb*(p2.y()-p1.y()));
    GPoint gp_ii = gf->point(pii);
    SPoint2 piib(p1b.x() + (double)(i+1)/nb*(p2b.x()-p1b.x()), p1b.y() + (double)(i+1)/nb*(p2b.y()-p1b.y()));
    GPoint gp_iib = gf->point(piib);
    length  += gp_i.distance(gp_ii); 
    lengthb += gp_ib.distance(gp_iib); 
    gp_i = gp_ii;
    gp_ib = gp_iib;
  }

  arc = 2*M_PI*rad;
  double lc =  arc/N;
  M = (int)(0.5*(length+lengthb)/lc) ;
  
  delete kdtree;
  delete[]index;
  delete[]dist;
  annDeallocPts(nodes);

  return true;
#endif

}

//vert1 is the outer circle
//vert2 is the inner circle
//         - - - -
//       -         -
//     -      -      -
//   v0-  v2-   -     -
//     -      -      -
//      -          -
//         - - - -
bool createRegularTwoCircleGridPeriodic (Centerline *center, GFace *gf)
{

#if defined(HAVE_ANN)
  std::vector<MVertex*> vert1, vert2;
  int N, M, close_ind, sign2;
  double arc, length;
  bool success = computeRingVertices(gf, center, vert1, vert2, N, M, close_ind, sign2, arc,length);
  if(!success) return false;

  MVertex *v0 = vert1[0]; SPoint2 p0; reparamMeshVertexOnFace(v0, gf, p0);
  MVertex *v2 = vert2[close_ind]; SPoint2 p2; reparamMeshVertexOnFace(v2, gf, p2);

  //printf("grid N = %d M = %d\n", N , M);
  std::vector<MVertex*> e00,e22;//edges without first and last vertex
  for (int i=1;i<N;i++) e00.push_back(vert1[i]);
  for (int i=1;i<N;i++) e22.push_back(vert2[(close_ind+i)%N]);
 
  std::vector<SPoint2> pe00, pe22;
  for (unsigned int i = 0; i < e00.size(); i++){
     SPoint2 p00; reparamMeshVertexOnFace(e00[i], gf, p00);
     SPoint2 p22; reparamMeshVertexOnFace(e22[i], gf, p22);
     pe00.push_back(p00);
     pe22.push_back(p22);
  }

  std::vector<SPoint2> pe02;
  std::vector<MVertex*> e02 = saturateEdgeRegular(gf,p0,p2,M+1,pe02);

  std::vector<MQuadrangle*> quads;
  std::vector<MVertex*> newv;
  fullMatrix<SPoint2> uv;
  std::vector<std::vector<MVertex*> > tab;

  createRegularGridPeriodic (gf,sign2,
  			     v0, p0,
  			     v2, p2,
  			     e02, pe02,
  			     e00, pe00,
  			     e22, pe22, 
  			     quads, newv, uv, tab);

  printQuads(gf, uv, quads, 0);

  transfiniteSmoother(gf, uv, tab, quads, newv, true);
  //ellipticSmoother(gf, uv, tab, quads, newv, true);

  updateFaceQuads(gf, quads, newv);

  //exit(1);
  //printParamGrid(gf, vert1, vert2, e00,e22,e02,e02,e02,e02, quads);

  return true;

#else
  return false;
#endif

}

//vert1 is the outer circle
//vert2 is the inner circle
//         - - - -
//       -         -
//     -      -      -
//   v0-  v2-   -v3   -v1
//     -      -      -
//      -          -
//         - - - -

bool createRegularTwoCircleGrid (Centerline *center, GFace *gf)
{
#if defined(HAVE_ANN)
  std::vector<MVertex*> vert1, vert2;
  int N, M, close_ind, sign2;
  double arc, length;
  bool success = computeRingVertices(gf, center, vert1, vert2, N, M, close_ind, sign2, arc,length);
  if(!success) return false;

  MVertex *v0 = vert1[0]; SPoint2 p0; reparamMeshVertexOnFace(v0, gf, p0);
  MVertex *v1 = vert1[N/2]; SPoint2 p1; reparamMeshVertexOnFace(v1, gf, p1);
  MVertex *v2 = vert2[close_ind]; SPoint2 p2; reparamMeshVertexOnFace(v2, gf, p2);
  MVertex *v3 = vert2[(close_ind+N/2)%N]; SPoint2 p3; reparamMeshVertexOnFace(v3, gf, p3);

  printf("grid N = %d M = %d\n", N , M);
  std::vector<MVertex*> e01,e10,e23,e32;//edges without first and last vertex
  for (int i=1;i<N/2;i++) e01.push_back(vert1[i]);
  for (int i=N/2+1;i<N;i++) e10.push_back(vert1[i]);
  for (int i=1;i<N/2;i++) e23.push_back(vert2[(close_ind+i)%N]);
  for (int i=N/2+1;i<N;i++) e32.push_back(vert2[(close_ind+i)%N]);

  std::vector<SPoint2> pe01, pe10, pe23, pe32;
  for (unsigned int i = 0; i < e01.size(); i++){
     SPoint2 p01; reparamMeshVertexOnFace(e01[i], gf, p01);
     SPoint2 p10; reparamMeshVertexOnFace(e10[i], gf, p10);
     SPoint2 p23; reparamMeshVertexOnFace(e23[i], gf, p23);
     SPoint2 p32; reparamMeshVertexOnFace(e32[i], gf, p32);
     pe01.push_back(p01);
     pe10.push_back(p10);
     pe23.push_back(p23);
     pe32.push_back(p32);
  }

  std::vector<SPoint2> pe02, pe13;
  std::vector<MVertex*> e02 = saturateEdgeHarmonic (gf,p0,p2,length, arc, M+1, pe02);
  std::vector<MVertex*> e13 = saturateEdgeHarmonic (gf,p1,p3,length, arc, M+1, pe13);

  std::vector<MVertex*> e_inner1 = e23;
  std::vector<MVertex*> e_inner2 = e32;
  std::vector<SPoint2> pe_inner1 = pe23;
  std::vector<SPoint2> pe_inner2 = pe32;
  if (sign2 <0){
    e_inner1 = e32;
    e_inner2 = e23;
    pe_inner1 = pe32;
    pe_inner2 = pe23;
  }

  std::vector<MQuadrangle*> quads, quadS1, quadS2;
  std::vector<MVertex*> newv, newv1, newv2;
  fullMatrix<SPoint2> uv1, uv2;
  std::vector<std::vector<MVertex*> > tab1, tab2;
  createRegularGrid (gf,
  		     v0, p0,
  		     e01, pe01, +1,
  		     v1,p1,
  		     e13, pe13, +1,
  		     v3,p3,
		     e_inner1, pe_inner1, -sign2,
  		     v2,p2,
  		     e02, pe02, -1,
  		     quads, newv, uv1, tab1);

  createRegularGrid (gf,
  		     v0,p0,
  		     e02, pe02,  +1,
  		     v2,p2,
  		     e_inner2, pe_inner2, -sign2,
  		     v3,p3,
  		     e13, pe13, -1,
  		     v1,p1,
  		     e10, pe10, +1,
  		     quads, newv, uv2, tab2);

  printQuads(gf, uv1, quads, 0);

  ellipticSmoother(gf, uv1, tab1, quadS1, newv1);
  ellipticSmoother(gf, uv2, tab2, quadS2, newv2);

  quads.clear();
  for (unsigned int i= 0; i< quadS1.size(); i++) quads.push_back(quadS1[i]);
  for (unsigned int i= 0; i< quadS2.size(); i++) quads.push_back(quadS2[i]);
  //updateFaceQuads(gf, quads, newv);

  printParamGrid(gf, vert1, vert2, e01,e10,e23,e32,e02,e13, quads);

  return true;

#else
  return false;
#endif

}


