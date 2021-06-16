#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;
#define MOD 1000000007
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	long long int dp[1000001];
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;
	long long int temp = 0;
	for (int i = 3; i <= n; i++) {
		temp += dp[i - 3] * 2;
		dp[i] = (2 * dp[i - 1] + 3 * dp[i - 2] + temp) % MOD;
		//temp+=
		/*for (int j = 3; j <= i; j++) {
			dp[i] += 2*dp[j-3] % MOD;

		}*/

	}

	cout << dp[n] << endl;
	return 0;
}