#include<stdio.h>
#include<string.h>

void getnext(char *str,int len,int *next)
{
	int i=0,j=1;
	*next=-1;
	*(next+1)=0;
	for(j=1;j<len;j++){
		i=*(next+j);
		while(*(str+i)!=*(str+j)){
			i=*(next+i);
			if(0==i||-1==i){
				break;
			}
		}
		if(*(str+i)==*(str+j)){
			*(next+j+1)=i+1;
		}
		else{
			*(next+j+1)=0;
		}
	}
}
void kmp(char *s1,char *s2,int n1,int n2,int *next)
{
	int i=0,j=0;
	for(j=0;j<n2;j++){
		while(*(s1+i)==*(s2+j)){
			j++;i++;
			if(i==n1||j==n2){
				break;
			}
		}
		if(n1==i){
			printf("s1是s2的子串,从第%d位到第%d位\n",j-i+1,j);
			break;
		}
		else{
			i=*(next+i);
			j--;
			if(-1==i){
				i=0;j++;
			}
		}
	}
	if(j==n2&&i!=n1){
		printf("s1不是s2的子串");
	}
	
}
int main()
{	char s1[255]="LVZY",s2[255]="ZLLVZYLVZL";
	int next[255];
	int n1=strlen(s1),n2=strlen(s2);
	getnext(s1,n1,next);
	kmp(s1,s2,n1,n2,next);
	return 0;
}