/*
Problem : https://www.acmicpc.net/problem/10974
Comment : 경우의수에 따라 찾아보자
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int used[10];
int selected[10];
void input() {
    cin >> N;
}

void go(int idx) {
    if(idx == N) {
        for(int i = 0; i < N; i++) cout << selected[i] << ' ';
        cout << "\n";
    }
    for(int i = 1; i <= N; i++) {
        if(used[i]) continue;
        used[i] = 1;
        selected[idx] = i;
        go(idx + 1);
        used[i] = 0;
        selected[idx] = 0;
    }
}

void pro() {
    go(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}