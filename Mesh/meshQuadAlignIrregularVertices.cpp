// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Standard Library
#include <ctime>
#include <queue>
using namespace std;

// Gecode
#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/minimodel.hh>
#include <gecode/gist.hh>
#include <gecode/driver.hh>
using namespace Gecode;

// Gmsh
#include "gmsh.h"
#include "GModel.h"
#include "geolog.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "PView.h"
#include "Field.h"
#include "PViewDataList.h"
#include "meshWinslow2d.h" // for smoothing
#include "meshGFaceOptimize.h"
#include "pointsGenerators.h"

// QuadMeshingTools
#include "lp_solve_wrapper.h"
#include "qmtMeshUtils.h"

// Some shortcuts
#define P(x) {cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define FIT(it,v) for (auto it = (v).begin(); it != (v).end(); it++)
#define DR(i,a,b) for (int i=(b); i-->(a);)
#define D(i,n) DR(i,0,n)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)
#define MA(a,v) a = max(a,v)
#define V vector
#define pb push_back
#define mt make_tuple

/*************/
/* Constants */
/*************/

const bool ERROR_VISU = true; // failed probes in compute_subdivided_edge_internal_points
constexpr double VIEW_INT_SCALING = 1.e-8; // Scaling applied on integer values storen in view (background field),
	// so the visualization is not broken by the integers

/*****************************/
/* General-purpose functions */
/*****************************/

// Modulo that works for negative numbers (since (-a)%m == -(a%m))
int mod(int a, int m) { return (a % m + m) % m; }

// For union-find
int find(int a, V<int>& p) { return p[a] == a ? a : (p[a] = find(p[a], p)); }

/*******************/
/* Print functions */
/*******************/

// Print vector
template<class T> ostream &operator<<(ostream &os, V<T> v) {
	F(i,S(v)) os<<(i?" ":"")<<v[i];
	return os; }
// Print set
template<class T> ostream &operator<<(ostream &os, set<T> s) {
	FIT(it, s) os << (it==s.begin()?"":" ") << *it;
	return os; }
// Print pair
template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1,T2> p) {
	os << '(' << p.first << ", " << p.second << ')';
	return os; }
// Print SPoint2
ostream &operator<<(ostream &os, SPoint2 p) {
	os << '(' << p.x() << ", " << p.y() << ')';
	return os; }
// Print SPoint3
ostream &operator<<(ostream &os, SPoint3 p) {
	os << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
	return os; }
// Print GPoint
ostream &operator<<(ostream &os, GPoint p) {
	os << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
	return os; }

/********************/
/* GeoLog functions */
/********************/

// MQuadrangle
void geolog(MQuadrangle* quad, double color, string name) {
	GeoLog::add({
		quad->getVertex(0)->point(),
		quad->getVertex(1)->point(),
		quad->getVertex(2)->point(),
		quad->getVertex(3)->point()
	}, color, name);
}

// MLine
void geolog(MLine* mline, double color, string name) {
	GeoLog::add({mline->getVertex(0)->point(), mline->getVertex(1)->point()}, color, name);
}

// GEdge
void geolog(GEdge* gedge, double color, string name) {
	F(i, gedge->getNumMeshElements())
		geolog((MLine*)gedge->getMeshElement(i), color, name);
}

// Initialize and run gmsh
void draw() {
	gmsh::initialize();
	GeoLog::flush();
	gmsh::fltk::run();
}

/*******************/
/* Data structures */
/*******************/

struct MeshHalfEdges;
struct Vertex;
struct HalfEdge;
struct Face;

struct TMesh;
struct TVertex;
struct TEdge;
struct TFace;

struct Trace;
struct TraceHalfEdges;
struct TraceIntersection;
struct TraceHalfEdgesIntersection;

struct Cluster;

bool myGetSingularitiesFromBackgroundField(GFace* gf, vector<pair<SPoint3, int> >& singularities);

// Vertex data structure.
// Basically an MVertex with connectivity attributes.
struct Vertex {
	MVertex* ptr; // pointer to corresponding MVertex
	V<HalfEdge*> hedges; // half-edges emanating from the vertex (no particular order)
	int valence; // number of incident faces (including "void")
	bool isOnBoundary, isSingularity, isGVertex, isOnCAD;
	void geolog(double value, const string& viewName) { GeoLog::add((SVector3)ptr->point(), value, viewName); }
	double dist(const Vertex* v) { return ptr->distance(v->ptr); } // distance to another Vertex
};

// Half-edge data structure.
// Basically an oriented MLine with additional attributes.
struct HalfEdge {
	HalfEdge *prev, *next, *oppo;
	Vertex *v1, *v2; // v1 = tail, v2 = head
	Face* face; // face to the left of half-edge
	GEdge* gedge; // GEdge on with the half-edge lies (NULL if none)
	void geolog(double value, const string& viewName) {
		GeoLog::add({v1->ptr->point(), v2->ptr->point()}, value, viewName); 
	}
};

// Face data structure.
// Basically an MQuadrangle with additonal attributes.
struct Face {
	MElement* ptr; // pointer to corresponding MElement (which is an MQuadrangle)
	HalfEdge* he; // reference to one half-edge of the face
	void geolog(double value, const string& viewName) {
		array<SVector3, 4> pts;
		HalfEdge* hek = he;
		F(k,4) {
			pts[k] = hek->v1->ptr->point();
			hek = hek->next;
		}
		GeoLog::add({pts[0], pts[1], pts[2], pts[3]}, value, viewName);
	}
};

// Data structure for a mesh represented by half-edges
struct MeshHalfEdges {
	V<Vertex*> vertices; // set of all Vertices
	V<HalfEdge*> hedges; // set of all Half-Edges
	V<Face*> faces; // set of all Faces

	// Destructor
	~MeshHalfEdges() {
		for(Vertex* v : vertices) delete v;
		for(HalfEdge* he : hedges) delete he;
		for(Face* f : faces) delete f;
	}

	void geolog(const string& viewName) {
		// Draw vertices and singular vertices
		for(Vertex* vertex : vertices) {
			vertex->geolog(0, viewName + " (vertices)");
			if(vertex->isSingularity)
				vertex->geolog(0, viewName + " (singularities)");
		}
		for(HalfEdge* he : hedges) he->geolog(0, viewName + " (edges)"); // draw half-edges
		for(Face* face : faces) face->geolog(rand(), viewName + " (faces)"); // draw faces
		// Draw base complex
		set<HalfEdge*> base_complex;
		int si = 0;
		for(Vertex* vertex : vertices) {
			if(vertex->valence != 4) {
				vertex->geolog(0, "irregular vertices");
				for(HalfEdge* hes : vertex->hedges) {
					HalfEdge* he = hes;
					while(he->v2->valence == 4) {
						he->geolog(si, "base complex");
						base_complex.insert(he);
						//he->geolog(si, "S"+to_string(si));
						he = he->next->oppo->next;
					}
					//he->geolog(si, "S"+to_string(si));
					he->geolog(si, "base complex");
					base_complex.insert(he);
					++si;
				}
			}
		}

		set<Face*> processedFaces;
		int cnt = 0;
		for(Face* face : faces) {
			if(!processedFaces.count(face)) {
				processedFaces.insert(face);
				++cnt;
				int color = rand();
				queue<Face*> q; q.push(face);
				while(S(q)) {
					Face* f = q.front(); q.pop();
					f->geolog(color, "base complex");
					HalfEdge* he = f->he;
					F(s,4) {
						if(!base_complex.count(he) && !he->gedge && !processedFaces.count(he->oppo->face)) {
							processedFaces.insert(he->oppo->face);
							q.push(he->oppo->face);
						}
						he = he->next;
					}
				}
			}
		}
		Msg::Info("Input mesh has %d patches.", cnt);

	}

};

int buildMeshHalfEdgesFromGModel(GModel* gm, MeshHalfEdges& M) {
	map<MVertex*, Vertex*> mv2new; // map mesh vertices to new vertices
	map<pair<Vertex*,Vertex*>, HalfEdge*> vPair2he; // map pair of vertices to half-edge
	for(GFace* gf : gm->getFaces()) for(MQuadrangle* q : gf->quadrangles) {
		M.faces.pb(new Face); M.faces.back()->ptr = q;
		int nh = S(M.hedges); // number of half-edges
		F(k, 4) M.hedges.pb(new HalfEdge);
		F(k, 4) {
			MVertex* mv = q->getVertex(k);
			Vertex* vertex;
			if(!mv2new.count(mv)) { // new vertex
				vertex = new Vertex; M.vertices.pb(vertex);
				vertex->ptr = mv, vertex->valence = 0, vertex->isOnBoundary = false, vertex->isSingularity = false;
				vertex->isGVertex = (dynamic_cast<GVertex*>(mv->onWhat()) != NULL);
				vertex->isOnCAD = (vertex->isGVertex || dynamic_cast<GEdge*>(mv->onWhat()) != NULL);
				mv2new[mv] = vertex;
			} else
				vertex = mv2new[mv];

			vertex->valence++;
			vertex->hedges.pb(M.hedges[nh+k]);
			M.hedges[nh+k]->face = M.faces.back();
			M.hedges[nh+k]->next = M.hedges[nh+mod(k+1,4)];
			M.hedges[nh+k]->prev = M.hedges[nh+mod(k-1,4)];
			M.hedges[nh+k]->gedge = NULL;
			M.hedges[nh+k]->oppo = NULL;
			M.hedges[nh+k]->v1 = vertex; // current vertex is tail of current he
			M.hedges[nh+mod(k-1,4)]->v2 = vertex; // current vertex is head of prev he
		}
		// Match opposite half-edges
		F(k, 4) {
			HalfEdge* he = M.hedges[nh+k];
			pair<Vertex*,Vertex*> v1v2 = {he->v1, he->v2}, v2v1 = {he->v2, he->v1};
			vPair2he[v1v2] = he;
			if(vPair2he.find(v2v1) != vPair2he.end()) { // if the opposite half-edge has been formed already
				he->oppo = vPair2he[v2v1];
				vPair2he[v2v1]->oppo = he;
			}
		}
		M.faces.back()->he = M.hedges[nh]; // any of the 4 half-edges will do
	}

	// Determine boundary and increase valence
	for(HalfEdge* he : M.hedges) if(he->oppo == NULL) {
		he->v1->isOnBoundary = he->v2->isOnBoundary = true;
		he->v1->valence++, he->v2->valence++;
	}

	// Assign GEdge's to HalfEdge's
	for(GEdge* gedge : gm->getEdges()) {
		F(i, gedge->getNumMeshElements()) {
			MElement* mline = gedge->getMeshElement(i);
			Vertex *v0 = mv2new[mline->getVertex(0)], *v1 = mv2new[mline->getVertex(1)];
			HalfEdge* he = vPair2he[{v0, v1}];
			if(he == NULL) { // free boundary
				he = vPair2he[{v1, v0}];
				he->gedge = gedge;
			} else {
				he->gedge = gedge;
				he->oppo->gedge = gedge;
			}
		}
	}

	// Identify singularities in background field and match them to corresponding irreg vertex
	for(GFace* gf : gm->getFaces()) {
		V<pair<SPoint3, int>> singularities;
		myGetSingularitiesFromBackgroundField(gf, singularities);
		for(auto p : singularities) {
			SPoint3 sing = p.first;
			int val = 4 - p.second;
			Vertex* closestVertex = NULL;
			double minDist = DBL_MAX;
			for(Vertex* v : M.vertices) {
				if(!v->isSingularity && v->valence == val && dynamic_cast<GFace*>(v->ptr->onWhat()) == gf) {
					double dist = v->ptr->point().distance(sing);
					if(closestVertex == NULL || dist < minDist) {
						closestVertex = v;
						minDist = dist;
					}
				}
			}
      if (closestVertex) {
        closestVertex->isSingularity = true;
        closestVertex->geolog(0, "singularities");
      }
		}
	}
	return 0;
}

// Data structure for vertex of T-mesh
struct TVertex {
	Vertex* vertex;
	V<pair<TVertex*, TEdge*>> adj; // adjacency list
	bool isSingular, isGVertex;
	void geolog(double value, const string& viewName) { vertex->geolog(value, viewName); }
};

// Date structure for (quad) face of T-mesh
struct TFace {
	array<V<TEdge*>,4> sides; // sides of the T-face, composed of T-edges
	V<Face*> faces; // list of quads composing the T-face
	void geolog(double value, const string& viewName) {
		for(Face* face : faces) face->geolog(value, viewName);
	}
	GFace* gface;
	array<int, 2> dim; // T-face dimensions
};

// Data structure for half-edge of T-mesh
struct TEdge {
	TFace* tface; // T-face on left of he
	int side; // side of T-face
	TVertex *tvertex1, *tvertex2; // T-vertices at the endpoints
	TEdge* oppo; // opposite T-edge
	int len; // integer length
	HalfEdge* he; // first half-edge
	GEdge* gedge; // corresponding GEdge
	int id; // gecode identifier
	bool isStitch;
	bool isOn35path = false;
	void geolog(double value, const string& viewName) {
		HalfEdge* hei = he;
		F(i, len) {
			hei->geolog(value, viewName);
			if(i != len-1) hei = hei->next->oppo->next;
		}
	}
};

