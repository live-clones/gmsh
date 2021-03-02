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

// Print vector
template<class T> ostream &operator<<(ostream &os, V<T> v) {
    F(i,S(v)) os<<(i?" ":"")<<v[i];
    return os;
}
// Print pair
template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1,T2> p) {
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

// Modulo that works for negative numbers (since (-a)%m == -(a%m))
int mod(int a, int m) { return (a % m + m) % m; }

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

struct TMesh {
    V<TFace*> tfaces;
    V<TEdge*> tedges;
    V<TVertex*> tvertices;
    map<HalfEdge*, TEdge*> hedgemap; // map half-edges to T-half-edges they lie on
    map<GEdge*, V<TEdge*>> gedge2tedges; 

    // Destructor
    ~TMesh() {
        for(TFace* tf : tfaces) delete tf;
        for(TEdge* the : tedges) delete the;
    }
    // Tmesh constructor from MeshHalfEdges
    // mode=0: streamlines stop when meeting a GEdge
    // mode=1: streamlines stop when meeting another streamline (Motorcycle Graph)
    TMesh(MeshHalfEdges &M, int mode) {
        // TODO: what if a GVertex is incident to only 2 GEdges? Normally there will be a warning :-)

        // Determine set of half-edges that lie on the T-mesh
        set<HalfEdge*> onTMesh; // set of half-edges lying on the T-mesh
        V<V<HalfEdge*>> streamlines;
        if(mode == 0) {
            // For every singular vertex that is NOT a geometric vertex,
            // trace streamlines until meeting another singular vertex or GEdge
            for(Vertex* vertex : M.vertices) {
                // If vertex is singular and not geometric (why?)
                if(vertex->valence != 4 && dynamic_cast<GVertex*>(vertex->ptr->onWhat()) == NULL) {
                    //H(vertex->valence);
                    HalfEdge* heStart = vertex->he;
                    F(i, vertex->valence) {
                        heStart = heStart->oppo->next;
                        HalfEdge* he = heStart;
                        while(true) {
                            //P("coucou");
                            onTMesh.insert(he);
                            onTMesh.insert(he->oppo);
                            //he->geolog(0, "onTMesh");
                            //he->oppo->geolog(0, "onTMesh");
                            // If we land on a singular vertex or geometric edge: stop
                            if(he->v2->valence != 4 || dynamic_cast<GEdge*>(he->v2->ptr->onWhat()) != NULL || dynamic_cast<GVertex*>(he->v2->ptr->onWhat()) != NULL) break;
                            he = he->next->oppo->next;
                        }
                    }
                }
            }

            // Add geometric edges
            for(HalfEdge* he : M.hedges) 
                if(he->gedge != NULL) 
                    onTMesh.insert(he);
        } else if(mode == 1) {
            for(Vertex* vertex : M.vertices) {
                // If vertex is singular and not geometric
                if(vertex->valence != 4 && dynamic_cast<GVertex*>(vertex->ptr->onWhat()) == NULL) {
                    HalfEdge* he = vertex->he;
                    F(i, vertex->valence) {
                        he = he->oppo->next;
                        streamlines.pb({he});
                        onTMesh.insert(he);
                        onTMesh.insert(he->oppo);
                    }
                }
            }
            H(S(streamlines));
            // Add geometric edges
            for(HalfEdge* he : M.hedges) 
                if(he->gedge != NULL) 
                    onTMesh.insert(he);
            // Extend streamlines
            while(true) {
                bool done = true;
                F(i, S(streamlines)) {
                    HalfEdge* he = streamlines[i].back();
                    if(he->v2->valence != 4) continue;
                    if(onTMesh.count(he->next) && onTMesh.count(he->oppo->prev)) continue;
                    done = false;
                    HalfEdge* next = he->next->oppo->next;
                    streamlines[i].pb(next);
                    onTMesh.insert(next);
                    onTMesh.insert(next->oppo);
                }
                if(done) break;
            }
        }

        //// Draw onTMesh
        //for(HalfEdge* he : onTMesh) {
            //he->geolog(0, "onTMesh");
        //}
        
        // Draw streamlines
        F(i, S(streamlines)) {
            int color = rand();
            for(HalfEdge* he : streamlines[i])
                he->geolog(color, "streamlines");
        }

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
            //while(face2tface[he->face] == tface) // while we're still on the patch
                he = he->next->oppo->next;
            }
            he = he->next; // now he has origin at some corner of tface
            //he = he->prev->oppo; // now he has origin at some corner of p
            F(s, 4) { // for each side of the patch
                do {
                //while(!onTMesh.count(he->next)) {
                //while(face2tface[he->face] == tface) { // while we're still on the T-face
                    TFace* atface = face2tface[he->oppo->face]; // adjacent T-face
                    if(hedgemap.count(he)) { // If T-edge already exists
                        TEdge* tedge = hedgemap[he];
                        tface->sides[s].pb(tedge);
                        F(i, tedge->len) he = he->next->oppo->next;
                        //while(face2tface[he->face] == tface && face2tface[he->oppo->face] == atface) {
                            //he = he->next->oppo->next;
                        //}
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
                            //P("coucou");
                            tedge->len++;
                            hedgemap[he] = tedge;
                            hedgemap[he->oppo] = tedge;
                            if(he->gedge != tedge->gedge)
                                P("WARNING: T-edge overlaps multiple GEdges!");
                            he = he->next->oppo->next;
                        } while(!onTMesh.count(he->prev) && !onTMesh.count(he->oppo->next));
                        //while(face2tface[he->face] == tface && face2tface[he->oppo->face] == atface) {
                            //tedge->len++;
                            //hedgemap[he] = tedge;
                            //hedgemap[he->oppo] = tedge;
                            //if(he->gedge != tedge->gedge)
                                //P("WARNING: T-edge overlaps multiple GEdges!");
                            //he = he->next->oppo->next;
                        //}
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
                    }
                //}
                } while(!onTMesh.count(he->prev));
                //he = he->next;
                he = he->prev->oppo;
            }
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
            l(*this, S(TM_.tedges), 0, Int::Limits::max), 
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
            // Constrain singularities to not collapse
            int nc = 0;
            int ns = 0;
            set<TVertex*> done;
            for(TVertex* tvertex : TM.tvertices) if(tvertex->isSingular &&
                    dynamic_cast<GVertex*>(tvertex->vertex->ptr->onWhat()) == NULL) {
                done.insert(tvertex);
                ++ns;
                queue<TVertex*> q; q.push(tvertex);
                map<TVertex*, pair<TVertex*, TEdge*>> parent;
                parent[tvertex] = {NULL,NULL};
                while(S(q)) {
                    TVertex* u = q.front(); q.pop();
                    for(pair<TVertex*, TEdge*> p : u->adj) {
                        TVertex* v = p.first; TEdge* e = p.second;
                        if(!parent.count(v)) {
                            q.push(v);
                            parent[v] = {u,e};
                        }
                    } 
                }
                for(TVertex* tvertex2 : TM.tvertices) {
                    if(!done.count(tvertex2) && tvertex2->isSingular &&
                            dynamic_cast<GVertex*>(tvertex2->vertex->ptr->onWhat()) == NULL) {
                        V<TEdge*> path;
                        TVertex* u = tvertex2;
                        while(u != tvertex) {
                            path.pb(parent[u].second);
                            u = parent[u].first;
                        }
                        int pathlen = 0;
                        IntVarArgs p(S(path));
                        F(i, S(path)) {
                            p[i] = l[path[i]->id];
                            pathlen += TM.tedges[path[i]->id]->len;
                        }
                        if(pathlen > 2)
                            rel(*this, sum(p) > 0);
                        ++nc;
                    }
                }
            }
            // Constrain singularities to not collapse on GEdges
            for(TVertex* tvertex : TM.tvertices) if(tvertex->isSingular && dynamic_cast<GVertex*>(tvertex->vertex->ptr->onWhat()) == NULL) {
                HalfEdge* hes = tvertex->vertex->he;
                F(i, tvertex->vertex->valence) {
                    hes = hes->oppo->next;
                    V<TEdge*> path;
                    HalfEdge* he = hes;
                    while(true) {
                        TEdge* tedge = TM.hedgemap.at(he); // [] is not allowed since hedgemap is const
                        path.pb(tedge);
                        F(j, tedge->len) he = he->next->oppo->next;
                        if(he->v1->valence != 4 || dynamic_cast<GEdge*>(he->v1->ptr->onWhat()) != NULL) break;
                    }
                    IntVarArgs p(S(path));
                    F(i, S(path)) p[i] = l[path[i]->id];
                    rel(*this, sum(p) > 0);
                }
            }
            // Constrain stitches to have length > 0
            for(TEdge* tedge : TM.tedges)
                if(tedge->isStitch)
                    rel(*this, l[tedge->id] > 0);
            
            //Cost function
            for(TEdge* tedge : TM.tedges)
                rel(*this, d[tedge->id] == abs(l[tedge->id] - tedge->len));
            //rel(*this, sumlen == sum(d)); // minimize distance to mesh
            rel(*this, costvar == sum(l)); // minimize sum of edge lengths
            count(*this, l, 0, IRT_EQ, nz); // nz == number of zero length T-edges
            //rel(*this, costvar == 1000*(-nz) + sum(d));

            // Branching function
            //branch(*this, l, INT_VAR_SIZE_MIN(), INT_VAL_MIN()); // TODO: is there a smarter way?
            Rnd rnd(42); branch(*this, l, INT_VAR_RND(rnd), INT_VAL_MIN()); // TODO: is there a smarter way?

            //// Merit function
            //auto m = [](const Space &home, IntVar x, int i) {
                //const AlignQuadMesh& model = static_cast<const AlignQuadMesh&>(home);
                //return model.TM.tedges[i]->len;
            //};
            //// First choose shortest edges and assign min value
            //branch(*this, l, INT_VAR_MERIT_MIN(m), INT_VAL_MIN());
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

// Main function
void alignQuadMesh(GModel* gm) {
    // Build MeshHalfEdges
    MeshHalfEdges M(gm);

    // Build T-Mesh
    TMesh TM(M, 0); // build
    TM.geolog("T-mesh"); // draw

    H(S(TM.tfaces));
    H(S(TM.tedges));
    H(S(TM.tvertices));

    for(TEdge* tedge : TM.tedges) 
        if(tedge->isStitch) P("stitch");

    //gmsh::initialize();
    //GeoLog::flush();
    //gmsh::fltk::run();
    
    P("building model");

    // Initialize and run Gecode model
    AlignQuadMesh* model = new AlignQuadMesh(TM);
    BAB<AlignQuadMesh> engine(model);
    delete model;

    //gmsh::initialize();
    //GeoLog::flush();
    //gmsh::fltk::run();

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

    // Measure time: Cpu

    for(TEdge* tedge : TM.tedges)
        cout << solution[tedge->id] - tedge->len << " ";
    cout << endl;

    // Draw T-edges with positive length
    for(TEdge* tedge : TM.tedges) {
        if(solution[tedge->id]) tedge->geolog(0, "length > 0");
    }

    // Merge T-vertices with distance 0
    V<V<TVertex*>> clusters;
    map<TVertex*, int> inCluster;
    V<bool> onCAD;
    V<SVector3> centers;
    for(TVertex* tvertex : TM.tvertices) if(!inCluster.count(tvertex)) {
        clusters.pb({tvertex});
        inCluster[tvertex] = S(clusters)-1;
        queue<TVertex*> q; q.push(tvertex);
        while(S(q)) {
            TVertex* u = q.front(); q.pop();
            for(auto p : u->adj) {
                TVertex* v = p.first;
                if(!inCluster.count(v) && solution[p.second->id] == 0) {
                    clusters.back().pb(v);
                    inCluster[v] = S(clusters)-1;
                    q.push(v);
                }
            }
        }
        // Determine onCAD and center
        onCAD.pb(false);
        centers.pb(SVector3(0.0));
        for(TVertex* tvertex : clusters.back()) {
            if(dynamic_cast<GVertex*>(tvertex->vertex->ptr->onWhat()) != NULL ||
               dynamic_cast<GEdge*>(tvertex->vertex->ptr->onWhat()) != NULL) {
                onCAD.back() = true;
                centers.back() = tvertex->vertex->ptr->point();
                break;
            } else if(tvertex->isSingular) {
                centers.back() = tvertex->vertex->ptr->point();
                break;
            } else {
                centers.back() += tvertex->vertex->ptr->point() * (1.0 / S(clusters.back()));
            }
        }
        GeoLog::add(centers.back(), onCAD.back(), "centers");
        //GeoLog::add(centers.back(), 0, "centers");
    }

    // Draw T-vertices, grouped by cluster
    for(V<TVertex*> cluster : clusters) {
        int color = rand();
        for(TVertex* tvertex : cluster) {
            tvertex->geolog(color, "clusters");
        }
    }


    //V<SVector3> centers(S(clusters));
    //V<bool> isSingle(S(clusters), false);
    //V<bool> isGVertex(S(clusters), false);
    //V<TVertex*> leader(S(clusters));
    //F(i, S(clusters)) {
        //centers[i] = SVector3(0.0);
        //for(TVertex* tvertex : clusters[i]) {
            //if(dynamic_cast<GVertex*>(tvertex->vertex->ptr->onWhat()) != NULL) {
                //isGVertex[i] = true;
            //}
            //if(tvertex->isSingular || isGVertex[i]) {
            ////if(tvertex->isSingular || dynamic_cast<GVertex*>(tvertex->vertex->ptr->onWhat()) != NULL) {
                //centers[i] = tvertex->vertex->ptr->point();
                //leader[i] = tvertex;
                //isSingle[i] = true;
                //break;
            //}
            //centers[i] += tvertex->vertex->ptr->point();
        //}
        //if(!isSingle[i])
            //F(k,3) centers[i][k] /= S(clusters[i]);
        //if(S(clusters[i]) == 1) isSingle[i] = true;
        //GeoLog::add(centers[i], 0, "centers");
    //}
    // Draw edges between centers (if not both on CAD)
    for(TVertex* tvertex : TM.tvertices) {
        for(auto p : tvertex->adj) {
            if(!onCAD[inCluster[tvertex]] || !onCAD[inCluster[p.first]])
            //if(isSingle[inCluster[tvertex]] && isSingle[inCluster[p.first]] && tvertex == leader[inCluster[tvertex]] && p.first == leader[inCluster[p.first]])
                //p.second->geolog(0, "minimal mesh");
            //else 
                GeoLog::add({centers[inCluster[tvertex]], centers[inCluster[p.first]]}, 0, "minimal mesh");
        }
    }
    P("coucou");
    // Draw CAD
    for(TEdge* tedge : TM.tedges)
        if(tedge->gedge != NULL || tedge->isStitch)
            tedge->geolog(0, "minimal mesh");
            //tedge->geolog(1, "minimal mesh");

    //// Choose views to show
    //PView* p = PView::getViewByName("T-mesh (faces)");
    //gmsh::option::setNumber("View["+std::to_string(p->getTag())+"].Visible", 0);

    
    gmsh::initialize();
    GeoLog::flush();
    gmsh::fltk::run();
}
