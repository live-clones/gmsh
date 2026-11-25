#include "matLocalMidSurfaceProjection.h"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {

void require(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

} // namespace

int main()
{
  try {
    const std::vector<std::pair<int, int>> classification = {
        {2, 10}, {2, 11}, {1, 20}, {0, 30}, {-1, -1}, {2, 12}};

    using matLocalMidSurfaceProjection::
        allOppositePairsAreSurfaceClassified;
    require(allOppositePairsAreSurfaceClassified(
                classification, {{0, 1}, {1, 5}}),
            "Two surface-classified opposite pairs were rejected");
    require(!allOppositePairsAreSurfaceClassified(
                classification, {{0, 2}}),
            "A curve-classified opposite point was accepted");
    require(!allOppositePairsAreSurfaceClassified(
                classification, {{0, 3}}),
            "A vertex-classified opposite point was accepted");
    require(!allOppositePairsAreSurfaceClassified(
                classification, {{0, 4}}),
            "An unclassified opposite point was accepted");
    require(!allOppositePairsAreSurfaceClassified(
                classification, {{0, 7}}),
            "An out-of-range opposite point was accepted");
    require(!allOppositePairsAreSurfaceClassified(classification, {}),
            "An empty opposite-pair set was accepted");

    using matLocalMidSurfaceProjection::Plane;
    using matLocalMidSurfaceProjection::RetainedVertexTopology;
    using matLocalMidSurfaceProjection::classifyRetainedVertexTopology;
    using matLocalMidSurfaceProjection::
        limitBoundaryProjectionDisplacementJump;
    using matLocalMidSurfaceProjection::planeMidwayBetween;
    using matLocalMidSurfaceProjection::projectOntoCommonLine;
    using matLocalMidSurfaceProjection::projectOntoEquidistantPointLine;
    using matLocalMidSurfaceProjection::projectedFanTriangleIsValid;
    using matLocalMidSurfaceProjection::projectOntoPlane;
    require(classifyRetainedVertexTopology({{2, 1}, {2, 1}, {2, 1}}) ==
                RetainedVertexTopology::RegularInterior,
            "A regular interior MAT vertex was not recognized");
    require(classifyRetainedVertexTopology({{1, 1}, {1, 1}, {2, 1}}) ==
                RetainedVertexTopology::SimpleBoundary,
            "A simple valence-one MAT boundary vertex was not recognized");
    require(classifyRetainedVertexTopology({{1, 1}}) ==
                RetainedVertexTopology::SimpleBoundary,
            "A valence-one endpoint was not recognized as boundary");
    require(classifyRetainedVertexTopology({{1, 1}, {2, 2}}) ==
                RetainedVertexTopology::Unsupported,
            "A boundary/triple-line endpoint was accepted as simple");
    require(classifyRetainedVertexTopology({{3, 1}}) ==
                RetainedVertexTopology::Unsupported,
            "A non-manifold retained edge was accepted");
    require(classifyRetainedVertexTopology({}) ==
                RetainedVertexTopology::Unsupported,
            "An isolated retained vertex was accepted");
    Plane lower;
    lower.origin = Eigen::Vector3d(2.0, -3.0, 0.0);
    lower.normal = Eigen::Vector3d(0.0, 0.0, 1.0);
    Plane upper;
    upper.origin = Eigen::Vector3d(-4.0, 7.0, 2.0);
    upper.normal = Eigen::Vector3d(0.0, 0.0, -1.0);
    Plane midway;
    require(planeMidwayBetween(lower, upper, midway),
            "Two parallel planes did not define a midway plane");
    const Eigen::Vector3d projected =
        projectOntoPlane(Eigen::Vector3d(8.0, 9.0, -5.0), midway);
    require(std::abs(projected.x() - 8.0) < 1e-14 &&
                std::abs(projected.y() - 9.0) < 1e-14 &&
                std::abs(projected.z() - 1.0) < 1e-14,
            "Projection between parallel planar one-rings is not exact");

    Plane side;
    side.origin = Eigen::Vector3d(2.0, 100.0, -40.0);
    side.normal = Eigen::Vector3d::UnitX();
    Plane top;
    top.origin = Eigen::Vector3d(-90.0, 50.0, 4.0);
    top.normal = Eigen::Vector3d::UnitZ();
    require(planeMidwayBetween(side, top, midway),
            "Two non-parallel planes did not define a midway plane");
    require(std::abs(midway.normal.dot(midway.origin) -
                     6.0 / std::sqrt(2.0)) < 1e-14,
            "The midway plane depends on tangential 1-ring centroids");

    Plane xPlane;
    xPlane.origin = Eigen::Vector3d(1.0, 20.0, -30.0);
    xPlane.normal = Eigen::Vector3d::UnitX();
    Plane yPlane;
    yPlane.origin = Eigen::Vector3d(-40.0, 2.0, 50.0);
    yPlane.normal = Eigen::Vector3d::UnitY();
    Eigen::Vector3d lineProjection;
    Eigen::Vector3d lineDirection;
    double lineRankRatio = -1.0;
    require(projectOntoCommonLine(
                Eigen::Vector3d(8.0, 9.0, 7.0), {xPlane, yPlane},
                lineProjection, lineDirection, &lineRankRatio),
            "Two independent bisectors did not define a common line");
    require((lineProjection - Eigen::Vector3d(1.0, 2.0, 7.0)).norm() <
                1e-14 &&
                std::abs(std::abs(lineDirection.z()) - 1.0) < 1e-14 &&
                std::abs(lineRankRatio) < 1e-14,
            "Projection onto a common bisector line is not exact");
    require(!projectOntoCommonLine(
                Eigen::Vector3d::Zero(), {xPlane, xPlane},
                lineProjection, lineDirection),
            "Parallel duplicate bisectors incorrectly defined a line");

    require(projectOntoEquidistantPointLine(
                Eigen::Vector3d(4.0, 5.0, 7.0),
                {Eigen::Vector3d(0.0, 0.0, 0.0),
                 Eigen::Vector3d(2.0, 0.0, 0.0),
                 Eigen::Vector3d(0.0, 2.0, 0.0)},
                lineProjection, lineDirection),
            "Three Voronoi generators did not define an equidistant line");
    require((lineProjection - Eigen::Vector3d(1.0, 1.0, 7.0)).norm() <
                1e-13 &&
                std::abs(std::abs(lineDirection.z()) - 1.0) < 1e-13,
            "Projection onto the three-point Voronoi line is wrong");

    bool limited = false;
    const Eigen::Vector3d filteredDisplacement =
        limitBoundaryProjectionDisplacementJump(
            Eigen::Vector3d::Zero(), Eigen::Vector3d(-1.0, 0.0, 0.0),
            Eigen::Vector3d(1.0, 0.0, 0.0),
            Eigen::Vector3d(0.0, 0.0, 0.1),
            Eigen::Vector3d(0.0, 0.0, 0.1),
            Eigen::Vector3d(0.0, 0.0, 2.0), 0.2, &limited);
    require(limited,
            "An isolated boundary projection spike was not limited");
    require(std::abs(filteredDisplacement.z() - 0.3) < 1e-14,
            "The boundary projection limiter used the wrong local scale");
    const Eigen::Vector3d smoothDisplacement =
        limitBoundaryProjectionDisplacementJump(
            Eigen::Vector3d::Zero(), Eigen::Vector3d(-1.0, 0.0, 0.0),
            Eigen::Vector3d(2.0, 0.0, 0.0),
            Eigen::Vector3d(0.0, 0.0, 0.0),
            Eigen::Vector3d(0.0, 0.0, 0.3),
            Eigen::Vector3d(0.0, 0.0, 0.1), 0.2, &limited);
    require(!limited &&
                (smoothDisplacement - Eigen::Vector3d(0.0, 0.0, 0.1))
                        .norm() < 1e-14,
            "A linearly varying boundary projection was modified");

    const Eigen::Vector3d triangleCenter(0.0, 0.0, 0.0);
    const Eigen::Vector3d triangleFirst(1.0, 0.0, 0.0);
    const Eigen::Vector3d triangleSecond(0.0, 1.0, 0.0);
    require(projectedFanTriangleIsValid(
                triangleCenter, triangleFirst, triangleSecond,
                triangleCenter + Eigen::Vector3d(2.0, -3.0, 4.0),
                triangleFirst + Eigen::Vector3d(2.0, -3.0, 4.0),
                triangleSecond + Eigen::Vector3d(2.0, -3.0, 4.0)),
            "A rigidly translated fan triangle was rejected");
    require(!projectedFanTriangleIsValid(
                triangleCenter, triangleFirst, triangleSecond,
                triangleCenter, triangleSecond, triangleFirst),
            "An inverted fan triangle was accepted");
    require(!projectedFanTriangleIsValid(
                triangleCenter, triangleFirst, triangleSecond,
                triangleCenter, 5.0 * triangleFirst,
                5.0 * triangleSecond),
            "An excessive local projection stretch was accepted");
    require(!projectedFanTriangleIsValid(
                triangleCenter, triangleFirst, triangleSecond,
                triangleCenter, 0.1 * triangleFirst,
                0.1 * triangleSecond),
            "An excessive local projection collapse was accepted");

    std::cout << "local mid-surface projection helpers passed\n";
    return 0;
  }
  catch(const std::exception &error) {
    std::cerr << "failed: " << error.what() << '\n';
    return 1;
  }
}
