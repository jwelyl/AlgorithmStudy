#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer(2);
	unordered_map<string, int> m;
	for (int i = 0; i < gems.size(); i++) {
		m[gems[i]]++;
	}
	int count = m.size();
	int start = 0;
	int end = 0;
	m.clear();
	answer[0] = 1;
	answer[1] = gems.size();
	while (start < gems.size() && end <= gems.size()) {

		if (m.size() == count) {
			m[gems[start]]--;
			if (m[gems[start]] == 0) {
				m.erase(gems[start]);
			}

			if (answer[1] - answer[0] > end - start) {
				answer[0] = start;
				answer[1] = end;
			}
			start++;
			//start end 차이 값 비교
		}
		else {
			if (end == gems.size())break;
			m[gems[end]]++;
			end++;
		}
	}

	if (answer[1] - answer[0] != gems.size() - 1) {
		answer[0] += 1;
	}

	return answer;
}