#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else return b;
}
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = 0;
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		graph[edge_list[i][0]].push_back(edge_list[i][1]);
		graph[edge_list[i][1]].push_back(edge_list[i][0]);
	}
	int dp[201][201];
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			dp[i][j] = 987654321;
		}
	}
	dp[0][gps_log[0]] = 0;

	for (int i = 1; i < gps_log.size(); i++) {
		for (int j = 1; j <= n; j++) {

			for (int k = 0; k < graph[j].size(); k++) {
				int num = graph[j][k];
				int temp = 0;
				if (gps_log[i] != num) {
					temp++;
				}
				dp[i][num] = min(dp[i][num], dp[i - 1][j] + temp);
			}
		}
	}
	if (dp[k - 1][gps_log[k - 1]] < 987654321) {
		answer = dp[k - 1][gps_log[k - 1]];
	}
	else answer = -1;
	return answer;
}