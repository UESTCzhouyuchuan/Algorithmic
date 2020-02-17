# -*- coding: utf-8 -*-
"""
Created on Wed Sep 19 12:38:03 2018

@author: 鑫鑫玉川
"""

f = open('emma.txt','r');

d={}
for line in f:
    word=line.strip().split()
    for w in word:
        if w in d:
            d[w]+=1
        else:
            d[w]=1
d1=[]
for w,c in d.items():
    d1.append((c,w))
    
d1.sort(reverse=True)

for c,w in d1[:10]:
    print (w)
    
f.close()