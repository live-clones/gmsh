#!/usr/bin/env python
#coding=utf-8
import OnelabClient as onelab

modelName = 'coin'

OL = onelab.client()
print('\nStarting METAMODEL - Action = %s' %(OL.getString('python/Action')))

#name and default value are required
A = OL.setNumber('A', 10)
#other attributes are optionals
#B = oc.def_number('Group/B', 0, min = -10, max = 10, step = 1)

OL.showGeometry(modelName + '.geo')

OL.run('gmsh', 'gmsh ' + modelName + '.geo -2')

OL.mergeFile(modelName + '.msh')

OL.run('subclient', 'sub.py')

C = OL.setNumber('Group/C', 2, choices = [0, 1, 2, 3], attributes={'Highlight':'Pink'})
D = OL.setNumber('Group/D', 2, labels = {0:'zero', 1:'un', 2:'deux', 3:'trois'}, attributes={'Highlight':'Blue'})

#utf-8 are allowed everywhere
#(should be prefixed by 'u' in python 2, not required in python 3)
#Omega = OL.getString(u'Ω', u'∫(∂φ/∂α)³dx', help=u'ask someone@universe.org',
#choices = ['oui', 'non', u'peut-être'])

OL.preProcess(modelName + '.txt.ol')

if OL.action != 'compute' :
  exit(0)
