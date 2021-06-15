#include <bits/stdc++.h>
#define MAX 103
using namespace std;

struct Node {
    int x, y, cnt, sword;
};
int graph[MAX][MAX];
int visited[MAX][MAX][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int flag, answer;
int n, m, t;

bool isOk(int x, int y) {
    return y >= 0 && y < m && x >= 0 && x < n;
}

void input() {
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> graph[i][j];
}

void bfs() {
    queue<Node> q;
    visited[0][0][0] = 1;
    q.push({0, 0, 1, 0});

    while(!q.empty()) {
        Node node = q.front();
        q.pop();

        if(graph[node.x][node.y] == 2) node.sword = 1;
        if(node.x == n - 1 && node.y == m - 1) {
            answer = node.cnt - 1;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if(node.sword) {
                if(isOk(nx, ny) && visited[nx][ny][node.sword] == 0) {
                    visited[nx][ny][node.sword] = node.cnt + 1;
                    q.push({nx, ny, node.cnt + 1, node.sword});
                }
            }
            else {
                if(isOk(nx, ny) && visited[nx][ny][0] == 0 && graph[nx][ny] != 1) {
                    visited[nx][ny][0] = node.cnt + 1;
                    q.push({nx, ny, node.cnt + 1, node.sword});
                }
            }
        }
    }
}

void pro() {
    bfs();
    if(answer > 0 && answer <= t) cout << answer;
    else cout << "Fail";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
}