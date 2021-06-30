//Title:- evaluation of prefix expresion
//coder:- Pavan Chavan
//Email:- pavan.21920161@viit.ac.in

//header file decreration
#include<stdio.h>
#include<string.h>

//function decleration
int isOperand(char);
int evaluate(char[]);
void push(int);
int pop();

//global varible decleration
int stack[20];
int top=-1;

//main
int main()
{
	char pre[20];
	int res;
	
	printf("Enter PostFix expression : ");
	gets(pre);
	
	printf("Input expression : %s \n", pre);
	res = evaluate(pre);
	printf("Result is : %d \n", res);
	
	return 0;	
}//main

// evaluate the prefix string
int evaluate(char exp[])
{
	int j=0;
	for(; j<strlen(exp); j++)		//travalling through the string
	{
		if(isOperand(exp[j]))		// if it is operand push it on stack
		{
			push(exp[j]-'0');
		}//if
		else
		{
			int x,y;		//if it is and operand then pop two element of stack and perfor
			y = pop();		// arithematic operation as per operator
			x = pop();
			switch(exp[j])
			{
				case '+'	:	push(x+y);
							break;
				
				case '-'	:	push(x-y);
							break;
								
				case '*'	:	push(x*y);
							break;
				
				case '/'	:	push(x/y);
							break;	
			}//swithc
		}//else
	}
	return pop();
}//evaluete

//check wherther input is operand or not
int isOperand(char ch)
{
	if(ch>=48 && ch<=57)
		return 1;
	else
		return 0;	
}//isOperand

//push on the stack
void push(int val)
{
	stack[++top] = val;
}//push

//pop from the stack
int pop()
{
    if(top==-1){
    printf("Invalid expression\n");
    exit(0);
    }
    else
	return stack[top--];
}//pop
