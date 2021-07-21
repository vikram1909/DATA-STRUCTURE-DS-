#include<stdio.h>

typedef struct polynomial
{
    float coffie;
    int expo;
    struct polynomial *link;
}node;

node *create(node *head,float cof,int exp)
{
    node *ptr=head,*newNode;
    newNode=(node*)malloc(sizeof(node));
    newNode->coffie=cof;
    newNode->expo=exp;
    newNode->link=NULL;
    if(head==NULL || head->expo<exp)
    {
        newNode->link=head;
        head=newNode;
    }
    else{
        while(ptr->link!=NULL && ptr->link->expo>exp)
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
        printf("%.0fx^%d",ptr->coffie,ptr->expo);
        ptr=ptr->link;
        if(ptr!=NULL)
            printf(" + ");
        else
            printf("\n");
    }
}

int main()
{
    node *head=NULL;
    int i,n,exp;
    float coffie;
    printf("Enter Number of Terms for Polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter cofficient for %d term: ",i+1);
        scanf("%f",&coffie);
        printf("\nEnter exponent for %d term: ",i+1);
        scanf("%d",&exp);
        head=create(head,coffie,exp);
    }
    printf("\nThis is your Polynomial expression:\n");
    display(head);

}
