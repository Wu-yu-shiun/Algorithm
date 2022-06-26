// divide and conquer, merge two sorted array to one sorted array
// avg:O(nlogn) best:O(nlogn) worst:O(nlogn)
// space:O(n)  => from extra array:O(n) + recursion stack:O(logn) = O(n)
// not adaptive, stable

#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int size){
    for(int i=0;i<size;++i) printf("%d ",arr[i]);
    printf("\n");
}

void merge(int* arr, int start, int mid, int end){ //if start at 0 and end at 7 => mid at 3
    int i=start, j=mid+1, k=0, temp[end-start+1];  //i for first array, j for second array, k for merge array
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=end) temp[k++]=arr[j++];
    
    for(int i=start;i<=end;++i) arr[i]=temp[i-start];
}

void merge_sort_iterative(int* arr, int size){
    for(int i=2;i<=size;i*=2){                              //要merge幾輪 (i為merge後，每個array的size大小)
        for(int j=0;j<size/i;++j){                          //每輪要merge幾組
            int start=i*j, end=start+i-1, mid=(start+end)/2;
            merge(arr,start,mid,end);
            //將可能沒merge到的部分和最後一組已經merge好的array再做merge
            if((j+1)==size/i && i*(j+1)<size) merge(arr,start,end,size-1);
        }
    }
}

void merge_sort_recursive(int* arr, int start, int end){
    if(start==end) return; //邊界：剩一個元素(已sort好)
    
    int mid=(start+end)/2; //先不斷切兩半 直到最深層
    merge_sort_recursive(arr, start, mid);
    merge_sort_recursive(arr, mid+1, end);
    merge(arr, start, mid, end);   //在returning phase做merge  (merge at post-order)
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
    
    //merge_sort_iterative(arr,size);
    merge_sort_recursive(arr, 0, size-1);
    
    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
