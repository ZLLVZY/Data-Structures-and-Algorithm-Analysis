#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define Size 20 
#define Zsize 10
typedef char dt;
typedef struct stack
{
	dt *top;
	dt *base;
	int Msize;
}st;
void creat(st *s)
{
	s->base=(dt*)malloc(Size*sizeof(dt));
	if(!s->base)
	{
		return;
	}
	s->top=s->base;
	s->Msize=Size;
}
void push(st *s,dt e)
{
	if(s->top-s->base>=Size)
	{
		s->base=(dt*)realloc(s->base,(s->Msize+Zsize)*sizeof(dt));
	}
    *(s->top)=e;
	s->top++;
}
void pop(st *s,dt *e)
{
	if(s->top==s->base)
    {
		return;
	}
	*e=*--s->top;
}
int stLen(st s)
{
	return(s.top-s.base);
}
int main()
{
	st st1,st2,st3;dt c,l=0,k=0,sum2[256],sum3[256];int i=0,j=0,m=0,n=0,n1=0,n2=0,n3=0,sum1=0;
	creat(&st1);
	creat(&st2);
	creat(&st3);
	printf("请输入二进制数,以#符号结束！\n");
	scanf("%c",&c);
	while(c!='#')
	{
		push(&st1,c);
		scanf("%c",&c);
	}
	getchar();
	n=n1=stLen(st1);
	for(i=0;i<n1;i++)
	{
		pop(&st1,&c);
		sum1=sum1+(c-48)*pow(2,i);
		l=l+(c-48)*pow(2,j%3);
		k=k+(c-48)*pow(2,j%4);
		if((j+1)%3==0&&j!=0)
		{
			l+=48;
			push(&st2,l);
			l=0;
		}
		if((j+1)%4==0&&j!=0)
		{
			if(k<10)
			{
				k+=48;
			}
			else
			{
				k+=55;
			}
			push(&st3,k);
			k=0;
		}
		j++;
	}
	if(l!=0)
	{
		l+=48;
		push(&st2,l);
	}
	if(k!=0)
	{
		if(k<10)
			{
				k+=48;
			}
			else
			{
				k+=55;
			}
			push(&st3,k);
	}
	n2=stLen(st2);
	n3=stLen(st3);
	for(i=0;i<n2;i++)
	{
		pop(&st2,sum2+i);
	}
	sum2[i]='\0';
	for(i=0;i<n3;i++)
	{
		pop(&st3,sum3+i);
	}
	sum3[i]='\0';
	printf("十进制为：%d\n",sum1);
	printf("八进制为：");
	puts(sum2);
	printf("十六进制为：");
	puts(sum3);
	return 0;
}