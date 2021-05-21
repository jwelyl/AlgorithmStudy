#include <string>
#include <vector>
#include<queue>
using namespace std;

struct info {
	int x;
	int y;
	int cost;
	int dir;
};

int solution(vector<vector<int>> board) {
	int answer = 25 * 25 * 600;
	int visit[25][25] = { 0 };
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			visit[i][j] = 25 * 25 * 600;
		}
	}
	//0 ¾Æ·¡->À§ / 1 À§->¾Æ·¡ / 2 ¿ì->ÁÂ / 3 ÁÂ->¿ì
	queue<info> q;
	q.push({ 0, 0, 0, -1 });

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	visit[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		int dir = q.front().dir;
		q.pop();
		//0 ¾Æ·¡->À§ / 1 À§->¾Æ·¡ / 2 ¿ì->ÁÂ / 3 ÁÂ->¿ì
		if (x == board.size() - 1 && y == board.size() - 1) {
			if (cost < answer) {
				answer = cost;
				continue;
			}
		}

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board.size()) {
				if (board[nx][ny] == 1) continue;
				//0, 0, 0, 0

				int pay = 0;
				if (dir == -1 || dir == i) pay = cost + 100;
				else pay = cost + 600;

				if (pay <= visit[nx][ny]) {
					visit[nx][ny] = pay;
					q.push({ nx, ny, pay, i });
				}
				//1, 0, 100, 0
			}
		}

	}

	return answer;
}