// Trace described in MeshHalfEdges
struct TraceHalfEdges {
	Vertex* orig; // origin of trace (singular vertex)
	V<HalfEdge*> hedges; // sequence of half-edges forming the trace
	double alpha; // prescribed max deviation for this trace
	bool onLeft, onRight; // have we encountered a trace on left/right with angle < alpha ?
	void geolog(double value, string name) {
		orig->geolog(value, name);
		for(HalfEdge* he : hedges) he->geolog(value, name);
	}
};

// Trace described in T-mesh
struct Trace {
	TVertex* orig; // origin of trace (singular vertex)
	TVertex* dest; // origin of trace that intersects (NULL if CAD)
	V<TEdge*> tedges; // sequence of T-edges forming the trace
	map<TEdge*, int> tedge2index; // index along Trace of given T-edge
	V<int> len; // len[i] = tedges[0]->len + ... + tedges[i]->len (S(len) == S(tedges))
	V<TraceIntersection*> intersections; // intersecting traces (S(intersections) == S(tedges)-1)
	int istar; // index of star; star is the first intersection with a trace that starts inside the pi/2 sector
	double alpha; // prescribed max deviation for this trace
	void geolog(double value, string name) { 
		orig->geolog(value, name);
		for(TEdge* tedge : tedges) tedge->geolog(value, name); 
	}
};

// Intersection of TraceHalfEdges
struct TraceHalfEdgesIntersection {
	TraceHalfEdges* t; // intersecting trace
	int li, lj;  // lengths of current and intersecting traces, resp.
};

// Intersection of Traces
struct TraceIntersection {
	Trace* t; // intersecting trace
	int i, j; // index along current and intersecting trace, resp.
};

struct TMesh {
	V<TFace*> tfaces;
	V<TEdge*> tedges;
	V<TVertex*> tvertices;
	V<Trace*> traces;
	V<TEdge*> id2te; /* id to one of the two opposite TEdge* */
	map<HalfEdge*, TEdge*> hedgemap; // map half-edges to T-half-edges they lie on
	map<GEdge*, V<TEdge*>> gedge2tedges; // sequence of T-edges forming a given GEdge (arbitrary orientation)
	int nTEdges; // number of undirected T-edges

	// Destructor
	~TMesh() {
		for(TFace* tf : tfaces) delete tf;
		for(TEdge* the : tedges) delete the;
	}

	// Tmesh default contructor
	TMesh() {}

	// Tmesh constructor from MeshHalfEdges
	// alpha_user is the max deviation of a singularity, in rad: 0 <= alpha <= pi/4
	TMesh(MeshHalfEdges &M, double alpha_user) {
		// TODO: what if a GVertex is incident to only 2 GEdges? Normally there will be a warning :-)

		// // TODO: identify "true" singularities, i.e. singularities not part of a 3-5 pair
		// int maxdist = 2; // if 2 singularities has distance <= maxdist, they are not true singularities
		// for(Vertex* vertex : M.vertices) {
		// 	if(vertex->valence == 4) {
		// 		vertex->isTrulySingular = false;
		// 		continue;
		// 	}
		// 	queue<pair<Vertex*, int>> q; q.push({vertex, 0});
		// 	set<Vertex*> vis; vis.insert(vertex);
		// 	vertex->isTrulySingular = true;
		// 	while(vertex->isTrulySingular && S(q)) {
		// 		Vertex* u = q.front().first;
		// 		int d = q.front().second;
		// 		q.pop();
		// 		if(d == maxdist) continue;
		// 		HalfEdge* he = u->he;
		// 		F(i, u->valence) {
		// 			he = he->oppo->next;
		// 			Vertex* v = he->v2;
		// 			if(!vis.count(v)) {
		// 				if(v->valence != 4) vertex->isTrulySingular = false;
		// 				vis.insert(v);
		// 				q.push({v, d+1});
		// 			}
		// 		}
		// 	}
		// }

		// // Draw trace origins
		// for(Vertex* v : M.vertices) {
		// 	if(v->valence != 4 || v->isGVertex) 
		// 		v->geolog(0, "trace origins");
		// }

		// draw();

		// Initialize traces
		// alpha = 0 when the origin of the trace is a GVertex!
		V<TraceHalfEdges*> hetraces; // traces, described using half-edges
		set<HalfEdge*> onTMesh; // set of half-edges lying on the T-mesh
		map<HalfEdge*, TraceHalfEdges*> hedge2trace; // map half-edge to trace it lies on
		map<HalfEdge*, int> hedge2index; // index of half-edge along trace (0,1,..)
		for(Vertex* vertex : M.vertices) {
			// If vertex is irregular, or a GVertex
			if(vertex->isGVertex || vertex->valence != 4) {
				for(HalfEdge* he : vertex->hedges) {
					// if(vertex->valence != 4 || he->gedge != NULL) { // if isGVertex, half-edge should lie on a GEdge
						// New trace!
						TraceHalfEdges* trace = new TraceHalfEdges;
						trace->orig = vertex;
						// trace->alpha = alpha_user;
						trace->alpha = (vertex->isGVertex && he->gedge != NULL) ? 0 : alpha_user;
						trace->hedges.pb(he);
						// trace->l = 1;
						trace->onLeft = trace->onRight = false;
						// trace->listar = -1;
						hetraces.pb(trace);
						hedge2trace[he] = trace;
						hedge2index[he] = 0;
						// Insert half-edge (and its opposite) in T-mesh
						onTMesh.insert(he);
						if(he->oppo != NULL) onTMesh.insert(he->oppo);
					// }
				}
			}
		}
		// H(S(hetraces));
		
		// // Draw onTMesh
		// for(HalfEdge* he : onTMesh) he->geolog(0, "onTMesh");

		// Propagate traces from singularities and GVertices
		set<TraceHalfEdges*> openTraces(ALL(hetraces)); // traces that still need to be propagated
		while(S(openTraces)) {
			for(TraceHalfEdges* trace : hetraces) {
				if(openTraces.count(trace)) { // if trace is not completed
					HalfEdge* he = trace->hedges.back(); // last half-edge of trace
					if(he->v2->valence != 4 || he->v2->isGVertex || he->next->oppo == NULL) { // irregular, geometric or hittinh the boundary: we're done here
						openTraces.erase(trace);
					} else {
						HalfEdge *hedgeLeft = he->next, *hedgeRight = NULL;
						if(he->oppo != NULL) hedgeRight = he->oppo->prev->oppo;
						if(!trace->onRight && hedge2trace.count(hedgeLeft)) { // trace on the right
							TraceHalfEdges* t = hedge2trace[hedgeLeft];
							if(t->orig->valence != 4 && t->orig != trace->orig && hedge2index[hedgeLeft] <= tan(trace->alpha) * (hedge2index[he] + 1))
								trace->onRight = true;
						}
						if(hedgeRight != NULL && !trace->onLeft && hedge2trace.count(hedgeRight)) { // trace on the left
							TraceHalfEdges* t = hedge2trace[hedgeRight];
							if(t->orig->valence != 4 && t->orig != trace->orig && hedge2index[hedgeRight] <= tan(trace->alpha) * (hedge2index[he] + 1))
								trace->onLeft = true;
						}
						if(trace->onLeft && trace->onRight) {
							openTraces.erase(trace);
						} else {
							// propagate :-)
							HalfEdge* next = he->next->oppo->next;
							trace->hedges.pb(next);
							hedge2trace[next] = trace;
							hedge2index[next] = hedge2index[he] + 1;
							onTMesh.insert(next);
							if(he->oppo != NULL) onTMesh.insert(next->oppo);
						}
					}
				}
			}
		}

		// // Propagate streamlines from remaining irregular vertices (3-5's)
		// for(Vertex* vertex : M.vertices) {
		// 	if(!vertex->isGVertex && !vertex->isSingularity && vertex->valence != 4) {
		// 		for(HalfEdge* heStart : vertex->hedges) {
		// 			HalfEdge* he = heStart;
		// 			while(true) {
		// 				onTMesh.insert(he);
		// 				onTMesh.insert(he->oppo);
		// 				HalfEdge *hedgeLeft = he->next, *hedgeRight = he->oppo->prev->oppo;
		// 				if(he->v2->valence != 4 || he->v2->isGVertex || onTMesh.count(hedgeLeft) || onTMesh.count(hedgeRight))
		// 					break;
		// 				he = he->next->oppo->next;
		// 			}
		// 		}
		// 	}
		// }

		// Draw traces
		for(TraceHalfEdges* trace : hetraces) trace->geolog(rand(), "hetraces");

		// // Draw onTMesh
		// for(HalfEdge* he : onTMesh) he->geolog(0, "onTMesh");

		// Assign faces to T-faces
		#pragma region
		map<Face*, TFace*> face2tface;
		for(Face* face : M.faces) {
			if(!face2tface.count(face)) { // if face has no parent yet
				TFace* tface = new TFace; tfaces.pb(tface);
				tface->gface = NULL;
				GFace* gf;
				queue<Face*> q; // queue of faces
				q.push(face); face2tface[face] = tface;
				while(S(q)) {
					Face* f = q.front(); q.pop();
					tface->faces.pb(f);
					HalfEdge* he = f->he;
					F(k, 4) {
						if(tface->gface == NULL && (gf = dynamic_cast<GFace*>(he->v1->ptr->onWhat())) != NULL)
							tface->gface = gf;
						if(!onTMesh.count(he) && he->oppo != NULL) {
							Face* af = he->oppo->face; // adjacent face
							if(!face2tface.count(af)) {
								face2tface[af] = tface;
								q.push(af);
							}
						}
						he = he->next;
					}
				}
			}
		}
		#pragma endregion

		set<TFace*> isTFaceProcessed;
		set<HalfEdge*> hedgesOnStitch;
		// // Check for periodic T-faces and split them
		// #pragma region
		// for(HalfEdge* hes : M.hedges) if(onTMesh.count(hes)) {
		// 	TFace* tface = face2tface[hes->face]; // current T-face
		// 	if(isTFaceProcessed.count(tface)) continue;
		// 	isTFaceProcessed.insert(tface);
		// 	HalfEdge* he = hes;
		// 	while(face2tface[he->face] == tface) {
		// 		he = he->next->oppo->next;
		// 		if(he == hes) {
		// 			P("periodic T-face!");
		// 			he = he->next;
		// 			while(face2tface[he->face] == tface) {
		// 				onTMesh.insert(he);
		// 				onTMesh.insert(he->oppo);
		// 				hedgesOnStitch.insert(he);
		// 				hedgesOnStitch.insert(he->oppo);
		// 				he = he->next->oppo->next;
		// 			}
		// 			break;
		// 		}
		// 	}
		// }
		// #pragma endregion

		// P("done splitting periodic T-faces");
		// draw();

		// Build T-edges
		map<Vertex*, TVertex*> vertexmap; // map vertices to corresponding T-vertices
		isTFaceProcessed.clear();
		nTEdges = 0;
		for(HalfEdge* hes : M.hedges) {
			if(!onTMesh.count(hes)) continue;
			TFace* tface = face2tface[hes->face]; // current T-face
			if(isTFaceProcessed.count(tface)) continue;
			isTFaceProcessed.insert(tface);
			HalfEdge* he = hes;
			while(!onTMesh.count(he->next)) { // while we're still on the T-face
				he = he->next->oppo->next;
			}
			// Now he points at some corner of tface
			F(s, 4) { // for each side of the patch
				he = he->next;
				// Now he has origin at some corner of tface
				while(true) {
					TEdge* tedge = new TEdge;
					tedges.pb(tedge); tface->sides[s].pb(tedge);
					tedge->he = he, tedge->len = 0, tedge->gedge = he->gedge,
						tedge->tface = tface, //tedge->id = S(tedges)-1,
						tedge->isStitch = hedgesOnStitch.count(he);
					if(he->oppo != NULL && hedgemap.count(he->oppo)) { // If opposite T-edge already exists
						tedge->oppo = hedgemap[he->oppo];
						hedgemap[he->oppo]->oppo = tedge;
						tedge->id = tedge->oppo->id;
					} else
						tedge->id = nTEdges++; // new unique T-edge
					if(tedge->gedge != NULL) gedge2tedges[tedge->gedge].pb(tedge);
					if(!vertexmap.count(he->v1)) {
						TVertex* tvertex = new TVertex; tvertices.pb(tvertex);
						tvertex->vertex = he->v1;
						vertexmap[he->v1] = tvertex;
						tvertex->isSingular = (tvertex->vertex->valence != 4);
						tvertex->isGVertex = tvertex->vertex->isGVertex;
					}
					TVertex* tvertex1 = vertexmap[he->v1];
					while(true) {
						tedge->len++;
						hedgemap[he] = tedge;
						if(he->gedge != tedge->gedge)
							P("WARNING: T-edge overlaps multiple GEdges!");
						if(he->v2->isGVertex || onTMesh.count(he->next) || (he->oppo != NULL && onTMesh.count(he->oppo->prev)))
							break;
						he = he->next->oppo->next;
					}
					if(!vertexmap.count(he->v2)) { // not very elegant :-(
						TVertex* tvertex = new TVertex; tvertices.pb(tvertex);
						tvertex->vertex = he->v2;
						vertexmap[he->v2] = tvertex;
						tvertex->isSingular = (tvertex->vertex->valence != 4);
						tvertex->isGVertex = tvertex->vertex->isGVertex;
					}
					// Add T-edge to T-vertex adjacencies
					TVertex* tvertex2 = vertexmap[he->v2];
					tvertex1->adj.pb({tvertex2, tedge});
					tvertex2->adj.pb({tvertex1, tedge});
					tedge->tvertex1 = tvertex1;
					tedge->tvertex2 = tvertex2;
					if(onTMesh.count(he->next)) {
						break;
					} else {
						he = he->next->oppo->next;
					}
				}
			}
		}
		// // Build adjacencies
		// for(TEdge* tedge : tedges) {
		// 	tedge->tvertex1->adj.pb({tedge->tvertex2, tedge});
		// 	if(tedge->oppo == NULL) tedge->tvertex2->adj.pb({tedge->tvertex1, tedge}); // boundary is a special case	
		// }
		// draw();

		// Build traces
		map<TraceHalfEdges*, Trace*> hetrace2trace;
		for(TraceHalfEdges* hetrace : hetraces) {
			Trace* trace = new Trace;
			trace->alpha = hetrace->alpha;
			hetrace2trace[hetrace] = trace;
			// H(vertexmap.count(hetrace->orig));
			if(!vertexmap.count(hetrace->orig)) {
				hetrace->orig->geolog(0, "not in vertexmap");
			}
			trace->orig = vertexmap[hetrace->orig];
			for(HalfEdge* he : hetrace->hedges) {
				TEdge* tedge = hedgemap[he];
				if(trace->tedges.empty() || tedge != trace->tedges.back()) {
					trace->tedge2index[tedge] = S(trace->tedges);
					trace->tedges.pb(tedge);
					if(trace->len.empty()) trace->len.pb(tedge->len);
					else trace->len.pb(tedge->len + trace->len.back());
				}
			}
			trace->dest = trace->tedges.back()->tvertex2;
			trace->dest->geolog(rand(), "dest");
			traces.pb(trace);
		}

		// Build intersections and istar
		F(itrace, S(traces)) {
			// P("treating trace " + to_string(itrace));
			Trace* trace = traces[itrace];
			// if(trace->orig->isGVertex) trace->orig->geolog(0, "trace->orig->isGVertex");
			// trace->geolog(0, "intersections of trace " + to_string(itrace));
			// H(S(trace->tedges));
		// for(Trace* trace : traces) {
			trace->istar = -1; // not found yet
			F(i, S(trace->tedges)) {
				TEdge* tedge = trace->tedges[i];
				if(tedge->tvertex2->vertex->valence != 4 || tedge->tvertex2->isGVertex) continue;
				// Determine last half-edge
				HalfEdge* he = tedge->he;
				F(k, tedge->len-1) he = he->next->oppo->next;
				HalfEdge *heLeft = he->next->oppo, *heRight;
				//  = he->oppo->prev;
				if(hedge2trace.count(heLeft)) { // there's an intersection on the left
					Trace* t = hetrace2trace[hedge2trace[heLeft]];
					// H(t);
					int j = t->tedge2index[hedgemap[heLeft]];
					if(trace->istar == -1 && t->len[j] < trace->len[i] && (trace->orig->vertex->valence + t->orig->vertex->valence != 8 || trace->orig->isGVertex || t->orig->isGVertex))  { // we have found istar :-)
						trace->istar = i; 
						// he->v2->geolog(0, "istar");
					}
					if(t->len[j] > tan(trace->alpha) * trace->len[i]) { // new intersection
						TraceIntersection* inters = new TraceIntersection;
						inters->t = t, inters->i = i, inters->j = j;
						// H(inters->i);
						// H(inters->j);
						trace->intersections.pb(inters);
						// he->v2->geolog(0, "intersections of trace " + to_string(itrace));
						// t->geolog(rand(), "intersections of trace " + to_string(itrace));
					}
				}
				if(he->oppo != NULL && hedge2trace.count(heRight = he->oppo->prev)) { // there's an intersection on the right
				// if(hedge2trace.count(heRight)) { // there's an intersection on the right
					Trace* t = hetrace2trace[hedge2trace[heRight]];
					// H(t);	
					int j = t->tedge2index[hedgemap[heRight]];
					// We don't want to prevent 3-5 pairs from collapsing
					if(trace->istar == -1 && t->len[j] < trace->len[i] && (trace->orig->vertex->valence + t->orig->vertex->valence != 8 || trace->orig->isGVertex || t->orig->isGVertex)) { // we have found istar :-)
						trace->istar = i; 
						// he->v2->geolog(0, "istar");
					}
					if(t->len[j] > tan(trace->alpha) * trace->len[i]) { // new intersection
						TraceIntersection* inters = new TraceIntersection;
						inters->t = t, inters->i = i, inters->j = j;
						// H(inters->i);
						// H(inters->j);
						trace->intersections.pb(inters);
						// he->v2->geolog(1, "intersections of trace " + to_string(itrace));
						// t->geolog(2, "intersections of trace " + to_string(itrace));
						// he->v2->geolog(0, "intersections");
					}
				}
				// cout << endl;
			}
			// If trace connects a 3-5 pair, leave istar = -1
			if(trace->istar == -1 && (trace->orig->vertex->valence + trace->dest->vertex->valence != 8 || trace->orig->isGVertex || trace->dest->isGVertex)) {
				trace->istar = S(trace->tedges)-1;
			}
		}

		// Draw traces
		for(Trace* trace : traces) {
			int color = rand();
			trace->geolog(color, "traces");
			if(trace->istar != -1) trace->tedges[trace->istar]->tvertex2->geolog(color, "istar");
		}
		

    // Maxence: add id to TEdge for Gecode
    id2te.resize(nTEdges,nullptr);
		for(TEdge* tedge : tedges) id2te[tedge->id] = tedge;

		assert(S(tedges) == 2*nTEdges);
	}
	void geolog(const string& viewName) {
		for(TVertex* tvertex : tvertices) tvertex->geolog(0, viewName + " (vertices)");
		for(TEdge* tedge : tedges) tedge->geolog(0, viewName + " (edges)");
		for(TFace* tface : tfaces) tface->geolog(rand(), viewName + " (faces)");
	}
};

