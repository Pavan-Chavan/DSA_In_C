//Title :-fibonacci series using greedy algoritham  
//code:- pavan chavan
//email:- pavan.21920161@viit.ac.in
//date :- 30/7/2021
#include<bits/stdc++.h>
using namespace std;
int feb(int n)
{
  if(n==0)
  return 0;

  if(n==1)
  return 1;

  return feb(n-1)+feb(n-2);
}

int main()
{
    cout<<feb(6);
}