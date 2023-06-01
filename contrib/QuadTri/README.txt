INFORMATION FOR QUADTRI PATCH VERSION 2.0 (August 23, 2013)

All new code is written by Trevor S. Strickler
<trevor.strickler@gmail.com>

Trevor S. Strickler hereby transfers copyright of QuadTri files to
Christophe Geuzaine and J.-F. Remacle with the understanding that
his contribution shall be cited appropriately.

All code reused from Gmsh is Copyright (C) 1997-2013 C. Geuzaine,
J.-F. Remacle

Gmsh is available at: www.gmsh.info

See licensing information below.


CONTENTS:

1. Copyright and Licensing

2. Introduction

3. How QuadTri works.
   a. For Transfinite Volumes.
   b. For Structured Extrusions.

4. Invoking QuadTri.
   a. For Transfinite Volumes.
   b. For Structured Extrusions.

5. How to modify Gmsh to use QuadTri.


COPYRIGHT AND LICENSING
-----------------------

QuadTri was written by Trevor S. Strickler
<trevor.strickler@gmail.com>. It is written as an addition to the
meshing code Gmsh, which is copyrighted by C. Geuzaine and J.-F.
Remacle and distributed under the GNU Public License version 2 with
an exception. QuadTri is released under the GNU Public License
Version 2 with the SAME exceptions as for the current release of Gmsh
as of August 23, 2013.  See the LICENSE.txt file in the Gmsh root
directory for more information.

Trevor S. Strickler hereby transfers copyright of QuadTri files to
Christophe Geuzaine and J.-F. Remacle with the understanding that
his contribution shall be cited appropriately.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, Version 2,
as published by the Free Software Foundation, or (at your option)
any later version, with or without the exception given in the
LICENSE.txt file supplied with this code and with Gmsh.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.


INTRODUCTION
----------------------------

The Quadrangle-to-Triangle (QuadToTri) interface allows the user to connect
structured regions containing quadrangle-bounded mesh elements (hexahedra,
prisms, or pyramids) to regions that contain tetrahedra. The QuadToTri
feature may be applied to both structured extrusions and tranfinite regions.


HOW QUADTRI WORKS
-----------------

The QuadToTri algorithms create a conformal interface between structured
regions that contain quadrangle-bounded mesh elements and tetrahedral regions
by subdividing elements in the quadrangle-containing region. First, on the
boundaries that the quad-containing region shares with a tetrahedral region,
all 2D quadrangle elements are divided into triangles. Then, the 3D volume
elements in the quad-containing region that touch these triangles are
subdivided into pyramids, tetrahedra, or prisms as necessary for the mesh to
remain conformal.

a. FOR TRANSFINITE VOLUMES:

The QuadTri algorithm for transfinite volumes is very simple.
A transfinite region with any combination of recombined and
un-recombined transfinite boundary surfaces is valid when meshed with
Transfinite QuadTri. Any mesh elements in a QuadToTri transfinite region
that are adjacent to unrecombined, 2D boundary surface elements will
be divided with a body-centered internal vertex, conformal to the
surface mesh. This method works for both 5- and 6-sided transfinite
regions.


b. STRUCTURED EXTRUSIONS:

QuadToTri may also be applied to structured extrusions.
The QuadToTri algorithms for structured extrusions ( from here on referred to
as 'QuadTriExtruded') work for any structured, extruded region. Source surfaces
may be structured or unstructured; the sources may also be all quadrangles,
all triangles, or mixed. Recently, the ability was added to apply QuadToTri to
a region extruded in a toroidal loop in which the 'top' surface coincides with
the source. The user also has the option to keep free lateral boundaries
recombined (where possible) and only divide the top surface into triangles.

There are two variations of QuadToTri for structured extrusions: the
'Add Vertices' method (method 1), and the 'No New Vertices' method (method 2).

Method 1 (No New Vertices): In 2D, this method subdivides the quadrangles
on the following boundary surfaces of an extruded, structured region: the top
surface of the extruded region, the boundaries that the region shares with
tetrahedral regions, and free lateral boundaries if the user has selected to
do so. In 3D, the method attempts to subdivide 3D elements in the region that
touch the boundary surface triangles WITHOUT adding any additional vertices.
This subdivision is accomplished by creating pyramids, prisms, or tetrahedra
such that the mesh remains valid. In some cases, due to certain lateral
boundary conditions, it may not be possible make a valid element subdivision
without adding additional vertices. In this case, an internal vertex is
created at the vertex-based centroid of the element. The element is then
divided using that vertex. When an internal vertex is created in the 'No New
Vertices' method, the user is alerted by a warning message sent for each
instance--however, the mesh will still be valid and conformal.

Method 2: (Add Vertices) In 2D, as in method 1, this method subdivides the
quadrangles on the following boundary surfaces of an extruded, structured
region: the top surface of the extruded region, the boundaries the region
shares with tetrahedral regions, and free lateral boundaries if the user has
selected to do so.  In 3D, body-centered vertices are added at the centroids
of any 3D elements in the region that are adjacent to the subdivided 2D
boundaries. The elements are then subdivided using the internal vertex into
pyramids, prisms, or tetrahedra such that the mesh remains valid.

