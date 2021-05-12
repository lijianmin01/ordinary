#include<stdio.h>

/*交换两个元素的位置*/
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

//冒泡排序v 从后往前
void BubbleSort(int A[],int n){
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        bool flag = false;
        for ( j = n-1; j > i ; j--)
        {
            if (A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                flag=true;
            }
        }
        if(flag==false){
            return;
        }   
    }
}

// 冒泡排序v 从前往后
void BubbleSort2(int A[],int n){
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        bool flag = false;
        for ( j = 0; j < n-i-1; j++)
        {
            if (A[j]>A[j+1]){
                swap(A[j+1],A[j]);
                flag=true;
            }
        }
        if(flag==false){
            return;
        }  
    }   
}

int main(){
    int i,j,n;
    scanf("%d",&n);
    int nums[1000];
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&nums[i]);
    }
    BubbleSort2(nums,n);
    for ( i = 0; i < n; i++)
    {
        printf("%d ",nums[i]);
    }
    return 0;
}