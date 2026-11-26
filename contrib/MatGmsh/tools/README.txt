MatGmsh: face-pairing walls, fusion and evaluator
=================================================

These files complete the MAT into a mid-surface and score it on the corpus
of benchmarks/MAT. They are unmodified copies, taken on 25 November 2026 from
the MatGmsh repository (commit 50f3a57 plus its uncommitted working tree);
nothing here is compiled by the Gmsh build. benchmarks/MAT/run_corpus.py
drives them.

contrib/MatGmsh/facepair/ (from tools/facepair/)

  fuse.py, hybrid.py   Fusion of a filtered MAT mesh with the walls. A wall
                       triangle is kept where it agrees with the MAT or lies
                       at mid-thickness of the part; with --gentle the MAT
                       triangles covered by a kept wall are removed. No node
                       is moved. Used as
                         fuse.py MAT.msh WALLS.brep THICKNESS OUT.msh --gentle --part PART.stp
  facepair.cpp, facepair_brep.cpp, facepair_trim.cpp, facepair.py, steps.py
                       Generator of the walls: opposite CAD faces found by
                       ray casting, offset to mid-thickness and extended into
                       the material. NOT run by run_corpus.py: the corpus
                       ships the walls computed on 9 October 2026
                       (<case>_mid_ext.brep). Regenerating them also needs
                       the trained pairing model (build/facepair/model.pkl of
                       the MatGmsh repository) and OpenCASCADE; the sources
                       copied here contain edits made after 9 October, so
                       they are not guaranteed to reproduce the shipped walls.

contrib/MatGmsh/tools/evaluation/ (from tests/ and tests/corpus/)

  projected_quality.py The evaluator (sha256 64c43774...). measure() samples
                       the truth mid-surface and the result, and returns the
                       missing area and the area off the truth, in units of
                       the local thickness squared, the interior coverage and
                       a verdict:
                         perfect  coverage >= 0.999, off truth <= 0.1, worst gap <= 0.1 t
                         good     coverage >= 0.99,  off truth <= 1,   worst gap <= 0.25 t
                         review   otherwise
  label_branches.py, run_corpus.py, generate_corpus.py, direct_midsurface_cases.py
                       Modules it imports.
  tessellate.cpp       OpenCASCADE tessellator, compiled on first use.

Layout. The scripts locate each other, and the Gmsh Python API, relative to
their original repository: <repo>/tools/facepair, <repo>/tests,
<repo>/tests/corpus and <repo>/../gmsh/{api/gmsh.py, build/libgmsh.*}.
run_corpus.py copies them into that layout under <output>/stage, with this
tree's api/gmsh.py and a link to the library of the build directory.

SHA-256 of the copies

d61459d82f27d9b147d7f93062cc86b62538aebc1d4c09e9bfbe96397e474721  facepair/facepair.cpp
dc30b244e3f62731774494e51c94281c11cd86627630a3ecd3455958f20f6b8b  facepair/facepair.py
982eecabc154a478cff4c876e644d7cbf454560d8450daf2e86d57f9727f5360  facepair/facepair_brep.cpp
cfc42887bfd3fd8f2d1d34446e4e09b0bd46999b1e4f82e83637c7d0bec50d5f  facepair/facepair_trim.cpp
bef93362eb1dd1080700fa0cdaa6dc027fc1118096ff52cf25cf3ae9c6b77f6b  facepair/fuse.py
17d946c3ed957f563360507d13504068fb2d580bf1189b0365138ed47ef8f24a  facepair/hybrid.py
aae6203feceacf3dc1f2db5742c0063567bfc90a02aa795f4f0f0dfccd0c0613  facepair/steps.py
6427fed6bf02f6ca6287fe33a712001e1bcdffb8827ae467bfb9132d759e8d4c  tools/evaluation/direct_midsurface_cases.py
36893af0245b076d2ba6bd57025702501c478aded3d1e991b78e06a8cefa6aba  tools/evaluation/generate_corpus.py
3980db52d2125a6b5898f0dd37f9b54a92e77e20d0774008f3a483ebce8c8dee  tools/evaluation/label_branches.py
64c437748f8d5930d9ba4d086c8cc5dfa150c1020ab3aad8512c15a4489f071a  tools/evaluation/projected_quality.py
53e988c9450303c8d88cf17528916255cdd432e0bcaae79669ef0a60514f6c35  tools/evaluation/run_corpus.py
a54b48f72765bf4482342a1195b06514bcdfdd865f062bef99fa9e43de889817  tools/evaluation/tessellate.cpp

contrib/MatGmsh/tools/topology/ (written for this tree, 26 November 2026)

  surface_topology.py  Components, Euler characteristic, sheets, junction
                       networks and free boundaries of a filtered or extended
                       MAT (an MSH file of gmshMat) and of the truth
                       mid-surface meshed by Gmsh, by the same code. Used for
                       the topology tables of VALIDATION.txt.
  branches_through.py  Where a branch of the mid-surface saved by the
                       Midsurfacer window (Save..., one surface per branch)
                       goes through another one: edges of two triangles of a
                       branch lying on a triangle of another branch, with the
                       two triangles on its two sides. An extended branch
                       must stop on the sheets it meets.
