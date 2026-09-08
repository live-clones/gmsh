#!/usr/bin/env python3
"""Fixed CAD degree-two stars must not disable a complete V2 face."""
import argparse
import json
import math
from pathlib import Path
import sys


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bindings', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    sys.path.insert(0, str(args.bindings.resolve()))
    import gmsh
    gmsh.initialize()
    records = []
    try:
        for name in ('qq', 'qt', 'unrelated_bowtie_rollback'):
            gmsh.clear()
            face = gmsh.model.occ.addRectangle(-3, -3, 0, 6, 6)
            pole = (0., .2 if name == 'qt' else 0., 0.)
            point = gmsh.model.occ.addPoint(*pole)
            gmsh.model.occ.synchronize()
            gmsh.model.mesh.embed(0, [point], 2, face)
            gmsh.model.mesh.addNodes(0, point, [1], pole)
            xyz = [pole, (-1.,0.,0.), (0.,-1.,0.), (1.,0.,0.), (0.,1.,0.)]
            if name == 'unrelated_bowtie_rollback':
                xyz += [(2.,2.,0.), (2.2,2.,0.), (2.2,2.2,0.), (2.,2.2,0.),
                        (1.8,2.,0.), (1.8,1.8,0.), (2.,1.8,0.)]
            tags = list(range(2, len(xyz)+1))
            gmsh.model.mesh.addNodes(2, face, tags, [x for p in xyz[1:] for x in p],
                [x for p in xyz[1:] for x in gmsh.model.getParametrization(2, face, p)])
            quads = [[1,2,3,4], [1,4,5,2]]
            if name == 'qt':
                gmsh.model.mesh.addElementsByType(face, 2, [1], [1,2,4])
                quads = [[1,4,5,2]]
            if name == 'unrelated_bowtie_rollback':
                quads += [[6,7,8,9], [6,10,11,12]]
            gmsh.model.mesh.addElementsByType(face, 3, list(range(2,2+len(quads))),
                                             [v for q in quads for v in q])
            gmsh.model.mesh.renumberElements()
            def connectivity():
                types, tags, nodes = gmsh.model.mesh.getElements(2, face)
                return [(int(t), list(map(int, ts)), list(map(int, ns)))
                        for t,ts,ns in zip(types,tags,nodes)]
            before = connectivity()
            for key, value in {'Mesh.QuadqsSmartLaplacian':1, 'Mesh.Smoothing':0,
                               'Mesh.QuadqsTargetSize':1, 'Mesh.QuadqsMinimumEdgeLength':0,
                               'Mesh.QuadqsMaximumEdgeLength':100, 'General.Verbosity':6}.items():
                gmsh.option.setNumber(key, value)
            gmsh.logger.start()
            gmsh.model.mesh.optimize('OptimizeQuadsFast', force=True)
            log = '\n'.join(gmsh.logger.get())
            gmsh.logger.stop()
            assert tuple(gmsh.model.mesh.getNode(1)[2:]) == (0,point)
            for tag, original in enumerate(xyz, 1):
                assert math.dist(gmsh.model.mesh.getNode(tag)[0], original) < 1.e-12
            assert len(gmsh.model.mesh.getNodes()[0]) == len(xyz)
            if name == 'unrelated_bowtie_rollback':
                assert connectivity() == before, (before, connectivity())
                assert 'not a regular oriented surface cell complex' in log
                assert 'prepared fixed CAD valence-two stars' not in log
            else:
                assert 'prepared fixed CAD valence-two stars: splitQuads=1 addedPoints=0' in log
                assert 'not a regular oriented surface cell complex' not in log
                assert 'validity=PASS invalid[T/Q]=0/0' in log
            records.append(dict(case=name, passed=True))
    finally:
        gmsh.finalize()
    args.report.write_text(json.dumps(records, indent=2)+'\n')
    print('PASS fixed CAD valence-two QQ/QT, fixed coordinates/classification, rollback on unrelated bowtie')


if __name__ == '__main__':
    main()
