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
    else {
        std::cerr << "Unknown geometry: " << geometry << std::endl;
        return 1;
    }

    // Create the mesh
    gmsh::option::setNumber("Mesh.MeshSizeFactor", clscale);
    gmsh::model::mesh::generate(2);
    gmsh::fltk::run();

    // Project the mesh on a plane
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

    size_t iElement = elementTagToIndex.begin()->second;
    size_t iNodes[3] = {nodeTagToIndex[elementNodeTags[3 * iElement + 0]],
                        nodeTagToIndex[elementNodeTags[3 * iElement + 1]],
                        nodeTagToIndex[elementNodeTags[3 * iElement + 2]]};
    std::cout << "Element " << elementTags[iElement] 
              << ": nodes " << iNodes[0] << " " << iNodes[1] << " " << iNodes[2] << std::endl;
    SVector3 d0 = {coord[3 * iNodes[1] + 0] - coord[3 * iNodes[0] + 0],
                   coord[3 * iNodes[1] + 1] - coord[3 * iNodes[0] + 1],
                   coord[3 * iNodes[1] + 2] - coord[3 * iNodes[0] + 2]};
    SVector3 d1 = {coord[3 * iNodes[2] + 0] - coord[3 * iNodes[0] + 0],
                   coord[3 * iNodes[2] + 1] - coord[3 * iNodes[0] + 1],
                   coord[3 * iNodes[2] + 2] - coord[3 * iNodes[0] + 2]};
    d0.normalize();
    d1 = d1 - dot(d1, d0) * d0;
    d1.normalize();
    SVector3 n = crossprod(d0, d1);
    n.normalize();
    std::cout << "Normal: " << n.x() << " " << n.y() << " " << n.z() << std::endl;

    for (std::size_t i = 0; i < nodeTags.size(); i++) {
        SVector3 p = {coord[3 * i + 0], coord[3 * i + 1], coord[3 * i + 2]};
        p = p - dot(p, n) * n;
        gmsh::model::mesh::setNode(nodeTags[i], {p.x(), p.y(), p.z()}, {});
    }
    CTX::instance()->mesh.changed = ENT_ALL;
    gmsh::fltk::run();

    // Untangling
    std::vector<std::array<double, 2> > points(nodeTags.size());
    for (std::size_t i = 0; i < nodeTags.size(); i++) {
        SVector3 p = {coord[3 * i + 0], coord[3 * i + 1], coord[3 * i + 2]};
        double u = dot(p, d0);
        double v = dot(p, d1);
        points[i] = {u, v};
    }
    std::vector<bool> locked(nodeTags.size(), false);
    locked[iNodes[0]] = true; locked[iNodes[1]] = true; locked[iNodes[2]] = true;
    std::vector<std::array<uint32_t, 3> > triangles(elementTags.size());
    for (std::size_t i = 0; i < elementTags.size(); i++) {
        triangles[i] = {(unsigned) nodeTagToIndex[elementNodeTags[3 * i + 0]],
                        (unsigned) nodeTagToIndex[elementNodeTags[3 * i + 1]],
                        (unsigned) nodeTagToIndex[elementNodeTags[3 * i + 2]]};
    }
    std::vector<std::array<std::array<double, 2>, 3> > triIdealShapes;
    untangle_triangles_2D(points, locked, triangles, triIdealShapes, lambda, iterMaxInner, iterMaxOuter, iterFailMax, timeMax);

    for (std::size_t i = 0; i < nodeTags.size(); i++) {
        SVector3 p = points[i][0] * d0 + points[i][1] * d1;
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
