#include<stdio.h>
void main()
{
	int a[50],b[50],i,j,m,n,p,temp;
	do
	{
		printf("Enter size of 1st array:- ");
		scanf("%d",&m);
	}while(m<=0 || m>50);
	printf("\nEnter %d elements for 1st array:-\n",m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	do
	{
		printf("Enter size of 2nd array:- ");
		scanf("%d",&n);
	}while(n<=0 || n>50);
	printf("\nEnter %d elements for 2nd array:-\n",n);
	for(j=1;j<=n;j++)
	{
		scanf("%d",&b[j]);
	}
	printf("\n\nThese are the element of 1st array:\n\n");
	for(i=1;i<=m;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n\nThese are the element of 2nd array:\n\n");
	for(j=1;j<=n;j++)
	{
		printf("%d\t",b[j]);
	}
	j=1;
	printf("\n\nThese are the elements of array after cancatinate :\n\n");
	for(i=1;i<=m+n;i++)
	{
		if(i>m)
		{
			a[i]=b[j];
			printf("%d\t",a[i]);
			j++;
		}
		else
		{
			printf("%d\t",a[i]);
		}
	}
}
