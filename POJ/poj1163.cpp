#include <stdio.h>
#define MAX 100

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n=0;
    int data[MAX][MAX];
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        for (int j=0;j<i+1;++j)
            scanf("%d",&data[i][j]);
    int dp[MAX];
    for (int i=0;i<n;++i)
        dp[i]=data[n-1][i];
    for (int i=n-2;i>=0;--i){
        for (int j=0;j<i+1;++j){
            dp[j]=data[i][j]+((dp[j]>dp[j+1])?dp[j]:dp[j+1]);
        }
    }
    printf("%d",dp[0]);
    return 0;
}