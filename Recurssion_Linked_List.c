#include<stdio.h>
struct Node *root=NULL; 
struct Node
{
    int data;
    struct  Node *link;
    
}
struct Node* insert(struct Node,int ele)
{
    if(node==NULL)
    {
        return newNode(ele);
    }
    else
    {
        node->link=insert(node->link,ele)
    }
}
void print_forward(struct Node* node)
{
    if(root==NULL)
    {
    printf("List is empty..")
    }
    else if(node==NULL)
    {
        printf("List ends here..");
    }
    else{
        printf("%d\n",node->data);
        print_forward(node->link);
    }
}


void main()
{

}
