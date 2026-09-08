#!/usr/bin/env python3
"""STEP surface campaign: h=4 triangles as a strict gate, PACK3D/V2, one report.

Only Python's standard library and the matching native Gmsh binary are needed.
Geometry and generated meshes are external inputs/outputs, never repository data.
"""
import argparse
import concurrent.futures
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import re
import selectors
import signal
import socket
import subprocess
import time

CRITERIA = {
    'warp': ('Warping Q (deg)', '<', 15, 25),
    'edgeRatio': ('Aspect ratio Q/T', '<', 5, 10),
    'quadAngleMin': ('Angle minimal Q (deg)', '>', 45, 25),
    'quadAngleMax': ('Angle maximal Q (deg)', '<', 135, 160),
    'triAngleMin': ('Angle minimal T (deg)', '>', 20, 10),
    'triAngleMax': ('Angle maximal T (deg)', '<', 120, 150),
    'skew': ('Skewing Q/T (deg)', '<', 125, 160),
}
BOUNDARY = re.compile(r'(?:unable|cannot|could not|failed) to recover|boundary.*(?:not recovered|recovery failed)', re.I)
ERROR = re.compile(r'^Error\s*:', re.M)


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def geo_string(path):
    return json.dumps(str(Path(path).resolve()))


def run_stage(gmsh, geo, log, timeout):
    """Stop the entire case process on boundary recovery failure, even a warning."""
    started = time.monotonic()
    env = dict(os.environ, OMP_NUM_THREADS='1', OPENBLAS_NUM_THREADS='1', MKL_NUM_THREADS='1')
    cmd = [str(gmsh), str(geo), '-parse_and_exit', '-nopopup', '-v', '6', '-nt', '1']
    reason = ''
    with log.open('wb') as sink:
        proc = subprocess.Popen(cmd, cwd=geo.parent, stdout=subprocess.PIPE,
                                stderr=subprocess.STDOUT, env=env, start_new_session=True)
        selector = selectors.DefaultSelector()
        selector.register(proc.stdout, selectors.EVENT_READ)
        pending = b''
        try:
            while selector.get_map():
                if time.monotonic() - started > timeout:
                    reason = 'timeout'
                    break
                for key, _ in selector.select(.25):
                    chunk = os.read(key.fileobj.fileno(), 65536)
                    if not chunk:
                        selector.unregister(key.fileobj)
                        continue
                    sink.write(chunk)
                    sink.flush()
                    pending += chunk
                    lines = pending.split(b'\n')
                    pending = lines.pop()
                    for line in lines:
                        text = line.decode(errors='replace')
                        if BOUNDARY.search(text):
                            reason = 'boundary: ' + text.strip()
                            break
                        if ERROR.search(text):
                            reason = 'gmsh-error: ' + text.strip()
                            break
                    if reason:
                        break
                if reason:
                    break
        finally:
            selector.close()
            if reason and proc.poll() is None:
                os.killpg(proc.pid, signal.SIGTERM)
            try:
                proc.wait(timeout=5)
            except subprocess.TimeoutExpired:
                os.killpg(proc.pid, signal.SIGKILL)
                proc.wait()
            proc.stdout.close()
    text = log.read_text(errors='replace')
    if not reason:
        match = BOUNDARY.search(text)
        if match:
            reason = 'boundary: ' + text[match.start():].splitlines()[0]
        elif proc.returncode or ERROR.search(text):
            reason = 'gmsh-error: exit=' + str(proc.returncode)
    return time.monotonic() - started, text, reason


def parse_quality(log):
    summary = re.findall(r'PACK final quality: (.*)', log)
    spec = re.findall(r'PACK final specifications pass\(preferred/total\|absolute/total\): (.*)', log)
    fit = re.findall(r'PACK final fit: (.*)', log)
    metrics = re.findall(r'PACK final quad metrics: (.*)', log)
    stop = re.findall(r'loop end rounds=(\d+) reason=([\w-]+)', log)
    if not (summary and spec and fit and metrics and stop):
        raise ValueError('missing native V2 quality audit or stopping condition')
    counts = {}
    for key in CRITERIA:
        m = re.search(r'\b' + key + r'=(\d+)/(\d+)\|(\d+)/(\d+)', spec[-1])
        if not m or m[2] != m[4]:
            raise ValueError('incomplete criterion ' + key)
        counts[key] = dict(preferred=int(m[1]), total=int(m[2]), absolute=int(m[3]))
    def count(key):
        return int(re.search(r'\b' + key + r'=(\d+)', summary[-1])[1])
    q, t = count('quads'), count('triangles')
    for k, c in counts.items():
        expected = q if k in ('warp', 'quadAngleMin', 'quadAngleMax') else t if k.startswith('triAngle') else q+t
        if c['total'] != expected:
            raise ValueError('wrong applicable count for ' + k)
    if len(re.findall(r'terminal Winslow sweep=\d+ moved=\d+', log)) != 4:
        raise ValueError('expected four terminal Winslow sweeps')
    if 'loop round=' in log[log.index('terminal Winslow begin'):]:
        raise ValueError('topology restarted after terminal Winslow')
    return dict(quads=q, triangles=t, counts=counts, summary=summary[-1],
                fit=fit[-1], metrics=metrics[-1], rounds=int(stop[-1][0]), stop=stop[-1][1])


