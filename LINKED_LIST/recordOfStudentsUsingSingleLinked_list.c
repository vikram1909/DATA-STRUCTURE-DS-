#include<stdio.h>
typedef struct record
{
    int roll;
    char name[10];
    char add[10];
    int marks;
    struct record *link;
}node;
node *head,*last;
void empty()
{
    head=last=NULL;
}
void insertRecord()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    printf("\nEnter your roll: ");
    scanf("%d",&ptr->roll);
    printf("\nEnter your Name: ");
    scanf("%s",ptr->name);
    printf("\nEnter your Address: ");
    scanf("%s",ptr->add);
    printf("\nEnter your Marks: ");
    scanf("%d",&ptr->marks);
    if(head==NULL)
    {
        head=last=ptr;
        ptr->link=NULL;
    }
    else
    {
        last->link=ptr;
        last=ptr;
        ptr->link=NULL;
    }
}
void Show()
{
    node *ptr=head;
    if(head==NULL)
    {
        printf("\nList Empty:\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t%s\t%s\t%d\n",ptr->roll,ptr->name,ptr->add,ptr->marks);
            ptr=ptr->link;
        }
    }
}
node *search(int item)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->roll==item)
        {
            return(ptr);
        }
        else
        {
            ptr=ptr->link;
        }
    }
    return(NULL);
}
void main()
{
    int i,n,item;
    node *r;
    printf("\nEnter how many record you want to insert:\n");
    scanf("%d",&n);
    printf("\nEnter %d record:\n",n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter record of %d Student\n",i);
        insertRecord();
    }
    printf("\nRoll\tName\tAddress\tMarks\n");
    Show();
    printf("\nEnter Roll no. whose record you want to search: ");
    scanf("%d",&item);
    r=search(item);
    if(r==NULL)
        printf("\nNo record found:\n");
    else
    {
        printf("\nRoll\tName\tAddress\tMarks\n");
        printf("%d\t%s\t%s\t%d\n",r->roll,r->name,r->add,r->marks);
    }
}
