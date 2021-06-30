//Title:- Expression evalution infix to post fix
//coder:- Pavan Chavan
//Email:- pavan.21920161@viit.ac.in

//global decleration part
//header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//micro defination
#define LP 10
#define RP 20
#define OPERAND 30
#define OPERATOR 40
#define LPP 0
#define AP 1
#define SP 1
#define MP 2
#define DP 2
#define REMP 2
#define NONE 9

//function decleration
void inFixToPostFix();
void push(char);
char pop();
int getPrecidance(char);
int getType(char);

//global variable decleration
char inFix[50],postFix[50],stack[50];
int top;

//this function convert the infix expresion into post fix expression
void inFixToPostFix()
{
    int p,l,i,type,prec;
    char next;
    i=p=0;
    l=strlen(inFix);
    while (i<l)
    {
        
        type = getType(inFix[i]);
        switch (type)
        {
        case LP:                    //it it is opaning paranthesis
                push(inFix[i]);
            break;
        
        case RP:                    //if is closing paranthesis
                while ((next=pop())!='(')
                {
                    postFix[p]=next;
                    ++p;
                }
                break;

        case OPERAND:           //when it is an operand
                postFix[p]=inFix[i];
                p++;
                break;
            
        case OPERATOR:          //when it is operator
                prec=getPrecidance(inFix[i]);
                while ((top>-1 && prec<= getPrecidance(stack[top])))
                {
                    postFix[p]=pop();
                    ++p;
                }
                push(inFix[i]);
                break;
        }//switch
        ++i;
    }//while
    while (top>-1)
    {                           //pushing remianig element on the postfix
        postFix[p]=pop();
        ++p;
    }//while
    
    
}
//push on the stack
void push(char ch)
{
    ++top;
    stack[top]=ch;    
}//push
//pop from the stack
char pop()
{
    char ch=stack[top];
    top--;
    return ch;
}//pop
//return the precidance of each operator
int getPrecidance(char sym)
{
    switch (sym)
    {
        case '(': return LPP;
        case '+': return AP;
        case '-': return SP;
        case '*': return MP;
        case '/': return DP;
        case '%': return REMP;
        default: return NONE;
    }//swithc
}//getprecidance
//return the type of varible
int getType(char sym)
{
    switch (sym)
    {
        case '(':   return LP;
        case ')':   return RP;
        case '+':
        case '-':
        case '/':
        case '*':
        case '%': return OPERATOR;
        default:    return OPERAND;
    }//switch
}//getType

void main()
{
    while (1)
    {
        int i=0;
        char ch;
        printf("Enter the valid algebra exoression to convert into postfix:");
        gets(inFix);
        inFixToPostFix();
        for (i = 0; i <= strlen(inFix); i++)
        {
            printf("%c",postFix[i]);
        }//for
        printf("\nDo you want to continue y/n :");
        if(ch=getche()=='n')
        exit(0);
    }//while
}//main