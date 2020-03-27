#include<stdio.h>
typedef struct LinkList
{
    int info;
    struct LinkList *link;
}node;
node *head,*last;
void empty()
{
    head=last=NULL;
}
void createNode()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=last=ptr;
        ptr->link=NULL;
    }
    else
    {
        last->link=ptr;
        ptr->link=NULL;
        last=ptr;
    }
}
void traverse()
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList Empty:");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->link;
        }
    }
}
void deletePrimeNumbers()
{
    int i,f=0;
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList Empty:");
    }
    else
    {
        while(ptr!=NULL)
        {
            for(i=2;i<=ptr->info;i++)
            {
                if(ptr->info%i==0)
                {
                    f++;
                }
            }
            if(f==1)
            {
                printf("%d\t",ptr->info);
            }
            ptr=ptr->link;
            f=0;
        }
    }
}
void main()
{
    int i,n;
    printf("\nEnter size of Link: ");
    scanf("%d",&n);
    printf("\nEnter %d elements for list:\n",n);
    for(i=1;i<=n;i++)
        createNode();
    printf("\nThese are the elements of the list:\n\n");
    traverse();
    printf("\nThese are the prime Numbers:\n\n");
    deletePrimeNumbers();
}
