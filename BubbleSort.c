#include<stdio.h>

//void bubblesort(int,int);

void main()
{
	int n,no,i;
	int arr[n];
	
	printf("How Many elements : ");
	scanf("%d",&n);
	
	printf("Enter array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&no);
	}
	
	bubblesort(arr,n);
	
	for(i=0;i<n;i++)
	{
		printf("% 5d ",arr[i]);
	}
}

void bubblesort(int arr[],int n)
{
	int temp;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;i<n-i-1;i++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];	
				arr[j]= arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	

}
