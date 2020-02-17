# -*- coding: utf-8 -*-
"""
Created on Mon Sep 10 18:55:32 2018

@author: 鑫鑫玉川
"""

"""随机停车问题"""
import random

def parking(low,high):
    if (high-low<1):
        return 0;
    else:
        x=random.uniform(low,high-1)
        return parking(low,x)+1+parking(x+1,high);

count=0;
for i in range(1000):
    count+=parking(0,5)
print(count/1000.)