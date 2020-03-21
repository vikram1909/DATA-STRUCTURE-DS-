#include<stdio.h>
typedef struct CircularDLL
{
    struct CircularDLL *prev;
    int info;
    struct CircularDLL *next;
}node;
node *head,*tail;
int count=0;
void empty()
{
    head=tail=NULL;
}
void createList()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=tail=ptr;
        ptr->prev=head;
        ptr->next=tail;
    }
    else
    {
        ptr->prev=tail;
        tail->next=ptr;
        ptr->next=head;
        tail=ptr;
        head->prev=tail;
    }
}
void traverse()
{
    node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("\nList is Empty:\n");
    }
    else
    {
        do
        {
            printf("%d\t",ptr->info);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
node *search(int item)
{
    node *ptr,*loc;
    ptr=head;
    if(head==NULL)
    {
        printf("\nList is empty:\n");
    }
    else
    {
        do
        {
            count++;
            if(ptr->info==item)
                return(ptr);
            ptr=ptr->next;
        }while(ptr->next!=head);
        count++;
        if(ptr->info==item)
                return(ptr);
        return(NULL);
    }
}
void insertAtBegining(int item)
{
    node *ptr;
    char ch;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        printf("\nList is empty:\nDo you want to insert:(Y/N): ");
        ch=getch();
        if(ch=='Y'||ch=='y')
        {
            head=ptr;
            ptr->prev=tail;
            ptr->next=head;
        }
        else
            exit(0);

    }
    else
    {
        ptr->next=head;
        head=ptr;
        tail->next=head;
        ptr->prev=tail;
    }
}
void insertAtEnding(int item)
{
    node *ptr;
    char ch;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        printf("\nList is empty:\nDo you want to insert:(Y/N): ");
        ch=getch();
        if(ch=='Y'||ch=='y')
        {
            head=ptr;
            ptr->prev=tail;
            ptr->next=head;
        }
        else
            exit(0);

    }
    else
    {
        tail->next=ptr;
        ptr->prev=tail;
        tail=ptr;
        ptr->next=head;
    }
}
void insertBeforeGivenNode(int before,int item)
{
    node *ptr,*loc;
    loc=search(before);
    if(loc==NULL)
    {
        printf("\nNumber does not exist int he List:\n");
    }
    else
    {
        ptr=(node*)malloc(sizeof(node));
        ptr->info=item;
        if(loc==head)
        {
            loc=ptr;
            ptr->prev=tail;
            ptr->next=head;
            loc->prev=ptr;
            head=ptr;
            tail->next=head;
            printf("\nThese are the elements of List:\n");
            traverse();
        }
        else
        {
            node *temp=loc->prev;
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=loc;
            loc->prev=ptr;
            printf("\nThese are the elements of List:\n");
            traverse();
        }
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
        ptr=(node*)malloc(sizeof(node));
        ptr->info=item;
        if(loc==tail)
        {
            loc->next=ptr;
            ptr->prev=loc;
            tail=ptr;
            ptr->next=head;
            head->prev=tail;
            printf("\nThese are the elements of List:\n");
            traverse();
        }
        else
        {
            node *temp=loc->next;
            ptr->next=temp;
            temp->prev=ptr;
            loc->next=ptr;
            ptr->prev=loc;
            printf("\nThese are the elements of List:\n");
            traverse();
        }
    }
}
void main()
{
    int n,i,num,beg,end,before,beforeNum,after,afterNum,choice;
    char ch;
    node *r;
    empty();
    a:
    printf("\nPress 1 for create List:\nPress 2 for search node:\nPress 3 for insert at begining:");
    printf("\nPress 4 for insert at ending:\nPress 5 for insert before node:\nPress 6 for insert after node:");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter size of List: ");
            scanf("%d",&n);
            printf("\nEnter %d elements for List:\n",n);
            for(i=1;i<=n;i++)
            {
                createList();
            }
            printf("\nThese are the elements of List:\n");
            traverse();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 2:
            printf("\nEnter which number you want to search: ");
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
        case 3:
            printf("\nEnter which number you want to insert at begining: ");
            scanf("%d",&beg);
            insertAtBegining(beg);
            printf("\nThese are the elements of List:\n");
            traverse();
            break;
        case 4:
            printf("\nEnter which number you want to insert at ending: ");
            scanf("%d",&end);
            insertAtEnding(end);
            printf("\nThese are the elements of List:\n");
            traverse();
            break;
        case 5:
            printf("\nEnter before which number you want to insert: ");
            scanf("%d",&before);
            printf("\nEnter which number you want to insert: ");
            scanf("%d",&beforeNum);
            insertBeforeGivenNode(before,beforeNum);
            break;
        case 6:

            printf("\nEnter After which number you want to insert: ");
            scanf("%d",&after);
            printf("\nEnter which number you want to insert: ");
            scanf("%d",&afterNum);
            insertAfterGivenNode(after,afterNum);
            break;
    }
}
