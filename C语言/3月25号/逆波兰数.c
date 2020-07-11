#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define Size 20 
#define Zsize 10
typedef double dt;
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
	st st1;char c;dt d,e;char str[256];int i=0;
	creat(&st1);
	printf("请输入逆波兰表达式，数据与运算符间用空格隔开，以#号为结束标志：\n");
	scanf("%c",&c);
	while(c!='#')
	{
		while(isdigit(c)||c=='.')
		{
		
			str[i++]=c;
			str[i]='\0';
			scanf("%c",&c);
			if(c==' ')
			{
				d=atof(str);
				push(&st1,d);
				i=0;
			}
		}
		switch(c)
		{
			case'+':
				pop(&st1,&d);
				pop(&st1,&e);
				push(&st1,d+e);
				break;
			case'-':
				pop(&st1,&e);
				pop(&st1,&d);
				push(&st1,d-e);
				break;
			case'*':
				pop(&st1,&e);
				pop(&st1,&d);
				push(&st1,d*e);
				break;
			case'/':
				pop(&st1,&e);
				pop(&st1,&d);
				if(e!=0)
				{
				push(&st1,d/e);
				}
				else
				{
					printf("\n除数为零，出错！\n");
					return -1;
				}	
				break;
		}
		scanf("%c",&c);
	}
	pop(&st1,&d);
	printf("运算结果为：%.2f\n",d);
}