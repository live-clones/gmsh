// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// std
#include <ctime>
#include <queue>
using namespace std;

// Gecode
#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/minimodel.hh>
using namespace Gecode;

// gmsh
#include "gmsh.h"
#include "GModel.h"
#include "geolog.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "PView.h"
#include "Field.h"
#include "PViewDataList.h"

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

// Print vector
template<class T> ostream &operator<<(ostream &os, V<T> v) {
	F(i,S(v)) os<<(i?" ":"")<<v[i];
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

// Modulo that works for negative numbers (since (-a)%m == -(a%m))
int mod(int a, int m) { return (a % m + m) % m; }

// Constants
// Failed probes in compute_subdivided_edge_internal_points
const bool ERROR_VISU = true;

// Scaling applied on integer values storen in view (background field),
// so the visualization is not broken by the integers
constexpr double VIEW_INT_SCALING = 1.e-8;

// Initialize and run gmsh
void draw() {
	gmsh::initialize();
	GeoLog::flush();
	gmsh::fltk::run();
}

// Using the background field, extract the singularities of a given GFace,
// as a list of (coordinates, valence) pair.
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

// Declaration of structures related to MeshHalfEdges
struct MeshHalfEdges;
struct Vertex;
struct HalfEdge;
struct Face;

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
		int si = 0;
		for(Vertex* vertex : vertices) {
			if(vertex->valence != 4) {
				vertex->geolog(0, "irregular vertices");
				for(HalfEdge* hes : vertex->hedges) {
					HalfEdge* he = hes;
					while(he->v2->valence == 4) {
						he->geolog(si, "base complex");
						//he->geolog(si, "S"+to_string(si));
						he = he->next->oppo->next;
					}
					//he->geolog(si, "S"+to_string(si));
					he->geolog(si, "base complex");
					++si;
				}
			}
		}
	}

	// Constructor from GModel
	MeshHalfEdges(const GModel* gm) {
		map<MVertex*, Vertex*> mv2new; // map mesh vertices to new vertices
		map<pair<Vertex*,Vertex*>, HalfEdge*> vPair2he; // map pair of vertices to half-edge
		for(GFace* gf : gm->getFaces()) for(MQuadrangle* q : gf->quadrangles) {
			faces.pb(new Face); faces.back()->ptr = q;
			int nh = S(hedges); // number of half-edges
			F(k, 4) hedges.pb(new HalfEdge);
			F(k, 4) {
				MVertex* mv = q->getVertex(k);
				Vertex* vertex;
				if(!mv2new.count(mv)) { // new vertex
					vertex = new Vertex; vertices.pb(vertex);
					vertex->ptr = mv, vertex->valence = 0, vertex->isOnBoundary = false, vertex->isSingularity = false;
					vertex->isGVertex = (dynamic_cast<GVertex*>(mv->onWhat()) != NULL);
					vertex->isOnCAD = (vertex->isGVertex || dynamic_cast<GEdge*>(mv->onWhat()) != NULL);
					mv2new[mv] = vertex;
				} else
					vertex = mv2new[mv];

				// // Check if GVertex and/or on CAD 
				// if(dynamic_cast<GVertex*>(vertex->ptr->onWhat()) != NULL) vertex->isGVertex = vertex->isOnCAD = true;
				// if(dynamic_cast<GEdge*>(vertex->ptr->onWhat()) != NULL) vertex->isOnCAD = true; NULL;
				
				vertex->valence++;
				vertex->hedges.pb(hedges[nh+k]);
				hedges[nh+k]->face = faces.back();
				hedges[nh+k]->next = hedges[nh+mod(k+1,4)];
				hedges[nh+k]->prev = hedges[nh+mod(k-1,4)];
				hedges[nh+k]->gedge = NULL;
				hedges[nh+k]->oppo = NULL;
				hedges[nh+k]->v1 = vertex; // current vertex is tail of current he
				hedges[nh+mod(k-1,4)]->v2 = vertex; // current vertex is head of prev he
			}
			// Match opposite half-edges
			F(k, 4) {
				HalfEdge* he = hedges[nh+k];
				pair<Vertex*,Vertex*> v1v2 = {he->v1, he->v2}, v2v1 = {he->v2, he->v1};
				vPair2he[v1v2] = he;
				if(vPair2he.find(v2v1) != vPair2he.end()) { // if the opposite half-edge has been formed already
					he->oppo = vPair2he[v2v1];
					vPair2he[v2v1]->oppo = he;
				}
			}
			faces.back()->he = hedges[nh]; // any of the 4 half-edges will do
		}

		// Determine boundary and increase valence
		for(HalfEdge* he : hedges) if(he->oppo == NULL) {
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

		// Identify singularities and match them to corresponding irreg vertex
		for(GFace* gf : gm->getFaces()) {
			V<pair<SPoint3, int>> singularities;
			myGetSingularitiesFromBackgroundField(gf, singularities);
			for(auto p : singularities) {
				SPoint3 sing = p.first;
				int val = 4 - p.second;
				Vertex* closestVertex = NULL;
				double minDist = DBL_MAX;
				for(Vertex* v : vertices) {
					if(!v->isSingularity && v->valence == val) {
						double dist = v->ptr->point().distance(sing);
						if(closestVertex == NULL || dist < minDist) {
							closestVertex = v;
							minDist = dist;
						}
					}
				}
				closestVertex->isSingularity = true;
				closestVertex->geolog(0, "isSingularity");
			}
		}

	}
};

struct TEdge;

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
};

// Data structure for half-edge of T-mesh
struct TEdge {
	TFace* tface; // T-face on left of he
	TVertex *tvertex1, *tvertex2; // T-vertices at the endpoints
	TEdge* oppo; // opposite T-edge
	int len; // integer length
	HalfEdge* he; // first half-edge
	GEdge* gedge; // corresponding GEdge
	int id; // gecode identifier
	bool isStitch;
	void geolog(double value, const string& viewName) {
		HalfEdge* hei = he;
		F(i, len) {
			hei->geolog(value, viewName);
			if(i != len-1) hei = hei->next->oppo->next;
		}
	}
};

// // Data structure for a topological mesh,
// // where vertices are on the mesh but edges are not
// struct TopoMesh {
// 	V<Vertex*> vertices;
// 	V<TopoEdge*> edges;
// 	map<Vertex*, V<TopoEdge*>> adj; // adjacency list

