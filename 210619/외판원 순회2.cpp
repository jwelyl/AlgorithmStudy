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
vector<vector<int>> graph;
bool visit[11] = { false };
int n;
vector<int> cycle;
int min2 = 987654321;
void dfs() {
	if (n == cycle.size()) {
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (graph[cycle[i]][cycle[i + 1]] == 0) return;
			ans += graph[cycle[i]][cycle[i + 1]];
		}
		if (graph[cycle[n - 1]][cycle[0]] == 0) return;
		ans += graph[cycle[n - 1]][cycle[0]];
		if (ans < min2) {
			min2 = ans;
		}

		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			cycle.push_back(i + 1);
			dfs();
			cycle.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	graph = vector<vector<int>>(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		int s, e;
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			graph[i][j] = num;
		}
	}
	dfs();
	//if (min2 == 987654321) cout << "0" << endl;
	cout << min2 << endl;
	return 0;
}