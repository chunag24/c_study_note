/*************************************************************************
	> File Name: 71.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Feb 10:05:51 2021
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000
struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n){
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x){
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        fa[x] = root;
        return root;
        //return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b){
        fa[get(a)] = get(b);
    }
};

UnionSet u;
int main(){
    int n, m;
    cin >> n >> m;
    cout << endl;
    u.init(n);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if ( a == 1 ){
            u.merge(b, c);
        }else{
            cout << (u.get(b) == u.get(c) ? "Yes" : "No") <<endl;
        }
    }
    return 0;
}
