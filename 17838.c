#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool like_command(char * input){
	bool result = true;
	if(strlen(input) != 7){
		result = false;
	}
	
	if(!(input[0] == input[1] && input[1] == input[4]
	&& input[0] != input[2] 
	&& input[2] == input[3] && input[3] == input[5] && input[5] == input[6])){
		result = false;
	}
	return result;
}

int main(){
	char input[10000] = {0,};
	int test_case, i;
	 
	scanf("%d", &test_case);
	
	for(i=0; i<test_case; i++){
		scanf("%s",input);
		if(like_command(input))	printf("1\n");
		else	printf("0\n");
	}	
}
