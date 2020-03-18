#include<stdio.h>
void main()
{
    int a[50],b[50],c[50],i,j,k,m,n;
    do
    {
        printf("\nEnter size of 1st Array: ");
        scanf("%d",&m);
    }while(m<=0 || m>50);
    printf("\nEnter %d elements for 1st Array:\n",m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
        printf("\nEnter size of 2nd Array: ");
        scanf("%d",&n);
    }while(n<=0 || n>50);
    printf("\nEnter %d elements for 2nd Array:\n",n);
    for(j=1;j<=n;j++)
    {
        scanf("%d",&b[j]);
    }
    printf("\nThese are the elements of 1st Array:\n\n");
    for(i=1;i<=m;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nThese are the elements of 2nd Array:\n\n");
    for(j=1;j<=n;j++)
    {
        printf("%d\t",b[j]);
    }
    i=1;j=1;k=1;
    while(i<=m && j<=n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k]=b[j];
            j++;
        }
        k++;
    }
    if(i>m)
    {
        while(j<=n)
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=m)
        {
            c[k]=a[i];
            i++;
            k++;
        }
    }
    printf("\nThese are the elements Array after Merging:\n\n");
    for(k=1;k<=m+n;k++)
    {
        printf("%d\t",c[k]);
    }
}


