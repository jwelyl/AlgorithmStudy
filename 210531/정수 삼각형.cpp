#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	int dp[500][500] = { {triangle[0][0]} };
	int n = 2;
	for (int i = 1; i < triangle.size(); i++) {
		int idx = 0;
		for (int j = 0; j < n / 2; j++) {
			int temp = dp[i][idx];
			if (temp < triangle[i][idx] + dp[i - 1][j]) {
				dp[i][idx] = triangle[i][idx] + dp[i - 1][j];
			}
			if (answer < dp[i][idx]) {
				answer = dp[i][idx];
			}

			idx++;

			temp = dp[i][idx];
			if (temp < triangle[i][idx] + dp[i - 1][j]) {
				dp[i][idx] = triangle[i][idx] + dp[i - 1][j];
			}
			if (answer < dp[i][idx]) {
				answer = dp[i][idx];
			}
		}
		n += 2;
	}

	return answer;
}