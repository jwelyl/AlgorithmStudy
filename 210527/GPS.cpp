#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
#define MAX_SIZE 201
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = INF;
	vector<int> adj[MAX_SIZE];
	int dp[100][MAX_SIZE];

	for (int i = 0; i < m; i++) {
		int r = edge_list[i][0];
		int c = edge_list[i][1];
		adj[r].push_back(c);
		adj[c].push_back(r);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][gps_log[0]] = 0;
	for (int i = 1; i < k - 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			int add = gps_log[i] == j ? 0 : 1;
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + add);
			for (const auto& e : adj[j]) {
				dp[i][j] = min(dp[i - 1][e] + add, dp[i][j]);
			}
		}
	}

	int fin = gps_log.back();
	for (const auto& e : adj[fin]) {
		answer = min(answer, dp[k - 2][e]);
	}
	answer = (answer > k - 2) ? -1 : answer;
	return answer;
}