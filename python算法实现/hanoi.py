# -*- coding: utf-8 -*-
"""
Created on Mon Sep 10 18:38:18 2018

@author: 鑫鑫玉川
"""
"""2的n次方-1"""
def hanoi(n,A,B,C):
     if n==1:
         print("Move",n,"from",A,"to",C)
     else:
        hanoi(n-1,A,C,B)
        print("Move",n,"from",A,"to",C)
        hanoi(n-1,B,A,C)

hanoi(5,"左","中","右")