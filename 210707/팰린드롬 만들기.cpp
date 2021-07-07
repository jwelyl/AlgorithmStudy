#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n, i;
int arr[5000];
int dp[5000][5000];

int func(int x, int y) {
	if (x > y)
		return 0;

	int& ref = dp[x][y];
	if (ref != -1)
		return ref;

	if (arr[x] == arr[y])
		return ref = func(x + 1, y - 1);
	else
		return ref = min(func(x + 1, y) + 1, func(x, y - 1) + 1);
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	memset(dp, -1, sizeof(dp));

	printf("%d", func(0, n - 1));

	return 0;
}
