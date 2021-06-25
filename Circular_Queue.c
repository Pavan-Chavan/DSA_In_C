//Title:- circular queue
// coder:- Pavan Chavan
// Email:- pavan.21920161@viit.ac.in
#include<stdio.h>

#define size 5
int queue[size];
int front,rear;
rear=-1;
front=-1;
// to add element in queue
void enQueue()
{
    if(isFull())
    {
        printf("Queue is Full...\n");
    }
    else
    {
        int ele=0;
        printf("Enter the element:");
        scanf("%d",&ele);
        if(rear==-1)
        rear=front=0;
        else if(rear==size-1)
        rear=0;
        else
        rear++;
        queue[rear]=ele;
    }
}//end of queue

//to delete elemen from front i.e remove elmeent
void deQueue()
{
    if(isEmpty())
    {
        printf("Queue is empty..");
    }
    else
    {
        printf("[%d] deleted succefully...",queue[front]);
        if(rear==front)
        rear=front=-1;
        else if(front==size-1)
        front=0;
        else
        front++;
    }
}//end of deQueue

//to check is queue is empty or not
int isEmpty()
{
    if(front==-1 && rear==-1)
    return 1;
    else
    return 0;
}//end of isEmpty

//to check is queue is full or not
int isFull()
{
    if(front==0 && rear==size-1 || front==rear+1)
    return 1;
    else
    return 0;
}//end of isFull

//to display the element of queue
void display()
{
    int i=rear;
    printf("Elements are :-");
    i=front;
    for(;i<=rear;)
    printf("%d ",queue[i++]);

}//end of display
//to print line
void line()
{
    puts("--------------------------------------------------------");
}

void main()
{
    int op,ele;
    
    line();

    printf("\t\t\t\tSTACK OPARATION\n");
    line();
    printf("\t\t\t\t1. EnQueue\n");
    printf("\t\t\t\t2. Dequeue\n");
    printf("\t\t\t\t3. DISPLAY\n");
    printf("\t\t\t\t4. EXIT\n\n\n");
    while(1)
    {
        printf("\t\t\tEnter your choice[ ]\b\b");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }//end of switch
    }//end of while

}//end of main
