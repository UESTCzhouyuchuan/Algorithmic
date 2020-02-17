
def OGLD_pro(a,m):
  if (m==0):
    return {'d':a,'x':1,'y':0}
  else:
    t=OGLD_pro(m,a%m)
    temp=t['x']
    t['x']=t['y']
    t['y']=temp-(a//m)*t['y']
    return t

def add1(P,Q,a,mod):
    if(Q[:] == P[:]):
      t=OGLD_pro(2*P[1],mod)
      r=((3*(P[0]**2)+a)*t['x'])%mod
    else:
      t=OGLD_pro(Q[0]-P[0],mod)
      r=((Q[1]-P[1])*t['x'])%mod
    Q[0]=(r**2-P[0]-Q[0])%mod
    Q[1]=(r*(P[0]-Q[0])-P[1])%mod
    print('r:',r)
    print(Q)

def add(P,a,mod,n):
  Q=P[:]
  while(n>1):
    if(Q[:] == P[:]):
      t=OGLD_pro(2*P[1],mod)
      r=((3*(P[0]**2)+a)*t['x'])%mod
    else:
      t=OGLD_pro(Q[0]-P[0],mod)
      r=((Q[1]-P[1])*t['x'])%mod
    Q[0]=(r**2-P[0]-Q[0])%mod
    Q[1]=(r*(P[0]-Q[0])-P[1])%mod
    n-=1
    print('r:',r)
    print(Q)
  

#add([7,2],1,11,3)
add1([3,5],[10,9],1,11)

