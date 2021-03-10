/*************************************************************************
	> File Name: oj-600.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed  4 Nov 07:50:33 2020
 ************************************************************************/

#include<iostream>
using namespace std;


int n, m, t , num[3005][3005];

int main(){
    scanf("%d%d%d", %n, %m, %t);
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &num[i][j]);
        }
    }
    int x = n, y = 1;
    while(1){
        if( num[x][y] == t){
            cout << x << " " << y < endl;
            return 0;
        }
        if (num[x][y] > t ){
            x--;
        }else {
            y++;
        }
    }
    cout << -1 << endl;
    return 0;
}

