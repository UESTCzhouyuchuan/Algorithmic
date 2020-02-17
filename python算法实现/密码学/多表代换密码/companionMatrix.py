from detMatrix import *
from multiAddMatrix import *

"""求伴随矩阵，要用到行列式以及代数余子式"""


def companionMatrix(A):
    n = A.shape[0]
    result = np.zeros((n, n),dtype=int)
    for i in range(n):
        for j in range(n):
            result[i][j] = ((-1) ** (i + j)) * detMatrix(restMatrix(A, i, j))
    return result
