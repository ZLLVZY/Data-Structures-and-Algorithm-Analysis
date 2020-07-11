#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct list
{
	int n;
	struct list *next;
};

struct list *creat(int m)
{
	struct list *s1,*s2,*head;
	int i=0;
	for(i=0;i<=m;i++)
	{
		if(i==0)
		{
			head=s1=(struct list*)malloc(sizeof(struct list));
		}
		else
		{
			s2=(struct list*)malloc(sizeof(struct list*));
			s2->n=i;
			s1->next=s2;
			s1=s2;
		}
	}
	s2->next=head->next;
	free(head);
	return s2->next;
}

void display(struct list *p,int m)
{
	int i=0;
    while(i<m)
    {
	    printf("%d ",p->n);
        p=p->next;
		i++;
    }
}

void destory(struct list *p,int m)
{
	struct list *temp1=p,*temp2;
	int i=0;
	while(i<m)
	{
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
		i++;
	}
}


int main()
{
	int m,i=0;
     printf("请输入拉丁方阵行数:\n");
    scanf("%d",&m);
    fflush(stdin);
	struct list *p=creat(m);
    while(i<m)
    {
    	if(i!=0)
        p=p->next;
    	display(p,m);
    	printf("\n");
    	i++;
	}
	destory(p,m);
    return 0;
}
