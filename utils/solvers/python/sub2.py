#!/usr/bin/env python
#coding=utf-8

import onelab

OL = onelab.client()

A = OL.defineNumber('A', value=30)
print 'sub2 A= %f' %(A)
