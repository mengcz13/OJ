#include <stdio.h>

#define MAX 276

int find(double list[],double tar,int start,int end){
	int s=start,e=end;
	int len=e-s;
	int mid=s+len/2;
	while (len){
		if (list[mid]==tar)
			return mid;
		else if (list[mid]<tar)
			s=mid+1;
		else
			e=mid;
		len=e-s;
		mid=s+len/2;
	}
	return s-1;
}

double CardLen(int n){
	double len=0;
	for (int i=0;i<n;++i){
		len+=1.0/(i+2);
	}
	return len;
}

int main(){
	double LenList[MAX+2];
	for (int i=1;i<MAX+1;++i){
		LenList[i]=CardLen(i);
	}
	LenList[0]=0;
	LenList[MAX+1]=0;
	double TargetLen=0;
	scanf("%lf",&TargetLen);
	while (TargetLen>=0.01){
		printf("%d card(s)\n",find(LenList,TargetLen,1,MAX)+1);
		scanf("%lf",&TargetLen);
	}
	return 0;
}
