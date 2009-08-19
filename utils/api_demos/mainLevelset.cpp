
#include "../../contrib/DiscreteIntegration/Integration3D.h"
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>
#include <gmsh/MHexahedron.h>
#include <gmsh/MTetrahedron.h>
#include <gmsh/MQuadrangle.h>
#include <gmsh/MTriangle.h>
#include <gmsh/MLine.h>
#include "../../contrib/DiscreteIntegration/DILevelset.h"
#include <time.h>
#include <iostream>
#include <queue>
#include <limits>

#define PI 3.14159265

// ----------------------------------------------------------------------
// --------------------------OUTPUT FILE --------------------------------
// ----------------------------------------------------------------------

int nbZeros(double number){
  if (number != 0) {
    double lg = log10(fabs(number));
    return (int)ceil(-lg) -1;
  }
  else
    return -1;
}

int digits(double number){
  int nC=0; double n=number, intpart; //printf("%-#15.15g \n",n);
  double eps = 1.e-15; //printf("%-#15.15g->%-#15.15g>%-#15.15g nC=%d\n",n,modf(n,&intpart),eps,nC);
  while(fabs(modf(n,&intpart))-1. < -eps && fabs(modf(n,&intpart)) > eps){
    nC++; n *=10; eps *=10; //printf("%-#15.17g->%-#15.17g>%-#15.17g nC=%d\n",n,modf(n,&intpart),eps,nC);
  } //printf("\n\n");
  return nC;
}


