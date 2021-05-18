#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> s;

	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			cities[i].at(j) = toupper(cities[i].at(j));
		}
	}

	for (int i = 0; i < cities.size(); i++) {
		auto it = find(s.begin(), s.end(), cities[i]);
		if (it == s.end()) { //존재X
			answer += 5;
		}
		else { //존재O
			int idx = find(s.begin(), s.end(), cities[i]) - s.begin();
			s.erase(s.begin() + idx);
			s.insert(s.begin(), cities[i]);
			answer += 1;
		}
		if (cacheSize == 0) continue;

		if (s.size() == cacheSize) {
			s.erase(s.begin() + 0);
		}
		s.push_back(cities[i]);
	}
	return answer;
}