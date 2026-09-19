#!/usr/bin/env python3
# Graphics tests: draws the cases of cases.txt with both drawing pipelines
# (fixed-function and shaders), saves an image after every step, times the
# drawing, and checks that every step drawn after the previous ones gives the
# picture a fresh start with the same steps gives (what is kept between
# frames must follow every change).
#
#   python3 run.py [-o dir] [--api dir] [-j jobs] [--pipelines 0,1]
#                  [--no-fresh] [--pick] [case name patterns...]
#
# Writes into the output directory (default ./out): the images, the timings
# and the picks (summary.json), and report.html. Exits with 1 if a check
# failed. Two runs (e.g. of two builds) are compared with compare.py.

import argparse
import concurrent.futures
import fnmatch
import json
import os
import re
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import pngdiff

WIDTH, HEIGHT = 600, 450
FRAMES = 5  # redraws timed after the first one
TOL, MAXFRAC = 8, 0.0005  # pixel tolerance, fraction of pixels that may differ


def parse_cases(path):
    cases, cur = [], None
    lines = open(path).read().replace('\\\n', ' ').split('\n')
    for line in lines:
        if not line.strip() or line.lstrip().startswith('#'):
            continue
        if line[0] not in ' \t':
            words = line.split()
            cur = {'name': words[0], 'files': [], 'numbers': {}, 'steps': []}
            for w in words[1:]:
                if '=' in w:
                    k, v = w.split('=')
                    cur['numbers'][k] = float(v)
                else:
                    cur['files'].append(w)
            cases.append(cur)
        else:
            cur['steps'].append(line.strip())
    return cases


def step_text(step):
    # a line break after every statement and every loop header: the parser
    # skips the body of a loop that starts on the line of its header
    step = re.sub(r'(For\s+\w+\s+In\s*\{[^}]*\})', r'\1\n', step)
    return step.replace(';', ';\n') + '\n'


def find(f, data):
    for d in (HERE, data):
        if os.path.exists(os.path.join(d, f)):
            return os.path.join(d, f)
    raise FileNotFoundError(f)


def gl_finish():
    # glFinish(), so that a draw is timed until the GPU is done with it
    import ctypes
    import ctypes.util
    for name in ('/System/Library/Frameworks/OpenGL.framework/OpenGL',
                 ctypes.util.find_library('GL'), 'opengl32'):
        try:
            return ctypes.CDLL(name).glFinish
        except (OSError, TypeError, AttributeError):
            pass
    return lambda: None


# ------------------------------------------------------------------ worker
# (one process per case and pipeline, so that nothing is kept from one case
# to the next, and one more per step checked from a fresh start)

def worker(case, shaders, upto, out, data, pick):
    import gmsh
    argv = ['gmsh']
    for k, v in case['numbers'].items():  # read by DefineConstant[]
        argv += ['-setnumber', k, str(v)]
    # the default options, whatever the user has saved
    gmsh.initialize(argv, readConfigFiles=False)
    gmsh.option.setNumber('General.Terminal', 0)
    for i, f in enumerate(case['files']):
        (gmsh.merge if i else gmsh.open)(find(f, data))
    gmsh.option.setNumber('General.Shaders', shaders)
    gmsh.option.setNumber('General.GraphicsWidth', WIDTH)
    gmsh.option.setNumber('General.GraphicsHeight', HEIGHT)
    gmsh.option.setNumber('General.MenuWidth', 200)
    gmsh.option.setNumber('General.MessageHeight', 0)
    gmsh.option.setNumber('General.SmallAxes', 0)
    # the time spent in the draws of the window, which Gmsh reports in its
    # debug messages (the wall time of a draw also counts what the window
    # system does, and waits for the display); the first draw is the one the
    # window makes when it opens
    gmsh.option.setNumber('General.Verbosity', 99)
    gmsh.logger.start()
    gmsh.fltk.initialize()
    gmsh.fltk.update()

    def apply(k):
        path = os.path.join(out, '%s_s%d_%d.geo' % (case['name'], shaders,
                                                    os.getpid()))
        with open(path, 'w') as f:
            f.write(step_text(case['steps'][k]))
        gmsh.logger.stop()
        gmsh.logger.start()
        gmsh.merge(path)
        os.remove(path)
        # a step that does not do what it says tests nothing
        errors = [l for l in gmsh.logger.get() if l.startswith('Error')]
        if errors:
            raise RuntimeError('step %d: %s' % (k, errors[0]))

    finish = gl_finish()

    def draw(keep=False):
        if not keep:
            gmsh.logger.stop()
            gmsh.logger.start()
        t = time.perf_counter()
        gmsh.graphics.draw()
        finish()
        wall = time.perf_counter() - t
        own = [float(l.split()[-2]) for l in gmsh.logger.get()
               if 'openglWindow::draw() done in' in l]
        return sum(own) if own else wall

    res = {'steps': []}
    base = os.path.join(out, '%s_s%d' % (case['name'], shaders))
    if upto is not None:  # a fresh start: all the steps at once
        for k in range(upto + 1):
            apply(k)
        draw()
        gmsh.write(base + '_%02d_fresh.png' % upto)
        gmsh.finalize()
        return res

    res['first'] = draw(True)  # with what the opening of the window built
    res['frames'] = 0.
    rx = gmsh.option.getNumber('General.RotationX')
    for i in range(FRAMES):
        gmsh.option.setNumber('General.RotationX', rx + i + 1)
        res['frames'] += draw() / FRAMES
    gmsh.option.setNumber('General.RotationX', rx)
    draw()
    gmsh.write(base + '_init.png')
    for k in range(len(case['steps'])):
        apply(k)
        res['steps'].append(draw())
        gmsh.write(base + '_%02d.png' % k)
    gmsh.finalize()
    return res


