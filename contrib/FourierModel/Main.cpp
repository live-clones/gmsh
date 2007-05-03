#include <cstring>
#include <iostream>
#include "Utils.h"
#include "Message.h"
#include "FM_Reader.h"

int main(int argc, char *argv[])
{
  char* fn;
  char continuation[16] = "continuation";

  if (argc == 1) {
    Msg::Info("Reading from default file : untitled.fm");
    fn = "untitled.fm";
  }
  else
    fn = argv[1];

  FM_Reader reader(fn);

  /*
  
  int n1=64;
  int n2=64;
  double h1 = 1./(n1-1);
  double h2 = 1./(n2-1);
  for (int j=0;j<n1;j++) {
    for (int k=0;k<n2;k++) {
      double u = j*h1;
      double v = k*h2;
      double x, y, z;
      patches[0]->F(u,v,x,y,z);
      printf("x(%d,%d) = %g; y(%d,%d) = %g; z(%d,%d) = %g;\n",
	     j+1,k+1,x,j+1,k+1,y,j+1,k+1,z);
    }
  } 
  
  for (int i=0;i<reader.GetNumIntersections();i++) {
    int n=128;
    double h = 1./(n-1);
    for (int j=0;j<n;j++) {
      double t = j*h;
      double x, y, z;
      reader.GetIntersection(i)->F(t,x,y,z);
      printf("x(%d,%d) = %g; y(%d,%d) = %g; z(%d,%d) = %g;\n",
	     i+1,j+1,x,i+1,j+1,y,i+1,j+1,z);
    }
  }

  for (int i=0;i<reader.GetNumPatches();i++) {
    std::cout << reader.GetPatchList()[i]->tag << "\n";
    std::cout << reader.GetPatchList()[i]->type << "\n";
    std::cout << reader.GetPatchList()[i]->projection << "\n";
    std::cout << reader.GetPatchList()[i]->normal[0] << " " << 
      reader.GetPatchList()[i]->normal[1] << " " << 
      reader.GetPatchList()[i]->normal[2] << "\n";
    std::cout << reader.GetPatchList()[i]->origin[0] << " " <<
      reader.GetPatchList()[i]->origin[1] << " " <<
      reader.GetPatchList()[i]->origin[2] << "\n";
    std::cout << reader.GetPatchList()[i]->tangent[0] << " " <<
      reader.GetPatchList()[i]->tangent[1] << " " <<
      reader.GetPatchList()[i]->tangent[2] << "\n";
    if (!strcmp(reader.GetPatchList()[i]->type,continuation)) {
      std::cout << reader.GetPatchList()[i]->periodic[0] << " " <<
      reader.GetPatchList()[i]->periodic[1] << "\n";
      std::cout << reader.GetPatchList()[i]->nModes[0] << " " <<
      reader.GetPatchList()[i]->nModes[1] << "\n";
      for (int j=0;j<reader.GetPatchList()[i]->nModes[0];j++)
	for (int k=0;k<reader.GetPatchList()[i]->nModes[1];k++)
	  std::cout << reader.GetPatchList()[i]->coeff[j][k].real() << " " <<
	    reader.GetPatchList()[i]->coeff[j][k].imag() << "\n";
    }
  }
  
  for (int i=0;i<reader.GetIntersectionList().size();i++) {
    std::cout << reader.GetIntersectionList()[i]->tag << "\n";
    std::cout << reader.GetIntersectionList()[i]->SP[0] <<
      " " << reader.GetIntersectionList()[i]->SP[1] << " " <<
	      reader.GetIntersectionList()[i]->SP[2] << "\n";
    std::cout << reader.GetIntersectionList()[i]->EP[0] <<
      " " << reader.GetIntersectionList()[i]->EP[1] << " " <<
      reader.GetIntersectionList()[i]->EP[2] << "\n";
    std::cout << reader.GetIntersectionList()[i]->
      intersectingPatches[0].patchTag << "\n";
    std::cout << reader.GetIntersectionList()[i]->
      intersectingPatches[1].patchTag << "\n";
  }
  */

  int nU=64;
  int nV=64;

  std::vector<int> color(3);
  color[0] = 0; color[1] = 0; color[2] = 1;
  
  std::vector<std::vector<double> > x(nU,std::vector<double>(nV));
  std::vector<std::vector<double> > y(nU,std::vector<double>(nV));
  std::vector<std::vector<double> > z(nU,std::vector<double>(nV));

  std::vector<std::vector<int> > mask = ones(nU,nV);

  for (int i=0;i<reader.GetNumFaces();i++) {
    double hU = 1./(nU-1);
    double hV = 1./(nV-1);
    for (int j=0;j<nU;j++) {
      for (int k=0;k<nV;k++) {
	double u = j*hU;
	double v = k*hV;
	reader.GetFace(i)->F(u,v,x[j][k],y[j][k],z[j][k]);
      }
    }
    if (i == 0)
      plotSceneViewer(0,"snc.iv",color,x,y,z,nU,nV,mask);
    else
      plotSceneViewer(1,"snc.iv",color,x,y,z,nU,nV,mask);
  }
}