// struct Cluster {
// 	V<TVertex*> tvertices;
// 	int type; // 0 = regular, 1 = singular, 2 = GVertex, 3 = CAD (non-GVertex)
// 	Vertex* center;
// 	GFace* gface;
// };

struct CVertex;
struct CEdge;
struct CFace;

struct CVertex {
	Vertex* vertex; // corresponding vertex
	V<TVertex*> tvertices; // group of T-vertices from T-mesh
	bool isSingularity;
	bool isOnCAD; // on GVertex or on GEdge
	V<pair<CVertex*, CEdge*>> adj;
	GFace* gface; // gface on which the vertex lies
	GVertex* gvertex;
	void geolog(double value, const string& name) { vertex->geolog(value, name); }
};

struct CEdge {
	CFace* cface; // C-face on the left
	int side;
	CVertex *cvertex1, *cvertex2;
	CEdge* oppo;
	GEdge* gedge;
	V<HalfEdge*> path;
	V<MLine*> mlines; // useful for geologging patch boundaries afterwards
	int q; // patch quantization
	void geolog(double value, const string& name) {
		for(HalfEdge* he : path) he->geolog(value, name);
	}
};

struct CFace {
	array<CEdge*, 4> sides;
	GFace* gface;
	V<MQuadrangle*> mquads; // useful for coloring patches afterwards
};

struct CMesh {
	V<CVertex*> cvertices;
	V<CEdge*> cedges;
	V<CFace*> cfaces;
	int ncedges; // number of unique C-edges