def run_worker(args, case, shaders, upto):
    cmd = [sys.executable, os.path.abspath(__file__), '--worker', case['name'],
           str(shaders), str(-1 if upto is None else upto), '-o', args.out,
           '--api', args.api]
    env = dict(os.environ)
    env['PYTHONPATH'] = args.api + os.pathsep + env.get('PYTHONPATH', '')
    p = subprocess.run(cmd, env=env, capture_output=True, text=True)
    if p.returncode:
        return {'error': (p.stdout + p.stderr).strip().split('\n')[-5:]}
    return json.loads(p.stdout.strip().split('\n')[-1])


def run_pick(args, case, shaders):
    exe = os.path.join(args.out, 'pick')
    p = subprocess.run([exe, case['name'], str(shaders), args.out, HERE,
                        os.path.join(args.out, 'data')],
                       capture_output=True, text=True)
    if p.returncode:
        return {'error': (p.stdout + p.stderr).strip().split('\n')[-5:]}
    return {'picks': p.stdout.split('\n')}


# -------------------------------------------------------------------- main

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('patterns', nargs='*')
    ap.add_argument('-o', '--out', default=os.path.join(HERE, 'out'))
    ap.add_argument('--api', default=os.path.join(HERE, '..', '..', 'api'))
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('--pipelines', default='0,1')
    ap.add_argument('--no-fresh', action='store_true')
    ap.add_argument('--pick', action='store_true',
                    help='also sweep picks with the driver built by '
                    'build_pick.py into the output directory')
    ap.add_argument('--worker', nargs=3, help=argparse.SUPPRESS)
    args = ap.parse_args()
    args.out = os.path.abspath(args.out)
    args.api = os.path.abspath(args.api)
    cases = parse_cases(os.path.join(HERE, 'cases.txt'))
    data = os.path.join(args.out, 'data')

    if args.worker:
        name, shaders, upto = args.worker
        case = [c for c in cases if c['name'] == name][0]
        res = worker(case, int(shaders), None if upto == '-1' else int(upto),
                     args.out, data, False)
        print(json.dumps(res))
        return 0

    if args.patterns:
        cases = [c for c in cases
                 if any(fnmatch.fnmatch(c['name'], p) for p in args.patterns)]
    os.makedirs(data, exist_ok=True)
    env = dict(os.environ)
    env['PYTHONPATH'] = args.api + os.pathsep + env.get('PYTHONPATH', '')
    subprocess.run([sys.executable, os.path.join(HERE, 'generate.py'), data],
                   env=env, check=True, capture_output=True)

    pipelines = [int(s) for s in args.pipelines.split(',')]
    jobs = {}
    with concurrent.futures.ThreadPoolExecutor(args.jobs) as ex:
        for c in cases:
            for s in pipelines:
                jobs[(c['name'], s, None)] = ex.submit(run_worker, args, c, s,
                                                       None)
                if not args.no_fresh:
                    for k in range(len(c['steps'])):
                        jobs[(c['name'], s, k)] = ex.submit(run_worker, args,
                                                            c, s, k)
                if args.pick:
                    jobs[(c['name'], s, 'pick')] = ex.submit(run_pick, args,
                                                             c, s)
    summary, failed = {}, 0
    for c in cases:
        for s in pipelines:
            key = '%s_s%d' % (c['name'], s)
            r = jobs[(c['name'], s, None)].result()
            r['fresh'] = []
            if 'error' in r:
                failed += 1
            elif not args.no_fresh:
                for k in range(len(c['steps'])):
                    f = jobs[(c['name'], s, k)].result()
                    if 'error' in f:
                        r['fresh'].append({'step': k, 'error': f['error']})
                        failed += 1
                        continue
                    base = os.path.join(args.out, key + '_%02d' % k)
                    n, tot = pngdiff.diff(base + '.png', base + '_fresh.png',
                                          TOL)
                    ok = n >= 0 and n <= MAXFRAC * tot
                    r['fresh'].append({'step': k, 'differ': n, 'ok': ok})
                    if ok:
                        os.remove(base + '_fresh.png')
                    else:
                        failed += 1
            # a step that changes nothing in the picture tests nothing
            r['unchanged'] = []
            if 'error' not in r:
                prev = os.path.join(args.out, key + '_init.png')
                for k in range(len(c['steps'])):
                    cur = os.path.join(args.out, key + '_%02d.png' % k)
                    if pngdiff.diff(prev, cur, TOL)[0] == 0:
                        r['unchanged'].append(k)
                    prev = cur
            if args.pick:
                r['pick'] = jobs[(c['name'], s, 'pick')].result()
                if 'error' in r['pick']: failed += 1
            summary[key] = r
            status = 'ERROR' if 'error' in r else \
                'FAIL' if any(not f.get('ok') for f in r['fresh']) else 'ok'
            print('%-28s %s %s' % (key, status, '' if 'error' in r else
                                   'first %.4f s, frame %.4f s, steps %.4f s'
                                   % (r['first'], r['frames'],
                                      sum(r['steps']))))
            if 'error' in r:
                print('\n'.join('    ' + l for l in r['error']))
            for k in r.get('unchanged', []):
                print('    step %d changes nothing in the picture (warning)' % k)
            for f in r['fresh']:
                if not f.get('ok'):
                    print('    step %d: %s' % (f['step'], f.get('error') or
                                               '%d pixels differ from a fresh '
                                               'start' % f['differ']))
    json.dump({'cases': cases, 'results': summary},
              open(os.path.join(args.out, 'summary.json'), 'w'), indent=1)
    report(args.out, cases, summary, pipelines)
    print('%d failure(s); report in %s' %
          (failed, os.path.join(args.out, 'report.html')))
    return 1 if failed else 0


