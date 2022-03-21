#include<stdio.h>
#include<stdlib.h> 

void quickSort(int arr[], int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2];    // pivot ���� (���) 
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
            /*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
            left++;
            right--;
        }
      } while (left<= right);    // left�� right ���� �����ʿ� ���� ������ �ݺ� 
 
    /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // ���� �迭 ��������� �ݺ� 
 
    if (left < R)
        quickSort(arr, left, R);    // ������ �迭 ��������� �ݺ� 
}

int main(void){
   int height=0, sum=0, i=0, n, m, j=1, max;   //���� n��, ���������� m���� , height ���ܱ��� ����, sum ���� �� ���� ����
   int result_tree;
   scanf("%d%*c%d", &n, &m);
   if(!(1<=n && n<=1000000) || !(1<=m && m<=2000000000))	;
   int* tree = (int*)malloc(sizeof(int) * n);
   for(i=0; i<n; i++){
      scanf("%d", &tree[i]);
   }
   quickSort(tree,0,n-1);	//�������� ����  
   max = tree[0];	//ù��° ���� �ִ밪  
   i=0; 
   while(1){
	    while(tree[i] == tree[i+1]){	//���� ������ ���ٸ�  
	      	j++;	//�ٱ� while�� �ѹ� ������ �� ���� �� �ִ� ������ ���� 
	        i++;
		}
	    sum+=j;	//while���� �����ϸ鼭 ���� �� ���� ���� 
	    result_tree = --tree[i];	//�߸��� ���� ����  
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
