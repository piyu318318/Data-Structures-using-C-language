#include<stdio.h>

void main()
{
	int mid,high,low,n,i,key;
	int arr[n];
	
	printf("Enter how many element you want");
	scanf("%d",&n);

	

	printf("Enter numbers for an array ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);		
	}
	
	printf("enter key to be seacrched ");
	scanf("%d",&key);
	
	
	low=0;
	high=n-1;
	mid= (low+high)/2;
	
	while(low<=high)
	{
		if(key<arr[mid])
		{
			high = mid-1;	
		}
		else if(key>arr[mid])
		{
			low = low +1;
		}
		else if(key == arr[mid])
		{
			printf("%d element found at position %d ",key,mid+1);
			break;
		}
		
		mid = (low+high)/2;
	}
	
	/*
	while(low<=high)
	{
		if(arr[mid]<key)
		{
			low = mid + 1;		
		}			
		else if(arr[mid] == key)
		{
			printf("%d element found at position %d",key,mid+1);
			break;
		}
		else 
		{
			high = mid-1;
		}
		
		mid = (low+high)/2;
		
		
	}
	*/
	
}
