#!/usr/bin/env python3
# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

"""What the interfaces may include, checked.

src/gui/Backend.h states two rules and nothing enforces them: the vocabulary
of src/gui includes nothing of Gmsh and names no toolkit, and an interface --
src/fltk, src/imgui, src/browser -- builds widgets from that vocabulary and
never reaches into Gmsh. This is the check. It reads the quoted #include
lines of every file of those four directories and complains about any header
that is not on the list of what the directory may see.

What a directory may see:

  src/gui        its own headers, and nothing else;
  src/browser    its own, src/gui, OS.h and GmshConfig.h;
  src/imgui      the same, the Dear ImGui headers, and src/scene, which is
                 the contract of the 3D scene and a chantier of its own;
  src/fltk       the same as the browser (FLTK's own headers come in angle
                 brackets and are not looked at).

The scene itself speaks Gmsh through and through, on purpose, and its files
are left out altogether: they are listed in SCENE below.

Everything that breaks the rule today is in TOLERATED, file by file, with the
section of the plan that is to make it go away. The list is a ratchet: a
header that appears and is not listed fails the check, and so does a listed
one that is no longer included, so that the list shrinks as the work is done
and never quietly grows. When a line of it goes, delete it here.

Run with the root of the tree as the only argument; ctest does.
"""

import glob
import os
import re
import sys

ALWAYS = {"OS.h", "GmshConfig.h"}

# the 3D scene of each interface, which is not held to the rule
SCENE = {
    "src/imgui/SceneImGui.cpp",
    "src/fltk/SceneFltk.cpp",
    "src/fltk/openglWindow.cpp", "src/fltk/openglWindow.h",
    "src/fltk/drawContextFltk.h",
    "src/fltk/drawContextFltkCairo.cpp", "src/fltk/drawContextFltkCairo.h",
    "src/fltk/drawContextFltkStringTexture.cpp",
    "src/fltk/drawContextFltkStringTexture.h",
    "src/fltk/graphicsFonts.cpp", "src/fltk/graphicsFonts.h",
    "src/fltk/Navigator.cpp", "src/fltk/Navigator.h",
}

