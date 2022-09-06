#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *link;
	int data ;
}*last=NULL;


void create(int);
void addatbeg(int);
void addatafter(int,int);
void display();
void search(int);
void count();
void deletedata(int);

void main()
{
	int ch;
	int no;
	int pos;
	
	while(1)
	{
		printf("\n*****Enter your choice*****");
		printf("\n1.create 2.addatabeginning 3.addatafter 4.display 5.search 6.count 7.deletedata  8.exit \n");
		scanf("%d",&ch);	
		switch(ch)
		{
			case 1:
					printf("Enter the data :");
					scanf("%d",&no);
					create(no);
					break;
			
			case 2:
					if(last == NULL)
					{
						printf("list is Empty");
						break;
					}
					printf("Enter the data :");
					scanf("%d",&no);
					addatbeg(no);
					break;
					
			case 3:
					if(last == NULL)
					{
						printf("list is Empty");
						break;
					}
					printf("Enter the position where you want to add data in between :");
					scanf("%d",&pos);
					printf("Enter the data :");
					scanf("%d",&no);
					addatafter(pos,no);
					break;
					
			case 4:
					if(last == NULL)
					{
						printf("list is Empty");
						break;
					}
					display();
					break;
					
			case 5:
					if(last == NULL)
					{
						printf("list is Empty");
						break;
					}
					printf("Enter the data to be searched :");
					scanf("%d",&no);
					search(no);
					break;
					
			case 6:
					if(last == NULL)
					{
						printf("list is Empty");
						break;
					}
					count();
					break;
					
			case 7:
					if(last == NULL)
					{
						printf("list is Empty");
						break;
					}
					printf("Enter the data to delete :");
					scanf("%d",&no);
					deletedata(no);
					break;
					
			case 8:
				exit(0);
		}	
	}
}

void create(int no)
{
	struct node *temp,*q;
	temp = malloc(sizeof(struct node));
	
	temp ->data =no;
//	temp ->link = NULL;
	
	if(last == NULL)//for first node only
	{
		temp ->link = temp;
		last = temp;
	}
	else
	{
		q=last;
		temp ->link  = last->link;
		last ->link = temp;
		last = temp;	
	}
}

void addatbeg(no)
{
	struct node *temp,*q;
	temp = malloc(sizeof(struct node));
	temp ->data =no;
	q=last->link;
	last -> link = temp;//connect last and the temp 
	temp -> link = q;//connect temp and old first node
}

void addatafter(int pos, int no)
{
	struct node *temp,*q=last->link;
	temp = malloc(sizeof(struct node));
	temp->data = no;
	
	int i=0;
	while(i<(pos-2))
	{
		q=q->link;
		i++;
	}
	
	q->link=temp;
	q->link = temp;
}

void display() //wrong logic 
{	
	struct node *q;
	q=last->link;
	
	while(q != last)//will print all ellements except last element
	{
		printf("%d ",q->data);
		q = q->link;
	}
	if(q ==  last)//will last print element
	{
		printf("%d ",q->data);	
	}
	
}

void search(int no)
{
	struct node *q=last->link;
	int pos = 0;
	int flag =0;//element found flag=1 else element is not in the list
	
	if(q->data == no)//will check first element in list 
	{
		flag=1;
		pos++;
		printf("\nEntered data found at position : %d"+ pos);
		return ;//will return from where it is called no need to search further elements 
	}
	else
	{
		pos++;//from 2nd element it will check so start count shoould be 1
		
		while(q->data != no)
		{
			if(q->data  == last->data)//even last element isnnt a element which we are seaching then break it.
			{
				break;
			}
			pos++;
			q = q->link;
		}
		if(q->data == no)
		{
			flag=1;
			printf("\nEntered data found at position : %d"+pos);
			return;//element is found no need to check flag so it will return from where it was called
		}	
	}
	
	if(flag == 0)
		printf("Entered data is not in the list ");
	
}

void count()
{
	struct node *q=last->link;
	int count =1;
	
	while(q != last)
	{
		count++;
		q=q->link;
	}
	
	printf("\nTotal elements in circular linkedlist is : %d",count);
		
}

void deletedata(no)
{
	struct node *temp,*q;
	q=last->link;
	
	//delete first element 
	if(q->data == no)
	{
		temp = q;
		last -> link = q->link;
		free(temp);
		printf("first element has been deleted");
		return ;//if first element == delete element no need to check further
	}
	
	//element in between
	while(q->link->data != no)
	{
		q=q->link;
	}
	if(q->link->data == no && q->link->data != last->data)//we dont delete last element here bzoz last node is connected to first  
	{	
		temp = q->link;
		q->link = temp ->link;
		free(temp);
		printf("data in between deleted ");
		return ;
	}
	
	//last element deleted
	
	while(q->link->data != last->data && q->link->data!= no)
	{
		q=q->link;
	}
	if( q->link->data == no)
	{
		temp = q->link;
		q->link = temp->link;
		free(temp);
		printf("last element has been deleted !");
		return;
	}
	
}
