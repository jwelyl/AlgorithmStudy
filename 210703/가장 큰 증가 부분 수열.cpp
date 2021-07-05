#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1001
int N;
int arr[MAX_SIZE];
int dp[MAX_SIZE];
int main()
{
	cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
		answer = max(dp[i], answer);
	}
	printf("%d\n", answer);
	return 0;
}