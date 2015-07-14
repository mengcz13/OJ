#include <stdio.h>

int main(){
	float sum=0,m=0;
	for (int i=0;i<12;++i){
		scanf("%f",&m);
		sum+=m;
	}
	sum/=12;
	printf("$%.2f",sum);
	return 0;
}
