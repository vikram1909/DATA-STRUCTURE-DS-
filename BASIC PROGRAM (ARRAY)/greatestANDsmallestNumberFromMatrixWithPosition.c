#include<stdio.h>
void main()
{
    int a[50][50],i,j,g,s,srow,scol,grow,gcol,r,c;
    printf("Enter size of Row: ");
    scanf("%d",&r);
    printf("\nEnter size of Collumn: ");
    scanf("%d",&c);
    printf("\nEnter Elements for (%d * %d) matrix:\n",r,c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nElements of (%d * %d) matrix :\n\n",r,c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n\n");
    }
    g=a[0][0];
    s=a[0][0];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(g < a[i][j])
            {
                g=a[i][j];
                grow=i;
                gcol=j;
            }
            if(s > a[i][j])
            {
                s=a[i][j];
                srow=i;
                scol=j;
            }
        }
    }
    printf("\nGREATEST=%d at POSITION=(%d,%d)\n",g,grow,gcol);
    printf("\nSMALLEST=%d at POSITION=(%d,%d)\n",s,srow,scol);
}
