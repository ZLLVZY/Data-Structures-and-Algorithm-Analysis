#include<stdio.h>
#define size 10 
typedef int etype;

int fib(int i){
	if(i<2)
		return i==0?0:1;
	return fib(i-2)+fib(i-1);
}

int cz(int n,int *p,int low,int high)
{
	etype mid;
	mid=low+(high-low)/2;
	if(*(p+mid)>n){
		return cz(n,p,low,mid);
	}
	if(*(p+mid)<n){
		return cz(n,p,mid,high);
	}
	else{
		return mid;
	}
}

int main()
{
	etype n,a[size],i;
	for(i=0;i<size;i++){
		a[i]=fib(i);
	}
	printf("��������ҵ�����");
	scanf("%d",&n);
	i=cz(n,a,0,size);
	printf("��Ҫ���ҵ�����쳲����������е�%d��\n",i+1);
}