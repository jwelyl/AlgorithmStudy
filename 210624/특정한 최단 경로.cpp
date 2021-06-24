#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define INF 2100000000

int a, b, c, v1, v2;
int N, E;
long long x, y;
long long result_1[801], result_v1[801], result_v2[801];
vector<pair<int, int>> v[801];

void dijkstra(int start, long long* result)
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		result[i] = INF;

	result[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int node = q.front();
		int dist = result[node];
		q.pop();

		for (int i = 0; i < v[node].size(); i++)
		{
			int next_node = v[node][i].first;
			int next_dist = v[node][i].second;

			if (result[next_node] > dist + next_dist)
			{
				result[next_node] = dist + next_dist;
				q.push(next_node);
			}
		}
	}
}

int main()
{
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(pair<int, int>(b, c));
		v[b].push_back(pair<int, int>(a, c));
	}

	cin >> v1 >> v2;

	dijkstra(1, result_1);
	dijkstra(v1, result_v1);
	dijkstra(v2, result_v2);

	x = result_1[v1] + result_v1[v2] + result_v2[N];
	y = result_1[v2] + result_v2[v1] + result_v1[N];

	if (min(x, y) >= INF) cout << -1;
	else cout << min(x, y);
}