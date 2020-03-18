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
void createNodeFromEnd()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=tail=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
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
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList Empty:");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->next;
        }

    }
}
void greatestNumber()
{
    node *ptr=head;
    int gr;
    if(head==NULL)
    {
        printf("\nList Empty:");
    }
    else
    {
        gr=head->info;
        while(ptr!=NULL)
        {
            if(gr<ptr->info)
            {
                gr=ptr->info;
            }
            ptr=ptr->next;
        }
    }
    printf("\n\nGreatest Number is: %d \n",gr);
}
void main()
{
    int i,n;
    printf("\nEnter size of List: ");
    scanf("%d",&n);
    printf("\nEnter %d Elements for List: \n",n);
    for(i=1;i<=n;i++)
    {
        createNodeFromEnd();
    }
    printf("\nThese are the Elements of List:\n");
    traversFromHead();
    greatestNumber();
}
