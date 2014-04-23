#!/usr/bin/env python
#coding=utf-8
import onelab

modelName = 'coin'

OL = onelab.client()
print('\nStarting METAMODEL - Action = %s' %(OL.getString('python/Action')))

print __file__

A = OL.defineNumber('A', value=10)
B = OL.defineNumber('Group/B', value=0, min = -10, max = 10, step = 1)
C = OL.defineNumber('Group/C', value=2, choices = [0, 1, 2, 3], attributes={'Highlight':'Pink'})
D = OL.defineNumber('Group/D', value=3, labels = {0:'zero', 1:'un', 2:'deux', 3:'trois'}, attributes={'Highlight':'Blue'})

OL.reloadGeometry(modelName + '.geo')
OL.preProcess(modelName + '.txt.ol')

if OL.action == 'compute' :
  OL.mesh(modelName + '.msh')
  
#OL.run('gmsh', 'gmsh ' + modelName + '.geo -2')
#OL.mergeFile(modelName + '.msh')

OL.run('subclient', './sub.py','')

OL.show('A')
OL.addNumberChoice('A',1.234)
OL.addNumberChoice('A',2.345)
OL.addNumberChoice('A',3.456)
OL.show('A')
OL.setNumber('A', choices=[])
OL.show('A')

#utf-8 are allowed everywhere
#(should be prefixed by 'u' in python 2, not required in python 3)
#Omega = OL.getString(u'Ω', u'∫(∂φ/∂α)³dx', help=u'ask someone@universe.org',
#choices = ['oui', 'non', u'peut-être'])




