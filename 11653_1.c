#include<stdio.h>

int main(){
	int arr[1000];
	int n, i=2;
	scanf("%d", &n);
	
	if(n==1)	return 0;
	
	while(i<=n/2){
		if(n%i == 0){
			n /= i;
			printf("%d\n", i);
			if(n == 1){	
				break;
			}
		}
		else	i++;
	}
	printf("%d", n);
	return 0;
}
