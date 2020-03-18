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
void deleteFirstNode()
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList empty:\n");
    }
    else
    {
        head=head->link;
        free(ptr);
    }
}
void deleteLastNode()
{
    node *ptr,*loc;
    if(head==NULL)
        printf("\nList empty:\n");
    else
    {
        loc=head;
        ptr=head->link;
        while(ptr->link!=NULL)
        {
            loc=ptr;
            ptr=ptr->link;
        }
        loc->link=NULL;
        free(ptr);
    }
}
node *search(int item)
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
void deleteAfterGivenNode(int after)
{
    node *ptr,*loc;
    loc=search(after);
    if(loc==NULL)
    {
        printf("\nItem does not exist:\n");
    }
    else if(loc->link==NULL)
    {
        printf("\nNO any node available after given node:\n");
    }
    else
    {
        ptr=loc->link;
        loc->link=ptr->link;
        free(ptr);
    }
}
void deleteGivenNumber(int num)
{
    node *ptr=head,*loc,*temp;
    if(head->info==num)
    {
        head=ptr->link;
        free(ptr);
    }
    else
    {
        loc=head;
        while(ptr->info!=num)
        {
            loc=ptr;
            ptr=ptr->link;
        }
        if(ptr->link==NULL)
        {
            loc->link=NULL;
            free(ptr);
        }
        else
        {
            temp=ptr->link;
            loc->link=temp;
            free(ptr);
        }
    }
}
void main()
{
    int n,i,item,choice,num;
    char ch;
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
    a:
    printf("\nPress 1 for delete First Node: ");
    printf("\nPress 2 for delete Last Node: ");
    printf("\nPress 3 for delete Aftr given Node: ");
    printf("\nPress 4 for delete given Number:\n");
    printf("\nEnter Your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        deleteFirstNode();
        printf("\nThese are the elements of List after deleting First Node:\n\n");
        travers();
        m:
        printf("\nDo you want to continue(Y/N):");
        ch=getch();
        if(ch=='Y'||ch=='y')
            goto a;
        else if(ch=='N'||ch=='n')
            break;
        else
        {
            printf("\n\nInvalid choice..Please press either 'Y' or 'N'.");
            goto m;
        }
    case 2:
        deleteLastNode();
        printf("\nThese are the elements of List after deleting last Node:\n\n");
        travers();
         n:
        printf("\nDo you want to continue(Y/N):");
        ch=getch();
        if(ch=='Y'||ch=='y')
            goto a;
        else if(ch=='N'||ch=='n')
            break;
        else
        {
            printf("\n\nInvalid choice..Please press either 'Y' or 'N'.");
            goto n;
        }
    case 3:
        printf("\nEnter after which number you want to delete:\n\n");
        scanf("%d",&item);
        deleteAfterGivenNode(item);
        printf("\nThese are the elements of List after deleting :\n\n");
        travers();
         o:
        printf("\nDo you want to continue(Y/N):");
        ch=getch();
        if(ch=='Y'||ch=='y')
            goto a;
        else if(ch=='N'||ch=='n')
            break;
        else
        {
            printf("\n\nInvalid choice..Please press either 'Y' or 'N'.");
            goto o;
        }
    case 4:
        printf("\nEnter  which number you want to delete: ");
        scanf("%d",&num);
        deleteGivenNumber(num);
        printf("\nThese are the elements of List after deleting :\n\n");
        travers();
         p:
        printf("\nDo you want to continue(Y/N):");
        ch=getch();
        if(ch=='Y'||ch=='y')
            goto a;
        else if(ch=='N'||ch=='n')
            break;
        else
        {
            printf("\n\nInvalid choice..Please press either 'Y' or 'N'.");
            goto p;
        }
    default :
        printf("\n\nInvalid choice..Please press only between 1 to 4.\n");
        goto a;
    }
}
