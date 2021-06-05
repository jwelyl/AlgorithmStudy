#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001
using namespace std;

int n;
vector<pair<int, int>> graph[MAX];
vector<int> tree[MAX];
bool visited[MAX];
int dist[MAX];
void input() {
    memset(visited, false, sizeof(visited));

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}

void dfs(int idx) {
    visited[idx] = 1;
    for(auto next : graph[idx]) {
        if(visited[next.first]) tree[next.first].push_back(idx);
        else {
            dist[next.first] = dist[idx] + next.second;
            dfs(next.first);
        }
    }
}

void pro() {
    dfs(1);
    int value = 0;
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[value]) value = i;

    fill(visited, visited + MAX, 0);
    fill(dist, dist + MAX, 0);

    dfs(value);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[value]) value = i;
    
    cout << dist[value];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}