#include<stdio.h>
#define n 8
int count=0;
int anquan(int h,int l,int (*chess)[n])
{
	int i=0;
	for(i=0;i<=h;i++){                       //�ж�λ�õ��Ϸ���û�лʺ�
		if(1==*(*(chess+i)+l))               
		return 0;
	}
	for(i=0;h-i>=0&&l-i>=0;i++){             //�ж�λ�õ����Ϸ���û�лʺ�
		if(1==*(*(chess+h-i)+l-i))
		return 0;
	}
	for(i=0;h-i>=0&&l+i<n;i++){              //�ж�λ�õ����Ϸ���û�лʺ�
		if(1==*(*(chess+h-i)+l+i))
		return 0;
	}
	return 1;                                //��Ϊ���ϵ��£����Ը����·��϶�û��1��ǰ���е�Ҳ��Ӱ�죬��������
}
void eightqueen(int h,int (*chess)[n])
{
	int i=0,j=0;
	if(n==h){
		count++;
		printf("��%d�ְڷŷ���Ϊ:\n",count);
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
			for(j=0;j<n;j++){                //��h+1�е������ж�������anquan()ʱ�������ԭ��n�е�1�������棩
				*(*(chess+h)+j)=0;           //���ҵ�n������anquan()����һ����
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
	printf("�˻ʺ������ܹ���%d�ְڷŷ�����\n",count);
	return 0;	
}