#include<stdio.h>
int count=0;
typedef struct CLL
{
    int info;
    struct CLL *link;
}node;
node *head;
void empty()
{
    head=NULL;
}
void createCircular()
{
    node *ptr,*loc;
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=ptr;
        ptr->link=ptr;
    }
    else
    {
        loc=head;
        while(loc->link!=head)
        {
            loc=loc->link;
        }
        loc->link=ptr;
        ptr->link=head;
    }
}
void traverse()
{
    node *ptr;
    if(head==NULL)
    {
        printf("\nList is Empty:\n");
    }
    else
    {
        ptr=head;
        do
        {
            printf("%d\t",ptr->info);
            ptr=ptr->link;
        }while(ptr!=head);
    }
}
node * search(int item)
{
    node *ptr=head;
    while(ptr->link!=head)
    {
        count++;
        if(ptr->info==item)
            return(ptr);
        ptr=ptr->link;
    }
    return(NULL);
}
void insertAtBegining(int item)
{
    node *ptr,*loc;
    char ch;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        printf("\nList is Empty:\nDo you want to insert this node:(Y/N):");
        ch=getch();
        if(ch=='Y'||ch=='y')
        {
            head=ptr;
            ptr->link=head;
        }
        else
            exit(0);
    }
    else
    {
        loc=head;
        while(loc->link!=head)
        {
            loc=loc->link;
        }
        ptr->link=head;
        head=ptr;
        loc->link=head;
    }
}
void insertAtEnding(int item)
{
    node *ptr,*loc;
    char ch;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        printf("\nList is Empty:\nDo you want to insert this node:(Y/N):");
        ch=getch();
        if(ch=='Y'||ch=='y')
        {
            head=ptr;
            ptr->link=head;
        }
        else
            exit(0);
    }
    else
    {
        loc=head;
        while(loc->link!=head)
        {
            loc=loc->link;
        }
        loc->link=ptr;
        ptr->link=head;
    }
}
void insertAfterGivenNode(int after,int item)
{
    node *ptr,*loc;
    loc=search(after);
    if(loc==NULL)
    {
        printf("\nNumber does not exist in the List:\n");
    }
    else
    {
        ptr=(node *)malloc(sizeof(node));
        ptr->info=item;
        ptr->link=loc->link;
        loc->link=ptr;
    }
}
void main()
{
    int i,n,num,num2,num3,choice,after,afterNum;
    node *r;
    empty();
    printf("\nEnter size of list: ");
    scanf("%d",&n);
    printf("\nEnter %d elements for the list:\n",n);
    for(i=1;i<=n;i++)
    {
        createCircular();
    }
    printf("\nThese are the elements of list:\n");
    traverse();
    printf("\nPress 1 for insert at begining:\nPress 2 for insert at ending:");
    printf("\nPress 3 searching:\nPress 4 for insert after given node:");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\nEnter a number which you want to insert at begining: ");
        scanf("%d",&num2);
        insertAtBegining(num2);
        printf("\nThese are the elements of list:\n");
        traverse();
        break;
    case 2:
        printf("\nEnter a number which you want to insert at ending: ");
        scanf("%d",&num3);
        insertAtEnding(num3);
        printf("\nThese are the elements of list:\n");
        traverse();
        break;
    case 3:
        printf("\nEnter that number which you want to search: ");
        scanf("%d",&num);
        r=search(num);
        if(r==NULL)
        {
            printf("\nNumber does not exist:\n");
        }
        else
        {
            if(count==1)
                printf("\nNumber %d is founded at %dst possion:\n",r->info,count);
            else if(count==2)
                printf("\nNumber %d is founded at %dnd possion:\n",r->info,count);
            else if(count==3)
                printf("\nNumber %d is founded at %drd possion:\n",r->info,count);
            else
                printf("\nNumber %d is founded at %dth possion:\n",r->info,count);
        }
        break;
    case 4:
        printf("\nEnter after which number you want to insert a node: ");
        scanf("%d",&after);
        printf("\nEnter which number you want to insert: ");
        scanf("%d",&afterNum);
        insertAfterGivenNode(after,afterNum);
        printf("\nThese are the elements of list:\n");
        traverse();
        break;
    }
}
