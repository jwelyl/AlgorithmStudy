#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool visit[10] = { false };

int cnt = 0;

vector<char> temp;
vector<char> s1;
vector<char> s2;
vector<char> cal;
vector<char> value;

void dfs(int idx, vector<char> s) {

	if (idx == s.size()) {

		bool chk = true;

		for (int i = 0; i < s1.size(); i++) {

			int dis1;
			int dis2;

			auto find_s1 = find(temp.begin(), temp.end(), s1[i]);
			if (find_s1 != temp.end()) {
				dis1 = find_s1 - temp.begin();
			}

			auto find_s2 = find(temp.begin(), temp.end(), s2[i]);
			if (find_s2 != temp.end()) {
				dis2 = find_s2 - temp.begin();
			}

			char calculate = cal[i];

			int value1 = value[i] - '0';

			int absolute = abs(dis1 - dis2);

			if (calculate == '=') {
				if (absolute - 1 == value1) {
				}
				else {
					chk = false;
					break;
				}
			}

			else if (calculate == '>') {
				if (absolute - 1 > value1) {
				}

				else {
					chk = false;
					break;
				}
			}

			else if (calculate == '<') {
				if (absolute - 1 < value1) {
				}
				else {
					chk = false;
					break;
				}
			}
		}

		if (chk) {
			cnt++;
		}

		return;
	}

	for (int i = 0; i < s.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			temp.push_back(s[i]);
			dfs(idx + 1, s);
			visit[i] = false;
			temp.pop_back();
		}
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;

	visit[10] = { false };
	cnt = 0;
	temp = vector<char>();
	s1 = vector<char>();
	s2 = vector<char>();
	cal = vector<char>();
	value = vector<char>();

	vector<char> name = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

	for (int i = 0; i < n; i++) {
		vector<string> v;

		s1.push_back(data[i].at(0));
		s2.push_back(data[i].at(2));
		cal.push_back(data[i].at(3));
		value.push_back(data[i].at(4));

	}

	dfs(0, name);
	answer = cnt;
	return answer;
}
