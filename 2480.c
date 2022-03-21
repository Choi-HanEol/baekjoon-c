#include<stdio.h>
int findmax(int a, int b, int c){
	int i=7;
	while(i--){
		if(a==i || b==i || c==i)	return i;
	}
}
int main(){
	int num[3];
	int score[7]={0};
	int i;
	int result;
	int count=0;
	scanf("%d %d %d",&num[0],&num[1],&num[2]);
	for(i=0; i<3; i++){
		if(score[num[i]]){
			count++;
			result=num[i];
		}
		else{
			score[num[i]] = 1;
		}
	}
	switch(count){
		case 0:
			printf("%d\n",findmax(num[0],num[1],num[2]) * 100);
			break;
		case 1:
			printf("%d\n", result*100 + 1000);
			break;
		case 2:
			printf("%d\n", result*1000 + 10000);
			break;
	}
}
