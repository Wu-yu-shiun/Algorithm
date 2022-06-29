//header: Linked-list ADT

#ifndef Linked_list_h
#define Linked_list_h

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


void sortedInsert(struct Node** p, int num){
    struct Node* last=NULL, * iter=*p;
    
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=num;
    temp->next=NULL;

    if(*p==NULL) *p=temp; //case1:空linked list
    else{
        while(iter && iter->data<num){
            last=iter;
            iter=iter->next;
        }
        if(iter==*p){ //case2:插入位置在index 0
            temp->next=*p;
            *p=temp;
        }
        else{ //case3:其他插入位置
            temp->next=last->next;
            last->next=temp;
        }
    }
}

struct Node** search(struct Node** p, int i, int key){
    while(p[i]){
        if(p[i]->data==key){
            printf("find %d!\n",key);
            return p;
        }
        p[i]=p[i]->next;
    }
    printf("cannot find %d!\n",key);
    return NULL;
}

#endif /* Linked_list_h */

//------------------------------------------------------------

//chaining => 用hash function output的值做分類，並將使用同格的元素以排序的方式用linked-list串接

#include <stdio.h>
#include <stdlib.h>
#include "Linked-list.h"

void print(struct Node** p, int size){
    printf("--------chain--------\n");
    for(int i=0;i<size;++i){
        struct Node* iter=p[i];
        printf("chain %d: ",i);
        while(iter){
            printf("%d ",iter->data);
            iter=iter->next;
        }
        printf("\n");
    }
    printf("--------chain--------\n");
}

int hash_function(int key, int size){
    return key%size;
}

void insert(struct Node** p, int size, int key){
    int hashnum=hash_function(key, size);
    sortedInsert(&p[hashnum], key); //not allowed negative number
}

int main(){
    int size;
    printf("size of array: ");
    scanf("%d",&size);
    printf("elements of array: ");
    int* arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;++i) scanf("%d",&arr[i]);
    
    // construct hash table
    struct Node* chainArray[size];
    //struct Node** chainArray=(struct Node**)malloc(sizeof(struct Node*)*size);
    for(int i=0;i<size;++i) chainArray[i]=NULL; //important!!!
    for(int i=0;i<size;++i) insert(chainArray, size, arr[i]);
    
   
    print(chainArray, size);  //print chain

    // search
    search(chainArray, hash_function(21, size), 21);
    search(chainArray, hash_function(33, size), 33);
    search(chainArray, hash_function(7, size), 7);
    
    
    free(arr);
    return 0;
}



