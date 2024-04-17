#include <iostream>
#include <gmsh.h>
#include <gmsh/GmshDefines.h>
#include <gmsh/SVector3.h>
#include <gmsh/Context.h>
#include <gmsh/winslowUntangler.h>

void halfPipe()
{
    // Create the geometry
    double lc = 0.1;
    double dx = 1.;
    // int startTag = gmsh::model::geo::addPoint(-dx, 0, 0, lc);
    // int centerTag = gmsh::model::geo::addPoint(0, 0, 0, lc);
    // int endTag = gmsh::model::geo::addPoint(+dx, 0, 0, lc);
    // int arcTag = gmsh::model::geo::addCircleArc(startTag, centerTag, endTag, -1, 0, 1, 0);
    // gmsh::vectorpair outDimTags;
    // gmsh::model::geo::extrude({{1,arcTag}}, 0, dx, 0, outDimTags);
    // gmsh::model::geo::synchronize();

    int arcTag = gmsh::model::occ::addCircle(0, 0, 0, 1, -1, -M_PI/2, M_PI/2, {0, 1, 0});
    gmsh::vectorpair outDimTags;
    gmsh::model::occ::extrude({{1,arcTag}}, 0, dx, 0, outDimTags);
    gmsh::model::occ::synchronize();
}

void fold()
{
    // Create the geometry
    double lc = 0.1;
    double dx = 1., dy = 0.1;
    int is[4];
    is[0] = gmsh::model::geo::addPoint(-dx, +dy, 0, lc);
    is[1] = gmsh::model::geo::addPoint(+dx, +dy, 0, lc);
    is[2] = gmsh::model::geo::addPoint(-dx, -dy, 0, lc);
    is[3] = gmsh::model::geo::addPoint(+dx, -dy, 0, lc);
    int ls[3];
    ls[0] = gmsh::model::geo::addLine(is[0], is[1]);
    ls[1] = gmsh::model::geo::addLine(is[1], is[2]);
    ls[2] = gmsh::model::geo::addLine(is[2], is[3]);
    gmsh::vectorpair outDimTags;
    gmsh::model::geo::extrude({{1,ls[0]}, {1,ls[1]}, {1,ls[2]}}, 0, 0, dx, outDimTags);
    gmsh::model::geo::synchronize();
}

void hole()
{
    // Create the geometry
    double lc = 0.1;
    double dx = 1.0;
    int arcTag = gmsh::model::occ::addCircle(0, 0, 0, 1, -1, -M_PI/2, M_PI/2, {0, 1, 0});
    gmsh::vectorpair outDimTags;
    gmsh::model::occ::extrude({{1,arcTag}}, 0, dx, 0, outDimTags);

    // Create a sphere to cut a hole
    double radius = 0.3;
    int sphereTag = gmsh::model::occ::addSphere(0, dx/2, dx, radius);
    gmsh::model::occ::synchronize();

    // Cut the sphere from the extruded surface
    gmsh::vectorpair outDimTags2;
    std::vector<gmsh::vectorpair> outDimTags3;
    gmsh::model::occ::cut({{2, 1}}, {{3, sphereTag}}, outDimTags2, outDimTags3, -1, true, true);

    gmsh::model::occ::synchronize();
}

void plane()
{
    // Create the geometry
    double lc = 0.1;
    double dx = 1.;
    int is[2];
    is[0] = gmsh::model::geo::addPoint(-dx, 0, 0, lc);
    is[1] = gmsh::model::geo::addPoint(+dx, 0, 0, lc);
    int l = gmsh::model::geo::addLine(is[0], is[1]);
    gmsh::vectorpair outDimTags;
    gmsh::model::geo::extrude({{1,l}}, 0, 0, dx, outDimTags);
    gmsh::model::geo::synchronize();
}

