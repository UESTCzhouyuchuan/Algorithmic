# -*- coding: utf-8 -*-
"""
Created on Sun Sep 16 20:19:33 2018

@author: 鑫鑫玉川
"""
#D装饰 S 排序 U 反装饰

def f(words):
    words.sort(key=lambda x: len(x),reverse=True)
    print(words)

words=['abc','efgh','jdfhbghj','abcd']

lst=[]

for word in words:
    lst.append((len(word),word))
    
lst.sort(reverse=True)

res=[]
for l,w in lst:
    res.append(w)
    
print(res)
f(words)
