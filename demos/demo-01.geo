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
   sets the target mesh size at the point. 
   
   The same convention is applied for all command: "If a number
   defines a new entity, it is enclosed between parentheses. If a
   number refers to a previously defined entity, it is enclosed
   between braces." */

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

/* README: You can merge files with File->Merge. This is most useful
   for post-processing purposes. Try for example to merge view1.pos
   together with this file.  Post-processing options are available by
   right-clicking on the view button. You can also directly launch
   Gmsh with several files as arguments on the command line. The first
   will be 'opened', the others will be 'merged'. 

   For example, try 'gmsh demo-01.geo view-01.pos view-02.pos'. Two view
   buttons will appear in the post-processing menu, respectively
   labeled "a scalar map" and "a vector map". A left mouse click will
   toggle the visibility of the particular view. A right mouse click
   will give you access to the view's options:

   - Reload: reload the file from which the view was loaded
   - Remove: removes the view
   - Duplicate: makes a copy of the view (without duplicating the data)
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

   All the options can also be specified in the input files. You can save the 
   current options with File->Save_Options_as
*/


/* README: The 'msh' file format is the native output file format for
   Gmsh. See the FORMAT file for an explanation of all the formats
   used by Gmsh.  */





