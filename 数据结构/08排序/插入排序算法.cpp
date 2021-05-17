#include<stdio.h>

// 直接插入排序
void InsertSort(int A[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        if(A[i]<A[i-1]){
            temp = A[i];
            for(j=i-1;j>=0&&A[j]>temp;j--){
                A[j+1]=A[j];
            }
            A[j+1]=temp;
        }
    }
}


/* 有哨兵的直接插入排序（0的位置空出来）
    n 数组长度
*/
void InsertSort2(int A[],int n){
    int i,j;
    for ( i = 2; i < n; i++)
    {
        if(A[i]<A[i-1]){
            A[0]=A[i];
            for(j=i-1;j>=1 && A[j]>A[0];j--){
                A[j+1]=A[j];
            }
            A[j+1]=A[0];
        }
    } 
}

/* 优化——折半插入排序
    有哨兵的
*/
void InsertSort3(int A[],int n){
    int i,j,low,mid,high;
    for(i=2;i<n;i++){
        if(A[i]<A[i-1]){
            A[0]=A[i];
            low = 1;
            high = i-1;
            while(high>=low){
                mid = (low+high)/2;
                if(A[mid]>A[0]){
                    high=mid-1;
                }else{
                    low = mid+1;
                }
            }
            for(j=i-1;j>=high+1;j--){
                A[j+1]=A[j];
            }
            A[high+1]=A[0];
        }
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int nums[1000];
    int i,j,temp;

    for(i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }

    InsertSort3(nums,n);
    for ( i = 1; i < n; i++)
    {
        printf("%d ",nums[i]);
    }
    
    return 0;
}