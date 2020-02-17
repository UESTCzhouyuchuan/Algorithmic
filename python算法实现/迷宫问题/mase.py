# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 23:19:34 2018

@author: 鑫鑫玉川
"""

#迷宫问题

xl=[0,1,0,-1,1,1,-1,-1]
yl=[1,0,-1,0,1,-1,1,-1]

def path(x,y,mx,my,a):
    if (x==mx and y==my):
        return True
    else:
        a[x,y]=1
        for i in range(8):
            x1=x+xl[i]
            y1=y+yl[i]
            if a[x1,y1]==0:
                if path(x1,y1,mx,my,a):
                    a[x1,y1]=88
                    return True
    return False
"""
a=np.zeros((n+2,n+2),dtype=np.int)
print (a)
"""

#初始化，利用随机数创建迷宫
"""
import random
b=[[random.randint(0,1) for i in range(2+m)]for j in range(n+2)]
b=np.array(b,dtype=int)
b[0,:]=b[9,:]=1
b[:,0]=b[:,9]=1
b[1,1]=0
b[8,8]=0
f = open("maze.txt","w+")
#数组写入文件np.savetxt(file，array,fmt(format))
np.savetxt(f,b,fmt='%2d')
f.close()
"""
#读文件到数组中 array=np.loadtxt(file,dtype)
import numpy as np
f = open("C:\\Users\\鑫鑫玉川\\Desktop\\pycode\\迷宫问题\\maze.txt","r+")
b=np.loadtxt(f,dtype=np.int)
f.close()
print("迷宫 following: \n",b)
print("能找到的出口吗:",end=' ')
if (path(1,1,8,8,b)):
    print("Yes\n")
else:
    print("No")
b[1,1]=88
print("88所在的地方即为路径: ")
print(b)