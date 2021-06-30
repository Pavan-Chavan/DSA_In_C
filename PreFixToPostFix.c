//Title:- Expression evalution prefix to post fix
//coder:- Pavan Chavan
//Email:- pavan.21920161@viit.ac.in

//decleration of herader file
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char c;
	struct node *left;
	struct node *right;	
};
//global varible decleration
struct node *stk[20], *temp, *root;

char prefix[20],ch;
int top=-1, max=20, len;

//function decleration
void post(struct node*);
void exptree();
void push(struct node*);
struct node* pop();

//main
int main()
{
	printf("Enter Prefix expression : ");
	scanf("%s", prefix);
	
	exptree();
	
	printf("Postfix expression is : ");
	post(root);
	return 0;
}//main

//print tree in post order travel
void post(struct node *p)
{
	if(p != NULL)
	{
		post(p->left);
		post(p->right);
		printf("%c", p->c);
	}//if
}//post

//creating tree from expression
void exptree()
{
	int i;
	len = strlen(prefix);
	i=len-1;
	
	while(i>=0) //travelling from end of string 
	{
		switch(prefix[i])       //checking of each element
		{
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '%' : 	temp = (struct node*)malloc(sizeof(struct node));
					   	temp->c = prefix[i];
				   		temp->left = pop();
				   		temp->right = pop();
				   		push(temp);
				   		break;          // create node-> add data into it ->  pop top of stack into left ->
                                        // again pop top of stack into right of node then push
                                        // node into stack
 		
 			default :	temp = (struct node*)malloc(sizeof(struct node));
 						temp->c = prefix[i];
 						temp->left = NULL;          // create node -> enter data into it -> make right left null
 						temp->right = NULL;         // push it on stack
 						push(temp);
 						break;
		}//switch
		--i;
	}//while
	root = pop();
}//exptree

//psuh address of node on stack of structure pointer varible
void push(struct node *p)
{
	if(top==max)
		printf("Stack is Full \n");
	else
		stk[++top] = p;
}//push

//pop and return address of structure 
struct node* pop()
{
	if(top==-1)
		printf("Invalid expression \n");
	else
		return stk[top--];
}//pop
