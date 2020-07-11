#include<stdio.h>
int main()
{
	int a[30],i=0,s=0;
	a[0]=0;
	a[1]=1;
	for(i=2;i<30;i++){
		a[i]=a[i-2]+a[i-1];
	}
	for(i=0;i<30;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
