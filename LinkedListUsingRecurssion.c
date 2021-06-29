//Title:- Linked list using reccurssion
// coder:- Pavan Chavan
// Email:- pavan.21920161@viit.ac.in

#include<stdio.h>

struct Node* newNode(int);  //fun decleration

struct Node *root;      //root varible of list
struct Node
{
    int data;
    struct Node *link;
};

//this function will reache to last node and then transfer control to
// newNode and returns adderss of node to its previous node
struct Node* insert(struct Node *node,int ele)
{
    if (node==NULL)
    {
        return newNode(ele);
    }
    else
    {
        node->link=insert(node->link,ele);
    }
    return node;
}
//to create new node 
struct Node* newNode(int ele)
{
    struct Node *node;
    node=(struct Node*)malloc(sizeof(struct Node));
    node->data=ele;
    printf("Data inseted succefully [%d]\n",ele);
    node->link=NULL;
    return node;
}
// print element in forward mode
void print(struct Node *node)   // this will check only is list is empty or not
{
    if(node==NULL)
    printf("List is empty..\n");
    else
    printForward(node);
}
void printForward(struct Node *node)    // this will print the list in forward mode
{
    if(node==NULL)
    return;
    else
    {
        printf("%d ",node->data);
        printForward(node->link);
    }
}

// print the list in reverse order
void printR(struct Node *node)  //this will check is list empty or not
{
    if(node==NULL)
    printf("List is empty...\n");
    else
    printReverse(node);
}
void printReverse(struct Node *node)    //this will print the list in reverse order
{
    if(node==NULL)
    return;
    printReverse(node->link);
    printf("%d ",node->data);
}

void main()
{
	int ch, ele;
	while(1)
	{
        printf("\n");
		printf("1. Insert \n");	
		printf("2. Print Forward \n");
		printf("3. Print_reverse \n");
		printf("4. Quit \n");
		
		printf("Enter choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1	:	printf("Enter element : ");
						scanf("%d", &ele);
						root = insert(root, ele);
						break ;
			
			case 2	:	printForward(root);
						break;
			
			case 3	:	printR(root);
						break;
			
			case 4	:	exit(1);
			default	:	printf("Invalid choice \n\n");
		}//switch
	}//while
}//main
