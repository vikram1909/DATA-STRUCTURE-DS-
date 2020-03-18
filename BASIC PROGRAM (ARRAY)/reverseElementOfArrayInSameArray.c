#include<stdio.h>
#include<conio.h>
void main()
{
	int a[100],n,i,j,temp,mid;
	do
	{
		printf("Enter size of Array :");
		scanf("%d",&n);
	}while(n<0 || n>100);
	printf("\nEnter %d elements for Array :\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	mid=(1+n)/2;
	j=n;
	printf("\n$********************************************$\n");
	printf("\nElements of Array in reverse :\n\n");
	for(i=1;i<=n;i++)
	{	
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			j--;
		if(i==mid)
		{
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}
