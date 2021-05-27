#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;
vector<vector<int>> graph;
int dp[101][201];

int go(int time, int here, vector<int> &gps_log) {
    if(time == 0) {
        if(here != gps_log[0]) return MAX;
        return 0;
    }
    
    int ret = dp[time][here];
    if(ret != -1) return ret;
    ret = MAX;
    
    for(auto next : graph[here])
        ret = min(ret, go(time - 1, next, gps_log));
    
    if(here != gps_log[time]) ret++;
    return dp[time][here] = ret;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    
    memset(dp, -1, sizeof(dp));
    graph = vector<vector<int>>(n + 1);
    for(auto ref : edge_list) {
        int x = ref[0]; int y = ref[1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++) graph[i].push_back(i);
    
    answer = go(k - 1, gps_log[k - 1], gps_log);
    if(answer >= MAX) answer = -1;
    return answer;
}