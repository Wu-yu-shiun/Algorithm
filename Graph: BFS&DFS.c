//header: Queue ADT

#include <stdio.h>
#include <stdlib.h>

#ifndef Queue_h
#define Queue_h

struct Node{
    int data;
    struct Node* next;
}* front=NULL,* rear=NULL;


void enqueue(int num){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=num;
    temp->next=NULL;
    if(front==NULL) front=rear=temp;
    else{
        rear->next=temp;
        rear=temp;
    }
}

int dequeue(){
    if(front==NULL){
        printf("Queue is empty!\n");
        return NULL;
    }
    else{
        int num=front->data;
        struct Node* temp=front;
        front=front->next;
        free(temp);
        return num;
    }
}

void printQueue(){
    struct Node* iter=front;
    printf("Queue: ");
    while(iter && iter!=rear){
        printf("%d ",iter->data);
        iter=iter->next;
    };
    printf("%d\n",rear->data);
}

bool isEmptyQueue(){
    return front==NULL;
}

#endif /* Queue_h */

//------------------------------------------------------------

// BFS & DFS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

void BFS(int** matrix, int size, int start){
    bool isVisited[size];
    memset(isVisited, false, sizeof(bool)*size);
    
    //first node
    printf("%d ",start);
    isVisited[start]=true;
    enqueue(start);
    //printQueue();
    
    while(!isEmptyQueue()){
        int num=dequeue();
        for(int i=1;i<size;++i){
            if(matrix[num][i]==1 && isVisited[i]==false){
                printf("%d ",i);
                isVisited[i]=true;
                enqueue(i);
                //printQueue();
            }
        }
    }
}

void DFS(int** matrix, int size, int num){
    static bool isVisited[100]={false}; // use static because of recursion
    
    if(isVisited[num]==false){
        printf("%d ",num);
        isVisited[num]=true;
        for(int i=1;i<size;++i){
            if(matrix[num][i]==1 && isVisited[i]==false) DFS(matrix, size, i);
        }
    }
}

int main(){
    int size;
    printf("size of matrix: ");
    scanf("%d",&size);
    printf("elements of matrix: ");
    int** adajacent_matrix=(int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;++i) adajacent_matrix[i]=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            scanf("%d",&adajacent_matrix[i][j]);
    
    printf("BFS: ");
    BFS(adajacent_matrix, 8, 1);
    printf("\n");
    
    printf("DFS: ");
    DFS(adajacent_matrix, 8, 1);
    printf("\n");
    
    return 0;
}


// test case
// size:8
// 0 0 0 0 0 0 0 0  0 0 1 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 1 1 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0

// matrix (第一排跟第一列無意義)
// 0 0 0 0 0 0 0 0
// 0 0 1 0 0 0 0 1   => 1 - 2,7
// 0 1 0 0 1 0 0 0   => 2 - 1,4
// 0 0 0 0 0 1 0 0   => 3 - 5
// 0 0 1 0 0 1 1 1   => 4 - 2,5,6,7
// 0 0 0 1 1 0 0 0   => 5 - 3,4
// 0 0 0 0 1 0 0 0   => 6 - 4
// 0 1 0 0 1 0 0 0   => 7 - 1,4

// graph
//     1
//    / \
//   2   7
//    \ /
//     4
//    / \
//   5   6
//  /
// 3
