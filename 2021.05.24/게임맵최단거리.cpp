#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int visit[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps) {
    int answer = 0;
    memset(visit, 0, sizeof(visit));
    int N = maps.size(); int M = maps[0].size();
    visit[0][0] = 1;
    queue<pair<int, int> > q;
    q.push({0 ,0});
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx == N | ny == M) continue;
            if(maps[nx][ny] == 0 || visit[nx][ny]) continue;
            visit[nx][ny] = visit[p.first][p.second] + 1;
            q.push({nx, ny});
        }
    }

    answer = visit[N -1][M - 1];
    if(answer == 0) return - 1;
    return answer;
}