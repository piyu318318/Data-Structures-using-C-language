#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*start;

void createlist(int);
void addatbeg(int);
void del(int);
void count();
void display();
void search(int);
void rev();

void main()
{
	int ch,i,n,m;
	
	
	start =NULL;
	
	while(1)
	{
		printf("\n1.create list 2.add at begining 3.delete 4.count 5.display 6.search 7.reverse 8.Quit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					printf("enter the element :");
					scanf("%d",&m);
					createlist(m);
					
				
				break;
		
			case 2:
				printf("Enter the element to add at the beginning :");
				scanf("%d",&m);
				addatbeg(m);
				break;
				
			case 3:
				if(start == NULL)
				{
					printf("Linkedlist is already empty and you are fool trying to delete an element");
				}
				else
				{
					printf("Enter the element to delete the element of linkedlist :");
					scanf("%d",&m);
					del(m);	
				}
				break;
				
			case 4:
				if(start == NULL)
					printf("Linkedlist is empty brother !!!");
				else
				{
					count();
				}
					
				break;
				
			case 5:
				if(start == NULL )
					printf("Linkedlist is already empty broda!!");
				else				
					display();
					
				break;
	
				
			case 6:
				if(start == NULL)
				{
					printf("Linkedlist is already empty and you are fool trying to delete an element");
				}				
				else
				{
					printf("Enter the element to search in the linkedlist :");
					scanf("%d",&m);
					search(m);
				}
				break;
				
			case 7:
				if(start == NULL)
					printf("emplty linkedlist");
				else
					rev();
				break;
					
			case 8:exit(1);
		}
		
			

	}
}


void createlist(int no)
{
	
	struct node *temp,*q;
	temp= malloc(sizeof(struct node));
	temp->data=no;
	temp->link=NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		q=start;
			while(q->link != NULL)
			{
				q=q->link;
			}
		q->link=temp;
	}
	
}

void addatbeg(int no)
{	
	struct node *temp;
	temp=malloc(sizeof(struct node));
	temp->data=no;
	temp->link=start;
	temp=start;
	
}


void del(int no)
{
	struct node *temp,*q;
	
	//if we want to delete first element in the linkedlist 
	if(start -> data == no)
	{
		temp=start;
		printf("%d element is deleted from the linkedlist : ",start->data);
		start = start->link;				
		free(temp);
		return;
	}
	
	
	//if we want to delete element betwenn the linkedlist 
	q=start;
	
	while(q->link->link != NULL)
	{
		if(q->link->data == no )
		{
			temp = q->link;
			q -> link = temp -> link;
			free(temp);
			return;
			
		}
		q=q->link;
	}
	
	
	//if we want to delete last elemnt of the linkedlist 
	
	if(q->link->data == no)
	{	
		temp=q->link;
		free(temp);
		printf("%d element deleted from the linkedlist ",q->link->data);
		q->link =NULL;
		
		return;
		
	}
}

void count(int no)
{
	struct node *q=start;
	int cnt=0;
	
	
	while(q!= NULL)
	{
		q=q->link;
		cnt++;
	}
	
	printf("count of a elements in linkedlist is %d:",cnt);
			
}

void display()
{
	struct node *q;
	q=start;
	
	while(q->link !=NULL)
	{
		printf("%d ",q->data);
		q=q->link;
	}
	printf("%d ",q->data);
}

void search(int no)
{
	struct node *q=start;
	int pos=1;

	
	while(q != NULL)
	{
		if(q->data == no)
		{
			printf("%d element found at position %d",q->data,pos);
			return;
		}
		
		q=q->link;
		pos++;
		
	}
}



 void rev()
  {
    struct node *p1,*p2,*p3;
    if(start->link==NULL)
      return;    //list containing only one node
    p1=start;
    p2=p1->link;
    p3=p2->link;
     p1->link=NULL;
     p2->link=p1;
      while(p3!=NULL)
      {
	    p1=p2;
	    p2=p3;
	    p3=p3->link;
	    p2->link=p1;
      }
    start=p2;
  }
  
  
  
  
/*
void rev()
{
	struct node *prev,*curr,*next;
	
	prev = start;
	curr = prev->link;
	next = curr->link;
	
	prev->link=NULL;
	curr->data=prev;
}

*/
