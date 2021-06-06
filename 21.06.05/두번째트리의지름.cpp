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
int A, B, C, D;
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
    for(int i = 1; i <= n; i++) {
        if(dist[i] > dist[A]) A = i;
    }

    for(int i = 1; i <= n; i++) {
        if(i == A) continue;
        else if(dist[i] > dist[C]) C = i;
    }

    fill(visited, visited + MAX, 0);
    fill(dist, dist + MAX, 0);
    dfs(A);
    for(int i = 1; i <= n; i++) {
        if(dist[i] > dist[B]) B = i;
    }
    int ret = dist[B];

    fill(visited, visited + MAX, 0);
    fill(dist, dist + MAX, 0);
    dfs(C);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[D]) D = i;

    cout << min(dist[D], ret);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}