def case(args, source):
    stem = source.stem
    row = dict(case=stem, state='running')
    tri = args.output / (stem + '.tri_h4.msh')
    quad = args.output / (stem + '_quads_h4.msh')
    common = '\n'.join([
        'General.AbortOnError = 4;', 'General.NumThreads = 1;',
        'Mesh.AlgorithmSwitchOnFailure = 0;', 'Mesh.MeshSizeMin = 4;',
        'Mesh.MeshSizeMax = 4;', 'Mesh.ElementOrder = 1;', 'Mesh.Smoothing = 3;',
        'Mesh.SaveAll = 1;', 'Mesh.SaveParametric = 1;', 'Mesh.Binary = 1;',
        'Merge ' + geo_string(source) + ';',
    ])
    scripts = [args.output / (stem + '.tri.geo'), args.output / (stem + '.quad.geo')]
    try:
        scripts[0].write_text(common + '\nMesh.Algorithm = 6;\nMesh.RecombineAll = 0;\nMesh 2;\nSave ' + geo_string(tri) + ';\n')
        seconds, text, error = run_stage(args.gmsh, scripts[0], args.output/(stem+'.tri.log'), args.timeout)
        row['triangleSeconds'] = seconds
        if error or not tri.is_file() or 'Done meshing 2D' not in text:
            row.update(state='skipped-boundary' if error.startswith('boundary:') else 'failed-triangles',
                       error=error or 'triangular mesh was not produced')
            return row
        scripts[1].write_text(common + '\nMerge ' + geo_string(tri) + ';\n' + '\n'.join([
            'Mesh.Algorithm = 9;', 'Mesh.RecombineAll = 1;',
            'Mesh.QuadqsPacking3D = 1;', 'Mesh.QuadqsCleanupMethod = 1;',
            'Mesh.QuadqsSmartLaplacian = 2;', 'Mesh.QuadqsIntrinsicEdgeLengthFactor = 0;',
            'Mesh.QuadqsTargetSize = 4;', 'Mesh.QuadqsMinimumEdgeLength = 2;',
            'Mesh.QuadqsMaximumEdgeLength = 8;', 'Mesh.RecombineMinimumQuality = -1;',
            'Mesh.QuadqsFinalSplitCadDistanceRatio = 0.2;',
            'Mesh 2;', 'Save ' + geo_string(quad) + ';',
        ]) + '\n')
        seconds, text, error = run_stage(args.gmsh, scripts[1], args.output/(stem+'.quad.log'), args.timeout)
        row['quadSeconds'] = seconds
        if error or not quad.is_file():
            row.update(state='failed-quads', error=error or 'quad mesh was not produced')
            return row
        row['quality'] = parse_quality(text)
        row['v2Seconds'] = float(re.findall(r'Done optimizing mesh \(Wall ([\d.e+-]+)s', text)[-1])
        row.update(state='completed', mesh=quad.name, meshSha256=sha(quad))
        return row
    except Exception as exc:
        row.update(state='failed', error=str(exc))
        return row
    finally:
        tri.unlink(missing_ok=True)
        for script in scripts:
            script.unlink(missing_ok=True)
        if row['state'] != 'completed':
            quad.unlink(missing_ok=True)


