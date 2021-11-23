/********************************************************************************
QuadTriUtils.cpp

The code in this file was written by Dr. Trevor S. Strickler.
email: <trevor.strickler@gmail.com>

This file is part of the QuadTri contribution to Gmsh. QuadTri allows the
conformal interface of quadrangle faces to triangle faces using pyramids and
other mesh elements.

Trevor S. Strickler hereby transfers copyright of QuadTri files to Christophe
Geuzaine and J.-F. Remacle with the understanding that his contribution shall be
cited appropriately. See the README.txt file for license information.
********************************************************************************/

#include <stdlib.h>
#include "QuadTriUtils.h"

// By Geuzaine, Remacle...
static void addTriangle(MVertex *v1, MVertex *v2, MVertex *v3, GFace *to)
{
  MTriangle *newTri = new MTriangle(v1, v2, v3);
  to->triangles.push_back(newTri);
}

// this determines if a face is a non-lateral face in a structured toroidal
// volume extrusion with at least one QuadToTri region...
int IsInToroidalQuadToTri(GFace *face)
{
  if(!face) return false;

  GModel *model = face->model();

  bool is_toroidal = false, is_quadtri = false, is_noaddverts = false;

  // Find the root face first...then step back through extrusions as far as can
  // find another structured region.  If there is a single quadtri region, and
  // this is a torus that extrudes back onto the root source surface, then
  // return true.
  GFace *root_face = 0;
  root_face = findRootSourceFaceForFace(face);
  unsigned int numRegions = 0;
  std::vector<GRegion *> adj_extruded_reg;

  // find the two regions adjacent to the root face. If this is a structured
  // torus, then both regions
  // should be structured extrusions and BOTH should have the same root face
  std::set<GRegion *, GEntityPtrLessThan>::iterator itreg;
  for(itreg = model->firstRegion(); itreg != model->lastRegion(); itreg++) {
    // save time
    if(numRegions >= 2) break;

    GRegion *region = (*itreg);

    // does face belong to region and if so is it a structured extrusion?
    std::vector<GFace *> region_faces = region->faces();
    if(std::find(region_faces.begin(), region_faces.end(), root_face) !=
         region_faces.end() &&
       region->meshAttributes.extrude &&
       region->meshAttributes.extrude->mesh.ExtrudeMesh &&
       region->meshAttributes.extrude->geo.Mode == EXTRUDED_ENTITY) {
      adj_extruded_reg.push_back(region);
      numRegions++;
    }
    else
      continue;
  }
  // if there are two structured extruded regions adjacent to the root face,
  // then find the one that is NOT extruded from the root directly.  Then follow
  // this face as far as possible back to the source.

  GRegion *last_region = 0;
  GFace *last_reg_source = 0;
  bool found_first = 0, found_last = 0;
  if(numRegions == 2) {
    for(int ind = 0; ind <= 1; ind++) {
      ExtrudeParams *adj_ep = adj_extruded_reg[ind]->meshAttributes.extrude;
      GFace *reg_source = 0;

      if(adj_ep && adj_ep->mesh.ExtrudeMesh) {
        reg_source = model->getFaceByTag(std::abs(adj_ep->geo.Source));
        if(adj_ep->mesh.QuadToTri) {
          is_quadtri = true;
          if(adj_ep->mesh.QuadToTri == QUADTRI_NOVERTS_1 ||
             adj_ep->mesh.QuadToTri == QUADTRI_NOVERTS_1_RECOMB)
            is_noaddverts = true;
        }
      }
      if(reg_source) {
        if(reg_source != root_face) {
          last_region = adj_extruded_reg[ind];
          last_reg_source = reg_source;
          found_last = true;
        }
        else {
          found_first = true;
        }
      }
      else {
        Msg::Error(
          "In IsInToroidalQuadToTri(), could not find source face of region %d",
          adj_extruded_reg[ind]->tag());
        return 0;
      }
    }
  }

  // walk back around to beginning if possible
  if(last_region && found_first && found_last) {
    GFace *iter_face = last_reg_source;
    GFace *iter_source_face = 0;
    bool done = false;
    unsigned int maxiter = model->getNumFaces() + 2;
    unsigned int counter = 0;
    while(!done && counter <= maxiter) {
      counter++;
      if(iter_face) {
        ExtrudeParams *iter_eps = iter_face->meshAttributes.extrude;
        if(iter_eps && iter_eps->mesh.ExtrudeMesh &&
           iter_eps->geo.Mode == COPIED_ENTITY) {
          if(iter_eps->mesh.QuadToTri) is_quadtri = true;
          iter_source_face =
            model->getFaceByTag(std::abs(iter_eps->geo.Source));
          if(iter_source_face) {
            if(iter_source_face == root_face) {
              is_toroidal = true;
              done = true;
            }
            else
              iter_face = iter_source_face;
          }
          else {
            Msg::Error("In IsInToroidalQuadToTri(), could not find source face "
                       "of face %d",
                       iter_face->tag());
            return 0;
          }
        }
        else // if we found a source face not extruded as part of structured
             // source (ie, not copied)
          return 0;
      }
      else {
        Msg::Error("In IsInToroidalQuadToTri(), could not find a face...");
        return 0;
      }
    }
  }

  // now return
  if(is_toroidal && is_quadtri) {
    if(!is_noaddverts)
      return 1;
    else
      return 2;
  }
  else
    return 0;
}

