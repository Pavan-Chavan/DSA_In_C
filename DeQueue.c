//Title:- Double ended Queue
// coder:- Pavan Chavan
// Email:- pavan.21920161@viit.ac.in

#include<stdio.h>

#define size 5
int dequeue[size];
int front =-1,rear=-1;

//to insert from front
void insertFront()
{
    if(isFull())
    {
        printf("Queue is full..");
        return;
    }
    else
    {
        int ele;
        printf("Enter the element:");
        scanf("%d",&ele);
        if(front==-1)
        front=rear=0;
        else if(front==0)
        front=size-1;
        else
        front--;
        dequeue[front]=ele;
    }
}//end of insert front

//insert from rear
void insertRear()
{
    if(isFull())
    {
        printf("Queue is full..\n");
        return;
    }
    else
    {
        int ele;
        printf("Enter the element:");
        scanf("%d",&ele);
        if(rear==-1)
        front=rear=0;
        else if(rear==size-1)
        rear=0;
        else
        rear++;
        dequeue[rear]=ele;
    }
}//end of insertRear

//delete from front
void deleteFront()
{
    if(isEmpty())
    {
        printf("Queue is empty..\n");
        return;
    }
    else
    {
        printf("Element delete succefully..%d",dequeue[front]);
        if(front==rear)
        front=rear=-1;
        if(front==size-1)
        front=0;
        else
        front++;
    }
}//end of deleteFront

//delete from rear
void deleteRear()
{
    if(isEmpty())
    {
        printf("Queue is empty..\n");
        return;
    }
    else
    {
        printf("Element deleted succesfully..%d",dequeue[rear]);
        if(rear==front)
        front=rear=-1;
        else if(rear==0)
        rear=size-1;
        else
        rear--;


    }
}//end deleterear

//to diplay the list
void display()
{
	int i;
	if(front == -1)
	{
		printf("No elements to display\n\n");
	}
	else if(front<=rear)
	{
		for(i=front ; i<=rear ; i++)
		{
			printf("Element %d : %d \n", i+1, dequeue[i]);
		}
		printf("\n");
	}
	else
	{
		for(i=front ; i<=size-1; i++)
		{
			printf("Element %d : %d \n",i+1,dequeue[i]);
		}
		for(i=0 ; i<=rear ; i++)
		{
			printf("Element %d : %d \n",i+1,dequeue[i]);
		}
		printf("\n");
	}
}// end of display

//to check is q is full
int isFull()
{
    if(rear==size-1 && front==0 || rear+1==front)
    return 1;
    else
    return 0;
}//end of isFull

//to check is q is empty
int isEmpty()
{
    if(front==-1 || rear==-1)
    return 1;
    else
    return 0;
}//end of isEmpty
void main()
{
	int choice , ele ;
	while(1)
	{
		printf("/*Deque operations**/\n");
		printf("1.InsertFront\n");
		printf("2.InsertRear\n");
		printf("3.DeleteFront\n");
		printf("4.DeleteRear\n");
		printf("5.Display\n");
		printf("6.Quit\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);
	

		switch(choice)
		{
			case 1		:	insertFront();
						break ;
			
			case 2		:	insertRear();
						break ;
			
			case 3		:	deleteFront();
						break ;
			
			case 4		:	deleteRear();
						break ;
			
			case 5		:	display();
						break ;
			
			case 6		:	exit(1);
			defualt	:	printf("Invalid choice...\n\n");
		}//end of switch
	}//end of while
}//end of main
