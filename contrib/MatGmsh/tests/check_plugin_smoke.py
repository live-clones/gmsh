#!/usr/bin/env python3
"""Optional native plugin smoke test against an explicitly selected Gmsh build."""
import argparse
import json
from pathlib import Path
import types


def load_api(api, library_directory):
    # The generated API resolves the shared library relative to __file__.
    # Execute it with the selected build directory, without changing the API
    # file or relying on an independently installed Gmsh package.
    module = types.ModuleType('gmsh_native_plugin_smoke')
    module.__file__ = str(library_directory.resolve() / 'gmsh.py')
    exec(compile(api.read_text(), str(api), 'exec'), module.__dict__)
    return module


def plain(value):
    if isinstance(value, (tuple, list)):
        return [plain(item) for item in value]
    if hasattr(value, 'tolist'):
        return value.tolist()
    return value


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--api', type=Path, required=True)
    parser.add_argument('--library-directory', type=Path, required=True)
    parser.add_argument('--geometry', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=False)
    gmsh = load_api(args.api, args.library_directory)
    gmsh.initialize()
    try:
        gmsh.option.setNumber('General.Terminal', 0)
        gmsh.option.setNumber('General.NumThreads', 1)
        gmsh.open(str(args.geometry.resolve()))
        gmsh.option.setNumber('Mesh.MeshSizeMin', .4)
        gmsh.option.setNumber('Mesh.MeshSizeMax', .4)
        gmsh.model.mesh.generate(2)

        def snapshot():
            return plain((gmsh.model.list(), gmsh.model.getCurrent(),
                          gmsh.model.getEntities(), gmsh.model.mesh.getNodes(),
                          gmsh.model.mesh.getElements(),
                          gmsh.option.getNumber('Mesh.Algorithm3D'),
                          gmsh.option.getNumber('Mesh.RandomFactor3D')))

        before = snapshot()
        old_views = set(gmsh.view.getTags())
        gmsh.plugin.setNumber('MatGmsh', 'Thickness', .8)
        gmsh.plugin.setNumber('MatGmsh', 'Stage', 1)
        gmsh.plugin.setNumber('MatGmsh', 'Project', 1)
        gmsh.plugin.setNumber('MatGmsh', 'ShowStages', 1)
        gmsh.plugin.setString('MatGmsh', 'OutputPrefix', str((args.output/'plugin').resolve()))
        final_view = gmsh.plugin.run('MatGmsh')
        new_views = [int(tag) for tag in gmsh.view.getTags() if tag not in old_views]
        unchanged = before == snapshot()
        counts = {str(tag): int(sum(gmsh.view.getListData(tag)[1])) for tag in new_views}
        passed = unchanged and len(new_views) == 3 and final_view in new_views and all(counts.values())
        result = dict(passed=passed, source_unchanged=unchanged,
                      added_views=new_views, final_view=final_view,
                      triangle_counts=counts)
        (args.output/'plugin-smoke.json').write_text(json.dumps(result, indent=2)+'\n')
        print(json.dumps(result))
        return 0 if passed else 1
    finally:
        gmsh.finalize()


if __name__ == '__main__':
    raise SystemExit(main())
