#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

struct info {
	int end;
	int value;
};
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	int dist[51];
	vector<info> graph[51];
	for (int i = 0; i < road.size(); i++) {
		int start = road[i][0];
		int end = road[i][1];
		int value = road[i][2];

		graph[start].push_back({ end, value });
		graph[end].push_back({ start, value });
	}
	fill_n(dist, 51, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 1,0 });
	dist[1] = 0;

	while (!pq.empty()) {
		int start = pq.top().first;
		int value = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[start].size(); i++) {
			if (value + graph[start][i].value < dist[graph[start][i].end]) {
				dist[graph[start][i].end] = value + graph[start][i].value;
				pq.push({ graph[start][i].end,  dist[graph[start][i].end] });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K) {
			answer++;
		}
	}
	return answer;
}