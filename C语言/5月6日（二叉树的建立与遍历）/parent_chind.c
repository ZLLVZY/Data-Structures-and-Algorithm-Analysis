//parent_child

#define Msize 100
typedef int etype;

typedef struct cd   //孩子节点
{
	int chind;
	strcut cd *next;
}cd;

typedef struct bt   //表头
{
	etype data;
	int parent;
	strcut bt *next;
}bt;

typedef struct tree
{
	bt tree[Msize];
	int r,n;
}