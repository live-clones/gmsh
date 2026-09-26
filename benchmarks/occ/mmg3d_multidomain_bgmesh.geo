// Hanging nodes on a shared internal interface with Mesh.Algorithm3D = 7 (MMG3D)
// and Mesh.MMG3DCombineDomains = 1.
//
// Two unit boxes touching at x = 1, made conformal with BooleanFragments, so they share one
// internal interface surface. The mesh is then adapted in the usual two-pass way: an initial
// isotropic mesh is generated, discarded, and regenerated against an anisotropic metric supplied
// as a *list-based* tensor PostView (mmg3d_multidomain_bgmesh.pos). The metric is piecewise
// constant per volume, hence discontinuous across the interface:
//
//     volume 1 (0 < x < 1): h_x = 0.02, h_y = h_z = 0.1   (M = diag(2500, 100, 100))
//     volume 2 (1 < x < 2): h   = 0.2                     (M = diag(25, 25, 25))
//
// EXPECTED: the interface triangulation contains every node that the tetrahedra of both volumes
// use, i.e. the surface mesh and the volume meshes agree on the interface.
//
// OBSERVED with Mesh.MMG3DCombineDomains = 1: a few nodes lying exactly on the interface plane
// x = 1 are used by tetrahedra of BOTH volumes yet belong to no triangle of the interface
// surface -- hanging nodes. The count varies between runs (typically 1 to 20). Those nodes are
// also classified on a GRegion (the opposite volume) rather than on the interface GFace, so
// gmsh.model.mesh.getNodes(3, vol, includeBoundary=True) does not return them.
//
// With Mesh.MMG3DCombineDomains = 0 (independent per-region MMG3D calls) the same geometry and
// metric give 0 hanging nodes, reproducibly.
//
// The two-pass structure is REQUIRED to trigger it. Meshing once against the same .pos field
// gives 0 hanging nodes, as do a uniform isotropic size and a smoothly varying MathEvalAniso
// field. Both the discontinuous metric and the Delete Meshes / re-mesh cycle are needed.
//
// Check the result with the gmsh Python API (do NOT re-mesh -- this file meshes itself):
//
//     import gmsh, numpy as np
//     gmsh.initialize(); gmsh.open("mmg3d_multidomain_bgmesh.geo")
//     vols = [t for _, t in gmsh.model.getEntities(3)]
//     def used(v):
//         ts, _, ns = gmsh.model.mesh.getElements(dim=3, tag=v)
//         return {int(k) for t, n in zip(ts, ns)
//                 if gmsh.model.mesh.getElementProperties(t)[3] == 4
//                 for k in np.asarray(n).reshape(-1)}
//     tri = set()
//     for _, s in gmsh.model.getEntities(2):
//         ts, _, ns = gmsh.model.mesh.getElements(dim=2, tag=s)
//         for t, n in zip(ts, ns):
//             if gmsh.model.mesh.getElementProperties(t)[3] == 3:
//                 tri |= {int(k) for k in np.asarray(n).reshape(-1)}
//     shared = used(vols[0]) & used(vols[1])
//     print("hanging nodes on interface:", len(shared - tri))   # 0 expected, > 0 observed

SetFactory("OpenCASCADE");

Box(1) = {0, 0, 0, 1, 1, 1};
Box(2) = {1, 0, 0, 1, 1, 1};
BooleanFragments{ Volume{1, 2}; Delete; }{}

General.NumThreads = 1;          // not a threading issue
Mesh.SaveAll = 1;                // keep surface elements in the output

// ---- pass 1: plain isotropic mesh -------------------------------------------------------
Mesh.MeshSizeMax = 0.15;
Mesh 3;

// ---- pass 2: discard it and remesh against the anisotropic background field --------------
Delete Meshes;

Merge "mmg3d_multidomain_bgmesh.pos";
Field[1] = PostView;
Field[1].ViewIndex = 0;
Background Field = 1;

Mesh.Algorithm = 7;              // BAMG (anisotropic surface mesh)
Mesh.Algorithm3D = 7;            // MMG3D (the only 3D algorithm honouring a tensor)
Mesh.MeshSizeFromPoints = 0;
Mesh.MeshSizeFromCurvature = 0;
Mesh.MeshSizeExtendFromBoundary = 0;
Mesh.MMG3DCombineDomains = 1;    // set to 0 for the working per-region path
Mesh 3;
