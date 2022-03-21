#include<stdio.h>
int fibo(int n, int a, int b, int count) {
	int result;
	result = a + b;
	if(a==0 && b==0)	b++;

	if (count < n)	fibo(n, b, result, ++count);
	else  return result;
}

int main(void) {
	int n, result;
	scanf("%d", &n);
	result = fibo(n, 0, 0, 0);
	printf("%d\n", result);
}
