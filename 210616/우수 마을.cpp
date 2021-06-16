#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;

vector<vector<int>> graph(10001);
vector<int> cost(10001);
bool visit[10001] = { false };
int dp[10001][2];
void dfs(int start) {

	dp[start][0] = cost[start];
	dp[start][1] = 0;

	for (int i = 0; i < graph[start].size(); i++) {
		if (!visit[graph[start][i]]) {
			visit[graph[start][i]] = true;
			dfs(graph[start][i]);

			//cout << start <<" "<<graph[start][i]<< endl; //4 5 , 3 4 , 2 3
			dp[start][0] += dp[graph[start][i]][1];
			dp[start][1] += max(dp[graph[start][i]][1], dp[graph[start][i]][0]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*
	우수 마을'로 선정된 마을 주민 수의 총 합을 최대로 해야 한다.
	마을 사이의 충돌을 방지하기 위해서, 만일 두 마을이 인접해 있으면 두 마을을 모두 '우수 마을'로 선정할 수는 없다.즉 '우수 마을'끼리는 서로 인접해 있을 수 없다.
	선정되지 못한 마을에 경각심을 불러일으키기 위해서, '우수 마을'로 선정되지 못한 마을은 적어도 하나의 '우수 마을'과는 인접해 있어야 한다.*/
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	visit[1] = true;
	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << endl;
	return 0;
}