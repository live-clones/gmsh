// Filtered MAT of the Doghouse with Plugin(MatGmsh): the skin is meshed at the
// size of Doghouse.geo, then the plugin adds the MAT as a view colored by
// sheet (the raw MAT is available as a hidden view). The plugin reports the
// certificate of the interior tetrahedra and the collapse in the message
// console. Needs a Gmsh built with ENABLE_MATGMSH.
Include "Doghouse.geo";
Mesh 2;
Plugin(MatGmsh).Thickness = 4;
Plugin(MatGmsh).OutputPrefix = "";
Plugin(MatGmsh).Run;