def report(out, cases, summary, pipelines):
    h = ['<!DOCTYPE html><html><head><meta charset="utf-8">'
         '<title>Graphics tests</title><style>body{font-family:sans-serif;'
         'margin:16px}img{width:300px;border:1px solid #ccc}'
         'td{vertical-align:top;font-size:12px}.bad{color:#c00}'
         'code{font-size:11px}</style></head><body><h1>Graphics tests</h1>']
    for c in cases:
        h.append('<h2>%s</h2><p>%s</p><table>' % (c['name'],
                                                   ' '.join(c['files'])))
        for k in [None] + list(range(len(c['steps']))):
            h.append('<tr><td><code>%s</code></td>' %
                     ('(opened)' if k is None else c['steps'][k]))
            for s in pipelines:
                key = '%s_s%d' % (c['name'], s)
                img = key + ('_init' if k is None else '_%02d' % k) + '.png'
                cell = '<img src="%s">' % img
                r = summary[key]
                if k is not None and k < len(r.get('fresh', [])) and \
                        not r['fresh'][k].get('ok'):
                    cell += '<br><span class="bad">fresh start differs</span>'\
                        '<br><img src="%s">' % img.replace('.png',
                                                           '_fresh.png')
                h.append('<td>%s</td>' % cell)
            h.append('</tr>')
        h.append('</table>')
    h.append('</body></html>')
    open(os.path.join(out, 'report.html'), 'w').write('\n'.join(h))


if __name__ == '__main__':
    sys.exit(main())
