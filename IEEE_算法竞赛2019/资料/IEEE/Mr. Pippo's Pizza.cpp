from __future__ import print_function
from math import factorial

# get first line of input
ways_of_cutting = int(raw_input())

# check if there is a remaining line of input (should return "None" and exit if EOF reached)
while ways_of_cutting:
    # print("ways_of_cutting: {}".format(ways_of_cutting))

    if ways_of_cutting == 1:
        print(3)
    elif ways_of_cutting == 2:
        print(4)
    elif ways_of_cutting == 5:
        print(5)
    else:
        for n in range(5, 1000):
            if factorial(2 * (n - 2)) / (factorial(n - 1) * factorial(n - 2)) == ways_of_cutting:
                print(n)
                break

    # get next line of input
    try:
        line = raw_input()
    except:
        break
    ways_of_cutting = int(line)
