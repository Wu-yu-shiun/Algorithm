// Prim's algorithm => 找最小生成樹(MST)
// time complexity -- O(n^2), if heap is used => O(nlogn)
// 先選出一個最短edge，再由此延伸出其他的edge (application of greedy method)

#include <stdio.h>
#include <stdlib.h>

#define V 7
#define MAX 32767

void print(int route[V+1], int result[V-1][2]){
    printf("\nroute: ");
    for(int i=1;i<V+1;++i) printf("%d ",route[i]);
    printf("\nresult:");
    for(int i=0;i<V-1;++i) printf("%d-%d ",result[i][0],result[i][1]);
    printf("\n");
}

void Prim_MST(int matrix[V+1][V+1]){
    int route[V+1];         // INT_MAX:haven't find route, 0:find correct route, 1~7: best route(route[0] is useless)
    int result[V-1][2]={0}; // only V-1 result to store [start]->[end]
    int min=MAX, v1=0, v2=0;

    //init first route
    for(int i=1;i<V+1;++i){
        route[i]=MAX;
        for(int j=i;j<V+1;++j){
            if(matrix[i][j]<min){
                min=matrix[i][j];
                v1=i;
                v2=j;
            }
        }
    }
    result[0][0]=v1;
    result[0][1]=v2;
    route[v1]=route[v2]=0;
    for(int i=1;i<V+1;++i){
        if(route[i]!=0){
            if(matrix[i][v1]>matrix[i][v2]) route[i]=v2;
            else route[i]=v1;
        }
    }
    //print(route, result);

    //other route
    for(int i=1;i<V-1;++i){
        min=MAX;
        for(int j=1;j<V+1;++j){
            if(route[j]!=0 && matrix[j][route[j]]<min){
                min=matrix[j][route[j]];
                v1=j;
                v2=route[v1];
            }
        }
        result[i][0]=v1; //new vertice
        result[i][1]=v2;  //route[start]==start, old vertice
        route[v1]=0;
        for(int j=1;j<V+1;++j){
            if(route[j]!=0 && matrix[j][v1]<matrix[j][route[j]]) route[j]=v1;
        }
        //print(route, result);
    }

    //print
    printf("Use Prim's algothrim to find MST\n");
    printf("edges:\n");
    int sum=0;
    for(int i=0;i<V-1;++i){
        int v1=result[i][0], v2=result[i][1];
        printf("[%d] --- [%d]: %d\n",v1,v2,list[v1][v2]);
        sum+=list[v1][v2];
    }
    printf("sum: %d",sum);
}

int main(){
    int _=MAX;
    int matrix[V+1][V+1]={{_, _, _, _, _, _, _, _},
                          {_, _,25, _, _, _, 5, _},
                          {_,25, _,12, _, _, _,10},
                          {_, _,12, _, 8, _, _, _},
                          {_, _, _, 8, _,16, _, 14},
                          {_, _, _, _,16, _,20, 18},
                          {_, 5, _, _, _,20, _, _},
                          {_, _,10, _,14,18, _, _}};
    
   
    Prim_MST(matrix);
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