void writePosFile (const std::vector<DI_IntegrationPoint> &ip, const std::vector<DI_IntegrationPoint> &ipS, const std::vector<DI_CuttingPoint> &cp,
                   std::vector<DI_Line> surfLines, std::vector<DI_Triangle> &surfTriangles, std::vector<DI_Quad> &surfQuads,
                   const std::vector<DI_Tetra> &Tetras, const std::vector<DI_Hexa> &Hexas)
{
  // check if a line has been created twice.
  printf("checking %d lines, %d triangles and %d quadrangles\n",surfLines.size(),surfTriangles.size(),surfQuads.size());
  for(int i=0;i<(int)surfLines.size();i++){
    for(int j=i+1;j<(int)surfLines.size();j++){
      int b=0;
      for(int k=0;k<2;k++){
        for(int l=0;l<2;l++){
          if(surfLines[i].pt(k).equal(surfLines[j].pt(l))) b++;
        }
      }
      if(b==2) {printf("BIIIP : line created twice (%d,%d)\n",i,j); surfLines[i].print(); surfLines[j].print();
      }
    }
  }
  // check if a triangle has been created twice.
  double tot=0.;
  for(int i=0;i<(int)surfTriangles.size();i++){
    tot += surfTriangles[i].surface();
    for(int j=i+1;j<(int)surfTriangles.size();j++){
      int b=0;
      for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){
          if(surfTriangles[i].pt(k).equal(surfTriangles[j].pt(l))) b++;
        }
      }
      if(b==3) {printf("BIIIP : triangle created twice (%d,%d)\n",i,j); surfTriangles[i].print(); surfTriangles[j].print();
        double lsi[3] = {10,10,10};
        surfTriangles[i].addLs(lsi);
      }
    }
  }
  // check if a quad has been created twice.
  for(int i=0;i<(int)surfQuads.size();i++){
    tot +=surfQuads[i].surface();
    for(int j=i+1;j<(int)surfQuads.size();j++){
      int b=0;
      for(int k=0;k<4;k++){
        for(int l=0;l<4;l++){
          if(surfQuads[i].pt(k).equal(surfQuads[j].pt(l))) b++;
        }
      }
      if(b==4) {printf("BIIIP : quadrangle created twice (%d,%d)\n",i,j); surfQuads[i].print();  surfQuads[j].print();
        double lsi[3] = {10,10,10};
        surfQuads[i].addLs(lsi);
      }
    }
  }
  printf("somme des \"surface()\":%g\n",tot);

  //check if a cuttingPoint has been created twice
  for(int i=0;i<(int)cp.size();i++) {
    for(int j=i+1;j<(int)cp.size();j++){
      if(cp[i].equal(cp[j]))
        {printf("BIIIP : CuttingPoint created twice (%d,%d)\n",i,j); cp[i].print(); cp[j].print();}
    }
  }//*/

  // check quality of the triangles and tetras
  double worstTr=1, qMTr=0, Smin=10;
  for(int i=0;i<(int)surfTriangles.size();i++){
    double qt=surfTriangles[i].quality();
    if(qt<worstTr) worstTr=qt;
    if(surfTriangles[i].surface()<Smin) Smin=surfTriangles[i].surface();
    qMTr += qt;
  }
  double worstT=1, qMT=0;
  for(int i=0;i<(int)Tetras.size();i++){
    double qt=Tetras[i].quality();
    if(qt<worstT) worstT=qt;
    qMT += qt;
  }
  printf("Quality :\n");
  if(surfTriangles.size()) printf(" triangles : worst=%g, mean=%g\n",worstTr,qMTr/surfTriangles.size());
  if(Tetras.size()) printf(" tetras : worst=%g, mean=%g\n",worstT,qMT/Tetras.size());
  printf("Smin = %g\n",Smin);

  printf("Writing file\n");
  FILE *f = fopen("MeshCut.pos","w");
  fprintf(f,"View\"\"{\n");
  int nbLn = surfLines.size();
  for (int i=0;i<nbLn;i++) {
    //if(surfLines[i].lsTag()!=-1){
    /*if(surfLines[i].isQuad()){
    fprintf(f,"SL2(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
      surfLines[i].x(0), surfLines[i].y(0), surfLines[i].z(0), surfLines[i].x(1), surfLines[i].y(1), surfLines[i].z(1),
      surfLines[i].x2(0), surfLines[i].y2(0), surfLines[i].z2(0),
      surfLines[i].pt(0).ls(),surfLines[i].pt(1).ls(),surfLines[i].mid(0).ls());
    }
    else{*/
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",//{%g,%g};\n",
      surfLines[i].x(0), surfLines[i].y(0), surfLines[i].z(0), surfLines[i].x(1), surfLines[i].y(1), surfLines[i].z(1),
      surfLines[i].lsTag(), surfLines[i].lsTag());
      //surfLines[i].pt(0).ls(),surfLines[i].pt(1).ls());
    //}//}
  }
  int nbTr = surfTriangles.size();
  for (int i=0;i<nbTr;i++) {
    //if(surfTriangles[i].lsTag()!=-1){
    //if(surfTriangles[i].x(0)>=xm && surfTriangles[i].x(0)<=xM && surfTriangles[i].y(0)>=ym && surfTriangles[i].y(0)<=yM && surfTriangles[i].z(0)>=zm && surfTriangles[i].z(0)<=zM && surfTriangles[i].x(1)>=xm && surfTriangles[i].x(1)<=xM && surfTriangles[i].y(1)>=ym && surfTriangles[i].y(1)<=yM && surfTriangles[i].z(1)>=zm && surfTriangles[i].z(1)<=zM && surfTriangles[i].x(2)>=xm && surfTriangles[i].x(2)<=xM && surfTriangles[i].y(2)>=ym && surfTriangles[i].y(2)<=yM && surfTriangles[i].z(2)>=zm && surfTriangles[i].z(2)<=zM)
    /*if(surfTriangles[i].isQuad()){
    fprintf(f,"ST2(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d,%d,%d};\n", //{%g,%g,%g,%g,%g,%g};\n",
      surfTriangles[i].x(0), surfTriangles[i].y(0), surfTriangles[i].z(0), surfTriangles[i].x(1), surfTriangles[i].y(1), surfTriangles[i].z(1),
      surfTriangles[i].x(2), surfTriangles[i].y(2), surfTriangles[i].z(2), surfTriangles[i].x2(0), surfTriangles[i].y2(0), surfTriangles[i].z2(0),
      surfTriangles[i].x2(1), surfTriangles[i].y2(1), surfTriangles[i].z2(1), surfTriangles[i].x2(2), surfTriangles[i].y2(2), surfTriangles[i].z2(2),
      surfTriangles[i].lsTag(), surfTriangles[i].lsTag(),surfTriangles[i].lsTag(),surfTriangles[i].lsTag(), surfTriangles[i].lsTag(),surfTriangles[i].lsTag());
      //surfTriangles[i].pt(0).ls(),surfTriangles[i].pt(1).ls(),surfTriangles[i].pt(2).ls(),surfTriangles[i].mid(0).ls(),surfTriangles[i].mid(1).ls(),surfTriangles[i].mid(2).ls());
    }
    else{*/
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",//{%g,%g,%g};\n",
      surfTriangles[i].x(0), surfTriangles[i].y(0), surfTriangles[i].z(0), surfTriangles[i].x(1), surfTriangles[i].y(1), surfTriangles[i].z(1),
      surfTriangles[i].x(2), surfTriangles[i].y(2), surfTriangles[i].z(2),
      //surfTriangles[i].lsTag(), surfTriangles[i].lsTag(),surfTriangles[i].lsTag());
      surfTriangles[i].pt(0).ls(),surfTriangles[i].pt(1).ls(),surfTriangles[i].pt(2).ls());
    //}//}
  }
  int nbQ = surfQuads.size();
  for (int i=0;i<nbQ;i++) {
    //if(surfQuads[i].lsTag()!=-1){
    /*if(surfQuads[i].isQuad()){
    fprintf(f,"SQ2(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
      surfQuads[i].x(0), surfQuads[i].y(0), surfQuads[i].z(0), surfQuads[i].x(1), surfQuads[i].y(1), surfQuads[i].z(1),
      surfQuads[i].x(2), surfQuads[i].y(2), surfQuads[i].z(2), surfQuads[i].x(3), surfQuads[i].y(3), surfQuads[i].z(3),
      surfQuads[i].x2(0), surfQuads[i].y2(0), surfQuads[i].z2(0), surfQuads[i].x2(1), surfQuads[i].y2(1), surfQuads[i].z2(1),
      surfQuads[i].x2(2), surfQuads[i].y2(2), surfQuads[i].z2(2), surfQuads[i].x2(3), surfQuads[i].y2(3), surfQuads[i].z2(3),
      surfQuads[i].x2(4), surfQuads[i].y2(4), surfQuads[i].z2(4),
      surfQuads[i].pt(0).ls(),surfQuads[i].pt(1).ls(),surfQuads[i].pt(2).ls(),surfQuads[i].pt(3).ls(),
      surfQuads[i].mid(0).ls(),surfQuads[i].mid(1).ls(),surfQuads[i].mid(2).ls(),surfQuads[i].mid(3).ls(),surfQuads[i].mid(4).ls());
    }
    else {*/
    fprintf(f,"SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n", //{%g,%g,%g,%g};\n",
      surfQuads[i].x(0), surfQuads[i].y(0), surfQuads[i].z(0), surfQuads[i].x(1), surfQuads[i].y(1), surfQuads[i].z(1),
      surfQuads[i].x(2), surfQuads[i].y(2), surfQuads[i].z(2), surfQuads[i].x(3), surfQuads[i].y(3), surfQuads[i].z(3),
      //surfQuads[i].lsTag(), surfQuads[i].lsTag(),surfQuads[i].lsTag(),surfQuads[i].lsTag());
      surfQuads[i].pt(0).ls(),surfQuads[i].pt(1).ls(),surfQuads[i].pt(2).ls(),surfQuads[i].pt(3).ls());
    //}//}
  }
  int nbT = Tetras.size();
  //double xm=3.33, xM=3.89, ym=2.22, yM=2.78, zm=1.66, zM=2.23;
  for (int i=0;i<nbT;i++) {
    //if(Tetras[i].sign()<=0){
    //if(Tetras[i].x(0)>=xm && Tetras[i].x(0)<=xM && Tetras[i].y(0)>=ym && Tetras[i].y(0)<=yM && Tetras[i].z(0)>=zm && Tetras[i].z(0)<=zM && Tetras[i].x(1)>=xm && Tetras[i].x(1)<=xM && Tetras[i].y(1)>=ym && Tetras[i].y(1)<=yM && Tetras[i].z(1)>=zm && Tetras[i].z(1)<=zM && Tetras[i].x(2)>=xm && Tetras[i].x(2)<=xM && Tetras[i].y(2)>=ym && Tetras[i].y(2)<=yM && Tetras[i].z(2)>=zm && Tetras[i].z(2)<=zM && Tetras[i].x(3)>=xm && Tetras[i].x(3)<=xM && Tetras[i].y(3)>=ym && Tetras[i].y(3)<=yM && Tetras[i].z(3)>=zm && Tetras[i].z(3)<=zM){
    /*if(Tetras[i].isQuad()){ 
    fprintf(f,"SS2(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g,%g};\n",
      Tetras[i].x(0), Tetras[i].y(0), Tetras[i].z(0), Tetras[i].x(1), Tetras[i].y(1), Tetras[i].z(1),
      Tetras[i].x(2), Tetras[i].y(2), Tetras[i].z(2), Tetras[i].x(3), Tetras[i].y(3), Tetras[i].z(3),
      Tetras[i].x2(0), Tetras[i].y2(0), Tetras[i].z2(0), Tetras[i].x2(3), Tetras[i].y2(3), Tetras[i].z2(3),
      Tetras[i].x2(1), Tetras[i].y2(1), Tetras[i].z2(1), Tetras[i].x2(2), Tetras[i].y2(2), Tetras[i].z2(2),
      Tetras[i].x2(4), Tetras[i].y2(4), Tetras[i].z2(4), Tetras[i].x2(5), Tetras[i].y2(5), Tetras[i].z2(5),
      Tetras[i].pt(0).ls(),Tetras[i].pt(1).ls(),Tetras[i].pt(2).ls(),Tetras[i].pt(3).ls(),
      Tetras[i].mid(0).ls(),Tetras[i].mid(1).ls(),Tetras[i].mid(2).ls(),Tetras[i].mid(3).ls(),Tetras[i].mid(4).ls(),Tetras[i].mid(5).ls());
    }
    else{*/
    fprintf(f,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",//{%g,%g,%g,%g};\n",
      Tetras[i].x(0), Tetras[i].y(0), Tetras[i].z(0), Tetras[i].x(1), Tetras[i].y(1), Tetras[i].z(1),
      Tetras[i].x(2), Tetras[i].y(2), Tetras[i].z(2), Tetras[i].x(3), Tetras[i].y(3), Tetras[i].z(3),//1.,1.,1.,1.);
      Tetras[i].lsTag(),Tetras[i].lsTag(),Tetras[i].lsTag(),Tetras[i].lsTag());
      //Tetras[i].pt(0).ls(),Tetras[i].pt(1).ls(),Tetras[i].pt(2).ls(),Tetras[i].pt(3).ls());
    //}//}
  }
  int nbH = Hexas.size();
  for (int i=0;i<nbH;i++) {
    //if(Hexas[i].sign()<=0){
    fprintf(f,"SH(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d,%d,%d,%d,%d};\n",//{%g,%g,%g,%g,%g,%g,%g,%g};\n",
      Hexas[i].x(0), Hexas[i].y(0), Hexas[i].z(0), Hexas[i].x(1), Hexas[i].y(1), Hexas[i].z(1),
      Hexas[i].x(2), Hexas[i].y(2), Hexas[i].z(2), Hexas[i].x(3), Hexas[i].y(3), Hexas[i].z(3),
      Hexas[i].x(4), Hexas[i].y(4), Hexas[i].z(4), Hexas[i].x(5), Hexas[i].y(5), Hexas[i].z(5),
      Hexas[i].x(6), Hexas[i].y(6), Hexas[i].z(6), Hexas[i].x(7), Hexas[i].y(7), Hexas[i].z(7),
      Hexas[i].lsTag(),Hexas[i].lsTag(),Hexas[i].lsTag(),Hexas[i].lsTag(),Hexas[i].lsTag(),Hexas[i].lsTag(),Hexas[i].lsTag(),Hexas[i].lsTag());
      //Hexas[i].pt(0).ls(),Hexas[i].pt(1).ls(),Hexas[i].pt(2).ls(),Hexas[i].pt(3).ls(),Hexas[i].pt(4).ls(),Hexas[i].pt(5).ls(),Hexas[i].pt(6).ls(),Hexas[i].pt(7).ls());
  }
  int nbIp = ip.size();
  int nbIpIn = 0;
  int nbIpOut = 0;
  for(int i=0;i<nbIp;i++) {
    if(ip[i].isInsideDomain()) nbIpIn++;
    if(ip[i].isOutsideDomain()) nbIpOut++;
    //if(ip[i].isInsideDomain()) 
      fprintf(f,"SP(%g,%g,%g){%g};\n", ip[i].x(), ip[i].y(), ip[i].z(), ip[i].ls());
  }

  int nbIpS = ipS.size();
  for(int i=0;i<nbIpS;i++) {
    //if(ipS[i].x()>=xm && ipS[i].x()<=xM && ipS[i].y()>=ym && ipS[i].y()<=yM && ipS[i].z()>=zm && ipS[i].z()<=zM){
    //if(ipS[i].lsTag()<=0) 
      fprintf(f,"SP(%g,%g,%g){%g};\n", ipS[i].x(), ipS[i].y(), ipS[i].z(), ipS[i].ls());//}
  }
  //for(int i=0;i<nbIpS;i++) ipS[i].print();

  int nbCP = cp.size();
  for(int i=0;i<nbCP;i++) {
    //fprintf(f,"SP(%g,%g,%g){%g};\n", cp[i].x(), cp[i].y(), cp[i].z(), cp[i].ls());
  }
  fprintf(f,"};\n");
  fclose(f);

  printf("%d lines\n", nbLn);
  printf("%d triangles\n", nbTr);
  printf("%d quadrangles\n", nbQ);
  printf("%d tetrahedra\n", nbT);
  printf("%d hexahedra\n", nbH);

  printf("%d integration points inside domain\n", nbIpIn);
  printf("%d integration points outside domain\n", nbIpOut);
  printf("%d integration points on boundary\n", nbIpS);
  printf("%d cutting points\n", nbCP);

  // Validation by calculating the volume and the surface of a sphere
  double resultVPart=0, resultVTot=0;
  for (int i=0;i<nbIp;i++) {
    resultVTot += ip[i].weight();
    if(ip[i].isInsideDomain()) resultVPart += ip[i].weight();
  }
  double resultSPart=0, resultSTot=0;
  for (int i=0;i<nbIpS;i++) {
    resultSTot += ipS[i].weight();
    if(ipS[i].isOnBorder()) resultSPart += ipS[i].weight();
  }

  printf("Integration domain result = %g / %g\n", resultVPart, resultVTot);
  //double volumeS = (4./3.)*(3.141592654*3.45*4.15*4.85)/8.;
  //printf("Exact volume value = %g\n", volumeS);

  printf("Integration boundary result = %g / %g\n", resultSPart,resultSTot);
  //double p = 1.6075;
  //double surfaceEllips = 4.0*3.141592654*pow((pow(3.45,p)*pow(4.15,p)+pow(3.45,p)*pow(4.85,p)+pow(4.15,p)*pow(4.85,p))/3.,1./p)/8.;
  //double surfacePart = 5*(4.7836-1.2) + 5*(4.7-0.8) + 5*(3.141592654/2-atan(1.2/4.7)-atan(0.8/4.7836))*4.85;
  //double surfaceTot = 5*5+5*5+5*3.141592654*4.85/2;
  //printf("Exact surface value = %g \n", surfaceEllips);

  /*int nMax[4]={1,1,1,1};
  for(int i=0;i<(int)ip.size();i++){
    int nx=digits(ip[i].x());
    int ny=digits(ip[i].y());
    int nz=digits(ip[i].z());
    int nw=digits(ip[i].weight());
    if(nx>nMax[0]) nMax[0]=nx;
    if(ny>nMax[1]) nMax[1]=ny;
    if(nz>nMax[2]) nMax[2]=nz;
    if(nw>nMax[3]) nMax[3]=nw;
  }

  printf("nMax=(%d,%d,%d,%d)\n",nMax[0],nMax[1],nMax[2],nMax[3]);

  //for(int i=10;i<15;i++) for(int j=10;j<15;j++) printf("%d,%d  %-#*.*g\n",i,j,i,j,ip[1].x());
  //for(int i=10;i<15;i++) for(int j=10;j<15;j++) printf("%d,%d  %-#*.*g\n",i,j,i,j,ip[2].x());
  for(int i=0;i<(int)ip.size();i++){
    //fprintf(f1,"  {{%-#12.13g, %-#12.13g, %#.1g}, %-#12.13g},\n",ip[i].x(),ip[i].x(),ip[i].z(),ip[i].x());
    printf("  {{%-#*.*g, %-#*.*g, %-#*.*g}, %+-#*.*g},\n", nMax[0],nMax[0]-nbZeros(ip[i].x()),ip[i].x(), nMax[1],nMax[1]-nbZeros(ip[i].y()),ip[i].y(),
                                                           nMax[2],nMax[2]-nbZeros(ip[i].z()),ip[i].z(), nMax[3],nMax[3]-nbZeros(ip[i].weight()),ip[i].weight());
  }*/
}

