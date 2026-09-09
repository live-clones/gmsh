#!/usr/bin/env python3
"""Exercise the native final V2 split on fixed planar and spherical quads."""
import argparse
import collections
import json
import math
import sys
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bindings", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()
    sys.path.insert(0, str(args.bindings.resolve()))
    import gmsh
    gmsh.initialize()
    assert gmsh.option.getNumber("Mesh.OptimizeQuadsFinalSplitCadDistanceRatio") == .2
    records = []
    try:
        for name in ("valid_plane", "concave_plane", "bowtie_plane", "near_flat", "near_flat_tt",
                     "sphere_02", "sphere_13", "sphere_below", "sphere_disabled", "sphere_no_gain",
                     "sphere_angle_cad"):
            gmsh.clear()
            gmsh.model.add(name)
            sphere = name.startswith("sphere")
            if sphere:
                gmsh.model.occ.addSphere(0, 0, 0, 1)
                gmsh.model.occ.synchronize()
                face = gmsh.model.getEntities(2)[0][1]
                uv = [(0.1, -0.4), (1., -0.35), (0.8, 0.3), (0.2, 0.2)]
                if name != "sphere_no_gain":
                    uv = [(.1, -.1), (.6, -.35), (1.1, -.1), (.6, .15)]
                if name == "sphere_13":
                    uv = uv[1:] + uv[:1]
                if name.startswith("sphere_angle_cad"):
                    # Convex UV patch: both triangle cuts satisfy absolute
                    # angles. 02 has a nicer minimum angle (30.8 vs 21.8 deg)
                    # but fits the sphere much worse (0.522 vs 0.161 maximum).
                    uv = [(0.9446935104177, -0.49459036228301095),
                          (2.004838977505863, -0.17689306305691),
                          (2.903548553680608, 0.600281611626578),
                          (1.8122584713971972, 0.18291995597179866)]
                xyz = [tuple(gmsh.model.getValue(2, face, p)) for p in uv]
            else:
                face = gmsh.model.occ.addRectangle(-5, -5, 0, 10, 10)
                gmsh.model.occ.synchronize()
                xy = [(0., 0.), (2., 0.), (2., 2.), (0., 2.)]
                if name == "concave_plane": xy[2] = (.5, .5)
                if name == "bowtie_plane": xy[1], xy[2] = xy[2], xy[1]
                if name.startswith("near_flat"):
                    xy = [(0., 0.), (1., -.01), (2., 0.), (1., 1.)]
                xyz = [(x, y, 0.) for x, y in xy]
                uv = [tuple(gmsh.model.getParametrization(2, face, p)) for p in xyz]
            distances = [max(1. - math.sqrt(sum(((1-t)*xyz[d][k] + t*xyz[d+2][k])**2
                          for k in range(3))) for t in (.25, .5, .75))
                         for d in range(2)] if sphere else [0., 0.]
            ratio = sum(distances)/2 if sphere else .1
            if name == "sphere_no_gain": ratio = min(distances) / 2
            if name == "sphere_below": ratio = max(distances) + .01
            if name == "sphere_disabled": ratio = -1
            gmsh.model.mesh.addNodes(2, face, [1, 2, 3, 4],
                                    [x for p in xyz for x in p], [x for p in uv for x in p])
            if name == "near_flat_tt":
                gmsh.model.mesh.addElementsByType(face, 2, [1, 2], [2, 3, 4, 4, 1, 2])
            elif name == "sphere_angle_cad_tt":
                gmsh.model.mesh.addElementsByType(face, 2, [1, 2], [1, 2, 3, 3, 4, 1])
            else:
                gmsh.model.mesh.addElementsByType(face, 3, [1], [1, 2, 3, 4])
            if name == "near_flat":
                assert gmsh.model.mesh.getElementQualities([1], "minSICN")[0] > 0
            gmsh.option.setNumber("Mesh.PackTargetSize", 1)
            gmsh.option.setNumber("Mesh.OptimizeQuadsMinimumEdgeLength", 0)
            gmsh.option.setNumber("Mesh.OptimizeQuadsMaximumEdgeLength", 100)
            gmsh.option.setNumber("Mesh.OptimizeQuadsFinalSplitCadDistanceRatio", ratio)
            gmsh.option.setNumber("Mesh.OptimizeQuadsSmartLaplacian", 1)
            gmsh.option.setNumber("Mesh.Smoothing", 0)
            gmsh.option.setNumber("General.Verbosity", 6)
            gmsh.logger.start()
            gmsh.model.mesh.optimize("OptimizeQuadsFast", force=True)
            log = "\n".join(gmsh.logger.get())
            gmsh.logger.stop()
            qtags, _ = gmsh.model.mesh.getElementsByType(3, face)
            ttags, conn = gmsh.model.mesh.getElementsByType(2, face)
            expected = name in ("concave_plane", "sphere_02", "sphere_13", "near_flat_tt",
                                "sphere_angle_cad", "sphere_angle_cad_tt")
            assert (len(qtags), len(ttags)) == ((0, 2) if expected else (1, 0)), name
            for tag, original in enumerate(xyz, 1):
                assert math.dist(gmsh.model.mesh.getNode(tag)[0], original) < 1.e-12, name
            diagonal = None
            if expected:
                reason = "cad-distance" if sphere and not name.startswith("sphere_angle_cad") else "invalid"
                if name == "sphere_angle_cad_tt":
                    assert "accepted TT swap" in log or "accepted TT CAD swap" in log, (name, log)
                elif name != "near_flat_tt":
                    assert "reason=" + reason + " diagonal=" in log, (name, log)
                else:
                    assert "accepted T-Q^n-T" not in log
                edges = collections.Counter()
                for i in range(0, len(conn), 3):
                    tri = list(map(int, conn[i:i+3]))
                    for j in range(3): edges[tuple(sorted((tri[j], tri[(j+1)%3])))] += 1
                    pts = [xyz[t-1] for t in tri]
                    a = [pts[1][k]-pts[0][k] for k in range(3)]
                    b = [pts[2][k]-pts[0][k] for k in range(3)]
                    cross = [a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]]
                    normal = [sum(p[k] for p in pts)/3 for k in range(3)] if sphere else [0, 0, 1]
                    assert sum(cross[k]*normal[k] for k in range(3)) > 1.e-12, name
                diagonal = next(e for e, count in edges.items() if count == 2)
                desired = (1, 3) if not sphere or distances[0] < distances[1] else (2, 4)
                if name.startswith("near_flat"): desired = (2, 4)
                assert diagonal == desired, (name, diagonal, distances)
                assert {e for e,c in edges.items() if c == 1} == {(1,2),(2,3),(3,4),(1,4)}, name
            records.append(dict(case=name, passed=True, diagonal=diagonal,
                                distances=distances, ratio=ratio))
    finally:
        gmsh.finalize()
    args.report.write_text(json.dumps(records, indent=2) + "\n")
    print("PASS: fixed nodes/boundary, concave repair, irreparable bowtie, CAD diagonal choice, threshold and disable")


if __name__ == "__main__":
    main()
