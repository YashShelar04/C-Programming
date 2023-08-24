#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

char stack[max];
char infix[max];
char postfix[max];
int top=-1;

void push(char);
char pop();
char peek();
void display();
void intopost();
int isEmpty();
int prec(char);

int main()
{
	printf("enter a valid infix expression:");
	gets(infix);
	intopost();
	puts(postfix);
	return 0;
	}
	
	void intopost()
	
	{
		int i,j=0,new;
		for(i=0;i<strlen(infix);i++)
		{
			char ch=infix[i];
			switch(ch)
			{
				case '(':
				push('(');
				break;
				
				case ')':
				while(stack[top]!='(')
				{
					postfix[j++]=pop();
					}
					
			     case '+':
			     case '-':
			     case '*':
			     case '/':
			     case '%':
			     if(prec(stack[top])>prec(ch))
			     {
					 postfix[j++]=pop();
					 push(ch);
				 }
				 
				 else
				 push(ch);
				 break;
				 case '^':
				 push(ch);

					
					default:
					postfix[j++]=infix[i];
					break;
				
				
				
				}
				
			}
			
			while(!isEmpty())
			{
				postfix[j++]=pop();
				}
		
		}
	
	
	int prec(char c)
	{
		switch(c)
		{
			case '^':
			return 3;
			
			case '*':
			case '/':
			case '%':
			return 2;
			
			case '+':
			case '-':
			return 1;
			
			default :
			return 0;
			
				}
		}
	
	void push(char c)
{
		if(top==max-1)
		{printf("overflow condition");
		return;}
	
		top++;
		stack[top]=c;
}	

char pop()
{
	if(top==-1)
	{printf("underflow condition");
		return '\0' ;}
		
		return stack[top];
		top--;
	}
	
	char peek()
{
	if(top==-1)
	{printf("underflow condition");
		return '0';}
	 return  stack[top];
	
	}
	
	int isEmpty()
	{
		if(top==-1)
		return 1;
		
		else 
		return 0;		
		
		}
	
		
		
	
