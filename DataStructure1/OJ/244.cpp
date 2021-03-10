 
/*************************************************************************
   > File Name: 244.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 五  1/ 3 16:24:48 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
#define MAX_N 500
struct Data {
    int x, y;
} arr[MAX_N + 5];
int tmp[MAX_N + 5];

bool check_y(int s, int e, int l, int c) {
    int cnt = 0;
    for (int i = s; i <= e; i++) {
        tmp[cnt++] = arr[i].y;
    }
    sort(tmp, tmp + cnt);
    for (int i = c - 1; i < cnt; i++) {
        if (tmp[i] - tmp[i - c + 1] < l) return true;
    }
    return false;
}

bool check(int n, int l, int c) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (arr[i].x - arr[j].x >= l) ++j;
        if (i - j + 1 < c) continue;
        if (check_y(j, i, l, c)) return true;
    }
    return false;
}

int bs(int l, int r, int n, int c) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (check(n, mid, c)) return bs(l, mid, n, c);
    return bs(mid + 1, r, n, c);
}

bool cmp(const Data &a, const Data &b) {
    if (a.x - b.x) return a.x < b.x;
    return a.y - b.y;
}

int main() {
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    cout << bs(0, 10000, n, c) << endl;
    return 0;
}
