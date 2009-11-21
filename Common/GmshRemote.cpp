// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GmshMessage.h"
#include "GmshSocket.h"
#include "OpenFile.h"
#include "OS.h"
#include "VertexArray.h"
#include "GmshRemote.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "PViewDataRemote.h"
#endif

#if defined(HAVE_MPI)
#include <mpi.h>
#define MPI_GMSH_COMPUTE_VIEW  1
#define MPI_GMSH_DATA_READY    2
#define MPI_GMSH_VARRAY        3
#define MPI_GMSH_VARRAY_LEN    4
#define MPI_GMSH_SHUTDOWN      5
#define MPI_GMSH_PARSE_STRING  6
#define MPI_GMSH_MERGE_FILE    7
#endif

static void computeAndSendVertexArrays(GmshClient *client, bool compute=true)
{
#if defined(HAVE_POST)
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PView *p = PView::list[i];
    if (compute)
      p->fillVertexArrays();
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();
    double min = data->getMin(), max = data->getMax();
    if(opt->rangeType == PViewOptions::PerTimeStep){
      min = data->getMin(opt->timeStep);
      max = data->getMax(opt->timeStep);
    }
    VertexArray *va[4] = 
      {p->va_points, p->va_lines, p->va_triangles, p->va_vectors};
    for(int type = 0; type < 4; type++){
      if(va[type]){
        int len;
        char *str = va[type]->toChar
          (p->getNum(), data->getName(), type + 1, min, max, 
           data->getNumTimeSteps(), data->getTime(opt->timeStep),
           data->getBoundingBox(), len);
        client->SendMessage(GmshSocket::GMSH_VERTEX_ARRAY, len, str);
        delete [] str;
      }
    }
  }
#endif
}

// This version sends VArrays using MPI
static void computeAndSendVertexArrays()
{
#if defined(HAVE_POST) && defined(HAVE_MPI)
  // compute...
  for(unsigned int i = 0; i < PView::list.size(); i++)
    PView::list[i]->fillVertexArrays();

  // ...and send
  int nbArrays = PView::list.size()* 4;
  MPI_Send(&nbArrays, 1, MPI_INT, 0, MPI_GMSH_DATA_READY, MPI_COMM_WORLD);

  for(unsigned int i = 0; i < PView::list.size(); i++){
    PView *p = PView::list[i];
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();
    double min = data->getMin(), max = data->getMax();
    if(opt->rangeType == PViewOptions::PerTimeStep){
      min = data->getMin(opt->timeStep);
      max = data->getMax(opt->timeStep);
    }
    VertexArray *va[4] = 
      {p->va_points, p->va_lines, p->va_triangles, p->va_vectors};
    for(int type = 0; type < 4; type++){
      if(va[type]){
        int len;
        char *str = va[type]->toChar
          (p->getNum(), data->getName(), type + 1, min, max, 
           data->getNumTimeSteps(), data->getTime(opt->timeStep),
           data->getBoundingBox(), len);
	MPI_Send(&len, 1, MPI_INT, 0, MPI_GMSH_VARRAY_LEN, MPI_COMM_WORLD);
	MPI_Send(str, len, MPI_CHAR, 0, MPI_GMSH_VARRAY, MPI_COMM_WORLD);
        delete [] str;
      }
    }
  }
#endif
}

// Merge the vertex arrays
void addToVertexArrays(const char* bytes, int len)
{
  int is = sizeof(int), ds = sizeof(double);

  std::string name;

  int index = 0;
  int num; memcpy(&num, &bytes[index], is); index += is;
  int ss; memcpy(&ss, &bytes[index], is); index += is;
  if(ss){
    std::vector<char> n(ss);
    memcpy(&n[0], &bytes[index], ss); index += ss;
    for(unsigned int i = 0; i < n.size(); i++) name += n[i];
  }
  
  int type; memcpy(&type, &bytes[index], is); index += is;
  
  PView *p = PView::list[num-1];
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();
  
  VertexArray *varrays[4] = 
    {p->va_points, p->va_lines, p->va_triangles, p->va_vectors};
  
  VertexArray *va = varrays[type-1];
  
  double min; memcpy(&min, &bytes[index], ds); index += ds;
  double max; memcpy(&max, &bytes[index], ds); index += ds;
  int numsteps; memcpy(&numsteps, &bytes[index], is); index += is;
  double time; memcpy(&time, &bytes[index], ds); index += ds;
  double xmin; memcpy(&xmin, &bytes[index], ds); index += ds;
  double ymin; memcpy(&ymin, &bytes[index], ds); index += ds;
  double zmin; memcpy(&zmin, &bytes[index], ds); index += ds;
  double xmax; memcpy(&xmax, &bytes[index], ds); index += ds;
  double ymax; memcpy(&ymax, &bytes[index], ds); index += ds;
  double zmax; memcpy(&zmax, &bytes[index], ds); index += ds;

  if (data->getMin() > min) data->setMin(min);
  if (data->getMax() < max) data->setMax(max);
  
  SBoundingBox3d bbox(xmin, ymin, zmin, xmax, ymax, zmax);
  SBoundingBox3d bb = data->getBoundingBox();
  bb += bbox;

  data->setBoundingBox(bb);

  if (type == 4) type = 2;
  VertexArray* toAdd = new VertexArray(type,100);
  toAdd->fromChar(bytes,0);
  va->merge(toAdd);
  delete toAdd;
}

