#!/usr/bin/env python3
"""Link an isolated V2 runner using the other objects of an existing Gmsh build.

Build the common `gmsh` target first, after any shared header or source change.
Each strategy compiles its own V2 and Winslow sources without rebuilding Gmsh. This
uses CMake's Unix Makefiles flags/link files; it does not depend on visibility
or symbol interposition in libgmsh and works with hidden C++ symbols on macOS.
"""

import argparse
import hashlib
import json
from pathlib import Path
import shlex
import subprocess
import sys


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path,
                        default=Path(__file__).resolve().parents[2])
    parser.add_argument("--build", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    source, build, output = (p.resolve() for p in
                             (args.source, args.build, args.output))
    cache = (build / "CMakeCache.txt").read_text()
    original_source = next(
        Path(line.split("=", 1)[1]).resolve() for line in cache.splitlines()
        if line.startswith("CMAKE_HOME_DIRECTORY:INTERNAL="))
    target = build / "CMakeFiles/gmsh.dir"
    make_flags = {}
    for line in (target / "flags.make").read_text().splitlines():
        if " = " in line:
            key, value = line.split(" = ", 1)
            make_flags[key] = shlex.split(value)

    def relocate(argument):
        # Generated headers come from the common build; source headers and
        # the newly compiled translation units come from the worktree.
        prefix = "-I" if argument.startswith("-I") else ""
        value = argument[len(prefix):]
        if value == str(build) or value.startswith(str(build) + "/"):
            return argument
        if value == str(original_source):
            return prefix + str(source)
        if value.startswith(str(original_source) + "/"):
            return prefix + str(source / Path(value).relative_to(original_source))
        return argument

    flags = [relocate(item) for key in
             ("CXX_DEFINES", "CXX_INCLUDES", "CXX_FLAGS")
             for item in make_flags[key]]
    link = shlex.split((target / "link.txt").read_text())
    compiler = link[0]
    objects = output.parent / (output.name + ".objects")
    objects.mkdir(parents=True, exist_ok=True)
    compiled = {}
    commands = []
    for name in ("quadV2StrategyMain.cpp", "smallCavityOptimizerV2.cpp",
                 "smallCavityWinslow.cpp"):
        translation_unit = source / "contrib/QuadOptimizer" / name
        object_path = objects / (name + ".o")
        command = [compiler, *flags, "-c", str(translation_unit),
                   "-o", str(object_path)]
        print(f"Compiling {translation_unit}", flush=True)
        subprocess.run(command, cwd=build, check=True)
        commands.append(command)
        compiled[name] = object_path

    replacements = {
        "CMakeFiles/gmsh.dir/src/common/Main.cpp.o":
            compiled["quadV2StrategyMain.cpp"],
        "CMakeFiles/gmsh.dir/contrib/QuadOptimizer/smallCavityOptimizerV2.cpp.o":
            compiled["smallCavityOptimizerV2.cpp"],
        "CMakeFiles/gmsh.dir/contrib/QuadOptimizer/smallCavityWinslow.cpp.o":
            compiled["smallCavityWinslow.cpp"],
    }
    for old, new in replacements.items():
        if link.count(old) != 1:
            raise RuntimeError(f"Expected exactly one {old} in the gmsh link command")
        link[link.index(old)] = str(new)
    if link.count("-o") != 1:
        raise RuntimeError("Cannot identify gmsh link output")
    link[link.index("-o") + 1] = str(output)
    print(f"Linking {output}", flush=True)
    subprocess.run(link, cwd=build, check=True)
    commands.append(link)
    files = (
        "contrib/QuadOptimizer/quadV2StrategyMain.cpp",
        "contrib/QuadOptimizer/smallCavityOptimizerV2.cpp",
        "contrib/QuadOptimizer/smallCavityOptimizer.h",
        "contrib/QuadOptimizer/halfEdge.h",
        "contrib/QuadOptimizer/halfEdge.cpp",
        "contrib/QuadOptimizer/halfEdgeMesh.h",
        "contrib/QuadOptimizer/quadQuality.cpp",
        "contrib/QuadOptimizer/smallCavityOptimizer.cpp",
        "contrib/QuadOptimizer/smallCavityWinslow.cpp",
        "contrib/QuadOptimizer/smallCavityWinslow.h",
        "contrib/QuadOptimizer/quadCadDistance.h",
        "contrib/QuadOptimizer/quadGeometryGuard.h",
        "contrib/QuadOptimizer/quadSmartLaplacian.h",
        "contrib/QuadOptimizer/quadSurfaceWinslow3D.h",
        "contrib/QuadOptimizer/smallCavityOptimizerV2.h",
        "contrib/QuadOptimizer/halfEdgeRewriteCatalog.h",
    )
    manifest = {
        "source": str(source), "commonBuild": str(build),
        "output": str(output), "commands": commands,
        "sourceSha256": {
            name: hashlib.sha256((source / name).read_bytes()).hexdigest()
            for name in (*files, "contrib/QuadOptimizer/quadQualityLedger.h",
                         "contrib/QuadOptimizer/quadPatchSearch.h")
            if (source / name).is_file()
        },
        "runnerSha256": hashlib.sha256(output.read_bytes()).hexdigest(),
    }
    output.with_name(output.name + ".build.json").write_text(
        json.dumps(manifest, indent=2) + "\n")
    print(output)


if __name__ == "__main__":
    try:
        main()
    except (OSError, RuntimeError, subprocess.CalledProcessError) as error:
        print(f"buildQuadV2Strategy: {error}", file=sys.stderr)
        sys.exit(1)
