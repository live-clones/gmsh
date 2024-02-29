# Mesh closed surface

```
cd highOrderSurface
mkdir build
cd build
gmsh Vertebra.stl -geodesic -clmax 2.5 -nt 12
python code.py 
```
| flag | default | option |
|:--:|:--:|:--|
| -f | ``\`` | Geo file used to affect nodes to entities |
| -d | 4 | Order of the approximating elements |

# Mesh plane surface

### Construct geodesics:
```
cd planeMesh
mkdir build
cd build
cmake ..
make
./expansion -f ../planeMesh/0.geo
```
| flag | default | option |
|:--:|:--:|:--|
| -f | ``../0.geo`` | Geo file |
| -clscale | 50 | Scale factor for the macro mesh |
| -clrefine | 1 | Scale factor for the micro mesh |
| -refineOption | 0 | Method to refine the macro mesh (from 0 to 2) |
| -r | 1 | Coefficient applied to the surface deformation |


### Construct high order polynomial elements:
```
python ../../highOrderSurface/code.py -f ../planeMesh/0.geo
```


### Solve the Laplace equation (only for ``0.geo``):
```
./poisson
gmsh v.msh
```
