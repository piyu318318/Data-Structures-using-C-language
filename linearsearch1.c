#include<stdio.h>

void main()
{
	int i,key,n,arr[n],flag=1;
	
	printf("Enter how many element");
	scanf("%d",&n);
	
	printf("Enter arrray element :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}
	
	printf("Enter number to be searched :");
	scanf("%d",&key);
	
	for(i=0;i<n;i++)
	{
		if(arr[i] == key)
		{
			printf("%d element is found at place %d",key,i+1);
			flag=2;
			break;
		}	
	}

	
	
	if(flag == 2)
	{
		printf("%d element is found at place %d",key,i+1);
	}
	else
	{
		printf("%d element is not found",key);
	}

	
}
