#include<stdio.h>
#include<stdlib.h>
typedef struct link_list
{
    int info;
    struct link_list *link;
}node;
node *head,*last;
void empty()
{
    head=last=NULL;
}
void create_list()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=last=ptr;
    }
    else
    {
        last->link=ptr;
        last=ptr;
    }
    ptr->link=NULL;
}
void travers()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->link;
    }
}
void insert_beg(int item)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    ptr->link=head;
    head=ptr;
    printf("\nThese are the elements of List after inserting at beggining:\n\n");
    travers();
}
void insert_end(int item)
{
    node *ptr,*loc;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        head=ptr;
        ptr->link=NULL;
    }
    else
    {
        loc=head;
        while(loc->link!=NULL)
        {
            loc=loc->link;
        }
        loc->link=ptr;
        ptr->link=NULL;
    }
    printf("\nThese are the elements of List after inserting at last:\n\n");
    travers();
}
node * search(int item)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->info==item)
            return(ptr);
        ptr=ptr->link;
    }
    return(NULL);
}
void insert_afterGivenItem(int item,int after)
{
    node *ptr,*loc;
    loc=search(after);
    if(loc==NULL)
    {
        printf("\nElement Not found:\n");
        exit(0);
    }
    else
    {
        ptr=(node*)malloc(sizeof(node));
        ptr->info=item;
        ptr->link=loc->link;
        loc->link=ptr;
    }
    printf("\nThese are the elements of list after deleting:\n\n");
    travers();
}
void insertBeforeGivenNode(int before,int item)
{
    node *ptr,*newnode,*loc;
    newnode=(node *)malloc(sizeof(node));
    newnode->info=item;
    if(head==NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL && ptr->info!=before)
        {
            loc=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL)
        {
            printf("\nGiven number is not presented in the list:\n");
        }
        else if(ptr==head)
        {
            newnode->link=ptr;
            head=newnode;
            printf("\nThese are the elements of list after deleting:\n\n");
            travers();
        }
        else
        {
            loc->link=newnode;
            newnode->link=ptr;
            printf("\nThese are the elements of list after deleting:\n\n");
            travers();
        }
    }
}
void main()
{
    int n,i,beg,end,choice,srch,after,numAfter,before,numBefore;
    node *r;
    char con;
    empty();
    printf("Enter size of list: ");
    scanf("%d",&n);
    printf("\nEnter %d elements for Link_list:\n",n);
    for(i=1;i<=n;i++)
    {
        create_list();
    }
    printf("\nThese are the elements of List:\n\n");
    travers();
    ab:
    printf("\n\nPress 1 for insert at beggining:\nPress 2 for insert at last:");
    printf("\nPress 3 for searching:\nPress 4 for insert after given number:\n");
    printf("\nEnter your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\nEnter Value for insert at beggining: ");
        scanf("%d",&beg);
        insert_beg(beg);
         a:
        printf("\nDo you want to continue ? (Y/N): ");
        con=getch();
        if(con == 'Y' || con == 'y')
        {
        //    printf("\nVikram\n");
            goto ab;
        }
        else if(con == 'N' || con == 'n')
        {
            //printf("\nSolty\n");
            break;
        }
        else
        {
            printf("\nEnvalid Entry....Please select only \"Y for Yes\" OR \"N for No\":\n");
            goto a;
        }
    case 2:
        printf("\nEnter Value for insert at last: ");
        scanf("%d",&end);
        insert_end(end);
         b:
        printf("\nDo you want to continue ? (Y/N): ");
        con=getch();
        if(con == 'Y' || con == 'y')
        {
        //    printf("\nVikram\n");
            goto ab;
        }
        else if(con == 'N' || con == 'n')
        {
            //printf("\nSolty\n");
            break;
        }
        else
        {
            printf("\nEnvalid Entry....Please select only \"Y for Yes\" OR \"N for No\":\n");
            goto b;
        }
    case 3:
        printf("\nEnter which number you want to search: ");
        scanf("%d",&srch);
        r=search(srch);
        if(r==NULL)
            printf("\nGiven Number does not exist in the List:");
        printf("\nthe %d number is founded:",r->info);
         c:
        printf("\nDo you want to continue ? (Y/N): ");
        con=getch();
        if(con == 'Y' || con == 'y')
        {
        //    printf("\nVikram\n");
            goto ab;
        }
        else if(con == 'N' || con == 'n')
        {
            //printf("\nSolty\n");
            break;
        }
        else
        {
            printf("\nEnvalid Entry....Please select only \"Y for Yes\" OR \"N for No\":\n");
            goto c;
        }
    case 4:
        printf("\nEnter that Number after that you want to inseret: ");
        scanf("%d",&after);
        printf("\nEnter that number which you want to inseret: ");
        scanf("%d",&numAfter);
        insert_afterGivenItem(numAfter,after);
        ent:
        printf("\nDo you want to continue ? (Y/N): ");
        con=getch();
        if(con == 'Y' || con == 'y')
        {
        //    printf("\nVikram\n");
            goto ab;
        }
        else if(con == 'N' || con == 'n')
        {
            //printf("\nSolty\n");
            break;
        }
        else
        {
            printf("\nEnvalid Entry....Please select only \"Y for Yes\" OR \"N for No\":\n");
            goto ent;
        }
   case 5:
        printf("\nEnter a Number before that you want to inseret newnode: ");
        scanf("%d",&before);
        printf("\nEnter that number which you want to inseret: ");
        scanf("%d",&numBefore);
        insertBeforeGivenNode(before,numBefore);
        sol:
        printf("\nDo you want to continue ? (Y/N): ");
        con=getch();
        if(con == 'Y' || con == 'y')
        {
        //    printf("\nVikram\n");
            goto ab;
        }
        else if(con == 'N' || con == 'n')
        {
            //printf("\nSolty\n");
            break;
        }
        else
        {
            printf("\nEnvalid Entry....Please select only \"Y for Yes\" OR \"N for No\":\n");
            goto sol;
        }
    default:
        printf("\nEnvalid Choice:\n");
        en:
        printf("\nDo you want to continue ? (Y/N): ");
        con=getch();
        if(con == 'Y' || con == 'y')
        {
            //printf("\nVikram\n");
            goto ab;
        }
        else if(con == 'N' || con == 'n')
        {
            //printf("\nSolty\n");
            break;
        }
        else
        {
            printf("\nEnvalid Entry....Please select only \"Y for Yes\" OR \"N for No\":\n");
            goto en;
        }
    }
}