// ----------------------------------------------------------------------
// ------------------------ READ pMESH  ---------------------------------
// ----------------------------------------------------------------------
void readMesh(GModel *m, std::vector<DI_Line> &Lines, std::vector<DI_Triangle> &Triangles, std::vector<DI_Quad> &Quads, std::vector<DI_Tetra> &Tetras, std::vector<DI_Hexa> &Hexas)
{
  // read the mesh and create the tetrahedra and hexahedra or the triangles and quadrangles.

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    for(int i=0;i<(int)(*it)->tetrahedra.size();i++){
      double x[4], y[4], z[4];
      MTetrahedron* t = (*it)->tetrahedra[i];
      for(int j=0;j<4;j++){
        MVertex * v = t->getVertex(j);
        x[j]= v->x();
        y[j]= v->y();
        z[j]= v->z();
      }
      DI_Tetra tt(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3]);
      Tetras.push_back(tt);
    }
    for(int i=0;i<(int)(*it)->hexahedra.size();i++){
      double x[8], y[8], z[8];
      MHexahedron* h = (*it)->hexahedra[i];
      for(int j=0;j<8;j++){
        MVertex * v = h->getVertex(j);
        x[j]= v->x();
        y[j]= v->y();
        z[j]= v->z();
      }
      DI_Hexa hh(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3],x[4],y[4],z[4],x[5],y[5],z[5],x[6],y[6],z[6],x[7],y[7],z[7]); hh.print();
      Hexas.push_back(hh);
    }
  }

  /*while (pRegion pr = RIter_next(rit)){
    int numV = R_numVertices(pr);
    double x[numV], y[numV], z[numV];
    pVertex pv;
    pPoint pp;
    for (int i=0; i<numV;++i) {
      pv = R_vertex(pr,i);
      pp = V_point(pv);
      x[i]= P_x(pp);
      y[i]= P_y(pp);
      z[i]= P_z(pp);
    }
    if(numV==4) { //Tetrahedral element
      DI_Tetra tt(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3]);
      Tetras.push_back(tt);
    }
    else if(numV==8){ //Hexahedral element
      DI_Hexa hh(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3],x[4],y[4],z[4],x[5],y[5],z[5],x[6],y[6],z[6],x[7],y[7],z[7]);
      Hexas.push_back(hh);
    }
    else {printf("Volume elements with %d nodes not handled \n",numV); throw;}
  }
  RIter_delete(rit);*/

  if(Hexas.size()==0 && Tetras.size()==0) { //add only surfaces if no volume.
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
      for(int i=0;i<(int)(*it)->triangles.size();i++){
        double x[3], y[3], z[3];
        MTriangle* t = (*it)->triangles[i];
        for(int j=0;j<3;j++){
          MVertex * v = t->getVertex(j);
          x[j]= v->x();
          y[j]= v->y();
          z[j]= v->z();
        }
        DI_Triangle tt(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2]);
        Triangles.push_back(tt);
      }
      for(int i=0;i<(int)(*it)->quadrangles.size();i++){
        double x[4], y[4], z[4];
        MQuadrangle* q = (*it)->quadrangles[i];
        for(int j=0;j<4;j++){
          MVertex * v = q->getVertex(j);
          x[j]= v->x();
          y[j]= v->y();
          z[j]= v->z();
        }
        DI_Quad qq(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3]);
        Quads.push_back(qq);
      }
    }
  }

  
  if(Hexas.size()==0 && Tetras.size()==0 && Triangles.size()==0 && Quads.size()==0) { //add only lines if no surface and no volume.
    for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
      for(int i=0;i<(int)(*it)->lines.size();i++){
        double x[2], y[2], z[2];
        MLine* l = (*it)->lines[i];
        for(int j=0;j<2;j++){
          MVertex * v = l->getVertex(j);
          x[j]= v->x();
          y[j]= v->y();
          z[j]= v->z();
        }
        DI_Line ll(x[0],y[0],z[0],x[1],y[1],z[1]);
        Lines.push_back(ll);
      }
    }
  }
  /*if(Hexas.size()==0 && Tetras.size()==0) { //add only surfaces if no volume.
    Triangles.reserve(M_numTriangles(mesh));
    Quads.reserve(M_numQuads(mesh));
    FIter fit = M_faceIter(mesh);
    while (pFace pf = FIter_next(fit)){
      int numV = F_numVertices(pf);
      double x[numV], y[numV], z[numV];
      pVertex pv;
      pPoint pp;
      for (int i=0; i<numV;++i) {
        pv = F_vertex(pf,i);
        pp = V_point(pv);
        x[i]= P_x(pp);
        y[i]= P_y(pp);
        z[i]= P_z(pp);
      }
      if(numV==3) { // Triangular element
        DI_Triangle tt(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2]);
        Triangles.push_back(tt);
      }
      else if(numV==4) { // Quadrangular element
        DI_Quad qq(x[0],y[0],z[0],x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3]);
        Quads.push_back(qq);
      }
      else {printf("Surface elements with %d nodes not handled \n",numV); throw;}
    }
    FIter_delete(fit);
  }*/
}

