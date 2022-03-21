#include<stdio.h>
int main(){
	int T;
	int i, j=0;
	double num;
	char m, spacebar;
	
	scanf("%d",&T);
	
	for(i = 0; i < T; i++){
		scanf("%lf ", &num);
		while(1){
			scanf("%c", &m);
			if(m == '@')	num*=3;
			else if(m == '%')	num+=5;
			else if(m == '#')	num-=7;	
			else if(m == '\n')	break;
			else	continue;
		}
		printf("%.2lf\n", num);
		j=0;
	}
}
