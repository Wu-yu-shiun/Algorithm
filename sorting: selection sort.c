// select the smallest element from original array to sorted array one by one
// time complexity -- avg:O(n^2) best:O(n^2) worst:O(n^2)
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

void selection_sort(int* arr, int size){
    for(int i=0;i<size-1;++i){          //找到sort array的第i項該放誰
        int smallest=i;
        for(int j=i+1;j<size;++j){
            if(arr[j]<arr[smallest]) smallest=j;
        }
        swap(&arr[i], &arr[smallest]);
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
    
    selection_sort(arr,size);
    
    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
