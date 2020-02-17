#include <stdio.h>
double findMedianSortedArrays(int*nums1,int nums1Size,int*nums2,int nums2Size);
int main(void){
	
	int a[2]={1,1},b[2]={1,2};
	printf("%f\n",findMedianSortedArrays(a,2,b,2));
	return 0;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i=0,j=0,k=0;
    double z1,z2;
    while (i<nums1Size&&j<nums2Size)
    {
        if (nums1[i]<nums2[j])
        {
            
            if (k==(nums1Size+nums2Size-1)/2)
                z1=nums1[i];
            if (k==(nums1Size+nums2Size)/2){
                z2=nums1[i];
                break;
            }
            i++;
            k++;
        }
        else
        {
            if (k==(nums1Size+nums2Size-1)/2)
                z1=nums2[j];
            if (k==(nums1Size+nums2Size)/2){
                z2=nums2[j];
                break;
            }
            j++;
            k++;
        }
    }
    while (i<nums1Size)
    {
        if (k==(nums1Size+nums2Size-1)/2)
                z1=nums1[i];
            if (k==(nums1Size+nums2Size)/2){
                z2=nums1[i];
                break;
            }
        i++;
        k++;
    }
    while (j<nums2Size)
    {
        if (k==(nums1Size+nums2Size-1)/2)
                z1=nums2[j];
            if (k==(nums1Size+nums2Size)/2){
                z2=nums2[j];
                break;
            }
            j++;
            k++;
    }
    return (z1+z2)/2;
}