	// Build coarse mesh from T-mesh and quantization (by splitting)
	CMesh(TMesh& TM, V<int> q) {
		
		// Step 1: split T-edges with quantization > 1 and T-faces with area > 0
		
		TMesh TM2; // Split T-mesh
		TM2.tvertices = TM.tvertices; // copy T-vertices
		for(TVertex* tvertex : TM2.tvertices) tvertex->adj.clear(); // clear adj
		TM2.nTEdges = 0;
		map<TEdge*, V<TEdge*>> tedge2new; // OLD T-edge to NEW T-edges
		map<TEdge*, V<TVertex*>> tedge2tvertices; // OLD T-edge to NEW T-vertices
		map<TEdge*, V<int>> tedge2pos; // OLD T-edge to NEW positions of T-vertices along T-edge
		// pos denotes a position in terms of the OLD quantization
		// len denotes the NEW quantization
		int iface = 0;
		for(TFace* tface : TM.tfaces) {
			array<V<TVertex*>,4> side_tvertices; // T-vertices separating the NEW quantization
			array<V<int>, 4> side_pos; // integer position of T-vertices along side (in terms of OLD quantization)
			array<V<V<TEdge*>>, 4> side_tedges; // new T-edges grouped by old T-edges (separated by T-vertices in side_tvertices) 
			array<int, 4> side_len; // total length of each side
			F(s, 4) {
				int curr_pos = 0; // old quantization
				int curr_len = 0; // new quantization
				side_tvertices[s].pb(tface->sides[s].front()->tvertex1); // add corner
				side_pos[s].pb(0);
				side_tedges[s].pb(V<TEdge*>());
				
				side_len[s] = 0;
				for(TEdge* tedge : tface->sides[s])
					side_len[s] += q[tedge->id];

				for(TEdge* tedge : tface->sides[s]) {
					// List vertices on T-edge
					V<Vertex*> vertices;
					HalfEdge* he = tedge->he;
					F(i, tedge->len) {
						vertices.pb(he->v1);
						he = he->next->oppo->next;
					}
					vertices.pb(he->v1);

					// Create new T-vertices
					V<TVertex*> tvertices;
					V<int> pos; // position of T-vertices along T-edge
					if(tedge2tvertices.count(tedge->oppo)) {
						// If opposite T-edge has been processed already: get corresponding new T-vertieces
						tvertices = tedge2tvertices[tedge->oppo]; reverse(ALL(tvertices));
						D(i, S(tedge2pos[tedge->oppo]))
							pos.pb(tedge->len - tedge2pos[tedge->oppo][i]);
					} else {
						tvertices.pb(tedge->tvertex1);
						pos.pb(0); // pos of T-vertices alons T-edge
						FR(i, 1, q[tedge->id]) { // q-1 new T-vertices need to be created
							TVertex* tvertex = new TVertex;
							tvertex->vertex = vertices[i*tedge->len / q[tedge->id]];
							tvertex->isSingular = false;
							tvertex->isGVertex = tvertex->vertex->isGVertex; // should always be false
							tvertices.pb(tvertex);
							pos.pb(i*tedge->len / q[tedge->id]);
							TM2.tvertices.pb(tvertex);
						}
						tvertices.pb(tedge->tvertex2);
						pos.pb(tedge->len);
						tedge2tvertices[tedge] = tvertices;
						tedge2pos[tedge] = pos;
					}

					// Create new T-edges
					V<TEdge*> newtedges;
					F(i, max(1, q[tedge->id])) {
						TEdge* newtedge = new TEdge;
						newtedge->tvertex1 = tvertices[i];
						newtedge->tvertex2 = tvertices[i+1];
						newtedge->len = min(1, q[tedge->id]);
						newtedge->gedge = tedge->gedge;
						// if(newtedge->gedge == NULL) GeoLog::add({newtedge->tvertex1->vertex->ptr->point(), newtedge->tvertex2->vertex->ptr->point()}, rand(), "tedge->gedge == NULL");
						if(tedge2new.count(tedge->oppo)) {
							newtedge->oppo = tedge2new[tedge->oppo][max(1, q[tedge->id])-1-i];
							newtedge->oppo->oppo = newtedge;
							newtedge->id = newtedge->oppo->id;
						} else {
							newtedge->oppo = NULL;
							newtedge->id = TM2.nTEdges++;
						}
						TM2.tedges.pb(newtedge);
						newtedges.pb(newtedge);
						side_tedges[s].back().pb(newtedge);
						// Determine if we add this T-vertex to the side_tvertices
						curr_len += newtedge->len;
						if(newtedge->len == 1 && curr_len < side_len[s]) {
							side_tvertices[s].pb(newtedge->tvertex2);
							side_pos[s].pb(curr_pos + pos[i+1]);
							if(curr_len < side_len[s]) side_tedges[s].pb(V<TEdge*>());
						}
						newtedge->tvertex1->adj.pb({newtedge->tvertex2, newtedge});
					}
					tedge2new[tedge] = newtedges; // map old T-edge to sequence of new T-edges
					curr_pos += tedge->len;
				}

				// Replace last side T-vertex by corner
				side_tvertices[s].pb(tface->sides[s].back()->tvertex2);
				side_pos[s].pb(curr_pos);
			}

			// Create interior vertices and edges
			int nx = max(1, side_len[0]), ny = max(1, side_len[1]); // number of T-faces along dimension

			// if(nx > 1 && ny > 1) {
			// 	Msg::Warning("nx > 1 && ny > 1: this will probably segfault!");
			// }

			V<V<TVertex*>> tvertices(nx+1, V<TVertex*>(ny+1));
			// Sides 0 and 2
			F(i, nx+1) {
				tvertices[i][0] = side_tvertices[0][i]; // side 0
				tvertices[i][ny] = side_tvertices[2][nx-i]; // side 2
			}
			// Sides 1 and 3
			F(i, ny+1) {
				tvertices[0][i] = side_tvertices[3][ny-i]; // side 3
				tvertices[nx][i] = side_tvertices[1][i]; // side 1
			}
			// TODO later!!
			// Interior T-vertices
			if(nx > 1 && ny > 1) {
				int mx = side_pos[0].back(), my = side_pos[1].back(); // dimensions in terms of OLD quantization
				// Msg::Info("nx = %d, ny = %d", nx, ny);
				// Msg::Info("mx = %d, my = %d", mx, my);
				V<V<Vertex*>> vertices(mx+1, V<Vertex*>(my+1));
				HalfEdge* he0 = tface->sides[0].front()->he;
				F(j, my+1) {
					if(j > 0) he0 = he0->prev->prev->oppo;
					HalfEdge* he = he0;
					vertices[0][j] = he0->v1;
					F(i, mx) {
						vertices[i+1][j] = he->v2;
						he = he->next->oppo->next;
					}
				}
				int color = rand();
				F(i, mx+1) F(j, my+1) vertices[i][j]->geolog(color, "vertices");

				// F(i, mx+1) F(j, my+1) {
				// 	vertices[i][j]->geolog(0, "patch vertices");
				// }
				// tface->geolog(0, "tface");

				H(side_pos[0]);
				H(side_pos[1]);
				H(side_pos[2]);
				H(side_pos[3]);

				// draw();

				FR(i, 1, nx) {
					FR(j, 1, ny) {
						int x1 = side_pos[0][i];
						int x2 = mx - side_pos[2][nx-i];
						int y1 = my - side_pos[3][ny-j];
						int y2 = side_pos[1][j];
						vertices[x1][0]->geolog(0, "x1");
						vertices[x2][my]->geolog(1, "x2");
						vertices[0][y1]->geolog(2, "y1");
						vertices[mx][y2]->geolog(3, "y2");
						// vertices[x2][y2]->geolog(2, "2");
						// draw();
						// Msg::Info("(x1,y1) = (%d,%d), (x2,y2) = (%d,%d)", x1, y1, x2, y2);
						int dx = x2 - x1, dy = y2 - y1;
						int xs = mx * (dx*y1 + x1*my) / (mx*my - dx*dy);
						int ys = my * (dy*x1 + y1*mx) / (mx*my - dx*dy);
						// Msg::Info("xs = %d, ys = %d", xs, ys);

						vertices[xs][ys]->geolog(0, "new interior T-vertices");

						TVertex* tvertex = new TVertex;
						tvertex->vertex = vertices[xs][ys];
						tvertex->isGVertex = tvertex->isSingular = false;
						tvertices[i][j] = tvertex;
						TM2.tvertices.pb(tvertex);
					}
				}

				F(i, nx+1) F(j, ny+1) if(!tvertices[i][j]) Msg::Error("Some interior T-vertex is not defined!");
			}

			// draw();

			// Create faces and interior edges
			V<V<TFace*>> tface_grid(nx, V<TFace*>(ny));
			F(i, nx) F(j, ny) {
				TFace* newtface = new TFace;
				tface_grid[i][j] = newtface;
				newtface->gface = tface->gface;
				newtface->dim[0] = side_len[0], newtface->dim[1] = side_len[1];
				// Bottom edge
				if(j == 0) {
					newtface->sides[0] = side_tedges[0][i];
					for(TEdge* tedge : side_tedges[0][i]) {
						tedge->tface = newtface;
						tedge->side = 0;
					}
				} else {
					TEdge* tedge = new TEdge;
					tedge->tface = newtface;
					tedge->side = 0;
					tedge->tvertex1 = tvertices[i][j];
					tedge->tvertex2 = tvertices[i+1][j];
					tedge->oppo = tface_grid[i][j-1]->sides[2][0];
					tedge->oppo->oppo = tedge;
					tedge->gedge = NULL;
					tedge->len = (side_len[0] > 0);
					tedge->id = TM2.nTEdges++;
					TM2.tedges.pb(tedge);
					newtface->sides[0] = {tedge};
					tedge->tvertex1->adj.pb({tedge->tvertex2, tedge});
				}
				// Right edge
				if(i+1 == nx) {
					newtface->sides[1] = side_tedges[1][j];
					for(TEdge* tedge : side_tedges[1][j]) {
						tedge->tface = newtface;
						tedge->side = 1;
					}
				} else {
					TEdge* tedge = new TEdge;
					tedge->tface = newtface;
					tedge->side = 1;
					tedge->tvertex1 = tvertices[i+1][j];
					tedge->tvertex2 = tvertices[i+1][j+1];
					//tedge->oppo = TODO;
					tedge->gedge = NULL;
					tedge->len = (side_len[1] > 0);
					tedge->id = TM2.nTEdges++;
					TM2.tedges.pb(tedge);
					newtface->sides[1] = {tedge};
					tedge->tvertex1->adj.pb({tedge->tvertex2, tedge});
				} 
				// Top edge
				if(j+1 == ny) {
					newtface->sides[2] = side_tedges[2][nx-1-i];
					for(TEdge* tedge : side_tedges[2][nx-1-i]) {
						tedge->tface = newtface;
						tedge->side = 2;
					}
				} else {
					TEdge* tedge = new TEdge;
					tedge->tface = newtface;
					tedge->side = 2;
					tedge->tvertex1 = tvertices[i+1][j+1];
					tedge->tvertex2 = tvertices[i][j+1];
					//tedge->oppo = TODO;
					tedge->gedge = NULL;
					tedge->len = (side_len[2] > 0);
					tedge->id = TM2.nTEdges++;
					TM2.tedges.pb(tedge);
					newtface->sides[2] = {tedge};
					tedge->tvertex1->adj.pb({tedge->tvertex2, tedge});
				}
				// Left edge
				if(i == 0) {
					newtface->sides[3] = side_tedges[3][ny-1-j];
					for(TEdge* tedge : side_tedges[3][ny-1-j]) {
						tedge->tface = newtface;
						tedge->side = 3;
					}
				} else {
					TEdge* tedge = new TEdge;
					tedge->tface = newtface;
					tedge->side = 3;
					tedge->tvertex1 = tvertices[i][j+1];
					tedge->tvertex2 = tvertices[i][j];
					tedge->oppo = tface_grid[i-1][j]->sides[1][0];
					tedge->oppo->oppo = tedge;
					tedge->gedge = NULL;
					tedge->len = (side_len[3] > 0);
					tedge->id = TM2.nTEdges++;
					TM2.tedges.pb(tedge);
					newtface->sides[3] = {tedge};
					tedge->tvertex1->adj.pb({tedge->tvertex2, tedge});
				}
				TM2.tfaces.pb(newtface);
			}
			iface++;
		}

		Msg::Info("Done splitting T-edges");


		// draw();

		// for(TEdge* tedge : TM2.tedges) {
		// 	if(!tedge->gedge) {
		// 		GeoLog::add({tedge->tvertex1->vertex->ptr->point(), tedge->tvertex2->vertex->ptr->point()}, 0, "tedge->gedge == NULL");
		// 	}
		// }

		// int cnt = 0;
		// for(TFace* tface : TM2.tfaces) {
		// 	F(s, 4) {
		// 		cnt += S(tface->sides[s]);
		// 		for(TEdge* tedge : tface->sides[s])
		// 			if(!tedge->gedge)
		// 				GeoLog::add({tedge->tvertex1->vertex->ptr->point(), tedge->tvertex2->vertex->ptr->point()}, 0, "tedge->gedge == NULL");
		// 	}
		// }
		// H(cnt);
		// H(S(TM2.tedges));

		// draw();

		// exit(0);

		// Step 2: after splitting, build coarse mesh

		// First: propagate the gedge attribute along parallel T-edges with distance 0
		// TODO
		for(TEdge* tedge_start : TM2.tedges) if(tedge_start->gedge) {
			TEdge* tedge = tedge_start;
			while(tedge->tface->dim[(tedge->side+1)%2] == 0) { // while the incident T-face has 0 area
				for(TEdge* next_tedge : tedge->tface->sides[(tedge->side+2)%4]) {
					if(next_tedge->len) {
						tedge = next_tedge;
						break;
					}
				}			
				tedge->gedge = tedge_start->gedge;
				tedge = tedge->oppo;
				tedge->gedge = tedge_start->gedge;
				if(tedge == tedge_start) break;	
			}	
		}

		for(TVertex* tvertex : TM2.tvertices) {
			tvertex->geolog(0, "T-vertices after split");
		}

		// Merge T-vertices with distance 0 into C-vertices
		map<TVertex*, CVertex*> tvertex2cvertex;
		for(TVertex* tvertex : TM2.tvertices) if(!tvertex2cvertex.count(tvertex)) {
			CVertex* cvertex = new CVertex; cvertices.pb(cvertex);
			cvertex->tvertices.pb(tvertex);
			tvertex2cvertex[tvertex] = cvertex;
			queue<TVertex*> Q; Q.push(tvertex);
			while(S(Q)) {
				TVertex* u = Q.front(); Q.pop();
				for(auto p : u->adj) {
					TVertex* v = p.first;
					if(!tvertex2cvertex.count(v) && p.second->len == 0) {
						cvertex->tvertices.pb(v);
						tvertex2cvertex[v] = cvertex;
						Q.push(v);
					}
				}
			}
			int color = rand();
			for(TVertex* tv : cvertex->tvertices) tv->geolog(color, "clusters");
			cvertex->isSingularity = cvertex->isOnCAD = false;
			cvertex->gvertex = NULL;
			cvertex->vertex = NULL;
			for(TVertex* tvertex : cvertex->tvertices) {
				Vertex* vertex = tvertex->vertex;
				GEntity* gentity = vertex->ptr->onWhat();
				GFace* gf = dynamic_cast<GFace*>(gentity);
				if(gf) cvertex->gface = gf;
				if(dynamic_cast<GVertex*>(gentity)) {
					cvertex->isOnCAD = true;
					cvertex->vertex = vertex;
					// int cnt = 0; for(HalfEdge* he : vertex->hedges) cnt += (he->gedge != NULL);
					// if(cnt >= 3) { // CAD degree should not be less than 3!
					cvertex->gvertex = dynamic_cast<GVertex*>(gentity);
					break; // since there can be only 1 GVertex per tvertex group
					// }
				}
				// if((cvertex->gvertex = dynamic_cast<GVertex*>(gentity))) {
				// 	cvertex->isOnCAD = true;
				// 	cvertex->vertex = vertex;
				// 	break; // since there can be only 1 GVertex per tvertex group
				// }
				if(dynamic_cast<GEdge*>(gentity)) {
					cvertex->isOnCAD = true;
					cvertex->vertex = vertex;
					// No break since there could be a GVertex in the cluster
				}
				if(cvertex->vertex == NULL && tvertex->isSingular) { // non-CAD singularity
					cvertex->isSingularity = true;
					cvertex->vertex = vertex;
				}
			}
			if(cvertex->vertex == NULL) // any vertex will do
				cvertex->vertex = cvertex->tvertices.front()->vertex;
			cvertex->geolog(0, "C-vertices");
		}

		// Create C-edges and C-faces
		map<pair<CVertex*, CVertex*>, CEdge*> cvertexpair2cedge;
		for(TFace* tface : TM2.tfaces) {
			// First check if T-face has area > 0 (otherwise: skip)
			int area = 1;
			F(k, 2) {
				int len = 0;
				for(TEdge* tedge : tface->sides[k])
					len += tedge->len;
				area *= len;
			}
			if(area == 0) continue;
			
			CFace* cface = new CFace; cfaces.pb(cface);
			cface->gface = tface->gface;

			// Iterate on each side of C-face
			F(s, 4) {
				int color = rand();
				
				// Find only T-edge with q = 1
				TEdge* tedge;
				F(i, S(tface->sides[s])) {
					tedge = tface->sides[s][i];
					if(tedge->len) break;
				}

				CVertex	*cvertex1 = tvertex2cvertex[tedge->tvertex1],
						*cvertex2 = tvertex2cvertex[tedge->tvertex2];
				Vertex *vertex1 = cvertex1->vertex, *vertex2 = cvertex2->vertex;

				CEdge* cedge = new CEdge; cedges.pb(cedge);
				cface->sides[s] = cedge;
				cedge->cface = cface;
				cedge->side = s;
				cedge->cvertex1 = cvertex1;
				cedge->cvertex2 = cvertex2;
				// if = cedge;

				// Assign GEdge, if any
				cedge->gedge = tedge->gedge;
				if(!tedge->gedge) {
					GeoLog::add({tedge->tvertex1->vertex->ptr->point(), tedge->tvertex2->vertex->ptr->point()}, 0, "tedge->gedge == NULL");
					// tedge->geolog(rand(), "tedge->gedge == NULL");
				}
				// Assign oppo, if it exists already
				if(cvertexpair2cedge.count({cvertex2, cvertex1})) {
					CEdge* oppo = cvertexpair2cedge[{cvertex2, cvertex1}];
					cedge->oppo = oppo;
					oppo->oppo = cedge;
					V<HalfEdge*> path = oppo->path;
					V<HalfEdge*> reversepath;
					D(i, S(path)) reversepath.pb(path[i]->oppo);
					cedge->path = reversepath;
				} else {
					cvertexpair2cedge[{cvertex1, cvertex2}] = cedge;
					// Determine shortest path
					V<HalfEdge*> path;
					map<Vertex*, HalfEdge*> parent; parent[vertex1] = NULL;
					V<Vertex*> Q; Q.pb(vertex1);
					int cnt = 0;
					while(true) {
						++cnt;
						if(cnt > 1000) {
							vertex1->geolog(0, "stuck");
							vertex2->geolog(0, "stuck");
							draw();
						}
						// Msg::Info("In while loop.");
						V<Vertex*> Qn;
						bool done = false;
						for(Vertex* u : Q) {
							for(HalfEdge* he : u->hedges) {
								Vertex* v = he->v2;
								// If path corresponds to a GEdge, force the path to stay on the GEdge
								if(cedge->gedge && v != vertex2 && !dynamic_cast<GEdge*>(v->ptr->onWhat()))
									continue;
								if(!parent.count(v)) {
									parent[v] = he;
									if(v == vertex2) {
										done = true;
										break;
									}
									Qn.pb(v);
								}
							}
							if(done) break;
						}
						if(done) break;
						Q = Qn;
						// Sort Q according to distance to center2
						sort(ALL(Q), [vertex1, vertex2](Vertex* a, Vertex* b)->bool { return a->dist(vertex1) + a->dist(vertex2) < b->dist(vertex1) + b->dist(vertex2); });
					}
					Vertex* u = vertex2;
					do {
						// H(u);
						HalfEdge* he = parent[u];
						path.pb(he);
						u = he->v1;
					} while(u != vertex1);

					// Reverse path (vertex1 -> vertex2)
					reverse(ALL(path));

					cedge->path = path;
					cedge->geolog(color, "coarse mesh");
				}
			}
		}
		H(S(cedges));
		H(4*S(cfaces));
	
		Msg::Info("Done building coarse mesh");
	}
};

