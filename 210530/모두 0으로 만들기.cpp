#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long ans = 0;

void dfs(vector<long>& a, vector<vector<int>>& graph, long long start, long long prev,
	vector<bool>& visit) {

	visit[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		if (visit[graph[start][i]] == false) {
			dfs(a, graph, graph[start][i], start, visit);
		}
	}

	if (start != 0) {

		long long num = a[start];
		if (num < 0) num *= -1;

		a[prev] += a[start];
		a[start] = 0;

		ans += num;
	}

}

long long solution(vector<int> a, vector<vector<int>> edges) {

	vector<vector<int>> graph(a.size());
	vector<bool>visit(a.size(), false);
	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}
	vector<long> b(a.size());
	for (int i = 0; i < a.size(); i++) {
		b[i] = a[i];
	}
	dfs(b, graph, 0, 0, visit);

	if (b[0] == 0)
		return ans;
	else
		return -1;
}