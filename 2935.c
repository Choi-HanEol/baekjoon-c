#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char A[101];
	char B[101];
	char result[200] = {'\0'};	//null�� ����Ų��. ���� �ƽ�Ű�ڵ�� 0, ������ ǥ�÷δ� '\0' 
	
	char oper;
	int i;
	scanf("%s%*c", A);
	scanf("%c%*c", &oper);
	scanf("%s%*c", B);
	
	if(oper == '+'){
		if(strlen(A) >= strlen(B)){
			strcpy(result,A);
			result[strlen(A) - strlen(B)] += 1;	//���� 10+10�̸� 20�� �Ǵ� ��츦 �����Ͽ� += ���, �׸���  �ڵ�����ȯ���� ���� +=�� ����� result = result + 1, �� char = char + int 
												//���� �ڷ������� ū �ڷ������� ��ȯ, char�� int�� ��ȯ�Ǿ� char������ ���Ե�. 
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

