#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <bitset>
using namespace std;
string ss = "";
void trans(int n) {
	if (n / 2 < 2) {
		if (n / 2 > 0) ss += to_string(n / 2);

		ss += to_string(n % 2);
		return;
	}
	else {
		trans(n / 2);
		ss += to_string(n % 2);
	}
}
vector<int> solution(string s) {
	vector<int> answer;
	int zero = 0;
	int cnt = 0;
	while (1) {
		string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				temp += s[i];
			}
			else zero++;
		}
		trans(temp.size());
		s = ss;
		ss = "";
		cnt++;
		if (s.size() == 1) break;
	}
	answer.push_back(cnt);
	answer.push_back(zero);
	return answer;
}