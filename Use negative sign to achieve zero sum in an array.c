#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool check(int* nums,int numsSize,int target){
    printf("now length: %d\n",numsSize);
    bool dp[numsSize+1][target+1];
    for(int i=0;i<numsSize+1;++i){
        for(int j=0;j<target+1;++j){
            if(j==0) dp[i][j]=true;
            else if(i==0) dp[i][j]=false;
            else dp[i][j]=(j<nums[i-1])?dp[i-1][j]:(dp[i-1][j]||dp[i-1][j-nums[i-1]]);
        }
    }
    return dp[numsSize][target];
}

//動態規劃優化版(space:O(n))
// bool check(int* nums,int numsSize,int target){
//     bool dp[target+1];
//     memset(dp,false,sizeof(bool)*(target+1));
//     dp[0]=true;
//     for(int i=0;i<numsSize;++i){
//         for(int j=target;j>=nums[i];--j)
//             dp[j]=dp[j]||dp[j-nums[i]];
//     }
//     return dp[target];
// }

void revise(int *nums,int numsSize){
    nums=(int*)realloc(nums, sizeof(int)*(numsSize+1));
    numsSize++;
    nums[numsSize-1]=1;
}

int main(){

    //input
    int numsSize;
    cout<<"size: ";
    cin>>numsSize;
    int* nums=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;++i){
        cin>>nums[i];
    }
    
    int result=0;
    while(true){
        
        int sum=0,target;
        for(int i=0;i<numsSize;++i){
            sum+=nums[i];
        }
        target=sum/2;
        
        if(sum%2!=0){
            revise(nums,numsSize);
            numsSize++;
            result++;
            continue;
        }
        
        if(!check(nums,numsSize,target)){
            revise(nums,numsSize);
            numsSize++;
            result++;
            continue;
        }

        break;
    }
    
    printf("Ans: %d\n",result);
    return 0;
}
