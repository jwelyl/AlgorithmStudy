#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
unordered_map<string, int> m;
bool visit[21] = { false };
void dfs(string order, int course, int start, int idx) {
	if (course == idx) {
		string temp = "";
		for (int i = 0; i < order.size(); i++) {
			if (visit[i]) {
				temp += order[i];
				//cout<<order[i]<<" ";
			}
		}
		m[temp]++;
		return;
	}

	for (int i = start; i < order.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			idx++;
			dfs(order, course, i + 1, idx);
			visit[i] = false;
			idx--;
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (int i = 0; i < orders.size(); i++) {
		sort(orders[i].begin(), orders[i].end());
	}

	for (int i = 0; i < course.size(); i++) { //2,3,4 개별로
		for (int j = 0; j < orders.size(); j++) { //모든 주문에 대해서 개수 
			dfs(orders[j], course[i], 0, 0);
		}
	}

	for (int i = 0; i < course.size(); i++) {
		int max = 0;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			if (course[i] == iter->first.size() && iter->second >= max) {
				max = iter->second;
			}
		}

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			if (course[i] == iter->first.size() && iter->second == max && max > 1) {
				answer.push_back(iter->first);
			}
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}