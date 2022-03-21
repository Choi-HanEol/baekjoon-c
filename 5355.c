#include<stdio.h>
int main(){
	int T;
	int i, j=0;
	double num;
	char input[3], spacebar;
	
	scanf("%d",&T);
	
	for(i = 0; i < T; i++){
		scanf("%lf ", &num);
		while(j < 3){
			input[j]=getchar();
			spacebar = getchar();	//spacebar 
			if(input[j] == '@')	num*=3;
			else if(input[j] == '%')	num+=5;
			else if(input[j] == '#')	num-=7;	
			if(input[j] == '\n' || spacebar == '\n')	break;
			j++;
		}
		printf("%.2lf\n", num);
		j=0;
	}
}
