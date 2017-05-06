#include<stdio.h>
#include<malloc.h>
#define num 5 

struct list
{
	int n,l;
	struct list *next;
};

struct list *creat()
{
	struct list *s1,*s2,*head;
	int i=0;
	for(i=0;i<=num;i++)
	{
		if(i==0)
		{
			head=s1;
		}
		else
		{
			s2=(struct list*)malloc(sizeof(struct list*));
			printf("请输入第%d位的密码\n",i);
			scanf("%d",&(s2->n));
			s2->l=i;
			s1->next=s2;
			s1=s2;
		}
		s2->next=head->next;
	}
	free(head);
	return s2->next;
}

int main()
{
    struct list *p=creat(),*temp;
	int m=p->n,j=1;   
    while(p->next!=p)
    {
    	if(1!=m)
    	{
	    	for(j=1;j<m-1;j++)
	    	{
				p=p->next;
			}
	        printf("%d->",p->next->l);
	        m=p->next->n;
			temp=p->next;
	        p->next=p->next->next;
	        free(temp);
	        p=p->next;
       	}
		else
		{			
			printf("%d->",p->l);
			m=p->n;
			temp=p;
			while(temp!=p->next)
			{p=p->next;}
			p->next=p->next->next;
			free(temp);
			p=p->next;
		}
    }
    printf("%d",p->l);
	return 0; 
} 
