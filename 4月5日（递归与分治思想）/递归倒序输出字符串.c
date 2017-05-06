#include<stdio.h>
void print(){
	char c;
	scanf("%c",&c);
	if('#'!=c){
		print();
	}
	if('#'!=c){
		printf("%c",c);
	}	
}
int main()
{
	print();
	return 0;
}