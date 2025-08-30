#include <stdio.h>
//有序数组的二分查找
int main(void) {
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int k = 0;
    scanf("%d",&k);
    int sz=sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    int right=sz-1;
    int mid=(left+right)/2;

    while (left<=right){
    if (arr[mid]<k) {
        left=mid+1;
    }
    else if (arr[mid]>k) {
        right=mid-1;
    }
    else {
        printf("找到了，下表为%d",mid);
        break;
    }
}
    if (left>=right) {
        printf("找不到");
    }
}