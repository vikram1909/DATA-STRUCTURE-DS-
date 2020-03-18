#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[50],i,ind,item,n;
	do
	{
		printf("\nEnter size of Array : ");
		scanf("%d",&n);
	}while(n<=0 || n>50);
	printf("\nEnter %d elements for array : \n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThese are the elements of array : \n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nEnter which number you want to delete from array : ");
	scanf("%d",&item);
	for(i=1;i<=n;i++)
	{
		if(a[i]==item)
		{
			ind=i;
			//exit(0);
		}
	}
	n=n-1;
	while(ind<=n)
	{
		a[ind]=a[ind+1];
		ind++;
	}
	printf("\nThese are the elements of array after deleting number : \n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}
