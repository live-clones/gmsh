#!/usr/bin/env python3
# Plugin tests: runs every case (a .geo file that builds a model or a view and
# runs a plugin on it) in a process of its own, in a directory of its own, and
# summarizes what it leaves behind: the mesh (nodes, elements of each type,
# physical groups), every view (for each kind of list or each step of model
# data: counts, sum, sum of absolute values, min and max of what it holds) and
# the names of the files written. Checks the summaries against ref.json.
#
#   python3 run.py [-o dir] [--api dir] [-j jobs] [--update] [cases...]
#
# A case fails if its process crashes, if it logs an error, or if its summary
# differs from the reference; --update writes the summaries of the cases run
# into ref.json instead of checking them. Exits with 1 if a case failed.

import argparse
import concurrent.futures
import fnmatch
import glob
import json
import math
import os
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
REF = os.path.join(HERE, 'ref.json')
RTOL = 1e-6  # relative to the sum of absolute values


def stats(values):
    if not len(values):
        return [0, 0., 0., 0., 0.]
    return [len(values), math.fsum(values), math.fsum(abs(v) for v in values),
            float(min(values)), float(max(values))]


def summarize(gmsh):
    out = {'mesh': {}, 'views': []}
    m = out['mesh']
    m['entities'] = [len(gmsh.model.getEntities(d)) for d in range(4)]
    tags, coord, _ = gmsh.model.mesh.getNodes()
    m['nodes'] = stats(list(coord))
    m['nodes'][0] = len(tags)
    types, etags, _ = gmsh.model.mesh.getElements()
    m['elements'] = {gmsh.model.mesh.getElementProperties(t)[0]: len(e)
                     for t, e in zip(types, etags)}
    m['physicals'] = len(gmsh.model.getPhysicalGroups())
    for tag in gmsh.view.getTags():
        i = gmsh.view.getIndex(tag)
        v = {'name': gmsh.option.getString('View[%d].Name' % i),
             'steps': int(gmsh.option.getNumber('View[%d].NbTimeStep' % i))}
        nerr = len(gmsh.logger.get())
        types, nums, data = gmsh.view.getListData(tag)
        if len(gmsh.logger.get()) == nerr:
            v['list'] = {t: [int(n)] + stats(d)[1:]
                         for t, n, d in zip(types, nums, data) if n}
            for dim in (2, 3):
                s = gmsh.view.getListDataStrings(tag, dim)[1]
                if s:
                    v['strings%d' % dim] = s
        else:
            # model data (not asked first: the C function behind
            # getModelData aborts on list data if errors throw)
            v['model'] = []
            for step in range(v['steps']):
                typ, t, d, time_, nc = gmsh.view.getModelData(tag, step)
                vals = [x for dd in d for x in dd]
                v['model'].append([typ, len(t), nc, time_] + stats(vals)[1:])
        out['views'].append(v)
    return out


def child(case, jsonfile):
    import gmsh
    gmsh.initialize(readConfigFiles=False)
    gmsh.option.setNumber('General.Terminal', 0)
    gmsh.option.setNumber('General.AbortOnError', 0)
    gmsh.logger.start()
    t0 = time.time()
    gmsh.open(case)
    wall = time.time() - t0
    errors = [l for l in gmsh.logger.get() if l.startswith('Error')]
    out = summarize(gmsh)
    out['errors'] = errors
    # names only: some files are written in an order that changes from run to
    # run (Plugin(Bubbles) numbers its entities in the order of pointers)
    out['files'] = [f for f in sorted(os.listdir('.'))
                    if f not in ('log.txt', 'summary.json')]
    out['time'] = wall
    gmsh.finalize()
    json.dump(out, open(jsonfile, 'w'), indent=1)


