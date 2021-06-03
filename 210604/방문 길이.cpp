#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {
	int answer = 0;
	bool visit[11][11][4] = { false };
	int nx = 5;
	int ny = 5;
	int dir = -1;
	//u == dir1 //d == dir2 //l == dir3 //r == dir4
	for (int i = 0; i < dirs.size(); i++) {
		int x = nx;
		int y = ny;

		if (dirs[i] == 'U') {
			x = nx - 1;
			y = ny;
			dir = 1;
			visit[nx][ny][2] = true;
		}
		else if (dirs[i] == 'D') {
			x = nx + 1;
			y = ny;
			dir = 2;
			visit[nx][ny][1] = true;
		}
		else if (dirs[i] == 'L') {
			x = nx;
			y = ny - 1;
			dir = 3;
			visit[nx][ny][4] = true;
		}
		else if (dirs[i] == 'R') {
			x = nx;
			y = ny + 1;
			dir = 4;
			visit[nx][ny][3] = true;
		}

		if (x < 0 || x>10 || y < 0 || y>10) continue;
		if (!visit[x][y][dir]) {
			answer++;
			visit[x][y][dir] = true;

		}
		nx = x;
		ny = y;
	}
	return answer;
}