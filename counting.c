#include<stdio.h>

void countingsort(int a[],int n,int k)
{
	int i,count[k-1],b[n];
	for(i=0;i<k;i++)
		count[i]=0;

	for(i=0;i<n;i++)
		count[a[i]]=count[a[i]]+1;

	for(i=1;i<k;i++)
		count[i]=count[i]+count[i-1];

	for(i=n-1;i>=0;i--)
	{
		count[a[i]]=count[a[i]]-1;
		b[count[a[i]]]=a[i];
	}

	for(i=0;i<n;i++)
		a[i]=b[i];
}

int main()
{
	int i,n,arr[30];
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	printf("Enter the elements of the array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	countingsort(arr,n,10);
	printf("Sorted array : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	return 0;
}