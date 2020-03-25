#include<stdio.h>
typedef struct CircularSLL
{
    int info;
    struct CircularSLL *link;
}node;
node *head,*locPrev;
int count=0;
void empty()
{
    head=NULL;
}
void createList()
{
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    scanf("%d",&ptr->info);
    if(head==NULL)
    {
        head=ptr;
        ptr->link=head;
    }
    else
    {
        temp=head;
        while(temp->link!=head)
        {
            temp=temp->link;
        }
        temp->link=ptr;
        ptr->link=head;
        temp=ptr;
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
            locPrev=ptr;
            ptr=ptr->link;
        }while(ptr!=head);
        locPrev=ptr;
        count=0;
        return(NULL);
    }
}
void deleteFirstNode()
{
    node *ptr,*temp;
    ptr=temp=head;
    if(head==NULL)
        printf("\nList is Empty:\n");
    else if(ptr->link==head&&head==ptr)
    {
        head=NULL;
        printf("\nThese are the Elements of List:\n");    //when only one node is available in the List.
        traverse();
    }
    else
    {
        while(temp->link!=head)
        {
            temp=temp->link;
        }
        head=ptr->link;
        temp->link=head;
        free(ptr);
        printf("\nThese are the Elements of List:\n");
        traverse();
    }
}
void deleteLastNode()
{
    node *ptr,*loc;
    ptr=head;
    if(head==NULL)
        printf("\nList is Empty:\n");
    else if(ptr->link==head&&ptr==head)
    {
        head=NULL;
        printf("\nThese are the Elements of List:\n");         //when only one node is available in the List.
        traverse();
    }
    else
    {
        while(ptr->link!=head)
        {
            loc=ptr;
            ptr=ptr->link;
        }
        loc->link=head;
        free(ptr);
        printf("\nThese are the Elements of List:\n");
        traverse();
    }
}
void deleteGivenNode(int item)
{
  node *loc,*temp;
  loc=search(item);
  if(loc==NULL)
      printf("\nNumber does not exits in the List:\n");
  else if(loc->link==head&&loc==head)
  {
        head=NULL;
        printf("\nNode is deleted;\n");                              //when only one node is available in the List.
        printf("\nThese are the Elements of List:\n");
        traverse();
  }
  else if(loc==head)
  {
        node *temp2=head;
        while(temp2->link!=head)
            temp2=temp2->link;
        head=loc->link;
        temp2->link=head;
        free(loc);
        printf("\nThese are the Elements of List:\n");
        traverse();
  }
  else if(loc->link==head)
  {
      locPrev->link=head;  //locPrev is globle node type Variable
      free(loc);
      printf("\nThese are the Elements of List:\n");
      traverse();
  }
  else
  {
      locPrev->link=loc->link;
      free(loc);
      printf("\nThese are the Elements of List:\n");
      traverse();
  }
}
void deleteAfterNode(int after)
{
    node *loc,*temp;
    loc=search(after);
    if(loc==NULL)
    {
        printf("\nNumber does not exist in the List:\n");
    }
    else if(loc->link==head)
    {
        printf("\nNo any node presented After given node:\n");
    }
    else
    {
        temp=loc->link;
        loc->link=temp->link;
        free(temp);
        printf("\nThese are the elements of List:\n");
        traverse();
    }
}
void deleteBeforeNode(int item)
{
    node *ptr,*temp1,*temp2;
    if(head==NULL)
    {
        printf("\nList is Empty:\n");
    }
    else
    {
        ptr=head;
        while(ptr->info!=item)
        {
            temp1=ptr;
            temp2=temp1;
            ptr=ptr->link;
        }
        if(ptr==head)
        {
            printf("\nNo any node presents Before given node:\n");
        }
        else if(temp1==temp2)
        {
            node *loc=head;
            while(loc->link!=head)
                loc=loc->link;
            head=ptr;
            loc->link=head;
            free(temp1);
            free(temp2);
            printf("\nThese are the elements of List:\n");
            traverse();
        }
        else
        {
            temp2->link=ptr;
            free(temp1);
            printf("\nThese are the elements of List:\n");
            traverse();
        }
    }
}
void main()
{
    int n,i,num,delNode,choice,after,before;
    char ch;
    node *r;
    empty();
    a:
    printf("\nPress 1 for create List:\nPress 2 for search node:\nPress 3 for Delete First node:");
    printf("\nPress 4 Delete Last node:\nPress 5 Delete given node:\nPress 6 for Delete after node:\nPress 7 for Delete brfore node:");
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
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 3:
            printf("\nDelete First Node");
            deleteFirstNode();
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 4:
            printf("\nDelete Last Node");
            deleteLastNode();
             printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 5:
            printf("\nEnter which node you want to Delete: ");
            scanf("%d",&delNode);
            deleteGivenNode(delNode);
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 6:
            printf("\nEnter After which number you want to delete: ");
            scanf("%d",&after);
            deleteAfterNode(after);
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
        case 7:
            printf("\nEnter After which number you want to delete: ");
            scanf("%d",&before);
            deleteBeforeNode(before);
            printf("\nDo you want to continue(Y/N):");
            ch=getch();
            if(ch=='Y'||ch=='y')
                goto a;
            else
                break;
            break;
    }
}
