#include<stdio.h>
void main()
{
	int a[100],i,ind,item,n;
	do
	{
		printf("Enter size of Array :");
		scanf("%d",&n);
	}while(n<=0 || n>100);
	printf("\nEnter %d elements for array :-\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("These are the elements of array :-\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nEnter item which you want to insert in Array : ");
	scanf("%d",&item);
	printf("\nEnter position where you want to insert the item : ");
	scanf("%d",&ind);
	i=n;
	while(i>=ind)
	{
		a[i+1]=a[i];
		i--;
	}
	a[ind]=item;
	n=n+1;
	printf("\nThese are the elements after inserting item in array :-\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}
