import gmsh
import numpy as np
import sys
import os
import csv
import math
import cmath
from scipy.optimize import minimize
from multiprocessing import Pool
import psutil
import time
import matplotlib.pyplot as plt

start_time = time.time()

from polyfit import polyfitCompute1D, polyfitEval1D, polyfitCompute2D, polyfitEval2D

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # Import the 3D plotting module


EPS = 1e-6

# possible: 3, 6, 9, 10, 12, 15, 21, 28, 36, 45, 55, 66
geoFile = ""
degree = 4
tri = 15
p_norm = 2
debug = False
fitOpt1 = False
fitOpt2 = False
polyfit = True
optimize = False
optimizationBounds = False
optimizationDistance = 1    # 0: distance, 1: weighted distance, 2: max distance
method = 'SLSQP'            # "SLSQP" or "L-BFGS-B"
nt=1
pwd = "./"
for i, arg in enumerate(sys.argv):
  if (arg == "-f" and len(sys.argv) >= i+2):
    geoFile = sys.argv[i+1]
  #if (arg == "-tri" and len(sys.argv) >= i+2):
  #  tri = int(sys.argv[i+1])
  if (arg == "-d" and len(sys.argv) >= i+2):
    degree = int(sys.argv[i+1])
  if (arg == "-p_norm" and len(sys.argv) >= i+2):
    p_norm = int(sys.argv[i+1])
  if (arg == "-nt" and len(sys.argv) >= i+2):
    nt = int(sys.argv[i+1])
  if (arg == "-debug"):
    debug = not debug
  if (arg == "-fitOpt1"):
    fitOpt1 = not fitOpt1
  if (arg == "-fitOpt2"):
    fitOpt2 = not fitOpt2
  if (arg == "-polyfit"):
    polyfit = not polyfit
  if (arg == "-optimize"):
    optimize = not optimize
  if (arg == "-bnd"):
    optimizationBounds = not optimizationBounds
  if (arg == "-dist" and len(sys.argv) >= i+2):
    optimizationDistance = int(sys.argv[i+1])
  if (arg == "-method" and len(sys.argv) >= i+2):
    if (sys.argv[i+1] == 'SLSQP' or sys.argv[i+1] == 'L-BFGS-B' or sys.argv[i+1] == 'BFGS'):
      method = sys.argv[i+1]
    else:
      print("Unknown method !")
      exit()



def distance(i):
  D = 0.
  DW = 0.
  DMax = 0.
  face = triangleVertices[i]
  isoParamCoord = isoParamCoords[face]
  
  allPoints = []
  allPoints.extend([face[0],face[1],face[2]])
  for index in range(3):
    v0 = face[index]
    v1 = face[(index+1)%3]
    if (v0 > v1):
      tmp = v0
      v0 = v1
      v1 = tmp
    allPoints.extend(edges[(v0,v1)])
  allPoints.extend(faces[face])
  
  xFit_coords = np.empty(3*len(allPoints))
  for index,p in enumerate(allPoints):
    xFit_coords[3*index:3*(index+1)] = np.append(isoParamCoord[p], 0.)
  _, _, xFit_coords = gmsh.model.mesh.getJacobian(i+1, xFit_coords)
  dists = {}
  
  for index,p in enumerate(allPoints):
    dists[p] = np.linalg.norm(coords[p] - xFit_coords[3*index:3*(index+1)], ord=p_norm)
    if (dists[p] > DMax):
      DMax = dists[p]

  D = np.sum([d for d in dists.values()])
  D /= len(dists)
  
  sum_of_dists = np.sum([[dists[p] for p in t] for t in triangleTriangles[face]], axis=1)
  DW = np.sum(sum_of_dists * triangleAreas[i][:-1])
  DW /= triangleAreas[i][-1] * 3
  if debug:
    if (optimizationDistance == 0):
      print("Distance=" + str(D))
    elif (optimizationDistance == 1):
      print("Distance weighted mean=" + str(DW))
    elif (optimizationDistance == 2):
      print("Distance max=" + str(DMax))
  return [D, DW, DMax]



