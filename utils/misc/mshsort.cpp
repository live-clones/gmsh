// $Id: mshsort.cpp,v 1.1 2004-10-08 04:36:21 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

// A small utility that reads a Gmsh mesh file and makes the numbering
// dense (without gaps in the node/element number sequences)

#include <stdio.h>
#include <strings.h>
#include <vector>
#include <map>

using namespace std;

int getNumNodes(int type)
{
  switch (type) {
  case 15: return 1;              // point
  case 1 : return 2;              // line 1
  case 8 : return 2 + 1;          // line 2
  case 2 : return 3;              // triangle 1
  case 9 : return 3 + 3;          // triangle 2
  case 3 : return 4;              // quadrangle 1
  case 10: return 4 + 4 + 1;      // quadrangle 2
  case 4 : return 4;              // tetrahedron 1
  case 11: return 4 + 6;          // tetrahedron 2
  case 5 : return 8;              // hexahedron 1
  case 12: return 8 + 12 + 6 + 1; // hexahedron 2 
  case 6 : return 6;              // prism 1
  case 13: return 6 + 9 + 3;      // prism 2
  case 7 : return 5;              // pyramid 1
  case 14: return 5 + 8 + 1;      // pyramid 2
  default: return 0;
  }
}

class node{
 private:
  int _num;
  double _x, _y, _z;
 public:
  node(double x, double y, double z) 
    : _num(0), _x(x), _y(y), _z(z) {}
  void setNum(int num){ _num = num; }
  int getNum(){ return _num; }
  void print(double version){
    fprintf(stdout, "%d %.16g %.16g %.16g\n", _num, _x, _y, _z);
  }
};

class element{
 private:
  int _num, _type, _physical, _elementary, _partition;
  vector<node*> _nodes;
 public:
  element(int type, int physical, int elementary, int partition) 
    : _num(0), _type(type), _physical(physical), _elementary(elementary),
      _partition(partition) {}
  void setNum(int num){ _num = num; }
  void addNode(node *n){ _nodes.push_back(n); }
  void print(double version){
    if(version == 2.0)
      fprintf(stdout, "%d %d 3 %d %d %d", _num, _type, _physical, 
	      _elementary, _partition);
    else
      fprintf(stdout, "%d %d %d %d %d", _num, _type, _physical,
	      _elementary, (int)_nodes.size());
    for(unsigned int i = 0; i < _nodes.size(); i++)
      fprintf(stdout, " %d", _nodes[i]->getNum());
    fprintf(stdout, "\n");
  }
};