def report(args, rows, manifest):
    lines = ['# Campagne A* — surfaces CAD 3D, quads h=4', '',
             f"Mise à jour : {datetime.now(timezone.utc).isoformat()} ; hôte : `{manifest['host']}` ; commit : `{manifest['commit']}`.", '',
             'STEP original → triangles h=4 → PACK 3D h=4 → V2 jusqu’à stabilité topologique → 4 Winslow globaux → découpe finale. '
             'Arrêt du cas sur échec de récupération de frontière ou erreur ; aucun algorithme de secours. '
             f'{args.jobs} cas simultanés, un thread Gmsh par cas. Les temps incluent la concurrence éventuelle.', '',
             'Les seuils angulaires/ratios sont stricts : au moins 99 % des éléments applicables doivent respecter la limite préférée, '
             '100 % la limite absolue. Longueurs demandées : [2,8]. Les violations par critère peuvent concerner les mêmes éléments.', '',
             '| Critère | Limite préférée (99 %) | Limite absolue (100 %) |', '|---|---:|---:|']
    for label,op,pref,absolute in CRITERIA.values():
        lines.append(f'| {label} | {op} {pref} | {op} {absolute} |')
    lines += ['', '| Géométrie | État | Q / T | Triangles (s) | Quads (s) | V2 (s) | Tours | Critères 99 % | Critères absolus |',
              '|---|---|---:|---:|---:|---:|---:|---:|---:|']
    for row in rows:
        q=row.get('quality'); name=row['case']
        if not q:
            lines.append(f"| {name} | {row['state']} | — | {row.get('triangleSeconds',0):.2f} | — | — | — | — | — |")
        else:
            counts=[c for c in q['counts'].values() if c['total']]
            pref=sum(100*c['preferred']>=99*c['total'] for c in counts)
            absolute=sum(c['absolute']==c['total'] for c in counts)
            lines.append(f"| [{name}]({row['mesh']}) | {row['state']} | {q['quads']} / {q['triangles']} | {row['triangleSeconds']:.2f} | {row['quadSeconds']:.2f} | {row['v2Seconds']:.3f} | {q['rounds']} ({q['stop']}) | {pref}/{len(counts)} | {absolute}/{len(counts)} |")
    for row in rows:
        lines += ['', '## '+row['case'], '']
        if 'error' in row:
            lines += ['Cas arrêté : '+row['error'].replace('|','\\|'), '']
        if 'quality' not in row:
            continue
        q=row['quality']; lines += ['| Critère | Respect préféré | Violations absolues |', '|---|---:|---:|']
        for key,c in q['counts'].items():
            ratio=f"{100*c['preferred']/c['total']:.2f} % ({c['preferred']}/{c['total']})" if c['total'] else 'N/A'
            lines.append(f"| {CRITERIA[key][0]} | {ratio} | {c['total']-c['absolute']}/{c['total']} |")
        lines += ['', 'Audit natif Gmsh (validité physique, orientation CAD, tailles et distance CAD échantillonnée) :',
                  '```text', q['summary'], q['metrics'], q['fit'], '```', '',
                  'Les échecs de validité, les critères non conformes et la couverture CAD incomplète restent visibles ; '
                  '« completed » signifie génération et audit terminés, pas conformité intégrale.']
    temporary = args.output/'rapport_A_h4.tmp'
    temporary.write_text('\n'.join(lines)+'\n')
    temporary.replace(args.output/'rapport_A_h4.md')


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--gmsh',type=Path,required=True)
    p.add_argument('--inputs',type=Path,required=True,help='Root containing A*.stp, directly or in case directories')
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--jobs',type=int,default=1)
    p.add_argument('--timeout',type=float,default=1800,help='Seconds per triangle or quad stage')
    p.add_argument('--commit',default='unknown')
    args=p.parse_args()
    args.gmsh=args.gmsh.resolve();args.inputs=args.inputs.resolve();args.output=args.output.resolve()
    if args.jobs<1 or args.timeout<=0:p.error('jobs and timeout must be positive')
    sources=sorted(x for x in args.inputs.rglob('A*') if x.suffix.lower() in ('.stp','.step'))
    if not sources or len({x.stem for x in sources})!=len(sources):p.error('no STEP sources or duplicate case names')
    args.output.mkdir(parents=True,exist_ok=True)
    if (args.output/'manifest.json').exists():p.error('campaign output already initialized; choose a new common directory')
    manifest=dict(host=socket.gethostname(),commit=args.commit,gmsh=str(args.gmsh),gmshSha256=sha(args.gmsh),
                  jobs=args.jobs,threadsPerCase=1,size=4,timeoutPerStage=args.timeout,
                  sources=[dict(path=str(x),sha256=sha(x)) for x in sources])
    (args.output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    rows=[dict(case=x.stem,state='pending') for x in sources];report(args,rows,manifest)
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futures={pool.submit(case,args,src):i for i,src in enumerate(sources)}
        for future in concurrent.futures.as_completed(futures):
            i=futures[future];rows[i]=future.result();report(args,rows,manifest)
            print(rows[i]['case'],rows[i]['state'],rows[i].get('error',''),flush=True)
    print('REPORT',args.output/'rapport_A_h4.md',flush=True)

if __name__=='__main__':main()