There are advantages and disadvantages to each of these two methods:

The 'No New Vertices' method creates the least number of mesh elements,
but the quality of the elements is sometimes slightly worse than for the
'Add Vertices' method when hexahedra are being divided.  Also, in rare
instances, the 'No New Vertices' method may be unable to divide an element
without adding a body-centered vertex; however, this is rare and *should*
only be possible when the source surface has 2D elements with all vertices
on a boundary AND if there are both recombined and unrecombined lateral
surfaces in the extrusion--but even then it is unlikely. Even if a new
vertex is created by the 'No New Vertices' method, the mesh will still be
conformal--but some users may not want an irregular vertex pattern in their
structured extrusions.


Recommendations: For considerations of element quality, use 'No New Vertices'
when only prisms are being divided (ie, when the extrusion  source is a
surface with all triangles). Use 'Add New Vertices' whenever hexahedra are
involved, or when the user does not care if new vertices are added to the
mesh.

If the user has a quad-containing, structured mesh to interface to
a tetrahedral region but would also like the structured mesh to remain
unchanged, interface regions may be built around the primary structured
region and those regions may have QuadToTri applied in order to create the
interface.


As a last note on QuadTriExtruded: The algorithms are 'smart' about the
boundary requirements of neighboring regions and will resolve lateral surface
mesh conflicts where ever necessary. The default behavior is to divide
free lateral boundaries into triangles when possible. Alternatively, the user
may choose to have as many laterals as possible remain as quadrangles.
However, regardless of user preference, the algorithms will do what they
have to do to maintain conformal meshes on the laterals. In other words, do
not worry about conformality with lateral neighbors--QuadTriExtruded will not
divide a lateral surface that must remain meshed as quadrangles, and it will
not recombine a lateral surface that must remain as triangles. However, NOTE:
the 'top' surface of a structured region is always divided by
QuadTriExtruded. Also, laterals between two QuadTriExtruded regions are
always recombined as quadrangles.



INVOKING QUADTRI
----------------

a. FOR TRANSFINITE VOLUMES:

The transfinite QuadTri algorithm may be applied by using the following
command:

TransfQuadTri { expression-list } | {:};

Where 'expression-list' is a list of volume numbers to apply QuadTri to.
{:} is used to apply TransfQuadTri to all existing volumes.  A transfinite
volume with any combination of recombined and un-recombined transfinite boundary
surfaces is valid when meshed with TransfQuadTri. When applied to
non-Transfinite volumes, TransfQuadTri has NO effect on those volumes.



b. FOR STRUCTURED EXTRUSIONS:

QuadTri for structured extrusions (QuadTriExtruded) is invoked by using
the appropriate keywords in the 'extrude-list layers' part of an 'Extrude'
command for structured meshes. (see Gmsh manual for description of the
'Extrude' command for structured meshes). Note that the QuadTriExtruded
commands only have an effect for the extrusion of a surface to create a
region, AND only if the 'Recombine' option is used (there is no point
in applying QuadTriExtruded to a fully subdivided region).

The keywords (note that only the first letter must be capitalized):

     QuadTriNoNewVerts; (for 'No New Vertices' method)
     QuadTriAddVerts;  (for 'Add Vertices' method)

Permissible variants (shown here as regular expressions (regexp) ):

     Quad[tT]ri[nN]o[nN]ew[vV]erts;
     Quad[tT]ri[aA]dd[vV]erts;

Optionally, for each of the two QuadTriExtruded methods, the user may choose
to keep free lateral surfaces of the region recombined (where possible) by
using:

     QuadTriNoNewVerts Recomblaterals;
     QuadTriAddVerts Recomblaterals;


Examples of Usage:

'No New Vertices' method, recombine laterals:

     Extrude {0.0, 0.0, 1.0} {Surface {surf_num}; Layers {10}; Recombine;
                              QuadTriNoNewVerts Recomblaterals; };

'Add Vertices' method not using the recombine laterals option:

     Extrude {0.0, 0.0, 1.0} {Surface {surf_num}; Layers {10}; QuadTriAddVerts;
                              Recombine; };

Let it be repeated: If the QuadTriExtruded region shares a lateral with another
region, QuadTriExtruded will only divide (or not divide) that surface in a way
that does not create conflicts between the regions, regardless of
whether Recomblaterals was used or not. In other words, do not worry
about conformality with lateral neighbors--QuadTriExtruded will not divide
a lateral surface that must remain quadrangles, nor will it recombine
a lateral surface that must remain triangles.


HOW TO MODIFY GMSH TO USE QUADTRI
---------------------------------------

One may simply copy the files distributed with the QuadTri patch
directly into the appropriate Gmsh directories (replacing any old copies with
the patched versions) and the changes to the source will be complete. The
user can then compile the source as for the regular Gmsh version. Be careful
not to get the src/mesh/CMakeLists.txt file confused with the CMakeLists.txt
file in other directories!!!!
