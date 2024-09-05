#include <vector>
using namespace std;

// taken from https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
// was wrong ... did some changes 

namespace geeksforgeeks {

  // A class that represents an undirected graph
  class Graph
  {
    std::vector<std::vector<int> > adj;    // A dynamic array of adjacency lists
  public:
    // Constructor and destructor
    Graph(int V)   { adj.resize( V ) ; }
    
    // function to add an edge to graph
    void addEdge(int v, int w);
    
    // Prints greedy coloring of the vertices
    void greedyColoring(std::vector<int> &result);
  };
 
  void Graph::addEdge(int v, int w)
  {
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
  }
  
  // Assigns colors (starting from 0) to all vertices and prints
  // the assignment of colors
  void Graph::greedyColoring(std::vector<int> &result)
  {
    int V = adj.size();
    // Assign the first color to first vertex
    result[0]  = 0;
    
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
      result[u] = -1;  // no color is assigned to u
    

    int nbColors = 1;

    int iter = 0;
    while(1){    
      // Assign colors to remaining V-1 vertices
      for (int u = 1; u < V; u++)
	{
	  std::set<int> colors;
	  
	  /* printf("Triangle %d ",u); */
	  /* std::vector<int>::iterator i; */
	  /* for (i = adj[u].begin(); i != adj[u].end(); ++i){ */
	  /*   printf(" (%d,%d) ",*i,result[*i]); */
	  /* } */
	  
	  
	  //	std::vector<int>::iterator i;
	  for (size_t i = 0 ; i< adj[u].size(); i ++){
	    int adji = adj[u][i];
	    if (result[adji] != -1){
	      colors.insert(result[adji]);
	      for (size_t j = 0 ; j< adj[adji].size(); j ++){
		int adjj = adj[adji][j];
		if (result[adjj] != -1)
		  colors.insert(result[adjj]);
	      }
	    }
	  }
	  
	  int cr;
	  if (colors.size() == nbColors){
	    cr = ++nbColors;
	  }
	  else {
	    for (size_t i=0;i<nbColors;i++){
	      if (colors.find(i) == colors.end()){
		cr = i;
		break;
	      }	      
	    }
	  }	
	  //	printf("color %d\n",cr);
	  result[u] = cr; // Assign the found color	
	}
      if (iter++>10)break;
    }
    /*      // print the result
     for (int u = 0; u < V; u++){ 
       printf("Triangle %d color %d ",u,result[u]); 
       std::vector<int>::iterator i; 
       for (i = adj[u].begin(); i != adj[u].end(); ++i){ 
     	printf(" (%d,%d) ",*i,result[*i]); 
       } 
      printf("\n"); 
     }
    */ 
  }
}
