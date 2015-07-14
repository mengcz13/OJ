#include <stdio.h>

#define N 1000
#define V 1000

int ValL[N+1];
int VolL[N+1];
int PT[V+1][N+1];

int max(int a, int b){
	return (a>b)?a:b;
}

int main(){
	int t=0, n=0, v=0;
	scanf("%d",&t);
	for (int cas=0;cas<t;++cas){
		scanf("%d%d",&n,&v);
		for (int i=1;i<=n;++i)
			scanf("%d",&ValL[i]);
		for (int i=1;i<=n;++i)
			scanf("%d",&VolL[i]);
		for (int i=0;i<=v;++i)
			PT[i][0]=0;
		for (int i=0;i<=v;++i)
			for (int j=1;j<=n;++j){
				if (VolL[j]<=i)
					PT[i][j]=max(PT[i][j-1],ValL[j]+PT[i-VolL[j]][j-1]);
				else
					PT[i][j]=PT[i][j-1];
				}
		printf("%d\n",PT[v][n]);
	}
	return 0;
}
