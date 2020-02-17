# -*- coding: utf-8 -*-
"""
Created on Mon Sep 10 19:15:32 2018

@author: 鑫鑫玉川
"""

"""判断元音字母数量"""


def vowles_count(s):

    count = 0
    for c in s:
        if c in 'aeiouAEIOU':
            count += 1
    return count


print(vowles_count("HEllo World"))
