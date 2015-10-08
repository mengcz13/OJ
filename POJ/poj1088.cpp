#include <stdio.h>
#include <string.h>

#define MAX 100
//#define DEBUG

int memsearch(int array[][MAX], int mem[][MAX], int r, int c, int a, int b){
    if (mem[a][b]!=0)
        return mem[a][b];
    int max=1;
    if (a-1>=0&&a-1<r&&b>=0&&b<c&&array[a-1][b]<array[a][b]){
        int temp=memsearch(array,mem,r,c,a-1,b);
        if (1+temp>max)
            max=1+temp;
    }
    if (a+1>=0&&a+1<r&&b>=0&&b<c&&array[a+1][b]<array[a][b]){
        int temp=memsearch(array,mem,r,c,a+1,b);
        if (1+temp>max)
            max=1+temp;
    }
    if (a>=0&&a<r&&b+1>=0&&b+1<c&&array[a][b+1]<array[a][b]){
        int temp=memsearch(array,mem,r,c,a,b+1);
        if (1+temp>max)
            max=1+temp;
    }
    if (a>=0&&a<r&&b-1>=0&&b-1<c&&array[a][b-1]<array[a][b]){
        int temp=memsearch(array,mem,r,c,a,b-1);
        if (1+temp>max)
            max=1+temp;
    }
    mem[a][b]=max;
    return max;
}

int main(){
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int r=0, c=0;
    int array[MAX][MAX];
    int mem[MAX][MAX];
    memset(mem,0,sizeof(mem));
    scanf("%d%d",&r,&c);
    for (int i=0;i<r;++i)
        for (int j=0;j<c;++j){
            scanf("%d",&array[i][j]);
        }
    int maxlen=0;
    for (int i=0;i<r;++i)
        for (int j=0;j<c;++j){
            memsearch(array,mem,r,c,i,j);
            if (mem[i][j]>maxlen)
                maxlen=mem[i][j];
        }
    printf("%d",maxlen);
    return 0;
}