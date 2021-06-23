#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, M;
int field[1001][1001];
int dist[1001][1001][2];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
void bfs(int row, int col)
{
	int r, c, nr, nc, b = 0;
	queue<pair<int, pair<int, int>>> q;
	dist[row][col][0] = 1;
	dist[row][col][1] = 1;
	q.push({ b,{ row, col } });
	while (!q.empty()) {
		r = q.front().second.first;
		c = q.front().second.second;
		b = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr <= 0 || nc <= 0 || nr > N || nc > M)
				continue;
			//벽이 아니고, 방문하지 않은 칸이라면
			if (field[nr][nc] == 0 && dist[nr][nc][b] == 0) {
				dist[nr][nc][b] = dist[r][c][b] + 1;
				q.push({ b,{ nr, nc } });
			}
			//벽을 부술 수 있고, 벽이며, 방문하지 않았다면
			else if (b == 0 && field[nr][nc] == 1 && dist[nr][nc][1] == 0) {
				dist[nr][nc][1] = dist[r][c][0] + 1;
				q.push({ 1,{ nr, nc } });
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	string buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		for (int j = 0; j < buf.length(); j++) {
			if (buf[j] == '1')
				field[i + 1][j + 1] = 1;
			else
				field[i + 1][j + 1] = 0;
		}
	}
	bfs(1, 1);
	dist[N][M][0] = dist[N][M][0] == 0 ? INF : dist[N][M][0];
	dist[N][M][1] = dist[N][M][1] == 0 ? INF : dist[N][M][1];
	if (dist[N][M][0] == INF && dist[N][M][1] == INF)
		printf("%d\n", -1);
	else
		printf("%d\n", min(dist[N][M][0], dist[N][M][1]));
	return 0;
}