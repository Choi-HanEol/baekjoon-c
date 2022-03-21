#include<stdio.h>
#include<stdlib.h> 

void quickSort(int arr[], int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
      int temp;
      do
      {
        while (arr[left] > pivot)    
            left++;
        while (arr[right] < pivot)    
            right--;
        if (left<= right)    
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
            left++;
            right--;
        }
      } while (left<= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 
 
    /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 
 
    if (left < R)
        quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}

int main(void){
   int height=0, sum=0, i=0, n, m, j=1, max;   //나무 n개, 가져가야할 m미터 , height 절단기의 높이, sum 얻은 총 나무 길이
   int result_tree;
   scanf("%d%*c%d", &n, &m);
   if(!(1<=n && n<=1000000) || !(1<=m && m<=2000000000))	;
   int* tree = (int*)malloc(sizeof(int) * n);
   for(i=0; i<n; i++){
      scanf("%d", &tree[i]);
   }
   quickSort(tree,0,n-1);	//오름차순 정렬  
   max = tree[0];	//첫번째 값이 최대값  
   i=0; 
   while(1){
	    while(tree[i] == tree[i+1]){	//다음 나무와 같다면  
	      	j++;	//바깥 while문 한번 수행할 때 얻을 수 있는 나무의 길이 
	        i++;
		}
	    sum+=j;	//while문을 수행하면서 얻은 총 나무 길이 
	    result_tree = --tree[i];	//잘리고 남은 나무  
	    height++;	
	    if(sum>=m){
	    	height = max - height;
	        printf("%d\n", height);
	        break; 
	    }   
   }
   for(; i>=0; i--)	tree[i] = result_tree;
   printf("tree : %d\n",result_tree);
   for(i=0; i<n; i++){
   		printf("%d ", tree[i]);
   }
   free(tree);
   return 0;
}
