#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > graph;
long long answer;
void go(vector<long long> &result, int now, int prev) {
    for(int ref : graph[now]) {
        if(ref != prev) go(result, ref, now);
    }
    
    long long temp = result[now];
    result[prev] += temp;
    answer += abs(temp);
    if(now != 0) result[now] = 0;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> result(a.size());
    for(int i = 0; i < a.size(); i++) result[i] = a[i];
    
    graph.resize(a.size());
    for(int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    go(result, 0, 0);
    
    if(result[0] == 0) return answer;
    else return -1;
}
