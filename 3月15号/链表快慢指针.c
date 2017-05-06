#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#define num 5

struct list
{
	int n;
	struct list *next;
};

struct list *creat()
{
	struct list *s1,*s2,*head;
	int i=0;
	srand((unsigned)time(NULL));
	for(i=0;i<=num;i++)
	{
		if(i==0)
		{
			head=s1;
		}
		else
		{
			s2=(struct list*)malloc(sizeof(struct list*));
			s2->n=(rand()%100);
			s1->next=s2;
			s1=s2;
		}
		s2->next=NULL;
	}
	return head;
}
void display(struct list *p)
{
    while(p->next!=NULL)
    {
        printf("%d ",p->next->n);
        p=p->next;
    }
}
int main()
{
    struct list *p1=creat(),*p2;
    display(p1);
    printf("\n");
    p2=p1;
    if(num%2==0)
    {
        while(p1->next!=NULL)
        {
            p1=p1->next->next;
            p2=p2->next;
        }
        printf("%d",p2->n);
    }
    else
    {
        while(p1->next->next!=NULL)
        {
            p1=p1->next->next;
            p2=p2->next;
        }
        printf("%d",p2->next->n);
    }
    return 0;
}
