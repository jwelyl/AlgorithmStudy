#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visit;
vector<vector<bool>> visit2;
vector<pair<int, int>> v[2];
bool visited[101] = { false };
vector<pair<int, int>> p;
int ans = 0;
bool check(pair<int, int> loc) {
	bool chk = true;
	int n = board.size();
	int x = loc.first;
	int y = loc.second;

	while (x >= 0 && y >= 0) {
		x--; y--;
		if (x < 0 || y < 0) break;

		if (visit[x][y]) {
			return false;
		}
	}
	x = loc.first, y = loc.second;
	while (x >= 0 && y < n) {
		x--; y++;
		if (x < 0 || y >= n) break;

		if (visit[x][y]) {
			return false;
		}
	}

	x = loc.first, y = loc.second;
	while (x < n && y >= 0) {
		x++; y--;
		if (x >= n || y < 0) break;

		if (visit[x][y]) {
			return false;
		}
	}

	x = loc.first, y = loc.second;
	while (x < n && y < n) {
		x++; y++;
		if (x >= n || y >= n) break;

		if (visit[x][y]) {
			return false;
		}
	}
	return true;
}

void dfs(int start, int color) {

	for (int i = start; i < v[color].size(); i++) {
		if (!visited[i]) {
			visited[i] = true;

			if (check({ v[color][i] })) {
				p.push_back(v[color][i]);
				visit[v[color][i].first][v[color][i].second] = true;
				dfs(i + 1, color);

				visit[v[color][i].first][v[color][i].second] = false;
				if (ans < p.size()) ans = p.size();
				p.pop_back();

			}

			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	board = vector<vector<int>>(n, vector<int>(n));
	visit = vector<vector<bool>>(n, vector<bool>(n));
	visit2 = visit;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
					v[0].push_back({ i,j });
				else v[1].push_back({ i,j });
			}
		}
	}
	dfs(0, 0); //Èæ»ö
	int temp = ans;
	ans = 0;

	dfs(0, 1); //¹é»ö
	cout << temp + ans << endl;
	return 0;
}