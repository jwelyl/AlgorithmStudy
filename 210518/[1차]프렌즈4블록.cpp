#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	vector<vector<char>> v(board.size());

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			v[i].push_back(board[i].at(j));
		}
	}
	//x+1, y+1, x+1y+1; 3가지의 경우
	int dx[3] = { 1,0,1 };
	int dy[3] = { 0,1,1 };
	while (1) {
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				char c = v[i][j];
				if (c == '0') continue;
				for (int k = 0; k <= 3; k++) {
					if (k == 3) {
						visit[i][j] = true;
						visit[i + 1][j] = true;
						visit[i][j + 1] = true;
						visit[i + 1][j + 1] = true;
						break;
					}//검사 무사
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || x >= m || y < 0 || y >= n) break;
					if (c != v[x][y]) break;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j]) {
					cnt++;
					v[i][j] = '0';
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == '0') { // 떨어져야 한다.
					int bottomX = i;
					while (bottomX < m && v[bottomX][j] == '0') {

						int upX = bottomX - 1;
						if (upX < 0) break;
						for (int k = upX; k >= 0; k--) {
							v[k + 1][j] = v[k][j];
							v[k][j] = '0';
						}
						bottomX++;
					}
				}
			}
		}
		answer += cnt;
		if (cnt == 0)
			break;
	}
	return answer;
}