// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>
#include <cstdint>

class GFace;

/**
 * @brief Untangling/smoothing of volume mesh based on minimization of the
 *        Winslow functional, with regularization for tangled elements.
 *        See the following paper for details:
 *          Foldover-free maps in 50 lines of code.
 *          Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
 * Sokolov, D. (2021). arXiv preprint arXiv:2102.03069. Quads are subdivided
 * into four overlapping triangles for the smoothing. Only for linear geometry,
 * not high-order. Only for planar surfaces. CAD parameterization for curved
 * faces not supported yet. Mesh vertices on boundary curves are fixed.
 *
 * @param gf The face containing the triangles/quads
 * @param iterMax Number of outer iterations in the optimization (re-evaluation
 * of coefficients in Winslow) Typical range is 10-100.
 * @param timeMax Maximum time budget for the smoothing (in seconds)
 *
 * @return True if the smoothing have been applied (mesh may still be tangled)
 */
bool untangleGFaceMeshConstrained(GFace *gf,
				  int iterMax = 1000,
                                  double timeMax = 9999.);//,
//				  int  curveInteriorEdges = false);



/*********************/
/* Utility functions */
/*********************/

/**
 * @brief Winslow untangler applies to triangles with target shapes. This
 * utility function create the necessary inputs from triangles and quads.
 *
 * @param[in] points Point coordinates
 * @param[in] elements Triangles and quads.
 * Triangles are detected with elements[i][3] = (uint32_t) -1
 * @param[out] triangles The triangles to optimize, without overlapping when
 * quad subdivided into four corner triangles.
 * @param[out] triIdealShapes The target shapes, equilateral tri for triangles
 * and right-angled triangles for quad.
 *
 * @return True if success
 */

// P3 --- ROBUST
const int NUMTCOMBILI_3  = 9;
const int N_COMBILI_3[100] = {1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,5,5,5,7,7,7,3,3,3,3,3,3};   
/*const int TRIANGLES_3[9][4] = {{0, 3, 8, 1},
			       {2, 7, 6, 1},
			       {5, 4, 1, 1},
			       {8, 9, 7, 1},
			       {9, 5, 6, 1},
			       {9, 3, 4, 1},
			       {0, 1, 2, 1},
			       {0, 1, 2, 1},
			       {0, 1, 2, 1}};*/


const int TRIANGLES_3[100][4] = {{0, 3, 8, 1},
				 {2, 7, 6, 1},
				 {5, 4, 1, 1},
				 {8, 3, 9, 1},
				 {9, 3, 4, 1},
				 {9, 4, 5, 1},
				 {8, 9, 7, 1},
				 {7, 9, 6, 1},
				 {6, 9, 5, 1},
				 {0, 3, 9, 1},  {3, 4, 8, 1}, {0, 4, 3, 1},
				 {4, 1, 9, 1},  {3, 4, 5, 1}, {1, 4, 3, 1},
				 {1, 5, 9, 1},  {5, 6, 4, 1}, {1, 6, 5, 1},
				 {6, 2, 9, 1},  {5, 6, 7, 1}, {2, 6, 5, 1},
				 {2, 7, 9, 1},  {7, 8, 6, 1}, {2, 7, 8, 1},
				 {8, 0, 9, 1},  {7, 8, 3, 1}, {0, 8, 7, 1},
				 {3, 4, 9, 12}, {0, 3, 5, 3}, {4, 1, 8, 3}, {0, 4, 3, 3}, {0, 1, 4, 3},
				 {5, 6, 9, 12}, {1, 5, 7, 3}, {6, 2, 4, 3}, {1, 6, 5, 3}, {1, 2, 6, 3},
				 {7, 8, 9, 12}, {2, 7, 3, 3}, {8, 0, 6, 3}, {2, 8, 7, 3}, {2, 0, 8, 3},
				 {3, 9, 7, 6},  {4, 9, 8, 6}, {4, 7, 9, 6}, {0, 9, 6, 3}, {0, 5, 9, 3}, {3, 6, 9, 3},{5, 8, 9, 3},
				 {5, 9, 3, 6},  {6, 9, 4, 6}, {6, 3, 9, 6}, {1, 9, 8, 3}, {1, 7, 9, 3}, {5, 8, 9, 3},{7, 4, 9, 3},
				 {7, 9, 5, 6},  {8, 9, 6, 6}, {8, 5, 9, 6}, {2, 9, 4, 3}, {2, 3, 9, 3}, {7, 4, 9, 3},{3, 6, 9, 3},
				 {0, 3, 9, 1},  {3, 4, 8, 1}, {0, 4, 3, 1},
				 {4, 1, 9, 1},  {3, 4, 5, 1}, {1, 4, 3, 1},
				 {1, 5, 9, 1},  {5, 6, 4, 1}, {1, 6, 5, 1},
				 {6, 2, 9, 1},  {5, 6, 7, 1}, {2, 6, 5, 1},
				 {2, 7, 9, 1},  {7, 8, 6, 1}, {2, 7, 8, 1},
				 {8, 0, 9, 1},  {7, 8, 3, 1}, {0, 8, 7, 1}};