// ----------------------------------------------------------------------
// -------------MESH INTEGRATION POINTS ---------------------------------
// ----------------------------------------------------------------------

void getIntegrationPoints(GModel *m, const gLevelset &Ls, std::vector<DI_IntegrationPoint> &ip, std::vector<DI_IntegrationPoint> &ipS,
                          std::vector<DI_CuttingPoint> &cp, std::vector<DI_Line> &surfLines, std::vector<DI_Triangle> &surfTriangles, std::vector<DI_Quad> &surfQuads,
                          std::vector<DI_Tetra> &subTetras, std::vector<DI_Hexa> &notCutHexas)
{
  clock_t start,end;
  start = clock();

  const int POL=1, POTr=1, POQ=1, POT=1, POH=1; //polynomial order for the lines, triangles, the quads, the tetrs and the hexas

  std::vector<DI_Line> Lines;
  std::vector<DI_Triangle> Triangles;
  std::vector<DI_Quad> Quads;
  std::vector<DI_Tetra> Tetras;
  std::vector<DI_Hexa> Hexas;
  

  readMesh(m, Lines, Triangles, Quads, Tetras, Hexas);
  printf("mesh reading finished : %d Lin, %d Tri, %d Qua, %d Tet, %d Hex\n", Lines.size(), Triangles.size(), Quads.size(), Tetras.size(), Hexas.size());

  for(int ln=0;ln<(int)Lines.size();ln++)
   Lines[ln].cut (Ls, ip, cp, POL, surfLines, 0);

  for(int tr=0;tr<(int)Triangles.size();tr++)
    Triangles[tr].cut (Ls, ip, ipS, cp, POQ, POTr, POL, surfQuads, surfTriangles, surfLines, 2);

  for(int q=0;q<(int)Quads.size();q++) {
    Quads[q].cut (Ls, ip, ipS, cp, POQ, POTr, POL, surfQuads, surfTriangles, surfLines, 2);
  }

  for(int t=0;t<(int)Tetras.size();t++){
    Tetras[t].cut (Ls, ip, ipS, cp, POT, POQ, POTr, subTetras, surfQuads, surfTriangles);
  }

  for(int h=0;h<(int)Hexas.size();h++){
    Hexas[h].cut (Ls, ip, ipS, cp, POH, POT, POQ, POTr, notCutHexas, subTetras, surfQuads, surfTriangles, surfLines);
  }

  end=clock();
  printf("End of computation :  %g seconds\n",((double)end - start) / CLOCKS_PER_SEC);
}

