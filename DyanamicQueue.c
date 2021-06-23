//Title:- Dyanamic Queue
// coder:- Pavan Chavan
// Email:- pavan.21920161@viit.ac.in

#include<stdio.h>
#include<stdlib.h>

int *queue,*front,*rear;
int min,curr;

void create_Queue()
{
    printf("\t\t\t\tEnter the base size of queue:");
    scanf("%d",&min);
    queue=(int*)calloc(min,sizeof(int));

    if(front=NULL)
        printf("\t\t\t\tMemeory out of bound\n");
    else
    {
        printf("\t\t\t\t%d memeory allocate succefully..\n",min);
        front=queue;
        rear=queue;                     //if we declread this on line 10 other functions are not going to work why
    }
    curr=min;
}//end of create queue

void insert()
{
    int n;
    if(front+curr==rear)
    {
        curr++;
        queue=(int*)realloc(queue,curr*sizeof(int));
    }

    printf("\t\t\t\tEnter the value:");
    scanf("%d",rear);
    ++rear;
}//end of insert

void display()
{
    if(front==rear)
        printf("\t\t\t\tQueue is empty..\n");
    else
    {
        int *i=front;
        for(;i<rear;i++)
        printf("\t\t\t\tElement is %d\n",*i);  //if we use front insted of queue it is not working why???
    }
}//end of display
void delete()
{
    if(rear==front)
    {
        printf("\t\t\t\tQueue is empty..\n");
        return;
    }
    else
    {
        int *i;
        printf("\t\t\t\tDeleted element is %d\n",*front);
        for(i=front+1;i<rear;i++)
        {
            *(i-1)=*i;
        }
        rear--; 
        if(curr>min)
        {
        --curr;
        queue=(int*)realloc(queue,curr*sizeof(int));
        }
    }   
}//end of delete
void line()
{
    puts("------------------------------------------------------------------");
}//end of line
void main()
{
    int op,ele;
    create_Queue();
    line();
    printf("\t\t\tQueue OPARATION\n");
    line();
    printf("\t\t\t\t1. Insert\n");
    printf("\t\t\t\t2. Delete\n");
    printf("\t\t\t\t3. DISPLAY\n");
    printf("\t\t\t\t4. EXIT\n\n\n");
    while(1){
        printf("\t\t\tEnter your choice[ ]\b\b");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }//end of while
    
}//end of main
