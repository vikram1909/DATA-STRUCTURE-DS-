#include<stdio.h>
#define MAX 10
void PUSH(int);
void POP();
void show();
int stack[MAX];
int top=0,n;
void PUSH(int n)
{
    if(top==MAX)
    {
        printf("\nStack is Overflow:\n");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}
void POP()
{
    if(top==0)
    {
        printf("\nStack is Underflow:\n");
    }
    else
    {
        top--;
        n=stack[top];
    }
}
void show()
{
    int i;
    if(top==0)
    {
        printf("\nStack Empty:\n");
    }
    else
    {
        printf("\nThese are the Elements:\n\n");
        for(i=1;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
    }
}
void main()
{
    int i,item,choice;
    char ch;
    printf("\nEnter how many Elements you want to insert:");
    scanf("%d",&n);
    printf("\nEnter %d Elements:\n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&item);
        PUSH(item);
    }
    show();
    a:
    printf("\nDo you want to Delete Elements from Stack (Y/N): ");
    ch=getch();
    if(ch=='Y'||ch=='y')
    {
        printf("\nPress 1 for one element: \nPress 2 for two elements: ");
        printf("\nPress 3 for three element: \nPress 4 for four elements: ");
        printf("\nPress 5 for all element:\n");
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            POP();
            break;
        case 2:
            for(i=1;i<=2;i++)
                POP();
            break;
        case 3:
            for(i=1;i<=3;i++)
                POP();
            break;
        case 4:
            for(i=1;i<=4;i++)
                POP();
            break;
        case 5:
            for(i=1;i<=n;i++)
                POP();
            break;
        }
        show();
    }
    else if(ch=='N'||ch=='n')
    {
        exit(0);
    }
    else
    {
        printf("\n\nEnvalid Choice...Pls Enter either 'Y' or 'N'\n");
        goto a;
    }
}
