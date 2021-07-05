#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_LEN 1001
int dp[MAX_LEN][MAX_LEN] = { { 0,0 } };
int GetLen(const string& x, const string& y)
{
	for (int i = 1; i < x.length(); i++) {
		for (int j = 1; j < y.length(); j++) {
			if (x[i] == y[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[x.length() - 1][y.length() - 1];
}
int main()
{
	string x, y;
	cin >> x >> y;
	x.insert(0, "0");
	y.insert(0, "0");

	printf("%d\n", GetLen(x, y));
	return 0;
}