// replace boundary quads in a source surface for toroidal quadtri extrusion
void ReplaceBndQuadsInFace(GFace *face)
{
  ExtrudeParams *ep = face->meshAttributes.extrude;
  bool is_struct = false;
  if((ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) ||
     face->meshAttributes.method == MESH_TRANSFINITE)
    is_struct = true;
  GFace *root_face = findRootSourceFaceForFace(face);
  if(root_face == face) {
    MVertexRTree pos_src_edge(CTX::instance()->geom.tolerance *
                              CTX::instance()->lc);
    QuadToTriInsertFaceEdgeVertices(face, pos_src_edge);
    std::vector<MQuadrangle *> quads2;
    // loop through source quads, if on boundary, delete them
    for(unsigned int i = 0; i < face->quadrangles.size(); i++) {
      std::vector<MVertex *> verts;
      int num_verts = face->quadrangles[i]->getNumVertices();
      bool on_edge = false;

      verts.reserve(num_verts);
      for(int j = 0; j < num_verts; j++)
        verts.push_back(face->quadrangles[i]->getVertex(j));

      for(int j = 0; j < num_verts; j++) {
        if(pos_src_edge.find(verts[j]->x(), verts[j]->y(), verts[j]->z())) {
          on_edge = true;
          break;
        }
      }
      if(on_edge) {
        delete face->quadrangles[i];
        if(is_struct) {
          addTriangle(verts[0], verts[2], verts[3], face);
          addTriangle(verts[0], verts[1], verts[2], face);
        }
        else {
          // draw other diagonals to minimize difference in average edge length
          // with diagonal length, in quadrature

          double mag_sq_ave = 0.0;
          for(int p = 0; p < 4; p++) {
            int d_leg = verts[p]->distance(verts[(p + 1) % 4]);
            mag_sq_ave += d_leg * d_leg;
          }
          mag_sq_ave /= 4.0;

          double d1 = verts[0]->distance(verts[2]);
          double d2 = verts[1]->distance(verts[3]);

          if(fabs(d1 * d1 - mag_sq_ave) <= fabs(d2 * d2 - mag_sq_ave)) {
            addTriangle(verts[0], verts[1], verts[2], face);
            addTriangle(verts[0], verts[2], verts[3], face);
          }
          else {
            addTriangle(verts[1], verts[2], verts[3], face);
            addTriangle(verts[1], verts[3], verts[0], face);
          }
        }
      }
      else
        quads2.push_back(face->quadrangles[i]);
    }
    face->quadrangles.clear();
    face->quadrangles = quads2;
  }
}

// Insert all vertices on a region's source edge, including corners, into
// pos_src_edge set.  Added 2010-01-09
void QuadToTriInsertSourceEdgeVertices(GRegion *gr, MVertexRTree &pos_src_edge)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(!ep || !ep->mesh.ExtrudeMesh || ep->geo.Mode != EXTRUDED_ENTITY) {
    Msg::Error("In QuadToTriInsertSourceEdgeVertices(), incomplete or no "
               "extrude info for region %d.",
               gr->tag());
    return;
  }

  GFace *source_face = gr->model()->getFaceByTag(std::abs(ep->geo.Source));

  std::vector<GEdge *> const &edges = source_face->edges();
  std::vector<GEdge *>::const_iterator ite = edges.begin();
  for(ite = edges.begin(); ite != edges.end(); ite++) {
    pos_src_edge.insert((*ite)->mesh_vertices);
    if((*ite)->getBeginVertex())
      pos_src_edge.insert((*ite)->getBeginVertex()->mesh_vertices);
    if((*ite)->getEndVertex())
      pos_src_edge.insert((*ite)->getEndVertex()->mesh_vertices);
  }
}