def addElement(iList, degree, surface, coord):
  tags = getElementNodes(degree, i)
  gmsh.model.mesh.addElements(2, surface, [getElementID(degree)], [[i+1 for i in iList]], [tags])


def getElementNodes(degree, i):
  tri = int((degree+1)*(degree+2)/2)
  tags = np.empty(tri, dtype=int)
  face = triangleVertices[i]

  vertices = triangleVertices[i]
  for k in range(3):
    tags[k] = vertexNodes[vertices[k]]
  
  if (tri-3>0):
    for j in range(3):
      v0 = triangleVertices[i][j]
      v1 = triangleVertices[i][(j+1)%3]
      if (v0 < v1):
        tmp = edgeNodes[(v0,v1)]
      else:
        tmp = edgeNodes[(v1,v0)][::-1]
      tags[3+j*(degree-1):3+(j+1)*(degree-1)] = tmp


  if (tri-3*degree > 0):
    tags[3*degree:] = innerNodes[face]

  return tags


def getElementID(degree):
  elementID_mapping = {
    1: 2,
    2: 9,
    3: 21,
    4: 23,
    5: 25,
    6: 42,
    7: 43,
    8: 44,
    9: 45,
    10: 46,
  }
  return elementID_mapping[degree]

def getElementID2D(degree):
  elementID_mapping = {
    1: 1,
    2: 8,
    3: 26,
    4: 27,
    5: 28,
    6: 62,
    7: 63,
    8: 64,
    9: 65,
    10: 66,
  }
  return elementID_mapping[degree]

def BarycentricCoord(p0, p1, p2, p):
  d1 = p1 - p0
  d2 = p2 - p0
  d = p - p0
  den = (d2[1]*d1[0] - d2[0]*d1[1])
  u = (d2[1]*d[0] - d2[0]*d[1]) / den
  v = (-d1[1]*d[0] + d1[0]*d[1]) / den
  return u,v




#
# L O A D S
#
gmsh.initialize()
mySurface = 1;
if (geoFile):
  gmsh.open(geoFile)
else:
  mySurface = gmsh.model.addDiscreteEntity(2);
  gmsh.model.geo.synchronize()



print("Load coordinates")
coords = {}
with open(pwd+"points.csv", newline='') as csvfile:
  reader = csv.DictReader(csvfile)
  for row in reader:
    t = int(row['pointTag'])
    x = float(row['x'])
    y = float(row['y'])
    z = float(row['z'])

    coords[t] = np.array([x,y,z])


print("Load Triangles")
triangleVertices = []
triangleTriangles = {}
with open(pwd+"triangles.csv", newline='') as csvfile:
  reader = csv.DictReader(csvfile)
  tmp = []
  for row in reader:
    v0 = int(row['firstVertexTag'])
    v1 = int(row['secondVertexTag'])
    v2 = int(row['thridVertexTag'])
    t0 = int(row['firstPointTag'])
    t1 = int(row['secondPointTag'])
    t2 = int(row['thridPointTag'])
    
    face = (v0, v1, v2)
    
    if (debug and len(triangleVertices) != 0 and triangleVertices[0] != face):
      break
    
    if (len(triangleVertices) == 0 or triangleVertices[-1] != face):
      triangleVertices.append(face)
    
    if (face not in triangleTriangles):
      triangleTriangles[face] = []
    triangleTriangles[face].append([t0, t1, t2])


print("Compute areas")
triangleAreas = np.empty(len(triangleVertices), dtype=object)
for i in range(len(triangleAreas)):
  face = triangleVertices[i]
  t0 = [coords[t[1]] - coords[t[0]] for t in triangleTriangles[face]]
  t1 = [coords[t[2]] - coords[t[0]] for t in triangleTriangles[face]]
  triangleAreas[i] = 0.5 * np.linalg.norm(np.cross(t0, t1), axis=1)
  triangleAreas[i] = np.append(triangleAreas[i], sum(triangleAreas[i]))


