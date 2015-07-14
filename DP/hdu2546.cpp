#include <stdio.h>

#define N 1100
#define M 1100

int PriceList[N+1];
int Table[M+1][N+1];

int max(int a,int b){
	return (a>b)?a:b;
}

int main(){
	int n=0, m=0, maxp=0;
	scanf("%d",&n);
	while (0!=n){
		for (int i=1;i<=n;++i)
			scanf("%d",&PriceList[i]);
		scanf("%d",&m);
		if (m<5)
			printf("%d\n",m);
		else{
		m-=5;
		maxp=1;
		for (int i=1;i<=n;++i)
			if (PriceList[maxp]<PriceList[i])
				maxp=i;
		for (int i=0;i<=m;++i)
			for (int j=0;j<=n;++j){
				if (i==0||j==0)
					Table[i][j]=0;
				else{
				if (maxp!=j){
					if (i-PriceList[j]>=0)
						Table[i][j]=max(Table[i][j-1],PriceList[j]+Table[i-PriceList[j]][j-1]);
					else
						Table[i][j]=Table[i][j-1];
				}
				else
					Table[i][j]=Table[i][j-1];
				}
			}
		for (int i=0;i<=m;++i){
			for (int j=0;j<=n;++j)
				printf("%d	",Table[i][j]);
			printf("\n");}
		printf("%d\n",m+5-Table[m][n]-PriceList[maxp]);
		}
		scanf("%d",&n);
	}
	return 0;
}
