#include<stdio.h>
#include<stdlib.h>
typedef char dt;
typedef struct qnode{
		dt data;
	    struct qnode *next;
}qnode;

typedef struct{
	qnode *front,*rear;
}linkqueue;

void creat(linkqueue *q){
	q->front=q->rear=(qnode*)malloc(sizeof(qnode*));
	if(!q->front)
		return;
	q->rear->next=NULL;
}

void push(linkqueue *q,dt e){
	qnode *p=(qnode*)malloc(sizeof(qnode*));
	p->data=e;
	q->rear->next=p;
	q->rear=p;
	q->rear->next=NULL;
}

void pop(linkqueue *q,dt *e){
	*e=q->front->next->data;
	q->front->next=q->front->next->next;
	if(NULL==q->front->next){
		q->rear=q->front;
		return;
	}
}

void destory(linkqueue *q){
	while(NULL!=(q->front->next)){
		q->rear=q->front->next;
		free(q->front);
		q->front=q->rear;
	}
	free(q->front);
}

void display(linkqueue q){
	while(NULL!=(q.front->next)){
		printf("%c",q.front->next->data);
		q.front=q.front->next;
	}
	printf("\n");
}
int main()
{
	linkqueue q1;dt c,d;
	creat(&q1);
	printf("请输入进入队列的字符串,以#号结束：\n");
	scanf("%c",&c);
	while('#'!=c){
		push(&q1,c);
		scanf("%c",&c);
	}
	printf("队列中的字符串为：\n");
	display(q1);
	destory(&q1);
	return 0;
}