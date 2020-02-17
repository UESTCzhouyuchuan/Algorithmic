# -*- coding: utf-8 -*-
"""
Created on Wed Sep 12 20:01:47 2018

@author: 鑫鑫玉川
"""

"""
my_list.append(元素) my_list.extend(列表)；
my_list.insert(位置)
my_list.pop(位置:默认为-1),my_list.remove(元素)；
my_list.sort()
my_list.reverse();
my_list.index(元素)
"""
nums = []
for i in range(10):
    nums.append(i)
for i in nums:
    print(i)
    
print(max(nums),min(nums))
print(sum(nums)/len(nums))