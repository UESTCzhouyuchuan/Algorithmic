# -*- coding: utf-8 -*-
"""
Created on Fri Sep 07 22:21:09 2018

@author: 鑫鑫玉川
"""


def is_leap_year(year):
    if ((year % 4 == 0 and year % 100 != 0)or year % 400 == 0):
        return True
    else:
        return False


def get_num_of_the_month(year, month):
    if month in (1, 3, 5, 7, 8, 10, 12):
        return 31
    elif month in (4, 6, 9, 11):
        return 30
    elif is_leap_year(year):
        return 29
    else:
        return 28


def get_the_total_of_the_year(year, month):
    days = 0
    for i in range(1800, year):
        if is_leap_year(i):
            days += 366
        else:
            days += 365
    for m in range(1, month):
        days += get_num_of_the_month(year, m)
    return days


def get_start_day(year, month):
    return (3+get_the_total_of_the_year(year, month)) % 7


year, month = map(int, input("输入年月:").split())
begin = get_start_day(year, month)
days = get_num_of_the_month(year, month)
Month = ["Junary", "Febrary", "March", "April", "May", "Juan",
         "July", "August", "Sepetember", "October", "November", "December"]
print(Month[month-1].rjust(20), year, end="\n\n")
print(" 日   一   二   三   四   五   六\n")
for i in range(begin % 7):
    print("%5s" % '', end='')
for y in range(days):
    print("%3d" % (y+1), end='')
    if (y+begin+1) % 7 == 0:
        print()
    else:
        print("  ", end='')
