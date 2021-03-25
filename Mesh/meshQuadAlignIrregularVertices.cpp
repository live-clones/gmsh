// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <ctime>

// std
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
// TODO: replace this one
#define RFC(_COND,...) do { if (_COND) {error(__VA_ARGS__); return false;} } while(0)

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

const bool ERROR_VISU = true;

struct HalfEdge;
struct Face;

// Vertex data structure
struct Vertex {
    MVertex* ptr; // pointer to corresponding MVertex
    //SVector3 p; // coordinates (ptr->point())
    HalfEdge* he; // reference to one (arbitrary) half-edge (tail of arrow)
    int valence; // number of incident faces
    Vertex(MVertex* _ptr, HalfEdge* _he, int _valence) : ptr(_ptr), he(_he), valence(_valence) {}
    void geolog(double value, const string& viewName) {
        GeoLog::add((SVector3)ptr->point(), value, viewName);
    }
};

// Half-edge data structure
struct HalfEdge {
    HalfEdge *prev, *next, *oppo;
    Vertex *v1, *v2; // v1 = tail, v2 = head
    Face* face; // face to the left of half-edge
    GEdge* gedge; // GEdge on with the half-edge lies (if any)
    void geolog(double value, const string& viewName) {
        SVector3 p1 = v1->ptr->point(), p2 = v2->ptr->point();
        GeoLog::add({p1,p2}, value, viewName);
    }
};

// Face data structure
struct Face {
    MElement* ptr; // pointer to corresponding MElement (which is an MQuadrangle)
    HalfEdge* he; // reference to one half-edge of the face
    void geolog(double value, const string& viewName) {
        V<SVector3> pts(4);
        HalfEdge* hek = he;
        F(k,4) {
            pts[k] = hek->v1->ptr->point();
            hek = hek->next;
        }
        //V<double> values(4, value);
        GeoLog::add({pts[0], pts[1], pts[2], pts[3]}, value, viewName);
    }
};

