#include <vector>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
struct info {
	int x;
	int y;
};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int num = 0;
	int max = 0;
	vector<int> answer(2);

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	vector<vector<bool>> visit(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] > 0 && !visit[i][j]) {
				visit[i][j] = true;

				queue<info> q;

				q.push({ i,j });
				num++;
				int start = picture[i][j];
				int max2 = 1;

				while (!q.empty()) {
					int nx = q.front().x;
					int ny = q.front().y;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int x = nx + dx[k];
						int y = ny + dy[k];

						if (x < 0 || x >= m || y < 0 || y >= n) continue;

						if (!visit[x][y] && picture[x][y] == start) {
							visit[x][y] = true;
							q.push({ x,y });
							max2++;
						}
					}
				}

				if (max < max2) {
					max = max2;
				}
			}

		}
	}
	answer[0] = num;
	answer[1] = max;

	return answer;
}