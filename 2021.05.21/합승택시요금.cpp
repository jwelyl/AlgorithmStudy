#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dist[201][201];

void solve(int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j ++){
            dist[i][j] = INF;
        }
    }
    for(int i = 1; i <=n; i++) dist[i][i] = 0;

    for(int i = 0; i < fares.size(); i++) {
        int u = fares[i][0];
        int v = fares[i][1];
        int len = fares[i][2];
        dist[u][v] = len;
        dist[v][u] = len;
    }
    
    solve(n);
    
    for(int i = 1; i <= n; i++) {
        if(dist[s][i] == INF || dist[i][a] == INF || dist[i][b] == INF) continue;
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    return answer;
}