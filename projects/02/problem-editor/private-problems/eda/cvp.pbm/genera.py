#!/usr/bin/python

import sys
import random


outputs, inputs, rows, assigs = map(int, sys.argv[1:])
cols = inputs

def node (i, j):
    return "n"+str(i)+"n"+str(j)

print "OUTPUT",
for j in range(outputs):
    print node(0, j),
print "END"

print "INPUT",
for j in range(inputs):
    print node(rows-1, j),
print "END"


for i in range(rows-1):
    for j in range(cols):
        r1 = random.randint(0, cols-1)
        r2 = random.randint(0, cols-1)
        if r1 == r2:
            r2 = random.randint(0, cols-1)
        op = random.randint(0, 2)
        if op == 0:
            print "NOT", node(i, j), node(i+1, r1)
        elif op == 1:
            print "AND", node(i, j), node(i+1, r1), node(i+1, r2)
        elif op == 2:
            print "OR", node(i, j), node(i+1, r1), node(i+1, r2)
print "END"



for i in range(assigs):
    n = random.randint(0, 2**inputs-1)
    for j in range(inputs):
        if (n >> j) & 1: print 'T',
        else: print 'F',
    print

