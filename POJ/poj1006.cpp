#include <stdio.h>

#define N1 23
#define N2 28
#define N3 33

#define M1 (N2*N3)
#define M2 (N1*N3)
#define M3 (N1*N2)

#define N (N1*N2*N3)

//#define DEBUG

struct EuclidResult{
	int d;
	int x;
	int y;
};

struct EuclidResult euclid_extended(int a, int b){
	struct EuclidResult res;
	res.d=a;res.x=1;res.y=0;
	if (0==b)
		return res;
	else{
		struct EuclidResult next=euclid_extended(b,a%b);
		res.d=next.d;
		res.x=next.y;
		res.y=next.x-(a/b)*next.y;
		return res;
	}
}

int main(){
	const int C1=M1*euclid_extended(M1,N1).x;
	const int C2=M2*euclid_extended(M2,N2).x;
	const int C3=M3*euclid_extended(M3,N3).x;
#ifdef DEBUG
	printf("%d	%d	%d\n",C1,C2,C3);
#endif
	int x1=0, x2=0, x3=0, curd=0, i=1;
	scanf("%d%d%d%d",&x1,&x2,&x3,&curd);
	while (x1>=0){
		x1%=N1;
		x2%=N2;
		x3%=N3;
		int b=x1*C1+x2*C2+x3*C3;
		while (b<0)
			b+=N;
		b=b%N;
		int base=curd-b;
		if (base<0)
			base=-base;
		else
			base=N-base%N;
		printf("Case %d: the next triple peak occurs in %d days.\n",i,base);
		i++;
		scanf("%d%d%d%d",&x1,&x2,&x3,&curd);
	}
	return 0;
}
