mod = 0x100000000
def circleShift(word,bit):
  a=word>>(32-bit)
  b=(word << bit)%mod
  return (b | a)
print(circleShift(0x80000000,2))
