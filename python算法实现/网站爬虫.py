# -*- coding: utf-8 -*-
"""
Created on Wed Sep 05 20:50:37 2018

@author: 鑫鑫玉川
"""
#coding:utf-8
import sys
import requests
reload(sys)
sys.setdefaultencoding('utf-8')

data=requests.get("https://www.baidu.com/s?tn=80035161_2_dg&wd=spyder%E4%B8%AD%E4%B8%AD%E6%96%87%E8%BE%93%E5%87%BA%E4%B9%B1%E7%A0%81")
print(data.text)
