#include<stdio.h>
#include<stdlib.h>
struct Node *root;
struct Node
{
    int data;
    struct Node *left,*right;
};
void insert()
{
    struct Node *temp;
    struct Node *curr,*parent;
    
    int ele;
    printf("Enter the value:");
    scanf("%d",&ele);

    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=ele;
    curr=root;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        while (curr)
        {
            parent=curr;
            if (curr->data>ele)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        if(parent->data<ele)
        {
            parent->right=temp;
        }    
        else
        {
            parent->left=temp;
        }
    }  
}

void delete()
{
    struct Node *temp,*curr,*parent;
    int found=0,ele;
    printf("Enter the element to search:");
    scanf("%d",&ele);
    curr=root;
    while (1)
    {
       
        if(curr->data==ele)
        {
            found =1;
            break;
        }
        else 
        parent=curr;
        if (curr->data>ele)
        {
            curr=curr->right;
        }
        else
        {
            curr=curr->left;
        }
    }//while 
    if(!found)
    printf("Element not found..");
    else
    {
        if (curr->left==NULL && curr->right==NULL)
        {
            if (curr==parent->right)
            parent->right=NULL;
            else
            parent->left=NULL;
        }//if
        else if(curr->left!=NULL && curr->right==NULL || curr->right!=NULL && curr->left==NULL)
        {
            if (curr->left!=NULL && curr->right==NULL)
            {
                if(parent->right==curr)
                parent->right=curr->left;
                else
                parent->left=curr->left;
                curr->left=NULL;
                free(curr);
            }//if
            else
            {
                if(parent->right=curr)
                parent->right=curr->right;
                else
                parent->left=curr->right;
                curr->right=NULL;
                free(curr);
            }//else
            
        }//else if
        
        /*
            deletion for node have 2 child node is left
        */

    }//else
}//delete
void printPreO()
{
    if(root)
    preOrderDisplay(root);
    else
    printf("Tree is empty...");
}//printPreO
void preOrderDisplay(struct Node *p)
{
    printf("%d ",p->data);
    if(p->left)
    preOrderDisplay(p->left);
    if(p->right)
    preOrderDisplay(p->right);
}//preOrderDisplay

void printPostO()
{
    if(root)
    postOrderDisplay(root);
    else
    printf("Tree is empty...");
}//printPostOrder
void postOrderDisplay(struct Node *p)
{
    if(p->left)
    postOrderDisplay(p->left);
    if(p->right)
    postOrderDisplay(p->right);
    printf("%d ",p->data);
}//postOrderDisplay
void printInO()
{
    if(root)
    inOrderDisplay(root);
    else
    printf("Tree is empty...");
}//printInOrder
void inOrderDisplay(struct Node *p)
{
    if(p->left)
    inOrderDisplay(p->left);
    printf("%d ",p->data);
    if(p->right)
    inOrderDisplay(p->right);
    
}//inOrderDisplay
void main()
{
	int choice , ele ;
	while(1)
	{
		printf("/*Deque operations**/\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.PreOrder Print\n");
		printf("4.InOrder Print\n");
		printf("5.PostOrder Print\n");
		printf("6.Quit\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);
	

		switch(choice)
		{
			case 1		:	insert();
						break ;
			
			case 2		:	delete();
						break ;
			
			case 3		:	printPreO();
						break ;
			
			case 4		:	printInO();
						break ;
			
			case 5		:	printPostO();
						break ;
			
			case 6		:	exit(1);
			defualt	:	printf("Invalid choice...\n\n");
		}//end of switch
	}//end of while
}//end of main