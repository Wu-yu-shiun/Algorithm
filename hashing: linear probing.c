//linear probing => 用hash function output的值做分類，該格已有元素佔用時，就往下找可用的空間存放

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash_function(int key, int size){
    int temp=key%size;
    return temp>=0 ? temp : -temp;
}

int probing(int* hash, int hashsize, int hashnum){
    int offset=0;
    while(hash[(hashnum+offset)%hashsize]!=-1) offset++;
    return (hashnum+offset)%hashsize;
}

void insert(int* hash, int hashsize, int key){
    int hashnum=hash_function(key, hashsize);
    if(hash[hashnum]!=-1) hashnum=probing(hash, hashsize, hashnum);
    hash[hashnum]=key;
}

void search(int* hash, int size, int key){
    int hashnum=hash_function(key, size);
    int offset=0;
    while(true){
        int temp=(hashnum+offset)%size;
        if(hash[temp]==key || hash[temp]==-1) break;
        offset++;
    }
    if(hash[(hashnum+offset)%size]==-1) printf("cannot find %d!\n",key);
    else printf("find %d!\n",key);
}

int main(){
    int size;
    printf("size of array: ");
    scanf("%d",&size);
    printf("elements of array: ");
    int* arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;++i) scanf("%d",&arr[i]);
    
    // construct hash table
    double lambda=0.5;
    int hashsize=size/lambda;
    int* hash=(int*)malloc(sizeof(int)*hashsize);
    
    memset(hash, -1, sizeof(int)*hashsize);
    for(int i=0;i<size;++i) insert(hash, hashsize, arr[i]);  //only not allowed -1
   
    // print hash table
    printf("--------hash table--------\n");
    for(int i=0;i<hashsize;++i) printf("table%d: %d\n",i,hash[i]);
    printf("--------hash table--------\n");
    
    // search
    search(hash, hashsize, 0);
    search(hash, hashsize, 3);
    search(hash, hashsize, 14);
    
    free(arr);
    return 0;
}
