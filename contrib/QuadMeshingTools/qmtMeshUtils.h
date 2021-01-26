// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <unordered_map>


class GModel;
class GFace;
class GEdge;
class MTriangle;
class MQuadrangle;
class MVertex;
class MElement;

std::vector<GFace*> model_faces(const GModel* gm);
std::vector<GEdge*> face_edges(const GFace* gf);
std::vector<GEdge*> model_edges(const GModel* gm);

bool buildVertexToVertexMap(
    const std::vector<MTriangle*>& triangles,
    std::unordered_map<MVertex*,std::vector<MVertex*> >& v2v);
