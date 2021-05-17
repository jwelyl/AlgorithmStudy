#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
vector<string> startv;
vector<pair<long long, long long>> window;
int get_ms_dur(string& str)
{
	int total = 0;
	int digit = 1000;
	for (int i = 0; i < str.size(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			total += (str[i] - '0') * digit;
			digit /= 10;
		}
	}
	return total;
}
int solution(vector<string> lines) {
	int answer = 0;
	for (const auto& str : lines) {
		string hour = str.substr(11, 2);
		string min = str.substr(14, 2);
		string sec = str.substr(17, 2);
		string ms = str.substr(20, 3);
		long long end = stoi(hour) * 3600 + stoi(min) * 60 + stoi(sec);
		end *= 1000;
		end += stoi(ms);

		string dur = str.substr(24);
		long long start = end - get_ms_dur(dur) + 1;
		window.push_back({ start, end });
	}
	for (int i = 0; i < window.size(); i++) {
		int count = 1;
		long long start = window[i].first;
		long long end = window[i].second;
		for (int j = i + 1; j < window.size(); j++) {
			if (start + 1 >= window[j].first || end + 1 > window[j].first)
				count++;
		}
		answer = max(answer, count);
	}
	return answer;
}