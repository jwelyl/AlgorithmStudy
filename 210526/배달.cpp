#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int dist[51][51];
void setting(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
}
void floyd(int n)
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	setting(N);
	for (int i = 0; i < road.size(); i++) {
		int s = road[i][0], e = road[i][1], d = road[i][2];
		dist[s][e] = min(dist[s][e], d);
		dist[e][s] = min(dist[e][s], d);
	}
	floyd(N);
	for (int i = 1; i <= N; i++) {
		if (dist[1][i] <= K)
			answer++;
	}
	return answer;
}