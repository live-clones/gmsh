#!/usr/bin/env python3
"""Compare active stars to full sweeps, including propagation and a stationary island."""
import argparse,json,math,re,subprocess,sys
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--bindings',type=Path,required=True); p.add_argument('--runner',type=Path,required=True); p.add_argument('--output',type=Path,required=True)
a=p.parse_args(); out=a.output.resolve(); out.mkdir(parents=True,exist_ok=True)
sys.path.insert(0,str(a.bindings.resolve())); import gmsh
gmsh.initialize(); gmsh.option.setNumber('General.Terminal',0)
face=gmsh.model.occ.addRectangle(-1,-1,0,17,6); gmsh.model.occ.synchronize()
geo=out/'active.fixture.brep'; mesh=out/'active.fixture.msh'; gmsh.write(str(geo))
xyz=[]; cells=[]
for shift in (0,10):
 base=len(xyz)
 for j in range(5):
  for i in range(5):
   x,y=i+shift,j
   if shift==0 and i==j==2:x+=.3; y+=.15
   xyz.append([x,y,0])
 for j in range(4):
  for i in range(4):
   k=base+j*5+i+1; cells.extend([k,k+1,k+6,k+5])
uv=gmsh.model.getParametrization(2,face,[v for c in xyz for v in c])
gmsh.model.mesh.addNodes(2,face,list(range(1,51)),[v for c in xyz for v in c],uv)
gmsh.model.mesh.addElementsByType(face,3,list(range(1,33)),cells)
gmsh.option.setNumber('Mesh.SaveAll',1); gmsh.option.setNumber('Mesh.SaveParametric',1); gmsh.write(str(mesh)); gmsh.finalize()
results={}
for mode in (0,1):
 prefix=out/f'active.mode{mode}'
 cmd=[str(a.runner.resolve()),'--input',str(mesh),'--geometry',str(geo),'--output',str(prefix)+'.msh','--report',str(prefix)+'.json','--active-smoothing',str(mode),'--smart-laplacian','1','--smoothing-passes','3','--final-winslow-passes','1','--valence','0','--swaps','0','--merge-tt','0','--max-passes','-1','--target-size','1','--min-edge','0','--max-edge','100','--verbosity','6']
 r=subprocess.run(cmd,capture_output=True,text=True,check=True,timeout=120); log=r.stdout+r.stderr; Path(str(prefix)+'.log').write_text(log)
 assert 'loop end rounds=1 reason=topology-idle' in log
 assert len(re.findall(r'nodeWinslow stage=polish sweep=[1-4] end visited=18 ',log))==4
 assert int(re.search(r'terminal Winslow end passes=4 moved=(\d+)',log)[1])>0
 assert 'loop round=' not in log[log.index('terminal Winslow begin'):]
 gmsh.initialize(); gmsh.option.setNumber('General.Terminal',0); gmsh.open(str(prefix)+'.msh')
 tags,coords,_=gmsh.model.mesh.getNodes(); points={int(t):list(coords[3*i:3*i+3]) for i,t in enumerate(tags)}
 assert len(gmsh.model.mesh.getElementsByType(3)[0])==32
 for t in range(26,51):assert math.dist(points[t],xyz[t-1])<1.e-12
 gmsh.finalize()
 results[mode]=dict(points=points,visited=sum(map(int,re.findall(r'end visited=(\d+)',log))),moved=sum(map(int,re.findall(r'end visited=\d+ acceptedNodes=(\d+)',log))))
error=max(math.dist(results[0]['points'][t],results[1]['points'][t]) for t in results[0]['points'])
assert error<1.e-11,error
assert results[1]['visited']<results[0]['visited'],results
assert results[0]['moved']==results[1]['moved']>1
report=dict(passed=True,fullVisited=results[0]['visited'],activeVisited=results[1]['visited'],acceptedMoves=results[1]['moved'],maximumCoordinateDifference=error)
(out/'active.smoothing-tests.json').write_text(json.dumps(report,indent=2)+'\n'); print('PASS',report)
