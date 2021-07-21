#include<stdio.h>


void createHeap(int arr[],int i)
{
    int temp=arr[i];
    while ((i>1)&&arr[i/2]<arr[i])
    {
        arr[i]=arr[i/2];
        i=i/2;
    }
    arr[i]=temp;
    
}
void deleteMaxAndReConstruct(int arr[],int i,int n)
{
    int temp=arr[i];
    int j=i*2;
    while (j<=n)
    {
        if(j<n && arr[j]<arr[j+1])
        j++;
        if(arr[j]<arr[j/2])
        break;
        arr[j/2]=arr[j];
        j=j*2;
    }
    arr[j/2]=temp;
    
}
void main()
{
    int list[]={0,5,4,3,2,1};
    int i,j,n=6;
    //element before sort
    for (i = 1; i <n; i++)
    {
        printf("%d\t",list[i]);
    }//for
    //creating heap
    for ( i = 1; i <=n; i++)
    {
        createHeap(list,i);
    }
    j=n;
    for ( i = 1; i <=j; i++)
    {
        int temp;
        temp=list[1];
        list[1]=list[n];
        list[n]=temp;
        n--;
        deleteMaxAndReConstruct(list,1,n);
    }
    n=j;
    printf("\n");
    //element after sort
    for (i = 1; i <n; i++)
    {
        printf("%d\t",list[i]);
    }//for
}
