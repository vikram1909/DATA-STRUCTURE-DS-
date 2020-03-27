#include<stdio.h>
typedef struct circularDLL
{
    struct circularDLL *prev;
    int info;
    struct circularDLL *next;
}node;
node *head,*tail;
int count=0;
void empty()
{
    head=tail=NULL;
}
void line()
{
    int i;
    printf("\n");
    for(i=1;i<=76;i++)
        printf("_");
    printf("\n\n");
}
void createList()
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=tail=ptr;
        ptr->prev=head;
        ptr->next=tail;
    }
    else
    {
         tail->next=ptr;
         ptr->prev=tail;
         tail=ptr;
         tail->next=head;
         head->prev=tail;
    }
}
void traverse()
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList empty:\n");
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
node * search(int item)
{
    node *ptr=head;
    if(head==NULL)
        printf("\nList is empty:\n");
    else
    {
        do
        {
            count++;
            if(ptr->info==item)
                return(ptr);
            ptr=ptr->next;
        }while(ptr!=head);
        count=0;
        return(NULL);
    }
}
void deleteFirstNode()
{
    node *ptr=head;
    if(head==NULL)
        printf("\nNo node Available:\n");
    else if(head==tail)
    {
        head=tail=NULL;
        free(ptr);
        printf("\nThese are the elements of List after deleting First node:\n\n");
        traverse();
    }
    else
    {
        head=ptr->next;
        head->prev=tail;
        tail->next=head;
        free(ptr);
        printf("\nThese are the elements of List after deleting First node:\n\n");
        traverse();
    }
}
void deleteLastNode()
{
    node *ptr;
    if(head==NULL)
        printf("\nNo node Available:\n");
    else if(head==tail)
    {
        head=tail=NULL;
        free(ptr);
        printf("\nThese are the elements of List after deleting Last node:\n\n");
        traverse();
    }
    else
    {
        ptr=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(ptr);
        printf("\nThese are the elements of List after deleting Last node:\n\n");
        traverse();
    }
}
void deleteGivenNode(int item)
{
    node *loc;
    loc=search(item);
    if(loc==NULL)
        printf("\nNumber does not found:\n");
    else if(head==tail)
    {
        head=tail=NULL;    //-> this condition will occur when only one node Available.
        free(loc);
        printf("\nList is empty after deleting given node.\n");
        printf("\nBecause only one node was presented in the List.\n");
    }
    else if(loc==head)
    {
        head=loc->next;
        head->prev=tail;
        tail->next=head;
        free(loc);
        printf("\nThese are the elements of List after deleting Given node:\n\n");
        traverse();
    }
    else if(loc==tail)
    {
         tail=loc->prev;
         tail->next=head;
         head->prev=tail;
         free(loc);
         printf("\nThese are the elements of List after deleting Given node:\n\n");
         traverse();
    }
    else
    {
        node *temp1,*temp2;
        temp1=loc->prev;
        temp2=loc->next;
        temp1->next=temp2;
        temp2->prev=temp1;
        free(loc);
        printf("\nThese are the elements of List after deleting Given node:\n\n");
        traverse();
    }
}
void deleteBeforeNode(int before)
{
    node *loc,*temp1,*temp2;
    loc=search(before);
    if(loc==NULL)
        printf("\nNumber does not found:\n");
    else if(loc==head)
        printf("\nNo any node available before given node:\n");
    else if(loc->prev==head)
    {
        temp1=loc->prev;
        head=loc;
        loc->prev=tail;
        tail->next=head;
        free(temp1);
        printf("\nThese are the elements of List after deleting Previous node:\n\n");
        traverse();
    }
    else
    {
        temp1=loc->prev;
        temp2=temp1->prev;
        temp2->next=loc;
        loc->prev=temp2;
        free(temp1);
        printf("\nThese are the elements of List after deleting Previous node:\n\n");
        traverse();
    }
}
void deleteAfterNode(int after)
{
    node *loc,*temp1,*temp2;
    loc=search(after);
    if(loc==NULL)
        printf("\nNumber does not found:\n");
    else if(loc==tail)
        printf("\nNo any node available After given node:\n");
    else if(loc->next==tail)
    {
        temp1=loc->next;
        tail=loc;
        tail->next=head;
        head->prev=tail;
        free(temp1);
        printf("\nThese are the elements of List after deleting node:\n\n");
        traverse();
    }
    else
    {
        temp1=loc->next;
        temp2=temp1->next;
        loc->next=temp2;
        temp2->prev=loc;
        free(temp1);
        printf("\nThese are the elements of List after deleting node:\n\n");
        traverse();
    }
}
void main()
{
    int n,i,num,given,before,after,choice;
    node *r;
    char ch;
    empty();
    a:
    printf("\nPress 1 for create List:\nPress 2 for search node:\nPress 3 for Delete First node:");
    printf("\nPress 4 Delete Last node:\nPress 5 Delete given node:\nPress 6 for Delete before node:\nPress 7 for Delete after node:");
    printf("\n\nEnter your choice: ");
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
            printf("\nThese are the elements of List:\n\n");
            traverse();
            line();
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
                printf("\nNumber does not exist:\n");
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
            line();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 3:
            deleteFirstNode();
            line();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 4:
            deleteLastNode();
            line();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 5:
            printf("\nEnter which numbrer you want to delete: ");
            scanf("%d",&given);
            deleteGivenNode(given);
            line();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 6:
            printf("\nEnter before which number you want to delete: ");
            scanf("%d",&before);
            deleteBeforeNode(before);
            line();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 7:
            printf("\nEnter after which number you want to delete: ");
            scanf("%d",&after);
            deleteAfterNode(after);
            line();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
    }
}