// Insert all vertices on a faces edges, including corners, into pos_edges set.
// Added 2010-01-18
void QuadToTriInsertFaceEdgeVertices(GFace *face, MVertexRTree &pos_edges)
{
  std::vector<GEdge *> const &edges = face->edges();
  std::vector<GEdge *>::const_iterator ite = edges.begin();
  while(ite != edges.end()) {
    pos_edges.insert((*ite)->mesh_vertices);
    if((*ite)->getBeginVertex())
      pos_edges.insert((*ite)->getBeginVertex()->mesh_vertices);
    if((*ite)->getEndVertex())
      pos_edges.insert((*ite)->getEndVertex()->mesh_vertices);
    ++ite;
  }
}

// Constructor for the CategorizedSourceElements structure.  See definition of
// CategorizedSourceElements in QuadTriUtils.h file for details.
CategorizedSourceElements::CategorizedSourceElements(GRegion *gr)
{
  region = (GRegion *)(NULL);
  source_face = (GFace *)(NULL);
  valid = false;

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if(!ep || !ep->mesh.QuadToTri || !ep->mesh.ExtrudeMesh) {
    Msg::Error("In CategorizedSourceElements constructor, invalid extrusion "
               "in region %d for performing QuadToTri mesh generation.",
               gr->tag());
    return;
  }

  GModel *model = gr->model();
  if(!model) {
    Msg::Error(
      "In CategorizedSourceElements constructor, invalid model for region "
      "%d.",
      gr->tag());
    return;
  }

  // now find and verify the source face

  GFace *source_tmp = model->getFaceByTag(std::abs(ep->geo.Source));
  if(!source_tmp) {
    Msg::Error("In CategorizedSourceElements constructor, invalid source face "
               "for region "
               "%d.",
               gr->tag());
    return;
  }

  // fill the data structure region and source face pointers
  valid = true;
  region = gr;
  source_face = source_tmp;

  // get source face boundary verts
  MVertexRTree bnd_verts(CTX::instance()->geom.tolerance * CTX::instance()->lc);
  QuadToTriInsertSourceEdgeVertices(gr, bnd_verts);

  unsigned int num_tri = source_face->triangles.size();
  unsigned int num_quad = source_face->quadrangles.size();

  // assign size to bool vectors
  tri_bool.assign(num_tri * 4, false);
  quad_bool.assign(num_quad * 5, false);

  // keep temporary set of one boundary point quad pivot indices
  std::set<MVertex *> one_pt_quad_pivots;

  // now classify the source elements in the vectors
  for(int t = 0; t < 2; t++) { // t = 0 loop over triangles, t=1 loop over quads
    int size =
      !t ? source_face->triangles.size() : source_face->quadrangles.size();
    for(int i = 0; i < size;
        i++) { // loop over total elements in current vector
      std::vector<MVertex *> elem_verts;
      MElement *elem;
      if(!t) {
        elem = source_face->triangles[i];
        elem->getVertices(elem_verts);
      }
      else {
        elem = source_face->quadrangles[i];
        elem->getVertices(elem_verts);
      }
      int elem_size = elem_verts.size();
      int bnd_count = 0;
      int bnd_vert = 0;
      // get the boundary vert bool values
      for(int k = 0; k < elem_size; k++) {
        if(bnd_verts.find(elem_verts[k]->x(), elem_verts[k]->y(),
                          elem_verts[k]->z())) {
          if(!t)
            tri_bool[4 * i + k + 1] = true;
          else
            quad_bool[5 * i + k + 1] = true;
          bnd_vert = k;
          bnd_count++;
        }
      }
      if(bnd_count) {
        if(!t)
          tri_bool[4 * i] = true;
        else
          quad_bool[5 * i] = true;
      }

      // Place element vector indices into appropriate set
      if(!bnd_count) {
        if (!t) internal_tri.insert(i);
        else internal_quad.insert(i);
      }
      else if(bnd_count == 1 || bnd_count == 2 || (bnd_count == 3 && t)) {
        if (!t) other_bnd_tri.insert(i);
        else other_bnd_quad.insert(i);
      }
      else if((bnd_count == 3 && !t) || bnd_count == 4) {
        if (!t) three_bnd_pt_tri.insert(i);
        else four_bnd_pt_quad.insert(i);
      }

      // if a one boundary point quad, record it in one_pt_quads set
      if(t && bnd_count == 1) {
        one_pt_quad_pivots.insert(elem_verts[(bnd_vert + 2) % 4]);
      }
    }
  }

  // If there were one_bnd_pt_quads, go through the search for all elements
  //  touching at pivot index that are either internal or two bnd point quads.
  // This would take awhile if had to do this for every element (n^2).
  // Fortunately, such elements are NOT typical at all.
  if(!one_pt_quad_pivots.size()) return;

  std::set<std::pair<unsigned int, unsigned int> >::iterator it_quad;
  std::set<unsigned int>::iterator it_int;
  for(int s = 0; s < 2; s++) {
    for(int q = 0; q < 2; q++) {
      std::set<unsigned int> *int_elems;
      if(!s) {
        if(!q)
          int_elems = &internal_tri;
        else
          continue;
      }
      else
        int_elems = !q ? &internal_quad : &other_bnd_quad;

      for(it_int = (*int_elems).begin(); it_int != (*int_elems).end();
          it_int++) {
        std::vector<MVertex *> verts;
        if(!s)
          source_face->triangles[(*it_int)]->getVertices(verts);
        else
          source_face->quadrangles[(*it_int)]->getVertices(verts);

        // for t == s == 1 (other_bnd_quads), only retain those with two
        // boundary verts
        if(s && q) {
          int bnd_count = 0;
          for(unsigned int k = 0; k < verts.size(); k++) {
            if(quad_bool[5 * (*it_int) + k + 1]) bnd_count++;
          }
          if(bnd_count != 2) continue;
        }

        // Don't eliminate the inner for loop with std::find because
        // or reverse the order of the two loops.  If an element touches
        // multiple pivots, always want to find the FIRST one in the pivots set
        // so that there is precedence and no conflicts at mesh time.  Looping
        // through the element vertices as the outer loop will sometimes choose
        // the wrong pivot.
        std::set<MVertex *>::iterator it_piv;
        bool found = false;
        for(it_piv = one_pt_quad_pivots.begin();
            it_piv != one_pt_quad_pivots.end(); it_piv++) {
          for(unsigned int t = 0; t < verts.size(); t++) {
            if((*it_piv) == verts[t]) {
              found = true;
              if(!s) {
                internal_tri_touch_one_bnd_pt_quad.insert(*it_int);
                tri_bool[4 * (*it_int)] = true;
                tri_bool[4 * (*it_int) + t + 1] = true;
              }
              else {
                if(!q) {
                  internal_quad_touch_one_bnd_pt_quad.insert(*it_int);
                  quad_bool[5 * (*it_int)] = true;
                  quad_bool[5 * (*it_int) + t + 1] = true;
                }
                else
                  two_bnd_pt_quad_touch_one_bnd_pt_quad.insert(*it_int);
              }
              break;
            }
          }
          if(found) break;
        }
      }
    }
  }
}

