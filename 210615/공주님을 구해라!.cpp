#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;
struct info {
	int x;
	int y;
	int exist;
	int cost;
};

int main() {

	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int loc;
			cin >> loc;
			v[i][j] = loc;
		}
	}
	queue<info> q;
	bool visit[101][101][2] = { false };

	q.push({ 0,0,false,0 });
	visit[0][0][0] = true;
	int dx[4] = { -1, 1, 0,0 };
	int dy[4] = { 0, 0, -1,1 };
	int ans = 987654321;

	bool flag = false;

	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int exist = q.front().exist;
		int nCost = q.front().cost;
		q.pop();

		if (nx == n - 1 && ny == m - 1 && nCost <= t) {
			if (nCost < ans) ans = nCost;
			break;
		}

		if (v[nx][ny] == 2) exist = 1;

		for (int i = 0; i < 4; i++) {
			int x = nx + dx[i];
			int y = ny + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (exist == 0 && v[x][y] == 1) continue;

			if (!visit[x][y][exist]) {
				visit[x][y][exist] = true;
				q.push({ x,y,exist,nCost + 1 });
			}

		}
	}

	if (ans == 987654321) cout << "Fail" << endl;
	else cout << ans << endl;
	return 0;
}