#include<stdio.h>
void swap (int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int main()
{
	int a,b;
	int temp;
	scanf("%d,%d",&a,&b);
	//swap(a,b);
	temp=a;
	a=b;
	b=temp;
	printf("%d,%d",a,b);
	return 0;
}