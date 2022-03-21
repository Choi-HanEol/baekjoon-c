#include<stdio.h>
int main(){
	int hour, min;
	int after;
	scanf("%d %d", &hour, &min);
	scanf("%d", &after);
	if(hour < 0 || hour > 24 || min < 0 || min > 60)	return 0;
	min += after;
	hour += min/60;
	min = min % 60;
	
	hour = hour % 24;
	printf("%d %d\n", hour, min);
}
