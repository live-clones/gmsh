#!/usr/bin/env python
#coding=utf-8

import OnelabClient as onelab

OL = onelab.client()

A = OL.getNumber('A')
B = OL.setNumber('Group/B', 20)

print 'A= %f B = %f' %(A, B)
