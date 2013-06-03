#!/usr/bin/env python
#coding=utf-8

import onelab
import math, os

def exportMsh(le1,le2):
   mshFile = open(onelab.path(__file__, "pend.msh"),'w')
   mshFile.write('$MeshFormat\n2.2 0 8\n$EndMeshFormat\n')
   mshFile.write('$Nodes\n3\n1 0 0 0\n2 0 %s 0\n3 0 %s 0\n$EndNodes\n' %(-le1, -le1-le2))
   mshFile.write('$Elements\n3\n1 1 2 0 1 1 2\n2 1 2 0 1 2 3\n3 15 2 0 2 3\n$EndElements\n')
   mshFile.close()

def exportMshOpt():
   optFile = open(onelab.path(__file__, "pend.msh.opt"),'w')
   optFile.write('n = PostProcessing.NbViews - 1;\n')
   optFile.write('If(n >= 0)\nView[n].ShowScale = 0;\nView[n].VectorType = 5;\n')
   optFile.write('View[n].ExternalView = 0;\nView[n].DisplacementFactor = 1 ;\n')
   optFile.write('View[n].PointType = 1;\nView[n].PointSize = 5;\n')
   optFile.write('View[n].LineWidth = 2;\nEndIf\n')
   optFile.close()

def exportIter(iter,t,x1,y1,x2,y2):
   mshFile = open(onelab.path(__file__, "pend.msh"),'a')
   mshFile.write('$NodeData\n1\n"motion"\n1\n\t%f\n3\n\t%d\n3\n' % (t, iter))
   mshFile.write('\t3\n\t1 0 0 0\n\t2 %f %f 0\n\t3 %f %f 0\n$EndNodeData\n' %(x1,y1,x2,y2))
   mshFile.close()

OL = onelab.client()

g = 9.8	# acceleration of gravity
m = 0.3 # mass of pendulum balls

l = OL.defineNumber('Geom/Length', value=1.0, label='Arm length [m]')
time = OL.defineNumber('Dyna/time', label='time [s]')
dt = OL.defineNumber('Dyna/dt', value=0.001, label='time step [s]')
tmax = OL.defineNumber('Dyna/tmax', value=20, label='max time [s]')
refresh = OL.defineNumber('Dyna/refresh', value=0.05, label='refresh interval [s]')
theta0 = OL.defineNumber('Init/theta', value=10, label='Initial theta angle [deg]', 
                         attributes={'Highlight':'Pink'})
phi0 = OL.defineNumber('Init/phi', value=180, label='Initial phi angle [deg]',
                       attributes={'Highlight':'Pink'})

# we're done if we are in the "check" phase
if OL.action == 'check' :
   exit(0)

l1 = l;
l2 = l;
m1 = m;
m2 = m;
theta = theta0 / 180.*math.pi;
phi = phi0 / 180.*math.pi;
theta_dot = 0.0
phi_dot = 0.0
time = 0.0
refr = 0.0
iter = 0

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
      OL.setNumber('python/Progress', value=time, min=0, max=tmax, visible=0)
      OL.setNumber('Dyna/time', value=time)
      OL.setNumber('Solu/phi', value=phi)
      OL.setNumber('Solu/theta', value=theta)
      OL.addNumberChoice('Solu/phi', phi)
      OL.addNumberChoice('Solu/theta', theta)
      OL.setNumber('Solu/phi_dot', value=phi_dot)
      OL.setNumber('Solu/theta_dot', value=theta_dot)
      OL.addNumberChoice('Solu/phi_dot', phi_dot)
      OL.addNumberChoice('Solu/theta_dot', theta_dot)
      OL.setString('Gmsh/Action', value='refresh')
      if(OL.getString('python/Action') == 'stop'):
         break;
      exportMsh(l1, l2)
      exportIter(iter, time, x1, y1+l1, x2, y2+l1+l2)
      OL.mergeFile(onelab.path(__file__, 'pend.msh'))
      iter += 1

OL.setNumber('python/Progress', value=0)

# comment the following lines out if you do not have gnuplot on your system
# OL.preProcess(onelab.path(__file__,'pend.plt.ol'))
# os.system('gnuplot pend.plt')

# run a subclient
# OL.run('subclient', './sub.py','')

# A = OL.defineNumber('A', value=10)
# B = OL.defineNumber('Group/B', value=0, min = -10, max = 10, step = 1)
# C = OL.defineNumber('Group/C', value=2, choices = [0, 1, 2, 3], 
#                     attributes={'Highlight':'Pink'})
# D = OL.defineNumber('Group/D', value=3, labels = {0:'zero', 1:'un', 2:'deux', 
#                     3:'trois'}, attributes={'Highlight':'Blue'})

# UTF-8 is allowed everywhere (should be prefixed by 'u' in python 2, not 
# required in python 3)
# Omega = OL.getString(u'Ω', u'∫(∂φ/∂α)³dx', help=u'ask someone@universe.org',
#                      choices = ['oui', 'non', u'peut-être'])
