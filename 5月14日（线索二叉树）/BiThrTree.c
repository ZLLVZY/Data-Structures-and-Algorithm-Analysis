#include<stdio.h>
#include<stdlib.h>
typedef char etype;
typedef enum{Link,Thread} PointerTag;
//�����洢��־λ
//Link(0)��ʾָ���ӵ�ָ��
//Thread(1)��ʾָ��ǰ����̵�����
typedef struct tnode{                                //�ڵ�
	etype data;
	PointerTag ltag,rtag;
	struct tnode *lchild,*rchild;
}tnode;

tnode *pre;                                          //ʼ��ָ��շ��ʹ��Ľڵ�

void CreatBiTree(tnode **T){                  	       //��ΪҪ��malloc�ı����ָ����ڵ��ָ���ֵ���ı���ָ���ֵ�����Ժ����β�����Ҫָ���ָ�����ı�ָ�롣
    char c;	
	scanf("%c",&c);
	if(' '==c){
		*T=NULL;
	}
	else{
		*T=(tnode *)malloc(sizeof(tnode));               //sizeof(tnode)��sizeof(tnode*)��С��һ����������Ҫ����tnode��������ռ�õĴ�С�ռ䣬���ռ��׵�ַ����������T������
		(*T)->data=c;
		(*T)->ltag=Link;
		(*T)->rtag=Link;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);
	}
}

void InThreading(tnode *T)
{
	if(T){
		InThreading(T->lchild); 				//�ݹ�����������
		if(!T->lchild){							//�ڵ㴦��
			T->ltag=Thread;
			T->lchild=pre;
		}
		if(!pre->rchild){							//�ڵ㴦��
			pre->rtag=Thread;
			pre->rchild=T;
		}
		pre=T;
		InThreading(T->rchild); 				//�ݹ��Һ���������
	}
}

void InorderThreading(tnode **p,tnode *T)
{
	*p=(tnode *)malloc(sizeof(tnode)); 				//��ʼ��ͷ���
	(*p)->ltag=Link;
	(*p)->rtag=Thread;
	(*p)->rchild=*p;
	if(!T){
		(*p)->lchild=*p;
	}
	else{
		(*p)->lchild=T;
		pre=*p;
		InThreading(T);								//��������������
		pre->rchild=*p;								//���ڵ��rchildָ��ͷ���
		(*p)->rchild=pre;							//ͷ�ڵ��rchildָ�������
		pre->rtag=Thread;							//���ڵ��rtag��Ϊrtag
	}
}

void InorderTraverse(tnode *P)      			//����������ǵݹ飩
{
	tnode *T=P->lchild;
	while(T!=P){
		while(T->ltag==Link){
		T=T->lchild;
		}
		printf("%c",T->data);
		while(T->rtag==Thread&&T->rchild!=P){
			T=T->rchild;
			printf("%c",T->data);
		}	
		T=T->rchild;
	}
	
}

int main()
{
	tnode *T=NULL,*P;
	CreatBiTree(&T);
	InorderThreading(&P,T);
	printf("���������������Ϊ��");
	InorderTraverse(P);
	printf("\n");
	return 0;
}











