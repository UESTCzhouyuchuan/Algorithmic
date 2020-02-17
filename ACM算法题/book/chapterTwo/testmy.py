mod=1000000007
def dfs(n,a,b):
  if (n==1):
    return (a+b)%mod
  if (n==2):
    return ((a+b)**2%mod-a*b%mod)%mod
  return (a+b)%mod*dfs(n-1,a,b)-a*b%mod*dfs(n-2,a,b)

