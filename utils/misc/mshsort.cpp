// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
  void print(FILE *fp, double version){
    fprintf(fp, "%d %.16g %.16g %.16g\n", _num, _x, _y, _z);
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
  void print(FILE *fp, double version){
    if(version == 2.0)
      fprintf(fp, "%d %d 3 %d %d %d", _num, _type, _physical, 
	      _elementary, _partition);
    else
      fprintf(fp, "%d %d %d %d %d", _num, _type, _physical,
	      _elementary, (int)_nodes.size());
    for(unsigned int i = 0; i < _nodes.size(); i++)
      fprintf(fp, " %d", _nodes[i]->getNum());
    fprintf(fp, "\n");
  }
};

double readMesh(FILE *fp, map<int, node*> &nodes, vector<element*> &elements)
{
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
	int num, type, physical, elementary, partition = 1, numNodes, numTags;
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
	element *e = new element(type, physical, elementary, partition);
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

void printMesh(FILE *fp, double version, map<int, node*> nodes, vector<element*> elements,
	       int nodeStartIndex=1, int elementStartIndex=1)
{
  map<int, node*>::const_iterator it = nodes.begin();
  map<int, node*>::const_iterator ite = nodes.end();

  if(version == 2.0){
    fprintf(fp, "$MeshFormat\n");
    fprintf(fp, "2.0 0 %d\n", (int)sizeof(double));
    fprintf(fp, "$EndMeshFormat\n");
    fprintf(fp, "$Nodes\n");
  }
  else
    fprintf(fp, "$NOD\n");
  fprintf(fp, "%d\n", (int)nodes.size());

  for(;it!=ite;++it){
    it->second->setNum(nodeStartIndex++);
    it->second->print(fp, version);
  }

  if(version == 2.0){
    fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
  }
  else{
    fprintf(fp, "$ENDNOD\n");
    fprintf(fp, "$ELM\n");
  }
  fprintf(fp, "%d\n", (int)elements.size());

  for(unsigned int i = 0; i < elements.size(); i++){
    elements[i]->setNum(elementStartIndex++);
    elements[i]->print(fp, version);
  }

  if(version == 2.0)
    fprintf(fp, "$EndElements\n");
  else
    fprintf(fp, "$ENDELM\n");
}

int main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(stderr, "mshsort, a utility to reorder the node and element lists in Gmsh MSH files\n");
    fprintf(stderr, "Usage: %s in.msh [out.msh] [node_start_index] [element_start_index]\n",
	    argv[0]);
    exit(1);
  }

  FILE *in, *out;
  if(!(in = fopen(argv[1], "r"))){
    fprintf(stderr, "Error: Unable to open input file '%s'\n", argv[1]);
    exit(1);
  }
  if(argc >= 3){
    if(!(out = fopen(argv[2], "w"))){
      fprintf(stderr, "Error: Unable to open output file '%s'\n", argv[2]);
      exit(1);
    }
  }
  else{
    out = stdout;
  }
  
  int nodeStartIndex = (argc >= 4) ? atoi(argv[3]) : 1;
  int elementStartIndex = (argc >= 5) ? atoi(argv[4]) : 1;    

  map<int, node*> nodes;
  vector<element*> elements;
  double version = readMesh(in, nodes, elements);
  printMesh(out, version, nodes, elements, nodeStartIndex, elementStartIndex);
}