class gLevelsetStrange : public gLevelsetPrimitive
{
public:
  
  gLevelsetStrange (int &tag) : gLevelsetPrimitive(tag) {}
  double operator () (const double &x, const double &y, const double &z) const{
    const double X = x-.5;
    const double Y = y-.5;
    const double R0 = .2;
    const double R = sqrt(X*X+Y*Y);
    const double theta = atan2(Y,X);
    const double ls = (R0-R)+(R0/5)*sin(4*theta); 
    return ls;
  }
  int type() const {return SPHERE;}
};

gLevelset *myCircle2b (){
  int tag = 5;
  std::vector<const gLevelset*> li,lj;
  li.push_back(new gLevelsetSphere (.5,.5,0,0.464, tag));
  li.push_back(new gLevelsetStrange(tag));
  lj.push_back(new gLevelsetCut(li));
  lj.push_back(new gLevelsetPlane (1.,0.,0.,-.5,tag));
  gLevelset *ls = new gLevelsetIntersection(lj);
  return ls ;//new gLevelsetReverse(ls);
}


// ---------------------------------------------------------------------
// ------------------ MAIN FUNCTION ------------------------------------
// ---------------------------------------------------------------------
int main(int argc, char **argv)
{
  int tag=1;
  //double ptc[3]={1,2.5,2.5};
  //double ptc0[3]={3.25,3.25,3.25};
  //double ptc1[3] = {0,1,0};
  //double ptc2[3] = {0,0,1};
  //double ptc3[3] = {2.5,2.5,0.2};
  //double ptc4[3] = {2.5,1.0,2.5};
  //double ptb1[3] = {0,0,0};
  //double ptb2[3] = {1,0,0};
  //double ptb3[3] = {1,1,0};
  //double ptb4[3] = {0,1,0};
  //double ptb5[3] = {0,0,1};
  //double ptb6[3] = {1,0,1};
  //double ptb7[3] = {1,1,1};
  //double ptb8[3] = {0,1,1};
  //double ptr1[3] = {0,-3,0};
  //double dirc[3]={1,0,0};
  //double dir1[3]={1,0,0};
  //double dir2[3]={0,1,0};
  //double dir3[3]={0,0,1};
  //double dir4[3]={-1,0,0};
  //double dir5[3]={0,-1,0};
  //double dir6[3]={0,0,-1};
  const gLevelsetSphere LsS1 (2.5,2.5,0,2.35,tag);
  const gLevelsetSphere LsS2 (2.5,2.5,0,1.75,tag);
  const gLevelsetSphere LsS3 (2.5,5.,0,2.5,tag);
  const gLevelsetPlane LsP1 (0,1,0,-2.9,tag);
  const gLevelsetPlane LsP2 (-1,0,0,1.25,tag);
  //const gLevelsetEllipsoid LsE (ptb1,dir3,2.54,3.6,4.85,tag);
  //const gLevelsetGenCylinder LsCy (ptc,dirc,4.85,tag);
  //const gLevelsetCone LsCo (ptc1,dirc,PI/4,tag);
  std::vector<const gLevelset *> p;
  p.push_back(&LsS1);
  p.push_back(&LsS2);
  //p.push_back(&LsS1);
  //const gLevelsetCut LSC (p);
  p.clear();
  //p.push_back(&LsCy);
  //p.push_back(&LsCo);
  //p.push_back(&LsE);
  //const gLevelsetCut LsCu (p);
  //p.clear();
  //p.push_back(&LsI);
  //p.push_back(&LsCu);
  //const gLevelsetIntersection LsI2 (p);
  //const gLevelset *ls = myCircle2b();

  //const gLevelset *ls = new gLevelsetCylinder (ptc,dirc,1.5,1,3,tag);
  //const gLevelsetBox Ls2 (ptc,dir1,dir2,dir3,1.05,0.55,0.8,tag);
  //const gLevelset *ls = new gLevelsetConrod (ptc4, dir2, dir3, 1.4, 0.9, 0.6, 0.8, 0.5, 0.6, 0.3, 1, 0.6, 3,tag);
  //const gLevelsetConrod levset (ptr1,dir2,dir3,2.8,1.8,1.2,1.6,1.,1.2,0.6,2.,1.2,6.,tag);
  //const gLevelsetBox Ls4 (ptb1,ptb2,ptb3,ptb4,ptb5,ptb6,ptb7,ptb8,tag);
  //const gLevelsetCylinder Ls8 (ptc4,dir3,0.8,0.5,1,tag);

  //double dirm3[3] = {-dir3[0],-dir3[1],-dir3[2]};
  //double pta2[3] = {ptc3[0],ptc3[1],ptc3[2]+3};
  //std::vector<const gLevelset *> v1;
  //v1.push_back(new gLevelsetGenCylinder (ptc3,dir3,2.2,tag));
  //v1.push_back(new gLevelsetPlane (ptc3,dirm3,tag));
  //v1.push_back(new gLevelsetPlane (pta2,dir3,tag));
  //const gLevelsetIntersection Ls15(v1);
  tag=1;
  //const gLevelset *ls = new gLevelsetPiston(tag);

  /*// teeth
  int tag = 5;
  const double p1 [3]={0.125,0.75,0.};
  const double p2 [3]={0.375,0.75,0.};
  const double p3 [3]={0.625,0.75,0.};
  const double p4 [3]={0.875,0.75,0.};
  const double n1 [3]={-1.,0.125/0.75,0.};
  const double n2 [3]={1.,0.125/0.75,0.};
  gLevelset *ls1 = new gLevelsetPlane (p1, n1, tag);
  gLevelset *ls2 = new gLevelsetPlane (p1, n2, tag);
  gLevelset *ls3 = new gLevelsetPlane (p2, n1, tag);
  gLevelset *ls4 = new gLevelsetPlane (p2, n2, tag);
  gLevelset *ls5 = new gLevelsetPlane (p3, n1, tag);
  gLevelset *ls6 = new gLevelsetPlane (p3, n2, tag);
  gLevelset *ls7 = new gLevelsetPlane (p4, n1, tag);
  gLevelset *ls8 = new gLevelsetPlane (p4, n2, tag);
  std::vector<const gLevelset*> l1,l2,l3,l4,li;
  l1.push_back(ls1);
  l1.push_back(ls2);
  l2.push_back(ls3);
  l2.push_back(ls4);
  l3.push_back(ls5);
  l3.push_back(ls6);
  l4.push_back(ls7);
  l4.push_back(ls8);
  li.push_back(new gLevelsetIntersection(l1));
  li.push_back(new gLevelsetIntersection(l2));
  li.push_back(new gLevelsetIntersection(l3));
  li.push_back(new gLevelsetIntersection(l4));
  const gLevelset *ls = new gLevelsetUnion(li);*/

  /*const double p1 [3]={1.,2.5,2.5};
  const double n1 [3]={1.,0.,0.};
  const double n2 [3]={0.,1.,0.};
  const double n3 [3]={0.,0.,1.};
  gLevelset *ls1 = new gLevelsetPlane (p1, n1, tag);
  gLevelset *ls2 = new gLevelsetPlane (p1, n2, tag);
  gLevelset *ls3 = new gLevelsetPlane (p1, n3, tag);
  std::vector<const gLevelset*> l1;
  l1.push_back(ls1);
  l1.push_back(ls2);
  l1.push_back(ls3);
  const gLevelset *ls = new gLevelsetUnion(l1);*/

  const double pt [3]={0.,0.,0.};
  const double dir[3]={0,0,1};
  tag=1;
  std::vector<const gLevelset*> li;
  li.push_back(new gLevelsetPlane(0,-1,0,0.52, tag));  //  -/+
  li.push_back(new gLevelsetPlane(-1,0,0,0.52, tag));
  //li.push_back(new gLevelsetGenCylinder(pt,dir,.75, tag));  //  -|+
  gLevelset *ls = new gLevelsetIntersection(li);
  //const gLevelset *ls =  new gLevelsetReverse (ls1);
  //gLevelset *ls = new gLevelsetGenCylinder(pt, dir, 0.75, tag);

  GmshInitialize(argc, argv);
  GmshSetOption("General", "Terminal", 1.);
  GModel *m = new GModel;
  m->readMSH(argv[1]); printf("mesh read\n");

  /*printf("  carreTri\n");
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      printf("ptf %d (%g,%g)\n",(*it)->mesh_vertices[i]->getNum(),(*it)->mesh_vertices[i]->x(),(*it)->mesh_vertices[i]->y());
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      printf("pte %d (%g,%g)\n",(*it)->mesh_vertices[i]->getNum(),(*it)->mesh_vertices[i]->x(),(*it)->mesh_vertices[i]->y()); printf("\n");*/

  GModel *cm = m->buildCutGModel(ls); printf("mesh cut\n");

  /*printf("  ccutmesh\n");
  for(GModel::fiter it = cm->firstFace(); it != cm->lastFace(); ++it){
    printf("face %d\n",(*it)->tag());
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      printf("tri %d (%d, %d, %d)\n",(*it)->triangles[i]->getNum(),(*it)->triangles[i]->getVertex(0)->getNum(),(*it)->triangles[i]->getVertex(1)->getNum(),(*it)->triangles[i]->getVertex(2)->getNum());
    //for(unsigned int i = 0; i < (*it)->polygons.size(); i++)
      //printf("poly %d (%d, %d, %d)\n",(*it)->polygons[i]->getNum(),(*it)->polygons[i]->getVertex(0)->getNum(),(*it)->polygons[i]->getVertex(1)->getNum(),(*it)->polygons[i]->getVertex(2)->getNum());
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      printf("ptf %d (%g,%g)\n",(*it)->mesh_vertices[i]->getNum(),(*it)->mesh_vertices[i]->x(),(*it)->mesh_vertices[i]->y());
  }
  for(GModel::eiter it = cm->firstEdge(); it != cm->lastEdge(); ++it){
    printf("edge %d\n",(*it)->tag());
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      printf("pte %d (%g,%g)\n",(*it)->mesh_vertices[i]->getNum(),(*it)->mesh_vertices[i]->x(),(*it)->mesh_vertices[i]->y());
  }*/

  cm->writeMSH("cutMesh.msh",2); printf("mesh written\n");

  /*GFace *gf = m->getFaceByTag(6); std::cout<<"face "<<gf<< " "<<gf->mesh_vertices.size()<<std::endl;
  GEdge *ge1 = m->getEdgeByTag(1); std::cout<<"edge1 "<<ge1<< " "<<ge1->mesh_vertices.size()<<std::endl;
  GEdge *ge2 = m->getEdgeByTag(2); std::cout<<"edge2 "<<ge2<< " "<<ge2->mesh_vertices.size()<<std::endl;
  GEdge *ge3 = m->getEdgeByTag(3); std::cout<<"edge3 "<<ge3<< " "<<ge3->mesh_vertices.size()<<std::endl;
  GEdge *ge4 = m->getEdgeByTag(4); std::cout<<"edge4 "<<ge4<< " "<<ge4->mesh_vertices.size()<<std::endl;
  for(int i = 0; i < gf->mesh_vertices.size(); i++)
    if(gf->mesh_vertices[i]->x() == 2 && gf->mesh_vertices[i]->y() == 0)
      std::cout << "face MVertex " << gf->mesh_vertices[i]->getNum() << " " << gf->mesh_vertices[i]->onWhat()->tag() << " " << gf->mesh_vertices[i] << " " << gf->mesh_vertices[i]->onWhat() << std::endl;
  for(int i = 0; i < ge3->mesh_vertices.size(); i++)
    if(ge3->mesh_vertices[i]->x() == 2 && ge3->mesh_vertices[i]->y() == 0)
      std::cout << "edge3 MVertex " << ge3->mesh_vertices[i]->getNum() << " " << ge3->mesh_vertices[i]->onWhat()->tag() << " " << ge3->mesh_vertices[i] << " " << ge3->mesh_vertices[i]->onWhat() << std::endl;
  for(int i = 0; i < ge4->mesh_vertices.size(); i++)
    if(ge4->mesh_vertices[i]->x() == 2 && ge4->mesh_vertices[i]->y() == 0)
      std::cout << "edge4 MVertex " << ge4->mesh_vertices[i]->getNum() << " " << ge4->mesh_vertices[i]->onWhat()->tag() << " " << ge4->mesh_vertices[i] << " " << ge4->mesh_vertices[i]->onWhat() << std::endl;*/

  //pGModel model = 0;
  //pMesh mesh = MS_newMesh(model);
  //M_load(mesh, "cubeHex.msh");

  std::vector<DI_IntegrationPoint> ip;    // contains the volume Integration points
  std::vector<DI_IntegrationPoint> ipS;   // contains the surface Integration points
  std::vector<DI_CuttingPoint> cp;        // contains the cutting points
  std::vector<DI_Line> surfLines;         // contains the line contour
  std::vector<DI_Triangle> surfTriangles; // contains the triangles forming the crack surface
  std::vector<DI_Quad> surfQuads;         // contains the quads forming the crack surface
  std::vector<DI_Tetra> Tetras;           // contains the tetrahedra formed by the cutting of the hexahedra/tetrahedra and the tetrahedra not cut by the level set
  std::vector<DI_Hexa> Hexas;             // contains the hexahedra not cut by the level set

  std::vector<const gLevelset *> primitives;
  ls->getPrimitives(primitives);
  //printf("prim = \n"); for(int i=0;i<(int)primitives.size();i++) {primitives[i]->print(); printf("LS(0,0)=%g LS(1,1)=%g\n",(*primitives[i])(0,0,0),(*primitives[i])(1,1,0));}
  std::vector<const gLevelset *> RPN;
  ls->getRPN(RPN);
  //printf("RPN = \n"); for(int i=0;i<(int)RPN.size();i++) {RPN[i]->print(); printf("LS(0,0)=%g LS(1,1)=%g\n",(*RPN[i])(0,0,0),(*RPN[i])(1,1,0));}

//  getIntegrationPoints(m, *ls, ip, ipS, cp, surfLines, surfTriangles, surfQuads, Tetras, Hexas);
//  writePosFile (ip, ipS, cp, surfLines, surfTriangles, surfQuads, Tetras, Hexas);

}
