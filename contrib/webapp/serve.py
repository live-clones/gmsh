#!/usr/bin/env python3

# The pages of the web app served for their development, as
#
#   python3 -m http.server 8000 --bind 127.0.0.1 --directory ~/src/gmsh
#
# serves them (the Gmsh source tree, the pages in /contrib/webapp/), with the
# source of Gmsh given to the assistant of the page (search_source and
# read_source, see assistantTools in onelab.html), read only:
#
#   /source/info                                    the tree and its branch
#   /source/search?query=...&path=...&max_results=...
#   /source/read?path=...&start_line=...&end_line=...
#
#   python3 serve.py [port] [--bind address] [--directory tree served]
#                    [--source tree given to the assistant]
#
# The source is the files of the programs of the tree (C++, the parser of the
# .geo language, CMake, Python, .geo, the documentation), not its hidden files
# (.git), and searched outside its build directories and the repositories it
# holds; none outside it, symbolic links followed. They are given only to the
# pages of this machine (the host of the request is this machine: not a page
# of another site whose name was made to point here). Nothing else is done: no
# file written, no command run.

import argparse
import json
import os
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlsplit

# the files of the source, by extension and by name
EXTENSIONS = {'.c', '.cc', '.cpp', '.cxx', '.h', '.hh', '.hpp', '.hxx', '.y',
              '.l', '.py', '.geo', '.cmake', '.texi', '.md'}
NAMES = {'CMakeLists.txt'}
# the files not searched: the parser generated from Gmsh.y and Gmsh.l (their
# lines are those of the grammar)
GENERATED = {'Gmsh.tab.cpp', 'Gmsh.tab.hpp', 'Gmsh.yy.cpp'}
# the directories searched first at the root (Gmsh itself, its API)
FIRST = ['src', 'api']
# the bounds: of the files read or searched (bytes), of the lines found by a
# search and their characters, of the lines read at once and their
# characters, of the text of an answer (characters)
MAX_FILE = 4 << 20
MAX_RESULTS, MAX_FOUND = 200, 300
MAX_LINES, MAX_LINE = 400, 2000
MAX_TEXT = 64 << 10
LOCAL = {'localhost', '127.0.0.1', '[::1]'}


class Refused(Exception):
    pass


class Source:
    def __init__(self, root):
        self.root = os.path.realpath(root)

    def relative(self, real):
        return os.path.relpath(real, self.root).replace(os.sep, '/')

    @staticmethod
    def program(name):
        return name in NAMES or os.path.splitext(name)[1] in EXTENSIONS

    def allowed(self, real):
        # (a real path: in the tree, not hidden)
        if real != self.root and not real.startswith(self.root + os.sep):
            return False
        return not any(p.startswith('.') for p in self.relative(real).split('/')
                       if p != '.')

    def searched(self, d, name):
        # a directory searched: not hidden, not a build directory, not a
        # repository of its own, not a link
        p = os.path.join(d, name)
        return not (name.startswith('.') or name.startswith('build') or
                    name in ('__pycache__', 'node_modules') or
                    os.path.islink(p) or os.path.exists(os.path.join(p, '.git')))

    def resolve(self, path):
        # the real path of path, relative to the root (the root if empty)
        path = (path or '').strip()
        if '\0' in path:
            raise Refused('Bad path')
        if os.path.isabs(path) or path.startswith('~'):
            raise Refused('Paths are relative to the root of the source '
                          '(e.g. src/parser/Gmsh.y)')
        parts = [p for p in path.replace('\\', '/').split('/') if p not in ('', '.')]
        if '..' in parts:
            raise Refused('No ".." in paths')
        real = os.path.realpath(os.path.join(self.root, *parts))
        if not self.allowed(real):
            raise Refused('Not in the source: ' + path)
        if not os.path.exists(real):
            raise Refused('No file or directory ' + path)
        return real

    def text(self, real):
        if os.path.getsize(real) > MAX_FILE:
            raise Refused('File too large: ' + self.relative(real))
        with open(real, 'rb') as f:
            return f.read().decode('utf-8', 'replace')

    def files(self, top):
        if os.path.isfile(top):
            if self.program(os.path.basename(top)):
                yield top
            return
        for d, dirs, names in os.walk(top):
            first = lambda x: FIRST.index(x) if d == self.root and x in FIRST else len(FIRST)
            dirs[:] = sorted((x for x in dirs if self.searched(d, x)),
                             key=lambda x: (first(x), x))
            for name in sorted(names):
                p = os.path.join(d, name)
                if (self.program(name) and not name.startswith('.') and
                    name not in GENERATED and
                    (not os.path.islink(p) or self.allowed(os.path.realpath(p)))):
                    yield p

    def info(self):
        return {'root': os.path.basename(self.root), 'branch': self.branch()}

    def branch(self):
        git = os.path.join(self.root, '.git')
        try:
            if os.path.isfile(git):  # (a worktree: "gitdir: ...")
                with open(git) as f:
                    git = os.path.join(self.root, f.read().split(':', 1)[1].strip())
            with open(os.path.join(git, 'HEAD')) as f:
                head = f.read().strip()
        except (OSError, IndexError):
            return None
        ref = 'ref: refs/heads/'
        return head[len(ref):] if head.startswith(ref) else head[:12]

    def search(self, query, path, max_results):
        if not query:
            raise Refused('No query')
        if len(query) > 200:
            raise Refused('Query too long')
        n = min(max(max_results or 50, 1), MAX_RESULTS)
        # (case-insensitive if the query has no capitals)
        fold = query == query.lower()
        results = []
        for real in self.files(self.resolve(path)):
            try:
                text = self.text(real)
            except (OSError, Refused):
                continue
            if query not in (text.lower() if fold else text):
                continue
            for i, line in enumerate(text.split('\n')):
                if query in (line.lower() if fold else line):
                    if len(results) == n:
                        return {'results': results, 'truncated': True}
                    results.append({'path': self.relative(real), 'line': i + 1,
                                    'text': line.strip()[:MAX_FOUND]})
        return {'results': results, 'truncated': False}

    def read(self, path, start, end):
        real = self.resolve(path)
        if os.path.isdir(real):
            names = sorted(os.listdir(real))
            paths = {x: os.path.join(real, x) for x in names}
            return {'path': self.relative(real), 'entries':
                    [x + '/' for x in names
                     if os.path.isdir(paths[x]) and self.searched(real, x)] +
                    [x for x in names if self.program(x) and os.path.isfile(paths[x]) and
                     self.allowed(os.path.realpath(paths[x]))]}
        if not self.program(os.path.basename(real)):
            raise Refused('Not a file of the source (C++, parser, CMake, Python, '
                          '.geo or documentation): ' + path)
        lines = self.text(real).split('\n')
        if lines[-1] == '':
            lines.pop()
        start = max(start or 1, 1)
        if start > len(lines):
            raise Refused('%s has %d lines' % (path, len(lines)))
        end = min(end or start + 199, start + MAX_LINES - 1, len(lines))
        out, size = [], 0
        for i in range(start - 1, end):
            line = '%6d\t%s' % (i + 1, lines[i][:MAX_LINE])
            if out and size + len(line) > MAX_TEXT:
                end = i
                break
            out.append(line)
            size += len(line) + 1
        return {'path': self.relative(real), 'start_line': start, 'end_line': end,
                'total_lines': len(lines), 'content': '\n'.join(out)}


