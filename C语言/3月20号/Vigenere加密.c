#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
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

/*void display( list *p)
{
	int i=0;
    while(i<num)
    {
	    printf("%c ",p->n);
        p=p->next;
		i++;
    }
}*/

int main()
{
	list *p=creat(),*q=creat();
	int m=0,i=0,j=0,k=0;
	dt s[256],d[256];
	int f[256];
	srand((unsigned)time(NULL));
    printf("请输入字符串明文：\n");
	gets(s);
	fflush(stdin);
	m=strlen(s);
	for(i=0;i<m;i++)
	{
		for(j=0;j<num;j++)
		{
			if(p->n==s[i])
			{
				k=f[i]=(rand()%100);
				while(k!=0)
				{
					q=q->next;
					k--;
				}
				d[i]=q->n;
				while(q->n!=p->n)
				{
					q=q->next;
				}
				break;
			}
			p=p->next;
			q=q->next;
		}
	}
	d[i]='\0';
	printf("随机密钥为：\n");
	for(i=0;i<m;i++)
	{
		printf("%d ",f[i]);
	}
	printf("\n密文为:\n");
	puts(d);
	return 0;
} 