#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
vector<int> adj[1001];

int f(int i)
{
	int &ret = dp[i];
	if (ret)
		return ret;
	for (int x : adj[i])
		ret = max(ret, f(x));
	return ++ret;
}
int main()
{
	int n, m, i;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	for (i = 1; i <= n; i++)
		cout << f(i) << ' ';
}