# What still breaks the rule, and which part of the plan takes it away. The
# plan is gmsh-imgui-plan.md, beside this tree; its sections are cited.
TOLERATED = {
    # --- Dear ImGui: the settings it reads off CTX and the calls it makes
    # into the facade (1.3), and the export options it writes by hand (1.4c)
    # what is left is the draw context of the scene, which this window
    # installs and hands to its panes: the scene, not the interface
    "src/imgui/appWindow.cpp": {"drawContext.h"},
    "src/imgui/contextPanels.cpp": {
        "Gui.h", "GuiActions.h", "GmshMessage.h", "GmshDefines.h",
        "drawContext.h"},
    "src/imgui/exportDialog.cpp": {
        "Gui.h", "GmshDefines.h", "Context.h", "Options.h"},
    "src/imgui/shortcuts.cpp": {
        "GuiActions.h", "GuiMenus.h", "Gui.h", "GmshMessage.h"},
    # --- FLTK: an adapter over the interface that was, until 1.4 makes it a
    # backend like the two others
    "src/fltk/CreateFileFltk.cpp": {"drawContext.h", "PixelBuffer.h",
                                    "Context.h"},
    "src/fltk/FlGui.cpp": {
        "Gui.h", "GuiActions.h", "GuiDialogs.h", "GuiStatus.h",
        "GmshDefines.h", "GmshMessage.h", "GModel.h", "MElement.h", "PView.h",
        "Plugin.h", "PluginManager.h", "OpenFile.h", "Options.h",
        "CommandLine.h", "Context.h", "StringUtils.h", "gl2ps.h",
        "gmshPopplerWrapper.h", "PixelBuffer.h", "Field.h", "3M.h"},
    "src/fltk/FlGui.h": {"SPoint2.h"},
    "src/fltk/extraDialogs.cpp": {
        "GmshDefines.h", "OpenFile.h", "CreateFile.h", "Options.h",
        "drawContext.h", "GModel.h", "Context.h", "PView.h"},
    "src/fltk/fileDialogs.cpp": {
        "GmshMessage.h", "GmshDefines.h", "StringUtils.h", "GuiDialogs.h",
        "CreateFile.h", "Options.h", "Context.h", "GModel.h", "PView.h",
        "PViewOptions.h"},
    "src/fltk/graphicWindow.cpp": {
        "GmshDefines.h", "GmshVersion.h", "GuiActions.h", "GuiDialogs.h",
        "Gui.h", "GuiMenus.h", "gmshLocalNetworkClient.h", "GModel.h",
        "PView.h", "PViewData.h", "PViewOptions.h", "OpenFile.h",
        "CreateFile.h", "findLinks.h", "scriptStringInterface.h",
        "CommandLine.h", "Options.h", "Context.h", "StringUtils.h",
        "onelabUtils.h", "gmshCrossFields.h", "3M.h"},
    "src/fltk/graphicWindow.h": {"GuiActions.h", "GuiStatus.h"},
    "src/fltk/inputRange.h": {"Context.h"},
    "src/fltk/menuFltk.cpp": {"GuiMenus.h"},
    "src/fltk/menuFltk.h": {"GuiMenus.h"},
    "src/fltk/onelabGroup.cpp": {
        "GmshMessage.h", "onelab.h", "gmshLocalNetworkClient.h",
        "GuiModules.h", "GuiActions.h", "GuiOnelab.h", "GuiMenus.h",
        "GmshGlobal.h", "Context.h", "GModel.h", "GmshDefines.h", "Options.h",
        "StringUtils.h", "onelabUtils.h", "OpenFile.h", "CreateFile.h",
        "drawContext.h", "PView.h", "PViewOptions.h"},
    "src/fltk/onelabGroup.h": {"onelab.h"},
    "src/fltk/solverButton.cpp": {"GmshMessage.h", "Options.h", "GuiMenus.h",
                                  "GuiActions.h"},
    "src/fltk/touchBar.mm": {"GuiActions.h", "drawContext.h", "Options.h",
                             "PView.h"},
    "src/fltk/viewButton.cpp": {
        "GuiDialogs.h", "drawContext.h", "Context.h", "GModel.h", "PView.h",
        "PViewData.h", "PViewOptions.h", "Options.h", "OpenFile.h",
        "GuiMenus.h", "GuiActions.h", "Field.h"},
}

INCLUDE = re.compile(r'\s*#\s*include\s+"([^"]+)"')


def headers_of(directory):
    """the names of the headers a directory holds"""
    return {os.path.basename(p) for p in glob.glob(os.path.join(directory,
                                                                 "*.h"))}


def sources_of(directory):
    """every source and header of a directory, in a stable order"""
    files = []
    for pattern in ("*.cpp", "*.h", "*.mm"):
        files += glob.glob(os.path.join(directory, pattern))
    return sorted(files)


def check(root):
    gui = headers_of(os.path.join(root, "src", "gui"))
    scene = headers_of(os.path.join(root, "src", "scene"))
    problems = []
    for name in ("gui", "browser", "imgui", "fltk"):
        directory = os.path.join(root, "src", name)
        own = headers_of(directory)
        allowed = set(own)
        if name != "gui":
            allowed |= gui | ALWAYS
        if name == "imgui":
            allowed |= scene
        for path in sources_of(directory):
            rel = os.path.relpath(path, root).replace(os.sep, "/")
            if rel in SCENE:
                continue
            tolerated = TOLERATED.get(rel, set())
            seen = set()
            with open(path, errors="replace") as f:
                for line in f:
                    m = INCLUDE.match(line)
                    if not m:
                        continue
                    header = m.group(1)
                    if header in allowed:
                        continue
                    if name == "imgui" and header.startswith("imgui"):
                        continue
                    seen.add(header)
                    if header not in tolerated:
                        problems.append("%s includes %s, which an interface "
                                        "may not see (see Backend.h)" %
                                        (rel, header))
            for header in sorted(tolerated - seen):
                problems.append("%s no longer includes %s: take it off the "
                                "list in %s" %
                                (rel, header,
                                 os.path.relpath(__file__, root)))
    return problems


if __name__ == "__main__":
    root = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        os.path.dirname(os.path.abspath(__file__)), "..", "..")
    problems = check(os.path.abspath(root))
    for p in problems:
        print(p)
    if problems:
        print("%d problem(s)" % len(problems))
        sys.exit(1)
    print("the interfaces include only what they may")
