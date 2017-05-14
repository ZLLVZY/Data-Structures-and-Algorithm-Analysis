#include<stdio.h>
#include<stdlib.h>
typedef char etype;
typedef enum{Link,Thread} PointerTag;
//线索存储标志位
//Link(0)表示指向孩子的指针
//Thread(1)表示指向前驱后继的线索
typedef struct tnode{                                //节点
	etype data;
	PointerTag ltag,rtag;
	struct tnode *lchild,*rchild;
}tnode;

tnode *pre;                                          //始终指向刚访问过的节点

void CreatBiTree(tnode **T){                  	       //因为要用malloc改变给出指向根节点的指针的值，改变了指针的值，所以函数形参这需要指针的指针来改变指针。
    char c;	
	scanf("%c",&c);
	if(' '==c){
		*T=NULL;
	}
	else{
		*T=(tnode *)malloc(sizeof(tnode));               //sizeof(tnode)和sizeof(tnode*)大小不一样，这里是要分配tnode数据类型占用的大小空间，将空间首地址给主函数中T！！！
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
		InThreading(T->lchild); 				//递归左孩子线索化
		if(!T->lchild){							//节点处理
			T->ltag=Thread;
			T->lchild=pre;
		}
		if(!pre->rchild){							//节点处理
			pre->rtag=Thread;
			pre->rchild=T;
		}
		pre=T;
		InThreading(T->rchild); 				//递归右孩子线索化
	}
}

void InorderThreading(tnode **p,tnode *T)
{
	*p=(tnode *)malloc(sizeof(tnode)); 				//初始化头结点
	(*p)->ltag=Link;
	(*p)->rtag=Thread;
	(*p)->rchild=*p;
	if(!T){
		(*p)->lchild=*p;
	}
	else{
		(*p)->lchild=T;
		pre=*p;
		InThreading(T);								//调用线索化函数
		pre->rchild=*p;								//最后节点的rchild指向头结点
		(*p)->rchild=pre;							//头节点的rchild指向最后结点
		pre->rtag=Thread;							//最后节点的rtag改为rtag
	}
}

void InorderTraverse(tnode *P)      			//中序遍历（非递归）
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
	printf("中序遍历的输出结果为：");
	InorderTraverse(P);
	printf("\n");
	return 0;
}











