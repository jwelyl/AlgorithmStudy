#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<int> adj[210];
    int dp[210][210];

    for (int i = 0; i < edge_list.size(); i++) {
        adj[edge_list[i][0]].push_back(edge_list[i][1]);
        adj[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    for (int i = 0; i < 210; i++) {
        for (int j = 0; j < 210; j++) {
            dp[i][j] = 99999999;
        }
    }

    // dp[i][j] : 경로의 i번째 위치가 j번 도시가 되면서 i번째 위치까지의 경로가 valid하게 고쳐야 하는 최소 횟수
    dp[0][gps_log[0]] = 0;
    for (int i = 1; i < k - 1; i++) {
        for (int j = 1; j <= n; j++) {
            int add = (gps_log[i] == j ? 0 : 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + add);

            for (auto p : adj[j]) {
                dp[i][j] = min(dp[i - 1][p] + add, dp[i][j]);
            }
        }
    }

    answer = 99999999;
    for (auto p : adj[gps_log.back()]) {
        answer = min(answer, dp[gps_log.size() - 2][p]);
    }

    if (answer > 100) {
        answer = -1;
    }

    return answer;
}