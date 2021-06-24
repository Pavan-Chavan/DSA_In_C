//Title:- Singly linked list
// coder:- Pavan Chavan
// Email:- pavan.21920161@viit.ac.in

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node *root;      //root varible to store root address

struct Node
{
    int data;       //we can change data as per our requirment
    int *link;
}; // end of node
// create list at once to add many varible

void createList()
{
    struct Node *temp,*last;
    int ele;
    while (1)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data:");
        scanf("%d",&temp->data);

        temp->link=NULL;

        if(root==NULL)
        {
        root=temp;
        }
        else
        {
            last->link=temp;
        }
        last=temp;
        
        printf("Do u want to continue[y/n] :");
        if(getche()=='n')
        break;
        printf("\n");
    }
    
}//end of create list
// use to sort element in asending order
void sort()
{
    int i,j,n,temp;
    struct Node *p,*q;
    n=lenght();
    p=root;
    for(i=0;i<n;i++)
    {
        
        q=p->link;
        for(j=0;j<n-i-1;j++)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->link;
        }
        p=p->link;
    }
}//end of sort
// to searche element is present linked list
void search()
{
    int ele,found=0;
    struct Node *temp=NULL;
    printf("Enter a element you want to search:");
    scanf("%d",&ele);
    temp=root;
    while(temp)
    {
        if(temp->data==ele)
        {
            found=1;
            break;
        }
        else
        {
            temp=temp->link;
        }
    }
    if(found!=1)
        {
            printf("Element not found..\n");
        }
    else
    printf("Element found...\n");

}//end of search
// to delete element after specific location
void deleteAfter()
{
    int choice,i=1;
    struct Node *temp=root,*temp1;

    printf("Enter Choice...:");
    scanf("%d",&choice);

    if(choice>lenght())
    {
        printf("invalid choice\n");
    }
    else
    {
        while(i<choice)
        {
            i++;
            temp=temp->link;
        }
        temp1=temp->link;
        temp->link=temp1->link;
        temp1->link=NULL;
        free(temp1);

    }

}//end of delete after
// to delete value at root
void deleteFirst()
{
    struct Node *temp;
    if(root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
    
    temp=root;
    printf("Element deleted succesfully...is %d\n",root->data);
    root=temp->link;
    temp->link=NULL;
    free(temp);
    }

}//end of delete first
// to add element before root
void addFirst()
{
    struct Node *new;
    new=(struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d",&new->data);
    new->link=root;
    root=new;
}//end of add first
// to swap the data of two given location
void data_Swap()
{
    int L1,L2,temp,i=1;
    struct Node *p=root,*q=root;

    printf("Enter the position of Nodes :");
    scanf("%d%d",&L1,&L2);

    if(L1<=lenght() && L2<=lenght())
    {
        while(i<=L1)
        {
            p=p->link;
            i++;
        }
        i=1;
        while(i<=L2)
        {
            q=q->link;
            i++;
        }

        temp=p->data;
        p->data=q->data;
        q->data=temp;

        printf("%d and %d swap succefully...",L1,L2);

    }
    else{
        printf("Enter valid choices:");
    }
}//end of data swap
// to display element is likned list
void display()
{
    struct Node *temp=root;
    if(root==NULL)
        printf("List is empty\n");
    else
    {
        while(temp)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }

}//end of display
// to add element after specific location
void addAfter()
{
    struct Node *temp,*p=root;
    int i=1,L;
    temp = (struct Node*) malloc(sizeof(struct Node));

    printf("Enter the position: ");
    scanf("%d",&L);
    
    printf("Enter the data:");
    scanf("%d",&temp->data);
    if(i>0)
    {
        while(i<L)
            {
                p=p->link;
                i++;
            }

            temp->link=p->link;
            p->link=temp;
    }
    else
    {
        printf("Enter valid choice..");
    }
}//end of addafter
// to calculate lenght of linked list
int lenght()
{
    int count=0;
    struct Node *temp=root;

    while(temp)
    {
        count++;
        temp=temp->link;
    }
    return count;
}//end of lenght
// to add element to last of list
void append()
{
    struct Node *temp;
    temp= (struct Node*)malloc(sizeof(struct Node));

    printf("Enter node data:");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct Node *last=root;
        while(last->link)
        {
            last=last->link;
        }
        last->link=temp;
    }
}//end of append
void line(){
    puts("--------------------------------------------------------");
}//end of line
void main()
{
    int op,ele;
    line();
    printf("\t\t\tQueue OPARATION\n");
    line();
    printf("\t\t\t\t1. Create List\n");
    printf("\t\t\t\t2. Sort\n");
    printf("\t\t\t\t3. Search\n");
    printf("\t\t\t\t4. Delete First\n");
    printf("\t\t\t\t5. Delete After\n");
    printf("\t\t\t\t6. Add First\n");
    printf("\t\t\t\t7. Add After\n");
    printf("\t\t\t\t8. Data Swap\n");
    printf("\t\t\t\t9. Display\n");
    printf("\t\t\t\t10. Lenght\n");
    printf("\t\t\t\t11. Append\n");
    printf("\t\t\t\t12. Exit\n\n\n");
    while(1){
        printf("\t\t\tEnter your choice[ ]\b\b");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            createList();
            break;
        case 2:
            sort();
            break;
        case 3:
            search();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteAfter();
            break;
        case 6:
            addFirst();
            break;
        case 7:
            addAfter();
            break;
        case 8:
            data_Swap();  
            break;
        case 9:
            display();  
            break;  
        case 10:
            lenght();  
            break; 
        case 11:
            append();  
            break;
        case 12:
            exit(0);  
        }//end of switch
    }//end of while
}//end of main




