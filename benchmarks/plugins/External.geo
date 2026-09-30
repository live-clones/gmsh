// Plugin(ElementAverage) of examples/api/plugin, loaded from a shared library
// in a directory of GMSHPLUGINSHOME (run.py builds it): the averages of the
// scalar view of triangles, model and list data, 3 steps
Merge "data/square.msh";
Merge "data/square.pos";
Plugin(ElementAverage).View = 0;
Plugin(ElementAverage).Run;
Plugin(ElementAverage).View = 4;
Plugin(ElementAverage).Scale = 2;
Plugin(ElementAverage).Name = "Twice";
Plugin(ElementAverage).Run;
