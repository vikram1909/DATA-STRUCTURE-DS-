#include<stdio.h>
typedef struct SortedLinkedList
{
    int info;
    struct SortedLinkedList *link;
}node;

node *create(node *head)
{
    node *newNode,*ptr=head;
    int data;
    newNode=(node*)malloc(sizeof(node));
    printf("\nEnter elements for node: ");
    scanf("%d",&data);
    newNode->info=data;
    if(head==NULL || ptr->info<data)
    {
         newNode->link=head;
         head=newNode;
    }
    else{
        while(ptr->link!=NULL && ptr->link->info>data)
        {
            ptr=ptr->link;
        }
        newNode->link=ptr->link;
        ptr->link=newNode;
    }
    return head;

}

void display(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->info);
        ptr=ptr->link;
    }
}

int main()
{
    node *head=NULL;
    int i,n;
    printf("Enter Number of node in the list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head=create(head);
    }
    printf("\nThese are the elements of sorted Linked List:\n");
    display(head);
}
