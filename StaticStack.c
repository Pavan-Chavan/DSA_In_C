//Title :- Static Stack Oparation
// coder name:- Pavan Chavan
// Email:- pavan.21920161@viit.ac.in

#include<stdio.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

int isFull()
{
    if(top==(SIZE-1))
    {

        return 1;
    }
    else
        return 0;
}
int isEmpty()
{

    if(top ==(-1))
        return 1;
    else
        return 0;
}

void push(int ele)
{

    if(isFull())
    {
        printf("Stack is Full\n");

    }
    else
    {
        ++top;
        stack[top]=ele;
        printf("Element added sucessfully\n");

    }
}

void traverse()
{
    if(isEmpty()){
        printf("Stack is empty\n");
    }
    else
    {

        int i;
        printf("Elements are:\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int peek()
{

    if(isEmpty())
    {

        return 0;
    }
    else
    {
        return stack[top];     // return stack[--top];
    }

}

int pop(void)
{
    if(isEmpty())
    {
        printf("Stack is empty\n ");
        return 0;
    }
    else
    {
        int ele;
        ele=stack[top];
        --top;
        return ele;     // return stack[--top];
    }
}




int main()
{
    int ch,ele;
    while(1)
    {
        printf("Stack operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. peek \n");
        printf("4. Traverse\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d",&ele);
            push(ele);
            break;
        case 2:
            ele=pop();
            if(ele==0)
                printf("Stack is empty\n");
            else
                printf("Poped element is %d\n",ele);
            break;
        case 3:
            ele=peek();
            if(ele==0)
                printf("Stack is empty\n");
            else
                printf("Peek element is %d\n",ele);
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter correct choice....");
        }

    }
}
