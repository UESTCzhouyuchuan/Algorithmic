# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 17:30:46 2018

@author: 鑫鑫玉川
"""
#判断字母升序
def is_ascending(name):
    p=name[0]
    for c in name:
        if p > c:
            return False
        p=c
        
    return True

#判断回文3种函数方法
def is_panlindorm(name):
    low=0
    high=len(name)-1
    while low < high:
        if name[low]!=name[high]:
            return False
        low+=1
        high-=1
        
    return True
def is_panlindorm1(name):
    name1=name[::-1]
    for i in range(len(name)):
        if name[i]!=name1[i]:
            return False
    return True
def is_panlindorm_rec(name):
    if len(name)<=1:
        return True
    if name[0]!=name[len(name)-1]:
        return False
    return is_panlindorm_rec(name[1:-1])
f = open('name.txt','r+')

for line in f:
    line=line.strip();"""Python strip() 方法用于移除字符串头尾指定的字符（默认为空格或换行符）或字符序列。"""
    if is_panlindorm(line):
        print (line)  ;    """title()函数:首字母大写，其余小写"""
    
f.close()