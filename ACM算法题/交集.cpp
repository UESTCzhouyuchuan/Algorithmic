/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <bits/stdc++.h>
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int n=nums1Size<nums2Size?nums1Size:nums2Size;
    returnSize=(int*)malloc(sizeof(int)*n);
    int k=0,t,q;
    int i,j;
    for (i=0;i<nums1Size;i++)
    {
        t=0;
        q=1;
        for (j=0;j<k;j++)
        {
            if (nums1[i]==returnSize[j])
                q++;
        }
        for(j=0;j<nums2Size;j++)
        {
           
            if (nums1[i]==nums2[j])
            {
                t++;
            }
        }
        if (t>=q)
            returnSize[k++]=nums1[i];
    }
    
    return returnSize;
}
int main(void)
{
    int a[4]={1,2,2,4},b[4]={2,2,1,4};
    int*c;
    int *d=intersect(a,4,b,4,c);
    printf("%d %d %d %d",d[0],d[1],d[2],d[3]);
    return 0;
}


