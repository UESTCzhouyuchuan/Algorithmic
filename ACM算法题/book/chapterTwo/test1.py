import numpy as np


def mergeSort(lyst):
    copyBuffer = np.zeros(len(lyst), dtype=int)
    mergeSortHelper(lyst, copyBuffer, 0, len(lyst) - 1)


def mergeSortHelper(lyst, copyBuffer, low, high):
    if low < high:
        middle = (low + high) // 2
        mergeSortHelper(lyst, copyBuffer, low, middle)
        mergeSortHelper(lyst, copyBuffer, middle + 1, high)
        merge(lyst, copyBuffer, low, middle, high)


def merge(lyst, copyBuffer, low, middle, high):
    i1 = low
    i2 = middle + 1

    for i in range(low, high + 1):
        if i1 > middle:
            copyBuffer[i] = lyst[i2]
            i2 += 1
        elif i2 > high:
            copyBuffer[i] = lyst[i1]
            i1 += 1
        elif lyst[i1] < lyst[i2]:
            copyBuffer[i] = lyst[i1]
            i1 += 1
        else:
            copyBuffer[i] = lyst[i2]
            i2 += 1
    for i in range(low, high + 1):
        lyst[i] = copyBuffer[i]

def split(lyst, n, m, k):
    mergeSort(lyst)
    i = 1
    j=k
    while i < k:
        print(lyst[j-1])
        i+=1
        j+=k

str_in0=input()
num0=list(map(int,str_in0.strip().split()))
n=num0[0]
m=num0[1]
k=num0[2]
majorlyst=[]
for i in range(k*k):
    str_in = input()
    num=list(map(int,str_in.strip().split()))
    majorlyst.extend(num)
    
row=majorlyst[::2]
column=majorlyst[1::2]

split(row,n,m,k)
split(column,n,m,k)
