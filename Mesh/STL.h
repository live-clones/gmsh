#ifndef _STL_H_
#define _STL_H_

class STL_Data
{
 public:
  Tree_T * Vertices;
  Tree_T *Simplexes;
  List_T *LVertices;
  List_T *LSimplexes;
  void Add_Facet (double x1, double y1, double z1,
                  double x2, double y2, double z2,
                  double x3, double y3, double z3);
  int GetNbFacets (){
    return Tree_Nbr (Simplexes);
  }
  int GetNbVertices (){
    return Tree_Nbr (Vertices);
  }
  void GetFacet (int iFac, int &v1, int &v2, int &v3);
  void GetVertex (int iVertex, double &x, double &y, double &z);
  STL_Data ();
  ~STL_Data ();
};

#endif
