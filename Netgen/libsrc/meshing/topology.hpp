#ifndef TOPOLOGY
#define TOPOLOGY

/**************************************************************************/
/* File:   topology.hh                                                    */
/* Author: Joachim Schoeberl                                              */
/* Date:   27. Apr. 01                                                    */
/**************************************************************************/

/*
    Mesh topology
    (Elements, Faces, Edges, Vertices
*/


class MeshTopology
{
  const Mesh & mesh;
  int buildedges;
  int buildfaces;

  MoveableArray<INDEX_2> edge2vert;
  MoveableArray<INDEX_4> face2vert;
  MoveableArray<int[12]> edges;
  MoveableArray<int[6]> faces;
  MoveableArray<int[4]> surfedges;
  MoveableArray<int> segedges;
  MoveableArray<int> surffaces;
  MoveableArray<INDEX_2> surf2volelement;
  MoveableArray<int> face2surfel;
  TABLE<int> *vert2element;
  TABLE<int> *vert2surfelement;
  TABLE<int> *vert2segment;
  int timestamp;
public:
  MeshTopology (const Mesh & amesh);

  void SetBuildEdges (int be)
  { buildedges = be; }
  void SetBuildFaces (int bf)
  { buildfaces = bf; }

  int HasEdges () const
  { return buildedges; }
  int HasFaces () const
  { return buildedges; }

  void Update();


  int GetNEdges () const
  { return edge2vert.Size(); }
  int GetNFaces () const
  { return face2vert.Size(); }

  static int GetNVertices (ELEMENT_TYPE et);
  static int GetNEdges (ELEMENT_TYPE et);
  static int GetNFaces (ELEMENT_TYPE et);

  static const Point3d * GetVertices (ELEMENT_TYPE et);
  static const ELEMENT_EDGE * GetEdges (ELEMENT_TYPE et);
  static const ELEMENT_FACE * GetFaces (ELEMENT_TYPE et);


  
  int GetSegmentEdge (int segnr) const { return abs(segedges[segnr-1]); }
  int GetSegmentEdgeOrientation (int segnr) const { return sgn(segedges[segnr-1]); }

  void GetSegmentEdge (int segnr, int & enr, int & orient) const
  {
    enr = abs(segedges.Get(segnr));
    orient = segedges.Get(segnr) > 0 ? 1 : -1;
  }

  void GetElementEdges (int elnr, ARRAY<int> & edges) const;
  void GetElementFaces (int elnr, ARRAY<int> & faces) const;
  void GetElementEdgeOrientations (int elnr, ARRAY<int> & eorient) const;
  void GetElementFaceOrientations (int elnr, ARRAY<int> & forient) const;

  int GetElementEdges (int elnr, int * edges, int * orient) const;
  int GetElementFaces (int elnr, int * faces, int * orient) const;

  void GetFaceVertices (int fnr, ARRAY<int> & vertices) const;
  void GetFaceVertices (int fnr, int * vertices) const;
  void GetEdgeVertices (int fnr, int & v1, int & v2) const;
  void GetFaceEdges (int fnr, ARRAY<int> & edges) const;

  ELEMENT_TYPE GetFaceType (int fnr) const;

  void GetSurfaceElementEdges (int elnr, ARRAY<int> & edges) const;
  int GetSurfaceElementFace (int elnr) const;
  void GetSurfaceElementEdgeOrientations (int elnr, ARRAY<int> & eorient) const;
  int GetSurfaceElementFaceOrientation (int elnr) const;

  int GetSurfaceElementEdges (int elnr, int * edges, int * orient) const;

  void GetSurface2VolumeElement (int selnr, int & elnr1, int & elnr2) const
  { 
    elnr1 = surf2volelement.Get(selnr)[0];
    elnr2 = surf2volelement.Get(selnr)[1];
  }

  int GetFace2SurfaceElement (int fnr) const { return face2surfel[fnr-1]; }
  
  void GetVertexElements (int vnr, ARRAY<int> & elements) const;
  FlatArray<int> GetVertexElements (int vnr) const;
};

#endif
