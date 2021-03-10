/*************************************************************************
	> File Name: decimalConverter.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Feb 13:13:10 2021
 ************************************************************************/
#include<stack>
#include<iostream>
using namespace std;


int main(){
    int r, n;
    stack<int> s;
    cin >> n >> r;
    while(n){
        s.push(n % r);
        n = n / r;
    }
    while(!s.empty()){
        switch(s.top()){
            case 10: cout <<'A'; break;
            case 11: cout <<'B'; break;
            case 12: cout <<'C'; break;
            case 13: cout <<'D'; break;
            case 14: cout <<'E'; break;
            case 15: cout <<'F'; break;
            default: cout << s.top(); break;
        }
        s.pop();
    }
    return 0;
}
