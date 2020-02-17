#二分法 x^2


y=2
a=0
b=y
guess=(a+b)/2
while abs(guess ** 2 - y) > 1e-4:
    if guess ** 2 > y:
        b=guess
    else:
        a=guess
    guess=(a+b)/2
print ("The root of is ",guess)
