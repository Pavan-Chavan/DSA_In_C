//Title:- Traverse in graph using BSF Algorithm in c
//coder:- Pavan Chavan
//Email:- pavan.21920161@viit.ac.in
//date:- 2/7/2021

//header files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//fun decleration
void insert(int);
int del();
int isEmpty();
int isInQueue(int);
int isVisited(int,int);

//global varible decleration
struct Node *front=NULL , *rear=NULL;
int visited[20];
int  vcnt=0,vertex;

//node for queue
struct Node 
{
    int data;
    struct Node *next;
};
//inserting value is queue
void insert(int x)
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->next=NULL;
    temp->data=x;
    if (front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

//first return front from Q and and shift front 
int del()
{
    struct Node *temp=front;
    int data;
    if (isEmpty())
    {
        return -1;
    }
    data=front->data;
    front=front->next;
    if (front==NULL)
    {
        rear=NULL;
    }
    free(temp);
    return data;
}
//checking is empty
int isEmpty()
{
    if(front==NULL)
    return 1;
    else
    return 0;
}
//checking is in Q
int isInQueue(int x)
{
    for (struct Node  *i = front; i != NULL; i=i->next)
    {
        if(x==i->data)
        return 1;
    }
    return 0;
}
//checking is in visit or not
int isVisited(int arrCnt,int val)
{
    for (int  i = 0; i < 6; i++)
    {
        if (visited[i]==val)
        {
            return 1;
        }
    }
        return 0; 
}
//mian
void main()
{
    int i;
    int G[6][6]={{0,1,1},{1,0,0,0,0,1},{1,0,0,1,1,0},{0,0,1},{0,0,1},{0,1}};
    insert(0);
    while (!isEmpty())
    {
        vertex=del();
        visited[vcnt]=vertex;
        vcnt++;
        for (i = 0; i < 6; i++)
        {
            if (G[vertex][i]==1)
            {
                if ((!isVisited(vcnt,i) && !isInQueue(i)))
                {
                    insert(i);    
                }//if
            }//if
        }//for
    }//while
    for (int i = 0; i < vcnt; i++)
    {
        printf("%d ",visited[i]);
    }
}//main