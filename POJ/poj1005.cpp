#include <stdio.h>

#define PI 3.14

int main(){
	int n=0;
	float x=0,y=0;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%f%f",&x,&y);
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,int(0.5*PI*(x*x+y*y)/50)+1);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
