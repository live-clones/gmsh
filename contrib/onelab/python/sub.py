#!/usr/bin/env python
#coding=utf-8


import OnelabClient

oc = OnelabClient.client()

A = oc.get_number('A')
B = oc.def_number('Group/B', 20)

print 'A= %f B = %f' %(A, B)

print('Action=%s' %(oc.get_string('python/Action')))
