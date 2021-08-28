//Title:- Parse Int
//coder:- Pavan Chavan
//Email:- pavan.21920161@viit.ac.in
//date:- 28/8/2021

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int>result;
    int i=0,temp=0,flag=0;
    while (1) {
        if (str[i]==',') {
            if (flag==1) {
            result.push_back(-temp);
            }
            else {
            result.push_back(temp);
            }
            i++;
            flag=0;
            temp=0;
            continue;
        }
        if (str[i]=='\0') {
            if (flag==1) {
            result.push_back(-temp);
            }
            else {
            result.push_back(temp);
            }
            return result;
        }
        if (str[i]=='-') {
            flag=1;
            i++;
            continue;
        }
        else {
            int a=str[i]-48;
            temp=(temp*10)+a;
            i++;
        }
    }
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}