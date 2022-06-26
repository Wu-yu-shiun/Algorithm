// heap data structure
// create max heap, and get largest number by deleting root node one by one
// time complexity -- avg:O(nlogn) best:O(nlogn) worst:O(nlogn)
// space complexity -- O(1)
// not adaptive, not stable

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

void heapify(int* arr,int size, int root){
    //heapify a subtree rooted with node index (將arr[index]不斷往下換到適當位置)
    while(true){
        int left=2*root+1, right=2*root+2, larger;

        if(left>=size) break; //no left and right child
        else if(right==size) larger=left; //only exist left child
        else larger=arr[left]>arr[right] ? left : right; //exist left and right child

        if(arr[larger]>arr[root]){
            swap(&arr[root], &arr[larger]);
            root=larger;
        }
        else break;
    }
}

void heap_sort(int* arr, int size){
    //heapify backwards (leaf nodes don't need to heapify)
    for(int i=size/2-1;i>=0;--i){
        heapify(arr, size, i);
    }
    
    //delete heap one by one (swap root and heap tail), then heapify root again
    for(int i=size-1;i>0;--i){
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
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
    
    heap_sort(arr,size);
    
    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
