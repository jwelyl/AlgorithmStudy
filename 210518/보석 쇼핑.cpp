#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
unordered_map<string, int> um;
vector<int> solution(vector<string> gems) {
	vector<int> answer(2, 0);
	for (const auto& gem : gems)
		um[gem]++;
	int kind = um.size();
	int s = 0, e = 0;
	int minKind = 987654321;
	unordered_map<string, int> km;
	while (1) {
		if (km.size() >= kind) {
			km[gems[s]]--;
			if (km[gems[s]] == 0)
				km.erase(gems[s]);
			s++;
		}
		else if (e == gems.size()) {
			break;
		}
		else {
			km[gems[e]]++;
			e++;
		}

		if (km.size() == kind) {
			if (minKind > e - s) {
				minKind = e - s;
				answer[0] = s + 1;
				answer[1] = e;
			}
		}
	}
	return answer;
}