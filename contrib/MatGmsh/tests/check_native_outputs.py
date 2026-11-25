#!/usr/bin/env python3
"""Audit gmshMat's MSH2 snapshots using only the Python standard library.

Usage: check_native_outputs.py OUTPUT_DIR --stage extended --project
This checks discrete data and stage contracts, not geometric equivalence to a
true midsurface, continuous coverage, or absence of triangle intersections.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
import math
from pathlib import Path


def digest(records):
    h = hashlib.sha256()
    for record in records:
        h.update((repr(record) + '\n').encode())
    return h.hexdigest()


def read_msh2(path):
    nodes, triangles, element_ids = {}, [], set()
    parents = None
    seen = set()
    with path.open() as stream:
        for line in stream:
            section = line.strip()
            if section == '$MeshFormat':
                version, binary, size = next(stream).split()
                if not version.startswith('2.') or binary != '0':
                    raise ValueError('Only ASCII MSH2 is supported: ' + str(path))
                if next(stream).strip() != '$EndMeshFormat':
                    raise ValueError('Missing EndMeshFormat marker')
                seen.add('format')
            elif section == '$Nodes':
                if 'nodes' in seen:
                    raise ValueError('Repeated Nodes section')
                seen.add('nodes')
                for _ in range(int(next(stream))):
                    values = next(stream).split()
                    if len(values) != 4:
                        raise ValueError('Malformed node record')
                    tag = int(values[0])
                    xyz = tuple(map(float, values[1:]))
                    if tag <= 0 or tag in nodes or not all(map(math.isfinite, xyz)):
                        raise ValueError('Duplicate, invalid or nonfinite node')
                    nodes[tag] = xyz
                if next(stream).strip() != '$EndNodes':
                    raise ValueError('Missing EndNodes marker')
            elif section == '$Elements':
                if 'elements' in seen:
                    raise ValueError('Repeated Elements section')
                seen.add('elements')
                for _ in range(int(next(stream))):
                    values = list(map(int, next(stream).split()))
                    if len(values) < 3:
                        raise ValueError('Malformed element record')
                    tag, kind, count = values[:3]
                    if tag <= 0 or tag in element_ids or count < 0 or len(values) < 3 + count:
                        raise ValueError('Duplicate or invalid element record')
                    element_ids.add(tag)
                    if kind == 2:
                        connectivity = tuple(values[3 + count:])
                        if len(connectivity) != 3:
                            raise ValueError('Triangle must have three nodes')
                        triangles.append((tag, tuple(values[3:3 + count]), connectivity))
                if next(stream).strip() != '$EndElements':
                    raise ValueError('Missing EndElements marker')
            elif section == '$ElementData':
                strings = [next(stream).strip().strip('"') for _ in range(int(next(stream)))]
                reals = [float(next(stream)) for _ in range(int(next(stream)))]
                integers = [int(next(stream)) for _ in range(int(next(stream)))]
                if len(integers) < 3 or integers[1] < 1 or integers[2] < 0:
                    raise ValueError('Malformed ElementData header')
                is_parent = strings and strings[0] == 'MAT parent'
                if is_parent:
                    if parents is not None or integers[1] != 1:
                        raise ValueError('Repeated or nonscalar MAT parent data')
                    parents = {}
                for _ in range(integers[2]):
                    values = next(stream).split()
                    if len(values) != integers[1] + 1:
                        raise ValueError('Malformed ElementData record')
                    if is_parent:
                        tag, parent = int(values[0]), float(values[1])
                        if tag in parents or not math.isfinite(parent) or not parent.is_integer() or parent < -1:
                            raise ValueError('Invalid MAT parent record')
                        parents[tag] = int(parent)
                if next(stream).strip() != '$EndElementData':
                    raise ValueError('Missing EndElementData marker')
    if seen != {'format', 'nodes', 'elements'} or not nodes or not triangles:
        raise ValueError('Missing mesh format, nodes or triangles')
    if parents is not None and set(parents) != {tag for tag, _, _ in triangles}:
        raise ValueError('MAT parent data does not cover all triangle records')
    return nodes, triangles, parents


def components(edges, isolated=()):
    graph = defaultdict(set)
    for v in isolated:
        graph[v]
    for a, b in edges:
        graph[a].add(b)
        graph[b].add(a)
    remaining = set(graph)
    count = 0
    while remaining:
        pending = [remaining.pop()]
        count += 1
        while pending:
            for v in graph[pending.pop()]:
                if v in remaining:
                    remaining.remove(v)
                    pending.append(v)
    return count, Counter(map(len, graph.values()))


def inspect_mesh(mesh):
    nodes, triangles, parents = mesh
    edge_uses, by_branch = defaultdict(list), defaultdict(list)
    used, seen = set(), set()
    area = 0.
    minimum = math.inf
    for tag, tags, tri in triangles:
        if len(set(tri)) != 3 or any(v not in nodes for v in tri):
            raise ValueError('Triangle has a repeated or missing node: ' + str(tag))
        key = tuple(sorted(tri))
        if key in seen:
            raise ValueError('Duplicate triangle connectivity: ' + str(tag))
        seen.add(key)
        used.update(tri)
        p, q, r = (nodes[v] for v in tri)
        a = tuple(q[i] - p[i] for i in range(3))
        b = tuple(r[i] - p[i] for i in range(3))
        cross = (a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0])
        measure = .5 * math.sqrt(sum(x*x for x in cross))
        if not math.isfinite(measure) or measure <= 0.:
            raise ValueError('Zero-area or nonfinite triangle: ' + str(tag))
        area += measure
        minimum = min(minimum, measure)
        # The native writer uses elementary surface tags for branch labels.
        branch = tags[1] if len(tags) > 1 else tags[0] if tags else 0
        for i in range(3):
            x, y = tri[i], tri[(i+1) % 3]
            edge = tuple(sorted((x, y)))
            edge_uses[edge].append((branch, 1 if x < y else -1))
            by_branch[branch].append(edge)
    boundary = [e for e, uses in edge_uses.items() if len(uses) == 1]
    junctions = [e for e, uses in edge_uses.items() if len(uses) > 2]
    component_count, _ = components(edge_uses, used)
    boundary_count, boundary_degrees = components(boundary)
    junction_count, junction_degrees = components(junctions)
    signature = ((edge, tuple(sorted(branch for branch, _ in edge_uses[edge])))
                 for edge in sorted(edge_uses))
    return dict(nodes=len(nodes), used_nodes=len(used), unused_nodes=len(nodes)-len(used),
                triangles=len(triangles), edges=len(edge_uses), components=component_count,
                euler=len(used)-len(edge_uses)+len(triangles),
                free_edges=len(boundary), boundary_components=boundary_count,
                boundary_vertex_degrees=dict(sorted(boundary_degrees.items())),
                junction_edges=len(junctions), junction_components=junction_count,
                junction_vertex_degrees=dict(sorted(junction_degrees.items())),
                maximum_edge_incidence=max(map(len, edge_uses.values())),
                same_direction_manifold_edges=sum(len(u) == 2 and u[0][1] == u[1][1]
                                                  for u in edge_uses.values()),
                branches={str(b): components(e)[0] for b, e in sorted(by_branch.items())},
                area=area, minimum_triangle_area=minimum,
                triangle_records_sha256=digest(sorted(triangles)),
                coordinates_sha256=digest(sorted(nodes.items())),
                parent_data_sha256=digest(sorted(parents.items())) if parents is not None else None,
                branch_incidence_sha256=digest(signature)), {
                    edge: edge_uses[edge][0][0] for edge in boundary}


def audit(directory, stage=None, project=False, baseline=None):
    report = json.loads((directory / 'report.json').read_text())
    if not isinstance(report, dict):
        raise ValueError('Report must be a JSON object')
    failures, snapshots, metadata, boundaries = [], {}, {}, {}
    stage = stage or ('extended' if (directory/'extended.msh').exists() else
                      'projected' if (directory/'projected.msh').exists() else 'filtered')
    required = ['skin', 'raw', 'filtered']
    if stage in ('projected', 'extended'):
        required.append('projected')
    if stage == 'extended':
        required.append('extended')
    for name in required:
        try:
            mesh = read_msh2(directory / (name + '.msh'))
            snapshots[name], boundaries[name] = inspect_mesh(mesh)
            if mesh[2] is None:
                failures.append(f'{name}: missing native MAT parent data')
            metadata[name] = dict(node_ids=set(mesh[0]), parents=set((mesh[2] or {}).values()),
                                  indices={tag: i for i, tag in enumerate(mesh[0])}
                                  if name == 'projected' else None)
            # Keep only stage contracts after hashing; avoid retaining all
            # triangle records from several large snapshots simultaneously.
            del mesh
        except (ValueError, OSError, StopIteration, OverflowError) as error:
            failures.append(f'{name}: {error}')
    recorded_stages = report.get('stages', {})
    if not isinstance(recorded_stages, dict):
        failures.append('Report stages must be a JSON object')
        recorded_stages = {}
    for name, measured in snapshots.items():
        if name == 'skin':
            continue
        recorded = recorded_stages.get(name)
        if not isinstance(recorded, dict):
            failures.append(f'{name}: missing report topology')
            continue
        for field in ('vertices', 'triangles', 'components', 'free_edges', 'junction_edges', 'euler'):
            value = measured['used_nodes' if field == 'vertices' else field]
            if type(recorded.get(field)) is not int or recorded[field] != value:
                failures.append(f'{name}: reported {field} differs from mesh ({value})')
    projection_contract = None
    if 'raw' in snapshots and 'filtered' in snapshots:
        raw_parents = metadata['raw']['parents']
        filtered_parents = metadata['filtered']['parents']
        if not filtered_parents <= raw_parents:
            failures.append('Filtered mesh invents MAT polygon parents absent from raw mesh')
    if 'filtered' in snapshots and 'projected' in snapshots:
        before, after = snapshots['filtered'], snapshots['projected']
        same = (before['triangle_records_sha256'] == after['triangle_records_sha256']
                and before['parent_data_sha256'] == after['parent_data_sha256']
                and metadata['filtered']['node_ids'] == metadata['projected']['node_ids'])
        if not same:
            failures.append('Projection changed triangle records or node identities')
        status = report.get('projectionStatus', report.get('projection_status'))
        if isinstance(report.get('projection'), dict):
            status = report['projection'].get('status', status)
        if status not in ('disabled', 'unchanged', 'applied', 'partial'):
            failures.append('Missing or unknown projection status')
        same_coordinates = before['coordinates_sha256'] == after['coordinates_sha256']
        if status in ('disabled', 'unchanged') and not (same and same_coordinates):
            failures.append('Disabled/rejected projection did not preserve its exact input')
        if project and status == 'disabled':
            failures.append('Projection requested but reported disabled')
        projection_contract = dict(status=status, identical_triangle_records_and_node_ids=same,
                                   identical_coordinates=same_coordinates)
    extension_contract = None
    if stage == 'extended' and 'projected' in snapshots:
        if 'extended' in snapshots:
            old_parents = metadata['projected']['parents'] - {-1}
            new_parents = metadata['extended']['parents'] - {-1}
            if new_parents != old_parents:
                failures.append('Extension loses or invents original MAT polygon parents')
        extension = report.get('extension', {})
        fronts = extension.get('fronts')
        if not isinstance(fronts, list):
            failures.append('Missing extension front ledger')
        else:
            # Front endpoints are input Mesh indices; MSH node tags need not
            # equal those indices, so use their original file order.
            index = metadata['projected']['indices']
            expected = {tuple(sorted((index[a], index[b]))): branch - 1
                        for (a, b), branch in boundaries['projected'].items()}
            actual = Counter()
            states = Counter()
            known = {'already_on_skin', 'reached_skin', 'reached_sheet', 'unresolved'}
            for front in fronts:
                try:
                    key = tuple(sorted((int(front['a']), int(front['b']))))
                    actual[key] += 1
                    states[front['status']] += 1
                    if key in expected and front.get('branch') != expected[key]:
                        failures.append('Front branch does not match its input free edge')
                    if front['status'] not in known:
                        failures.append('Unknown front status: ' + str(front['status']))
                except (KeyError, TypeError, ValueError):
                    failures.append('Malformed front ledger entry')
            if set(actual) != set(expected) or any(n != 1 for n in actual.values()):
                failures.append('Front ledger does not cover each input free edge exactly once')
            if not isinstance(extension.get('complete'), bool):
                failures.append('Missing extension completion state')
            if extension.get('complete') and states.get('unresolved', 0):
                failures.append('Extension claims completion with unresolved fronts')
            extension_contract = dict(expected_fronts=len(expected), recorded_fronts=len(fronts),
                                      states=dict(states), complete=extension.get('complete'))
    comparison = None
    if baseline:
        reference, _ = inspect_mesh(read_msh2(baseline))
        selected = snapshots.get(stage)
        comparison = dict(baseline=str(baseline), baseline_statistics=reference,
                          selected_stage=stage, selected_statistics=selected,
                          identical_triangle_records=bool(selected and
                              selected['triangle_records_sha256'] == reference['triangle_records_sha256']),
                          identical_coordinates=bool(selected and
                              selected['coordinates_sha256'] == reference['coordinates_sha256']),
                          note='Statistics and identities only; differing triangulations require a geometric audit.')
    return dict(passed=not failures, failures=failures, stage=stage, snapshots=snapshots,
                projection=projection_contract, extension=extension_contract, baseline_comparison=comparison,
                scope='ASCII MSH2 integrity, discrete topology descriptors, branch incidence, optional projection identity and front bookkeeping. No intersection, midsurface accuracy or continuous coverage certificate.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    parser.add_argument('--stage', choices=['filtered', 'projected', 'extended'])
    parser.add_argument('--project', action='store_true')
    parser.add_argument('--baseline', type=Path, help='Optional ASCII MSH2 baseline for statistics only')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    try:
        result = audit(args.directory, args.stage, args.project, args.baseline)
    except (ValueError, OSError, StopIteration, OverflowError) as error:
        result = dict(passed=False, failures=[str(error)])
    output = args.output or args.directory / 'native-output-audit.json'
    output.write_text(json.dumps(result, indent=2, allow_nan=False) + '\n')
    print(json.dumps(dict(passed=result['passed'], failures=result['failures'], output=str(output))))
    return 0 if result['passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
