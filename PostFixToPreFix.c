//Title:- Expression evalution postfix to prefix
//coder:- Pavan Chavan
//Email:- pavan.21920161@viit.ac.in

//header file decleration
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure node for tree
struct node
{
	char c;
	struct node *left;
	struct node *right;	
};
//global varible decleration
struct node *stk[20], *temp, *root;

char postfix[20],ch;
int top=-1, max=20, len;

//function decleration
void preorder(struct node*);
void exptree();
void push(struct node*);
struct node* pop();

//main
int main()
{
	printf("Enter Postfix expression : ");
	scanf("%s", postfix);
	
	exptree();
	
	printf("Prefix expression is : ");
	preorder(root);
	return 0;
}//main

//travelling in preorder to print in prefix
void preorder(struct node *p)
{
	if(p != NULL)
	{
		printf("%c", p->c);
		preorder(p->left);
		preorder(p->right);
		
	}//if
}//preorder

//creating tree for postfix expression
void exptree()
{
	int i, j;
	i=0;
	j = strlen(postfix);
	
	while(i<j)      //travelling from first to last
	{
		switch(postfix[i])  //check for each varible
		{
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '%' : 	temp = (struct node*)malloc(sizeof(struct node));       //when oparator
					   	temp->c = postfix[i];
				   		temp->right = pop();        // creating a node->enter data ->poping top of stack into right of node
				   		temp->left = pop();         // poping the top of stack on to left of node then push node
				   		push(temp);                 // on stack
				   		break;
 		
 			default :	temp = (struct node*)malloc(sizeof(struct node));   // when operand
 						temp->c = postfix[i];       // creating a node -> enter data -> put null on left and right
 						temp->left = NULL;           // push it on the stak
 						temp->right = NULL;
 						push(temp);
 						break;
		}//switch
		++i;
	}//while
	root = pop();
}//exptree
//push adderess of node on stack of structue pointer varible
void push(struct node *p)
{
	if(top==max)
		printf("Stack is Full \n");
	else
		stk[++top] = p;
}//push
//return address of strcuture which is top on stack
struct node* pop()
{
	if(top==-1)
		printf("Invalid expression \n");
	else
		return stk[top--];
}//pop