// Find centroid of vertices in vector v, return in vector
std::vector<double> QtFindVertsCentroid(std::vector<MVertex *> v)
{
  std::vector<double> v_return;
  const int v_size = v.size();

  if(v_size != 6 && v_size != 8 && v_size != 3 && v_size != 4) {
    Msg::Error(
      "In QtFindVertsCentroid(), number of vertices is not 3, 4, 6, or 8.");
    return v_return;
  }

  // for 3D
  int n_lat_tmp = 10;
  if(v_size == 6)
    n_lat_tmp = 3;
  else if(v_size == 8)
    n_lat_tmp = 4;

  const int n_lat = n_lat_tmp;

  double x = 0.0, y = 0.0, z = 0.0;
  int v_count = 0;
  for(int p = 0; p < v_size; p++) {
    // skip degenerate vertices - 3D
    if((v_size == 6 || v_size == 8) && p > n_lat - 1 && v[p] == v[p - n_lat])
      continue;
    // skip degenerate vertices - 2D
    if((v_size == 3 || v_size == 4) && v[p] == v[(p + v_size - 1) % v_size])
      continue;
    v_count++;
    x += v[p]->x();
    y += v[p]->y();
    z += v[p]->z();
  }
  x /= v_count;
  y /= v_count;
  z /= v_count;

  v_return.push_back(x);
  v_return.push_back(y);
  v_return.push_back(z);

  return v_return;
}

