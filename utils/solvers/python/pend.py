#!/usr/bin/env python
#coding=utf-8

# 1) launch "gmsh pend.py"
# 2) there is no 2... :-)

import onelab
import math, os

c = onelab.client(__file__)

def exportMsh(le1,le2):
   mshFile = open(c.getPath("pend.msh"), 'w')
   mshFile.write('$MeshFormat\n2.2 0 8\n$EndMeshFormat\n')
   mshFile.write('$Nodes\n3\n1 0 0 0\n2 0 %s 0\n3 0 %s 0\n$EndNodes\n' %(-le1, -le1-le2))
   mshFile.write('$Elements\n3\n1 1 2 0 1 1 2\n2 1 2 0 1 2 3\n3 15 2 0 2 3\n$EndElements\n')
   mshFile.close()

def exportMshOpt():
   optFile = open(c.getPath("pend.msh.opt"),'w')
   optFile.write('n = PostProcessing.NbViews - 1;\n')
   optFile.write('If(n >= 0)\nView[n].ShowScale = 0;\nView[n].VectorType = 5;\n')
   optFile.write('View[n].ExternalView = 0;\nView[n].DisplacementFactor = 1 ;\n')
   optFile.write('View[n].PointType = 1;\nView[n].PointSize = 5;\n')
   optFile.write('View[n].LineWidth = 2;\nEndIf\n')
   optFile.close()

def exportIter(iter,t,x1,y1,x2,y2):
   mshFile = open(c.getPath("pend.msh"),'a')
   mshFile.write('$NodeData\n1\n"motion"\n1\n\t%f\n3\n\t%d\n3\n' % (t, iter))
   mshFile.write('\t3\n\t1 0 0 0\n\t2 %f %f 0\n\t3 %f %f 0\n$EndNodeData\n' %(x1,y1,x2,y2))
   mshFile.close()

g = 9.8	# acceleration of gravity
m = 0.3 # mass of pendulum balls

l = c.defineNumber('Geom/arm length [m]', value=1.0)
time = c.defineNumber('Dyna/time [s]', value=0.0)
dt = c.defineNumber('Dyna/time step [s]', value=0.001)
tmax = c.defineNumber('Dyna/max time [s]', value=20)
refresh = c.defineNumber('Dyna/refresh interval [s]', value=0.1)
theta0 = c.defineNumber('Init/initial theta angle [deg]', value=10, 
                         attributes={'Highlight':'Pink'})
phi0 = c.defineNumber('Init/initial phi angle [deg]', value=180,
                       attributes={'Highlight':'Pink'})

# we're done if we are in the "check" phase
if c.action == 'check' :
   exit(0)

l1 = l;
l2 = l;
m1 = m;
m2 = m;
theta = theta0 / 180.*math.pi;
phi = phi0 / 180.*math.pi;
theta_dot = 0.0
phi_dot = 0.0
refr = 0.0
iter = 0
time = 0.0

while (time < tmax):
   delta = phi - theta
   sdelta = math.sin(delta)
   cdelta = math.cos(delta)
   theta_dot_dot = ( m2*l1*(theta_dot**2.0)*sdelta*cdelta
                     + m2*g*math.sin(phi)*cdelta
                     + m2*l2*(phi_dot**2.0)*sdelta
                     - (m1+m2)*g*math.sin(theta) )
   theta_dot_dot /= ( (m1+m2)*l1 - m2*l1*(cdelta)**2.0 )
   
   phi_dot_dot = ( -m2*l2*(phi_dot**2.0)*sdelta*cdelta
                    + (m1+m2)*(g*math.sin(theta)*cdelta
                               - l1*(theta_dot**2.0)*sdelta
                               - g*math.sin(phi)) )
   phi_dot_dot /= ( (m1+m2)*l2 - m2*l2*(cdelta)**2.0 )
   
   theta_dot = theta_dot + theta_dot_dot*dt
   phi_dot = phi_dot + phi_dot_dot*dt

   theta = theta + theta_dot*dt
   phi = phi + phi_dot*dt

   x1 =  l1*math.sin(theta)
   y1 = -l1*math.cos(theta)
   x2 =  l1*math.sin(theta) + l2*math.sin(phi)
   y2 = -l1*math.cos(theta) - l2*math.cos(phi)

   time += dt
   refr += dt

   exportMshOpt()

   if refr >= refresh:
      refr = 0
      c.setNumber(c.name + '/Progress', value=time, min=0, max=tmax, visible=0)
      c.setNumber('Dyna/time [s]', value=time)
      c.setNumber('Solu/phi', value=phi)
      c.addNumberChoice('Solu/phi', phi)
      c.setNumber('Solu/theta', value=theta)
      c.addNumberChoice('Solu/theta', theta)
      c.setNumber('Solu/phi dot', value=phi_dot)
      c.addNumberChoice('Solu/phi dot', phi_dot)
      c.setNumber('Solu/theta dot', value=theta_dot)
      c.addNumberChoice('Solu/theta dot', theta_dot)

      # ask Gmsh to refresh
      c.setString('Gmsh/Action', value='refresh')

      # stop if we are asked to (by Gmsh)
      if(c.getString(c.name + '/Action') == 'stop'):
         break;

      exportMsh(l1, l2)
      exportIter(iter, time, x1, y1+l1, x2, y2+l1+l2)
      c.mergeFile(c.checkPath('pend.msh'))
      iter += 1

c.setNumber(c.name + '/Progress', value=0)
