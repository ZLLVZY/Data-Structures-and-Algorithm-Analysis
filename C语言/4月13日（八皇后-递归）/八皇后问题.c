#include<stdio.h>
#define n 8
int count=0;
int anquan(int h,int l,int (*chess)[n])
{
	int i=0;
	for(i=0;i<=h;i++){                       //判断位置的上方有没有皇后
		if(1==*(*(chess+i)+l))               
		return 0;
	}
	for(i=0;h-i>=0&&l-i>=0;i++){             //判断位置的左上方有没有皇后
		if(1==*(*(chess+h-i)+l-i))
		return 0;
	}
	for(i=0;h-i>=0&&l+i<n;i++){              //判断位置的右上方有没有皇后
		if(1==*(*(chess+h-i)+l+i))
		return 0;
	}
	return 1;                                //因为由上到下，所以该行下方肯定没有1，前面有的也不影响，后面会清掉
}
void eightqueen(int h,int (*chess)[n])
{
	int i=0,j=0;
	if(n==h){
		count++;
		printf("第%d种摆放方法为:\n",count);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d ",*(*(chess+i)+j));
			}
			printf("\n");
		}
		printf("\n");
	}
	else{
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){                //若h+1行的所有列都不满足anquan()时，先清掉原先n行的1（接下面）
				*(*(chess+h)+j)=0;           //再找第n行满足anquan()的下一个数
			}
			if(anquan(h,i,chess)){
				*(*(chess+h)+i)=1;
				eightqueen(h+1,chess);	
			}
		}
	}
}
int main()
{
	int i=0,j=0,chess[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			chess[i][j]=0;
		}
	}
	eightqueen(0,chess);
	printf("八皇后问题总共有%d种摆放方法。\n",count);
	return 0;	
}