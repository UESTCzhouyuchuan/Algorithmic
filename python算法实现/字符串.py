# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 18:09:14 2018

@author: 鑫鑫玉川
"""

#格式化输出format: "{field name:align width.precision type}".format()
import math
print ("Pi is {: <9.4f}".format(math.pi)) 
#python正则表达式:regular expression(在re库中)
"""正则表达式描述字符串的模式:
    .表示所有字符
    \d表示任意一个数字 \d+表示一系列数字
    [a-z]表示任意一个小写字母
    """
import re
name="CBBAAACBBAA"
pattern="C.A"
result=re.search(pattern,name)
if result:
    print("Yes")
else:
    print("No")
