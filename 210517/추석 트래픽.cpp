#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	vector<int> start;
	vector<int> end;

	for (int i = 0; i < lines.size(); i++) {
		int h = stoi(lines[i].substr(11, 2)) * 3600 * 1000;
		int m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
		int s = stoi(lines[i].substr(17, 2)) * 1000;
		int ms = stoi(lines[i].substr(20, 3));

		int process = stof(lines[i].substr(24, lines[i].size() - 24 - 1)) * 1000;

		start.push_back(h + m + s + ms - process + 1);
		end.push_back(h + m + s + ms);
	}

	for (int i = 0; i < lines.size(); i++) {
		//int minTime = start[i];
		int maxTime = end[i] + 1000;
		int cnt = 0;
		for (int j = i; j < end.size(); j++) {
			if (start[j] < maxTime) {
				cnt++;
			}
		}

		if (answer < cnt) {
			answer = cnt;
		}
	}


	return answer;
}