#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct info {
	int x1;
	int y1;
	int x2;
	int y2;
	int cost;
};
bool visit[101][101][101][101] = { false };

int solution(vector<vector<int>> board) {
	int answer = 987654321;
	queue<info> q;
	q.push({ 0,0,0,1,0 });
	visit[0][0][0][1] = true;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	while (!q.empty()) {
		int nx1 = q.front().x1;
		int ny1 = q.front().y1;
		int nx2 = q.front().x2;
		int ny2 = q.front().y2;
		int nCost = q.front().cost;

		q.pop();
		if ((nx1 == board.size() - 1 && ny1 == board.size() - 1) ||
			(nx2 == board.size() - 1 && ny2 == board.size() - 1)) {
			if (nCost < answer) {
				answer = nCost;
			}
		}
		for (int i = 0; i < 4; i++) {
			int x1 = nx1 + dx[i];
			int y1 = ny1 + dy[i];
			int x2 = nx2 + dx[i];
			int y2 = ny2 + dy[i];

			if (x1 < 0 || x1 >= board.size() || y1 < 0 || y1 >= board.size()
				|| x2 < 0 || x2 >= board.size() || y2 < 0 || y2 >= board.size()) continue;
			if (board[x1][y1] == 1 || board[x2][y2] == 1) continue;

			if (!visit[x1][y1][x2][y2]) {
				visit[x1][y1][x2][y2] = true;
				q.push({ x1,y1,x2,y2,nCost + 1 });
			}
		}
		//뒤집기 차례
		int x1 = nx1;
		int y1 = ny1;
		int x2 = nx2;
		int y2 = ny2;
		if (ny1 == ny2) { //세로인 경우
			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					x2 = nx1;
					y2 = ny1;
					x1 = nx2 - 1;
					y1 = ny2 - 1;
				}
				else if (i == 1) {
					x1 = nx1 + 1;
					y1 = ny1 - 1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (i == 2) {
					x1 = nx1;
					y1 = ny1;
					x2 = nx2 - 1;
					y2 = ny2 + 1;
				}
				else if (i == 3) {
					x2 = nx1 + 1;
					y2 = ny1 + 1;
					x1 = nx2;
					y1 = ny2;

				}
				if (x1 < 0 || x1 >= board.size() || y1 < 0 || y1 >= board.size()
					|| x2 < 0 || x2 >= board.size() || y2 < 0 || y2 >= board.size()) continue;
				if (board[x1][y1] == 1 || board[x2][y2] == 1) continue;

				if (i == 0) {
					if (x1 + 1 >= board.size() || board[x1 + 1][y1] == 1) continue;
				}
				if (i == 1) {
					if (x1 - 1 < 0 || board[x1 - 1][y1] == 1) continue;
				}
				if (i == 2) {
					if (x2 + 1 >= board.size() || board[x2 + 1][y2] == 1) continue;
				}
				else if (i == 3) {
					if (x2 - 1 < 0 || board[x2 - 1][y2] == 1) continue;
				}

				if (!visit[x1][y1][x2][y2]) {
					visit[x1][y1][x2][y2] = true;
					q.push({ x1,y1,x2,y2,nCost + 1 });
				}
			}
		}
		else { //가로인경우
			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					x2 = nx1;
					y2 = ny1;
					x1 = nx1 - 1;
					y1 = ny1;
				}
				else if (i == 1) {
					x1 = nx1;
					y1 = ny1;
					x2 = nx2 + 1;
					y2 = ny2 - 1;
				}
				else if (i == 2) {
					x1 = nx1 - 1;
					y1 = ny1 + 1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (i == 3) {
					x1 = nx2;
					y1 = ny2;
					x2 = nx1 + 1;
					y2 = ny1 + 1;
				}

				if (x1 < 0 || x1 >= board.size() || y1 < 0 || y1 >= board.size()
					|| x2 < 0 || x2 >= board.size() || y2 < 0 || y2 >= board.size()) continue;
				if (board[x1][y1] == 1 || board[x2][y2] == 1) continue;

				if (i == 0) {
					if (y1 + 1 >= board.size() || board[x1][y1 + 1] == 1) continue;
				}
				if (i == 1) {
					if (y2 + 1 >= board.size() || board[x2][y2 + 1] == 1) continue;
				}
				if (i == 2) {
					if (y1 - 1 < 0 || board[x1][y1 - 1] == 1) continue;
				}
				if (i == 3) {
					if (y2 - 1 < 0 || board[x2][y2 - 1] == 1) continue;
				}

				if (!visit[x1][y1][x2][y2]) {
					visit[x1][y1][x2][y2] = true;
					q.push({ x1,y1,x2,y2,nCost + 1 });
				}
			}

		}

	}
	return answer;
}