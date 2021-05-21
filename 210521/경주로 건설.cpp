#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_SIZE 25
#define INF 987654321
int N;
queue<pair<int, pair<int, int>>>q;
int field[MAX_SIZE][MAX_SIZE][4];
vector<vector<int>> _board;
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
const int line = 100;
const int corner = 600;
void bfs(int row, int col)
{
	for (int i = 0; i < 4; i++) {
		q.push({ i,{ row, col } });
		field[row][col][i] = 0;
	}
	int r, c, nr, nc, d, nd;
	while (!q.empty()) {
		d = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			nd = i;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (_board[nr][nc] == 1)
				continue;
			if (d == nd) {
				if (field[nr][nc][nd] > field[r][c][d] + line) {
					field[nr][nc][nd] = field[r][c][d] + line;
					q.push({ nd,{ nr, nc } });
				}
			}
			else {
				if (field[nr][nc][nd] > field[r][c][d] + corner) {
					field[nr][nc][nd] = field[r][c][d] + corner;
					q.push({ nd,{ nr, nc } });
				}
			}
		}
	}
}
int solution(vector<vector<int>> board) {
	int answer = INF;
	N = board.size();
	_board = board;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				field[i][j][k] = INF;
			}
		}
	}
	bfs(0, 0);
	for (int i = 0; i < 4; i++) {
		answer = min(answer, field[N - 1][N - 1][i]);
	}
	return answer;
}