// }

struct TraceHalfEdgesIntersection;
struct TraceIntersection;

// Trace described in MeshHalfEdges
struct TraceHalfEdges {
	Vertex* orig; // origin of trace (singular vertex)
	// Vertex* dest; // origin of trace that intersects (NULL if CAD)
	V<HalfEdge*> hedges; // sequence of half-edges forming the trace
	// V<TraceHalfEdgesIntersection*> intersections; // intersecting traces
	double alpha; // prescribed max deviation for this trace
	bool onLeft, onRight; // have we encountered a trace on left/right with angle < alpha ?
	// int listar; // distance between i and star, the first intersection with a trace that starts inside the pi/2 sector
	// int len; // total length the the trace
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

		// Draw trace origins
		for(Vertex* v : M.vertices) {
			if(v->valence != 4 || v->isGVertex) 
				v->geolog(0, "trace origins");
		}

		// draw();

		// Initialize traces
		// alpha = 0 when the origin of the trace is a GVertex!
		V<TraceHalfEdges*> hetraces; // traces, described using half-edges
		set<HalfEdge*> onTMesh; // set of half-edges lying on the T-mesh
		map<HalfEdge*, TraceHalfEdges*> hedge2trace; // map half-edge to trace it lies on
		map<HalfEdge*, int> hedge2index; // index of half-edge along trace (0,1,..)
		for(Vertex* vertex : M.vertices) {
			// If vertex is a singularity, or a GVertex
			if(vertex->isGVertex || vertex->isSingularity) {
				for(HalfEdge* he : vertex->hedges) {
					if(vertex->valence != 4 || he->gedge != NULL) { // if isGVertex, half-edge should lie on a GEdge
						// New trace!
						TraceHalfEdges* trace = new TraceHalfEdges;
						trace->orig = vertex;
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
					}
				}
			}
		}
		H(S(hetraces));
		
		// Draw onTMesh
		for(HalfEdge* he : onTMesh) he->geolog(0, "onTMesh");

