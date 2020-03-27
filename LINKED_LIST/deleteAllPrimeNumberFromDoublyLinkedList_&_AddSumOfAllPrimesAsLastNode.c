/*Ques:- delete all prime numbers from List and ADD sum of
all prime numbers at last node in the List.*/
#include<stdio.h>
typedef struct Del_Prime
{
    struct Del_Prime *prev;
    int info;
    struct Del_Prime *next;
}node;
node *head,*tail;
int sum=0;
void empty()
{
    head=tail=NULL;
}
int prime(int item)
{
    int i,f=0;
    for(i=2;i<=item/2;i++)
    {
        if(item%i==0)
        {
            f=1;
            break;
        }
    }
    if(f==0)
        return 1;
    else
        return 0;
}
void createList()
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
    ptr=head;
    if(head==NULL)
        printf("List Empty:\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->next;
        }
    }
}
void delPrime()
{
    node *ptr;
    int loc;
    ptr=head;
    if(head==NULL)
        printf("\nList empty:\n");
    else
    {
        while(ptr!=NULL)
        {
            loc=ptr->info;
            if(prime(loc))
            {
                printf("%d\t",loc);
                sum=sum+loc;
                if(head==tail)
                {
                    head=tail=NULL;
                    free(ptr);
                }
                else if(ptr==head)
                {
                    head=ptr->next;
                    head->prev=NULL;
                    free(ptr);
                }
                else if(ptr==tail)
                {
                    tail=ptr->prev;
                    tail->next=NULL;
                    free(ptr);
                }
                else
                {
                    node *temp1,*temp2;
                    temp1=ptr->prev;
                    temp2=ptr->next;
                    temp1->next=temp2;
                    temp2->prev=temp1;
                    free(ptr);
                }
                ptr=ptr->next;
            }
            else
                ptr=ptr->next;
        }
    }
}
void addSum(int item)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
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
        tail=ptr;
        ptr->next=NULL;
    }
}
void main()
{
    int i,n;
    printf("\nEnter size of List: ");
    scanf("%d",&n);
    printf("\nEnter %d elements for List:\n",n);
    for(i=1;i<=n;i++)
    {
        createList();
    }
    printf("\nThese are the elements of List:\n\n");
    traverse();
    printf("\n\nThese are prime numbers:\n");
    delPrime();
    if(sum==0)
        printf("\n\nNo any prime number is available in the List:\n");
    else
    {
        printf("\n\nSum of All prime numbers is: %d\n",sum);
        printf("\nThese are the elements of List after deleting all prime numbers:\n\n");
        traverse();
        printf("\n\nThese are the elements After Adding sum of prime numbers as a last node:\n\n");
        addSum(sum);
        traverse();
    }
}
