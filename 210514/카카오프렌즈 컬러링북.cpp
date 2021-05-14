#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_SIZE 100
int visit[MAX_SIZE][MAX_SIZE];
int dirRow[] = { -1, 1, 0, 0 };
int dirCol[] = { 0, 0, -1, 1 };
int M, N;
void setting()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
}
int bfs(int i, int j, vector<vector<int>>& picture, int area)
{
	queue<pair<int, int>> q;
	visit[i][j] = true;
	q.push({ i, j });
	int nr, nc, r, c, cnt = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= M || nc >= N)
				continue;
			if (visit[nr][nc] == 0 && picture[nr][nc] == area) {
				q.push({ nr, nc });
				visit[nr][nc] = area;
				++cnt;
			}
		}
	}
	return cnt;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	M = m;
	N = n;
	setting();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0 && picture[i][j] != 0) {
				++number_of_area;
				max_size_of_one_area =
					max(max_size_of_one_area, bfs(i, j, picture, picture[i][j]));
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}