#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_SIZE 5001
int N, M;
int height[MAX_SIZE];
vector<int> graph[MAX_SIZE];
int dp[MAX_SIZE];
int dfs(int cur)
{
	if (dp[cur] == -1) {
		dp[cur] = 1;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (height[cur] < height[next]) {
				dp[cur] = max(dp[cur], dfs(next) + 1);
			}
		}
	}
	return dp[cur];
}
int main()
{
	cin >> N >> M;
	int s, e;
	for (int i = 0; i <= N; i++)
		dp[i] = -1;
	for (int i = 0; i < N; i++)
		scanf("%d", &height[i + 1]);
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (int i = 1; i <= N; i++)
		dfs(i);
	for (int i = 1; i <= N; i++)
		printf("%d\n", dp[i]);
	return 0;
}