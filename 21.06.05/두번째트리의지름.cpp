#include <bits/stdc++.h>
using namespace std;

int n;
<<<<<<< HEAD
vector<pair<int, int>> graph[MAX];
vector<int> tree[MAX];
bool visited[MAX];
int dist[MAX];
int A, B, C, D;
=======
vector<pair<int, int>> graph[100001];
vector<int> tree[100001];
bool visited[100001];
int dist[100001];
int A, B, C, D;
int ret;
>>>>>>> 53ed6b0bc53e1f45ef7ff61144e0b399386fe779
void input() {
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
<<<<<<< HEAD
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
=======
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[A]) A = i; // 가장 먼 A노드

    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    dfs(A);
    for(int i = 1; i <= n; i++) {
        if(dist[i] > dist[B]) B = i; // 가장 먼 B노드
    }
    for(int i = 1; i <= n; i++) {
        if(i == B) continue;
        if(dist[i] > dist[C]) C = i;
    }
    ret = dist[C];
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    dfs(B);
    for(int i = 1; i <= n; i++) {
        if(i == A) continue;
        if(dist[i] > dist[D]) D = i;
    }
    
    cout << max(ret, dist[D]);
>>>>>>> 53ed6b0bc53e1f45ef7ff61144e0b399386fe779
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}
