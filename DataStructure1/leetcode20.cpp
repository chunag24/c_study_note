/*************************************************************************
	> File Name: leetcode20.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Feb 18:07:03 2021
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;



class Solution{
    public:
    bool isValid(string s){
        unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6}};
        stack<char> str;
        bool istrue = true;
        for (char c : s){
            int flag = m[c];
            if( flag >= 1 && flag <= 3 ){
                str.push(c);
            }else if( !str.empty() && m[str.top()] == flag - 3 ){
                str.pop();
            }else{
                istrue = false;
                break;
            }
        }
        if(!str.empty()) istrue = false;
        return istrue;
    }
};

int main(){
    Solution solution;
    solution.isValid("()");
    return 0;
}
