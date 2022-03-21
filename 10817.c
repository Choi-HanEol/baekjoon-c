#include<stdio.h>
int sort(int *arr){// 내림차순  
	int tmp;
	int i, j;
	for(i=0; i<sizeof(arr)/sizeof(int); i++){
		for(j=i; j<sizeof(arr)/sizeof(int); j++){
			if(arr[i]<arr[j]){
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;   			
			}
		}
	}
	printf("function sizeof arr = %d \n",sizeof(arr));
	return sizeof(arr);
}
int main(){
	int arr[3];
	int result;
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	printf("main sizeof arr = %d \n", sizeof(arr));
	result = sort(arr);
	printf("%d", result);
}
