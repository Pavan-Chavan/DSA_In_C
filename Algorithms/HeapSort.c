//Title :- Heap Sort
//code:- pavan chavan
//email:- pavan.21920161@viit.ac.in
//date :- 21/7/2021

#include<stdio.h>

//create heap 
void createHeap(int arr[],int i)
{
    int temp=arr[i];
    while ((i>1) && arr[i/2]<arr[i])  //i is starting from child and we runing this loop until we
    {                                //we get parent i.e (i>1) as well parent must greter than child
        arr[i]=arr[i/2];            //if parent is smaller copie parent to child`s position
        i=i/2;                      //shifting pointer to parent node
    }                               //when this loop end we get correct position for new added element 
    arr[i]=temp;                    //placing new added element to correct position
    
}

//this fun will call after swaping root of tree with last element in array
// now we have to adjust heap again
void deleteMaxAndReConstruct(int arr[],int i,int n) 
{
    int temp=arr[i];                        //i is locating at root and we need to find correct positin for
    int j=i*2;                              // list[i]  j is lookng at parent of i
    while (j<=n)                            // loop will execute until we reach to last child/node
    {
        if(j<n && arr[j]<arr[j+1])          //checking which child node is greater 
        j++;                                //locating at biger node
        if(arr[j]<arr[j/2])                 //checking is parent is greter than child or not
        break;                              // if all ok then break the loop
        arr[j/2]=arr[j];                    // if not then interchange their position
        j=j*2;                              // location to child position
    }
    arr[j/2]=temp;                          // after finding correct position for root it will store 
}

void main()
{
    int list[]={0,5,4,3,2,1};       // demo list user can change as per requiment
    int i,j,n=6;

    //element before sort
    for (i = 1; i <n; i++)
    {
        printf("%d\t",list[i]);
    }//for

    //creating heap
    for ( i = 1; i <n; i++)
    {
        createHeap(list,i);
    }

    j=n;                            //now j will hold size of array
    for ( i = 1; i <=j; i++)
    {
        int temp;
        temp=list[1];
        list[1]=list[n];            //interchanging root and last element in the tree
        list[n]=temp;               // stroring root to last element in the list 
        n--;                        // ignoring last recently sorted element 
        deleteMaxAndReConstruct(list,1,n);  // recontructing the heap after changing root
    }
    n=j;                            // now n will hold the size of list
    printf("\n");

    //element after sort
    for (i = 1; i <n; i++)
    {
        printf("%d\t",list[i]);
    }//for
}//main
