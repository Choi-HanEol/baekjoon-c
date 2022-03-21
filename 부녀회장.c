#include<stdio.h>
#include<stdlib.h>
int main(){
	int apart[15][15]={0};
	int i,j,t;
	int k, n;
	for(i=1; i<15; i++){//아파트 0층 사람 수  
		apart[0][i] = i;
	}
	for(i=1; i<15; i++){
		for(j=1; j<15; j++){
			apart[i][j] = apart[i-1][j] + apart[i][j-1];
		}
	}
	scanf("%d",&t);
	for(i=0; i<t; i++){
		scanf("%d%d", &k, &n);
		printf("%d\n",apart[k][n]);
	}
	
}
