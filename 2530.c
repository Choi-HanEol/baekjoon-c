#include<stdio.h>
int main(){
	int hour, min, sec;
	int after;
	scanf("%d %d %d", &hour, &min, &sec);
	scanf("%d", &after);
	if(hour < 0 || hour > 24 || min < 0 || min > 60 || sec < 0 || sec > 60)	 return 0;
	sec += after;
	min += sec/60;
	sec = sec % 60;
	
	hour += min/60;
	min = min % 60;
	
	hour = hour % 24;
	printf("%d %d %d\n", hour, min, sec);
}