// Add a new vertex at the centroid of a vector of vertices (this goes into a
// region Added 2010-02-06
MVertex *QtMakeCentroidVertex(const std::vector<MVertex *> &v,
                              std::vector<MVertex *> *target, GEntity *entity,
                              MVertexRTree &pos)
{
  int v_size = v.size();
  if(v_size != 6 && v_size != 8 && v_size != 3 && v_size != 4) {
    Msg::Error("In makeCentroidVertex(), number of vertices does not equal 3, "
               "4, 6, or 8.");
    return (MVertex *)(NULL);
  }

  // find the centroid of vertices
  std::vector<double> centroid = QtFindVertsCentroid(v);
  double x = 0., y = 0., z = 0.;
  if(centroid.size()) {
    x = centroid[0];
    y = centroid[1];
    z = centroid[2];
  }

  // make new vertex
  MVertex *tmp = pos.find(x, y, z);
  MVertex *v_int;
  // simple check if it exists
  if(!tmp) {
    v_int = new MVertex(x, y, z, entity);
    target->push_back(v_int);
    pos.insert(v_int);
  }
  else
    v_int = tmp;

  return (v_int);
}

// Finds the index of the lowest valued pointer in a vector of MVertex pointers
// Added 2011-03-10
int getIndexForLowestVertexPointer(std::vector<MVertex *> v)
{
  int ind_low = 0;
  int v_size = v.size();
  for(int i = 1; i < v_size; i++) {
    if(v[i] < v[ind_low]) ind_low = i;
  }
  return ind_low;
}

// Given 4 verts on a face, find an existent diagonal, if any.
// Two possible methods:  If the 'index_guess' argument is the index of the
// correct triangle, finding it is simple. If not, have to do a complete
// pedantic search. Added 2010-01-26
std::pair<int, int> FindDiagonalEdgeIndices(std::vector<MVertex *> verts,
                                            GFace *face, bool lateral,
                                            unsigned int index_guess)
{
  if(verts.size() != 4) {
    Msg::Error("FindDiagonalEdgeIndices(), size of verts array not equal 4.");
    return std::pair<int, int>(0, 0);
  }
  if(!lateral) {
    MVertex *tmp = verts[2];
    verts[2] = verts[3];
    verts[3] = tmp;
  }

  int s_max = face->triangles.size();
  MElement *elem_tmp = NULL;
  bool wrong_guess = false;
  for(int s = 0; s < s_max; s++) {
    if(s != 0 && !wrong_guess) {
      wrong_guess = true;
      if(!face->quadrangles.size())
        Msg::Error("FindDiagonalEdgeIndices() encountered unexpected surface "
                   "configuration.");
    }
    int v_count0 = 0, v_count1 = 0;
    elem_tmp = (MElement *)(face->triangles[(s + index_guess) % s_max]);
    int num_verts = elem_tmp->getNumVertices();
    for(int g = 0; g < num_verts; g++) {
      if(elem_tmp->getVertex(g) == verts[0] ||
         elem_tmp->getVertex(g) == verts[3])
        v_count0++;
      else if(elem_tmp->getVertex(g) == verts[1] ||
              elem_tmp->getVertex(g) == verts[2])
        v_count1++;
      if(lateral) {
        if(v_count0 > 1)
          return std::pair<int, int>(std::min(0, 3), std::max(0, 3));
        else if(v_count1 > 1)
          return std::pair<int, int>(std::min(1, 2), std::max(1, 2));
      }
      else {
        if(v_count0 > 1)
          return std::pair<int, int>(std::min(0, 2), std::max(0, 2));
        else if(v_count1 > 1)
          return std::pair<int, int>(std::min(1, 3), std::max(1, 3));
      }
    }
  }

  if(!face->quadrangles.size())
    Msg::Error("In FindDiagonalEdgeIndices(), could not "
               "find a diagonal on surface %d.",
               face->tag());
  return std::pair<int, int>(0, 0);
}

