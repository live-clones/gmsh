#include "hxt_tools.h"
#include "hxt_point_gen_1d.h"

#include "hxt_point_gen_numerics.h"


// For the following: a line is a boundary edge

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to find corners through mesh lines input
//  
//    Returns an uint32_t array with a flag for all mesh vertices: 
//      0:  internal vertices 
//      1:  starting of line (connected to only one edge)
//      2:  vertices on boundary lines (connected to two edges)
//      3+: corner vertices (points) connected to 3 or more edges
//
//              /
//             /
//            /    (2)    (1)
//      (3+) o------o------o
//           |
//           |
//           |
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtFlagBoundaryCorners(HXTMesh *mesh, uint32_t *cornerflag)
{
  for (uint64_t i=0; i<mesh->lines.num; i++){
    HXT_ASSERT_MSG(mesh->lines.node[2*i+0] != mesh->lines.node[2*i+1],"Line with duplicate nodes");
    cornerflag[mesh->lines.node[2*i+0]] ++ ;
    cornerflag[mesh->lines.node[2*i+1]] ++ ;
  }
  return HXT_STATUS_OK;
}


//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to discretize a line 
//
//    o-----o-----o-----o-----o-----o  input line (ordered array of lines i.e. boundary edges)
//
//    o--x----x----x---x----x----x--o  computed vertices conforming to sizemap
//  
//    Start and end vertices (corners) not inserted here
//    In the case of closed line start an end vertices coincide (same point)
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtDiscretizeLine(HXTMesh *mesh,
                            const double *directions,
                            const double *sizemap,
                            const uint64_t numLines,   // number of lines (boundary edges)
                            const uint64_t *lines,     // ordered array of these lines
                            const uint32_t startPoint, // starting point (corner) of line
                            const uint32_t *corners,   // array with all corner points of the mesh
                            HXTMesh *fmesh,            // final mesh where the new vertices and lines will be stored
                            uint64_t *points2lines)    // array holding the "parent" line of original mesh for each vertex
{

  //--------------------------------------------------------------------
  // A. List points of current line 
  //--------------------------------------------------------------------
  uint32_t numPoints = (uint32_t)numLines + 1;
  uint32_t *pointsOrig;
  HXT_CHECK(hxtMalloc(&pointsOrig,numPoints*sizeof(uint32_t)));

  uint32_t curr = startPoint;
  uint32_t next = UINT32_MAX;
  uint32_t node0,node1;
  pointsOrig[0] = startPoint;
  
  for (uint64_t i=0; i<numLines; i++){
    node0 = mesh->lines.node[2*lines[i]+0];
    node1 = mesh->lines.node[2*lines[i]+1];
    next = (curr == node0) ? node1 : node0;
    pointsOrig[i+1] = next;
    curr = next;
    HXT_ASSERT(pointsOrig[i] != pointsOrig[i+1]);
    HXT_ASSERT_MSG(pointsOrig[i] == node0 || pointsOrig[i] == node1, "Point not on line");
  }
  uint32_t endPoint = pointsOrig[numPoints-1];

  // Find index of start and end nodes in the final mesh
  uint32_t startPointIndexFinal = UINT32_MAX; 
  uint32_t endPointIndexFinal = UINT32_MAX; 
  for (uint32_t i=0; i<fmesh->points.num; i++){
    if (corners[i] == startPoint) startPointIndexFinal = fmesh->points.node[i];
    if (corners[i] == endPoint) endPointIndexFinal = fmesh->points.node[i];
  }
  HXT_ASSERT_MSG(startPointIndexFinal != UINT32_MAX,"Did not find start node in final mesh");
  HXT_ASSERT_MSG(  endPointIndexFinal != UINT32_MAX,"Did not find end node in final mesh");


  //--------------------------------------------------------------------
  // B. Compute mapped accumulated size for each point
  //--------------------------------------------------------------------
  // To store mapped accumulated size
  double *pointsMap;
  HXT_CHECK(hxtMalloc(&pointsMap,numPoints*sizeof(double)));

  double mappedLength = 0.; // total length of mapped line
  pointsMap[0]=mappedLength;
  for (uint32_t i=0; i<numPoints-1; i++){

    double *p0 = mesh->vertices.coord + 4*pointsOrig[i];
    double *p1 = mesh->vertices.coord + 4*pointsOrig[i+1];
    double lsize = distance(p0,p1);

    double vec[3] = {p1[0]-p0[0],p1[1]-p0[1],p1[2]-p0[2]};
    normalize(vec);
   


    // Find equivalent sizes for p0 and p1
    double size[2] = {0.,0.};
    double frame[9];
    for (uint32_t j=0; j<2; j++){
      for (int k=0; k<9; k++) 
        frame[k] = directions[9*pointsOrig[i+j]+k];

      double maxDot = 0.0;
      uint32_t indMax = UINT32_MAX;
      double dots[3] = {fabs(myDot(vec,&frame[0])),
                        fabs(myDot(vec,&frame[3])),
                        fabs(myDot(vec,&frame[6]))};
      for (int k=0; k<3; k++){
        if (dots[k] > maxDot){
          maxDot = dots[k];
          indMax = k;
        }
      }
      size[j] = sizemap[3*pointsOrig[i+j]+indMax];
    }

    double ltilda = lsize*(1./size[0] + 1./size[1])*0.5;  
    
    mappedLength += ltilda;
    pointsMap[i+1] = mappedLength;
  }
  
  uint32_t G = round(mappedLength);
  // To ensure at least two points on the line
  if (G == 0 || G == 1) G = 2; 
  // For the case of closed line, we want to ensure
  // at least three points to be topologically valid 
  if (G <3 && startPoint == endPoint) G=3; 

  // ATTENTION for blossom quad 
  // To ensure even number of points for each line
  
  if (G%2 != 0 && G != 1){
    if (mappedLength>1) G--;
    if (mappedLength<1) G++;
  }

  double hnew = mappedLength/G; 
  uint32_t numPointsNew = G+1;


  //--------------------------------------------------------------------
  // C. Compute new interpolated points
  //    they are uniform in the mapped space 
  //    interpolate for actual coordinates 
  //    Store points and lines on final mesh 
  //--------------------------------------------------------------------
  
  // iterate "interior" nodes 
  for (uint32_t i=1; i<numPointsNew-1; i++){
    double pointNew = i*hnew; // coordinate of the new point on the mapped space
    for (uint32_t j=0; j<numPoints-1; j++){
      if (pointNew >= pointsMap[j] && pointNew<=pointsMap[j+1]){
        double t = (pointNew-pointsMap[j])/(pointsMap[j+1]-pointsMap[j]);

        double *p0 = mesh->vertices.coord + 4*pointsOrig[j];
        double *p1 = mesh->vertices.coord + 4*pointsOrig[j+1];

        HXT_ASSERT_MSG(pointsOrig[j] == mesh->lines.node[2*lines[j]+0] || 
                       pointsOrig[j] == mesh->lines.node[2*lines[j]+1], "Did not find correct parent line"); 
 
        // Store coordinates 
        // Ignore start and end point (mesh corners already stored)
        fmesh->vertices.coord[4*fmesh->vertices.num+0] = p0[0] + t * (p1[0]-p0[0]);
        fmesh->vertices.coord[4*fmesh->vertices.num+1] = p0[1] + t * (p1[1]-p0[1]);
        fmesh->vertices.coord[4*fmesh->vertices.num+2] = p0[2] + t * (p1[2]-p0[2]);

        // Store parent lint for each point
        points2lines[fmesh->vertices.num] = lines[j];

        // Build line 
        fmesh->lines.colors[fmesh->lines.num] = mesh->lines.colors[lines[j]];
        fmesh->lines.node[2*fmesh->lines.num+0] = fmesh->vertices.num-1;
        fmesh->lines.node[2*fmesh->lines.num+1] = fmesh->vertices.num;

        if (i==1){
          fmesh->lines.node[2*fmesh->lines.num+0] = startPointIndexFinal;
        }

        fmesh->lines.num++;
        fmesh->vertices.num++;

        break;
      }
    }
  }

  // Build last line
  fmesh->lines.colors[fmesh->lines.num] = mesh->lines.colors[lines[numLines-1]];
  fmesh->lines.node[2*fmesh->lines.num+0] = fmesh->vertices.num-1;
  if (numPointsNew == 2) fmesh->lines.node[2*fmesh->lines.num+0] = startPointIndexFinal;
  fmesh->lines.node[2*fmesh->lines.num+1] = endPointIndexFinal;
  fmesh->lines.num++;

  /*printf("   Mapped total line length L_ab = %f and number of new points %d \n", mappedLength, numPointsNew);*/
  /*printf("   with interval in the mapped space = %f and last point %f \n", hnew, hnew*G);*/
  /*printf("\n");*/

  HXT_CHECK(hxtFree(&pointsOrig));
  HXT_CHECK(hxtFree(&pointsMap));
  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to generate points on lines 
//  
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGeneratePointsOnLines(HXTMesh *mesh, 
                                   HXTPointGenOptions *opt,
                                   const double *directions,
                                   const double *sizemap, 
                                   HXTMesh *fmesh, 
                                   HXTPointGenParent *parent)
{

  HXT_INFO("");
  HXT_INFO("========= Generating points on lines ==========");
  HXT_INFO_COND(opt->verbosity>0,"");

  HXT_ASSERT_MSG(mesh->lines.num != 0, "Mesh does not have lines");


  // Array to store point "parent" element 
  // - for corner points gives id of corner vertex of initial mesh
  // - for points on lines gives the id of line
  uint64_t *pointParent = NULL;
  HXT_CHECK(hxtMalloc(&pointParent,fmesh->vertices.size*sizeof(uint64_t)));
  for (uint32_t i=0; i<fmesh->vertices.size; i++) pointParent[i] = UINT64_MAX;
 

  // A. Flag corner points
  uint32_t *cornerflag;
  HXT_CHECK(hxtMalloc(&cornerflag,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) cornerflag[i] = 0;
  HXT_CHECK(hxtFlagBoundaryCorners(mesh,cornerflag));

  // Set internal vertices and "regular" boundary vertices to UINT32_MAX
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (cornerflag[i] == 2) cornerflag[i] = UINT32_MAX;
    if (cornerflag[i] == 0) cornerflag[i] = UINT32_MAX;
  }

  // For open triangulations corner points should be provided in input
  for (uint32_t i=0; i<mesh->points.num; i++){
    if (cornerflag[mesh->points.node[i]] == UINT32_MAX)
      cornerflag[mesh->points.node[i]] = 2;
  }

  // B. Count corners and boundary points 
  uint32_t numCorners = 0; // connected to 1 or 3+ lines 
  uint32_t maxLinesToPoint = 0; // maximum number of lines starting from a corner

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (cornerflag[i] == UINT32_MAX) continue; // FOR 2D
    numCorners++;
    if (cornerflag[i] > maxLinesToPoint) maxLinesToPoint = cornerflag[i];
  }

  // Correction if we have only closed lineloops without corners 
  if (maxLinesToPoint == 0) maxLinesToPoint = 2;

  // Realloc if numCorners > fmesh->points.size
  // TODO Realloc 
  if (numCorners>fmesh->points.size) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Num of corners larger than allocated - TODO realloc");



  // C. Store corner points correspondance of initial mesh
  //    fmesh->points.node[i] -> final mesh vertex of corner point
  //    cornerpoints[i]       -> initial mesh vertex of corner point
  //    size of corner points = fmesh->points.num
  uint32_t *cornerpoints;
  HXT_CHECK(hxtMalloc(&cornerpoints,mesh->lines.size*sizeof(uint32_t)));
  uint32_t countStartPoints = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (cornerflag[i] != UINT32_MAX){ 

      cornerpoints[countStartPoints] = i;
      countStartPoints++;

      // Storing corner points on the final mesh 
      fmesh->vertices.coord[4*fmesh->vertices.num+0] = mesh->vertices.coord[4*i+0];
      fmesh->vertices.coord[4*fmesh->vertices.num+1] = mesh->vertices.coord[4*i+1];
      fmesh->vertices.coord[4*fmesh->vertices.num+2] = mesh->vertices.coord[4*i+2];

      // Storing of point element
      fmesh->points.node[fmesh->points.num] = fmesh->vertices.num;

      pointParent[fmesh->vertices.num] = i; //store the index of corner vertex of initial mesh

      fmesh->vertices.num++;
      fmesh->points.num++;

    }
  }

  HXT_ASSERT(numCorners == countStartPoints);
  HXT_ASSERT(fmesh->vertices.num == countStartPoints);


  // D. Create points to lines array 
  // Array node2line to store boundary edges (lines) for each point 
  uint64_t *node2line;
  HXT_CHECK(hxtMalloc(&node2line, maxLinesToPoint*mesh->vertices.num*sizeof(uint64_t)));
  for (uint64_t i=0; i<maxLinesToPoint*mesh->vertices.num; i++) node2line[i] = UINT64_MAX;

  for (uint64_t i=0; i<mesh->lines.num; i++){
    for (uint32_t j=0; j<2; j++){
      uint32_t currentPoint = mesh->lines.node[2*i+j];
      for (uint32_t k=0; k<maxLinesToPoint; k++){
        // Add line to node in position k if is empty
        if(node2line[maxLinesToPoint*currentPoint+k] == UINT64_MAX){
          node2line[maxLinesToPoint*currentPoint+k] = i;
          break;
        }
        // Break if line already exists in node2line
        if(node2line[maxLinesToPoint*currentPoint+k] == i){
          break;
        }
      }
    }
  }



  // E. Create and discretize sets of lines (boundary edges)
  
  // Array to flag already processed lines (boundary edges)
  uint8_t *insertLine;
  HXT_CHECK(hxtMalloc(&insertLine,mesh->lines.num*sizeof(uint8_t)));
  for (uint64_t i=0; i<mesh->lines.num; i++) insertLine[i] = 1;
  uint64_t numProcessedLines = 0; // total number of processed lines 
 
  // Array to store each set of lines to be discretized
  // Starting from corner point and ending on corner point
  uint64_t *orderLines;
  HXT_CHECK(hxtMalloc(&orderLines,mesh->lines.num*sizeof(uint64_t)));
  uint64_t numOrderLines = 0 ;
 
  // E1. Propagate from corners to corners and discretize 
  
  for (uint32_t i=0; i<numCorners; i++){
    uint32_t start = cornerpoints[i];

    // Iterate for all lines starting from that corner 
    for (uint32_t j=0; j<cornerflag[start]; j++){

      uint64_t currentLine = node2line[maxLinesToPoint*start+j];
      HXT_ASSERT_MSG(currentLine != UINT64_MAX, "Point to lines not well defined");

      uint32_t node0 = mesh->lines.node[2*currentLine+0];
      uint32_t node1 = mesh->lines.node[2*currentLine+1];
      HXT_ASSERT_MSG(node0 != node1, "A closed loop line should not be here");
      HXT_ASSERT_MSG(start != node0 || start != node1, "Corner is not contained on line");

      if (insertLine[currentLine] == 0) continue;

      numOrderLines = 0;
      orderLines[numOrderLines] = currentLine;
      numOrderLines++;
      insertLine[currentLine] = 0; // line is processed 
      uint32_t curr = start;
      uint64_t line0, line1;

      HXT_INFO_COND(opt->verbosity>0,"Start %d %lu %lu - %d %d", start+1, currentLine, currentLine + mesh->points.num, node0, node1);

      while(1){

        // nodes of current line 
        node0 = mesh->lines.node[2*currentLine+0];
        node1 = mesh->lines.node[2*currentLine+1];

        // next node
        uint32_t next = (node0 == curr) ? node1 : node0;
        HXT_ASSERT_MSG(next != curr, "A closed loop line should not be here");
        if (next == start) break; // the line loop is closed 

        if (cornerflag[next] != UINT32_MAX) break; // Found another corner 

        // lines of next node 
        line0 = node2line[maxLinesToPoint*next+0];
        line1 = node2line[maxLinesToPoint*next+1];

        currentLine = (line0 == currentLine) ? line1 : line0;
        HXT_ASSERT_MSG(insertLine[currentLine] != 0, "Line is already processed -> impossible");

        curr = next;
        
        // insert new line 
        orderLines[numOrderLines] = currentLine;
        insertLine[currentLine] = 0;
        numOrderLines++;

      }

      // At this point we have the ordered array orderLines with numOrderLines lines (i.e. boundary edges)
      numProcessedLines += numOrderLines;

      HXT_INFO_COND(opt->verbosity>0,"Corner point %3d - Number of boundary edges %3lu - Number of processed lines %3lu", start, numOrderLines, numProcessedLines);

      HXT_CHECK(hxtDiscretizeLine(mesh,directions,sizemap,numOrderLines,orderLines,start,cornerpoints,fmesh,pointParent));

    }

  }


  // E2. Process remaining lines without corners  
  
  uint64_t numClosedLines = 0;
  uint64_t numClosedLoops = 0;
  for (uint32_t i=0; i<mesh->lines.num; i++){
    if (insertLine[i] == 0) continue;

    uint64_t currentLine = i;
    numClosedLines ++;

    uint32_t node0 = mesh->lines.node[2*currentLine+0];
    uint32_t node1 = mesh->lines.node[2*currentLine+1];
    HXT_ASSERT_MSG(node0 != node1, "A closed loop line should not be here");

    // We start from node0 of the first non processed line we encounter
    // We add this start node also in the list of corners 
    uint32_t start = node0;
    cornerpoints[countStartPoints] = start;
    countStartPoints++;

    // Storing corner points on the final mesh 
    fmesh->vertices.coord[4*fmesh->vertices.num+0] = mesh->vertices.coord[4*node0+0];
    fmesh->vertices.coord[4*fmesh->vertices.num+1] = mesh->vertices.coord[4*node0+1];
    fmesh->vertices.coord[4*fmesh->vertices.num+2] = mesh->vertices.coord[4*node0+2];

    // Storing of point element
    fmesh->points.node[fmesh->points.num] = fmesh->vertices.num;

    pointParent[fmesh->vertices.num] = start; //store the index of corner vertex of initial mesh

    fmesh->vertices.num++;
    fmesh->points.num++;

    uint32_t curr = start;

    numOrderLines = 0;
    orderLines[numOrderLines] = currentLine;
    numOrderLines++;
    insertLine[currentLine] = 0; // line is processed 
    uint32_t line0, line1;

    while(1){
      
      // nodes of current line 
      node0 = mesh->lines.node[2*currentLine+0];
      node1 = mesh->lines.node[2*currentLine+1];

      // next node
      uint32_t next = (node0 == curr) ? node1 : node0;
      HXT_ASSERT_MSG(next != curr, "A closed loop line should not be here");
      if (next == start) break; // the line loop is closed 

      // lines of next node 
      line0 = node2line[maxLinesToPoint*next+0];
      line1 = node2line[maxLinesToPoint*next+1];

      currentLine = (line0 == currentLine) ? line1 : line0;
      HXT_ASSERT_MSG(insertLine[currentLine] != 0, "Line is already processed -> impossible");

      curr = next;
        
      // insert new line 
      orderLines[numOrderLines] = currentLine;
      insertLine[currentLine] = 0;

      numOrderLines++;
      numClosedLines++;

    }

    // At this point we have the ordered array orderLines with numOrderLines lines (i.e. boundary edges)
    numProcessedLines += numOrderLines;
    HXT_INFO_COND(opt->verbosity>0,"Closed line loop - Number of boundary edges %3lu - Number of processed lines %3lu", numOrderLines, numProcessedLines);

    HXT_CHECK(hxtDiscretizeLine(mesh,directions,sizemap,numOrderLines,orderLines,start,cornerpoints,fmesh,pointParent));
    numClosedLoops++;

  }

  HXT_ASSERT_MSG(mesh->lines.num == numProcessedLines, "Did not process all mesh lines");
  HXT_ASSERT_MSG((numCorners+numClosedLoops)==countStartPoints, "Something is missing");



  // Fill point gen parent struct with lines and points   
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (pointParent[i] == UINT64_MAX){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Vertex %d does not have parent element",i);
    }
    parent[i].type = 1;
    parent[i].id = pointParent[i];
  }

  // Fill point gen parent struct with corner points 
  for (uint32_t i=0; i<fmesh->points.num; i++){
    uint32_t nodeID = fmesh->points.node[i];
    if (pointParent[nodeID] == UINT64_MAX){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Vertex %d does not have parent element",i);
    }
    parent[nodeID].type = 15;
    parent[nodeID].id = pointParent[nodeID];
  }




  HXT_INFO_COND(opt->verbosity>0,"");
  HXT_INFO_COND(opt->verbosity>0,"Initial mesh number of lines         %lu", mesh->lines.num);
  HXT_INFO_COND(opt->verbosity>0,"Number of actual corners:            %d",  numCorners);
  HXT_INFO_COND(opt->verbosity>0,"Number of start points:              %d",  countStartPoints);
  HXT_INFO_COND(opt->verbosity>0,"Number of closed lineloops:          %lu", numClosedLoops);
  HXT_INFO_COND(opt->verbosity>0,"Number of fmesh vertices:            %d",  fmesh->vertices.num);
  HXT_INFO_COND(opt->verbosity>0,"Number of fmesh corner points:       %d",  fmesh->points.num);
  HXT_INFO_COND(opt->verbosity>0,"Number of fmesh lines:               %lu", fmesh->lines.num);

  HXT_CHECK(hxtFree(&pointParent));

  HXT_CHECK(hxtFree(&cornerflag));
  HXT_CHECK(hxtFree(&cornerpoints));
  HXT_CHECK(hxtFree(&node2line));
  HXT_CHECK(hxtFree(&insertLine));
  HXT_CHECK(hxtFree(&orderLines));

  return HXT_STATUS_OK;
}


