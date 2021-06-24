//Title:- Doubly linked list
// coder:- Pavan Chavan
// Email:- pavan.21920161@viit.ac.in

#include<stdio.h>
#include<stdlib.h>
//structure node
struct Node *root;
struct  Node
{  
    int data;
    struct Node *left,*right;

};//end of structure
//search is element is present in lined list
void search()
{
    struct Node *temp=root;
    int ele,found=0;
    printf("Ente the element to searche:");
    scanf("%d",&ele);

    while (temp)
    {
        if(temp->data==ele)
        {
            found = 1;
            break;
        }
        temp=temp->right;
    }
    if(found)
    printf("%d element founded.....\n",ele);
    else
    printf("Element not found...");
}//end of search

//this will sort in assending order
void sort()
{
    struct Node *p=root,*q=NULL;
    int temp=0;
    for(;p->right;p=p->right)
    {
        q=p->right;
        for(;q->right;)
        {
            q=q->right;
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
    printf("Element sorted succefully....\n");
}//end of sort 

//this will delete element after given node
void deleteAfter()
{
    if(root==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *p=root,*q=NULL;
    int pos=0,i=0;
    printf("Enter the position:");
    scanf("%d",&pos); 
    if(pos<lenght())
    {
        while(1<pos)
        {
            p=p->right;
            pos--;
        } 
        q=p->right;
        printf("Element deleted succefully..[%d]\n",q->data);
        p->right=q->right;
        if((q->right))
        q->right->left=p;
        q->left=NULL;
        q->left=NULL;
        free(q);  
    }
    else
    printf("Invalid Position\n");
}//end of delete after

//this will delete the root
void deleteFirst()
{
    struct Node *temp;
    if(root == NULL) //checking if list is empty or not
    printf("List is empty..\n");
    else
    {
        printf("[%d] Element deleted succefully..\n",root->data);
        temp=root; 
        if(lenght()>1) //shift root if lenght grether than 1
        {
            root=root->right;
            root->left=NULL;
        }
        if(lenght()==1) 
        root=NULL;      //making root null if only 1 node it there
        temp->right=NULL; //making pointer in node null to free mem
        free(temp);
    }//else
}//deleteFirst

//add element before root
void addAfter()
{
    struct Node *temp,*p=root;
    int pos,i=1;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left=NULL;
    temp->right=NULL;
    printf("Enter the element:\n");
    scanf("%d",&temp->data);
    printf("Enter the position:\n");
    scanf("%d",&pos); 

    //printf("%d",temp->data);
    if(pos<=lenght())
    {
        while(i<pos)
        {
            p=p->right;
            i++;
        } 
        if(root==NULL)
        {
            temp->right=NULL;
            root=temp;        
        }
        else
        {
            temp->right=p->right;
            if(p->right)
            p->right->left=temp; 
            p->right=temp;
            temp->left=p;
        }
    }
    else
    printf("Invalid Position\n");
}//end of addfirst

//this add element after specific location
void addFirst()
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left=NULL;
    printf("Enter the element:\n");
    scanf("%d",&temp->data);
    if(root==NULL)
    {
        temp->right=root;
        root=temp;
        
    }
    else
    {
        root->left=temp;
        temp->right=root;
        root=temp;
    }
}//end of add after

//create linked list 
void create()
{
    struct Node *last,*new;
    while(1)
    {
        new = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data:");
        scanf("%d",&new->data);
        new->right=NULL;
        new->left=NULL;

        if(root==NULL)
        {
            root=new;
            new->left=NULL;
        }
        else
        {
            last->right=new;
            new->left=last;
        }
        last=new;

        printf("Do u want to continue..");
        if(getche() == 'n')
        {
            last->right=NULL;
            break;
        }
        printf("\n");
    }
}//end of create

int lenght() // measure lenght
{
    struct Node *temp=root;
    int i=0;
    while(temp)
    {
        i++;
        temp=temp->right;
    }
    return i;

}//end of lenght

//display the list
void display()
{
    struct Node *temp=root;
    if (temp==NULL)
    {
        printf("Link is empty\n");
    }
    else
    {
        printf("Element in the List:-");
        while(temp)
        {
            printf("%d ",temp->data);
            temp=temp->right;
         }
         printf("\n");
    }

}//end of display

//this will print list in reverse order
void displayReverse()
{
    struct Node *temp=root;

    while(temp->right)
    temp=temp->right;

    printf("Element in reverse order:- ");
    while (temp)
    {
        printf("%d ",temp->data);
        temp=temp->left;
    }
    
}//end of display reverse

//add element at end of list
void append(int ele)
{
    struct  Node *temp=NULL;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=ele;
    temp->left=NULL;
    temp->right=NULL;
    printf("%d is addes succesfully..\n",ele);
    if(root==NULL)
    root=temp;
    else
    {
        struct Node *p=root;
        while(p->right)
        p=p->right;
        p->right=temp;
        temp->left=p;
    }

}//end of append

//create a line
void line(){
    puts("----------------------------------------------------\n");
}
void main()
{
    int op,ele;
    line();
    printf("\t\t\tDoubly Linked List OPARATION\n");
    line();
    printf("\t\t\t\t1. Create List\n");
    printf("\t\t\t\t2. Sort\n");
    printf("\t\t\t\t3. Search\n");
    printf("\t\t\t\t4. Delete First\n");
    printf("\t\t\t\t5. Delete After\n");
    printf("\t\t\t\t6. Add First\n");
    printf("\t\t\t\t7. Add After\n");
    printf("\t\t\t\t8. Display reverse\n");
    printf("\t\t\t\t9. Display\n");
    printf("\t\t\t\t10. Append\n");
    printf("\t\t\t\t11. Exit\n\n\n");
    while(1){
        printf("\t\t\tEnter your choice[ ]\b\b");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            create();
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
            displayReverse();  
            break;
        case 9:
            display();  
            break;  
        case 10:
            printf("Enter the data : \n");
            scanf("%d",&ele);
            append(ele);  
            break;
        case 11:
            exit(0);  
        }//end of switch
    }//end of while
}//end of main