		// Propagate traces
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
							if(t->orig->isSingularity && t->orig != trace->orig && hedge2index[hedgeLeft] <= tan(trace->alpha) * (hedge2index[he] + 1))
								trace->onRight = true;
						}
						if(hedgeRight != NULL && !trace->onLeft && hedge2trace.count(hedgeRight)) { // trace on the left
							TraceHalfEdges* t = hedge2trace[hedgeRight];
							if(t->orig->isSingularity && t->orig != trace->orig && hedge2index[hedgeRight] <= tan(trace->alpha) * (hedge2index[he] + 1))
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

		// draw();

		// Propagate streamlines from remaining irregular vertices (3-5's)
		for(Vertex* vertex : M.vertices) {
			if(!vertex->isGVertex && !vertex->isSingularity && vertex->valence != 4) {
				for(HalfEdge* heStart : vertex->hedges) {
					HalfEdge* he = heStart;
					while(true) {
						onTMesh.insert(he);
						onTMesh.insert(he->oppo);
						HalfEdge *hedgeLeft = he->next, *hedgeRight = he->oppo->prev->oppo;
						if(he->v2->valence != 4 || he->v2->isGVertex || onTMesh.count(hedgeLeft) || onTMesh.count(hedgeRight))
							break;
						he = he->next->oppo->next;
					}
				}
			}
		}

		P("done propagating traces");

		// Draw traces
		for(TraceHalfEdges* trace : hetraces) trace->geolog(rand(), "hetraces");

		// Draw onTMesh
		for(HalfEdge* he : onTMesh) he->geolog(0, "onTMesh");

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

		// Draw T-faces
		for(TFace* tface : tfaces) tface->geolog(rand(), "T-faces");

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
		P("done building T-edges");

		H(nTEdges);
		H(S(tedges));

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
			traces.pb(trace);
		}

		// Build intersections and istar
		F(itrace, S(traces)) {
			// P("treating trace " + to_string(itrace));
			Trace* trace = traces[itrace];
			// trace->geolog(0, "intersections of trace " + to_string(itrace));
			// H(S(trace->tedges));
		// for(Trace* trace : traces) {
			trace->istar = -1; // not found yet
			F(i, S(trace->tedges)) {
				TEdge* tedge = trace->tedges[i];
				if(tedge->tvertex2->isSingular || tedge->tvertex2->isGVertex) continue;
				// H(i);
				// Determine last half-edge
				HalfEdge* he = tedge->he;
				F(k, tedge->len-1) he = he->next->oppo->next;
				HalfEdge *heLeft = he->next->oppo, *heRight;
				//  = he->oppo->prev;
				if(hedge2trace.count(heLeft)) { // there's an intersection on the left
					Trace* t = hetrace2trace[hedge2trace[heLeft]];
					// H(t);
					int j = t->tedge2index[hedgemap[heLeft]];
					if(trace->istar == -1 && t->len[j] < trace->len[i])  { // we have found istar :-)
						trace->istar = i; 
						he->v2->geolog(0, "istar");
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
					if(trace->istar == -1 && t->len[j] < trace->len[i]) { // we have found istar :-)
						trace->istar = i; 
						he->v2->geolog(0, "istar");
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
			if(trace->istar == -1) {
				trace->istar = S(trace->tedges)-1;
			}
		}

		// Draw traces
		for(Trace* trace : traces)
			trace->geolog(rand(), "traces");
	}
	void geolog(const string& viewName) {
		for(TVertex* tvertex : tvertices) tvertex->geolog(0, viewName + " (vertices)");
		for(TEdge* tedge : tedges) tedge->geolog(0, viewName + " (edges)");
		for(TFace* tface : tfaces) tface->geolog(rand(), viewName + " (faces)");
	}
};

class OptimizeLengths : public IntMinimizeSpace {
	protected:
		IntVarArray l; // lengths of T-edges
		IntVarArray d; // diff between current and desired edge lengths
		IntVar costvar; // cost to minimize
		const TMesh& TM;
	public:
		OptimizeLengths(const TMesh& TM_, V<int> lens, V<int> target_lens) :
			l(*this, S(lens), 0, Int::Limits::max),
			d(*this, S(lens), 0, Int::Limits::max),
			costvar(*this, 0, Int::Limits::max),
			TM(TM_) {

			// Constrain zero and nonzero T-edges
			F(i, S(lens)) {
				if(lens[i])
					rel(*this, l[i] > 0);
				else
					rel(*this, l[i] == 0);
			}

			// Constrain opposite sides of T-faces to have equal length
			for(TFace* tface : TM.tfaces) {
				array<IntVarArgs,4> s; // 4 sides
				F(k, 4) {
					s[k] = IntVarArgs(S(tface->sides[k]));
					F(i, S(tface->sides[k]))
						s[k][i] = l[tface->sides[k][i]->id];
				}
				rel(*this, sum(s[0]) == sum(s[2]));
				rel(*this, sum(s[1]) == sum(s[3]));
			}



			// Cost function
			// F(i, S(lens)) rel(*this, d[i] == (l[i] - target_lens[i]) * (l[i] - target_lens[i])); // L2 norm
			F(i, S(lens)) rel(*this, d[i] == abs(l[i] - target_lens[i])); // L1 norm
			// for(TEdge* tedge : TM.tedges) rel(*this, d[tedge->id] == abs(l[tedge->id] - tedge->len)); // L1 norm
			// for(TEdge* tedge : TM.tedges) rel(*this, d[tedge->id] == (l[tedge->id] - tedge->len) * (l[tedge->id] - tedge->len)); // L2 norm
			rel(*this, costvar == sum(d));

			// Branching function
			Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_MIN()); // TODO: is there a smarter way?
		}
		// copier
		OptimizeLengths(OptimizeLengths& s) : IntMinimizeSpace(s), TM(s.TM) {
			l.update(*this, s.l);
			d.update(*this, s.d);
			costvar.update(*this, s.costvar);
		}
		virtual Space* copy(void) {
			return new OptimizeLengths(*this);
		}
		// printer
		void print(void) const {
			cout << l << ". Cost = " << costvar << endl;
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

// Gecode model
class AlignQuadMesh : public IntMinimizeSpace {
	protected:
		IntVarArray l; // lengths of T-edges
		IntVarArray d; // diff between current and desired edge lengths
		IntVarArray a; // area of each T-face
		IntVar nz; // number of T-edges with zero length
		IntVar costvar; // cost to minimize
		const TMesh& TM;
	public:
		AlignQuadMesh(const TMesh& TM_, int lmax) :
			l(*this, TM_.nTEdges, 0, lmax),
			// l(*this, TM_.nTEdges, 0, 44),
			// l(*this, TM_.nTEdges, 0, Int::Limits::max),
			d(*this, TM_.nTEdges, 0, Int::Limits::max),
			a(*this, S(TM_.tfaces), 0, Int::Limits::max),
			nz(*this, 0, TM_.nTEdges),
			costvar(*this, Int::Limits::min, Int::Limits::max),
			TM(TM_) {

			// // Constrain opposite T-edges to have the same length
			// for(TEdge* tedge : TM.tedges) {
			// 	rel(*this, l[tedge->id] == l[tedge->oppo->id]);
			// }

			// // Constrain GEdge's to have length > 0 (TODO: still necessary?)
			// for(auto it : TM.gedge2tedges) {
			// 	IntVarArgs g(S(it.second));
			// 	F(i, S(it.second)) g[i] = l[it.second[i]->id];
			// 	rel(*this, sum(g) > 0);
			// }

			for(TEdge* tedge : TM.tedges) {
				GEdge* gedge1 = dynamic_cast<GEdge*>(tedge->tvertex1->vertex->ptr->onWhat());
				GEdge* gedge2 = dynamic_cast<GEdge*>(tedge->tvertex2->vertex->ptr->onWhat());
				if(gedge1 != NULL && gedge2 != NULL && gedge1 != gedge2) {
					tedge->geolog(0, "T-edge forced > 0");
					rel(*this, l[tedge->id] > 0);
				}
			}

			// Constrain opposite sides of T-faces to have equal length
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
				rel(*this, a[f] == sum(s[0]) * sum(s[1]));
			}

			// Validity constraints
			for(Trace* trace : TM.traces) {
				// H(trace->orig);
				// if(trace->orig->vertex->valence == 4) continue; // ignore regular vertices
				// if(!trace->orig->vertex->isSingularity) continue; // ignore non-truly singular vertices
				// if(trace->istar == -1) continue;
				IntVarArgs s(trace->istar+1);
				// H(trace->istar+1)
				F(i, trace->istar+1) {
					// H(trace->tedges[i]->id);
					s[i] = l[trace->tedges[i]->id];
				}
				rel(*this, sum(s) > 0);
			}

			// Layout constraints
			// F(itrace, S(TM.traces)) {
			for(Trace* trace : TM.traces) {
				// Trace* trace = TM.traces[itrace];
				// if(!trace->orig->vertex->isSingularity) continue; // ignore non-truly singular vertices
				for(TraceIntersection* inters : trace->intersections) {	
					if(inters->t->len[inters->j] > tan(trace->alpha) * trace->len[inters->i]) {
						// New layout constraint
						IntVarArgs s(inters->j+1);
						F(i, inters->j+1)
							s[i] = l[inters->t->tedges[i]->id];
						rel(*this, sum(s) > 0);
					}
				}
			}

			// // Compute distance between all pairs of irregular vertices
			// map<TVertex*, map<TVertex*, int>> dist;
			// for(TVertex* tvertex : TM.tvertices) if(tvertex->isSingular && !isGVertex(tvertex->vertex)) { // we don't care about non-singular vertices!
			// 	// initialize dist[tvertex]
			// 	for(TVertex* v : TM.tvertices)
			// 		dist[tvertex][v] = (tvertex == v) ? 0 : INT_MAX;
			// 	priority_queue<pair<int,TVertex*>> pq; pq.push({0, tvertex});
			// 	while(S(pq)) {
			// 		pair<int,TVertex*> p = pq.top(); pq.pop();
			// 		TVertex* u = p.second; int du = -p.first;
			// 		if(dist[tvertex][u] < du) continue;
			// 		for(pair<TVertex*, TEdge*> pa : u->adj) {
			// 			TVertex* v = pa.first; TEdge* e = pa.second;
			// 			int dv = du + e->len;
			// 			if(dist[tvertex][v] > dv) {
			// 				dist[tvertex][v] = dv;
			// 				pq.push({-dv, v});
			// 			}
			// 		}
			// 	}
			// }

			// For every non-singularity irregular vertex, find its match and force collapse
			map<TVertex*, TVertex*> match;
			for(TVertex* tvertex : TM.tvertices) {
				// Vertex* vertex = tvertex->vertex;
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
					IntVarArgs p(S(path));
					int color = rand();
					F(i, S(path)) {
						p[i] = l[path[i]->id];
						path[i]->geolog(color, "paths connecting 3-5 pairs");
					}
					rel(*this, sum(p) == 0);
				}
			}

			// // Constrain traces to have positive length
			// for(Trace* trace : TM.traces) {
			// 	bool collapse = false;
			// 	if(trace->dest != NULL && trace->orig->isSingular && !isGVertex(trace->orig->vertex) && trace->dest->isSingular && !isGVertex(trace->dest->vertex) && dist[trace->orig][trace->dest] <= 2) {
			// 		P("pair of 3-5 detected!");
			// 		trace->geolog(rand(), "dist <= 2");
			// 		collapse = true;
			// 	}

			// 	IntVarArgs t(S(trace->tedges));
			// 	F(i, S(trace->tedges))
			// 		t[i] = l[trace->tedges[i]->id];
			// 	//if(collapse)
			// 		//rel(*this, sum(t) == 0);
			// 	//else
			// 		//rel(*this, sum(t) > 0);
			// 	if(!collapse)
			// 		rel(*this, sum(t) > 0);
			// }

			// P("done constraining traces to have positive length");

			// Constrain singularities to not collapse
			//int nc = 0;
			//int ns = 0;
			//set<TVertex*> done;
			//for(TVertex* tvertex : TM.tvertices) if(tvertex->isSingular &&
					//dynamic_cast<GVertex*>(tvertex->vertex->ptr->onWhat()) == NULL) {
				//done.insert(tvertex);
				//++ns;
				//queue<TVertex*> q; q.push(tvertex);
				//map<TVertex*, pair<TVertex*, TEdge*>> parent;
				//parent[tvertex] = {NULL,NULL};
				//while(S(q)) {
					//TVertex* u = q.front(); q.pop();
					//for(pair<TVertex*, TEdge*> p : u->adj) {
						//TVertex* v = p.first; TEdge* e = p.second;
						//if(!parent.count(v)) {
							//q.push(v);
							//parent[v] = {u,e};
						//}
					//}
				//}
				//for(TVertex* tvertex2 : TM.tvertices) {
					//if(!done.count(tvertex2) && tvertex2->isSingular &&
							//dynamic_cast<GVertex*>(tvertex2->vertex->ptr->onWhat()) == NULL) {
						//V<TEdge*> path;
						//TVertex* u = tvertex2;
						//while(u != tvertex) {
							//path.pb(parent[u].second);
							//u = parent[u].first;
						//}
						//int pathlen = 0;
						//IntVarArgs p(S(path));
						//F(i, S(path)) {
							//p[i] = l[path[i]->id];
							//pathlen += TM.tedges[path[i]->id]->len;
						//}
						//if(pathlen > 2)
							//rel(*this, sum(p) > 0);
						//++nc;
					//}
				//}
			//}
			//// Constrain singularities to not collapse on GEdges
			//for(TVertex* tvertex : TM.tvertices) if(tvertex->isSingular && dynamic_cast<GVertex*>(tvertex->vertex->ptr->onWhat()) == NULL) {
				//HalfEdge* hes = tvertex->vertex->he;
				//F(i, tvertex->vertex->valence) {
					//hes = hes->oppo->next;
					//V<TEdge*> path;
					//HalfEdge* he = hes;
					//while(true) {
						//TEdge* tedge = TM.hedgemap.at(he); // [] is not allowed since hedgemap is const
						//path.pb(tedge);
						//F(j, tedge->len) he = he->next->oppo->next;
						//if(he->v1->valence != 4 || dynamic_cast<GEdge*>(he->v1->ptr->onWhat()) != NULL) break;
					//}
					//IntVarArgs p(S(path));
					//F(i, S(path)) p[i] = l[path[i]->id];
					//rel(*this, sum(p) > 0);
				//}
			//}

			// Constrain stitches to have length > 0
			for(TEdge* tedge : TM.tedges)
				if(tedge->isStitch)
					rel(*this, l[tedge->id] > 0);

			// Cost function
			// rel(*this, costvar == sum(l)); // minimize sum of edge lengths
			// for(TEdge* tedge : TM.tedges) rel(*this, d[tedge->id] == abs(l[tedge->id] - tedge->len));
			// count(*this, l, 0, IRT_EQ, nz); // nz == number of zero length T-edges
			// rel(*this, costvar == 10000*(-nz) + sum(d));
			// rel(*this, costvar == -nz);
			rel(*this, costvar == sum(a));

			// Branching function
			// branch(*this, l, INT_VAR_SIZE_MIN(), INT_VAL_MIN()); // TODO: is there a smarter way?
			// Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_RND(rnd)); // TODO: is there a smarter way?
			Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_MIN()); // TODO: is there a smarter way?

			//// Merit function
			//auto m = [](const Space &home, IntVar x, int i) {
				//const AlignQuadMesh& model = static_cast<const AlignQuadMesh&>(home);
				//return model.TM.tedges[i]->len;
			//};
			//// First choose shortest edges and assign min value
			//branch(*this, l, INT_VAR_MERIT_MIN(m), INT_VAL_MIN());
			// First choose longest edges and assign min value
			//branch(*this, l, INT_VAR_MERIT_MAX(m), INT_VAL_MIN());

			P("done constructing AlignQuadMesh");
		}
		// copier
		AlignQuadMesh(AlignQuadMesh& s) : IntMinimizeSpace(s), TM(s.TM) {
			l.update(*this, s.l);
			d.update(*this, s.d);
			a.update(*this, s.a);
			nz.update(*this, s.nz);
			costvar.update(*this, s.costvar);
		}
		virtual Space* copy(void) {
			return new AlignQuadMesh(*this);
		}
		// printer
		void print(void) const {
			cout << "There are " << nz << " zero-length T-edges: " << l << ". Cost = " << costvar << endl;
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



struct Cluster {
	V<TVertex*> tvertices;
	int type; // 0 = regular, 1 = singular, 2 = GVertex, 3 = CAD (non-GVertex)
	Vertex* center;
	GFace* gface;
};

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

// Transfinite Interpolation, for computing interior points
bool transfinite_interpolation(
	const vector<SVector3>& c1,
	const vector<SVector3>& c2,
	const vector<SVector3>& c3,
	const vector<SVector3>& c4,
	vector<SVector3>& pts) {
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

  vector<SVector3> c1_u, c3_u, c2_v, c4_v;
  c1_u = std::vector<SVector3>(c1.begin()+1, c1.end()-1);
  c3_u = std::vector<SVector3>(c3.begin()+1, c3.end()-1);
  c2_v = std::vector<SVector3>(c2.begin()+1, c2.end()-1);
  c4_v = std::vector<SVector3>(c4.begin()+1, c4.end()-1);
  std::reverse(c3_u.begin(),c3_u.end());
  std::reverse(c4_v.begin(),c4_v.end());

  pts.resize(Ni*Nj);
  F(i,Ni) F(j,Nj) {
	double u = (1.+i) / (1.+Ni);
	double v = (1.+j) / (1.+Nj);
	pts[Ni*j+i] = (1.-v) * c1_u[i] + v * c3_u[i] + (1.-u) * c4_v[j] + u * c2_v[j]
	  - ((1.-u)*(1.-v)*c1[0] + u*v*c3[0] + u * (1.-v) * c2[0] + (1.-u)*v*c4[0]);
  }

  return true;
}



// Main function
void alignQuadMesh(GModel* gm) {

	// Build MeshHalfEdges
	MeshHalfEdges M(gm);

	// // Delete initial mesh (not needed anymore)
	// gm->deleteMesh();

	// Build T-Mesh
	TMesh TM(M, M_PI/6); // build
	TM.geolog("T-mesh"); // draw

	H(S(TM.tfaces));
	H(S(TM.tedges));
	H(S(TM.tvertices));

	// draw();

	// Initialize and run Gecode model
	P("building model");
	AlignQuadMesh* model = new AlignQuadMesh(TM, 2); // TODO: determine lmax
	// Search::TimeStop ts(30000);
	Search::TimeStop ts(2000);
	Search::Options options;
	options.stop = &ts;
	BAB<AlignQuadMesh> engine(model, options);
	delete model;
	P("running BAB...");
	clock_t start = clock();
	V<int> lens;
	while(AlignQuadMesh* state = engine.next()) {
		state->getSolution(lens);
		// int sum = 0; for(int i : solution) sum += i; // compute sum of edge lengths
		state->print();
		//cout << "solution (sum = " << sum << "): " << solution << endl;
	}
	if(S(lens) == 0) {
		P("no solution found :-(");
		return;
	}
	double elapsed = double(clock()-start) / CLOCKS_PER_SEC;
	H(elapsed);

	V<int> target_lens(TM.nTEdges);
	for(TEdge* tedge : TM.tedges)
		target_lens[tedge->id] = tedge->len;

	// OptimizeLengths* model2 = new OptimizeLengths(TM, lens, target_lens);
	// Search::TimeStop ts2(30000);
	// Search::Options options2;
	// options2.stop = &ts2;
	// BAB<OptimizeLengths> engine2(model2, options2);
	// delete model2;
	// P("running BAB...");
	// start = clock();
	// V<int> solution;
	// while(OptimizeLengths* state = engine2.next()) {
	// 	state->getSolution(solution);
	// 	state->print();
	// }
	// if(S(solution) == 0) {
	// 	P("no solution found :-(");
	// 	return;
	// }
	// elapsed = double(clock()-start) / CLOCKS_PER_SEC;
	// H(elapsed);
	V<int> solution = lens;
	

	// Draw T-edges with positive length
	for(TEdge* tedge : TM.tedges) if(solution[tedge->id]) {
		tedge->geolog(0, "length > 0");
		if(solution[tedge->id] > 1) tedge->geolog(0, "length > 1");
		//tedge->tface1->geolog(rand(), "area > 0");
		//tedge->tface2->geolog(rand(), "area > 0");
	}

	// Split T-edges with quantization > 1 and T-faces with area > 0
	TMesh TM2;
	TM2.tvertices = TM.tvertices; // copy T-vertices
	// Clear adj
	for(TVertex* tvertex : TM2.tvertices) tvertex->adj.clear();
	TM2.nTEdges = 0;
	map<TEdge*, V<TEdge*>> tedge2new;
	map<TEdge*, V<TVertex*>> tedge2tvertices; // OLD T-edge to NEW T-vertices
	map<TEdge*, V<int>> tedge2pos;
	int iface = 0;
	for(TFace* tface : TM.tfaces) {
		array<V<TVertex*>,4> side_tvertices; // T-vertices separating the NEW quantization
		array<V<int>, 4> side_pos; // integer position of T-vertices along side (in terms of OLD quantization)
		array<V<V<TEdge*>>, 4> side_tedges; // new T-edges grouped by new T-faces (separated by T-vertices in side_tvertices) 
		array<int, 4> side_len; // total length of each side
		F(s, 4) {
			int curr_pos = 0; // old quantization
			int curr_len = 0; // new quantization
			side_tvertices[s].pb(tface->sides[s].front()->tvertex1); // add corner
			side_pos[s].pb(0);
			side_tedges[s].pb(V<TEdge*>());
			
			side_len[s] = 0;
			for(TEdge* tedge : tface->sides[s])
				side_len[s] += solution[tedge->id];

			for(TEdge* tedge : tface->sides[s]) {
				// int sol = solution[tedge->id];
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
				V<int> pos;
				if(tedge2tvertices.count(tedge->oppo)) {
					tvertices = tedge2tvertices[tedge->oppo]; reverse(ALL(tvertices));
					pos = tedge2pos[tedge->oppo]; reverse(ALL(pos));
				} else {
					tvertices.pb(tedge->tvertex1);
					pos.pb(0); // pos of T-vertices alons T-edge
					FR(i, 1, solution[tedge->id]) {
						TVertex* tvertex = new TVertex;
						tvertex->vertex = vertices[i*tedge->len / solution[tedge->id]];
						tvertex->isSingular = false;
						tvertex->isGVertex = tvertex->vertex->isGVertex;
						tvertices.pb(tvertex);
						pos.pb(i*tedge->len / solution[tedge->id]);
						TM2.tvertices.pb(tvertex);
					}
					tvertices.pb(tedge->tvertex2);
					pos.pb(tedge->len);
					tedge2tvertices[tedge] = tvertices;
					tedge2pos[tedge] = pos;
				}

				// Create new T-edges
				V<TEdge*> newtedges;
				// int side_len = 0; // total side length
				F(i, max(1, solution[tedge->id])) {
					TEdge* newtedge = new TEdge;
					// newtedge->tface = tface;
					newtedge->tvertex1 = tvertices[i];
					newtedge->tvertex2 = tvertices[i+1];
					newtedge->len = min(1, solution[tedge->id]);
					newtedge->gedge = tedge->gedge;
					if(tedge2new.count(tedge->oppo)) {
						newtedge->oppo = tedge2new[tedge->oppo][max(1, solution[tedge->id])-1-i];
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
			// side_tvertices[s].back() = tface->sides[s].back()->tvertex2;
			// side_pos[s].back() = curr_pos;
			side_tvertices[s].pb(tface->sides[s].back()->tvertex2);
			side_pos[s].pb(curr_pos);

			H(S(side_tvertices[s]));
			H(side_pos[s]);
			H(S(side_tedges[s]));
		}

		// Create interior vertices and edges
		int nx = max(1, side_len[0]), ny = max(1, side_len[1]); // number of T-faces along dimension
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
		// // Interior T-vertices
		// FR(i, 1, nx) {
		// 	FR(j, 1, ny) {
		// 		int x1 = side_pos[0][i];
		// 		int x2 = side_pos[2][nx-i];
		// 		int y1 = side_pos[3][ny-j];
		// 		int y2 = side_pos[1][j];
		// 		int dx = x2 - x1, dy = y2 - y1;
		// 		int xs = nx * (dx*y1 + x1*ny) / (nx*ny - dx*dy);
		// 		int ys = ny * (dy*x1 + y1*nx) / (nx*ny - dx*dy);
		// 	}
		// }

		H(nx);
		H(ny);

		// H(side_len);
		F(s, 4) cout << side_len[s] << ' ';
		cout << endl;

		// Create faces and interior edges
		// TODO: oppo of interior edges
		F(i, nx) F(j, ny) {
			TFace* newtface = new TFace;
			newtface->gface = tface->gface;
			// Bottom edge
			if(j == 0)
				newtface->sides[0] = side_tedges[0][i];
			else {
				TEdge* tedge = new TEdge;
				tedge->tface = newtface;
				tedge->tvertex1 = tvertices[i][j];
				tedge->tvertex2 = tvertices[i+1][j];
				//tedge->oppo = TODO;
				tedge->gedge = NULL;
				tedge->len = (side_len[0] > 0);
				tedge->id = TM2.nTEdges++;
				TM2.tedges.pb(tedge);
				newtface->sides[0] = {tedge};
				tedge->tvertex1->adj.pb({tedge->tvertex2, tedge});
			}
			// Right edge
			if(i+1 == nx)
				newtface->sides[1] = side_tedges[1][j];
			else {
				TEdge* tedge = new TEdge;
				tedge->tface = newtface;
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
			if(j+1 == ny)
				newtface->sides[2] = side_tedges[2][nx-1-i];
			else {
				TEdge* tedge = new TEdge;
				tedge->tface = newtface;
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
			if(i == 0)
				newtface->sides[3] = side_tedges[3][ny-1-j];
			else {
				TEdge* tedge = new TEdge;
				tedge->tface = newtface;
				tedge->tvertex1 = tvertices[i][j+1];
				tedge->tvertex2 = tvertices[i][j];
				//tedge->oppo = TODO;
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

	H(TM2.nTEdges);
	H(S(TM2.tvertices));
	H(S(TM2.tedges));
	H(S(TM2.tfaces));

	set<Vertex*> sv;
	for(TVertex* tvertex : TM2.tvertices) {
		if(sv.count(tvertex->vertex)) {
			tvertex->geolog(0, "double");
			draw();
		}
		sv.insert(tvertex->vertex);
	}

	// for(TVertex* tvertex : TM2.tvertices) tvertex->geolog(rand(), "TM2 T-vertices");
	// for(TEdge* tedge : TM2.tedges) tedge->geolog(rand(), "TM2 T-edges");

	// TM2.geolog("TM2");
 
	for(TEdge* tedge : TM2.tedges) {
		GeoLog::add({tedge->tvertex1->vertex->ptr->point(), tedge->tvertex2->vertex->ptr->point()}, tedge->len, "topo edges");
	}
	for(TVertex* tvertex : TM2.tvertices) {
		tvertex->geolog(0, "topo vertices");
	}

	// Build new mesh

	// Merge T-vertices with distance 0 into clusters
	V<Cluster*> clusters;
	map<TVertex*, Cluster*> inCluster;
	int i = 0;
	for(TVertex* tvertex : TM2.tvertices) if(!inCluster.count(tvertex)) {
		tvertex->geolog(i++, "new cluster");
		Cluster* cluster = new Cluster; clusters.pb(cluster);
		cluster->tvertices.pb(tvertex);
		inCluster[tvertex] = cluster;
		queue<TVertex*> q; q.push(tvertex);
		while(S(q)) {
			TVertex* u = q.front(); q.pop();
			for(auto p : u->adj) {
				TVertex* v = p.first;
				// if(!inCluster.count(v) && solution[p.second->id] == 0) {
				if(!inCluster.count(v) && p.second->len == 0) {
					p.second->geolog(rand(), "adj");
					cluster->tvertices.pb(v);
					inCluster[v] = cluster;
					q.push(v);
				}
			}
		}
		// Determine type and center
		cluster->type = 0;
		cluster->gface = NULL;
		cluster->center = NULL;
		for(TVertex* tvertex : cluster->tvertices) {
			Vertex* vertex = tvertex->vertex;
			GEntity* gentity = vertex->ptr->onWhat();
			GFace* gf = dynamic_cast<GFace*>(gentity);
			if(gf != NULL) {
				cluster->gface = gf;
			}
			if(dynamic_cast<GVertex*>(gentity) != NULL) {
				cluster->type = 2;
				cluster->center = vertex;
				break; // since there can be only one GVertex per cluster
			} 
			if(dynamic_cast<GEdge*>(gentity) != NULL) {
				cluster->type = 3;
				cluster->center = vertex;
				// We don't break since there could be a GVertex in the cluster
			}
			if(cluster->center == NULL && tvertex->isSingular) { // non-geometric singularity
				cluster->type = 1;
				cluster->center = vertex;
				// break; // since there can be only one sing per cluster
			}
		}

		if(cluster->type == 0) // any vertex will do
			cluster->center = cluster->tvertices[0]->vertex;
			//centers.back() = clusters.back()[0]->vertex->ptr;
			//centers.back() = mean;
		GeoLog::add(SVector3(cluster->center->ptr->point()), cluster->type, "centers");
	}

	// Draw T-vertices, grouped by cluster
	for(Cluster* cluster : clusters) {
		int color = rand();
		for(TVertex* tvertex : cluster->tvertices)
			tvertex->geolog(color, "cluster");
	}

	// Construct minimal mesh
	map<pair<Cluster*,Cluster*>, V<Vertex*>> paths; // paths between clusters
	set<HalfEdge*> onMinMesh; // set of half-edges lying on the minimal mesh
	// add whole CAD to minmesh
	for(TEdge* tedge : TM2.tedges) if(tedge->gedge != NULL || tedge->isStitch) {
		HalfEdge* he = tedge->he;
		F(i, tedge->len) {
			onMinMesh.insert(he);
			if(i != tedge->len-1) he = he->next->oppo->next;
		}
	}

	// Assign pairs of clusters to corresponding GEdge
	map<pair<Cluster*, Cluster*>, GEdge*> clusterpair2gedge;
	for(TEdge* tedge : TM2.tedges) if(tedge->gedge != NULL) {
		Cluster *cluster1 = inCluster[tedge->tvertex1], *cluster2 = inCluster[tedge->tvertex2];
		clusterpair2gedge[{cluster1, cluster2}] = clusterpair2gedge[{cluster2, cluster1}] = tedge->gedge;
	}

	// Build new mesh
	
	// GVertices
	map<GVertex*, MVertex*> gvertex2mvertex;
	for(TVertex* tvertex : TM2.tvertices) if(tvertex->isGVertex) {
		MVertex* mv = tvertex->vertex->ptr;
		GVertex* gvertex = (GVertex*) mv->onWhat();
		MVertex* newmv = new MVertex(mv->x(), mv->y(), mv->z(), gvertex);
		gvertex2mvertex[gvertex] = newmv;
	}

	// for(GVertex* gvertex : gm->getVertices()) {
	// 	H(gvertex2mvertex[gvertex]);
	// 	// H(gvertex2mvertex.count(gvertex));
	// }
	// exit(0);

	map<GEdge*, V<MEdgeVertex*>> gedge2mvertices; // for every GEdge, we store its new mesh vertices
	map<GEdge*, V<MLine*>> gedge2mlines;
	set<pair<Cluster*, Cluster*>> processedClusterPairs;
	int totalArea = 0;
	for(TFace* tface : TM2.tfaces) {
		// First check if T-face has positive area (otherwise skip it)
		int area = 1;
		F(k,2) {
			int len = 0;
			for(TEdge* tedge : tface->sides[k])
				len += tedge->len;
				// len += solution[tedge->id];
			area *= len;
		}
		if(area == 0) continue;
		totalArea += area;
		tface->geolog(rand(), "area > 0");

		// Iterate on each side of the patch
		array<V<SVector3>,4> side_vertices; // vertices on sides of patch
		F(k,4) {
			int color = rand();
			for(TEdge* tedge : tface->sides[k]) { // for every T-edge on the side
				// tedge->geolog(rand(), "T-edge #" + to_string(cnt++));
				Cluster *cluster1 = inCluster[tedge->tvertex1], *cluster2 = inCluster[tedge->tvertex2];
				Vertex* center1 = cluster1->center, *center2 = cluster2->center;
				// If first T-edge, add vertex to side_vertices
				if(tedge == tface->sides[k].front())
					side_vertices[k].pb(cluster1->center->ptr->point());
				// If same cluster (i.e. tedge->len == 0), skip
				if(cluster1 == cluster2) continue;

				GEdge* gedge; GVertex *gvertex1, *gvertex2;
				if(clusterpair2gedge.count({cluster1, cluster2})) {
					gedge = clusterpair2gedge[{cluster1, cluster2}];
					gvertex1 = dynamic_cast<GVertex*>(center1->ptr->onWhat());
					gvertex2 = dynamic_cast<GVertex*>(center2->ptr->onWhat());
				} else
					gedge = NULL;

				V<Vertex*> path;
				if(paths.count({cluster2, cluster1})) { // path already exists
					path = paths[{cluster2,cluster1}];
					reverse(ALL(path));
				} else {
					map<Vertex*, Vertex*> parent; parent[center1] = NULL;
					V<Vertex*> q; q.pb(center1);
					while(true) {
						V<Vertex*> qn;
						bool done = false;
						for(Vertex* u : q) {
							for(HalfEdge* he : u->hedges) {
								Vertex* v = he->v2;
								// If path corresponds to a GEdge, force the path to stay on the GEdge
								if(gedge != NULL && v != center2 && dynamic_cast<GEdge*>(v->ptr->onWhat()) == NULL)
									continue;
								if(!parent.count(v)) {
									parent[v] = u;
									if(v == center2) {
										done = true;
										break;
									}
									qn.pb(v);
								}
							}
							if(done) break;
						}
						if(done) break;
						q = qn;
						// Sort q according to distance to center2
						sort(ALL(q), [center1, center2](Vertex* a, Vertex* b)->bool { return a->dist(center1) + a->dist(center2) <  b->dist(center1) + b->dist(center2); });
					}
					
					path.pb(center2);
					Vertex* u = center2;
					do {
						u = parent[u];
						path.pb(u);
						// P("coucou");
					} while(u != center1);
					reverse(ALL(path)); // center1 -> center2
					paths[{cluster1, cluster2}] = path;
					// paths[{cluster2, cluster1}] = path;
					FR(i, 1, S(path))
						GeoLog::add({SVector3(path[i-1]->ptr->point()), SVector3(path[i]->ptr->point())}, color, "minimal mesh");
				}
				// Path has been determined
				// H(S(path));
				// FR(i, 1, S(path))
				// 	GeoLog::add({SVector3(path[i-1]->ptr->point()), SVector3(path[i]->ptr->point())}, color, "minimal mesh");
				V<SPoint3> pts(S(path));
				F(i	, S(path)) pts[i] = path[i]->ptr->point();
				V<SPoint3> ipts;
				// int nb_ipts = 5 * solution[tedge->id] - 1;
				int nb_ipts = 5 * tedge->len - 1;
				compute_subdivided_edge_internal_points(pts, nb_ipts, ipts);
				// Add first and last point
				// if(tedge == tface->sides[k].front()) {
				// 	ipts.insert(ipts.begin(), pts[0]);
				// }
				ipts.insert(ipts.begin(), pts[0]);
				ipts.pb(pts.back());

				FR(i, 1, S(ipts)) side_vertices[k].pb(ipts[i]);

				if(S(ipts) == 1) {
					tedge->geolog(0, "S(ipts) == 1");
				}

				FR(i, 1, S(ipts))
					GeoLog::add({ipts[i-1], ipts[i]}, tedge->id, "minimal mesh (resampled)");

				// draw();

				// If GEdge, create MEdgeVertices
				if(gedge != NULL && !processedClusterPairs.count({cluster1, cluster2})) { 
				// if(gedge != NULL && !gedge2mvertices.count(gedge)) {
					processedClusterPairs.insert({cluster1, cluster2});
					processedClusterPairs.insert({cluster2, cluster1});
					V<MVertex*> mvertices(S(ipts));
					// mvertices[0] = gvertex2mvertex[gvertex1];
					// GeoLog::add(gvertex2mvertex[gvertex1]->point(), 0, "gvertex1");
					FR(i, 0, S(ipts)) {
						if(i == 0 && gvertex1 != NULL) 
							mvertices[0] = gvertex2mvertex[gvertex1];
						else if(i == S(ipts)-1 && gvertex2 != NULL) 
							mvertices[S(ipts)-1] = gvertex2mvertex[gvertex2];
						else {
							double param;
							gedge->closestPoint(ipts[i], param);
							MEdgeVertex* mev = new MEdgeVertex(ipts[i].x(), ipts[i].y(), ipts[i].z(), gedge, param);
							gedge2mvertices[gedge].pb(mev);
							mvertices[i] = mev;
							// gedge->addMeshVertex(mev);
						}
					}
					// mvertices[S(ipts)-1] = gvertex2mvertex[gvertex2];
					H(gvertex2mvertex.count(gvertex2));
					H(gvertex2mvertex[gvertex2]);
					// GeoLog::add(gvertex2mvertex[gvertex2]->point(), 0, "gvertex2");
					// Create MLines
					FR(i, 1, S(ipts)) {
						MLine* ml = new MLine(mvertices[i-1], mvertices[i]);
						GeoLog::add({mvertices[i-1]->point(), mvertices[i]->point()}, 0, "ml");
						gedge2mlines[gedge].pb(ml);
					}
				}
			}
		}
		if(S(side_vertices[0]) != S(side_vertices[2]) || S(side_vertices[1]) != S(side_vertices[3])) {
			tface->geolog(0, "TFI fail");
			draw();
			
		}
		V<SVector3> ipts;
		if(S(side_vertices[0]) != 2 && S(side_vertices[1]) != 2)
			transfinite_interpolation(side_vertices[0], side_vertices[1], side_vertices[2], side_vertices[3], ipts);

		int n = S(side_vertices[0]), m = S(side_vertices[1]);
		V<V<SVector3>> apts(n, V<SVector3>(m)); // all points: side_vertices + ipts
		F(i, n) {
			F(j, m) {
				if(i == 0) apts[i][j] = side_vertices[3][m-1-j];
				else if(j == 0) apts[i][j] = side_vertices[0][i];
				else if(i == n-1) apts[i][j] = side_vertices[1][j];
				else if(j == m-1) apts[i][j] = side_vertices[2][n-1-i];
				else apts[i][j] = ipts[(i-1)+(j-1)*(n-2)];
				// Project on GFace
				GPoint proj = tface->gface->closestPoint(SPoint3(apts[i][j]), SPoint3(apts[i][j]));
				apts[i][j] = SVector3(proj.x(), proj.y(), proj.z());
			}
		}
		int color = rand();
		F(i,n) F(j,m) {
			if(i < n-1) GeoLog::add({apts[i][j], apts[i+1][j]}, 0, "new edges");
			if(j < m-1) GeoLog::add({apts[i][j], apts[i][j+1]}, 0, "new edges");
			if(i < n-1 && j < m-1) GeoLog::add({apts[i][j], apts[i+1][j], apts[i+1][j+1], apts[i][j+1]}, color, "new faces");
		}
	}

	// Put new mesh into GModel
	gm->deleteMesh();
	// GVertices
	for(GVertex* gvertex : gm->getVertices()) {
		// if(!gvertex2mvertex.count(gvertex)) exit(0);
		// assert(gvertex2mvertex.count(gvertex));
		GeoLog::add(gvertex2mvertex[gvertex]->point(), 0, "gvertices");
		// gvertex2mvertex[gvertex]->geolog("gvertices", 0);
		gvertex->addMeshVertex(gvertex2mvertex[gvertex]);
	}
	// GEdges
	for(GEdge* gedge : gm->getEdges()) {
		H(S(gedge2mvertices[gedge]));
		H(S(gedge2mlines[gedge]));
		for(MEdgeVertex* mev : gedge2mvertices[gedge]) {
			gedge->addMeshVertex(mev);
		}
		for(MLine* ml : gedge2mlines[gedge]) {
			// H(ml->getNumVertices());
			// GeoLog::add({ml->getVertex(0)->point(), ml->getVertex(1)->point()}, 0, "mev");
			gedge->addLine(ml);
		}
	}
	// GFaces


	draw();
}
