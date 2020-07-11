#include<stdio.h>
#include<stdlib.h>
#define num 26
typedef char dt;
typedef struct list
{
	dt n;
	struct list *piror;
	struct list *next;
}list;

list *creat()
{
	list *s1,*s2,*temp;
	int i=0;
	for(i=0;i<=num;i++)
	{
		if(i==0)
		{
			s1=temp=(list*)malloc(sizeof(list));
			//printf("%d,%d\n",temp,s1);
		}
		else
		{
			s2=(list*)malloc(sizeof(list));
			s2->n=i+64;
			s1->next=s2;
			s2->piror=s1;
			s1=s2;
		}
	}
	s2->next=temp->next;
	temp->next->piror=s2;
	free(temp);
	return s2->next;
}

void display( list *p)
{
	int i=0;
    while(i<num)
    {
	    printf("%c ",p->n);
        p=p->next;
		i++;
    }
}

int main()
{
	list *p=creat();
	int m=3,i=0;
    printf("请输入一个整数：\n");
	scanf("%d",&m);
	fflush(stdin);
	if(m>=0)
	{
		for(i=0;i<m;i++)
		{
			p=p->next;
		}
	}
	else
	{
		m=m*(-1);
		for(i=0;i<m;i++)
		{
			p=p->piror;
		}
	}
	display(p);
	return 0;
} 