// divide and conquer 
// 先確立該array第一個元素的正確位置，再將該元素的兩邊畫分成兩subarray繼續重複做
// avg:O(nlogn), best:O(nlogn) => 能精準切成兩半時 , worst:(O^2) => 切下去一邊一直都只剩一個(ex:already sorted array, and standard use first element)
// space:O(nlogn)
// not adaptive, not stable

void print(int* arr, int size){
    for(int i=0;i<size;++i) printf("%d ",arr[i]);
    printf("\n");
}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void quick_sort(int* arr, int size, int start, int end){
    if(start<0 || end>=size || start>=end) return; //終止條件：start或end超出陣列 / start,end已交會
    
    int i=start, j=end; //雙指針:i從最左開始，j從最右開始
    //將第一個元素定為標準，i找比標準大的項目，j找比標準小的項目
    //找到後，i和j的元素swap，重複做，直到i,j相遇，相遇後，標準(第一個元素)和和ij相遇位置元素swap
    while(i<j){
        while(arr[j]>=arr[start] && i<j) j--;
        while(arr[i]<=arr[start] && i<j) i++; //注意！j--,i++兩行不能互換位置，否則會影響到i,j相遇時的位置，導致swap出錯
        if(i<j) swap(&arr[i],&arr[j]);
    }
    swap(&arr[start],&arr[i]);
    
    //standard已擺到正確位置，剩下拆成左右部分繼續做
    quick_sort(arr, size, start, i-1);
    quick_sort(arr, size, i+1, end);
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
    
    quick_sort(arr, size, 0, size-1);
    
    printf("After sort: ");
    print(arr,size);
    
    free(arr);
    return 0;
}
