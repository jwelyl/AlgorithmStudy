#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> port(n + 1);
	int s, e;
	cin >> s >> e;
	bool visit[300001] = { false };
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		port[x].push_back(y);
		port[y].push_back(x);
	}
	queue<pair<int, int>> q;
	q.push({ s,0 });

	int dx[2] = { 1,-1 };

	while (!q.empty()) {
		int loc = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (loc == e) {
			cout << cost << endl;
			break;
		}

		if (port[loc].size() > 0) {
			for (int i = 0; i < port[loc].size(); i++) {
				if (!visit[port[loc][i]]) {
					q.push({ port[loc][i], cost + 1 });
					visit[port[loc][i]] = true;
				}

			}
		}

		for (int i = 0; i < 2; i++) {
			int next = loc + dx[i];
			if (next<0 || next>n) continue;
			if (!visit[next]) {
				q.push({ next,cost + 1 });
				visit[next] = true;
			}
		}

	}
	return 0;
}