double readMesh(char *fileName, map<int, node*> &nodes, vector<element*> &elements)
{
  FILE *fp = fopen(fileName, "r");

  if(!fp){
    fprintf(stderr, "Error: Unable to open file '%s'\n", fileName);
    exit(1);
  }

  double version = 1.0;

  while(1) {
    char str[256];
    do {
      fgets(str, sizeof(str), fp);
      if(feof(fp))
        break;
    } while(str[0] != '$');
    
    if(feof(fp))
      break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {
      int format, size;
      fscanf(fp, "%lf %d %d\n", &version, &format, &size);
      if(version != 2.0){
	fprintf(stderr, "Error: Wrong msh file version %g\n", version);
	exit(1);
      }
      if(format){
        fprintf(stderr, "Error: Unknown data format for mesh\n");
        exit(1);
      }
    }
    else if(!strncmp(&str[1], "NOD", 3) ||
	    !strncmp(&str[1], "NOE", 3) ||
	    !strncmp(&str[1], "Nodes", 5)) {
      int numNodes;
      fscanf(fp, "%d", &numNodes);
      for(int i = 0; i < numNodes; i++) {
	int num;
	double x, y, z;
        fscanf(fp, "%d %lf %lf %lf", &num, &x, &y, &z);
	if(nodes.count(num)){
	  fprintf(stderr, "Error: node %d already exists\n", num);
	  exit(1);
	}
	else
	  nodes[num] = new node(x, y, z);
      }
    }
    else if(!strncmp(&str[1], "ELM", 3) ||
	    !strncmp(&str[1], "Elements", 8)) {
      int numElements;
      fscanf(fp, "%d", &numElements);
      for(int i = 0; i < numElements; i++) {
	int num, type, physical, elementary, partition = 0, numNodes, numTags;
	if(version <= 1.0){
	  fscanf(fp, "%d %d %d %d %d",
		 &num, &type, &physical, &elementary, &numNodes);
	  int numNodesCheck = getNumNodes(type);
	  if(!numNodesCheck){
	    fprintf(stderr, "Error: Unknown type %d for element %d\n", type, num); 
	    exit(1);
	  }
	  if(numNodes != numNodesCheck){
	    fprintf(stderr, "Error: Wrong number of nodes for element %d\n", num);
	    exit(1);
	  }
	}
	else{
	  fscanf(fp, "%d %d %d", &num, &type, &numTags);
	  elementary = physical = partition = 1;
	  for(int j = 0; j < numTags; j++){
	    int tag;
	    fscanf(fp, "%d", &tag);	    
	    if(j == 0)
	      physical = tag;
	    else if(j == 1)
	      elementary = tag;
	    else if(j == 2)
	      partition = tag;
	    // ignore any other tags for now
	  }
	  numNodes = getNumNodes(type);
	  if(!numNodes){
	    fprintf(stderr, "Error: Unknown type %d for element %d\n", type, num); 
	    exit(1);
	  }
	}
	element *e = new element(type, elementary, physical, partition);
        for(int j = 0; j < numNodes; j++){
	  int numNode;
          fscanf(fp, "%d", &numNode);
	  if(nodes.count(numNode))
	    e->addNode(nodes[numNode]);
	  else{
            fprintf(stderr, "Error: Unknown vertex %d in element %d\n", numNode,  num);
	    exit(1);
	  }
	}
	elements.push_back(e);
      }
    }

    do {
      fgets(str, sizeof(str), fp);
      if(feof(fp)){
        fprintf(stderr, "Error: Prematured end of mesh file\n");
	exit(1);
      }
    } while(str[0] != '$');
    
  }

  fclose(fp);

  return version;
}

void printMesh(double version, map<int, node*> nodes, vector<element*> elements)
{
  map<int, node*>::const_iterator it = nodes.begin();
  map<int, node*>::const_iterator ite = nodes.end();

  if(version == 2.0){
    fprintf(stdout, "$MeshFormat\n");
    fprintf(stdout, "2.0 0 %d\n", sizeof(double));
    fprintf(stdout, "$EndMeshFormat\n");
    fprintf(stdout, "$Nodes\n");
  }
  else
    fprintf(stdout, "$NOD\n");
  fprintf(stdout, "%d\n", (int)nodes.size());

  int index = 1;
  for(;it!=ite;++it){
    it->second->setNum(index++);
    it->second->print(version);
  }

  if(version == 2.0){
    fprintf(stdout, "$EndNodes\n");
    fprintf(stdout, "$Elements\n");
  }
  else{
    fprintf(stdout, "$ENDNOD\n");
    fprintf(stdout, "$ELM\n");
  }
  fprintf(stdout, "%d\n", (int)elements.size());

  for(unsigned int i = 0; i < elements.size(); i++){
    elements[i]->setNum(i+1);
    elements[i]->print(version);
  }

  if(version == 2.0)
    fprintf(stdout, "$EndElements\n");
  else
    fprintf(stdout, "$ENDELM\n");
}

int main(int argc, char **argv)
{
  if(argc != 2){
    fprintf(stderr, "mshsort, a utility to reorder the node and element lists in Gmsh MSH files\n");
    fprintf(stderr, "Usage: %s file.msh\n", argv[0]);
    exit(1);
  }

  map<int, node*> nodes;
  vector<element*> elements;
  double version = readMesh(argv[1], nodes, elements);
  printMesh(version, nodes, elements);
}
