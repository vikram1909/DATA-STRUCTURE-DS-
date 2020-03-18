#include<stdio.h>
typedef struct PQ
{
    int data;
    int prio;
    struct PQ *link;
}node;
node *head;
void empty()
{
    head=NULL;
}
void heading()
{
    printf("\nData\tPriority\n");
}
void createQueue()
{
    node *ptr,*loc,*temp;
    ptr=(node *)malloc(sizeof(node));
    printf("\nData: ");
    scanf("%d",&ptr->data);
    printf("\nPriority: ");
    scanf("%d",&ptr->prio);
    if(head==NULL)
    {
        head=ptr;
        ptr->link=NULL;
    }
    else
    {
        loc=head;
        while(loc->prio <= ptr->prio && loc->link!=NULL)
        {
            temp=loc;
            loc=loc->link;
        }
        if(loc->prio>ptr->prio)
        {
            if(head==loc)
            {
                ptr->link=loc;
                head=loc=ptr;
                //temp->link=ptr;
            }
            else
            {
                temp->link=ptr;
                ptr->link=loc;
            }

        }
        else
        {
            loc->link=ptr;
            loc=ptr;
            ptr->link=NULL;
        }
    }
    printf("\nNode inserted Successfully:\n");
}
void insertNode(int data,int pr)
{
    node *ptr,*loc,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    ptr->prio=pr;
    //ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
        ptr->link=NULL;
    }
    else
    {
        loc=head;
        while(loc->prio <= ptr->prio && loc->link!=NULL)
        {
            temp=loc;
            loc=loc->link;
        }
        if(loc->prio>ptr->prio)
        {
            if(head==loc)
            {
                ptr->link=loc;
                head=loc=ptr;
                //temp->link=ptr;
            }
            else
            {
                temp->link=ptr;
                ptr->link=loc;
            }
        }
        else
        {
            loc->link=ptr;
            temp=loc;
            loc=ptr;
            ptr->link=NULL;
        }
    }
}
void traverse()
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nQueue is Empty:\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t%d\n",ptr->data,ptr->prio);
            ptr=ptr->link;
        }
    }
}
void main()
{
    int data,pr,choice;
    char ch;
    empty();
    printf("\nEnter element for Queue:\n");
    a:
    createQueue();
    printf("\nDo you want insert more node(Y/N): ");
    ch=getch();
    if(ch=='Y'||ch=='y')
        goto a;
    printf("\nThese are the data of Queue:\n");
    heading();
    traverse();
    printf("\nPress 1 for create Queue:\n");
    printf("\nPress 2 for insert new node in Queue:\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter Data for New node:\n");
            b:
            printf("\ndata: ");
            scanf("%d",&data);
            printf("\nPriority: ");
            scanf("%d",&pr);
            insertNode(data,pr);
            printf("\nDo you want insert more node(Y/N): ");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto b;
            printf("\nThese are the data of Queue after inserting some new node:\n");
            heading();
            traverse();
            break;
    }
}
