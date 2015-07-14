#include <stdio.h>

#define N 65535

int find(int List[],int tar,int sta, int end){
	int s=sta,e=end;
	int len=e-s;
	int mid=s+len/2;
	while (len){
		if (List[mid]==tar)
			return mid;
		else if (List[mid]<tar)
			s=mid+1;
		else
			e=mid;
		len=e-s;
		mid=s+len/2;
	}
	return s-1;
}

int main(){
	int SumList[N+2];
	for (int i=1;i<=N;++i){
		SumList[i]=i*(i+1)/2;
	}
	int t=0,n=0;
	scanf("%d",&t);
	for (int i=0;i<t;++i){
		scanf("%d",&n);
		int LastNum=find(SumList,n,1,N+1);
		int left=n%SumList[LastNum];
		printf("%d\n",left==0?LastNum:left);
	}
	return 0;
}
