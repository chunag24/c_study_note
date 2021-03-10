/*************************************************************************
	> File Name: 266.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Feb 11:38:31 2021
 ************************************************************************/

#include<iostream>
#include<stack> 

using namespace std;


int calculate(string s){
    stack<int> stk;
    int num = 0;
    char sign = '+';
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if (isdigit(c)){
            num = 10 * num + (c - '0');
        }
            num = calculate(s);
            if((!isdigit(c) && c != ' ') || i == s.size() - 1){
            switch(sign){
                int pre;
                case '+':
                    stk.push(num); break;
                case '-':
                    stk.push(-num); break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre*num);
                    break;
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre/num);
                    break;
            }
            sign = c;
            num = 0;
            }
           
        
    }
    int result = 0;
    while(!stk.empty()){
        result += stk.top();
        stk.pop();
    }
    
    return result;

}


int main(){
    string c;
    cin >> c;
    cout << calculate(c) << endl;

}
