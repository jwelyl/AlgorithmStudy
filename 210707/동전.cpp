#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int tc, total, n;
	cin >> tc;
	while (tc--) {
		vector<int> coins;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			coins.push_back(temp);
		}
		cin >> total;
		int dp[10001];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coins[i]; j <= total; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}
		printf("%d\n", dp[total]);
	}
	return 0;
}