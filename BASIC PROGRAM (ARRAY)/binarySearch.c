#include<stdio.h>
#include<conio.h>
void main()
{
	int a[100],i,beg,end,mid,n,item;
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
	beg=1;
	end=n;
	mid=(beg+end)/2;
	printf("Enter which number you want to search :");
	scanf("%d",&item);
	printf("\n$********************************************$\n");
	while(beg<=end && a[mid]!=item)
	{
		if(item > a[mid])
		{
			beg=mid+1;
		}
		else
		{
			end=mid-1;
		}
		mid=(beg+end)/2;
	}
	if(a[mid]==item)
		printf("\nNumber %d is available in array at %d position.\n",item,mid);
	else
		printf("\nNumber %d is not available in array\n",item);
}
