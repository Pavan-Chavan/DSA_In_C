#include<stdio.h>

int *stack, *top ,curr,min;
void createStack()
{
    printf("\n\n\t\tEnter the basic size of stack [ ]\b\b");
    scanf("%d",&min);
    curr=min;
    stack=(int*)calloc(min,sizeof(int));
    if(stack==NULL)
        printf("Memory not avaible...\n");
    else
        top=stack;
}

void push(int ele)
{
    if(top==stack+curr)
    {
        curr++;
        stack=(int*)realloc(stack,curr*sizeof(int));
    }

       *top=ele;
        top++;
        printf("\t\t\tElement pushed succesfully....\n");

}

int pop()
{
    if(top==stack)
    {
       printf("\t\t\tStack is empty\n");
    }
    else
    {
        top--;
        printf("\t\t\tPopped Element is [%d].....\n",*top);
        if(curr>min)
        {
            curr--;
            stack=(int*)realloc(stack,curr*sizeof(int));

        }
    }
}

display()
{
    if(stack==top)
    {
        printf("\t\t\tStack is empty\n");
    }
    else{
        int *i;
        for(i=top-1;i>=stack;i--)
        printf("\t\t\tElements are:[%d]\n",*i);
    }
}
line()
{
    printf("--------------------------------------------------------------------------------\n");
}
void main()
{
    int op,ele;
    createStack();
    line();
    printf("\t\t\t\tSTACK OPARATION\n");
    line();
    printf("\t\t\t\t1. PUSH\n");
    printf("\t\t\t\t2. POP\n");
    printf("\t\t\t\t3. DISPLAY\n");
    printf("\t\t\t\t4. EXIT\n\n\n");
    while(1){
    printf("\t\t\tEnter your choice[ ]\b\b");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("\t\t\tEnter element:_\b");
        scanf("%d",&ele);
        push(ele);
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    }
}

}


