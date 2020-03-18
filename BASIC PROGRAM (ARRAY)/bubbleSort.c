#include<stdio.h>
void main()
{
    int a[50],i,p,temp,m;
    do
    {
        printf("\nEnter size of  Array: ");
        scanf("%d",&m);
    }while(m<=0 || m>50);
    printf("\nEnter %d elements for Array:\n",m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
printf("\n\nThese are the sorted elements of array:\n\n");
	for(p=1;p<=m-1;p++)
    {
        for(i=1;i<=m-p;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }

        }
    }
    for(i=1;i<=m;i++)
	{
		printf("%d\t",a[i]);
	}
}
