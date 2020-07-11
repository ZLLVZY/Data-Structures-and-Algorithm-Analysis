#include<stdio.h>
void move(int n,char x,char y,char z)
{
	if(1==n){
		printf("%c-->%c\n",x,z);	//直接将x移到z
	}
	else{
		move(n-1,x,z,y);		//借助z，将x移到y
		printf("%c-->%c\n",x,z);		//将第n个盘从x移到z
		move(n-1,y,x,z);		//借助x，将y移到z
	}
}
int main()
{
	int n;
	printf("请输入汉诺塔的层数：");
	scanf("%d",&n);
	printf("攻略为：\n");
	move(n,'x','y','z');
	return 0;
}
