#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
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
int plus(st s)
{
	int i=stLen(s),j=0,k=1;
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
int main()
{
	st st1;char c,d='0';char str[256];int i=0,j=0,k=0;
	creat(&st1);
	printf("请输入运算表达式，以#号为结束标志：\n");
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
				for(j=0;j<i;j++)
				{
					printf("%c",str[j]);
				}
				i=0;
				printf(" ");
			}
		}
		if(c=='*'||c=='/'||c=='(')
		{
			push(&st1,c);
		}
		if(c=='+'||c=='-')
		{
			k=plus(st1);
			if(1==k)
			{
				push(&st1,c);	
			}
			if(2==k)
			{
				while(st1.top!=st1.base)
				{
					pop(&st1,&d);
					printf("%c ",d);
				}
				push(&st1,c);
			}
		}
		if(c==')')
		{
			while(d!='(')
			{
				pop(&st1,&d);
				if(d!='(')
				{
					printf("%c ",d);
				}
			}
		}
		if(c!='#')
		{
			scanf("%c",&c);
		}
	}
	while(st1.top!=st1.base)
		{
			pop(&st1,&d);
			printf("%c ",d);
		}
	return 0;
}