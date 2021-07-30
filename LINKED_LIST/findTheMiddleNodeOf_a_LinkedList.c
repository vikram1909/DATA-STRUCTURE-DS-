#include<stdio.h>
typedef struct MiddleNode
{
    int info;
    struct MiddleNode *next;
}node;
node *createNode(node *head)
{
    node *ptr,*temp;
    int data;
    ptr=(node*)malloc(sizeof(node));
    scanf("%d",&data);
    ptr->info=data;
    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->info=data;
        ptr->next=NULL;
    }
    return head;
}
void display(node *head)
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList is Empty:");
    }
    else
    {
        printf("\nThese are the elements of List\n");
        while(ptr!=NULL)
        {
            printf("%d  ",ptr->info);
            ptr=ptr->next;
        }
    }
}
int getMiddleNode(node *head)
{
    node *slow,*fast;
    slow=fast=head;
    if(head!=NULL)
    {

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->info;
    }
    else
        return -1;
}
int main()
{
    int n,i,mid;
    node *head=NULL;
    printf("Enter size of list: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the data for %d node:\n ",i+1);
        head=createNode(head);
    }
    //function for displaying the available node in list
    display(head);
    mid=getMiddleNode(head);
    if(mid!=-1)
    {
        printf("\n\nThis is the value of middle node of linked list:\n");
        printf("%d\n",mid);
    }
    else
        printf("\n\nList is Empty:\n");

}
