#include <stdio.h>

#define MAXMN 10000

int price[MAXMN+1];
double p[MAXMN+1];
double ndp[MAXMN+1];

double min(double,double);

int main(){
	int n=0, m=0;
	scanf("%d%d",&n,&m);
	while (n!=0||m!=0){
	for (int i=0;i<m;++i){
		scanf("%d%lf",&price[i+1],&p[i+1]);
		p[i+1]=1-p[i+1];
	}
	ndp[0]=1;
	for (int i=0;i<=n;++i){
		ndp[i]=1;
	}
	for (int j=1;j<=m;++j){
		for (int i=n;i>=0;--i){
			if (price[j]<=i)
				ndp[i]=min(ndp[i],p[j]*ndp[i-price[j]]);
		}
	}
	printf("%.1f%%\n",(1-ndp[n])*100);
	scanf("%d%d",&n,&m);
	}
	return 0;
}

double min(double a, double b){
	return (a>b)?b:a;
}