def run_case(name, args):
    wdir = os.path.join(args.o, name)
    os.makedirs(wdir, exist_ok=True)
    for f in os.listdir(wdir):
        os.remove(os.path.join(wdir, f))
    env = dict(os.environ, PYTHONPATH=args.api)
    cmd = [sys.executable, os.path.abspath(__file__), '--child',
           os.path.join(HERE, name + '.geo')]
    with open(os.path.join(wdir, 'log.txt'), 'w') as log:
        r = subprocess.run(cmd, cwd=wdir, env=env, stdout=log, stderr=log)
    js = os.path.join(wdir, 'summary.json')
    if r.returncode or not os.path.exists(js):
        return {'crash': r.returncode}
    return json.load(open(js))


def differences(a, b, path=''):
    if isinstance(a, dict) and isinstance(b, dict):
        d = []
        for k in sorted(set(a) | set(b)):
            if k not in a or k not in b:
                d.append('%s/%s: only in %s' % (path, k,
                                                 'new' if k in a else 'ref'))
            else:
                d += differences(a[k], b[k], path + '/' + str(k))
        return d
    if isinstance(a, list) and isinstance(b, list):
        if len(a) != len(b):
            return ['%s: length %d, ref %d' % (path, len(a), len(b))]
        # count, sum, sum of absolute values, min, max: compare the four
        # floating point numbers relative to the sum of absolute values
        scale = abs(a[2]) if len(a) == 5 and isinstance(a[2], float) else 0
        d = []
        for i, (x, y) in enumerate(zip(a, b)):
            if isinstance(x, float) or isinstance(y, float):
                tol = RTOL * max(scale, abs(x), abs(y), 1e-300)
                if abs(x - y) > tol:
                    d.append('%s[%d]: %.17g, ref %.17g' % (path, i, x, y))
            else:
                d += differences(x, y, '%s[%d]' % (path, i))
        return d
    return [] if a == b else ['%s: %r, ref %r' % (path, a, b)]


def main():
    p = argparse.ArgumentParser()
    p.add_argument('-o', default=os.path.join(HERE, 'out'))
    p.add_argument('--api', default=os.path.join(HERE, '..', '..', 'api'))
    p.add_argument('-j', type=int, default=os.cpu_count())
    p.add_argument('--update', action='store_true')
    p.add_argument('--child', nargs=1)
    p.add_argument('cases', nargs='*')
    args = p.parse_args()
    if args.child:
        return child(args.child[0], 'summary.json')
    args.o = os.path.abspath(args.o)
    args.api = os.path.abspath(args.api)

    names = sorted(os.path.basename(f)[:-4]
                   for f in glob.glob(os.path.join(HERE, '*.geo')))
    names = [n for n in names if not n.startswith('_')]
    if args.cases:
        names = [n for n in names
                 if any(fnmatch.fnmatch(n, c) for c in args.cases)]
    ref = json.load(open(REF)) if os.path.exists(REF) else {}

    with concurrent.futures.ThreadPoolExecutor(args.j) as ex:
        results = dict(zip(names, ex.map(lambda n: run_case(n, args), names)))

    failed = 0
    for n in names:
        r = results[n]
        if 'crash' in r:
            status, why = 'CRASH', ['exit code %s, see %s' %
                                    (r['crash'], os.path.join(args.o, n))]
        elif r['errors']:
            status, why = 'ERROR', r['errors']
        elif args.update:
            status, why = 'ok', []
        elif n not in ref:
            status, why = 'NEW', ['no reference']
        else:
            r2 = {k: v for k, v in r.items() if k != 'time'}
            why = differences(r2, ref[n])
            status = 'DIFF' if why else 'ok'
        t = r.get('time')
        print('%-5s %-32s %s' % (status, n, '%.3f s' % t if t else ''))
        for w in why[:10]:
            print('      ' + w)
        failed += status != 'ok'

    if args.update:
        for n in names:
            if 'crash' not in results[n]:
                ref[n] = {k: v for k, v in results[n].items() if k != 'time'}
        json.dump(ref, open(REF, 'w'), indent=1, sort_keys=True)
    print('%d cases, %d failed' % (len(names), failed))
    return 1 if failed else 0


if __name__ == '__main__':
    sys.exit(main())
