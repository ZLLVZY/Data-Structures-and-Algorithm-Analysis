#include<stdio.h>
void move(int n,char x,char y,char z)
{
	if(1==n){
		printf("%c-->%c\n",x,z);	//ֱ�ӽ�x�Ƶ�z
	}
	else{
		move(n-1,x,z,y);		//����z����x�Ƶ�y
		printf("%c-->%c\n",x,z);		//����n���̴�x�Ƶ�z
		move(n-1,y,x,z);		//����x����y�Ƶ�z
	}
}
int main()
{
	int n;
	printf("�����뺺ŵ���Ĳ�����");
	scanf("%d",&n);
	printf("����Ϊ��\n");
	move(n,'x','y','z');
	return 0;
}
