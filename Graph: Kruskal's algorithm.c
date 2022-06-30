// Kruskal's algorithm => 找最小生成樹(MST)
// time complexity -- O(n^2), if heap is used => O(nlogn)
// 不斷選取最短edge，一旦會變成loop就跳過 (application of greedy method)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 7
#define E 9
#define MAX 32767

void Union(int set[V+1], int v1, int v2){
    if(set[v1]<set[v2]){
        set[v1]+=set[v2];
        set[v2]=v1;
    }
    else{
        set[v2]+=set[v1];
        set[v1]=v2;
    }
}

int Find(int set[V+1], int v){
    int parent=v;
    
    while(set[parent]>0){   // find v's its parent
        parent=set[parent];
    }
    
//    while(v!=parent){   // v=>set[v], set[v]=>parent
//        int temp=set[v];
//        set[v]=parent;
//        v=temp;
//    }
    return parent;
}

void Kruskal_MST(int list[3][E]){
    int result[V-1][2]={0};     // record all finding edges
    bool isUsed[E]={0};         // record the edges is used or not
    int set[V+1];               // record [parent vertice index] or [all vertices num this parent have in negative]                             // set[0] is useless
    memset(set,-1,sizeof(int)*(V+1));

    //find all edges
    int i=0;
    while(i<V-1){
        int min=MAX, v1=0, v2=0, edge=0;
        
        //find minimum cost edge
        for(int j=0;j<E;++j){
            if(isUsed[j]==false && list[2][j]<min){
                v1=list[0][j];
                v2=list[1][j];
                min=list[2][j];
                edge=j;
            }
        }
        isUsed[edge]=true;
        
        //check if the edge forms a cycle or not
        if(Find(set, v1)!=Find(set, v2)){
            result[i][0]=v1;
            result[i][1]=v2;
            Union(set, Find(set, v1), Find(set, v2));
            i++;
        }
    }

    //print
    printf("Use Kruskal's algothrim to find MST\n");
    printf("edges:\n");
    int sum=0;
    for(int i=0;i<V-1;++i){
        int v1=result[i][0], v2=result[i][1];
        for(int j=0;j<E;++j){
            if(list[0][j]==v1 && list[1][j]==v2){
                printf("[%d] --- [%d]: %d\n",v1,v2,list[2][j]);
                sum+=list[2][j];
                break;
            }
        }
    }
    printf("sum: %d",sum);
}

int main(){
    int list[3][E] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                      { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                      {25, 5, 12, 10, 8, 16, 14, 20, 18}};
    
    Kruskal_MST(list);
    printf("\n");
    return 0;
}

//            [1]
//           /   \
//        5 /     \ 25
//         /       \
//       [6]       [2]
//        |      /14|
//     20 |   [7]   | 12
//        |18/ |    |
//       [5]   |   [3]
//         \   |14 /
//       16 \  |  / 8
//           \ | /
//            [4]
