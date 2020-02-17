# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 12:41:09 2018

@author: 鑫鑫玉川
"""

def gcd(m,n):
    if n==0:
        return m;
    else:
        return gcd(n,m%n);

def OGLD(a,b,xy):
   if b==0:
       xy[0]=1
       xy[1]=0
       return a;
   else:
       ans=OGLD(b,a%b,xy)
       tmp=xy[0];
       xy[0]=xy[1];
       s=int(a/b)
       xy[1]=tmp-s*xy[0]
       return ans
xy=[0,0]
print (OGLD(4864,3458,xy))
print(xy)
