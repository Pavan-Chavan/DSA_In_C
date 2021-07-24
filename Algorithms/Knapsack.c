//Title :-0/1knapsack (greedy algoritham)
//code:- pavan chavan
//email:- pavan.21920161@viit.ac.in
//date :- 21/7/2021

#include<stdio.h>

int knapsack(int wt[],int pr[],int w,int n)
{
    if(w==0 || n==0)
    return 0;           //return 0 when ther is no element left or weight is over

    else if(wt[n]>w)
    return knapsack(wt,pr,w,n-1);   //we are skiping the element when avaible weight in sack is less that 
                                    //weight of item is list
    else
    return max( knapsack(wt,pr,w,n-1),                  //returning max of if we take 
                (knapsack(wt,pr,w-wt[n],n-1)+pr[n]));    //element or not
                                                                                    
}

int main()
{
    int wt[3]={120,100,50},pr[3]={30,20,3},w=50,n=4;
    int result;

    result=knapsack(wt,pr,w,n);

    printf("Maximume profit is :- %d",result);

}