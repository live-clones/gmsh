// Interface to the Netgen meshing kernel for Gmsh. This file replaces
// the original nglib.cpp file from the Netgen distribution.

#include <GmshMessage.h>
#include <linalg.hpp>
#include <meshing.hpp>
#include <nginterface.h>

namespace netgen
{
   int id, ntasks;
   MeshingParameters mparam;
}

namespace nglib {
#include "nglib.h"
}

using namespace netgen;

namespace nglib
{
  class mystreambuf : public streambuf {
    int index;
    char txt[1024];
  public:
    mystreambuf() : index(0) {}
    int sync()
    {
      txt[index] = '\0';
      if(!index || (index == 1 && (txt[0] == '.' || txt[0] == '+' ||
                                   txt[0] == ' ' || txt[0] == '*'))){
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
    int overflow(int ch)
    {
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

   // initialize, deconstruct Netgen library:
   void Ng_Init ()
   {
     // mycout = &cout;
     // myerr = &cerr;
     // netgen::testout->SetOutStream (new ofstream ("test.out"));
     // testout = new ofstream ("test.out");
     static bool first = true;
     if(first){
       first = false;
       //mycout = &cout;
       //myerr = &cout;
       //testout = &cout;
       mycout = new ostream(new mystreambuf());
       myerr = new ostream(new mystreambuf());
       testout = new ostream(new mystreambuf());
     }
   }

   // Clean-up functions before ending usage of nglib
  void Ng_Exit ()
   {
      ;
   }

   // Create a new netgen mesh object
  Ng_Mesh * Ng_NewMesh ()
  {
    Mesh * mesh = new Mesh;
    mesh->AddFaceDescriptor (FaceDescriptor (1, 1, 0, 1));
    return (Ng_Mesh*)(void*)mesh;
  }

  // Delete an existing netgen mesh object
  void Ng_DeleteMesh (Ng_Mesh * mesh)
  {
    if(mesh != NULL)
      {
        // Delete the Mesh structures
        ((Mesh*)mesh)->DeleteMesh();

        // Now delete the Mesh class itself
        delete (Mesh*)mesh;

        // Set the Ng_Mesh pointer to NULL
        mesh = NULL;
      }
  }

  // Manually add a point to an existing mesh object
  void Ng_AddPoint (Ng_Mesh * mesh, double * x)
  {
    Mesh * m = (Mesh*)mesh;
    m->AddPoint (Point3d (x[0], x[1], x[2]));
  }

  // Manually add a surface element of a given type to an existing mesh object
  void Ng_AddSurfaceElement (Ng_Mesh * mesh, Ng_Surface_Element_Type et,
                             int * pi)
  {
    Mesh * m = (Mesh*)mesh;
    Element2d el (3);
    el.SetIndex (1);
    el.PNum(1) = pi[0];
    el.PNum(2) = pi[1];
    el.PNum(3) = pi[2];
    m->AddSurfaceElement (el);
  }

  // Manually add a volume element of a given type to an existing mesh object
  void Ng_AddVolumeElement (Ng_Mesh * mesh, Ng_Volume_Element_Type et,
                            int * pi)
  {
    Mesh * m = (Mesh*)mesh;
    Element el (4);
    el.SetIndex (1);
    el.PNum(1) = pi[0];
    el.PNum(2) = pi[1];
    el.PNum(3) = pi[2];
    el.PNum(4) = pi[3];
    m->AddVolumeElement (el);
  }

  // Obtain the number of points in the mesh
  int Ng_GetNP (Ng_Mesh * mesh)
  {
    return ((Mesh*)mesh) -> GetNP();
  }

  // Obtain the number of volume elements in the mesh
  int Ng_GetNE (Ng_Mesh * mesh)
  {
    return ((Mesh*)mesh) -> GetNE();
  }

  //  Return point coordinates of a given point index in the mesh
  void Ng_GetPoint (Ng_Mesh * mesh, int num, double * x)
  {
    const Point3d & p = ((Mesh*)mesh)->Point(num);
    x[0] = p.X();
    x[1] = p.Y();
    x[2] = p.Z();
  }

  // Return the volume element at a given index "pi"
  Ng_Volume_Element_Type
  Ng_GetVolumeElement (Ng_Mesh * mesh, int num, int * pi)
  {
    const Element & el = ((Mesh*)mesh)->VolumeElement(num);
    for (int i = 1; i <= el.GetNP(); i++)
      pi[i-1] = el.PNum(i);
    Ng_Volume_Element_Type et;
    switch (el.GetNP())
      {
      case 4: et = NG_TET; break;
      case 5: et = NG_PYRAMID; break;
      case 6: et = NG_PRISM; break;
      case 10: et = NG_TET10; break;
      default:
        et = NG_TET; break; // for the compiler
      }
    return et;
  }

  // Generates volume mesh from an existing surface mesh
  Ng_Result Ng_GenerateVolumeMesh (Ng_Mesh * mesh, Ng_Meshing_Parameters * mp)
  {
    Mesh * m = (Mesh*)mesh;

    // Philippose - 30/08/2009
    // Do not locally re-define "mparam" here... "mparam" is a global
    // object
    //MeshingParameters mparam;
    mp->Transfer_Parameters();

    m->CalcLocalH(mparam.grading);

    MeshVolume (mparam, *m);
    RemoveIllegalElements (*m);
    OptimizeVolume (mparam, *m);

    return NG_OK;
  }

  // Generates volume mesh from an existing surface mesh
  Ng_Result Ng_GenerateVolumeMesh (Ng_Mesh * mesh, double maxh)
  {
    Mesh *m = (Mesh*)mesh;

    MeshingParameters mparam;
    mparam.uselocalh = 1;
    mparam.maxh = maxh;

    try{
      m->CalcLocalH(mparam.grading);
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
  Ng_Result Ng_OptimizeVolumeMesh(Ng_Mesh *mesh, double maxh)
  {
    Mesh *m = (Mesh*)mesh;

    MeshingParameters mparam;
    mparam.uselocalh = 1;
    mparam.maxh = maxh;

    try{
      m->CalcLocalH(mparam.grading);
      //MeshVolume(mparam, *m);
      RemoveIllegalElements(*m);
      OptimizeVolume(mparam, *m);
    }
    catch(netgen::NgException error){
      return NG_VOLUME_FAILURE;
    }
    return NG_OK;
  }

  // ------------------ Begin - Meshing Parameters related functions ------------------
  // Constructor for the local nglib meshing parameters class
  Ng_Meshing_Parameters :: Ng_Meshing_Parameters()
  {
    uselocalh = 1;

    maxh = 1000;
    minh = 0.0;

    fineness = 0.5;
    grading = 0.3;

    elementsperedge = 2.0;
    elementspercurve = 2.0;

    closeedgeenable = 0;
    closeedgefact = 2.0;

    second_order = 0;
    quad_dominated = 0;

    meshsize_filename = 0;

    optsurfmeshenable = 1;
    optvolmeshenable = 1;

    optsteps_2d = 3;
    optsteps_3d = 3;

    invert_tets = 0;
    invert_trigs = 0;

    check_overlap = 1;
    check_overlapping_boundary = 1;
  }

  // Reset the local meshing parameters to the default values
  void Ng_Meshing_Parameters :: Reset_Parameters()
  {
    uselocalh = 1;

    maxh = 1000;
    minh = 0;

    fineness = 0.5;
    grading = 0.3;

    elementsperedge = 2.0;
    elementspercurve = 2.0;

    closeedgeenable = 0;
    closeedgefact = 2.0;

    second_order = 0;
    quad_dominated = 0;

    meshsize_filename = 0;

    optsurfmeshenable = 1;
    optvolmeshenable = 1;

    optsteps_2d = 3;
    optsteps_3d = 3;

    invert_tets = 0;
    invert_trigs = 0;

    check_overlap = 1;
    check_overlapping_boundary = 1;
  }

  //
  void Ng_Meshing_Parameters :: Transfer_Parameters()
  {
    mparam.uselocalh = uselocalh;

    mparam.maxh = maxh;
    mparam.minh = minh;

    mparam.grading = grading;
    mparam.curvaturesafety = elementspercurve;
    mparam.segmentsperedge = elementsperedge;

    mparam.secondorder = second_order;
    mparam.quad = quad_dominated;

    mparam.meshsizefilename = meshsize_filename;

    mparam.optsteps2d = optsteps_2d;
    mparam.optsteps3d = optsteps_3d;

    mparam.inverttets = invert_tets;
    mparam.inverttrigs = invert_trigs;

    mparam.checkoverlap = check_overlap;
    mparam.checkoverlappingboundary = check_overlapping_boundary;
  }

} // End of namespace nglib

// compatibility functions:
namespace netgen
{
   char geomfilename[255];

   void MyError (const char * ch)
   {
     (*myerr) << ch;
   }




   //Destination for messages, errors, ...
   void Ng_PrintDest(const char * s)
   {
      (*mycout) << s << flush;
   }




   double GetTime ()
   {
      return 0;
   }




   void ResetTime ()
   {
      ;
   }




   void MyBeep (int i)
   {
      ;
   }




   void Render()
   {
      ;
   }
} // End of namespace netgen


void Ng_Redraw () { ; }
void Ng_ClearSolutionData () { ; }
void Ng_SetSolutionData (Ng_SolutionData * soldata) { ; }
void Ng_InitSolutionData (Ng_SolutionData * soldata) { ; }
