import numpy as np


def detMatrix(A):
    if (A.shape[0] != A.shape[1]):  
        print("The matrix row not equal column")
        return
    else:
        if (A.shape[0]==1):
            return A[0][0]
        elif (A.shape[0] == 2):  
            return (A[0][0] * A[1][1] - A[1][0] * A[0][1])
        else:  
            sum = 0
            n = A.shape[0]

            for col in range(n):
                sum += A[0][col] * ((-1) ** col) * detMatrix(restMatrix(A, 0, col))  # 调用自己求出代数余子式的行列?
            return sum



def restMatrix(A, row, col):
    n = A.shape[0]
    B = np.zeros((n - 1, n - 1),dtype=int)
    for i in range(n):
        for j in range(n):
            if (i < row and j < col):
                B[i][j] = A[i][j]
            elif (i > row and j < col):
                B[i - 1][j] = A[i][j]
            elif (i < row and j > col):
                B[i][j - 1] = A[i][j]
            elif (i > row and j > col):
                B[i - 1][j - 1] = A[i][j]
    return B
