/*************************************************************************
	> File Name: 268.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Feb 10:29:05 2021
 ************************************************************************/

#include<iostream>
#include<map>
#include<queue>

using namespace std;
#define MAX_N 1000

map<int, int> q_ind;
queue<int> main_q;
queue<int> q[MAX_N + 5];


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        for (int j = 0; j < m; j++){
            int a;
            cin >> a; 
            q_ind[a] = i;
        }
    }
    string op;
    while (cin >> op){
        if (op == "STOP") break;
        if (op == "ENQUEUE") {
            int x;
            cin >> x;
            q[q_ind[x]].push(x);
            if (q[q_ind[x]].size() == 1) main_q.push(q_ind[x]);
        }else{
            cout << q[main_q.front()].front() << endl;
            q[main_q.front()].pop();
            if (q[main_q.front()].empty()) main_q.pop();
        }
    }
    return 0;
}

