#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <bitset>
using namespace std;
vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2, 0);
	set<string> s;
	string start = words[0];
	s.insert(words[0]);
	int cnt = 1;

	for (int i = 1; i < words.size(); i++) {
		cnt++;
		auto it = find(s.begin(), s.end(), words[i]);
		if (it == s.end() && start.back() == words[i].at(0)) {
			s.insert(words[i]);
			start = words[i];
		}
		else {
			answer[0] = cnt;
			answer[1] = i / n + 1;
			break;
		}

		cnt = cnt % n;

	}
	return answer;
}