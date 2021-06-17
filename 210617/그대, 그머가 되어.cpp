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
	int end;
	int cost;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int a, b;
	cin >> a >> b;
	cin >> n >> m;
	vector<info> graph[1001];
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back({ e,1 });
		graph[e].push_back({ s,1 });
	}
	int dist[1001];
	fill_n(dist, 1001, 987654321);
	dist[a] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,a });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int end = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[end].size(); i++) {
			if (graph[end][i].cost + cost < dist[graph[end][i].end]) {

				dist[graph[end][i].end] = graph[end][i].cost + cost;
				pq.push({ dist[graph[end][i].end] , graph[end][i].end });
			}
		}
	}
	if (dist[b] == 987654321) {
		cout << "-1" << endl;
		return 0;
	}
	cout << dist[b] << endl;
	return 0;
}