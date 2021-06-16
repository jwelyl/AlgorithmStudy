/*
Problem : https://www.acmicpc.net/problem/14852
Comment : 1차원 배열로 하게 되면 시간초과발생... 
*/
#include <bits/stdc++.h>
#define MAX 1000001
#define MOD 1000000007
using namespace std;

int N;
long long int dp[MAX][2];
void input() {
    cin >> N;
}

void pro() {
    dp[0][0] = 0; 
    dp[1][0] = 2;
    dp[2][0] = 7; dp[2][1] = 1;
    
    for(int i = 3; i <= N; i++) {
        dp[i][1] = (dp[i - 1][1] + dp[i - 3][0]) % MOD;
        dp[i][0] = (3*dp[i - 2][0] + 2*dp[i - 1][0] + 2*dp[i][1]) % MOD;
    }
    cout << dp[N][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}