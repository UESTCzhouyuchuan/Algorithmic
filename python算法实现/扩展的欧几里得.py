# -*- coding: utf-8 -*-
"""
Created on Thu Oct 11 21:54:36 2018

@author: 鑫鑫玉川
"""

def OGLD(a,b):
    if (b==0):
        return {'d':a,'x':1,'y':0}
    else:
        t=OGLD(b,a%b)
        tmp=t['x']
        t['x']=t['y']
        t['y']=tmp-int(a/b)*t['y'] 
        return t

a,b = map (int,input("输入这两个数：").split())
print(OGLD(a,b))