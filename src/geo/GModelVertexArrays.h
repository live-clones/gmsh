// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMODEL_VERTEX_ARRAYS_H
#define GMODEL_VERTEX_ARRAYS_H

// What GModelVertexArrays.cpp builds the arrays of the geometry and the mesh
// with, and what the drawing needs to ask the same questions of an entity or
// an element as the arrays were filled with.

#include <cstdint>
#include <utility>
#include <vector>

class GEntity;
class GRegion;
class MElement;

// the colour a selected entity is drawn in
unsigned int getSelectionColor(GEntity *e);
// the colour of an entity: its own, the one of its dimension, or the one of
// the carousel; the selection colour when it is selected and asked for
unsigned int getColorByEntity(GEntity *e, bool withSelection = true);
// is this element drawn at all? (its own visibility, and the ranges of
// quality and size the options keep)
bool isElementVisible(MElement *ele);
// is this element kept by whole element mode, which removes the elements a
// clipping plane cuts rather than cutting them?
bool elementIsKept(MElement *ele);
// The faces (the edges, if in2D) of a set of elements that no other element
// of the set shares - its skin - as (index of the element, face), in the order
// of the elements; the elements with a 0 in `use', if given, are left out.
void findBoundaryOfElements(const std::vector<MElement *> &elements,
                            bool in2D, const std::vector<std::uint8_t> *use,
                            std::vector<std::pair<std::uint32_t, int> > &left);
// the 3D elements of a volume that are drawn and that a clipping plane of the
// mesh may cut: told from the spheres kept around them, without going through
// the others, if there are enough of them (all of them otherwise)
void getElementsNearClipPlanes(GRegion *r, std::vector<MElement *> &elements);

#endif
