#include<stdio.h>
double n;
long long a,s;
long long d,f;
long long sishewuru(double g){
	if(g>=(int)g+0.5){
		return g+1;
	}
	else return g;
}
long long f1(long long q){
	if(q==1||q==2){
		return 1;
	}
	if(q==0){
		return 0;
	}
	return f1(q-1)+f1(q-2);
}
long long f2(long long p){
	if(p==sishewuru(n/3)){
		return a;
	}
	if(p==sishewuru(n/3)-1){
		return s;
	}
	return f2(p-1)+f2(p-2);
}
long long f3(long long i){
	if(i==sishewuru(2*n/3)){
		return d;
	}
	if(i==sishewuru(2*n/3-1)){
		return f;
	}
	return f3(i-1)+f3(i-2);
}
int main()
{
	scanf("%lf",&n);
	long long o;
	switch ((int)n){
		case 0:	o=0;break;
		case 1:	o=1;break;
		default:
			a=f1(sishewuru(n/3));
			s=f1(sishewuru(n/3)-1);
			d=f2(sishewuru(2*n/3));
			f=f2(sishewuru(2*n/3)-1);
			o=f3(n);
			break;
	}
	printf("%lld",o);
	return 0;
}