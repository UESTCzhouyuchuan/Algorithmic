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
*���ļ�   *
***********/
void ReadFile(FILE*fp,RecType R[],int *n); 
void SaveFile(FILE*fp,RecType R[],int n); 
/**********
*������� *
************/
void Disp(RecType R[],int n); 
/****************
*������         * 
*****************/
void HeapSort(RecType R[],int n);
/***************************
*����                       * 
****************************/
void QuickSort(RecType R[],int l,int r);
int  partition(RecType R[],int l,int r);
/******************************
*�������� nlogn,n             *
*******************************/
void Merge(RecType R[],int l,int mid,int r);
void MergeSortDC(RecType R[],int l,int r);
void MergeSort(RecType R[],int n); 