/*****************/
/* Gecode models */
/*****************/

// Find coarsest mesh
class AlignQuadMesh : public IntMinimizeSpace {
	protected:
		IntVarArray l; // lengths of T-edges
		IntVar costvar; // cost to minimize
		const TMesh& TM;
	public:
		AlignQuadMesh(const TMesh& TM_, int lmax, int strategy) :
			// l(*this, TM_.nTEdges, 0, lmax),
			l(*this, TM_.nTEdges, 0, Int::Limits::max),
			costvar(*this, 0, Int::Limits::max),
			TM(TM_) {

			for(TEdge * tedge : TM.tedges) {
				GEdge* gedge1 = dynamic_cast<GEdge*>(tedge->tvertex1->vertex->ptr->onWhat());
				GEdge* gedge2 = dynamic_cast<GEdge*>(tedge->tvertex2->vertex->ptr->onWhat());
				if(gedge1 != NULL && gedge2 != NULL && gedge1 != gedge2) {
					tedge->geolog(0, "T-edge forced > 0");
					rel(*this, l[tedge->id] > 0);
				}
			}

			// Constrain quantization to not exceed original length
			for(TEdge* tedge : TM.tedges) {
				rel(*this, l[tedge->id] <= tedge->len);
			}

			// Constrain opposite sides of T-faces to have equal length
			// IntVarArgs a(S(TM.tfaces));
			IntVarArray a(*this,S(TM.tfaces));
			F(f, S(TM.tfaces)) {
				TFace* tface = TM.tfaces[f];
				array<IntVarArgs,4> s; // 4 sides
				F(k, 4) {
					s[k] = IntVarArgs(S(tface->sides[k]));
					F(i, S(tface->sides[k]))
						s[k][i] = l[tface->sides[k][i]->id];
				}
				rel(*this, sum(s[0]) == sum(s[2]));
				rel(*this, sum(s[1]) == sum(s[3]));
				a[f] = expr(*this, sum(s[0]) * sum(s[1]));
			}

			// Validity constraints
			for(Trace* trace : TM.traces) {
				// if(trace->orig->vertex->valence != 4) {
				if(true) {
					int color = rand();
					IntVarArgs s(trace->istar+1);
					F(i, trace->istar+1) {
						s[i] = l[trace->tedges[i]->id];
						trace->tedges[i]->geolog(color, "validity constraints");
					}
					rel(*this, sum(s) > 0);
				} else {
					Msg::Warning("trace origin has valence 4");
				}
			}

			// Layout constraints
			for(Trace* trace : TM.traces) {
				for(TraceIntersection* inters : trace->intersections) {	
					if(inters->t->len[inters->j] > tan(trace->alpha) * trace->len[inters->i]) {
						// // If origin of the intersecting trace is a GVertex, check that it has at least 3 GEdge incident half-edges
						// if(inters->t->orig->isGVertex) {
						// 	int cnt = 0;
						// 	for(HalfEdge* he : inters->t->orig->vertex->hedges) {
						// 		cnt += (he->gedge != NULL);
						// 	}
						// 	if(cnt < 3) continue;
						// }

						// New layout constraint
						IntVarArgs s(inters->j+1);
						F(i, inters->j+1)
							s[i] = l[inters->t->tedges[i]->id];
						rel(*this, sum(s) > 0);
					}
				}
			}

			// For every non-singularity irregular vertex, find its match and force collapse
			map<TVertex*, TVertex*> match;
			vector<vector<int> > pathes_35;
			for(TVertex* tvertex : TM.tvertices) {
				// If vertex is irregular, but not a singularity nor a GVertex,
				if(tvertex->vertex->valence != 4 && !tvertex->vertex->isSingularity && !tvertex->isGVertex) {
					if(match.count(tvertex)) continue; // Matching vertex already found
					map<TVertex*, int> dist;
					map<TVertex*, pair<TVertex*, TEdge*>> par; // parent
					for(TVertex* v : TM.tvertices) dist[v] = (tvertex == v) ? 0 : INT_MAX;
					priority_queue<pair<int,TVertex*>> pq; pq.push({0, tvertex});
					while(S(pq)) {
						auto p = pq.top(); pq.pop();
						TVertex* u = p.second; int du = -p.first;
						if(dist[u] < du) continue;
						if(u->vertex->valence + tvertex->vertex->valence == 8 && !u->vertex->isSingularity && !u->isGVertex) {
							match[tvertex] = u;
							match[u] = tvertex;
							int color = rand();
							tvertex->geolog(color, "matching pairs");
							u->geolog(color, "matching pairs");
							break;
						}
						for(auto pa : u->adj) {
							TVertex* v = pa.first; TEdge* e = pa.second;
							// if(v == u) P("v == u !!!");
							int dv = du + e->len;
							if(dist[v] > dv) {
								dist[v] = dv;
								par[v] = {u, e};
								pq.push({-dv, v});
							}
						}
					}

					// Form path and force it to collapse
					TVertex* u = match[tvertex];
					V<TEdge*> path; // sequence of T-edges connecting the matching pair
					while(u != tvertex) {
						auto pa = par[u];
						path.pb(pa.second);
						u = pa.first;
					}

          vector<int> path_ids;
          F(i, S(path)) {
            path_ids.push_back(path[i]->id);
          }
          pathes_35.push_back(path_ids);

          // // Gecode constraints
					// IntVarArgs p(S(path));
					// int color = rand();
					// F(i, S(path)) {
					// 	p[i] = l[path[i]->id];
					// 	path[i]->geolog(color, "paths connecting 3-5 pairs");
					// }
					// rel(*this, sum(p) == 0);
				}
			}
      F(i,S(pathes_35)) F(j,S(pathes_35[i])) {
        TM.tedges[pathes_35[i][j]]->isOn35path = true;
      }
      Msg::Info("Number of 3-5 pathes: %li", S(pathes_35));

			// draw();

			// Constrain stitches to have length > 0
			for(TEdge* tedge : TM.tedges) 
				if(tedge->isStitch) {
					rel(*this, l[tedge->id] > 0);
					Msg::Info("stitch found");
				}


			// Branching function
			// branch(*this, l, INT_VAR_NONE(), INT_VAL_MIN()); // branch on first unassigned variable

      // // Current branching
			// branch(*this, l, INT_VAR_MAX_MIN(), INT_VAL_MIN()); // branch on smallest maximum value

			// Rnd rnd(42); branch(*this, l, INT_VAR_NONE(), INT_VAL_MAX()); // give max value to first unassigned variable
			// Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_RND(rnd)); // TODO: is there a smarter way?
			// Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_MIN()); // TODO: is there a smarter way?

			// branch(*this, l, INT_VAR_MERIT_MIN(choose_variable), INT_VAL_MAX());

      Msg::Info("BAB strategy: %i", strategy);
      if (strategy == 0) {
        branch(*this, l, INT_VAR_MAX_MIN(), INT_VAL_MIN()); // branch on smallest maximum value

        // Cost function
        rel(*this, costvar == sum(a)); // mimimize sum of areas
      } else {
        // Variable selection
        auto choose_variable = [](const Space &home, IntVar x, int i) {
          const AlignQuadMesh& model = static_cast<const AlignQuadMesh&>(home);
          TEdge* te = model.TM.id2te[i];
          // Msg::Info("[var] %i, merit: %i", i, te->len);
          return te->len;
        };
        // Value selection
        auto choose_value = [](const Space &home, IntVar x, int i) {
          const AlignQuadMesh& model = static_cast<const AlignQuadMesh&>(home);
          TEdge* te = model.TM.id2te[i];
          int value = 1;
          if (te->len == x.max()) {
            value = te->len;
          } else {
            value = x.min();
          }
          // if (model.TM.tedges[i]->isOn35path) {
          //   value = x.min();
          // } else {
          //   value = x.max();
          // }
          // Msg::Info("[value] var %i: min=%i, max=%i, len=%i  ->   %i", i, x.min(), x.max(), te->len, value);
          // Msg::Info("        degree = %i, afc = %i", x.degree(), x.afc());
          return value;

        };
        branch(*this, l, INT_VAR_MERIT_MIN(choose_variable), INT_VAL(choose_value));

        // minimize number of non-zero area patches
        // IntVar nnz(*this,0,int(TM.tfaces.size()));
        // count(*this, a, 0, IRT_GR, nnz); 
        // rel(*this, costvar == nnz);

        // maximize number of zero-length edges
        IntVar nz(*this,0,TM.nTEdges);
        count(*this, l, 0, IRT_EQ, nz); // nz == number of zero length T-edges
        rel(*this, costvar == TM.nTEdges-nz);
      }

			//// First choose shortest edges and assign min value
			//branch(*this, l, INT_VAR_MERIT_MIN(m), INT_VAL_MIN());
			// First choose longest edges and assign min value
			//branch(*this, l, INT_VAR_MERIT_MAX(m), INT_VAL_MIN());

			P("done constructing AlignQuadMesh");
		}
		// copier
		AlignQuadMesh(AlignQuadMesh& s) : IntMinimizeSpace(s), TM(s.TM) {
			l.update(*this, s.l);
			// a.update(*this, s.a);
			costvar.update(*this, s.costvar);
		}
		virtual Space* copy(void) {
			return new AlignQuadMesh(*this);
		}
		// printer
		void print(ostream& os) const {
      int nz = 0;
      F(i,l.size()) if (l[i].val() == 0) nz += 1;
      os << "Solution: " << l << ". Cost = " << costvar << ". #0: " << nz << endl;
		}
		// cost function
		virtual IntVar cost(void) const {
			return costvar;
		}
		// extract solution
		void getSolution(V<int>& sol) {
			sol.resize(S(l));
			F(i, S(l))
				sol[i] = l[i].val();
		}
};

