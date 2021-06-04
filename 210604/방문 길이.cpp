#include <string>
using namespace std;
#define MAX_SIZE 11
int dirRow[] = { -1, 1, 0, 0 };
int dirCol[] = { 0, 0, 1, -1 };
bool visit[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
int solution(string dirs) {
	int answer = 0;
	int dir = 0;
	int r = MAX_SIZE / 2, c = MAX_SIZE / 2, nr, nc;
	for (const auto& d : dirs) {
		if (d == 'U')
			dir = 0;
		else if (d == 'D')
			dir = 1;
		else if (d == 'R')
			dir = 2;
		else if (d == 'L')
			dir = 3;

		nr = r + dirRow[dir];
		nc = c + dirCol[dir];
		if (nr < 0 || nc < 0 || nr >= MAX_SIZE || nc >= MAX_SIZE)
			continue;
		if (visit[r][c][nr][nc] == false) {
			//방향을 따지지 않음
			visit[r][c][nr][nc] = true;
			visit[nr][nc][r][c] = true;
			answer++;
		}
		r = nr;
		c = nc;
	}
	return answer;
}