//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to get line vertices and lines/points from input mesh
//  
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGetPointsOnLinesFromInputMesh(HXTMesh *mesh, 
                                           HXTPointGenOptions *opt,
                                           HXTMesh *fmesh, 
                                           HXTPointGenParent *fparent)
{
  HXT_INFO("");
  HXT_INFO("========= Get points on lines from input mesh ==========");

  HXTPointGenParent *parent;
  HXT_CHECK(hxtMalloc(&parent,mesh->vertices.num*sizeof(HXTPointGenParent)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) parent[i].type = UINT8_MAX;
  for (uint32_t i=0; i<mesh->vertices.num; i++) parent[i].id = UINT64_MAX;
  
  for (uint64_t i=0; i<mesh->lines.num; i++){
    fmesh->lines.node[2*i+0] = mesh->lines.node[2*i+0];
    fmesh->lines.node[2*i+1] = mesh->lines.node[2*i+1];
    fmesh->lines.colors[i] = mesh->lines.colors[i];
    parent[mesh->lines.node[2*i+0]].type = 1;
    parent[mesh->lines.node[2*i+1]].type = 1;
    parent[mesh->lines.node[2*i+0]].id = i;
    parent[mesh->lines.node[2*i+1]].id = i;
    fmesh->lines.num++;
  }
  for (uint32_t i=0; i<mesh->points.num; i++){
    fmesh->points.node[i] = mesh->points.node[i];
    parent[mesh->points.node[i]].type = 15;
    parent[mesh->points.node[i]].id = mesh->points.node[i];
    fmesh->points.num++;
  }

  uint32_t countV = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (parent[i].type == UINT8_MAX) continue;
    fmesh->vertices.coord[4*countV+0] = mesh->vertices.coord[4*i+0];
    fmesh->vertices.coord[4*countV+1] = mesh->vertices.coord[4*i+1];
    fmesh->vertices.coord[4*countV+2] = mesh->vertices.coord[4*i+2];
    fparent[countV].type = parent[i].type;
    fparent[countV].id = parent[i].id;
    countV++;
    fmesh->vertices.num++;
  }

  HXT_CHECK(hxtFree(&parent));

  return HXT_STATUS_OK;
}