// Find best quantization for quad loops
class OptimizeLengths : public IntMinimizeSpace {
	protected:
		IntVarArray l; // quantization of quad loops
		IntVarArray d; // diff between current and desired gedge lengths
		IntVar costvar; // cost to minimize
	public:
		OptimizeLengths(int nquadloops, map<GEdge*, set<int>>& gedge2quadloops) :
			l(*this, nquadloops, 1, 100), // TODO
			d(*this, S(gedge2quadloops), 0, Int::Limits::max),
			costvar(*this, 0, Int::Limits::max) {

			FIT(it, gedge2quadloops) {
				GEdge* gedge = it->first;
				set<int> quadloops = it->second;
				IntVarArgs s(S(quadloops));
				int i = 0;
				for(int ql : quadloops)
					s[i++] = l[ql];
				H(gedge->tag());
				H(S(quadloops));
				rel(*this, d[gedge->tag()-1] == (sum(s) - gedge->getNumMeshElements()) * (sum(s) - gedge->getNumMeshElements()));
			}

			// Cost function
			rel(*this, costvar == sum(d));

			// Branching function
			Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_MIN()); // TODO: is there a smarter way?
		}
		// copier
		OptimizeLengths(OptimizeLengths& s) : IntMinimizeSpace(s) {
			l.update(*this, s.l);
			d.update(*this, s.d);
			costvar.update(*this, s.costvar);
		}
		virtual Space* copy(void) {
			return new OptimizeLengths(*this);
		}
		// printer
		void print(void) const {
      int nz = 0;
      F(i,l.size()) if (l[i].val() == 0) nz += 1;
      cout << l << ". Cost = " << costvar << ". #0: " << nz << endl;
		}
		// cost function
		virtual IntVar cost(void) const {
			return costvar;
		}
		// extract solution
		void getSolution(V<int>& sol) {
			sol.resize(S(l));
			F(i, S(l))
				sol[i] = l[i].val();
		}
};

/******************/
/* Misc functions */
/******************/

// Resample polyline
bool compute_subdivided_edge_internal_points(const std::vector<SPoint3>& pts, size_t N, vector<SPoint3>& newPts) {
	newPts.clear();
	if (N == 0) return true;

	/* Size map size(t) */
	vector<SPoint3> failed_probes;
	vector<double> size(pts.size(),0.);
	F(i, size.size()) {
	// size[i] = sizemap.eval(pts[i]);
	size[i] = 1;
	if (size[i] == DBL_MAX) {
	  failed_probes.push_back(pts[i]);
	}
	}

	vector<double> Pri(pts.size(),0.);
	/* Integral of inverse, Pri = int(1/size(t),t) */
	double totalLen = 0.;
	F(i,pts.size()-1.) {
		double len = pts[i].distance(pts[i+1]);
	//double len = distance(pts[i+1], pts[i]);
		totalLen += len;
		Pri[i+1] = Pri[i] + 0.5 * (1./double(size[i]) + 1./double(size[i+1])) * len;
	}



	vector<double> targetLens(N, 0.);
	F(i,N) {
	double n = double(1.+i)/double(1.+N) * Pri.back();
	double len_j = 0.;
	double len_jp1 = 0.;
	F(j,pts.size()-1) {
	  len_jp1 = len_j + pts[j].distance(pts[j+1]);
	  //len_jp1 = len_j + length(pts[j+1] - pts[j]);
	  if (Pri[j] <= n && n < Pri[j+1]) {
		double lambda = (n - Pri[j]) / (Pri[j+1] - Pri[j]);
		targetLens[i] = (1.-lambda) * len_j + lambda * len_jp1;
	  } else if (n == Pri[j+1]) {
		targetLens[i] = len_jp1;
	  }
	  len_j = len_jp1;
	}
	}

	constexpr bool NAIVE = false;
	size_t prev_j = 0;
	double prev_acc = 0.;
	F(i,N) {
	double targetLen = targetLens[i];

	bool found = false;
	if (NAIVE) {
	  double len_j = 0.;
	  for(size_t j = 0; j < pts.size()-1; ++j) {
		//double acc = length(pts[j+1]-pts[j]);
		double acc = pts[j].distance(pts[j+1]);
		double len_jp1 = len_j + acc;

		if (len_j < targetLen && targetLen <= len_jp1) {
		  double lambda = (targetLen - len_j) / (len_jp1 - len_j);
		  SPoint3 pt = SPoint3((1.-lambda) * pts[j] + lambda * pts[j+1]);
		  // double h = (1.-lambda) * size[j] + lambda * size[j+1];
		  newPts.push_back(pt);
		  // newSizes.push_back(h);
		  found = true;
		  break;
		}

		len_j = len_jp1;
	  }
	} else {
	  double acc = prev_acc;
	  for(size_t j = prev_j; j < pts.size()-1; ++j) {
		double len_j = acc;
		acc += pts[j].distance(pts[j+1]);
		//acc += length(pts[j+1]-pts[j]);
		double len_jp1 = acc;

		if (len_j < targetLen && targetLen <= len_jp1) {
		  double lambda = (targetLen - len_j) / (len_jp1 - len_j);
		  SPoint3 pt = SPoint3((1.-lambda) * pts[j] + lambda * pts[j+1]);
		  // double h = (1.-lambda) * size[j] + lambda * size[j+1];
		  newPts.push_back(pt);
		  // newSizes.push_back(h);
		  found = true;
		  prev_j = j;
		  prev_acc = len_j;
		  break;
		}
	  }
	}
	if (!found) {
	  cout << "sample point not found !" << endl;
	  return false;
	}
}

if (ERROR_VISU && failed_probes.size() > 0) {
F(i,failed_probes.size()) {
  GeoLog::add({SVector3(failed_probes[i])},double(i), "compute_subdivided_edge_internal_points");
}
GeoLog::flush();
}
//RFC(failed_probes.size() > 0, "compute_subdivided_edge_internal_points | {} probe failures", failed_probes.size());

return true;
}

// Resample polyline
bool sample_polyline(const std::vector<SPoint3>& pts, double t, SPoint3& pt) {
  if (t < 0. || t > 1.) return false;
  if (t == 0.) {
    pt = pts.front();
    return true;
  } else if (t == 1.) {
    pt = pts.back();
    return true;
  }

  double totalLen = 0.;
  F(i,pts.size()-1.) {
    double len = pts[i].distance(pts[i+1]);
    totalLen += len;
  }
  double targetLen = t * totalLen;

  bool found = false;
  double acc = 0.;
  for(size_t j = 0; j < pts.size()-1; ++j) {
    double len_j = acc;
    acc += pts[j].distance(pts[j+1]);
    double len_jp1 = acc;

    if (len_j < targetLen && targetLen <= len_jp1) {
      double lambda = (targetLen - len_j) / (len_jp1 - len_j);
      pt = SPoint3((1.-lambda) * pts[j] + lambda * pts[j+1]);
      found = true;
      break;
    }
  }
  if (!found) {
    Msg::Error("sample_polyline: not found, t=%f, totalLen=%f, targetLen=%f, acc=%f",t,totalLen,targetLen,acc);
    return false;
  }

  return true;
}

// Transfinite Interpolation, for computing interior points
bool transfinite_interpolation( const vector<SPoint3>& c1, const vector<SPoint3>& c2,
	const vector<SPoint3>& c3, const vector<SPoint3>& c4, vector<SPoint3>& pts) {
  if (c1.size() <= 2 || c2.size() <= 2 || c3.size() <= 2 || c4.size() <= 2) {
	Msg::Error("cannot TFI, c1.size=%d, c2.size=%d, c3.size=%d, c4.size=%d", c1.size(),c2.size(),c3.size(),c4.size());
	return false;
  }
  if (c1.size() != c3.size() || c2.size() != c4.size()) {
	Msg::Error("cannot TFI, c1.size=%d, c2.size=%d, c3.size=%d, c4.size=%d", c1.size(),c2.size(),c3.size(),c4.size());
	return false;
  }

  size_t Ni = c1.size()-2;
  size_t Nj = c2.size()-2;

  vector<SPoint3> c1_u, c3_u, c2_v, c4_v;
  c1_u = std::vector<SPoint3>(c1.begin()+1, c1.end()-1);
  c3_u = std::vector<SPoint3>(c3.begin()+1, c3.end()-1);
  c2_v = std::vector<SPoint3>(c2.begin()+1, c2.end()-1);
  c4_v = std::vector<SPoint3>(c4.begin()+1, c4.end()-1);
  std::reverse(c3_u.begin(),c3_u.end());
  std::reverse(c4_v.begin(),c4_v.end());

  pts.resize(Ni*Nj);
  F(i,Ni) F(j,Nj) {
	double u = (1.+i) / (1.+Ni);
	double v = (1.+j) / (1.+Nj);
	pts[Ni*j+i] = SPoint3((1.-v) * c1_u[i] + v * c3_u[i] + (1.-u) * c4_v[j] + u * c2_v[j]
	  - ((1.-u)*(1.-v)*c1[0] + u*v*c3[0] + u * (1.-v) * c2[0] + (1.-u)*v*c4[0]));
  }

  return true;
}

// Using the background field, extract the singularities of a given GFace, as a list of (coordinates, valence) pair.
bool myGetSingularitiesFromBackgroundField(GFace* gf, vector<pair<SPoint3, int> >& singularities) {
	singularities.clear();

	Field* field = nullptr;
	FieldManager *fields = gf->model()->getFields();
	if(fields->getBackgroundField() > 0) {
		Field *guiding_field = fields->get(fields->getBackgroundField());
		if(guiding_field && guiding_field->numComponents() == 3) 
			field = guiding_field;
	}
	if (field == nullptr) {
		Msg::Error("get singularities: face %i, failed to get background field", gf->tag());
		return false;
	}

	int viewTag = int(field->options["IView"]->numericalValue());
	PView* view = PView::getViewByTag(viewTag);
	if (view == nullptr) {
		Msg::Error("failed to get view for tag = %i", viewTag);
		return false;
	}
	PViewDataList *d = dynamic_cast<PViewDataList *>(view->getData());
	if (d == nullptr) {
		Msg::Error("view type is wrong");
		return false;
	}

	size_t nVP = d->VP.size()/6;
	for (size_t i = 0; i < nVP; ++i) {
		int gfTag = int(std::round(d->VP[6*i+3] / VIEW_INT_SCALING));
		if (gfTag != gf->tag()) continue;
		int index = int(std::round(d->VP[6*i+4] / VIEW_INT_SCALING));
		double x = d->VP[6*i+0];
		double y = d->VP[6*i+1];
		double z = d->VP[6*i+2];
		singularities.push_back(std::make_pair(SPoint3(x,y,z),index));
	}

	return true;
}

V<int> optimizeQuantization(TMesh& TM, int strategy = 0) {
	AlignQuadMesh* model = new AlignQuadMesh(TM, 2, strategy); // TODO: determine lmax

	// Options opt("Align Quad Mesh");
	// Script::run<AlignQuadMesh, BAB, Options>(opt);
	// Gist::Print<AlignQuadMesh> p("Print solution");
	// Gist::Options opt;
	// opt.inspect.click(&p);
	// Gist::bab(model, opt);
	// draw();

	Search::Options options;
	// Search::TimeStop ts(60000);
	double tMax = 10;
  if (strategy == 0) {
    tMax = 3;
  }
  Msg::Info("BAB search ... (time max: %.3fsec)", tMax);
	Search::TimeStop ts(tMax*1000);
	options.stop = &ts;
	BAB<AlignQuadMesh> engine(model, options);
	delete model;
	V<int> sol;
	clock_t start = clock();
	while(AlignQuadMesh* state = engine.next()) {
		state->getSolution(sol);
		// cout << state << endl;
		state->print(cout);
	}
	if(S(sol) == 0) {
		P("No quantization found!");		
		// Msg::Error("No quantization found!");
	}
	double elapsed = double(clock() - start) / CLOCKS_PER_SEC;
	Msg::Info("Time for quantization: %.2lf s", elapsed);
	return sol;
}



