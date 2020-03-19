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
void deleteAfterGivenNode(int after)
{
    node *loc,*ptr,*temp;
    ptr=head;
    if(head==NULL)
    {
        printf("\nList is Empty:\n");
    }
    else
    {
        do
        {
            loc=ptr;
            ptr=ptr->next;
        }while(loc->info!=after);
        if(loc==tail)
        {
            printf("\nNo node exist after given number:\n");
        }
        else
        {
            temp=ptr->next;
            loc->next=temp;
            temp->prev=loc;
            free(ptr);
            printf("\nThese are the elements of List after deleting node:\n");
            traverse();
        }
    }
}
void deleteBeforeGivenNode(int before)
{
    node *loc,*temp1,*temp2;
    loc=search(before);
    if(loc==NULL)
    {
        printf("\nGiven number is not presented in list:\n");
    }
    else if(loc->prev==NULL)
    {
        printf("\nNo any node presents before given node:\n");
    }
    else if(loc->prev==head)
    {
        head=loc;
        free(loc->prev);
        loc->prev=NULL;
        printf("\nThese are the elements of List after deleting node:\n");
        traverse();
    }
    else
    {
        temp1=loc->prev;
        temp2=temp1->prev;
        temp2->next=loc;
        loc->prev=temp2;
        free(temp1);
        printf("\nThese are the elements of List after deleting node:\n");
        traverse();
    }
}
void deleteGivenNode(int given)
{
    node *loc,*temp1,*temp2;
    loc=search(given);
    if(loc==NULL)
    {
        printf("\nGiven number is not presented in list:\n");
    }
    else if(loc==head)
    {
        head=loc->next;
        head->prev=NULL;
        free(loc);
        printf("\nThese are the elements of List after deleting given node:\n");
        traverse();
    }
    else
    {
        temp1=loc->prev;
        temp2=loc->next;
        temp1->next=temp2;
        temp2->prev=temp1;
        free(loc);
        printf("\nThese are the elements of List after deleting given node:\n");
        traverse();
    }
}
void main()
{
    int n,i,choice,item,after,before,given;
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
            break;
        case 4:
            printf("\nEnter number after that you want to delete: ");
            scanf("%d",&after);
            deleteAfterGivenNode(after);
            break;
        case 5:
            printf("\nEnter number before that you want to delete: ");
            scanf("%d",&before);
            deleteBeforeGivenNode(before);
            break;
        case 6:
            printf("\nEnter number that you want to delete: ");
            scanf("%d",&given);
            deleteGivenNode(given);
            break;
    }
}
