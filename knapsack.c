#include<stdio.h>

void printArray(int a[],int n) 
{
  for (int i=n-1;i>=0;i--) 
  {
    printf("%d ",a[i]);
  }
  printf("\n");
}

void printArray1(float a[],int n) 
{
  for (int i=n-1;i>=0;i--) 
  {
    printf("%.2f ",a[i]);
  }
  printf("\n");
}

void insertionSort(int p[],int w[],float r[],int n) 
{
  for (int i=1;i<n;i++) 
  {
    int temp=r[i];
    int j=i-1;
    while (temp<r[j] && j>=0) 
    {
      	r[j+1]=r[j];
      	p[j+1]=p[j];
      	w[j+1]=w[j];
      	j--;
    }
    r[j+1]=temp;
  }
  printArray1(r,n);
  printArray(p,n);
  printArray(w,n);
}

void knapsack(int p[],int w[],int n,int m)
{
	float r[50],sum=0;
	int x[50],i,temp;
	for(i=0;i<n;i++)
		r[i]=(float)p[i]/(float)w[i];

	insertionSort(p,w,r,n);

	for(i=0;i<n;i++)
		x[i]=0;

	for(i=0;i<n;i++)
	{
		if(w[i]<=m)
		{
			x[i]=w[i];
			m=m-w[i];
			sum=sum+p[i];
		}
		else
		{
			temp=w[i];
			w[i]=w[i]-m;
			x[i]=temp-w[i];
			m=m-x[i];
			sum=sum+((float)p[i]*((float)x[i]/(float)temp));
		}

		if(m==0)
			break;
	}
	printf("Knapsack : ");
	for(i=0;i<n-1;i++)
		printf("%d ",x[i]);
	printf("\nTotal Profit : %.2f",sum);
	
}

int main()
{
	int p[50],w[50],m,n,i;
	printf("Enter the capacity of knapsack : ");
	scanf("%d",&m);
	printf("Enter the no of items : ");
	scanf("%d",&n);
	printf("Enter the profit array : ");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);

	printf("Enter the weight array : ");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	
	knapsack(p,w,n,m);
}