V<int> optimizeQuantizationLpSolve(TMesh& TM) {

  size_t N = TM.nTEdges;

  V<int> valueMin(N,0);
  V<int> valueMax(N,INT_MAX);
  for(TEdge * tedge : TM.tedges) {
    valueMax[tedge->id] = tedge->len;

    GEdge* gedge1 = dynamic_cast<GEdge*>(tedge->tvertex1->vertex->ptr->onWhat());
    GEdge* gedge2 = dynamic_cast<GEdge*>(tedge->tvertex2->vertex->ptr->onWhat());
    if(gedge1 != NULL && gedge2 != NULL && gedge1 != gedge2) {
      valueMin[tedge->id] = 1;
    }


    // Constrain stitches to have length > 0
    if(tedge->isStitch) {
      valueMin[tedge->id] = 1;
    }
  }

  lp_solve::LpSolveSolver solver(N);

  // variable range
  F(i,N) {
    solver.setInteger(i);
    solver.setBounds(i,valueMin[i],valueMax[i]);
  }


  // Constrain opposite sides of T-faces to have equal length
  F(f, S(TM.tfaces)) {
    TFace* tface = TM.tfaces[f];
    array<V<int>,4> s; // 4 sides
    F(k, 4) {
      s[k].resize(S(tface->sides[k]));
      F(i, S(tface->sides[k]))
        s[k][i] = tface->sides[k][i]->id;
    }
    { // sum side 0 = sum side 2
      std::vector<std::pair<int,double> > column_value;
      F(i,S(s[0])) column_value.push_back({s[0][i],1.});
      F(i,S(s[2])) column_value.push_back({s[2][i],-1.});
      solver.addConstraintRow(column_value, lp_solve::LPS_EQ, 0);
    }
    { // sum side 1 = sum side 3
      std::vector<std::pair<int,double> > column_value;
      F(i,S(s[1])) column_value.push_back({s[1][i],1.});
      F(i,S(s[3])) column_value.push_back({s[3][i],-1.});
      solver.addConstraintRow(column_value, lp_solve::LPS_EQ, 0);
    }
  }

  // Validity constraints
  for(Trace* trace : TM.traces) {
    // if(trace->orig->vertex->valence != 4) {
    if(trace->istar != -1) {
      std::vector<std::pair<int,double> > column_value;
      F(i, trace->istar+1) {
        column_value.push_back({trace->tedges[i]->id,1.});
      }
      solver.addConstraintRow(column_value, lp_solve::LPS_GE, 1);
    }
  }

  // Layout constraints
  for(Trace* trace : TM.traces) {
    for(TraceIntersection* inters : trace->intersections) {	
	  // If intersection correspondonds to a 3-5 pair, don't put a constraint to allow them to collapse
      if(inters->t->len[inters->j] > tan(trace->alpha) * trace->len[inters->i] && (trace->orig->vertex->valence + inters->t->orig->vertex->valence != 8 || trace->orig->isGVertex || inters->t->orig->isGVertex)) {
        // // If origin of the intersecting trace is a GVertex, check that it has at least 3 GEdge incident half-edges
        // if(inters->t->orig->isGVertex) {
        // 	int cnt = 0;
        // 	for(HalfEdge* he : inters->t->orig->vertex->hedges) {
        // 		cnt += (he->gedge != NULL);
        // 	}
        // 	if(cnt < 3) continue;
        // }

        // New layout constraint
        std::vector<std::pair<int,double> > column_value;
        F(i, inters->j+1) {
          column_value.push_back({inters->t->tedges[i]->id,1});
        }
        solver.addConstraintRow(column_value, lp_solve::LPS_GE, 1);
      }
    }
  }

//   // Prevent any irregular vertex from collapsing on CAD
//   for(TVertex* tvertex : TM.tvertices) if(tvertex->vertex->valence != 4) {
// 	  for(HalfEdge* hes : tvertex->vertex->hedges) {
// 		  HalfEdge* he = hes;
// 		  while(!he->v2->isOnCAD && ) {

// 		  }
// 	  }
//   }

  // Objective function
  {
    std::vector<std::pair<int,double> > column_value;
    F(i,N) {
      double w = 1./double(TM.id2te[i]->len);
      column_value.push_back({i,w});
    }
    solver.setObjectiveFunction(column_value,true);
  }

  // Tell the solver to start from upper bound (see lp_solve documentation)
  if (true) {
    // maxence: not the right values ? don't know how to use it to specify initial guess :/
    bool okb = solver.setBasisUpperBound();
    if (!okb) {
      Msg::Warning("failed to set basis for lp_solve");
    }
  }

	V<double> sol;
  if (solver.lpSolve(sol)) {
    Msg::Info("quantization found with lp_solve:");

    int nz = 0;
    F(i,sol.size()) if (sol[i] == 0) nz += 1;
    P(sol);
    std::cout << "#0: " << nz << endl;
  }

  V<int> sol_int(sol.size(),0);
  F(i,N) sol_int[i] = (int) sol[i];

	return sol_int;
}

void buildMeshFromCMesh(CMesh& CM, GModel* gm) {
	
	// Map C-elements to elements of the new mesh
	map<CEdge*, V<MVertex*>> cedge2mvertices;
	// map<CEdge*, V<MLine*>> cedge2mlines;
	map<CVertex*, MVertex*> cvertex2mvertex;
	
	// Map GEntities to new mesh elements
	map<GVertex*, MVertex*> gvertex2mvertex;
	map<GEdge*, V<MEdgeVertex*>> gedge2mvertices;
	map<GEdge*, V<MLine*>> gedge2mlines;
	map<GFace*, V<MFaceVertex*>> gface2mvertices;
	map<GFace*, V<MQuadrangle*>> gface2mquads;
	
	// Build MVertices on GVertices
	for(CVertex* cvertex : CM.cvertices) if(cvertex->gvertex) {
		MVertex* mv = cvertex->vertex->ptr;
		MVertex* newmv = new MVertex(mv->x(), mv->y(), mv->z(), cvertex->gvertex);
		gvertex2mvertex[cvertex->gvertex] = newmv;
	}

	for(CFace* cface : CM.cfaces) {
		array<V<MVertex*>, 4> side_mvertices;
		array<V<MLine*>, 4> side_mlines;
		GFace* gface = cface->gface;
		F(s, 4) {
			CEdge* cedge = cface->sides[s];
			GEdge* gedge = cedge->gedge;
			if(!gedge) cedge->geolog(rand(), "cedge->gedge == NULL");
			CVertex *cvertex1 = cedge->cvertex1, *cvertex2 = cedge->cvertex2;
			GVertex *gvertex1 = cvertex1->gvertex, *gvertex2 = cvertex2->gvertex;
			if(cedge2mvertices.count(cedge)) {
				side_mvertices[s] = cedge2mvertices[cedge];
				side_mlines[s] = cedge->mlines;
				continue;
			}
			
			// Resample path
			V<SPoint3> points;
			for(HalfEdge* he : cedge->path)
				points.pb(he->v1->ptr->point());
			points.pb(cedge->path.back()->v2->ptr->point());
			V<SPoint3> newpoints; // resampled points
			// int nb_internal = 4; // number of internal points. TODO
			int nb_internal = cedge->q - 1; // number of internal points.
			compute_subdivided_edge_internal_points(points, nb_internal, newpoints);
			newpoints.insert(newpoints.begin(), points.front());
			newpoints.pb(points.back());

			// Create MVertices

			// cvertex1
			if(gvertex1) side_mvertices[s].pb(gvertex2mvertex[gvertex1]);
			else if(cvertex2mvertex.count(cvertex1)) side_mvertices[s].pb(cvertex2mvertex[cvertex1]);
			else {
				SPoint3 p = newpoints.front();
				GEdge* local_gedge = dynamic_cast<GEdge*>(cvertex1->vertex->ptr->onWhat());
				if(local_gedge) {
					double param; local_gedge->closestPoint(p, param);
					MEdgeVertex* mev = new MEdgeVertex(p.x(), p.y(), p.z(), local_gedge, param);
					gedge2mvertices[local_gedge].pb(mev);
					side_mvertices[s].pb(mev);
					cvertex2mvertex[cvertex1] = mev;
				} else {
					double uv[2]; gface->closestPoint(p, uv); // get params
					MFaceVertex* mfv = new MFaceVertex(p.x(), p.y(), p.z(), cface->gface, uv[0], uv[1]);
					gface2mvertices[gface].pb(mfv);
					side_mvertices[s].pb(mfv);
					cvertex2mvertex[cvertex1] = mfv;
				}
			}

			// Internal points
			FR(i, 1, S(newpoints)-1) {
				SPoint3 p = newpoints[i];
				if(gedge) { 
					double param; gedge->closestPoint(p, param);
					MEdgeVertex* mev = new MEdgeVertex(p.x(), p.y(), p.z(), gedge, param);
					gedge2mvertices[gedge].pb(mev);
					side_mvertices[s].pb(mev);
				} else {
					double uv[2]; gface->closestPoint(p, uv); // get parameters
					MFaceVertex* mfv = new MFaceVertex(p.x(), p.y(), p.z(), cface->gface, uv[0], uv[1]);
					gface2mvertices[gface].pb(mfv);
					side_mvertices[s].pb(mfv);
				}
			}

			// cvertex2
			if(gvertex2) side_mvertices[s].pb(gvertex2mvertex[gvertex2]);
			else if(cvertex2mvertex.count(cvertex2)) side_mvertices[s].pb(cvertex2mvertex[cvertex2]);
			else {
				SPoint3 p = newpoints.back();
				GEdge* local_gedge = dynamic_cast<GEdge*>(cvertex2->vertex->ptr->onWhat());
				if(local_gedge) { 
					double param; local_gedge->closestPoint(p, param);
					MEdgeVertex* mev = new MEdgeVertex(p.x(), p.y(), p.z(), local_gedge, param);
					gedge2mvertices[local_gedge].pb(mev);
					side_mvertices[s].pb(mev);
					cvertex2mvertex[cvertex2] = mev;
				} else {
					double uv[2]; gface->closestPoint(p, uv); // get params
					MFaceVertex* mfv = new MFaceVertex(p.x(), p.y(), p.z(), cface->gface, uv[0], uv[1]);
					gface2mvertices[gface].pb(mfv);
					side_mvertices[s].pb(mfv);
					cvertex2mvertex[cvertex2] = mfv;
				} 
			}

			// Store MVertices
			cedge2mvertices[cedge] = side_mvertices[s];
			V<MVertex*> rev = side_mvertices[s]; reverse(ALL(rev));
			cedge2mvertices[cedge->oppo] = rev;

			// Create MLines
			FR(i, 1, S(newpoints)) {
				MLine* ml = new MLine(side_mvertices[s][i-1], side_mvertices[s][i]);
				side_mlines[s].pb(ml);
				if(gedge) gedge2mlines[gedge].pb(ml);
			}
			cedge->mlines = side_mlines[s];
			V<MLine*> rev_mline = side_mlines[s]; reverse(ALL(rev_mline));
			cedge->oppo->mlines = rev_mline;
		}

		// Create internal MVertices
		array<V<SPoint3>, 4> side_points;
		F(s, 4) for(MVertex* mv : side_mvertices[s]) side_points[s].pb(mv->point());
		V<SPoint3> newpoints;
		int n = S(side_points[0]), m = S(side_points[1]);
		if(n != 2 && m != 2)
			transfinite_interpolation(side_points[0], side_points[1], side_points[2], side_points[3], newpoints);
		V<V<MVertex*>> all_mv(n, V<MVertex*>(m));
		F(i, n) F(j, m) {
			if(i == 0) all_mv[i][j] = side_mvertices[3][m-1-j];
			else if(j == 0) all_mv[i][j] = side_mvertices[0][i];
			else if(i == n-1) all_mv[i][j] = side_mvertices[1][j];
			else if(j == m-1) all_mv[i][j] = side_mvertices[2][n-1-i];
			else {
				double guess[2];
				GPoint gp = gface->closestPoint(newpoints[(i-1)+(j-1)*(n-2)], guess);
				all_mv[i][j] = new MFaceVertex(gp.x(), gp.y(), gp.z(), gface, gp.u(), gp.v());
				gface2mvertices[gface].pb((MFaceVertex*)all_mv[i][j]); // needed?
			}
		}

		// Create MQuadrangles
		F(i, n-1) F(j, m-1) {
			MQuadrangle* mq = new MQuadrangle(all_mv[i][j], all_mv[i+1][j], all_mv[i+1][j+1], all_mv[i][j+1]);
			gface2mquads[gface].pb(mq);
			cface->mquads.pb(mq);
		}
	}

	// Delete old mesh and put new one into GModel
	gm->deleteMesh();

	// GVertices
	for(GVertex* gvertex : gm->getVertices())
		if(gvertex2mvertex.count(gvertex)) // in some cases a GVertex has no mesh vertex!
			gvertex->addMeshVertex(gvertex2mvertex[gvertex]);
	// GEdges
	for(GEdge* gedge : gm->getEdges()) {
		for(MEdgeVertex* mev : gedge2mvertices[gedge])
			gedge->addMeshVertex(mev);
		for(MLine* ml : gedge2mlines[gedge])
			gedge->addLine(ml);
	}
	// GFaces
	for(GFace* gface : gm->getFaces()) {
		for(MFaceVertex* mfv : gface2mvertices[gface]) {
			gface->addMeshVertex(mfv);
			GeoLog::add(mfv->point(), 0, "gface2mvertices");
		}
		for(MQuadrangle* mq : gface2mquads[gface])
			gface->addQuadrangle(mq);
	}
}

