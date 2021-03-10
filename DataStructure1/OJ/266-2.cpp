/*************************************************************************
	> File Name: 266-2.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Feb 15:27:04 2021
 ************************************************************************/

#include<iostream>
#include<stack>

using namespace std;


class Solution{
public:
    int calculate(string s){
        int begin = 0;
        return calHelper(s, begin);
    }
    int calHelper(string s, int &i){
        char operation = '+';
        stack<int> nums;
        int num = 0;
        int res = 0;
        for(i; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] == '('){
                num = calHelper(s, ++i);//
                i++;
            }
            if(( (s[i] < '0' || s[i] > '9') && s[i] != ' ') || i >= s.size() - 1 ){
                int pre = 0;
                switch(operation){
                    case '+':
                        nums.push(num);
                        break;
                    case '-':
                        nums.push(-num);
                        break;
                    case '*':
                        pre = nums.top();
                        nums.pop();
                        nums.push(pre * num);
                        break;
                    case '/':
                        pre = nums.top();
                        nums.pop();
                        nums.push(pre / num);
                        break;
                }
                operation = s[i];
                num = 0;
            }
            if (s[i] == ')') break;
        }
        while(!nums.empty()){
            res += nums.top();
            nums.pop();
        }
        return res;

    }
};

int main (){
    Solution s;
    string c;
    cin >> c;
    cout << s.calculate(c) << endl;




    return 0;
}
