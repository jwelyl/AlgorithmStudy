/*
Problem : https://www.acmicpc.net/problem/14496
Comment : bfs돌리면서 b에 도착하면 정답!
*/
#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int N;
int graph[MAX][MAX];
int visited[MAX][MAX];
int color[MAX][MAX];
int dx[] = {1, -1, 1, -1};
int dy[] = {-1, 1, 1, -1};
int answer[] = {0, 0};
void input() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(i % 2 == 0) {
                if(j % 2 == 0) color[i][j] = 1;
            }
            else if(j % 2 == 1) color[i][j] = 1;
        }
    }
}

void get_ans(int idx, int cnt, int col) {
    answer[col] = max(cnt, answer[col]);

    for(int i = idx; i < N * N; i++) {
        int x = i / N;
        int y = i % N;

        if(color[x][y] != col || !graph[x][y]) continue; // 대각선이 아니거나 비숍을 놓을 수 없다면
        bool isOk = true;
        for(int j = 0; j < 4; j++) {
            int nx = x, ny = y;

            while(true) {
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                if(visited[nx][ny]) {
                    isOk = false;
                    j = 4;
                    break;
                }
                nx += dx[j]; ny += dy[j];
            }
        }
        if(!isOk) continue;
        visited[x][y] = 1;
        get_ans(i, cnt + 1, col);
        visited[x][y] = 0;
    }
}

void pro() {
    get_ans(0, 0, 0);
    get_ans(0, 0, 1);
    cout << answer[0] + answer[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}