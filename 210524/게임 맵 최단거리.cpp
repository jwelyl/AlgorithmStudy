#include<vector>
#include <queue>
using namespace std;
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
int dist[100][100];
vector<vector<int>> _maps;
int bfs(int row, int col)
{
	int MaxRow = _maps.size();
	int MaxCol = _maps[0].size();
	int r, c, nr, nc;
	dist[row][col] = 1;
	queue<pair<int, int>> q;
	q.push({ row, col });
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= MaxRow || nc >= MaxCol)
				continue;
			if (_maps[nr][nc] == 1 && dist[nr][nc] == 0) {
				q.push({ nr, nc });
				dist[nr][nc] = dist[r][c] + 1;
			}
		}
	}
	if (dist[MaxRow - 1][MaxCol - 1] == 0)
		return -1;
	else
		return dist[MaxRow - 1][MaxCol - 1];
}
int solution(vector<vector<int> > maps)
{
	int answer = 0;
	_maps = maps;
	answer = bfs(0, 0);
	return answer;
}