// KMP algorithm => 從字串中找取子字串
// time complexity -- O(n+m) where n=size of string, m=size of substring (if we you brute froce, O(n*m))
// 用LPS(失敗函數)在substring的每個字元標記上該退回的特定索引值，可避免暴力法在兩字串配對失敗時，重複檢查到string同字元的過程
// i,j分別在string,substring中做對比，配對失敗後，i可繼續往前，j則退到該格LPS標記的數字index上

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMP_search(char* str1, char* str2){
    int n, m,result=0;
    n=(int)strlen(str1);
    m=(int)strlen(str2);
    
    //1. create LPS array (longest prefix suffix Array) of the substring
    int lps[m], len=0;  //len：到目前為止重複到的部分
    lps[0]=0;
    for(int i=1;i<m;++i){
        while(str2[i]!=str2[len] && len>0) len=lps[len-1];
        if(str2[i]==str2[len]) len++;
        lps[i]=len;
    }
    
    printf("lps array: ");
    for(int i=0;i<m;++i) printf("%d",lps[i]);
    printf("\n");
    
    //2. start to search
    for(int i=0,j=0;i<n;i++)
    {
        if(str1[i]==str2[j]){
            j++;
            if(j==m){
                printf("Found a substring starting at index %d.\n",i-j+1);
                result++;
            }
        }
        else if(j>0){
            j=lps[j-1];
            i--;
        }
    }
    
    return result;
}

int main(){
    char str1[100], str2[100];
    printf("string:");
    scanf("%s",str1);
    printf("substring:");
    scanf("%s",str2);
    
    printf("There are %d substrings in the string.\n",KMP_search(str1,str2));
    return 0;
}

// lps array (過了index為x的字元後，若在index為x+1配對失敗時，可以找lps[x]作為下輪str2要開始檢查的對象)
// ex1  abcdabeabf   ex2  aacaaaac  ex3  bababbababb  ex4 aabcadaabe  ex5  aaaabaacd
//      0000120120        01012223       00123123456      0100101230       012301200

// test case
// ex1  str1=abcdabgabcdabckaabbabcdabck                      str2=abcdabck     ans=2 at index 7,19
// ex2  str1=afsdajskfjjareklasfjarereralkfjarealkjrea;;iot   str2=re           ans=5 at index 12,21,23,32,28
// ex3  str1=ababdabacdababcabab                              str2=ababcabab    ans=1 at index 10
// ex4  str1=ABCABAABCABAC                                    str2=CAB          ans=2 at index 2,8
