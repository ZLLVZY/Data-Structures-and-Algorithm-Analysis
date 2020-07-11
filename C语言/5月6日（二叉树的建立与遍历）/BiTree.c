#include<stdio.h>
#include<stdlib.h>
typedef char etype;

typedef struct tnode{
	etype data;
	struct tnode *lchild,*rchild;
}tnode;

void CreatBiTree(tnode **T){                  	       //��ΪҪ��malloc�ı����ָ����ڵ��ָ���ֵ���ı���ָ���ֵ�����Ժ����β�����Ҫָ���ָ�����ı�ָ�롣
    char c;
	
	scanf("%c",&c);
	if(' '==c){
		*T=NULL;
	}
	else{
		*T=(tnode *)malloc(sizeof(tnode));               //sizeof(tnode)��sizeof(tnode*)��С��һ����������Ҫ����tnode��������ռ�õĴ�С�ռ䣬���ռ��׵�ַ����������T������
		(*T)->data=c;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);
	}
}

void visit(etype data,int level)
{
	printf("����Ϊ:%c,�����ڲ���Ϊ:%d\n",data,level);
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