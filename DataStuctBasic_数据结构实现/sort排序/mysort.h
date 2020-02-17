#pragma once
#define Info char
#define MAX 100
#include <bits/stdc++.h>
typedef struct
{
	Info data;
	int key;
}RecType;

/**********
*读文件   *
***********/
void ReadFile(FILE*fp,RecType R[],int *n); 
void SaveFile(FILE*fp,RecType R[],int n); 
/**********
*输出数组 *
************/
void Disp(RecType R[],int n); 
/****************
*堆排序         * 
*****************/
void HeapSort(RecType R[],int n);
/***************************
*快排                       * 
****************************/
void QuickSort(RecType R[],int l,int r);
int  partition(RecType R[],int l,int r);
/******************************
*并归排序 nlogn,n             *
*******************************/
void Merge(RecType R[],int l,int mid,int r);
void MergeSortDC(RecType R[],int l,int r);
void MergeSort(RecType R[],int n); 
