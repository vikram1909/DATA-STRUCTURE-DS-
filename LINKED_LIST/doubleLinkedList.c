#include<stdio.h>
typedef struct dll
{
    struct dll *prev;
    int info;
    struct dll *next;
}node;
node *head,*tail;
void empty()
{
    head=tail=NULL;
}
void createNode()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        ptr->prev=ptr->next=NULL;
        head=tail=ptr;
    }
    else
    {
        ptr->next=NULL;
        ptr->prev=tail;
        tail->next=ptr;
        tail=ptr;

    }
}
void travers()
{
    node *ptr;
    if(head==NULL)
    {
        printf("\n List empty:");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->next;
        }
    }
}
void traversInvers()
{
    node *ptr;
    if(head==NULL)
    {
        printf("\n List empty:");
    }
    else
    {
        ptr=tail;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->prev;
        }
    }
}
void delete_beg()
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList empty:");
    }
    else if(head->next==NULL)
    {
        ptr=head;
        head=tail=NULL;
        free(ptr);
    }
    else
    {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
    }
}
void delete_end()
{
    node *ptr=tail;
    if(tail==NULL)
    {
        printf("\nList empty:");
    }
    else if(tail->prev==NULL)
    {
        ptr=tail;
        head=tail=NULL;
        free(ptr);
    }
    else
    {
        ptr=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(ptr);
    }
}
void main()
{
    int i,n,choice;
    empty();
    printf("\nEnter sizeof list: ");
    scanf("%d",&n);
    printf("\nEnter %d elements for list:\n",n);
    for(i=1.;i<=n;i++)
    {
        createNode();
    }
    printf("\nPress 1 for Travers:\n\nPress 2 for Travers in Reverse:\n\nPress 3 for delete first node:\n");
    printf("\nEnter Your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\nThese are the elements of list:\n\n");
        travers();
        break;
    case 2:
        printf("\n\nThese are the elements of list in revers:\n\n");
        traversInvers();
        break;
    case 3:
        printf("\n\nThese are the elements of list after deleting first node:\n\n");
        delete_beg();
        travers();
        break;
    case 4:
        printf("\n\nThese are the elements of list after deleting first node:\n\n");
        delete_end();
        travers();
    }
}