const int NUMTCOMBILI_3_  = 9;
const int N_COMBILI_3_[15] = {1,1,1,3,3,3,3,3,3,5,5,5,7,7,7};   
const int TRIANGLES_3_[57][4] = {{0, 3, 8, 1},
				{4, 1, 5, 1},
				{7, 6, 2, 1}, 
				{0, 3, 9, 9},  {3, 4, 8, 9}, {0, 4, 3, 9},
				{4, 1, 9, 9},  {3, 4, 5, 9}, {1, 3, 4, 9},
				{1, 5, 9, 9},  {5, 6, 4, 9}, {1, 6, 5, 9},
				{6, 2, 9, 9},  {5, 6, 7, 9}, {2, 5, 6, 9},
				{2, 7, 9, 9},  {7, 8, 6, 9}, {2, 8, 7, 9},
				{8, 0, 9, 9},  {7, 8, 3, 9}, {0, 7, 8, 9},
				{3, 4, 9, 12}, {0, 3, 5, 3}, {4, 1, 8, 3}, {0, 4, 3, 3}, {0, 1, 4, 3},
				{5, 6, 9, 12}, {1, 5, 7, 3}, {6, 2, 4, 3}, {1, 6, 5, 3}, {1, 2, 6, 3},
				{7, 8, 9, 12}, {2, 7, 3, 3}, {8, 0, 6, 3}, {2, 8, 7, 3}, {2, 0, 8, 3},
				{3, 9, 7, 6},  {4, 9, 8, 6}, {4, 7, 9, 6}, {0, 9, 6, 3}, {0, 5, 9, 3}, {3, 6, 9, 3},{5, 8, 9, 3},
				{5, 9, 3, 6},  {6, 9, 4, 6}, {6, 3, 9, 6}, {1, 9, 8, 3}, {1, 7, 9, 3}, {5, 8, 9, 3},{7, 4, 9, 3},
				{7, 9, 5, 6},  {8, 9, 6, 6}, {8, 5, 9, 6}, {2, 9, 4, 3}, {2, 3, 9, 3}, {7, 4, 9, 3},{3, 6, 9, 3}};


bool buildTrianglesAndTargetsFromElements(
    std::vector<std::array<double,2> >& points,
    std::vector<std::array<uint32_t,10> >& elements,
    std::vector<std::array<uint32_t, 3> >& triangles,
    std::vector<std::array<std::array<double,2>, 3> >& triIdealShapes);

bool buildTrianglesAndTargetsFromElements(
    std::vector<std::array<double,2> >& points,
    std::vector<std::array<uint32_t,4> >& elements,
    std::vector<std::array<uint32_t, 3> >& triangles,
    std::vector<std::array<std::array<double,2>, 3> >& triIdealShapes);
