// insertion sort改良版，可降低insertion插入時需同時動到過多元素的問題
// 以間隔的方式做數字比對，每輪的間隔是上一輪的一半，直到1排序完成，同間隔為一組，進行insertion sort
// time complexity -- avg:O(nlogn), best:O(nlogn), worst:(O^2)       (actually nore than O(nlogn), about O(n^3/2)
// space complexity -- O(1)
// adaptive, not stable

#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int size){
    for(int i=0;i<size;++i) printf("%d ",arr[i]);
    printf("\n");
}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void shell_sort(int* arr, int size){
    for(int gap=size/2;gap>0;gap/=2){               //要做幾輪
        for(int start=0;start<gap;++start){         //一輪有幾組(j為start index)
            int cur=start;                          //以同間隔為同一組，前後比對大小(k為目前index)
            while(cur>=0 && cur+gap<size){
                if(arr[cur]>arr[cur+gap]){
                    swap(&arr[cur], &arr[cur+gap]);
                    if(cur>=gap){                   //往回找上一對的元素
                        cur-=gap;
                        continue;
                    }
                }
                cur+=gap;                           //找下一對
            }
        }
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
    
    shell_sort(arr, size);
    
    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
