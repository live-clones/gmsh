#!/usr/bin/env python
#coding=utf-8

import onelab

OL = onelab.client()

A = OL.getNumber('A')
print 'A= %f' %(A)
OL.setNumber('Group/B', value=20)


