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
void insertNodeAtEnd()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=tail=ptr;
        ptr->prev=NULL;
        ptr->next=NULL;
    }
    else
    {
        tail->next=ptr;
        ptr->prev=tail;
        ptr->next=NULL;
        tail=ptr;
    }
}
void traverse()
{
    node *ptr;
    if(head==NULL)
    {
        printf("\nList Empty:\n");
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
void deleteFirstNode()
{
    node *ptr;
    if(head==NULL)
    {
        printf("\nList empty:\n");
    }
    else
    {
        ptr=head;
        head=ptr->next;
        head->prev=NULL;
        free(ptr);
    }
}
void deleteLastNode()
{
    node *ptr;
    if(head==NULL)
    {
        printf("\nList empty:\n");
    }
    else
    {
        ptr=tail;
        tail=ptr->prev;
        tail->next=NULL;
        free(ptr);
    }
}
node *search(int item)
{
    node *ptr;
    if(head==NULL)
    {
        printf("\nList Empty: \n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->info==item)
            {
                return(ptr);
            }
            ptr=ptr->next;
        }
        return(NULL);
    }
}
void main()
{
    int n,i,choice,item;
    node *r;
    empty();
    printf("\nEnter size of List: ");
    scanf("%d",&n);
    printf("\nEnter %d elements for List: \n",n);
    for(i=1;i<=n;i++)
        insertNodeAtEnd();
    printf("\nThese are the elemenyts of List:\n");
    traverse();
    printf("\n\nPress 1 for delete First Node: \nPress 2 for delete Last node:");
    printf("\nPress 3 for Search Number:\n");
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            deleteFirstNode();
            printf("\nThese are the elemenyts of List after deleting First Node:\n");
            traverse();
            break;
        case 2:
            deleteLastNode();
            printf("\nThese are the elemenyts of List after deleting Last Node:\n");
            traverse();
            break;
        case 3:
            printf("\nEnter that number which you want to search: ");
            scanf("%d",&item);
            r=search(item);
            if(r==NULL)
                printf("\nNumber doea not exist in the List:\n");
            else
                printf("\nNumber %d Founded...\n",r->info);
    }
}
