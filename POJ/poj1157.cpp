#include <stdio.h>

#define MAX 100+5
#define DEBUG

int main(){
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int ae[MAX][MAX];
    int value[MAX][MAX];
    int tempmax[MAX];
    int f=0, v=0;
    scanf("%d%d",&f,&v);
    for (int i=1;i<=f;++i){
        for (int j=1;j<=v;++j){
            scanf("%d",&value[i][j]);
        }
    }
    ae[1][0]=0;
    ae[1][1]=value[1][1];
    for (int j=2;j<=v;++j){
        if (value[1][j]>ae[1][j-1])
            ae[1][j]=value[1][j];
        else
            ae[1][j]=ae[1][j-1];
    }
    for (int i=2;i<=f;++i)
        for (int j=i;j<=v;++j){
            tempmax[j]=value[i][j];
            //j-i时间内计算从位置q到末端j的最大值
            for (int q=j-1;q>=i;q--){
                if (value[i][q]>tempmax[q+1])
                    tempmax[q]=value[i][q];
                else
                    tempmax[q]=tempmax[q+1];
            }
            //状态转移方程ae[i][j]=max{ae[i-1][k]+max{value[i][k+1..j]}}(i-1<=k<=j-1, i<=j<=v)
            //ae[i][j]表示前i种花插在前j个花瓶内所能得到的最大值, 注意每种花都不能不插, 所以j>=i
            int cum=ae[i-1][i-1]+tempmax[i], temp=0;
            for (int k=i;k<j;++k){
                temp=ae[i-1][k]+tempmax[k+1];
                if (temp>cum)
                    cum=temp;
            }
            ae[i][j]=cum;
            #ifdef DEBUG
            printf("%d %d %d\n",i,j,ae[i][j]);
            #endif
        }
    printf("%d",ae[f][v]);
}