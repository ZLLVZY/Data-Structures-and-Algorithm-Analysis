#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define Size 20 
#define Zsize 10
typedef double dt;
typedef char ct;
typedef struct stack
{
	dt *top;
	dt *base;
	int Msize;
}st;
typedef struct sta
{
	ct *top;
	ct *base;
	int Msize;
}sta;
void creat1(st *s)
{
	s->base=(dt*)malloc(Size*sizeof(dt));
	if(!s->base)
	{
		return;
	}
	s->top=s->base;
	s->Msize=Size;
}
void push1(st *s,dt e)
{
	if(s->top-s->base>=Size)
	{
		s->base=(dt*)realloc(s->base,(s->Msize+Zsize)*sizeof(dt));
	}
    *(s->top)=e;
	s->top++;
}
void pop1(st *s,dt *e)
{
	if(s->top==s->base)
    {
		return;
	}
	*e=*--s->top;
}
void creat2(sta *s)
{
	s->base=(ct*)malloc(Size*sizeof(ct));
	if(!s->base)
	{
		return;
	}
	s->top=s->base;
	s->Msize=Size;
}
void push2(sta *s,ct e)
{
	if(s->top-s->base>=Size)
	{
		s->base=(ct*)realloc(s->base,(s->Msize+Zsize)*sizeof(ct));
	}
    *(s->top)=e;
	s->top++;
}
void pop2(sta *s,ct *e)
{
	if(s->top==s->base)
    {
		return;
	}
	*e=*--s->top;
}
int stLen1(st s)
{
	return(s.top-s.base);
}int stLen2(sta s)
{
	return(s.top-s.base);
}
int plus(sta s)
{
	int i=stLen2(s),j=0,k=1;
	for(j=0;j<i;j++)
		{
			if(*(--s.top)=='*'||*(--s.top)=='/')
			{
				k=2;
				break;
			}
		}
	return k;
}
void cal(char c,st *st1)
{
	double d,e;
	switch(c)
		{
			case'+':
				pop1(st1,&d);
				pop1(st1,&e);
				push1(st1,d+e);
				break;
			case'-':
				pop1(st1,&e);
				pop1(st1,&d);
				push1(st1,d-e);
				break;
			case'*':
				pop1(st1,&e);
				pop1(st1,&d);
				push1(st1,d*e);
				break;
			case'/':
				pop1(st1,&e);
				pop1(st1,&d);
				if(e!=0)
				{
				push1(st1,d/e);
				}
				else
				{
					printf("\n除数为零，出错！\n");
					return;
				}	
				break;
		}
}
int main()
{
	st st1;sta st2;char c,e,str[256];double d;int i=0,k;
	creat1(&st1);creat2(&st2);
	printf("请输入运算表达式，以#号结束：\n");
	scanf("%c",&c);
	while(c!='#')
	{
		while(isdigit(c)||c=='.')
		{
			str[i++]=c;
			str[i]='\0';
			scanf("%c",&c);
			if(!(isdigit(c)||c=='.'))
			{
				d=atof(str);
				push1(&st1,d);
				i=0;
			}
		}
		if(c=='*'||c=='/'||c=='(')
		{
			push2(&st2,c);
		}
		if(c=='+'||c=='-')
		{
			k=plus(st2);
			if(1==k)
			{
				push2(&st2,c);	
			}
			if(2==k)
			{
				while(st2.top!=st2.base)
				{
					pop2(&st2,&e);
					cal(e,&st1);
				}
				push2(&st2,c);
			}
		}
		if(c==')')
		{
			while(e!='(')
			{
				pop2(&st2,&e);
				if(d!='(')
				{
					cal(e,&st1);
				}
			}
		}
		if(c!='#')
		{
			scanf("%c",&c);
		}
	}
	while(st2.top!=st2.base)
		{
			pop2(&st2,&e);
			cal(e,&st1);
		}
	pop1(&st1,&d);
	printf("运算结果为：%.2f\n",d);
	return 0;
}