// Get number of regions neighboring a face
int GetNeighborRegionsOfFace(GFace *face, std::vector<GRegion *> &neighbors)
{
  GModel *model = face->model();

  if(!model) {
    Msg::Error("GetNeighborRegionsOfFace(), face %d has no parent model.",
               face->tag());
    return 0;
  }

  // first see if the face has the list of regions
  int regions_count = face->numRegions();
  if(regions_count > 0) {
    neighbors.push_back(face->getRegion(0));
    if(regions_count > 1) neighbors.push_back(face->getRegion(1));
    return regions_count;
  }
  else
    regions_count = 0;

  // pedantic search
  std::set<GRegion *, GEntityPtrLessThan>::iterator itreg;
  for(itreg = model->firstRegion(); itreg != model->lastRegion(); itreg++) {
    std::vector<GFace *> reg_faces = (*itreg)->faces();
    if(std::find(reg_faces.begin(), reg_faces.end(), face) != reg_faces.end()) {
      regions_count++;
      face->addRegion((*itreg));
      neighbors.push_back((*itreg));
      if(regions_count >= 2) return regions_count;
    }
  }

  return regions_count;
}

// Tests whether a surface is a lateral of a region
// Trevor Strickler 12/09/10
int IsSurfaceALateralForRegion(GRegion *region, GFace *face)
{
  // NOTE: don't necessarily require the face to be extruded! just in the
  // position
  //  of lateral is all we care about here.
  ExtrudeParams *ep = face->meshAttributes.extrude;
  ExtrudeParams *reg_ep = region->meshAttributes.extrude;

  // if there is no REGION extrude information, skip the rest
  if(!reg_ep) return 0;

  GModel *model = face->model();
  // GEdge *face_source = NULL;
  // if( ep && ep->geo.Mode == EXTRUDED_ENTITY)
  // face_source = model->getEdgeByTag(std::abs(ep->geo.Source));

  GFace *reg_source = model->getFaceByTag(std::abs(reg_ep->geo.Source));

  if(!reg_source) {
    Msg::Error(
      "In IsSurfaceALateralForRegion(), unknown source surface number %d.",
      region->meshAttributes.extrude->geo.Source);
    return 0;
  }

  // if face is the region's source, return 0
  if(reg_source == face) return 0;

  // of course, the face has to belong to the region!
  std::vector<GFace *> region_faces = region->faces();
  if(std::find(region_faces.begin(), region_faces.end(), face) ==
     region_faces.end())
    return 0;

  // if this face is a COPIED_ENTITY with source = region source face, this is
  // the top.  Exit.
  if(ep && ep->geo.Mode == COPIED_ENTITY &&
     reg_source == model->getFaceByTag(std::abs(ep->geo.Source)))
    return 0;

  //
  // Now to prove the face is lateral, it must not be the "top" face. If
  // this face has replaced the region's original lateral through
  // ReplaceDuplicateSurfaces(), then the previous test for "topness" won't
  // have signaled an error. However, this face COULD still be in the  top
  // position. So, check that the lateral shares AN edge (not the source edge,
  // necessarily) with the region's source face. THEN, IF they share an edge,
  // extrude all of the source GVertex positions and see if they are found in
  // this face.  IF so, then it is a top and not a lateral.

  std::vector<GEdge *> region_source_edges = reg_source->edges();
  std::vector<GEdge *> face_edges = face->edges();
  std::vector<GEdge *>::iterator ite = face_edges.begin();

  bool edge_found = false;
  int common_count = 0;
  // GEdge *common_edge = NULL;
  for(ite = region_source_edges.begin(); ite != region_source_edges.end();
      ite++) {
    if(std::find(face_edges.begin(), face_edges.end(), (*ite)) !=
       face_edges.end()) {
      edge_found = true;
      // common_edge = (*ite);
      common_count++;
      if(common_count > 1) return 0;
    }
  }

  if(!edge_found)
    return 0;
  else if(reg_ep->geo.Type == ROTATE || reg_ep->geo.Type == TRANSLATE_ROTATE) {
    // create lists of GVertex object for source face and present face
    std::vector<GVertex *> const &face_v = face->vertices();
    std::vector<GVertex *> const &source_v = reg_source->vertices();
    std::vector<GVertex *>::const_iterator itvs;
    double const tol = 1.00e-12;
    double const eps = std::abs(tol * CTX::instance()->lc);
    unsigned int j_top, k_top;
    j_top = reg_ep->mesh.NbLayer - 1;
    k_top = reg_ep->mesh.NbElmLayer[j_top];
    bool found_all = true;
    for(itvs = source_v.begin(); itvs != source_v.end(); itvs++) {
      double x1 = (*itvs)->x(), y1 = (*itvs)->y(), z1 = (*itvs)->z();
      reg_ep->Extrude(j_top, k_top, x1, y1, z1);
      std::vector<GVertex *>::const_iterator itvf;
      bool found_one = false;
      for(itvf = face_v.begin(); itvf != face_v.end(); itvf++) {
        double x2 = (*itvf)->x(), y2 = (*itvf)->y(), z2 = (*itvf)->z();
        if(fabs(x2 - x1) <= eps && fabs(y2 - y1) <= eps &&
           fabs(z2 - z1) <= eps) {
          found_one = true;
          break;
        }
      }
      if(!found_one) {
        found_all = false;
        break;
      }
    }
    // if surface is certainly the top
    if(found_all) {
      return 0;
    }
  }

  return 1; // if code executes here, passed all tests
}

