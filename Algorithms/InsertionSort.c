//Title :- Insertion sort
//code:- pavan chavan
//email:- pavan.21920161@viit.ac.in
//date :- 21/7/2021

#include<stdio.h>

int arr[5]={5,4,3,2,1};
int n=5;
//insertion sort
void insertionSort(int arr[],int n)
{
    int j,i,temp;
    for (i = 1; i < n; i++)
    {
        temp=arr[i];
        j=i-1;
        while (j>=0 && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void main()
{
    int i,j,temp,sorted=0;
    
    //element before sort
    for (i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }//for

    insertionSort(arr,n);
    printf("\n");
    //element after sort
    for (i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }//for
}//main