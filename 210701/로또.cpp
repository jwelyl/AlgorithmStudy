#include <iostream>
#include <string.h>
using namespace std;
#define MAX_VALUE 2001
#define MAX_RANGE 11
int N, M;
long long dp[MAX_RANGE][MAX_VALUE];
int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N >> M;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < MAX_VALUE; i++) {
			dp[0][i] = 1;
		}
		for (int i = 1; i < MAX_RANGE; i++) {
			for (int j = 1; j < MAX_VALUE; j++) {
				dp[i][j] = dp[i - 1][j / 2] + dp[i][j - 1];
			}
		}
		printf("%lld\n", dp[N][M]);
	}
	return 0;
}