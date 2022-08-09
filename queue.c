#include<stdio.h>
#include <stdlib.h>
#define max 5

int a[max];//array defined
int front =-1;
int rear =-1;

void enqueue()
{
	int no;
	if(rear == max-1)
	{
		printf("\nqueue is full :");
		return;
	}
	
	if(front == -1 )
	{
		front =0;
	}
	printf("enter a number to add in a queue :");
	scanf("%d",&no);
	
	rear = rear +1;
	a[rear]=no;
	
}

void dequeue()
{
	if(front == -1 || front > rear) 
	{
		printf("Queue is empty ");
		return;
	}
	else
	{
		printf("element %d  is deleted from the queue",a[front]);
		front = front+1;
	}
}

void display()
{
	int i;
	if(front ==-1 || front > rear)
	{
		printf("queue is empty ");
		return;
	}
	
	for(i=front ; i<= rear ;i++)
	{	
			printf("%d",a[i]);	
	} 
	
}


void main()
{
	int ch;
	
	while(1)
	{
		printf("\nEnter your choice 1.insert 2.delete 3.display 4.quit \n");
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
			case 4:
				exit(1);
			default :
				printf("wrong choice ");
		}
	}

}

