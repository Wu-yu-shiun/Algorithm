// Dijkstra algorithm => 找最短路徑樹(SPT)
// time complexity -- O(n^2) or O(V^2), if heap is used => O(nlogn) or O(ElogV)
// 每個節點存有從起點到這裡的最短路徑值，剛開始除了起點的最短路徑值為0，其他節點都是無限大
// 之後不斷挑選出目前最短路徑值最小的節點，找出它連出去的路並更新其他節點的最短路徑值，挑過的節點不能再挑(application of greedy method)

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 10
#define MAX 32767

int min(int a, int b){
    return a<b ? a : b;
}

void Dijkstra_SPT(int list[3][E],int start){
    
    int result[V+1];             // record minimum range of every edge, result[0] is useless
    for(int i=1;i<V+1;++i) result[i]= (i==start) ? 0 : MAX;
    bool isUsed[V+1]={0};          // record the edges is used or not, isUsed[0] is useless
    
    //for(int i=1;i<V+1;++i) printf("%d ",result[i]);
    printf("\n");
    int index=0;
    while(index<V-1){
        // select minimum edge
        int min=MAX, selectEdge=0;
        for(int i=1;i<V+1;++i){
            if(result[i]<min && isUsed[i]==false){
                selectEdge=i;
                min=result[i];
            }
        }
        isUsed[selectEdge]=true;
        //printf("select edge: %d\n",selectEdge);
        
        //update all result
        for(int i=0;i<E;++i){
            if(list[0][i]==selectEdge){
                int modifyEdge=list[1][i], newPath=result[selectEdge]+list[2][i];
                //printf("modifyEdge: %d, newPath: %d, oldPath: %d\n",modifyEdge,newPath,result[modifyEdge]);
                if(newPath<result[modifyEdge]) result[modifyEdge]=newPath;
            }
        }

        index++;
    }
    
    //print result
    printf("Use Dijkstra algothrim to find SPT:\n");
    for(int i=1;i<=V;++i){
        if(result[i]==MAX) printf("From vertice%d to vertice%d minimum distance: MAX\n",start,i);
        else printf("From vertice%d to vertice%d minimum distance: %d\n",start,i,result[i]);
    }
    
}

int main(){
    int list[3][E] = {{ 1,  1,  1,  2,  2,  3,  4,  5,  5,  6},
                      { 2,  4,  3,  3,  4,  5,  5,  2,  3,  5},
                      {50, 10, 45, 10, 15, 30, 15, 20, 35,  3}};
    
    Dijkstra_SPT(list,1);
    printf("\n");
    return 0;
}

//                 45
//          ↗ ------------- ↘
//        ↗                   ↘
//      ↗    50           10    ↘
//    [1] -------> [2] -------> [3]
//     |          ↙ |          ↗ ↙
//     |        ↙   |        ↗ ↙
//  10 |   15 ↙   20|   35 ↗ ↙ 30
//     |    ↙       |    ↗ ↙
//     ↓  ↙         |  ↗ ↙
//    [4] -------> [5] <------- [6]
//           15            3
