#include<stdio.h>
#include<malloc.h>
#define num 13
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
			s2->n=0;
			s1->next=s2;
			s1=s2;
		}
		s2->next=head->next;
	}
	free(head);
	return s2->next;
}

void display(struct list *p)
{
	int i=0; 
    while(i<num)
    {
	    printf("%d ",p->n);
        p=p->next;
		i++;
    }
}

void destory(struct list *p)
{
	struct list *temp1=p,*temp2;
	int i=0;
	while(i<num)
	{
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
		i++; 
	}	
}
 
int main()
{
	int count=2,i=0;
    struct list *p=creat();
    p->n=1;
    while(count<=13)
    {
	    for(i=0;i<count;i++)
	    {
			p=p->next;
			if(p->n!=0)
			i--;
		}
		p->n=count;
		count++;
    }
    while(p->n!=1)
    p=p->next;
    display(p);
    destory(p);
    return 0; 
} 
