// hash table
// time complexity -- avg:O(n+k) best:O(n+k) worst:O(n+k)
// space complexity -- O(k)  k depends on the element max to min range (hash table size)
// not adaptive, not stable

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int* arr, int size){
    for(int i=0;i<size;++i) printf("%d ",arr[i]);
    printf("\n");
}

void count_sort(int* arr, int size){
    //get hash size
    int max=arr[0], min=arr[0];
    for(int i=1;i<size;++i){
        if(arr[i]>max) max=arr[i];
        else if(arr[i]<min) min=arr[i];
    }

    //fill in hash table
    int tableSize=max-min+1, hash[tableSize]; // min~max 平移(-min)至 0~max-min
    memset(hash, 0, sizeof(int)*tableSize);
    for(int i=0;i<size;++i) hash[arr[i]-min]++; // min~max 平移(-min)至 0~max-min

    //read hash table
    int i=0,j=0; //i for hash table, j for array
    while(i<tableSize){
        if(hash[i]>0){
            arr[j++]=i+min; // 0~max-min 平移(+min)回來 min~max
            hash[i]--;
        }
        else i++;
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
    
    count_sort(arr,size);

    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
