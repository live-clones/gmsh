/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   Trivial 2D example

   All important comments are marked with "README"
*/


/* README: This defines a variable called lc. Note that you can use C
   or C++ style comments in all Gmsh files. */

lc = 0.007;

/* README: This defines the point '1', located at x=0, y=0, z=0, with
   an associated characteristic length 'lc'. The characteristic length
   sets the target mesh size at the point. */

Point(1) = {0,  0,  0, lc};

// Other points

Point(2) = {.1, 0,  0, lc};
Point(3) = {.1, .3, 0, lc};
Point(4) = {0,  .3, 0, lc};

/* README: To define lines, simply give a pair of point numbers */

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

/* README: A line loop is defined as a list of lines (with signs) */

Line Loop(5) = {4,1,2,3};

/* README: A plane surface is defined as a list of line loops (only
   one here) */

Plane Surface(6) = {5};

/* README: Now that all elementary entities are defined, we define the
   physical entities, i.e. the composed entities whose meshes will be
   saved in the output file */

Physical Line(1111) = {1};
Physical Line(2222) = {3};
Physical Line(3333) = {2,4};
Physical Surface(9999) = {6};

/* README: You can also specify options in the file. For example, this
   redefines the color of geometry points. See ex03.geo for a more
   complete example. */

Color{
  Geometry{
    Points = Orange;
  }
}

/* README: You can merge files with File->Merge. This is most useful
   for post-processing purposes. Try for example to merge view1.pos
   together with this file.  Post-processing options are available by
   right-clicking on the view button. You can also directly launch
   Gmsh with several files as arguments on the command line. The first
   will be 'opened', the others will be 'merged'. 

   For example, try 'gmsh ex01.geo view01.pos view02.pos'. Two view
   buttons will appear in the post-processing menu, respectively
   labeled "a scalar map" and "a vector map". A left mouse click will
   toggle the visibility of the particular view. A right mouse click
   will give you access to the view's options:

   - Remove: removes the view
   - Duplicate: makes a formal copy of the view
   - Lighting: activates/deactivates lighting for the view
   - Scale: gives access to the scale menu (range definition, iso-value
     choice, ...)
   - Color: defines the colormap for the view
   - Offset: permits to move the view around, and to make elevation 
     maps
   - Vector display: change vector attributes
   - Time step: select the displayed time step
   - Export as background mesh: exports the map, considered as an
     error map, as a background mesh, i.e. as a characteristic length map
   - Apply as current bg mesh: applies the view as the current background 
     mesh.  

   If you want modifications made to one view to affect also all 
   other views, select the appropriate option in Options->Post-Processing
*/


/* README: The 'msh' file format is the native output file format for
   Gmsh. The file is divided in several sections (enclosed in $KEY and
   $ENDKEY pairs). Two fields are important: $NOD/$ENDNOD defines the
   nodes and $ELM/$ENDELM defines the elements.

   The syntax is as follows:

   $NOD
   number-of-nodes
   node-number x-coord y-coord z-coord 
   ...
   $ENDNOD

   $ELM
   number-of-elements
   elm-number elm-type elm-region unused number-of-nodes node-numbers
   ...
   $ENDELM

   All the syntactic variables stand for integers except x-coord,
   y-coord and z-coord which stand for floating point values.  The
   elm-type value defines the geometrical type for the element:
   
   elm-type: 
   
   1 Line (2 nodes, 1 edge). 
   2 Triangle (3 nodes, 3 edges). 
   3 Quadrangle (4 nodes, 4 edges). 
   4 Tetrahedron (4 nodes, 6 edges, 4 facets). 
   5 Hexahedron (8 nodes, 12 edges, 6 facets). 
   6 Prism (6 nodes, 9 edges, 5 facets). 
   7 Pyramid (5 nodes, 8 edges, 5 facets). 
   15 Point (1 node). 

   The elm-region value is the number of the physical entity to which
   the element belongs. 

   The 'unv' is the universal file format standard. 
*/

/* README: The format of post-processing views is detailled in 'view01.pos' */






