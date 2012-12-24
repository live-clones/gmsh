#!/usr/bin/env python
#coding=utf-8
import OnelabClient

oc = OnelabClient.client()

#name and default value are required
A = oc.get_number('A', 10)
#other attributes are optionals
B = oc.get_number('Group/B', 0, min = -10, max = 10, step = 1)
C = oc.get_number('Group/C', 2, choices = [0, 1, 2, 3], attributes={'Highlight':'Pink'})
D = oc.get_number('Group/D', 2, labels = {0:'zero', 1:'un', 2:'deux', 3:'trois'}, attributes={'Highlight':'Blue'})
#utf-8 are allowed everywhere (should be prefixed by 'u' in python 2, not required in python 3)
Omega = oc.get_string(u'Ω', u'∫(∂φ/∂α)³dx', help=u'ask someone@universe.org', choices = ['oui', 'non', u'peut-être'])

if oc.action != 'compute' :
  exit(0)

#this is the solver code
print (A, B, C, str(Omega))