void optimizePatchQuantization(CMesh& CM) {
	V<V<CEdge*>> quadloops;
	map<CEdge*, int> cedge2quadloop;
	for(CEdge* cedge_start : CM.cedges) {
		if(!cedge2quadloop.count(cedge_start)) {
			double q = 0; int ne = 0;
			CEdge* cedge = cedge_start;
			quadloops.emplace_back();
			do {
				q += S(cedge->path);
				// if(cedge->gedge) {
				// 	// q += S(cedge->path);
				// 	q += cedge->gedge->length(cedge->gedge->getLowerBound(), cedge->gedge->getUpperBound());
				// 	++ne;
				// 	// cout << S(cedge->path) << ' ';
				// }
				quadloops.back().pb(cedge); cedge2quadloop[cedge] = S(quadloops)-1;
				cedge = cedge->cface->sides[(cedge->side+2)%4];
				quadloops.back().pb(cedge); cedge2quadloop[cedge] = S(quadloops)-1;
				cedge = cedge->oppo;
			} while(cedge != cedge_start);
			// cout << endl;
			q /= (S(quadloops.back()) / 2);
			for(CEdge* cedge : quadloops.back()) cedge->q = q;
			// for(CEdge* cedge : quadloops.back()) cedge->q = 10;
			
		}
	}

	Msg::Info("There are %d quad loops.", S(quadloops));
	
	map<GEdge*, set<int>> gedge2quadloops;
	for(CEdge* cedge : CM.cedges) {
		if(cedge->gedge) {
			gedge2quadloops[cedge->gedge].insert(cedge2quadloop[cedge]);
		}
	}

	// // Linear system of normal equations
	// int n = S(quadloops);
	// V<V<int>> A(n, V<int>(n, 0));
	// V<double> b(n, 0);
	// F(i, n) {
	// 	for(CEdge* cedge : quadloops[i]) {
	// 		if(cedge->gedge) {
	// 			for(int j : gedge2quadloops[cedge->gedge]) {
	// 				++A[i][j];
	// 			}
	// 			b[i] += cedge->gedge->length(cedge->gedge->getLowerBound(), cedge->gedge->getUpperBound());
	// 		}
	// 	}
	// }
	// cout << '[';
	// F(i, n) {
	// 	cout << '[';
	// 	F(j, n) cout << A[i][j] << ", ";
	// 	cout << "], ";
	// 	// cout << A[i] <<  "    " << b[i] << endl;
	// }
	// cout << ']' << endl;
	// cout << '[';
	// F(i,n) cout << b[i] << ", ";
	// cout << ']' << endl;

	// draw();


	F(i, S(quadloops)) {
		int color = rand();
		for(CEdge* cedge : quadloops[i])
			cedge->geolog(color, "quadloops");
	}
	H(S(quadloops));

	
	// OptimizeLengths* model = new OptimizeLengths(S(quadloops), gedge2quadloops);
	// Search::Options options;
	// // Search::TimeStop ts(100000);
	// // options.stop = &ts;
	// BAB<OptimizeLengths> engine(model, options);
	// delete model;
	// V<int> q;
	// while(OptimizeLengths* state = engine.next()) {
	// 	state->getSolution(q);
	// 	state->print();
	// }

	// Assign quantization to C-edges
	// V<int> q = {6, 1, 6, 2, 2, 5, 5, 8, 2};
	// V<int> q = {6, 3, 4, 4, 4, 3, 3, 3, 1}; // best for B0
	// V<int> q = {1, 3, 10, 1, 3, 8, 1, 4, 4, 2, 14, 3, 2, 2, 1, 4};
	// F(i, S(quadloops))
	// 	for(CEdge* cedge : quadloops[i])
			// cedge->q = q[i];
	
	// draw();
}

bool getConvexPatchSides(
    const std::vector<MElement*>& elts,
    const std::vector<MVertex*>& bnd,
    std::vector<std::vector<MVertex*> >& sides) {
  sides.clear();
  std::unordered_map<MVertex*,int> valence;
  for (MElement* e: elts) F(lv,e->getNumVertices()) {
    valence[e->getVertex(lv)] += 1;
  }
  F(i0,bnd.size()) if (valence[bnd[i0]] == 1) {
    sides.resize(sides.size()+1);

    F(inc,bnd.size()) {
      MVertex* v = bnd[(i0+inc)%bnd.size()];
      sides.back().push_back(v);
      if (inc > 0 && inc < bnd.size()-1 && valence[v] == 1) {
        sides.resize(sides.size()+1);
        sides.back().push_back(v);
      }
    }


    break;
  }

  return sides.size() > 0;
}

#define TRAN_QUA(c1, c2, c3, c4, s1, s2, s3, s4, u, v)                         \
  (1. - u) * c4 + u *c2 + (1. - v) * c1 + v *c3 -                              \
    ((1. - u) * (1. - v) * s1 + u * (1. - v) * s2 + u * v * s3 +               \
     (1. - u) * v * s4)

bool buildHighOrderQuadMeshFromBaseComplex(GModel* gm, CMesh& CM, int N) {
  vector<array<MVertex*,4> > patchCorners;
  vector<array<vector<SPoint3>,4> > patchPolylines;
  vector<GFace*> patchGFaces;
  unordered_map<MVertex*,GEntity*> cornerEntity;

  /* Collect info in current mesh */
  for(CFace* cface : CM.cfaces) {
    vector<MElement*> elts;
    for(MQuadrangle* quad : cface->mquads) {
      elts.push_back(quad);
    }

    std::vector<MVertex*> bnd;
    bool okb = buildBoundary(elts,bnd);
    if (!okb) {
      Msg::Error("failed to build patch boundary (should not happen)");
      return false;
    }
    if (bnd.back() != bnd.front()) { // ensure repetition of first vertex
      bnd.push_back(bnd.front());
    }
    std::vector<std::vector<MVertex*> > sides;
    bool oks = getConvexPatchSides(elts, bnd, sides);
    if (!oks || sides.size() != 4) {
      Msg::Error("failed to get 4 patch sides, got %li (should not happen)", sides.size());
      return false;
    }
    patchCorners.push_back({sides[0].front(), sides[1].front(), sides[2].front(), sides[3].front()});
    patchGFaces.push_back(cface->gface);
    patchPolylines.resize(patchPolylines.size()+1);
    F(k,4) {
      cornerEntity[sides[k].front()] = sides[k].front()->onWhat();
      F(lv,sides[k].size()) {
        patchPolylines.back()[k].push_back(sides[k][lv]->point());
      }
    }
  }

	// Build corners and put them in the GModel
	unordered_map<MVertex*,MVertex*> old2new;
  for (auto& kv: cornerEntity) {
    GEntity* ge = kv.second;
    MVertex* v = kv.first;
    MVertex* nv = nullptr;
    if (ge->dim() == 0) {
      nv = new MVertex(v->x(),v->y(),v->z(), ge);
    } else if (ge->dim() == 1) {
      double t = 0;
      if (dynamic_cast<MEdgeVertex*>(v)) {
        v->getParameter(0,t);
      }
      nv = new MEdgeVertex(v->x(),v->y(),v->z(),ge,t);
    } else if (ge->dim() == 2) {
      double uv0 = 0.;
      double uv1 = 0.;
      if (dynamic_cast<MFaceVertex*>(v)) {
        v->getParameter(0,uv0);
        v->getParameter(1,uv1);
      }
      nv = new MFaceVertex(v->x(),v->y(),v->z(),ge,uv0,uv1);
    }
    old2new[v] = nv;
  }

	// Delete old mesh and put new one into GModel
	gm->deleteMesh();

	// Create corners and coarse quads
  for (auto& kv: cornerEntity) {
    GEntity* ge = kv.second;
    MVertex* v = kv.first;
    MVertex* nv = old2new[v];
    ge->addMeshVertex(nv);
  }
  vector<std::pair<GFace*,size_t> > newQuadLocation(patchCorners.size());
  F(f,patchCorners.size()) {
    MVertex* v0 = old2new[patchCorners[f][0]];
    MVertex* v1 = old2new[patchCorners[f][1]];
    MVertex* v2 = old2new[patchCorners[f][2]];
    MVertex* v3 = old2new[patchCorners[f][3]];
    MQuadrangle* q = new MQuadrangle(v0,v1,v2,v3);
    patchGFaces[f]->addQuadrangle(q);
    newQuadLocation[f] = {patchGFaces[f],patchGFaces[f]->quadrangles.size()-1};
  }

  gm->setOrderN(N, true, false);

  /* Compute position of high-order nodes from patch polylines */
  F(f,newQuadLocation.size()) {
    GFace* gf = newQuadLocation[f].first;
    size_t idx = newQuadLocation[f].second;
    MQuadrangle* q = gf->quadrangles[idx];
    array<vector<SPoint3>,4> cs;
    F(le,4) {
      vector<MVertex*> vs;
      q->getEdgeVertices(le,vs);

      vector<SPoint3> newPts;
      compute_subdivided_edge_internal_points(patchPolylines[f][le],vs.size()-2,newPts);

      F(lv,newPts.size()) {
        vs[lv+2]->setXYZ(newPts[lv]);
      }

      newPts.insert(newPts.begin(),patchPolylines[f][le].front());
      newPts.push_back(patchPolylines[f][le].back());
      cs[le] = newPts;
    }

    // transfinite interpolation to get interior points
    fullMatrix<double> mat = gmshGenerateMonomialsQuadrangle(q->getPolynomialOrder());
    size_t E = q->getPolynomialOrder() - 1;
    for (size_t lv = 4+4*E; lv < q->getNumVertices(); ++lv) {
      double u = mat(lv,0) / double(E+1);
      double v = mat(lv,1) / double(E+1);
      SPoint3 c1u,c2v,c3u,c4v;
      sample_polyline(cs[0],u,c1u);
      sample_polyline(cs[1],v,c2v);
      sample_polyline(cs[2],1.-u,c3u); // 1-u because ordering inverted
      sample_polyline(cs[3],1.-v,c4v); // 1-v because ordering inverted
      SPoint3 pt = SPoint3(TRAN_QUA(c1u,c2v,c3u,c4v,cs[0][0],cs[1][0],cs[2][0],cs[3][0], u, v));
      q->getVertex(lv)->setXYZ(pt);

      if (gf->geomType() != GFace::Plane && gf->haveParametrization()) {
        double uv[2];
        GPoint proj = gf->closestPoint(q->getVertex(lv)->point(),uv);
        if (proj.succeeded()) {
          q->getVertex(lv)->setXYZ(proj.x(),proj.y(),proj.z());
          q->getVertex(lv)->setParameter(0,proj.u());
          q->getVertex(lv)->setParameter(1,proj.v());
        }
      }
    }
  }
  

  return true;
}


/*****************/
/* Main function */
/*****************/

void alignQuadMesh(GModel* gm) {

	int nit = 2;

	V<int> np;

	F(it, nit) {

		// Build MeshHalfEdges
		MeshHalfEdges M; buildMeshHalfEdgesFromGModel(gm, M);
		Msg::Info("M has %d faces, %d half-edges, and %d vertices.", S(M.faces), S(M.hedges), S(M.vertices));

		M.geolog("M");


		// Build T-Mesh
		TMesh TM(M, M_PI/4); // build
		// TMesh TM(M, 0); // build
		TM.geolog("T-mesh"); // draw
		Msg::Info("TM has %d T-faces, %d half-T-edges (%d T-edges), and %d T-vertices",
			S(TM.tfaces), S(TM.tedges), TM.nTEdges, S(TM.tvertices));

		// draw();
		

		// Quantization optimization (start from initial quantization)
	// Msg::Info("---------------------- Quantization starting from initial values -------------------");
		// V<int> q = optimizeQuantization(TM, 1);

		// Quantization optimization (start from 0)
	Msg::Info("---------------------- Quantization starting from 0 -------------------");
		V<int> q0 = optimizeQuantization(TM, 0);

		// Quantization optimization with LpSolve
	Msg::Info("---------------------- Quantization with lp_solve -------------------");
		V<int> q = optimizeQuantizationLpSolve(TM);

		if(S(q) == 0) return; // no quantization found :(

		// Draw T-edges with positive length
		for(TEdge* tedge : TM.tedges) if(q[tedge->id]) {
			tedge->geolog(q[tedge->id], "length > 0");
			if(q[tedge->id] > 1) tedge->geolog(0, "length > 1");
		}

		// Build coarse patches
		CMesh CM(TM, q);

		np.pb(S(CM.cfaces));

		// Optimize patch quantization
		optimizePatchQuantization(CM);

		
		// Build mesh
		buildMeshFromCMesh(CM, gm);

		// Sanity checks
		// Sanity check: no duplicate MVertices
		V<GEntity*> gentities; gm->getEntities(gentities);
		map<SPoint3, int> count_sp3;
		for(GEntity* ge : gentities) {
			for(MVertex* v : ge->mesh_vertices) {
				++count_sp3[v->point()];
				if(dynamic_cast<GFace*>(v->onWhat())) {
					GeoLog::add(v->point(), 0, "on GFace");
				}
			}
		}
		FIT(it, count_sp3) {
			if(it->second > 1) {
				Msg::Error("duplicate MVertices (%d)!", it->second);
				GeoLog::add(it->first, it->second, "!duplicates");
			}
		}

		v2t_cont adj;
		for(GFace* gf : gm->getFaces()) {
			buildVertexToElement(gf->quadrangles, adj);
		}

		FIT(it, adj) {
			GeoLog::add(it->first->point(), S(it->second), "#incident faces");
		}

		if(it == nit-1) {

			// Smooth mesh
			meshWinslow2d(gm, 1000);

			// Color quads by patch
			for(CFace* cface : CM.cfaces) {
				int color = rand();
				for(MQuadrangle* quad : cface->mquads) {
					geolog(quad, color, "patches");
					// GeoLog::add({}, color, "patches");
				}
			}
			// Color patch boundaries
			for(CEdge* cedge : CM.cedges)
				for(MLine* mline : cedge->mlines)
					geolog(mline, 0, "patches");
		}

    if (it == nit - 1) { // last iteration
      int N = 5;
      Msg::Info("Build high-order mesh ... (N = %i, %li quads)", N, CM.cfaces.size());
      buildHighOrderQuadMeshFromBaseComplex(gm, CM, N);
    }
	}

	H(np);


	draw();
}
