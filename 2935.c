#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char A[101];
	char B[101];
	char result[200] = {'\0'};	//null을 가리킨다. 널의 아스키코드는 0, 문자의 표시로는 '\0' 
	
	char oper;
	int i;
	scanf("%s%*c", A);
	scanf("%c%*c", &oper);
	scanf("%s%*c", B);
	
	if(oper == '+'){
		if(strlen(A) >= strlen(B)){
			strcpy(result,A);
			result[strlen(A) - strlen(B)] += 1;	//만약 10+10이면 20이 되는 경우를 감안하여 += 사용, 그리고  자동형변환으로 인해 +=를 해줘야 result = result + 1, 즉 char = char + int 
												//작은 자료형에서 큰 자료형으로 변환, char이 int로 변환되어 char형으로 대입됨. 
		}
		else{
			strcpy(result,B);
			result[strlen(B) - strlen(A)] = '1';
		} 	
	}
	else if(oper == '*'){
		result[0] = '1';
		for(i=1; i <= strlen(A) + strlen(B) - 2; i++){
			result[i] = '0';
		}
	}	
	else	return 0;
	printf("%s",result);

	return 0;
}

