//Title:- Expression evalution infix to pre fix
//coder:- Pavan Chavan
//Email:- pavan.21920161@viit.ac.in

//global decleration part
//header files
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

//micro defination
#define LP 10
#define RP 20
#define OPERAND 30
#define OPERATOR 40
#define RPP 0
#define AP 1
#define SP 1
#define MP 2
#define DP 2
#define REMP 2
#define NONE 9

//function decleration
void infixTOPreFix();
char pop();
void push(char);
int getType(char);
int getPricidance(char);

//global variable decleration
char inFix[40],preFix[40],stack[40];
int top;

//this function convert the infix expresion into post fix expression
void infixTOPreFix()
{
    int i,p,l,type,prec;
    char next;
    i=p=0;
    l=strlen(inFix);
    l--;
    while (l>=0)
    {
        type=getType(inFix[l]);
        switch (type)
        {
        case RP:
            push(inFix[l]);         //for closing paranthesis
            break;
        
        case OPERAND:
            preFix[p++]=inFix[l];   // for operand
            break;
        
        case LP:
            while ((next=pop())!='(')   //for opening paranthesis
            {
                preFix[p++]=next;
            }
            break;
        
        case OPERATOR:                  //for operator
            prec=getPricidance(inFix[l]);
            while (top>-1 && prec<=getPricidance(stack[top]))
            {
                preFix[p++]=pop();
            }
            push(inFix[l]);
            break;

        }//switch
        l--;
    }//while
    while (top>-1)
    {
        preFix[p++]=pop();
    }//while
}
//to return type of element
int getType(char ch)
{
    switch (ch)
    {
    case '(': return LP;
    case ')': return RP;
    case '+':
    case '-':
    case '*':
    case '/':
    case '%': return OPERATOR;
    default : return OPERAND;
    }//switch
}//getType
//thie function return pricidance to oparator
int getPricidance(char ch)
{
    switch (ch)
    {
    case ')': return RPP;
    case '+': return AP;
    case '-': return SP;
    case '*': return MP;
    case '/': return DP;
    case '%': return REMP;
    default : return NONE;
    }//switch
}//getPricidance

//to push element on stack
void push(char ch)
{
    //top++;
    stack[++top]=ch;
}//push

//to pop element from element from stack
char pop()
{
    char ch=stack[top];
    top--;
    return ch;
}//pop

//main
void main()
{
    char ch;
    int i;
    do
    {
        printf("Enter the infix expression:");
        gets(inFix);

        infixTOPreFix();
        printf("Prefix Expresion is :");

        for ( i=strlen(inFix); i>=0; i--)
        {
           printf("%c",preFix[i]);
        }
        printf("\nDo you want to continue(y/n):");
        ch=getche();
    }while(ch=='y');    //do while
}//main