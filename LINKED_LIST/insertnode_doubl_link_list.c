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
void insertFromHead()
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=tail=ptr;
        ptr->prev=NULL;
        ptr->next=NULL;
    }
    else
    {
       ptr->prev=NULL;
       ptr->next=head;
       head->prev=ptr;
       head=ptr;
    }
}
void insertFromTail()
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
void traversFromHead()
{
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->next;
    }
}
void traversFromTail()
{
    node *ptr=tail;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->prev;
    }
}
node * search(int item)
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
            if(ptr->info==item)
            {
                return(ptr);
            }
            ptr=ptr->next;
        }
        return(NULL);
    }
}
void insertAfterNode(item,after)
{
    node *ptr,*loc;
    loc=search(after);
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    if(loc==NULL)
    {
        printf("\nNumber does not found:");
    }
    else if(loc->next==NULL)
    {

        loc->next=ptr;
        ptr->prev=loc;
        tail=ptr;
        ptr->next=NULL;
    }
    else
    {
        node *temp;
        temp=loc->next;
        ptr->next=temp;
        temp->prev=ptr;
        loc->next=ptr;
        ptr->prev=loc;

    }
}
void insertBeforeNode(item,before)
{
    node *ptr,*loc;
    loc=search(before);
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    if(loc==NULL)
    {
        printf("\nNumber does not found:");
    }
    else if(loc->prev==NULL)
    {

        loc->prev=ptr;
        ptr->next=loc;
        ptr->prev=NULL;
        head=ptr;
    }
    else
    {
        node *temp;
        temp=loc->prev;
        loc->prev=ptr;
        ptr->next=loc;
        ptr->prev=temp;
        temp->next=ptr;

    }
}
void main()
{
    int i,n,choice1,choice2,item,insAfter,after,before,insBefore;
    node *r;
    empty();
    printf("\nEnter size of List:");
    scanf("%d",&n);
    printf("\nPress 1 for Insert Form Head: \nPress 2 for Insert Form Tail: \n");
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:
            printf("\nEnter %d elements for List:\n",n);
            for(i=1;i<=n;i++)
            {
                insertFromHead();
            }
            printf("\nPress 1 for Traverse Form Head: \nPress 2 for Traverse Form Tail: \n");
            printf("\nEnter Your Choice: ");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                    printf("\nThese are the elements of List:\n");
                    traversFromHead();
                    break;
                case 2:
                    printf("\nThese are the elements of List:\n");
                    traversFromTail();
                    break;
            }
            printf("\nEnter Which number you want to search: ");
            scanf("%d",&item);
            r=search(item);
            if(r!=NULL)
            {
                printf("\nNumber found [ %d ]",r->info);
            }
            else
            {
                printf("\nNumber not found ");
            }
            printf("\nEnter the number after that item will be inserted: ");
            scanf("%d",&after);
            printf("\nEnter that number which you want to insert: ");
            scanf("%d",&insAfter);
            insertAfterNode(insAfter,after);
            printf("\nThese are the elements after insert:\n");
            traversFromHead();
            /**************************************/
            printf("\nEnter the number before that item will be inserted: ");
            scanf("%d",&before);
            printf("\nEnter that number which you want to insert: ");
            scanf("%d",&insBefore);
            insertBeforeNode(insBefore,before);
            printf("\nThese are the elements after insert:\n");
            traversFromHead();
            break;
        case 2:
            printf("\nEnter %d elements for List:\n",n);
            for(i=1;i<=n;i++)
            {
                insertFromTail();
            }
            printf("\nPress 1 for Traverse Form Head: \nPress 2 for Traverse Form Tail: \n");
            printf("\nEnter Your Choice: ");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                    printf("\nThese are the elements of List:\n");
                    traversFromHead();
                    break;
                case 2:
                    printf("\nThese are the elements of List:\n");
                    traversFromTail();
                    break;
            }
            printf("\nEnter Which number you want to search: ");
            scanf("%d",&item);
            r=search(item);
            if(r!=NULL)
            {
                printf("\nNumber found [ %d ]",r->info);
            }
            else
            {
                printf("\nNumber not found ");
            }
             printf("\nEnter the number after that item will be inserted: ");
            scanf("%d",&after);
            printf("\nEnter that number which you want to insert: ");
            scanf("%d",&insAfter);
            insertAfterNode(insAfter,after);
            printf("\nThese are the elements after insert:\n");
            traversFromHead();
            /**************************************/
            printf("\nEnter the number before that item will be inserted: ");
            scanf("%d",&before);
            printf("\nEnter that number which you want to insert: ");
            scanf("%d",&insBefore);
            insertBeforeNode(insBefore,before);
            printf("\nThese are the elements after insert:\n");
            traversFromHead();
            break;
    }
}
