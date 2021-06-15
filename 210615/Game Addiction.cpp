#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;

int maxValue(int a, int b) {
	if (a < b) return b;
	else return a;
}

int minValue(int a, int b) {
	if (a > b) return b;
	else return a;
}
int main() {

	int h, n;
	cin >> h >> n;
	int max = maxValue(h, n) + 1;
	int min = minValue(h, n) + 1;
	long long int dp[50][50];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			dp[i][j] = 0;
		}
	}
	dp[min - 1][min] = 1;

	for (int i = min; i <= max; i++) {
		for (int j = min; j <= i; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[max][max] << endl;
	return 0;
}