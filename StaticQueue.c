#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front=0;        //to point the starting of queue
int rear=0;         // to point last point of queue
int isFull()
{
    if(rear==SIZE)
        return 1;
    else
        return 0;
}//isFull() ends
int isEmpty()
{
    if(front==rear)
        return 1;
    else
        return 0;
}//isEmpty() ends
void insert()
{
    if(!isFull())
    {
        printf("Enter the data:");
        scanf("%d",&queue[rear]);
        rear++;                                 //rear pointing one location ahed from top of stack
        printf("Data entered succesfully...");
    }
    else
        printf("Queue is full.....");
}//insert() ends
void delete()
{
    if(isEmpty())
    {
        printf("Queue is empty...");
    }
    else
    {
        int i;
        printf("%d element deleted succesfully..",queue[front]);
        for(i=0;i<rear-1;i++)                       //rear will point to top on q
            queue[i]=queue[i+1];
        rear--;
    }

}//end of delete
void travers()
{
    int i=0;
    if(isEmpty())
    {
        printf("Queue is empty...\n");
    }
    else
    {
        for(;i<rear;)
        printf("%d vlaue of queue is:%d\n",i,queue[i++]);
    }
}//end of travers

int main()
{
    int ch,ele;
    while(1)
    {
        printf("Queue operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse \n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            travers();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter correct choice....");
        }

    }
}



