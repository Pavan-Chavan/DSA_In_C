//Title :- Selection Sort
//code:- pavan chavan
//email:- pavan.21920161@viit.ac.in
//date :- 15/7/2021

#include<stdio.h>

int arr[5]={5,4,3,2,1};
int n=5;
void main()
{
    int i,j,least,temp;
    
    //algorithm start from here
    for (i = 0; i < n; i++)
    {
        least=i;
        for (j =i+1; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                least=j;
            }//if
        }//for
        temp=arr[i];
        arr[i]=arr[least];
        arr[least]=temp;        
    }//for
    //algorithm ends here
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    
}//main