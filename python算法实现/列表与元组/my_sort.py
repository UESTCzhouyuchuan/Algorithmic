# -*- coding: utf-8 -*-
"""
Created on Wed Sep 12 21:39:55 2018

@author: 鑫鑫玉川
"""
"""
sortd(list)

list.sort()

"""
def selection_sort(lst):
    pass
def bubble_sort(lst):
    pass
    

def partition(lst,left,right):
    l = left
    r = right-1
    tmp = lst[l]
    while ( l < r ) :
        while ( l < r and lst[r] >= tmp):
            r=r-1
        lst[l]=lst[r]
        while ( l < r and lst[l] <= tmp):
            l=l+1
        lst[r]=lst[l]
    lst[l]=tmp
    return l
def QuickSort(lst,l,r):
    if (r-l > 0):
        t=partition(lst,l,r)
        QuickSort(lst,l,t)
        QuickSort(lst,t+1,r)
        

lst=[1,3,5,2,4]
QuickSort(lst,0,len(lst))
print(lst)
        
    
