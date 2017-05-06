#include<stdio.h>
#include<malloc.h>
#define num 41

struct list
{
	int n;
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
			s2->n=i;
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
	int m=3,j=1;    
    while(p->next!=p)
    {
    	for(j=1;j<m-1;j++)
    	{
			p=p->next;
		}
        printf("%d->",p->next->n);
        temp=p->next;
        p->next=p->next->next;
        free(temp);
        p=p->next;
    }
    printf("%d",p->next->n);
    return 0; 
} 
