// sort one by one (brute force?)
// avg:O(n^2) best:O(n) worst:O(n^2)
// adaptive stable

#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int size){
    for(int i=0;i<size;++i) printf("%d ",arr[i]);
    printf("\n");
}

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int* arr, int size){
    bool isSort=true;                   //做加速
    for(int i=0;i<size-1;++i){          //此次要換好第i項
        for(int j=size-1;j>i;--j){      //從最後面往前換
            if(arr[j-1]>arr[j]) swap(&arr[j-1],&arr[j]);
            isSort=false;
        }
        if(isSort) break;               //確認j迴圈是否經過交換，若無，代表已經sort好
    }
}

int main(){
    int size;
    printf("size of array: ");
    scanf("%d",&size);
    printf("elements of array: ");
    int* arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;++i) scanf("%d",&arr[i]);
    
    printf("Before sort: ");
    print(arr,size);
    
    bubble_sort(arr,size);
    
    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
