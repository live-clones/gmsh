#!/usr/bin/env python3
"""Exercise Plugin(MatGmsh) through the native executable, without the Python API.

Usage: python3 check_app_plugin_smoke.py --gmsh build/gmsh [--output NEW_DIR]
Outputs and the application log remain in NEW_DIR, or a new temporary directory.
"""
import argparse
import json
from pathlib import Path
import re
import subprocess
import tempfile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--gmsh', type=Path, required=True)
    parser.add_argument('--output', type=Path)
    parser.add_argument('--timeout', type=float, default=120.)
    args = parser.parse_args()
    if args.output:
        directory = args.output.resolve()
        directory.mkdir(parents=True, exist_ok=False)
    else:
        directory = Path(tempfile.mkdtemp(prefix='gmsh-native-plugin-'))
    quote = lambda path: json.dumps(str(path), ensure_ascii=False)
    geometry = directory/'plate.geo'
    geometry.write_text(f'''General.NumThreads = 1;
General.Terminal = 1;
SetFactory("OpenCASCADE");
Box(1) = {{-2, -1, -.4, 4, 2, .8}};
Mesh.MeshSizeMin = .4;
Mesh.MeshSizeMax = .4;
Mesh 2;
Mesh.MshFileVersion = 4.1;
Mesh.Binary = 1;
Mesh.SaveAll = 1;
Save {quote(directory/'source-before.msh')};
Plugin(MatGmsh).Thickness = .8;
Plugin(MatGmsh).Stage = 1;
Plugin(MatGmsh).Project = 1;
Plugin(MatGmsh).ShowStages = 1;
Plugin(MatGmsh).OutputPrefix = {quote(directory/'plugin')};
Plugin(MatGmsh).Run;
Save {quote(directory/'source-after.msh')};
''')
    failures = []
    command = [str(args.gmsh.resolve()), str(geometry), '-0', '-nopopup', '-v', '5']
    try:
        process = subprocess.run(command, stdout=subprocess.PIPE,
                                 stderr=subprocess.STDOUT, text=True,
                                 timeout=args.timeout)
        log, exit_code = process.stdout, process.returncode
    except (OSError, subprocess.TimeoutExpired) as error:
        log, exit_code = str(error), None
        failures.append('Application could not complete: ' + str(error))
    (directory/'application.log').write_text(log)
    if exit_code != 0:
        failures.append('Application exit code is not zero: ' + str(exit_code))
    errors = [line for line in log.splitlines() if re.search(r'\bError\b', line)]
    if errors:
        failures.append('Application printed Error diagnostics even if its exit code was zero')
    before, after = directory/'source-before.msh', directory/'source-after.msh'
    same_source = before.is_file() and after.is_file() and before.stat().st_size > 0
    same_source = bool(same_source and before.read_bytes() == after.read_bytes())
    if not same_source:
        failures.append('Source snapshots are missing, empty or differ byte for byte')
    sizes = {}
    for stage in ('raw', 'filtered', 'projected'):
        path = directory/('plugin_' + stage + '.msh')
        sizes[stage] = path.stat().st_size if path.is_file() else 0
        if not sizes[stage]:
            failures.append('Missing or empty plugin snapshot: ' + stage)
    report = {}
    try:
        report = json.loads((directory/'plugin_report.json').read_text())
        for stage in sizes:
            if report.get('stages', {}).get(stage, {}).get('triangles', 0) <= 0:
                failures.append('Report lacks nonempty stage: ' + stage)
        if report.get('projection_status') not in ('applied', 'unchanged'):
            failures.append('Requested projection was not executed or explicitly retained')
    except (OSError, ValueError, TypeError) as error:
        failures.append('Missing or invalid plugin report: ' + str(error))
    result = dict(passed=not failures, failures=failures, exit_code=exit_code,
                  source_byte_identical=same_source, snapshot_bytes=sizes,
                  projection_status=report.get('projection_status'),
                  error_diagnostics=errors, directory=str(directory))
    (directory/'app-plugin-smoke.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result))
    return 0 if result['passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
