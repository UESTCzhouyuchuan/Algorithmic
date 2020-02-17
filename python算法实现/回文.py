# -*- coding: utf-8 -*-
"""
Created on Wed Sep 05 08:33:31 2018

@author: 鑫鑫玉川
"""

num=int(input('输入:'))
num_t=num
num_p=0
while num_t!=0:
    num_p=num_p*10+num_t%10
    num_t=num_t/10
if num_p==num:
    print("Yes")
else:
    print("No")