print("Load Edges")
edges = {}
with open(pwd+"edges.csv", newline='') as csvfile:
  reader = csv.DictReader(csvfile)
  for row in reader:
    firstIndex = int(row['firstVertexTag'])
    secondIndex = int(row['secondVertexTag'])
    pointIndex = int(row['pointTag'])
    
    edge = (firstIndex, secondIndex)
    if (debug and ((firstIndex not in triangleVertices[0]) or 
                   secondIndex not in triangleVertices[0])):
      continue
    
    if edge not in edges:
      edges[edge] = []
    edges[edge].append(pointIndex)


print("Load Faces")
faces = {}
with open(pwd+"faces.csv", newline='') as csvfile:
  reader = csv.DictReader(csvfile)

  for row in reader:
    v0 = int(row['firstVertexTag'])
    v1 = int(row['secondVertexTag'])
    v2 = int(row['thridVertexTag'])
    p = int(row['pointTag'])

    face = (v0, v1, v2)
    if (debug and len(faces) != 0 and face not in faces):
      break

    if (face not in faces):
      faces[face] = []
    faces[face].append(p)

print("Load Parametrization")
paramCoords = {}
with open(pwd+"parametrization.csv", newline='') as csvfile:
  reader = csv.DictReader(csvfile)

  for row in reader:
    v0 = int(row['firstVertexTag'])
    v1 = int(row['secondVertexTag'])
    v2 = int(row['thridVertexTag'])
    p = int(row['pointTag'])
    u = float(row['pointU'])
    v = float(row['pointV'])

    face = (v0, v1, v2)
    if (debug and len(paramCoords) != 0 and face not in paramCoords):
      break

    if (face not in paramCoords):
      paramCoords[face] = {}
    paramCoords[face][p] = np.array([u, v])


print("Map on isoparametric triangle")
isoParamCoords = {}
for face in triangleVertices:
  isoParamCoords[face] = {j: BarycentricCoord(paramCoords[face][face[0]],
                                              paramCoords[face][face[1]],
                                              paramCoords[face][face[2]], p) for j, p in paramCoords[face].items()}


