#include<stdio.h>
#include <stdlib.h>
#define MAX 5 

int top=-1;
int A[MAX];


void push()
{	 
	int no;
	if(top == MAX-1)
	{
		printf("stack is full");
	}
	else
	{
		printf("\nEnter a number to be pushed ");
		scanf("%d",&no);
		top = top +1;
		A[top]=no;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("stack is already emplty");
	}
	else
	{
		printf("top element %d is popped from the stack ",A[top]);
		top = top-1;
	}
}


void display()
{
	
	int i;
	if(top == -1)
	{
		printf("stack is already emplty");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("\n%d",A[i]);
		}
	}
}



void main()
{
	int ch;
	while(1)
	{
		printf("\nEnter your choice ");
		printf("1.push 2.pop 3.display 4.quit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:	
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				exit(0);
				break;
				
			default :
				printf("wrong choice pls enter valid choice ");
				break;
				
		}	
	}
	
}
