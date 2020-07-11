#include<stdio.h>
#include<string.h>
int main()
{
	char s1[10]="ZLLVZY",s2[10]="LVZY";
	int i=0,j=0,k=0;					
	for(i=0;i<strlen(s1);i++){
		if(s2[0]==s1[i]){
			for(j=0;j<strlen(s2);j++){
				k=0;
				if(s1[i+j]==s2[j]){
					k=1;
				}
			}
		}
		if(1==k){
			break;
		}
	}
	if(1==k){
		printf("s2是s1的子串,是从s1的%d位到%d位",i+1,i+j);
	}
	else{
		printf("s2不是s1的子串");
	}
	return 0;
}