#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
int zero = 0;
int one = 0;
void trans(vector<vector<int>>& arr) {
	int start = arr[0][0];
	bool c = true;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (start != arr[i][j]) {
				c = false;
			}
		}
	}
	if (c) {
		if (start == 0) zero++;
		else one++;
		return;
	}
	vector<vector<vector<int>>> v(4, vector<vector<int>>(arr.size() / 2));
	int s[4] = { arr[0][0], arr[0][arr.size() / 2], arr[arr.size() / 2][0], arr[arr.size() / 2][arr.size() / 2] };
	bool chk[4] = { false };
	for (int i = 0; i < arr.size() / 2; i++) {
		for (int j = 0; j < arr[i].size() / 2; j++) {
			v[0][i].push_back(arr[i][j]);
			if (s[0] != arr[i][j]) chk[0] = true;
		}

		for (int j = arr[i].size() / 2; j < arr[i].size(); j++) {
			v[1][i].push_back(arr[i][j]);
			if (s[1] != arr[i][j]) chk[1] = true;
		}
	}


	for (int i = arr.size() / 2; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size() / 2; j++) {
			v[2][i - arr.size() / 2].push_back(arr[i][j]);
			if (s[2] != arr[i][j]) chk[2] = true;
		}

		for (int j = arr[i].size() / 2; j < arr[i].size(); j++) {
			v[3][i - arr.size() / 2].push_back(arr[i][j]);
			if (s[3] != arr[i][j]) chk[3] = true;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (chk[i]) {
			vector<vector<int>> temp(v[i].begin(), v[i].end());
			trans(temp);
		}
		else {
			if (s[i] == 0) {
				zero += 1;
			}
			else {
				one += 1;
			}
		}

	}
}
vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;
	trans(arr);
	answer.push_back(zero);
	answer.push_back(one);
	return answer;
}