#include<stdio.h>
#define max 5

int stack[max];
int top=-1;

void push()
{
		if(top==max-1)
		{printf("overflow condition");
		return;}
		
		int num;
		printf("enter the new element:");
		scanf("%d",&num);
		top++;
		stack[top]=num;
}

void pop()
{
	if(top==-1)
	{printf("underflow condition");
		return ;}
		
		printf("element popped:%d",stack[top]);
		top--;
	}
	
void peek()
{
	if(top==-1)
	{printf("underflow condition");
		return ;}
	printf("the element at the top position:%d",stack[top]);
	
	}
	
void display()
{
	if(top==-1)
	{printf("underflow condition");
		return ;}
		
		int i;
		
		for(i=top;i>=0;i--)
		{
			printf("%d ",stack[i]);
			}
	}

int main()
{
	int choice;
	
	while(1)
	{
		printf("\nenter your choice:\n");
		printf("\n1.push\t2.pop\t3.peek\t4.display\t5.exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
				case 1:
				push();
				break;
				
				case 2:
				pop();
				break;
				
				case 3:
				peek();
				break;
				
				case 4:
				display();
				break;
				
				case 5:
				return 0;
				break;
				
				default:
				printf("enter a valid choice please");
				break;
				
				
		}
		
		
	}
	}
