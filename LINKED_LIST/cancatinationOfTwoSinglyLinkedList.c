#include<stdio.h>
typedef struct concatLL
{
    int info;
    struct concatLL *link;
}node;
node *head1=NULL,*head2=NULL;
void createFirstList()
{
    node *ptr,*loc;
    ptr=(node*)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head1==NULL)
    {
        head1=ptr;
        ptr->link=NULL;
    }
    else
    {
        loc=head1;
        while(loc->link!=NULL)
        {
            loc=loc->link;
        }
        loc->link=ptr;
        ptr->link=NULL;
    }
}
void createSecondList()
{
    node *ptr,*loc;
    ptr=(node*)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head2==NULL)
    {
        head2=ptr;
        ptr->link=NULL;
    }
    else
    {
        loc=head2;
        while(loc->link!=NULL)
        {
             loc=loc->link;
        }
        loc->link=ptr;
        ptr->link=NULL;
    }
}
void traverseFirstList()
{
    node *ptr;
    ptr=head1;
    if(head1==NULL)
    {
        printf("\nFirst List is Empty:\n");
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
void traverseSecondList()
{
    node *ptr;
    ptr=head2;
    if(head2==NULL)
    {
        printf("\nFirst List is Empty:\n");
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
void concatinate()
{
    node *ptr,*last,*loc;
    ptr=head1;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    last=ptr;
    ptr=head2;
    while(ptr!=NULL)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->info=ptr->info;
        temp->link=NULL;
        last->link=temp;
        last=temp;
        last->link=NULL;
        loc=ptr;
        head2=head2->link;
        ptr=head2;
        free(loc);
    }
}
void main()
{
    int n,m,i;
    printf("\n\nEnter size of First List: ");
    scanf("%d",&n);
    printf("\n\nEnter %d elements for first List:\n",n);
    for(i=1;i<=n;i++)
    {
        createFirstList();
    }
    printf("\n\nThese are the Elements of First List:\n");
    traverseFirstList();
    printf("\n\nEnter size of Second List: ");
    scanf("%d",&m);
    printf("\nEnter %d elements for Second List:\n",m);
    for(i=1;i<=m;i++)
    {
        createSecondList();
    }
    printf("\n\nThese are the Elements of Second List:\n");
    traverseSecondList();
    printf("\n\nThese are the elements of list after concatinating both:\n");
    concatinate();
    traverseFirstList();
    printf("\n");
}