entities = {}
tag2Entity = {}
if (geoFile and os.path.exists(pwd+"entities.csv")):
  print("Load Entities")
  with open(pwd+"entities.csv", newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    tmp = []
    for row in reader:
      eDim = int(row['entityDim'])
      eTag = int(row['entityTag'])

      if (eDim == 0):
        vTags = [int(row['vertexTag1'])]
      elif (eDim == 1):
        vTags = [int(row['vertexTag1']), int(row['vertexTag2'])]
      elif (eDim == 2):
        vTags = [int(row['vertexTag1']), int(row['vertexTag2']), int(row['vertexTag3'])]
        

      if (eDim,eTag) not in entities:
        entities[(eDim,eTag)] = []
      if (eDim == 2):
        entities[(eDim,eTag)].extend(vTags)
      else:
        entities[(eDim,eTag)].append(vTags)

      for vTag in vTags:
        if vTag not in tag2Entity:
          tag2Entity[vTag] = (eDim,eTag)

#
# B U I L D   E L E M E N T S
#
print("Build elements")
nodeCount = 0

print(" - Vertices nodes")
vertexNodes = {}
vertexNodeCoords = []
for i,face in enumerate(triangleVertices):
  for j in range(3):
    vertex = triangleVertices[i][j]
    if vertex not in vertexNodes:
      nodeCount += 1
      vertexNodes[vertex] = nodeCount
      vertexNodeCoords.extend(coords[vertex])

      if tag2Entity:
        dimTag = tag2Entity[vertex]
      else:
        dimTag = (2,mySurface)
        
      gmsh.model.mesh.addNodes(dimTag[0], dimTag[1], [vertexNodes[vertex]], coords[vertex])
      
# gmsh.model.mesh.addNodes(2, mySurface, range(1,nodeCount+1), vertexNodeCoords)


print(" - Edges nodes")
edgeTs = np.arange(1., degree) / degree

edgeNodes = {}
edgeNodeCoords = []
lineCount = 1;
for edge,points in edges.items():
  if (edge[0] > edge[1]):
    continue
  
  # Collect points
  xs = np.empty(len(points) + 2, dtype=float)
  ys = np.empty(len(points) + 2, dtype=float)
  zs = np.empty(len(points) + 2, dtype=float)
  xs[0], ys[0], zs[0] = coords[edge[0]]
  for k,point in enumerate(points):
    xs[k+1], ys[k+1], zs[k+1] = coords[point]
  xs[-1], ys[-1], zs[-1] = coords[edge[1]]

  # Parametrization
  delta_x = np.diff(xs)
  delta_y = np.diff(ys)
  delta_z = np.diff(zs)
  ts = np.zeros(len(xs))
  ts[1:] = np.sqrt(delta_x ** 2 + delta_y ** 2 + delta_z ** 2).cumsum()
  ts /= ts[-1]

  # Find nodes
  if polyfit:
    if fitOpt1:
      fitRange = [0, len(xs)-1]
    else:
      fitRange = []

    xCoefficients = polyfitCompute1D(ts, xs, degree, fitRange)
    yCoefficients = polyfitCompute1D(ts, ys, degree, fitRange)
    zCoefficients = polyfitCompute1D(ts, zs, degree, fitRange)

    nodeXs = polyfitEval1D(xCoefficients, edgeTs)
    nodeYs = polyfitEval1D(yCoefficients, edgeTs)
    nodeZs = polyfitEval1D(zCoefficients, edgeTs)

  else:
    nodeXs = np.empty(len(edgeTs), dtype=float)
    nodeYs = np.empty(len(edgeTs), dtype=float)
    nodeZs = np.empty(len(edgeTs), dtype=float)

    for i,ot in enumerate(edgeTs):
      for j in range(len(ts)-1):
        if (ts[j] <= ot and ot <= ts[j+1]):
          ratio = (ot-ts[j])/(ts[j+1]-ts[j])
          oppRatio = 1- ratio
          nodeXs[i] = oppRatio * xs[j] + ratio * xs[j+1]
          nodeYs[i] = oppRatio * ys[j] + ratio * ys[j+1]
          nodeZs[i] = oppRatio * zs[j] + ratio * zs[j+1]
          break

  edgeNodes[edge] = range(nodeCount+1,nodeCount+1+len(edgeTs))
  nodeCount += len(edgeTs)
  for l in range(len(edgeTs)):
    edgeNodeCoords.extend([nodeXs[l], nodeYs[l], nodeZs[l]])

  dimTag = (0,0)
  if (entities):
    for entity,es in entities.items():
      if (entity[0] == 0):
        continue

      if (entity[0] == 1):
        for e in es:
          if ((edge[0] in e) and (edge[1] in e)):
            dimTag = entity
            break
        continue
      if (dimTag != (0,0)):
        break


      if ((edge[0] in es) and (edge[1] in es)):
        dimTag = entity
        break
  else:
    dimTag = (2,mySurface)

  if (dimTag == (0,0)):
    print("Error: the two vertices "+edge+" are not defined on the same physical group")
    exit()

  coordsTmp = edgeNodeCoords[-3*len(edgeNodes[edge]):]
  gmsh.model.mesh.addNodes(dimTag[0], dimTag[1], edgeNodes[edge], coordsTmp)

  if (dimTag[0] == 1):
    tags = []
    tags.append(vertexNodes[edge[0]])
    tags.append(vertexNodes[edge[1]])
    tags.extend(edgeNodes[edge])
    elementID = getElementID2D(degree)
    
    gmsh.model.mesh.addElements(dimTag[0], dimTag[1], [elementID], [[lineCount]], [tags])
    lineCount += 1


# gmsh.model.mesh.addNodes(2, mySurface, range(len(vertexNodes)+1,nodeCount+1), edgeNodeCoords)


print(" - Interior nodes")
verticesUVs = [0, 0, 1, 0, 0, 1]
edgeUVs = []
for i in range(3):
  for j,edgeT in enumerate(edgeTs):
    edgeUVs.extend([(1-edgeT)*verticesUVs[2*i+x] + edgeT*verticesUVs[2*((i+1)%3)+x] for x in range(2)])
faceUVs = []
dmp = degree
shift = 0.
while (dmp > 2):
  shift += 1/degree
  if (dmp == 3):
    faceUVs.append([shift, shift])
    break
  faceUVs.append([shift, shift])
  faceUVs.append([1-(2*shift), shift])
  faceUVs.append([shift, 1-(2*shift)])
  dmp -= 3
  for i in range(1,dmp):
    faceUVs.append([shift + i/degree, shift])
  for i in range(1,dmp):
    faceUVs.append([1-(2*shift + i/degree), shift + i/degree])
  for i in range(1,dmp):
    faceUVs.append([shift, 1-(2*shift + i/degree)])

innerNodes = {}
innerCoords = []
for i,face in enumerate(triangleVertices):
  # Collect points
  points = faces[face]
  total_length = len(points)
  faceEdges = []
  for j in range(3):
    v0 = face[j]
    v1 = face[(j+1)%3]
    if (v0 > v1):
      v0, v1 = v1, v0
    faceEdges.append((v0,v1))
    total_length += len(edges[faceEdges[j]])
  total_length += 3
  if (polyfit):
    if (fitOpt2):
      total_length += 3*(degree-1)

  xs = np.empty(total_length)
  ys = np.empty(total_length)
  zs = np.empty(total_length)
  us = np.empty(total_length)
  vs = np.empty(total_length)
  
  k = 0
  for j in range(3):
    xs[k], ys[k], zs[k] = coords[face[j]]
    us[k], vs[k] = verticesUVs[2*j:2*(j+1)]
    k += 1
  for j in range(3):
    edge = faceEdges[j]
    for p in edges[edge]:
      xs[k], ys[k], zs[k] = coords[p]
      us[k], vs[k] = isoParamCoords[face][p]
      k += 1
  for p in points:
    xs[k], ys[k], zs[k] = coords[p]
    us[k], vs[k] = isoParamCoords[face][p]
    k += 1
  
  # Find nodes
  if polyfit:
    fi = []
    
    if (fitOpt1):
      fi.extend(range(3))
    
    if (fitOpt2):
      fi.extend(range(k,k+3*(degree-1)))
      nodeCoords = []
      for j in range(3):
        v0 = face[j]
        v1 = face[(j+1)%3]
        if (v0 > v1):
          v0, v1 = v1, v0
        edge = (v0,v1)
        for node in edgeNodes[edge]:
          index = node-len(vertexNodes)-1
          nodeCoords.extend(edgeNodeCoords[3*index:3*(index+1)])
      for n in range(3*(degree-1)):
        xs[k], ys[k], zs[k] = nodeCoords[3*n:3*(n+1)]
        us[k], vs[k] = edgeUVs[2*n:2*(n+1)]
        k += 1


    xCoefficients = polyfitCompute2D(us, vs, xs, degree, fi)
    yCoefficients = polyfitCompute2D(us, vs, ys, degree, fi)
    zCoefficients = polyfitCompute2D(us, vs, zs, degree, fi)

    for index,nodeUV in enumerate(faceUVs):
      nodeX = polyfitEval2D(xCoefficients, nodeUV[0], nodeUV[1])
      nodeY = polyfitEval2D(yCoefficients, nodeUV[0], nodeUV[1])
      nodeZ = polyfitEval2D(zCoefficients, nodeUV[0], nodeUV[1])
      innerCoords.extend([nodeX, nodeY, nodeZ])
    innerNodes[face] = range(nodeCount+1, nodeCount+1+len(faceUVs))
    nodeCount += len(faceUVs)

  else:
    triangles = triangleTriangles[face]
    for index,p in enumerate(faceUVs):
      for t in triangles:
        u,v = BarycentricCoord(np.array(isoParamCoords[face][t[2]]),
                               np.array(isoParamCoords[face][t[0]]),
                               np.array(isoParamCoords[face][t[1]]), np.array(p))
        if (u >= 0 and v >= 0 and 1-u-v >= 0):
          c1 = coords[t[0]]
          c2 = coords[t[1]]
          c3 = coords[t[2]]
          nodeXs = u*c1[0] + v*c2[0] + (1-u-v)*c3[0]
          nodeYs = u*c1[1] + v*c2[1] + (1-u-v)*c3[1]
          nodeZs = u*c1[2] + v*c2[2] + (1-u-v)*c3[2]
          innerCoords.extend([nodeXs, nodeYs, nodeZs])
          break
    innerNodes[face] = range(nodeCount+1, nodeCount+1+len(faceUVs))
    nodeCount += len(faceUVs)

  dimTag = (0,0)
  if (entities):
    for entity,ts in entities.items():
      if (entity[0] == 0 or entity[0] == 1):
        continue

      if ((face[0] in ts) and (face[1] in ts) and (face[2] in ts)):
        dimTag = entity
        break
  else:
    dimTag = (2,mySurface)
    
  if (dimTag == (0,0)):
    print("Error: the two vertices "+edge+" are not defined on the same physical group")
    exit()

  coordsTmp = innerCoords[-3*len(innerNodes[face]):]
  gmsh.model.mesh.addNodes(dimTag[0], dimTag[1], innerNodes[face], coordsTmp)


firstInteriorNode = len(vertexNodes)+(degree-1)*len(edgeNodes)+1
# gmsh.model.mesh.addNodes(2, mySurface, range(firstInteriorNode,nodeCount+1), innerCoords)


print(" - Add elements")
tagss = []
indices = []
elementID = getElementID(degree)
for i in range(len(triangleVertices)):
  tagss.extend(getElementNodes(degree, i))
  indices.append(i+1)
gmsh.model.mesh.addElements(2, mySurface, [elementID], [indices], [tagss])


print(" - Compute distances")
dists = np.empty(len(triangleVertices))
distWs = np.empty(len(triangleVertices))
distMaxs = np.empty(len(triangleVertices))
for i,face in enumerate(triangleVertices):
  dists[i], distWs[i], distMaxs[i] = distance(i)





def optimizeTriangle(i):
  face = triangleVertices[i]
  points = faces[face]

  tri = int((degree+1)*(degree+2)/2)
  tags = range(firstInteriorNode + i*(tri-3*degree), firstInteriorNode + (i+1)*(tri-3*degree))
  xl = np.empty(3*len(tags))
  bnd_xl = np.empty([3*len(tags), 2])

  xs = np.empty(len(points))
  ys = np.empty(len(points))
  zs = np.empty(len(points))
  for j,p in enumerate(points):
    xs[j], ys[j], zs[j] = coords[p]
  minCoords = np.array([min(xs), min(ys), min(zs)])
  maxCoords = np.array([max(xs), max(ys), max(zs)])
  diff = maxCoords - minCoords
  boxScaling = 1e-1
  for j,nodeUV in enumerate(faceUVs):
    xl[3*j]   = polyfitEval2D(xCoefficients, nodeUV[0], nodeUV[1])
    xl[3*j+1] = polyfitEval2D(yCoefficients, nodeUV[0], nodeUV[1])
    xl[3*j+2] = polyfitEval2D(zCoefficients, nodeUV[0], nodeUV[1])
    bnd_xl[3*j:3*(j+1),:] = list(zip(xl[3*j:3*(j+1)] - boxScaling*diff, xl[3*j:3*(j+1)] + boxScaling*diff))

  def objective_function(xl):
    for index,tag in enumerate(tags):
      gmsh.model.mesh.setNode(tag, xl[3*index:3*(index+1)], [])
    return distance(i)[optimizationDistance]


  if optimizationBounds:
    results = minimize(objective_function, xl, method=method, bounds=bnd_xl)
  else:
    results = minimize(objective_function, xl, method=method)
  optimized_xl = results.x
  minimized_dist = results.fun


  print(str(i) +" over "+ str(len(triangleVertices)))
  print("Distance: " + str(dists[i]))
  print("Distance weighted: " + str(distWs[i]))
  print("Distance max: " + str(distMaxs[i]))

  if optimize:
    dist, distW, distMax = distance(i)
    print("Minimized distance: " + str(dist))
    print("Minimized distance weighted: " + str(distW))
    print("Minimized distance max: " + str(distMax))
    #print("Not Optimized xl: " + str(xl))
    #print("Optimized xl: " + str(optimized_xl))
  print()

  return optimized_xl, dist, distW, distMax


elementTags = []
for i,face in enumerate(triangleVertices):
  elementTags.append(i+1)

if optimize:
  if tri > 6:
    print("Optimization of inner points")
    threadNum=len(psutil.Process().cpu_affinity())
    with Pool(threadNum) as pool:
      results = pool.map(optimizeTriangle, range(len(triangleVertices)))

  optDists = np.empty(len(elementTags))
  optDistWs = np.empty(len(elementTags))
  optDistMaxs = np.empty(len(elementTags))
  for i in range(len(results)):
    optimized_xl, dist, distW, distMax = results[i]
    optDists[i] = dist
    optDistWs[i] = distW
    optDistMaxs[i] = distMax

modelName = gmsh.model.getCurrent()

gmsh.view.add("Distance", 1)
if optimize:
  gmsh.view.add("OptDistance", 2)
gmsh.view.add("Distance_weighted", 3)
if optimize:
  gmsh.view.add("OptDistance_weighted", 4)
gmsh.view.add("Distance_max", 5)
if optimize:
  gmsh.view.add("OptDistance_max", 6)

gmsh.view.addModelData(1, 0, modelName, "ElementData", elementTags, [[d] for d in dists])
if optimize:
  gmsh.view.addModelData(2, 0, modelName, "ElementData", elementTags, [[d] for d in optDists])
gmsh.view.addModelData(3, 0, modelName, "ElementData", elementTags, [[d] for d in distWs])
if optimize:
  gmsh.view.addModelData(4, 0, modelName, "ElementData", elementTags, [[d] for d in optDistWs])
gmsh.view.addModelData(5, 0, modelName, "ElementData", elementTags, [[d] for d in distMaxs])
if optimize:
  gmsh.view.addModelData(6, 0, modelName, "ElementData", elementTags, [[d] for d in optDistMaxs])




gmsh.option.setNumber("Geometry.Points", 0)
gmsh.option.setNumber("Geometry.Curves", 0)
#gmsh.option.setNumber("Mesh.Nodes", 1)
gmsh.option.setNumber("Mesh.Lines", 1)
gmsh.option.setNumber("Mesh.SurfaceEdges", 1)
#gmsh.option.setNumber("Mesh.SurfaceFaces", 1)
gmsh.option.setNumber("Mesh.NumSubEdges", 10)

if (tri > 3):
  for i in range(6):
    if (not optimize) and ((i+1)%2==0):
      continue
    gmsh.view.option.setNumber(i+1, "AdaptVisualizationGrid", 1)
    gmsh.view.option.setNumber(i+1, "TargetError", -1e-1)
    gmsh.view.option.setNumber(i+1, "MaxRecursionLevel", 6)

end_time = time.time()
elapsed_time = end_time - start_time
print(f"Elapsed time: {elapsed_time} seconds")


fname = ""
if debug:
  fname += "d"
if geoFile:
  fname += os.path.splitext(os.path.basename(geoFile))[0]
if polyfit:
  fname += "polyfit"
if optimize:
  fname += "O"
fname += str(degree)

gmsh.write(fname+".msh")

try:
  os.remove(fname+"dists.msh")
except:
  pass
for i in range(6):
  if (not optimize) and ((i+1)%2==0):
    continue
  gmsh.view.write(i+1, fname+"dists.msh", True)

if '-nopopup' not in sys.argv:
  gmsh.fltk.run()

gmsh.finalize()


