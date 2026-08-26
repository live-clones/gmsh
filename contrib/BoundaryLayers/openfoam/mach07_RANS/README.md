# Mach 0.7 RANS OpenFOAM template

This is a small OpenFOAM template for testing Gmsh boundary-layer meshes with a
compressible steady RANS computation.

The intended solver is `rhoSimpleFoam` with the `kOmegaSST` model. The freestream
state is deliberately simple:

- Mach number: 0.7
- Static pressure: 101325 Pa
- Static temperature: 300 K
- Air: gamma = 1.4, R = 287 J/(kg K)
- Speed of sound: about 347.2 m/s
- Freestream velocity: (243 0 0) m/s
- Turbulence intensity: 0.5 %
- Turbulence length scale: 1 m
- k = 2.214675 m2/s2
- omega = 2.712 1/s

## Mesh

OpenFOAM needs a volume mesh. A pure 2D Gmsh surface mesh must be extruded into a
thin one-cell volume mesh, with `front`/`back` patches set to `empty`.

The expected patch names are:

- `inlet`
- `outlet`
- `farfield` or `outer`
- `wall` or `body`
- `frontAndBack` for 2D cases

After `gmshToFoam`, check and edit `constant/polyMesh/boundary` if needed:

- wall/body patches should have type `wall`;
- front/back patches in a 2D extrusion should have type `empty`;
- inlet/outlet/farfield patches should have type `patch`.

## Running

Copy or link a Gmsh volume mesh as `mesh.msh` in this directory, then run:

```sh
./Allrun mesh.msh
```

or manually:

```sh
gmshToFoam mesh.msh
checkMesh -allTopology -allGeometry
rhoSimpleFoam
```

If your OpenFOAM installation is the Foundation v13 modular solver layout, the
equivalent solver command may be `foamRun -solver compressibleFluid`; keep the
same dictionaries as a starting point, then adjust to the installed tutorials if
OpenFOAM reports renamed fields.
