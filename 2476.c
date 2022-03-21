#include<stdio.h>
#include<stdlib.h>
int findMaxScore(int *n_score, int n){
	int i;
	int max=0;
	for(i=0; i<n; i++){
		if(n_score[i]>max)	max=n_score[i];
	}
	return max;
}

int findScore(int *score){
	int i, j;
	int same;
	int count = 1;
	int max=0;
	for(i=0; i<3; i++){
		for(j=i+1; j<3; j++){
			if(score[i] == score[j]){
				same=score[j];
				count++;
			}	
		}
		if(max<score[i])	max=score[i];
	}
	switch(count){
		case 1:
			return max*100;
		case 2:
			return same*100 + 1000;
		default:
			return same*1000 + 10000;
	}
}

int main(){
	int n;
	int score[3];
	int *n_score;
	int i,j;
	scanf("%d",&n);
	n_score = (int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++){
		for(j=0; j<3; j++){
			scanf("%d%*c",&score[j]);
		}
		n_score[i] = findScore(score);
	}
	printf("%d", findMaxScore(n_score, n));
	return 0;
}
