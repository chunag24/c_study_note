/*************************************************************************
	> File Name: 265.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Feb 17:06:18 2021
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>

using namespace std;


stack<char> sta;
void clear(){
    while(!sta.empty()){
        sta.pop();
    }
}

int main(){
    string s;
    cin >> s;
    int ans = 0, t = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            sta.push(s[i]);
        }else if (s[i] == ')'){
            if (sta.empty() || sta.top() != '('){
                ans = max(ans, t);
                t = 0;
                clear();
            }else if (sta.top() == '('){
                t += 2;
                sta.pop();
            }
        }else if (s[i] == ']'){
            if (sta.empty() || sta.top() != '['){
                ans = max(ans, t);
                t = 0;
                clear();
            }else if (sta.top() == '['){
                t += 2;
                sta.pop();
            }
        }else if (s[i] == '}'){
            if (sta.empty() || sta.top() != '{'){
                ans = max(ans, t);
                t = 0;
                clear();
            }else if (sta.top() == '{'){
                t += 2;
                sta.pop();
            }
        }
    }

    ans = max(ans, t);
    cout << ans << endl;

    
    return 0;

}
