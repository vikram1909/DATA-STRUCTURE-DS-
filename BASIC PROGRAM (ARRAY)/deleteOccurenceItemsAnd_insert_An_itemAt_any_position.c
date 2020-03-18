#include<stdio.h>
void main()
{
    int a[50],i,num,r,pos,j,t=0,n,m,item,ind,flag=0;
    do
    {
        printf("Enter size of array:- ");
        scanf("%d",&n);
    }while(n<=0 || n>50);
    printf("\nEnter %d elements for array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nThese are the elements of array:\n\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nEnter which element you want to delete: ");
    scanf("%d",&item);
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(item==a[i])
            {
                ind=i;
                for(i=ind;i<n-t;i++)
                {
                    a[i]=a[i+1];
                }
                t++;
            }
            else
            {
                flag=flag+1;
            }
        }
    }
    if(flag!=n*n)
    {
        printf("\nThese are the elements of array after delete:\n\n");
        for(i=0;i<n-t;i++)
        {
            printf("%d\t",a[i]);
        }
        num=n-t;
        r=num;
        printf("\nEnter a value that you want to insert: ");
        scanf("%d",&m);
        printf("\nEnter index number where you want to insert %d : ",m);
        scanf("%d",&pos);
        while(pos<=num)
        {
            a[num]=a[num-1];
            num--;
        }
        a[num]=m;
        r++;
        printf("\nThese are the elements of array after insert %d at index %d:\n\n",m,pos);
        for(i=0;i<r;i++)
        {
            printf("%d\t",a[i]);
        }
    }
    else
    {
        printf("\nEntered number does not exist in the Array Please enter existence number:\n");
    }
}

