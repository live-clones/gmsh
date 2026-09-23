// Plugin(ExtractElements): elements of tetrahedra, hexahedra and triangles
// with values in a range, at the first, last or all steps, model and list
// data, scalar, vector and cell data; by dimension; all visible elements

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(ExtractElements).MinVal = 0.5;
Plugin(ExtractElements).MaxVal = 1.5;
views() = {0, 1, 3, 4, 5, 7};
For i In {0 : #views() - 1}
  Plugin(ExtractElements).View = views(i);
  Plugin(ExtractElements).Run;
EndFor
Plugin(ExtractElements).View = 0;
Plugin(ExtractElements).TimeStep = 2;
Plugin(ExtractElements).Run;
Plugin(ExtractElements).TimeStep = -1;
Plugin(ExtractElements).Run;
Plugin(ExtractElements).TimeStep = 0;
Plugin(ExtractElements).MinVal = 0;
Plugin(ExtractElements).MaxVal = 0;
Plugin(ExtractElements).Run;

Merge "data/hexes.pos";
Plugin(ExtractElements).MinVal = 0.5;
Plugin(ExtractElements).MaxVal = 1.5;
Plugin(ExtractElements).View = PostProcessing.NbViews - 4;
Plugin(ExtractElements).Run;

Merge "data/square.pos";
Plugin(ExtractElements).View = PostProcessing.NbViews - 4;
Plugin(ExtractElements).Run;
Plugin(ExtractElements).Dimension = 2;
Plugin(ExtractElements).Run;
Plugin(ExtractElements).Dimension = 1;
Plugin(ExtractElements).Run;
