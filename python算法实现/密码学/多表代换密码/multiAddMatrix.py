#multiAddMatrix.py
import numpy as np

#矩阵乘积
def multiMatrix(A,M,n):
    len_M = len(M)
    result=np.zeros((len_M,n),dtype=int)
    for i in range(len_M):
        for j in range(n):
            sum=0
            for k in range(n):
                sum+=A[j][k]*M[i][k]
            result[i][j]=sum%26
    return result
#求矩阵相加
def addMatrix(A,B,n):
    for item in A:
        for i in range(n):
            item[i]+=B[i]
            item[i]=item[i]%26
#求矩阵差
def subMatrix(A,B,n):
    for item in A:
        for i in range(n):
            item[i]-=B[i]
            item[i]=item[i]%26