// Function to determine if a face is a top surface for a region.  It returns 1
// if the face is COPIED_ENTITY with source = region's source and if face
// belongs to region. Otherwise, return 0 (NOTE: ReplaceDuplicateSurfaces() can
// remove a top surface and replace it.  If that happens, this will return 0.
// That is INTENDED for THIS function. Added 2010-12-13
int IsSurfaceATopForRegion(GRegion *region, GFace *face)
{
  // first make sure there is extrude info
  if(!region->meshAttributes.extrude || !face->meshAttributes.extrude) return 0;

  ExtrudeParams *reg_ep = region->meshAttributes.extrude;
  ExtrudeParams *face_ep = face->meshAttributes.extrude;
  GModel *model = face->model();
  GFace *reg_source = model->getFaceByTag(std::abs(reg_ep->geo.Source));

  if(reg_ep->geo.Mode != EXTRUDED_ENTITY || !reg_source) return 0;

  if(face_ep->geo.Mode != COPIED_ENTITY || face == reg_source) return 0;

  GFace *face_source = model->getFaceByTag(std::abs(face_ep->geo.Source));

  // whether face is a copy of region's source
  if(!reg_source || !face_source || reg_source != face_source) return 0;

  // of course, the face has to belong to the region!
  std::vector<GFace *> region_faces = region->faces();
  if(std::find(region_faces.begin(), region_faces.end(), face) ==
     region_faces.end())
    return 0;

  // if make it this far, return 1
  return 1;
}

// Find the bottom root source surface of an extruded surface (source of source
// of source, etc.)
GFace *findRootSourceFaceForFace(GFace *face)
{
  ExtrudeParams *ep = face->meshAttributes.extrude;
  if(!(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY))
    return face;

  GFace *source_face;
  GModel *model = face->model();
  int max_iter = model->getNumFaces();
  int iter_counter = 0;
  ExtrudeParams *ep_iter = ep;
  while(iter_counter <= max_iter) {
    iter_counter++;
    source_face = model->getFaceByTag(std::abs(ep_iter->geo.Source));
    if(!source_face) {
      Msg::Error(
        "findRootSourceFaceForFace() could not find valid surface for tag %d.",
        ep->geo.Source);
      return (GFace *)(NULL);
    }
    ep_iter = source_face->meshAttributes.extrude;
    if(!(ep_iter && ep_iter->mesh.ExtrudeMesh &&
         ep_iter->geo.Mode == COPIED_ENTITY))
      return source_face;
  }

  Msg::Error("findRootSourceFaceForFace() failed to find root source.");
  return (GFace *)(NULL);
}

// Input is vert_bnd[], which describes some 2D element: vert_bnd[i] is true if
// the ith vertex the element touches a lateral edge boundary of the surface the
// element is in.
// Output is touch_bnd[]: Each element of touch_bnd[] corresponds to an edge of
// the element described by vert_bnd[].  Edge i of touch_bnd[] is formed by
// vertices i and (i+1)%element_size of the element. The value of touch_bnd[i]
// is non-zero if that edge touches a boundary edge of the surface that the
// element is in. Added 2011-03-10
void fill_touch_bnd(int touch_bnd[], std::vector<bool> vert_bnd, int n_lat)
{
  for(int i = 0; i < n_lat; i++) touch_bnd[i] = 0;

  for(int i = 0; i < n_lat; i++) {
    if(vert_bnd[i]) {
      touch_bnd[i] = 1;
      touch_bnd[(i + n_lat - 1) % n_lat] = 1;
    }
  }
}
