# -*- coding: utf-8 -*-
"""
Created on Wed Sep 05 19:19:21 2018

@author: 鑫鑫玉川
"""
#encoding=utf-8
#素数prime
def is_prime(num):
    for i in range(2,num):
        if num%2==0:
            return False
    return True
x=int(input(u"输入一个数字，判断是否为素数:"))
if is_prime(x):
    print("Yes是")
else:
    print("No")

