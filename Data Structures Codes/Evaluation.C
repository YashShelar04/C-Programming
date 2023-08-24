#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 20

void getOperator(char op){
	int flag;
	switch(op){
	        case '+': flag=1;
	        case '-': flag=2;
	        case '*': flag=3;
        	case '/': flag=4;
	        case '^': flag=5;
	        default: flag=-1;
		}
}

void evaluation(char*expression){
	char stack[max];
	int top=-1;
	int answer;
	int flag;
	
	for(int i=0;expression[i]!='\0';i++){
		char ch=expression[i];
		getOperator(ch);
		
		if(flag =-1){
			stack[++top]=(int)ch;
		}else if(top!=-1&&flag!=-1){
			switch(flag){
				case 1: answer=stack[top-2]+stack[top-1];
				break;
				case 2: answer=stack[top-2]-stack[top-1];
				break;
				case 3: answer=stack[top-2]*stack[top-1];
				break;
				case 4: answer=stack[top-2]/stack[top-1];
				break;
				case 5: answer=pow(stack[top-2],stack[top-1]);
				break;
			}
		}
		stack[++top]=answer;
	}
}



int main(){
	char expression[max];
	int answer;
	
	printf("Enter the postfix Expression: ");
	fgets(expression,max,stdin);
	
	evaluation(expression);
	
	printf("The value of the above expression is: %d",answer);
}
