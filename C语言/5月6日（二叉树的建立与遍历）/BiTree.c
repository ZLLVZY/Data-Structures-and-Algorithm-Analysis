#include<stdio.h>
#include<stdlib.h>
typedef char etype;

typedef struct tnode{
	etype data;
	struct tnode *lchild,*rchild;
}tnode;

void CreatBiTree(tnode **T){                  	       //因为要用malloc改变给出指向根节点的指针的值，改变了指针的值，所以函数形参这需要指针的指针来改变指针。
    char c;
	
	scanf("%c",&c);
	if(' '==c){
		*T=NULL;
	}
	else{
		*T=(tnode *)malloc(sizeof(tnode));               //sizeof(tnode)和sizeof(tnode*)大小不一样，这里是要分配tnode数据类型占用的大小空间，将空间首地址给主函数中T！！！
		(*T)->data=c;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);
	}
}

void visit(etype data,int level)
{
	printf("数据为:%c,它所在层数为:%d\n",data,level);
}

void PerOrderTraverse(tnode *T,int level){
	if(T){
		visit(T->data,level);
		PerOrderTraverse(T->lchild,level+1);
		PerOrderTraverse(T->rchild,level+1);
	}
	else{
		return;
	}
}
int main()
{
	int level=1;
	tnode *T;
	CreatBiTree(&T);
	PerOrderTraverse(T,level);
	return 0;
}