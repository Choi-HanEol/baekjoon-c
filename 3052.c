#include<stdio.h>
int main(){
	int i, j, count=0;
	int list[10], reminder_list[10];
	for(i=0; i<10; i++){
		scanf("%d", &list[i]);
		reminder_list[i] = list[i] % 42;
	}
	for(i=0; i<10; i++){
		for(j=i+1; j<10; j++){
			if(reminder_list[i] == -1)	continue;
			else if(reminder_list[i] == reminder_list[j]){
				list[j] = -1;
			} 
		}
	}
	for(i=0; i<10; i++){
		if(list[i] != -1)	count++;
	}
	printf("%d", count);
	return 0;
}
