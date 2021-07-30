//Title :-fibonacci series using dynamic algoritham  
//code:- pavan chavan
//email:- pavan.21920161@viit.ac.in
//date :- 30/7/2021
#include<bits/stdc++.h>
using namespace std;
int record[7]={-1,-1,-1,-1,-1,-1,-1};
int feb(int n)
{
    if(record[n]!=-1)
    return record[n];

    if(n==0)
    return 0;

    if(n==1)
    return 1;

    record[n]=feb(n-1)+feb(n-2);
    //cout<<record[n];
    return record[n];
}

int main()
{
    cout<<feb(6);
}