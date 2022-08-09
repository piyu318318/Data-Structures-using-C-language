#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *link;
}*rear=NULL,*front=NULL;

void enqueue()
{
	int no;
	struct node *temp;
	temp = malloc(sizeof(struct node));
	printf("Enter a number to add in a queue");
	scanf("%d",&no);
	temp->data =no;
	temp->link = NULL;
	
	if(front == NULL && rear == NULL)
	{
		front = temp;
		rear=temp;
	}
	else
	{
		rear->link = temp;
		rear=temp;
	}

	

	
}

void dequeue()
{
	struct node *temp;
	if(front == NULL)
	{
		printf("queue is empty ");
	}
	else 
	{
		
		temp = front;
		front = temp->link;
		printf("%d element is deleted from the queue ",temp->data);
		free(temp);
	}
}

void display()
{
	struct node *q;
	q=front;
	if(front == NULL)
	{
		printf("\nqueue is empty ");
	}
	else
	{
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q= q->link;
		}
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("\nEnter your choice 1.insert 2.delete 3.display 4.quit");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				enqueue();
				break;
				
			case 2:
				dequeue();
				break;
			
			case 3:
				display();
				break;
				
			case 4:exit(1);
			
			default : 
				printf("\nwrong choice entered");
				break;
				
				
		}
	}
}
