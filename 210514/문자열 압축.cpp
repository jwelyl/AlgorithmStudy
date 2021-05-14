#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int solution(string s) {
	int answer = 0;
	answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++) {
		string start;
		for (int j = 0; j < i; j++) {
			start += s[j];
		}
		string temp = "";
		int cnt = 1;

		for (int j = i; j <= s.size() * 2; j += i) {
			if (j >= s.size()) {
				if (cnt != 1) {
					temp = temp + to_string(cnt) + start;
				}
				else {
					temp = temp + start;
				}
				break;
			}
			if (start == s.substr(j, i)) {
				cnt++;
			}
			else {
				if (cnt != 1) {
					temp = temp + to_string(cnt) + start;
				}
				else {
					temp = temp + start;
				}
				cnt = 1;
				start = s.substr(j, i);
			}
		}
		if (temp.size() < answer) {
			answer = temp.size();
		}

	}
	return answer;
}