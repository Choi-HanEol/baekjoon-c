#include<stdio.h>

int GCD(int a, int b){
	int i=1;
	int result;
	while(i<=a){
		if(a%i==0 && b%i==0)	result=i;
		i++;
	}
	return result;
}

int main(){
   int t, tmp;
   int a, b;
   int i,j;
   int result;
   int z;//�ִ�����  
   scanf("%d",&t);
   for(i=0; i<t; i++){
      scanf("%d%*c%d",&a, &b);
      if(a>b){ //a�� �������� 
      	tmp = a;
      	a=b;
      	b=tmp;
	  }	
      z=GCD(a,b);
	  a=a/z;
	  b=b/z;
	  result=a*b*z;

	  printf("%d\n",result);

   }      
}