int main(int argc, char* argv[])
{
    // Initialize Gmsh
    gmsh::initialize();

    // Create a new model
    gmsh::model::add("Model");

    std::string geometry = "halfPipe";
    double lambda = 1.;
    int iterMaxInner = 300;
    int iterMaxOuter = 100;
    int iterFailMax = 10;
    double timeMax = 9999.;
    double clscale = 1.;
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-g" && i + 1 < argc) {
            geometry = argv[i + 1];
        }
        else if (std::string(argv[i]) == "-l" && i + 1 < argc) {
            lambda = std::stod(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-i" && i + 1 < argc) {
            iterMaxInner = std::stoi(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-o" && i + 1 < argc) {
            iterMaxOuter = std::stoi(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-f" && i + 1 < argc) {
            iterFailMax = std::stoi(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-t" && i + 1 < argc) {
            timeMax = std::stod(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-clscale" && i + 1 < argc) {
            clscale = std::stod(argv[i + 1]);
        }
    }

    if (geometry == "halfPipe")
        halfPipe();
    else if (geometry == "fold")
        fold();
    else if (geometry == "hole")
        hole();
    else if (geometry == "plane")
        plane();
    else {
        std::cerr << "Unknown geometry: " << geometry << std::endl;
        return 1;
    }

    // Create the mesh
    gmsh::option::setNumber("Mesh.MeshSizeFactor", clscale);
    gmsh::model::mesh::generate(2);
    gmsh::fltk::run();

    std::vector<std::size_t> nodeTags;
    std::vector<double> coord, parametricCoord;
    gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord);
    std::map<size_t, size_t> nodeTagToIndex;
    for (std::size_t i = 0; i < nodeTags.size(); i++) {
        nodeTagToIndex[nodeTags[i]] = i;
    }

    std::vector<std::size_t> elementTags, elementNodeTags;
    gmsh::model::mesh::getElementsByType(MSH_TRI_3, elementTags, elementNodeTags);
    std::map<size_t, size_t> elementTagToIndex;
    for (std::size_t i = 0; i < elementTags.size(); i++) {
        elementTagToIndex[elementTags[i]] = i;
    }


    //
    // Get projection directions
    //
    // Average normal
    int PROJ_OPT = 1;
    SVector3 n = {0, 0, 0};
    if (PROJ_OPT == 0) {
        size_t iElement = elementTagToIndex.begin()->second;
        size_t iNodes[3] = {nodeTagToIndex[elementNodeTags[3 * iElement + 0]],
                            nodeTagToIndex[elementNodeTags[3 * iElement + 1]],
                            nodeTagToIndex[elementNodeTags[3 * iElement + 2]]};
        SVector3 d0 = {coord[3 * iNodes[1] + 0] - coord[3 * iNodes[0] + 0],
                    coord[3 * iNodes[1] + 1] - coord[3 * iNodes[0] + 1],
                    coord[3 * iNodes[1] + 2] - coord[3 * iNodes[0] + 2]};
        SVector3 d1 = {coord[3 * iNodes[2] + 0] - coord[3 * iNodes[0] + 0],
                    coord[3 * iNodes[2] + 1] - coord[3 * iNodes[0] + 1],
                    coord[3 * iNodes[2] + 2] - coord[3 * iNodes[0] + 2]};
        n = crossprod(d0, d1);
    }
    else if (PROJ_OPT == 1) {
        for (size_t i = 0; i < elementTags.size(); i++) {
            size_t iNodes[3] = {nodeTagToIndex[elementNodeTags[3 * i + 0]],
                                nodeTagToIndex[elementNodeTags[3 * i + 1]],
                                nodeTagToIndex[elementNodeTags[3 * i + 2]]};
            SVector3 d0 = {coord[3 * iNodes[1] + 0] - coord[3 * iNodes[0] + 0],
                           coord[3 * iNodes[1] + 1] - coord[3 * iNodes[0] + 1],
                           coord[3 * iNodes[1] + 2] - coord[3 * iNodes[0] + 2]};
            SVector3 d1 = {coord[3 * iNodes[2] + 0] - coord[3 * iNodes[0] + 0],
                           coord[3 * iNodes[2] + 1] - coord[3 * iNodes[0] + 1],
                           coord[3 * iNodes[2] + 2] - coord[3 * iNodes[0] + 2]};
            n += crossprod(d0, d1);
        }
        if (n == SVector3{0, 0, 0})
            n = {0, 0, 1};
    }
    else 
        n = {0, 0, 1};

    n.normalize();
    std::cout << "Normal: " << n.x() << " " << n.y() << " " << n.z() << std::endl;

    // u and v directions
    SVector3 du = {1, 0, 0};
    SVector3 dv = crossprod(n, du);
    if (norm(dv) < 1.e-6) {
        du = {0, 1, 0};
        dv = crossprod(n,du);
    }
    du = du - dot(du,n) * n;
    du.normalize();
    dv.normalize();
    std::cout << "du: " << du.x() << " " << du.y() << " " << du.z() << std::endl;
    std::cout << "dv: " << dv.x() << " " << dv.y() << " " << dv.z() << std::endl;


    //
    // Untangling
    //
    // Points
    std::vector<std::array<double, 2> > points(nodeTags.size());
    for (std::size_t i = 0; i < nodeTags.size(); i++) {
        SVector3 p = {coord[3 * i + 0], coord[3 * i + 1], coord[3 * i + 2]};
        double u = dot(p, du);
        double v = dot(p, dv);
        points[i] = {u, v};
    }

    // Locked points
    std::vector<bool> locked(nodeTags.size(), false);
    // size_t iElement = elementTagToIndex.begin()->second;
    // size_t iNodes[3] = {nodeTagToIndex[elementNodeTags[3 * iElement + 0]],
    //                     nodeTagToIndex[elementNodeTags[3 * iElement + 1]],
    //                     nodeTagToIndex[elementNodeTags[3 * iElement + 2]]};
    // locked[iNodes[0]] = true; locked[iNodes[1]] = true; // locked[iNodes[2]] = true;

    // Triangles
    std::vector<std::array<uint32_t, 3> > triangles(elementTags.size());
    for (std::size_t i = 0; i < elementTags.size(); i++) {
        triangles[i] = {(unsigned) nodeTagToIndex[elementNodeTags[3 * i + 0]],
                        (unsigned) nodeTagToIndex[elementNodeTags[3 * i + 1]],
                        (unsigned) nodeTagToIndex[elementNodeTags[3 * i + 2]]};
    }

    // Ideal shapes
    std::vector<std::array<std::array<double, 2>, 3> > triIdealShapes(elementTags.size());
    for (size_t i = 0; i < elementTags.size(); i++) {
        size_t iNodes[3] = {nodeTagToIndex[elementNodeTags[3 * i + 0]],
                            nodeTagToIndex[elementNodeTags[3 * i + 1]],
                            nodeTagToIndex[elementNodeTags[3 * i + 2]]};
        SVector3 d0 = {coord[3 * iNodes[1] + 0] - coord[3 * iNodes[0] + 0],
                        coord[3 * iNodes[1] + 1] - coord[3 * iNodes[0] + 1],
                        coord[3 * iNodes[1] + 2] - coord[3 * iNodes[0] + 2]};
        SVector3 d1 = {coord[3 * iNodes[2] + 0] - coord[3 * iNodes[0] + 0],
                        coord[3 * iNodes[2] + 1] - coord[3 * iNodes[0] + 1],
                        coord[3 * iNodes[2] + 2] - coord[3 * iNodes[0] + 2]};
        double dx0 = norm(d0);
        double dx1 = dot(d0,d1) / dx0;
        double dy1 = sqrt(dot(d1,d1) - dx1 * dx1);
        triIdealShapes[i][0] = {0, 0};
        triIdealShapes[i][1] = {dx0, 0};
        triIdealShapes[i][2] = {dx1, dy1};
    }

    untangle_triangles_2D(points, locked, triangles, triIdealShapes, lambda, iterMaxInner, iterMaxOuter, iterFailMax, timeMax);


    // Update the mesh
    for (std::size_t i = 0; i < nodeTags.size(); i++) {
        SVector3 p = points[i][0] * du + points[i][1] * dv;
        gmsh::model::mesh::setNode(nodeTags[i], {p.x(), p.y(), p.z()}, {});
    }
    CTX::instance()->mesh.changed = ENT_ALL;
    gmsh::fltk::run();

    // Save the untangled mesh
    gmsh::write("untangled.msh");

    // Finalize Gmsh
    gmsh::finalize();

    return 0;
}
