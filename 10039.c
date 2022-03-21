#include<stdio.h>
int main(){
	int score[5]={0};
	int avg=0;
	int i;
	for(i=0; i<sizeof(score)/sizeof(int); i++){
		scanf("%d", &score[i]);
		if(score[i]<40)	score[i]=40;
		avg+=score[i];
	}
	printf("%d",avg/5);
	return 0;
}
