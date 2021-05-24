#include<vector>
#include<queue>
using namespace std;
struct info {
	int x;
	int y;
	int value;
};
int solution(vector<vector<int> > maps)
{
	int answer = 987654321;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	//bool visit[101][101] = { false };
	int visit[101][101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visit[i][j] = 987654321;
		}
	}
	queue<info> q;
	q.push({ 0,0,1 });

	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int nValue = q.front().value;
		q.pop();
		if (nx == maps.size() - 1 && ny == maps[0].size() - 1) {
			if (nValue < answer) {
				answer = nValue;
			}
		}

		for (int i = 0; i < 4; i++) {
			int x = nx + dx[i];
			int y = ny + dy[i];
			int value = nValue + 1;
			if (x < 0 || x >= maps.size() || y < 0 || y >= maps[0].size()) continue;
			if (maps[x][y] == 0) continue;
			if (value < visit[x][y]) {
				visit[x][y] = value;
				q.push({ x,y,value });
			}
		}
	}
	if (answer == 987654321) {
		return -1;
	}

	return answer;
}