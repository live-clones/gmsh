// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "gmsh.h"
#include "GModel.h"
#include "geolog.h"
#include "MQuadrangle.h"

// Some shortcuts
#define P(x) {if (debug) cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define DR(i,a,b) for (int i=(b); i-->(a);)
#define D(i,n) DR(i,0,n)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)
#define MA(a,v) a = max(a,v)
#define V vector
#define pb push_back
#define mt make_tuple
using namespace std;
const bool debug = 1;

// Print vector
template<class T> ostream &operator<<(ostream &os, V<T> v) {
    F(i,S(v)) os<<(i?" ":"")<<v[i];
    return os;
}

// Modulo that works for negative numbers (since (-a)%m == -(a%m))
int mod(int a, int m) { return (a % m + m) % m; }

// Declare half-edge
struct HalfEdge;

// Vertex data structure
struct Vertex {
    MVertex* ptr; // pointer to corresponding MVertex
    //SVector3 p; // coordinates (ptr->point())
    HalfEdge* he; // reference to one (arbitrary) half-edge (tail of arrow)
    bool isSingularity; // TODO: needed?
};

// Face data structure
struct Face {
    MQuadrangle* ptr; // pointer to corresponding MQuadrangle
    HalfEdge* he; // reference to one half-edge of the face
};

// Half-edge data structure
struct HalfEdge {
    HalfEdge *prev, *next, *oppo;
    Vertex *v1, *v2; // v1 = tail, v2 = head
    Face* face;
};

// Data structure for a mesh represented by half-edges
struct MeshHalfEdges {
    V<Vertex> vertices;
    V<HalfEdge> hedges;
    V<Face> faces;
};

// Build a MeshHalfEdge, given a GModel
int createMeshHalfEdges(const GModel* gm, MeshHalfEdges& M) {
    // Extract quads from model
    V<MQuadrangle*> quads;
    for(GFace* gf : gm->getFaces()) 
        quads.insert(quads.end(), ALL(gf->quadrangles)); // append gf->quadrangles to quads

    // Cleanup M
    M.vertices.clear(); //M.vertices.reserve(4*S(quads));
    M.hedges.clear();   //M.hedges.reserve(4*S(quads));
    M.faces.clear();    //M.faces.reserve(4*S(quads));

    map<MVertex*, Vertex*> mv2new; // map mesh vertices to new vertices
    map<pair<Vertex*,Vertex*>, HalfEdge*> vPair2he; // map pair of vertices to half-edge
    for(MQuadrangle* q : quads) {
        M.faces.pb({q, NULL});
        int nh = S(M.hedges); // number of half-edges
        M.hedges.resize(nh+4);
        F(k, 4) {
            MVertex* mv = q->getVertex(k);
            if(mv2new.find(mv) == mv2new.end()) {
                M.vertices.pb({mv, &(M.hedges[nh+k]), false}); // current vertex is tail of current he
                mv2new[mv] = &(M.vertices.back());
            }
            M.hedges[nh+k].face = &(M.faces.back());
            M.hedges[nh+k].next = &(M.hedges[nh+mod(k+1,4)]);
            M.hedges[nh+k].prev = &(M.hedges[nh+mod(k-1,4)]);
            //M.hedges[nh+k].oppo = NULL; // later
            M.hedges[nh+k].v1 = mv2new[mv]; // current vertex is tail of current he
            M.hedges[nh+mod(k-1,4)].v2 = mv2new[mv]; // current vertex is head of previous he:
        }
        // Match opposite half-edges
        //F(k, 4) {
            //HalfEdge* he = &(M.hedges[nh+k]);
            //pair<Vertex*,Vertex*> v1v2 = {he->v1, he->v2}, v2v1 = {he->v2, he->v1};
            //vPair2he[v1v2] = he;
            //if(vPair2he.find(v2v1) != vPair2he.end()) {
                //he->oppo = vPair2he[v2v1];
                //vPair2he[v2v1]->oppo = he;
            //}
        //}
        //M.faces.back().he = &(M.hedges[nh]); // any of the 4 half-edges will do
    }

    return 0;
}

// Main function
void alignQuadMesh(GModel* gm) {
    MeshHalfEdges M;
    createMeshHalfEdges(gm, M);

    //gmsh::initialize();
    //GeoLog::flush();
    //gmsh::fltk::run();
}

