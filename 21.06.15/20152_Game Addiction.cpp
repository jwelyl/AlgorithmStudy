/*
Problem : https://www.acmicpc.net/problem/20152
Comment : 대각선 하단 기준으로 보면 되기 때문에 
          1. 아래로 가거나 오른쪽 가면서 범위확인하기
          2. 도착할 수 있다면 갈 수 있는 경로
*/

#include <bits/stdc++.h>
using namespace std;
int H, N, answer;
long long dp[31][31]; // x와 y 일 때의 갈 수 있는 경우
void input() {
    cin >> H >> N;
    memset(dp, 0, sizeof(dp));
}

long long findPC(int x, int y) {
    if(x < y) return 0;
    if(x > N || y > N) return 0;
    if(x == N && y == N) return 1;
    
    long long ret = dp[x][y];
    if(ret != 0) return dp[x][y];

    ret = findPC(x + 1, y) + findPC(x, y + 1);
    return dp[x][y] = ret;
}

int pro() {
    if(H > N) swap(H, N);
    cout << findPC(H, H) << "\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
}
