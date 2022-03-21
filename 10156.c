#include<stdio.h>
int main(){
	int k, n, m;
	long long money;
	
	scanf("%d %d %d", &k, &n, &m);
	money=k*n-m;
	if(money<0)	money=0;
	printf("%lld",money);
}
