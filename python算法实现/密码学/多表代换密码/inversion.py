#inversion.py
import numpy as np
from companionMatrix import *
from multiAddMatrix import * 
#求出矩阵的逆
def inversion(A):
        companion = companionMatrix(A)
        det = detMatrix(A)%26
        print(det)
        t=OGLD_pro(det,26)
        det=t['x']
        print(companion,det)
        for i in range(A.shape[0]):
                for j in range(i+1):
                        companion[i][j] = (companion[i][j]*det)%26
                        if (i != j):
                                companion[j][i] = (companion[j][i]*det)%26
                                temp = companion[i][j]
                                companion[i][j] = companion[j][i]
                                companion[j][i] = temp
        return companion
"""扩展的欧几里得算法，用于求矩阵行列式的逆"""
def OGLD_pro(a,b):
    if (b==0):
        return {'d':a,'x':1,'y':0}
    else:
        t=OGLD_pro(b,a%b)
        temp=t['x']
        t['x']=t['y']
        t['y']=temp-(a//b)*t['y']
        return t

a=np.array([[11,2],[5,23]])
print(19*6%26,19*25%26)