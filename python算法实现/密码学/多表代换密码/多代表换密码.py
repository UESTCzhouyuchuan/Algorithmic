#多表代换密码.py
from inversion import *

from multiAddMatrix import *

from transTo import *

def encryptProcess(A,M,B,n):
  result=multiMatrix(A,M,n)
  addMatrix(result,B,n)
  return result
def outEncryptProcess(A,M,B,n):
  A_ = inversion(A)
  print("加密矩阵A的逆为：\n",A_)
  result=np.array([[M[j][i] for i in range(M.shape[1])] for j in range(M.shape[0])])
  subMatrix(result,B,n)
  finalResult=multiMatrix(A_,result,n)
  return finalResult
A=np.array([[11,2,19],[5,23,25],[20,7,17]])
B=[0,0,0]
n=len(B)
myStr="yourpinnoisfouronetwosix"
b = transToMatrix(myStr, n)
print("明文为：",myStr)
print("\n明文转化为数字后得到M矩阵：\n",b)
print("\n加密矩阵A为：\n",A)
print("\n....正在加密，稍等....")
secret=encryptProcess(A,b,B,n)
print("\n加密后的M矩阵为：\n",secret)
secStr = transToString(secret,n)
print("\n密文为：",secStr)
print("\n....正在解密，稍等.....")
result=outEncryptProcess(A,secret,B,n)
print("\n解密后的M矩阵为：\n",result)
print("\n密文解密后的明文为：",transToString(result,n))

