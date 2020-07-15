## Embed a point in a curve

Gmsh supports embedding arbitrary points in surfaces and volumes, but not for curves.

We can provide this feature ourselves by segmenting the curve at the given point.
This requires the `OpenCASCADE` kernel. 

### Python
```python
{{#include embed-point.py}}
```
