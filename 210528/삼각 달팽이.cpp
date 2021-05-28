#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> solution(int n) {
	int result = n;
	vector<int> answer;

	vector<vector<int>> v(n + 1, vector<int>(n, 0));
	int cnt = 1;
	int num = 1;

	while (1) {

		for (int i = num; i <= n; i++) {
			v[i][num - 1] = cnt++;
		}
		for (int i = num; i < n; i++) {
			v[n][i] = cnt++;
		}
		for (int i = n - 1; i > num; i--) {
			v[i][n - 1] = cnt++;
		}
		if (num >= n) break;
		num += 2;
		n--;
	}

	for (int i = 1; i <= result; i++) {
		for (int j = 0; j < result; j++) {
			if (v[i][j] == 0) continue;
			else {
				answer.push_back(v[i][j]);
			}
		}
	}
	return answer;
}