int GmshRemote()
{
  GmshClient *client = Msg::GetClient();
  
  int rank = Msg::GetCommRank();
  int nbDaemon = Msg::GetCommSize();

  if(!client && rank == 0) return 0;

  if(client && nbDaemon < 2) computeAndSendVertexArrays(client);

  while(1){

    // on the node with MPI rank 0, communicate through a socket
    if (rank == 0) {
      // stop if we have no communications for 5 minutes
      int ret = client->Select(300, 0);
      if(!ret){
	client->Info("Timout: stopping remote Gmsh...");
	break;
      }
      else if(ret < 0){
	client->Error("Error on select: stopping remote Gmsh...");
	break;
      }

      int type, length, swap;
      if(!client->ReceiveHeader(&type, &length, &swap)){
	client->Error("Did not receive message header: stopping remote Gmsh...");
	break;
      }
      
      char *msg = new char[length + 1];
      if(!client->ReceiveString(length, msg)){
	client->Error("Did not receive message body: stopping remote Gmsh...");
	delete [] msg;
	break;
      }

      if(type == GmshSocket::GMSH_STOP){
	client->Info("Stopping remote Gmsh...");
	break;
      }
      else if(type == GmshSocket::GMSH_VERTEX_ARRAY){
#if !defined(HAVE_MPI)
        ParseString(msg);
        computeAndSendVertexArrays(client);
#else
        // FIXME should parse options on each node before computing varrays!

	// tell every node to start computing
	int mpi_msg = MPI_GMSH_COMPUTE_VIEW;
	MPI_Bcast(&mpi_msg, 1, MPI_INT, 0, MPI_COMM_WORLD);
	// fill the arrays on the master node
	for(unsigned int i = 0; i < PView::list.size(); i++)
          PView::list[i]->fillVertexArrays();
	// wait and send the data from every other node
	for (int i = 0; i < nbDaemon - 1; i++) {
	  int nbArrays;
	  MPI_Status status;
	  MPI_Recv(&nbArrays, 1, MPI_INT, MPI_ANY_SOURCE,
		   MPI_GMSH_DATA_READY, MPI_COMM_WORLD, &status);
	  int source = status.MPI_SOURCE;
	  // get each varray in turn, then add it to the varrays of
	  // the master node
	  for (int j = 0; j < nbArrays; j++) {
	    int len;
	    MPI_Status status2;
	    MPI_Recv(&len, 1, MPI_INT, status.MPI_SOURCE,
		     MPI_GMSH_VARRAY_LEN, MPI_COMM_WORLD, &status2);
	    char str[len];
	    MPI_Recv(str, len, MPI_CHAR, status.MPI_SOURCE,
		     MPI_GMSH_VARRAY, MPI_COMM_WORLD, &status2);
            addToVertexArrays(str,len);
	  }
	}
	computeAndSendVertexArrays(client, false);
#endif
      }
      else if(type == GmshSocket::GMSH_MERGE_FILE){
	MergeFile(msg);
#if !defined(HAVE_MPI)
	computeAndSendVertexArrays(client);
#else
	int mpi_msg = MPI_GMSH_MERGE_FILE;
	MPI_Bcast(&mpi_msg, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(msg, length, MPI_CHAR, 0, MPI_COMM_WORLD);
#endif
      }
      else if(type == GmshSocket::GMSH_PARSE_STRING){
	ParseString(msg);
#if defined(HAVE_MPI)
	int mpi_msg = MPI_GMSH_PARSE_STRING;
	MPI_Bcast(&mpi_msg, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(msg, length, MPI_CHAR, 0, MPI_COMM_WORLD);
#endif
      }
      else if(type == GmshSocket::GMSH_SPEED_TEST){
	client->Info("Sending huge array");
	std::string huge(500000000, 'a');
	client->SpeedTest(huge.c_str());
      }
      else{
	client->Error("Ignoring unknown message");
      }
    
      delete [] msg;
    } 
    else { // if we're not on the master node (rank != 0) wait for him...
#if defined(HAVE_MPI)
      int mpi_msg; 
      MPI_Bcast(&mpi_msg, 1, MPI_INT, 0, MPI_COMM_WORLD);
      if (mpi_msg == MPI_GMSH_COMPUTE_VIEW)
	computeAndSendVertexArrays();
      else if(mpi_msg == MPI_GMSH_SHUTDOWN)
	Msg::Exit(0);
      else if(mpi_msg == MPI_GMSH_PARSE_STRING){
	int length;
	MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);
	char msg[length];
	MPI_Bcast(msg, length, MPI_CHAR, 0, MPI_COMM_WORLD);
	ParseString(msg);
      }
      else if (mpi_msg == MPI_GMSH_MERGE_FILE){
	int length;
	MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);
	char msg[length];
	MPI_Bcast(msg, length, MPI_CHAR, 0, MPI_COMM_WORLD);
	MergeFile(msg);
      }
#endif
    }
  }
  
#if defined(HAVE_MPI)
  int mpi_msg = MPI_GMSH_SHUTDOWN;
  MPI_Bcast(&mpi_msg, 1, MPI_INT, 0, MPI_COMM_WORLD);
#endif

  return 0;
}
