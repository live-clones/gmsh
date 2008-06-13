// small additions to the netgen interface library for Gmsh

#include "meshing.hpp"
#include "mystdlib.h"

namespace nglib {
#include "nglib.h"
}

using namespace netgen;

#include <iostream>
#include "Message.h"

namespace nglib
{

class mystreambuf: public streambuf
{
  int index;
  char txt[1024];
 public:
  mystreambuf() { 
    index = 0; 
  }
  int sync(){ 
    txt[index] = '\0';
    if(!index || 
       (index == 1 && (txt[0] == '.' || txt[0] == '+' || txt[0] == ' '))){
      // ignore these messages
    }
    else{
      if(!strncmp(txt, "ERROR", 5))
	Msg::Error(txt);
      else
	Msg::Info(txt);
    }
    index = 0; 
    return 0; 
  }
  int overflow(int ch){ 
    if(index < 1023){
      txt[index] = ch;
      if(txt[index] == '\n' || txt[index] == '\r') txt[index] = ' ';
      if(!index && txt[0] == ' '){
	// skip initial spaces
      }
      else{
	index++;
      }
    }
    return 0; 
  }
};

// replaces the standard Ng_Init
void NgAddOn_Init()
{
  //mycout = &cout;
  //myerr = &cerr;
  //testout = new ofstream ("test.out");
  static bool first = true;
  if(first){
    first = false;
    mycout = new ostream(new mystreambuf());
    myerr = new ostream(new mystreambuf());
    testout = new ofstream("/dev/null");
  }
}

// generates volume mesh from surface mesh, without optimization
Ng_Result NgAddOn_GenerateVolumeMesh(Ng_Mesh *mesh, double maxh)
{
  Mesh *m = (Mesh*)mesh;

  MeshingParameters mparam;
  mparam.uselocalh = 1;
  mparam.maxh = maxh;
  
  try{
    m->CalcLocalH();
    MeshVolume(mparam, *m);
    //RemoveIllegalElements(*m);
    //OptimizeVolume(mparam, *m);
  }
  catch(netgen::NgException error){
    return NG_VOLUME_FAILURE;
  }
  return NG_OK;
}

// optimizes an existing 3D mesh
Ng_Result NgAddOn_OptimizeVolumeMesh(Ng_Mesh *mesh, double maxh)
{
  Mesh *m = (Mesh*)mesh;

  MeshingParameters mparam;
  mparam.uselocalh = 1;
  mparam.maxh = maxh;

  try{
    m->CalcLocalH();
    //MeshVolume(mparam, *m);
    RemoveIllegalElements(*m);
    OptimizeVolume(mparam, *m);
  }
  catch(netgen::NgException error){
    return NG_VOLUME_FAILURE;
  }
  return NG_OK;
}

}
