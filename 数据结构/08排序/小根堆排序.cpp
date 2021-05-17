#include<stdio.h>

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

/*以k为根的子树，调整为小根堆*/
void HeadAdjustMin(int A[],int k,int len){
    int i,j;
    A[0]=A[k];
    for ( i = 2*k; i <= len; i*=2)
    {
        if(i<len&&A[i]>A[i+1]){
            i++;
        }
        if(A[0]<=A[i]){
            break;
        }else{
            A[k]=A[i];
            k = i;
        }
    }
    A[k]=A[0];
}

// 建立小根堆
void BuildMinHeap(int A[],int len){
    int i;
    for ( i = len/2; i >=1 ; i--)
    {
        HeadAdjustMin(A,i,len);
    }
    
}

// 利用小根堆进行排序
void HeapSort(int A[],int len){
    BuildMinHeap(A,len);
    int i;
    for(i=len;i>1;i--){
        swap(A[1],A[i]);
        HeadAdjustMin(A,1,i-1);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int nums[1000];
    int i,j;
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&nums[i+1]);
    }
    HeapSort(nums,n);
    for ( i = 0; i < n; i++)
    {
        printf("%d ",nums[i+1]);
    }
    
    return 0;
}