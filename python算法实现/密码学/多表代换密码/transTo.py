#transTo.py
import numpy as np
#英文字母字符串转化为行为n的矩阵
def transToMatrix(string, n):
    result = []
    words = "abcdefghijklmnopqrstuvwxyz"
    trans = {words[i]: i for i in range(26)}
    index = 0
    while (index < len(string)):
        a = []
        while (True):
            a.append(trans[string[index]])
            index += 1
            if (index % n == 0):
                break
        result.append(a)
    result = np.array(result)
    return result
#矩阵转化为字符串
def transToString(a, n):
    words = "abcdefghijklmnopqrstuvwxyz"
    result = []
    for i in range(len(a)):
        for j in range(n):
            result.append(words[a[i][j]])
    result = np.array(result)
    return result
