/*
Problem : https://www.acmicpc.net/problem/14496
Comment : bfs돌리면서 b에 도착하면 정답!
*/
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int a, b, n, m;
int visited[MAX];
vector<int> graph[MAX];
void input() {
    cin >> a >> b;
    cin >> n >> m;
    fill(visited, visited+MAX, -1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void pro() {
    queue<int> q;
    q.push(a);
    visited[a] = 0;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        if(here == b) {
            cout << visited[here];
            return;
        }
        for(int next : graph[here]) {
            if(visited[next] == -1) {
                q.push(next);
                visited[next] = visited[here] + 1;
            }
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}