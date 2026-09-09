#!/usr/bin/env python3
"""Planar 3D Sample4 quads with nonconvex UV must survive and audit as valid."""
import argparse,json,math,sys
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--bindings',type=Path,required=True)
p.add_argument('--reference',type=Path,required=True,help='Sample4 parametrized reference or delivered mesh')
p.add_argument('--report',type=Path,required=True)
p.add_argument('--cases',type=Path,required=True,help='External JSON list of face/xyz quad fixtures')
a=p.parse_args(); sys.path.insert(0,str(a.bindings.resolve())); import gmsh
# Geometry-specific coordinates are supplied externally, never committed.
CASES = json.loads(a.cases.read_text())
gmsh.initialize(); gmsh.option.setNumber('General.Terminal',0); records=[]
try:
 for index,r in enumerate(CASES):
  gmsh.clear(); gmsh.open(str(a.reference.resolve())); face=r['face']
  flat=[v for q in r['xyz'] for v in q]; uv=list(gmsh.model.getParametrization(2,face,flat))
  points=[uv[2*i:2*i+2] for i in range(4)]; turns=[]
  for i in range(4):
   x,y,z=points[i],points[(i+1)%4],points[(i+2)%4]
   turns.append((y[0]-x[0])*(z[1]-x[1])-(y[1]-x[1])*(z[0]-x[0]))
  assert min(turns)<0<max(turns),turns
  gmsh.model.mesh.clear(); gmsh.model.mesh.addNodes(2,face,[1,2,3,4],flat,uv)
  gmsh.model.mesh.addElementsByType(face,3,[1],[1,2,3,4])
  for key,val in {'Mesh.Smoothing':0,'Mesh.OptimizeQuadsSmartLaplacian':1,'Mesh.PackTargetSize':2,'Mesh.OptimizeQuadsMinimumEdgeLength':0,'Mesh.OptimizeQuadsMaximumEdgeLength':100,'General.Verbosity':6}.items():gmsh.option.setNumber(key,val)
  gmsh.logger.start(); gmsh.model.mesh.optimize('OptimizeQuadsFast',force=True)
  log='\n'.join(gmsh.logger.get()); gmsh.logger.stop()
  qt,_=gmsh.model.mesh.getElementsByType(3,face); tt,_=gmsh.model.mesh.getElementsByType(2,face)
  assert len(qt)==1 and len(tt)==0,(index,len(qt),len(tt))
  assert 'validity=PASS invalid[T/Q]=0/0' in log,(index,log)
  assert gmsh.model.mesh.getElementQualities(qt,'minSICN')[0]>0
  for t,q in enumerate(r['xyz'],1):assert math.dist(gmsh.model.mesh.getNode(t)[0],q)<1.e-12
  records.append(dict(case=index,passed=True))
finally:gmsh.finalize()
a.report.write_text(json.dumps(records,indent=2)+'\n'); print('PASS physical quad preservation and native validity audit:',len(records),'nonconvex UV cases')
