#include<stdio.h>

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

/*将以k为跟的子树调整为大根堆*/
void HeadAdjust(int A[],int k,int len){
    int i,j;
    /*A[0] 暂存根节点*/
    A[0]=A[k];
    for(i=2*k;i<=len;i*=2){
        if(i<len&&A[i]<A[i+1]){
            i++;
        }
        if(A[0]>=A[i]){
            break;
        }else{
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=A[0];
}
/*建立大根堆*/
void BuildMaxHeap(int A[],int len){
    int i;
    for ( i = len/2; i >0; i--)
    {
        HeadAdjust(A,i,len);
    }
    
}

void HeapSort(int A[],int len){
    BuildMaxHeap(A,len);
    int i;
    for ( i = len; i > 1; i--)
    {
        swap(A[i],A[1]);
        HeadAdjust(A,1,i-1);
    }
    
}


int main(void){
    int n;
    scanf("%d",&n);
    int nums[1000];
    int i,j;
    for ( i = 0; i < n; i++)
    {
        scanf("%d",nums[i+1]);
    }
    HeapSort(nums,n);
    for ( i = 0; i < n; i++)
    {
        printf("%d ",nums[i+1]);
    }
    
    return 0;
}