// Data structure for a mesh represented by half-edges
struct MeshHalfEdges {
    V<Vertex*> vertices;
    V<HalfEdge*> hedges;
    V<Face*> faces;
    // Destructor
    ~MeshHalfEdges() {
        for(Vertex* v : vertices) delete v;
        for(HalfEdge* he : hedges) delete he;
        for(Face* f : faces) delete f;
    }
    // Constructor from GModel
    MeshHalfEdges(const GModel* gm) {
        // Extract quads from model
        V<MQuadrangle*> quads;
        for(GFace* gf : gm->getFaces())
            quads.insert(quads.end(), ALL(gf->quadrangles)); // append gf->quadrangles to quads

        map<MVertex*, Vertex*> mv2new; // map mesh vertices to new vertices
        map<pair<Vertex*,Vertex*>, HalfEdge*> vPair2he; // map pair of vertices to half-edge
        for(MQuadrangle* q : quads) {
            faces.pb(new Face); faces.back()->ptr = q;
            int nh = S(hedges);
            F(k, 4) hedges.pb(new HalfEdge);
            F(k, 4) {
                MVertex* mv = q->getVertex(k);
                if(mv2new.find(mv) == mv2new.end()) {
                    vertices.pb(new Vertex(mv, hedges[nh+k], 0)); // current vertex is tail of current he
                    mv2new[mv] = vertices.back();
                }
                mv2new[mv]->valence++;
                hedges[nh+k]->face = faces.back();
                hedges[nh+k]->next = hedges[nh+mod(k+1,4)];
                hedges[nh+k]->prev = hedges[nh+mod(k-1,4)];
                hedges[nh+k]->gedge = NULL;
                hedges[nh+k]->v1 = mv2new[mv]; // current vertex is tail of current he
                hedges[nh+mod(k-1,4)]->v2 = mv2new[mv]; // current vertex is head of prev he
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

        // Assign GEdge's to HalfEdge's
        H(S(gm->getEdges()));
        for(GEdge* gedge : gm->getEdges()) {
            H(gedge->getNumMeshElements());
            F(i, gedge->getNumMeshElements()) {
                MElement* mline = gedge->getMeshElement(i);
                HalfEdge* he = vPair2he[{mv2new[mline->getVertex(0)], mv2new[mline->getVertex(1)]}];
                he->gedge = gedge;
                he->oppo->gedge = gedge;
            }
        }
    }
    // Draw the base complex
    void geologBaseComplex() {
        int si = 0;
        for(Vertex* vertex : vertices) {
            if(vertex->valence != 4) {
                vertex->geolog(0, "irregular vertices");
                HalfEdge* hes = vertex->he;
                F(i, vertex->valence) {
                    hes = hes->oppo->next;
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
};

// Check if Vertex is a GVertex
bool isGVertex(Vertex* v) { return dynamic_cast<GVertex*>(v->ptr->onWhat()) != NULL; }
// Check if Vertex is on the CAD
bool isOnCAD(Vertex* v) { return isGVertex(v) || dynamic_cast<GEdge*>(v->ptr->onWhat()) != NULL; }

struct TEdge;

// Data structure for vertex of T-mesh
struct TVertex {
    Vertex* vertex;
    V<pair<TVertex*, TEdge*>> adj; // adjacency list
    bool isSingular;
    void geolog(double value, const string& viewName) { vertex->geolog(value, viewName); }
};

// Date structure for (quad) face of T-mesh
struct TFace {
    array<V<TEdge*>,4> sides; // sides of the T-face, composed of T-edges
    V<Face*> faces; // list of quads composing the T-face
    void geolog(double value, const string& viewName) {
        for(Face* face : faces) face->geolog(value, viewName);
    }
};

// Data structure for half-edge of T-mesh
struct TEdge {
    TFace *tface1, *tface2; // pointer to T-faces on left and right of he
    TVertex *tvertex1, *tvertex2; // T-vertices at the endpoints
    int len; // integer length
    HalfEdge* he; // first half-edge
    GEdge* gedge; // corresponding GEdge
    int id; // gecode identifier
    bool isStitch;
    void geolog(double value, const string& viewName) {
        HalfEdge* hei = he;
        F(i, len) {
            hei->geolog(value, viewName);
            hei = hei->next->oppo->next;
        }
    }
};

// Trace described in MeshHalfEdges
struct TraceHalfEdges {
    Vertex* orig; // origin of trace (singular vertex)
    Vertex* dest; // origin of trace that intersects (NULL if CAD)
    V<HalfEdge*> hedges; // sequence of half-edges forming the trace
};

// Trace described in T-mesh
struct Trace {
    TVertex* orig; // origin of trace (singular vertex)
    TVertex* dest; // origin of trace that intersects (NULL if CAD)
    V<TEdge*> tedges; // sequence of T-edges forming the trace
    void geolog(double value, string name) { for(TEdge* tedge : tedges) tedge->geolog(value, name); }
};

struct TMesh {
    V<TFace*> tfaces;
    V<TEdge*> tedges;
    V<TVertex*> tvertices;
    V<Trace*> traces;
    map<HalfEdge*, TEdge*> hedgemap; // map half-edges to T-half-edges they lie on
    map<GEdge*, V<TEdge*>> gedge2tedges;

    // Destructor
    ~TMesh() {
        for(TFace* tf : tfaces) delete tf;
        for(TEdge* the : tedges) delete the;
    }
    // Tmesh constructor from MeshHalfEdges
    TMesh(MeshHalfEdges &M) {
        // TODO: what if a GVertex is incident to only 2 GEdges? Normally there will be a warning :-)

        // Determine set of half-edges that lie on the T-mesh
        V<TraceHalfEdges*> hetraces; // traces, described using half-edges
        set<HalfEdge*> onTMesh; // set of half-edges lying on the T-mesh
        map<HalfEdge*, TraceHalfEdges*> hedge2trace; // map half-edge to trace it lies on
        for(Vertex* vertex : M.vertices) {
            // If vertex is singular and not GVertex
            if(vertex->valence != 4 && !isGVertex(vertex)) {
                HalfEdge* he = vertex->he;
                F(i, vertex->valence) {
                    he = he->oppo->next;
                    // New trace!
                    TraceHalfEdges* trace = new TraceHalfEdges;
                    trace->orig = vertex;
                    trace->hedges.pb(he);
                    hetraces.pb(trace);
                    hedge2trace[he] = trace;
                    // Insert half-edge (and its opposite) in T-mesh
                    onTMesh.insert(he);
                    onTMesh.insert(he->oppo);
                }
            }
        }
        H(S(hetraces));
        // Add geometric edges
        for(HalfEdge* he : M.hedges)
            if(he->gedge != NULL)
                onTMesh.insert(he);
        // Propagate traces
        set<TraceHalfEdges*> openTraces(ALL(hetraces)); // traces that still need to be propagated
        while(S(openTraces)) {
            for(TraceHalfEdges* trace : hetraces) {
                if(openTraces.count(trace)) { // if trace is not completed
                    HalfEdge* he = trace->hedges.back();
                    bool done = true;
                    if(he->v2->valence != 4) // irregular vertex
                        trace->dest = he->v2;
                    else if(hedge2trace.count(he->next)) // trace on the left
                        trace->dest = hedge2trace[he->next]->orig;
                    else if(hedge2trace.count(he->oppo->prev->oppo)) // trace on the right
                        trace->dest = hedge2trace[he->oppo->prev->oppo]->orig;
                    else if(isOnCAD(he->v2)) // hitting on the CAD
                        trace->dest = NULL;
                    else {
                        done = false;
                        HalfEdge* next = he->next->oppo->next;
                        trace->hedges.pb(next);
                        hedge2trace[next] = trace;
                        onTMesh.insert(next);
                        onTMesh.insert(next->oppo);
                    }
                    if(done) openTraces.erase(trace);
                }
            }
        }

        P("done propagating traces");

        //// Draw onTMesh
        //for(HalfEdge* he : onTMesh) {
            //he->geolog(0, "onTMesh");
        //}

        //gmsh::initialize();
        //GeoLog::flush();
        //gmsh::fltk::run();

        // Assign faces to T-faces
        map<Face*, TFace*> face2tface;
        for(Face* face : M.faces) {
            if(!face2tface.count(face)) { // if face has no parent yet
                TFace* tface = new TFace; tfaces.pb(tface);
                queue<Face*> q; // queue of faces
                q.push(face); face2tface[face] = tface;
                while(S(q)) {
                    Face* f = q.front(); q.pop();
                    tface->faces.pb(f);
                    HalfEdge* he = f->he;
                    F(k, 4) {
                        if(!onTMesh.count(he)) {
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

        P("done defining T-faces");

        // Check for periodic T-faces and split them
        set<TFace*> isTFaceProcessed;
        set<HalfEdge*> hedgesOnStitch;
        for(HalfEdge* hes : M.hedges) if(onTMesh.count(hes)) {
            TFace* tface = face2tface[hes->face]; // current T-face
            if(isTFaceProcessed.count(tface)) continue;
            isTFaceProcessed.insert(tface);
            HalfEdge* he = hes;
            while(face2tface[he->face] == tface) {
                he = he->next->oppo->next;
                if(he == hes) {
                    P("periodic T-face!");
                    he = he->next;
                    while(face2tface[he->face] == tface) {
                        onTMesh.insert(he);
                        onTMesh.insert(he->oppo);
                        hedgesOnStitch.insert(he);
                        hedgesOnStitch.insert(he->oppo);
                        he = he->next->oppo->next;
                    }
                    break;
                }
            }
        }

        P("done splitting periodic T-faces");

        // Build T-edges
        map<Vertex*, TVertex*> vertexmap; // map vertices to corresponding T-vertices
        isTFaceProcessed.clear();
        for(HalfEdge* hes : M.hedges) {
            if(!onTMesh.count(hes)) continue;
            TFace* tface = face2tface[hes->face]; // current T-face
            if(isTFaceProcessed.count(tface)) continue;
            isTFaceProcessed.insert(tface);
            HalfEdge* he = hes;
            while(!onTMesh.count(he->next)) { // while we're still on the T-face
                he = he->next->oppo->next;
            }
            he = he->next; // now he has origin at some corner of tface
            F(s, 4) { // for each side of the patch
                do {
                    TFace* atface = face2tface[he->oppo->face]; // adjacent T-face
                    if(hedgemap.count(he)) { // If T-edge already exists
                        TEdge* tedge = hedgemap[he];
                        tface->sides[s].pb(tedge);
                        F(i, tedge->len) he = he->next->oppo->next;
                    } else {
                        TEdge* tedge = new TEdge;
                        tedges.pb(tedge); tface->sides[s].pb(tedge);
                        tedge->he = he, tedge->len = 0, tedge->gedge = he->gedge,
                            tedge->tface1 = tface, tedge->tface2 = atface, tedge->id = S(tedges)-1,
                            tedge->isStitch = hedgesOnStitch.count(he);
                        if(tedge->gedge != NULL) gedge2tedges[tedge->gedge].pb(tedge);
                        if(!vertexmap.count(he->v1)) {
                            TVertex* tvertex = new TVertex; tvertices.pb(tvertex);
                            tvertex->vertex = he->v1;
                            vertexmap[he->v1] = tvertex;
                            tvertex->isSingular = (he->v1->valence != 4);
                        }
                        TVertex* tvertex1 = vertexmap[he->v1];
                        do {
                            tedge->len++;
                            hedgemap[he] = tedge;
                            hedgemap[he->oppo] = tedge;
                            if(he->gedge != tedge->gedge)
                                P("WARNING: T-edge overlaps multiple GEdges!");
                            he = he->next->oppo->next;
                        } while(!onTMesh.count(he->prev) && !onTMesh.count(he->oppo->next));
                        if(!vertexmap.count(he->v1)) { // not very elegant :-(
                            TVertex* tvertex = new TVertex; tvertices.pb(tvertex);
                            tvertex->vertex = he->v1;
                            vertexmap[he->v1] = tvertex;
                            tvertex->isSingular = (he->v1->valence != 4);
                        }
                        // Add T-edge to T-vertex adjacencies
                        TVertex* tvertex2 = vertexmap[he->v1];
                        tvertex1->adj.pb({tvertex2, tedge});
                        tvertex2->adj.pb({tvertex1, tedge});
                        tedge->tvertex1 = tvertex1;
                        tedge->tvertex2 = tvertex2;
                    }
                //}
                } while(!onTMesh.count(he->prev));
                he = he->prev->oppo;
            }
        }

        P("done building T-edges");

        // Build traces
        for(TraceHalfEdges* hetrace : hetraces) {
            Trace* trace = new Trace;
            trace->orig = vertexmap[hetrace->orig];
            trace->dest = vertexmap[hetrace->dest];
            for(HalfEdge* he : hetrace->hedges) {
                TEdge* tedge = hedgemap[he];
                if(trace->tedges.empty() || tedge != trace->tedges.back())
                    trace->tedges.pb(tedge);
            }
            traces.pb(trace);
        }

        // Draw traces
        for(Trace* trace : traces) {
            int color = rand();
            for(TEdge* tedge : trace->tedges)
                tedge->geolog(color, "traces");
        }
    }
    void geolog(const string& viewName) {
        for(TVertex* tvertex : tvertices) tvertex->geolog(0, viewName + " (vertices)");
        for(TEdge* tedge : tedges) tedge->geolog(0, viewName + " (edges)");
        for(TFace* tface : tfaces) tface->geolog(rand(), viewName + " (faces)");
    }
};

// Gecode model
class AlignQuadMesh : public IntMinimizeSpace {
    protected:
        IntVarArray l; // lengths of T-edges
        IntVarArray d; // diff between current and desired edge lengths
        IntVar nz; // number of T-edges with zero length
        IntVar costvar; // cost to minimize
        const TMesh& TM;
    public:
        AlignQuadMesh(const TMesh& TM_) :
            l(*this, S(TM_.tedges), 0, 10),
            //l(*this, S(TM_.tedges), 0, Int::Limits::max),
            d(*this, S(TM_.tedges), 0, Int::Limits::max),
            nz(*this, 0, S(TM_.tedges)),
            costvar(*this, Int::Limits::min, Int::Limits::max),
            TM(TM_) {


            // Constrain GEdge's to have length > 0
            for(auto it : TM.gedge2tedges) {
                IntVarArgs g(S(it.second));
                F(i, S(it.second)) g[i] = l[it.second[i]->id];
                rel(*this, sum(g) > 0);
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

            // Compute distance between all pairs of irregular vertices
            map<TVertex*, map<TVertex*, int>> dist;
            for(TVertex* tvertex : TM.tvertices) if(tvertex->isSingular && !isGVertex(tvertex->vertex)) { // we don't care about non-singular vertices!
                // initialize dist[tvertex]
                for(TVertex* v : TM.tvertices)
                    dist[tvertex][v] = (tvertex == v) ? 0 : INT_MAX;
                priority_queue<pair<int,TVertex*>> pq; pq.push({0, tvertex});
                while(S(pq)) {
                    pair<int,TVertex*> p = pq.top(); pq.pop();
                    TVertex* u = p.second; int du = -p.first;
                    if(dist[tvertex][u] < du) continue;
                    for(pair<TVertex*, TEdge*> pa : u->adj) {
                        TVertex* v = pa.first; TEdge* e = pa.second;
                        int dv = du + e->len;
                        if(dist[tvertex][v] > dv) {
                            dist[tvertex][v] = dv;
                            pq.push({-dv, v});
                        }
                    }
                }
            }

            // Constrain traces to have positive length
            for(Trace* trace : TM.traces) {
                bool collapse = false;
                if(trace->dest != NULL && trace->orig->isSingular && !isGVertex(trace->orig->vertex) && trace->dest->isSingular && !isGVertex(trace->dest->vertex) && dist[trace->orig][trace->dest] <= 2) {
                    P("pair of 3-5 detected!");
                    trace->geolog(rand(), "dist <= 2");
                    collapse = true;
                }

                IntVarArgs t(S(trace->tedges));
                F(i, S(trace->tedges))
                    t[i] = l[trace->tedges[i]->id];
                //if(collapse)
                    //rel(*this, sum(t) == 0);
                //else
                    //rel(*this, sum(t) > 0);
                if(!collapse)
                    rel(*this, sum(t) > 0);
            }

            P("done constraining traces to have positive length");

            //gmsh::initialize();
            //GeoLog::flush();
            //gmsh::fltk::run();

            //// Constrain singularities to not collapse
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
            rel(*this, costvar == sum(l)); // minimize sum of edge lengths
            for(TEdge* tedge : TM.tedges) rel(*this, d[tedge->id] == abs(l[tedge->id] - tedge->len));
            count(*this, l, 0, IRT_EQ, nz); // nz == number of zero length T-edges
            //rel(*this, costvar == 1000*(-nz) + sum(d));
            //rel(*this, costvar == -nz);

            // Branching function
            //branch(*this, l, INT_VAR_SIZE_MIN(), INT_VAL_MIN()); // TODO: is there a smarter way?
            //Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_RND(rnd)); // TODO: is there a smarter way?
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
            nz.update(*this, s.nz);
            costvar.update(*this, s.costvar);
        }
        virtual Space* copy(void) {
            return new AlignQuadMesh(*this);
        }
        // printer
        void print(void) const {
            cout << "There are " << nz << " zero-length T-edges: " << l << endl;
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

    // Build T-Mesh
    TMesh TM(M); // build
    TM.geolog("T-mesh"); // draw

    H(S(TM.tfaces));
    H(S(TM.tedges));
    H(S(TM.tvertices));



    // Initialize and run Gecode model
    P("building model");
    AlignQuadMesh* model = new AlignQuadMesh(TM);
    BAB<AlignQuadMesh> engine(model);
    delete model;
    P("running BAB...");
    clock_t start = clock();
    V<int> solution;
    while(AlignQuadMesh* state = engine.next()) {
        state->getSolution(solution);
        int sum = 0; for(int i : solution) sum += i; // compute sum of edge lengths
        state->print();
        //cout << "solution (sum = " << sum << "): " << solution << endl;
    }
    double elapsed = double(clock()-start) / CLOCKS_PER_SEC;
    H(elapsed);


    // Draw T-edges with positive length
    for(TEdge* tedge : TM.tedges) if(solution[tedge->id]) {
        tedge->geolog(0, "length > 0");
        //tedge->tface1->geolog(rand(), "area > 0");
        //tedge->tface2->geolog(rand(), "area > 0");
    }

    //set<TFace*> posarea(ALL(TM.tfaces));
    //for(TEdge* tedge : TM.tedges) if(solution[tedge->id] == 0) {
        //posarea.erase(tedge->tface1);
        //posarea.erase(tedge->tface2);
    //}
    //for(TFace* tface : posarea) tface->geolog(rand(), "area > 0");

    // Merge T-vertices with distance 0 into clusters
    V<Cluster*> clusters;
    //V<V<TVertex*>> clusters;
    map<TVertex*, Cluster*> inCluster;
    //V<int> type; // 0 = regular, 1 = singular, 2 = GVertex, 3 = CAD (non-GVertex)
    //V<MVertex*> centers;
    //V<GFace*> cluster2face;
    for(TVertex* tvertex : TM.tvertices) if(!inCluster.count(tvertex)) {
        Cluster* cluster = new Cluster; clusters.pb(cluster);
        cluster->tvertices.pb(tvertex);
        inCluster[tvertex] = cluster;
        queue<TVertex*> q; q.push(tvertex);
        while(S(q)) {
            TVertex* u = q.front(); q.pop();
            for(auto p : u->adj) {
                TVertex* v = p.first;
                if(!inCluster.count(v) && solution[p.second->id] == 0) {
                    cluster->tvertices.pb(v);
                    inCluster[v] = cluster;
                    q.push(v);
                }
            }
        }
        // Determine type and center
        cluster->type = 0;
        cluster->gface = NULL;
        for(TVertex* tvertex : cluster->tvertices) {
            Vertex* vertex = tvertex->vertex;
            GEntity* gentity = vertex->ptr->onWhat();
            GFace* gf = dynamic_cast<GFace*>(gentity);
            if(gf != NULL) {
                //P("GFace found!");
                cluster->gface = gf;
            }
            if(dynamic_cast<GVertex*>(gentity) != NULL) {
                cluster->type = 2;
                cluster->center = vertex;
                break; // since there can be only one GVertex per cluster
            } else if(dynamic_cast<GEdge*>(gentity) != NULL) {
                cluster->type = 3;
                cluster->center = vertex;
                // We don't break since there could be a GVertex in the cluster
            } else if(tvertex->isSingular) { // non-geometric singularity
                cluster->type = 1;
                cluster->center = vertex;
                break; // since there can be only one sing per cluster
            }
        }
        H(cluster->type);
        H(cluster->gface);

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
            tvertex->geolog(color, "clusters");
    }

    // Construct minimal mesh
    map<pair<Cluster*,Cluster*>, V<Vertex*>> paths; // paths between clusters
    set<HalfEdge*> onMinMesh; // set of half-edges lying on the minimal mesh
    // add whole CAD to minmesh
    for(TEdge* tedge : TM.tedges) if(tedge->gedge != NULL || tedge->isStitch) {
        HalfEdge* he = tedge->he;
        F(i, tedge->len) {
            onMinMesh.insert(he);
            he = he->next->oppo->next;
        }
    }

    for(TFace* tface : TM.tfaces) {
        // First check if T-face has positive area (otherwise skip it)
        bool positiveArea = true;
        F(k,4) {
            int len = 0;
            for(TEdge* tedge : tface->sides[k])
                len += solution[tedge->id];
            if(len == 0) positiveArea = false;
        }
        if(!positiveArea) continue;
        tface->geolog(rand(), "area > 0");

        array<V<SVector3>,4> side_vertices; // vertices on sides of patch
        array<Cluster*,4> corners;
        int color = rand();
        F(k,4) {
            for(TEdge* tedge : tface->sides[k]) {
                Cluster *cluster1 = inCluster[tedge->tvertex1], *cluster2 = inCluster[tedge->tvertex2];
                if(cluster1 == cluster2) continue;
                if(tface == tedge->tface2) // T-face is on wrong side of T-edge
                    swap(cluster1, cluster2);
                if(corners[k] == NULL) corners[k] = cluster1;
                int type1 = cluster1->type, type2 = cluster2->type;
                if(type1 > 1 && type2 > 2) { // if both on CAD
                    H(tedge->gedge);
                    H(tedge->tvertex1->vertex);
                    H(tedge->tvertex2->vertex);
                    H(cluster1->center);
                    H(cluster2->center);
                    cout << endl;
                }
                V<Vertex*> path;
                if(paths.count({cluster2, cluster1})) { // path already exists
                    path = paths[{cluster2,cluster1}];
                    reverse(ALL(path));
                } else {
                    Vertex* center1 = cluster1->center, *center2 = cluster2->center;
                    queue<Vertex*> q; q.push(center1);
                    map<Vertex*, Vertex*> parent; parent[center1] = NULL;
                    bool done = false;
                    bool bothOnCAD = (type1 > 1 && type2 > 1);
                    // Find shortest path on mesh between center1 and center2
                    while(!done && S(q)) {
                        Vertex* u = q.front(); q.pop();
                        HalfEdge* he = u->he;
                        F(k, u->valence) {
                            he = he->oppo->next;
                            Vertex* v = he->v2;
                            if(v == center2) {
                                parent[v] = u;
                                done = true; break;
                            }
                            if(isOnCAD(v) == bothOnCAD && !parent.count(v)) {
                                parent[v] = u;
                                q.push(v);
                            }
                        }
                    }

                    //if(parent[center2] == NULL) {
                        //center1->geolog(0, "fail");
                        //center2->geolog(1, "fail");
                        //gmsh::initialize();
                        //GeoLog::flush();
                        //gmsh::fltk::run();
                    //}

                    path.pb(center2);
                    Vertex* u = center2;
                    do {
                        u = parent[u];
                        path.pb(u);
                    } while(u != center1);
                    reverse(ALL(path)); // center1 -> center2
                    paths[{cluster1, cluster2}] = path;
                }
                // Path has been determined
                H(S(path));
                if(S(path)) {
                    V<SPoint3> pts(S(path));
                    F(i, S(path)) pts[i] = path[i]->ptr->point();
                    V<SPoint3> ipts;
                    int nb_ipts = 10 * solution[tedge->id];
                    H(nb_ipts);
                    H(S(pts));
                    bool oks = compute_subdivided_edge_internal_points(pts, nb_ipts, ipts);
                    // Add first and last point
                    ipts.insert(ipts.begin(), pts[0]);
                    ipts.pb(pts.back());

                    F(i, S(ipts)) side_vertices[k].pb(ipts[i]);

                    int color = rand();
                    FR(i, 1, S(ipts)) {
                        ostringstream name; name << "patch " << tface;
                        //GeoLog::add({SVector3(ipts[i-1]), SVector3(ipts[i])}, i, name.str());
                        //GeoLog::add({SVector3(path[i-1]->ptr->point()), SVector3(path[i]->ptr->point())}, color, "minimal mesh");
                    }
                }
            }
            //corners[k]->center->geolog(color, "corners");
        }
        H(S(side_vertices[0]));
        H(S(side_vertices[1]));
        H(S(side_vertices[2]));
        H(S(side_vertices[3]));
        V<SVector3> ipts;
        transfinite_interpolation(side_vertices[0], side_vertices[1], side_vertices[2], side_vertices[3], ipts);
        H(S(ipts));

        int n = S(side_vertices[0]), m = S(side_vertices[1]);
        V<V<SVector3>> apts(n, V<SVector3>(m)); // all points: side_vertices + ipts
        F(i, n) {
            F(j, m) {
                if(i == 0) apts[i][j] = side_vertices[3][m-1-j];
                else if(j == 0) apts[i][j] = side_vertices[0][i];
                else if(i == n-1) apts[i][j] = side_vertices[1][j];
                else if(j == m-1) apts[i][j] = side_vertices[2][n-1-i];
                else apts[i][j] = ipts[(i-1)+(j-1)*(n-2)];
            }
        }
        color = rand();
        F(i,n) F(j,m) {
            if(i < n-1) GeoLog::add({apts[i][j], apts[i+1][j]}, 0, "new edges");
            if(j < m-1) GeoLog::add({apts[i][j], apts[i][j+1]}, 0, "new edges");
            if(i < n-1 && j < m-1) GeoLog::add({apts[i][j], apts[i+1][j], apts[i+1][j+1], apts[i][j+1]}, color, "new faces");
        }
    }


    //set<pair<Cluster*,Cluster*>> connected; // pairs of clusters that are already connected
    //for(TVertex* tvertex1 : TM.tvertices) {
        //for(auto p : tvertex1->adj) {
            //TVertex* tvertex2 = p.first;
            //Cluster *cluster1 = inCluster[tvertex1], *cluster2 = inCluster[tvertex2];
            //if(cluster1 == cluster2 || connected.count({cluster1,cluster2}) || connected.count({cluster2,cluster1})) continue;
            //connected.insert({cluster1, cluster2});
            //int type1 = cluster1->type, type2 = cluster2->type;
            //if(type1 <= 1 || type2 <= 1) { // if not both on CAD
                //GFace* gf = (type1 <= 1) ? cluster1->gface : cluster2->gface;
                //Vertex* center1 = cluster1->center, *center2 = cluster2->center;
                //TEdge* tedge = p.second;

                //// Find shortest path on mesh between center1 and center2
                //queue<Vertex*> q; q.push(center1);
                //map<Vertex*, Vertex*> parent; parent[center1] = NULL;
                //bool done = false;
                //while(!done && S(q)) {
                    //Vertex* u = q.front(); q.pop();
                    //HalfEdge* he = u->he;
                    //F(k, u->valence) {
                        //he = he->oppo->next;
                        //Vertex* v = he->v2;
                        //if(v == center2) {
                            //parent[v] = u;
                            //done = true; break;
                        //}
                        //if(!isOnCAD(v) && !parent.count(v)) {
                            //parent[v] = u;
                            //q.push(v);
                        //}
                    //}
                //}

                //V<Vertex*> path; path.pb(center2);
                //Vertex* u = center2;
                //do {
                    //u = parent[u];
                    //path.pb(u);
                //} while(u != center1);

                //V<SPoint3> pts(S(path));
                //F(i, S(path)) pts[i] = path[i]->ptr->point();
                //V<SPoint3> ipts;
                //int nb_ipts = 10 * solution[tedge->id];
                //bool oks = compute_subdivided_edge_internal_points(pts, nb_ipts, ipts);
                //// Add first and last point
                //ipts.insert(ipts.begin(), pts[0]);
                //ipts.pb(pts.back());

                //int color = rand();
                //FR(i, 1, S(ipts)) {
                    //GeoLog::add({SVector3(ipts[i-1]), SVector3(ipts[i])}, color, "minimal mesh");
                    ////GeoLog::add({SVector3(path[i-1]->ptr->point()), SVector3(path[i]->ptr->point())}, color, "minimal mesh");
                //}

                //H(S(path));


                ////SPoint2 param1, param2;
                ////P("coucou");
                ////bool status1 = reparamMeshVertexOnFace(center1, gf, param1);
                ////bool status2 = reparamMeshVertexOnFace(center2, gf, param2);
                ////GPoint proj1 = gf->closestPoint(center1->point(), center1->point());
                ////GPoint proj2 = gf->closestPoint(center2->point(), center2->point());
                ////cout << param1 << endl;
                ////cout << proj1.u() << " " << proj1.v() << endl;
                ////cout << param2 << endl;
                ////cout << proj2.u() << " " << proj2.v() << endl;


                ////int n = 50;
                ////V<GPoint> curve(n+1);
                ////F(i,n+1) {
                    ////double lambda = (double)i/n;
                    ////SPoint2 param(proj1.u() * (1-lambda) + proj2.u() * (lambda), proj1.v() * (1-lambda) + proj2.v() * (lambda));
                    ////curve[i] = gf->point(param);
                    //////P(curve[i]);
                    //////cout << curve[i] << endl;
                ////}

                //////cout << gpoint1 << " " << gpoint2 << endl;
                ////cout << endl;

                ////// Draw curve
                ////FR(i,1,n+1) {
                    ////SVector3 p1(curve[i-1].x(), curve[i-1].y(), curve[i-1].z());
                    ////SVector3 p2(curve[i].x(), curve[i].y(), curve[i].z());
                    //////SVector3 p1(curve[i-1].x(), curve[i-1].y(), curve[i-1].z());
                    ////GeoLog::add({p1, p2}, 0, "minimal mesh");
                ////}
            //}
        //}
    //}
    
    //P("coucou");

    //// Draw CAD
    //for(TEdge* tedge : TM.tedges)
        //if(tedge->gedge != NULL || tedge->isStitch)
            //tedge->geolog(0, "minimal mesh");
            ////tedge->geolog(1, "minimal mesh");

    gmsh::initialize();
    GeoLog::flush();
    gmsh::fltk::run();
}
