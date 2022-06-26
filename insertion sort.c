// insert the element to sorted array(linked-list) one by one from original array(linked-list)
// time complexity -- avg:O(n^2) best:O(n) worst:O(n^2)
// space complexity -- O(1)
// adaptive, stable

#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int size){
    for(int i=0;i<size;++i) printf("%d ",arr[i]);
    printf("\n");
}

void insertion_sort(int* arr, int size){
    for(int i=1;i<size;++i){          //此次要換好原來陣列的第i項
        int temp=arr[i], j=i-1;       //用j從已排序好陣列的最後面檢查回來
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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
    
    insertion_sort(arr,size);
    
    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
