#include <bits/stdc++.h>
using namespace std;

int MOD = 20170805;
int M, N;
int dp[501][501][2];
int dx[] = {1, 0};
int dy[] = {0, 1};
vector<vector<int> > citys;
int go(int x, int y, int type) {
    if(x == M - 1 && y == N - 1) return 1;
    
    int ret = dp[x][y][type];
    if(ret != -1) return dp[x][y][type];
    ret = 0;
    
    for(int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if(citys[x][y] == 0 || (citys[x][y] == 2 && i == type))
                ret += go(nx, ny, i) % MOD;
        }
    }
    return dp[x][y][type] = ret % MOD;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    M = m; N = n;
    citys = city_map;
    memset(dp, -1, sizeof(dp));
    
    answer = go(0, 0, 0);
    return answer;
}
