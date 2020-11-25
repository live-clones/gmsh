#include <iostream>

#include "GModel.h"

using namespace std;

void alignQuadMesh(GModel* gm) {
    // cout << gm->getNumRegions() << endl;
    // cout << gm->getNumFaces() << endl;
    // cout << gm->getNumEdges() << endl;
    // cout << gm->getNumVertices() << endl;

    set<GFace *, GEntityPtrLessThan> faces = gm->getFaces();
    for(GFace* face : faces) {
        vector<GVertex*> vertices = face->vertices();
        vector<MTriangle *> triangles = face->triangles;
        vector<MQuadrangle *> quads = face->quadrangles;
        cout << "face has " << vertices.size() << " vertices" << endl;
        cout << "face has " << triangles.size() << " triangles" << endl;
        cout << "face has " << quads.size() << " quads" << endl;
        cout << endl;
    }

    // cout << gm->getMaxVertexNumber() << endl;
    // auto gv = gm->viter();
}
