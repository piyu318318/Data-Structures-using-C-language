#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*top=NULL;

void main()
{
	int ch;
	abc:
	while(1)
	{
		YES:
		printf("\nEnter your choice : 1: push  2: pop 3: display 4: quit\n");
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
				
			default :
				printf("wrong choice chosen :");
				break;
		}
	}
}



void push()
{
	struct node *temp;
	int no;
	temp = malloc(sizeof(struct node));
	printf("Enter a number to pushed in a dyanamic stack :");
	scanf("%d",&no);
	temp -> link =top;
	temp -> data =no;
	top=temp;
	
}


void pop()
{
	struct node *temp;
	if(top == NULL)
	{
		printf("stack is empty");
	}
	temp = top;
	printf("%d element has been popped from dyanamic stack :",temp->data);
	top=top->link;	
	free(temp);

	
}


void display()
{
	struct node *q;
	q=top;
	if(top == NULL)
	{
		printf("stack is empty \n");
		goto abc;
	}
	
	
	while(q->link !=NULL)
	{
		printf("\n%d",q->data);
		q=q->link;	
	}	
	printf("\n%d",q->data);
	

					
}
