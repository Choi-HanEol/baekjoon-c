#include<stdio.h>
#include<stdlib.h> 

void bubblesort(int data[], int data_size){
	int i, j, temp;
	for (i = 0; i < data_size; i++) {
		for (j = 0; j < (data_size - 1) - i; j++) {
			if (data[j] < data[j + 1]) {	// 버블 정렬 사용
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

int main(void){
	int height=0, sum=0, i=0, n, m, j=1;	//나무 n개, 가져가야할 m미터 
	scanf("%d%*c%d", &n, &m);
	int* tree = (int*)malloc(sizeof(int) * n);
	for(i=0; i<n; i++){
		scanf("%d", &tree[i]);
	}
	bubblesort(tree,n);
	i=0;
	while(1){
		if(tree[i] == tree[i+1]){
			j++;
			i++;
		}	
		sum+=j;
		height++;
		if(sum>=7){
			printf("%d\n", height);
			free(tree);
			break; 
		}	
	}
	free(tree);
	return 0;
}