class Handler(SimpleHTTPRequestHandler):
    extensions_map = {**SimpleHTTPRequestHandler.extensions_map,
                      '.mjs': 'text/javascript', '.wasm': 'application/wasm'}
    source = None

    def do_GET(self):
        url = urlsplit(self.path)
        if not url.path.startswith('/source/'):
            return super().do_GET()
        host = self.headers.get('Host', '')
        host = host[:host.find(']') + 1] if host.startswith('[') else host.split(':')[0]
        if host not in LOCAL:
            return self.answer(403, {'error': 'The source is given only to the '
                                     'pages of this machine'})
        q = {k: v[0] for k, v in parse_qs(url.query).items()}
        number = lambda k: int(q[k]) if q.get(k) else None
        try:
            what = url.path[len('/source/'):]
            if what == 'info':
                body = self.source.info()
            elif what == 'search':
                body = self.source.search(q.get('query', ''), q.get('path'),
                                          number('max_results'))
            elif what == 'read':
                body = self.source.read(q.get('path', ''), number('start_line'),
                                        number('end_line'))
            else:
                return self.answer(404, {'error': 'No ' + url.path})
        except ValueError:
            return self.answer(400, {'error': 'Numbers expected'})
        except Refused as e:
            return self.answer(403, {'error': str(e)})
        except OSError as e:
            return self.answer(404, {'error': e.strerror or str(e)})
        self.answer(200, body)

    def answer(self, status, body):
        data = json.dumps(body).encode()
        self.send_response(status)
        self.send_header('Content-Type', 'application/json')
        self.send_header('Cache-Control', 'no-store')
        self.send_header('Content-Length', str(len(data)))
        self.end_headers()
        self.wfile.write(data)


def main():
    tree = os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__))))
    p = argparse.ArgumentParser(description='Serve the web app and the source of '
                                'Gmsh to its assistant, read only')
    p.add_argument('port', nargs='?', type=int, default=8000)
    p.add_argument('--bind', default='127.0.0.1')
    p.add_argument('--directory', default=tree, help='the tree served (this one)')
    p.add_argument('--source', help='the tree given to the assistant (the one served)')
    a = p.parse_args()
    Handler.source = Source(a.source or a.directory)
    info = Handler.source.info()
    print('Serving http://%s:%d/contrib/webapp/onelab.html (%s), the source of %s%s'
          % ('localhost' if a.bind == '127.0.0.1' else a.bind, a.port, a.directory,
             Handler.source.root, ' (' + info['branch'] + ')' if info['branch'] else ''),
          flush=True)
    server = ThreadingHTTPServer((a.bind, a.port),
                                 lambda *args: Handler(*args, directory=a.directory))
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == '__main__':
    main()
