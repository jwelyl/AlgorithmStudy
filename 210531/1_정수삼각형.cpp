#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int len = triangle.size();
    vector<vector<int>> dp(len, vector<int>(len));

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }
    
    return *max_element(dp[len - 1].begin(), dp[len - 1].end());
}
