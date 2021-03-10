/*************************************************************************
	> File Name: 263.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Feb 20:33:33 2021
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>


using namespace std;
#define MAX_N 20
int arr[MAX_N + 5];

bool is_valid(int *arr, int n){
    stack<int> s;
    int temp = 0;
    for(int i = 0; i < n; i++){
        while( temp < arr[i] ) {
            
            s.push(++temp);
            cout << "pushing " << temp << " into stack with i = " << i << " and arr[i]= "<< arr[i] <<endl;
        }
        if(s.top() - arr[i]) return false;
        cout << "popping "<< s.top() << "out of the stack"<< endl;
        s.pop();
    }
    return true;
}

void print(int *arr, int n){
    cout << "This is printed:";
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
    cout << endl;
    return;
}

int main(){
    int n, cnt = 20;
    cin >> n;
    for( int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    do{
        print(arr, n);
        if(is_valid(arr, n)){
            cout << "Valid output: ";
            for(int i = 0; i < n; i++){
                cout << arr[i];
            }
            cout << endl;
            cout <<"NNNNNNNNNNNNNNNNNNNNNNN"<<endl;
            cnt--;
        }
    }while(next_permutation(arr, arr + n) && cnt);// nxt permutation represents the next availalbe sort order

    return 0;
}
