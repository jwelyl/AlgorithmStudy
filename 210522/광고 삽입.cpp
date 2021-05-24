#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	long play = stol(play_time.substr(0, 2)) * 3600 + stol(play_time.substr(3, 2)) * 60 + stol(play_time.substr(6, 2));
	long adv = stol(adv_time.substr(0, 2)) * 3600 + stol(adv_time.substr(3, 2)) * 60 + stol(adv_time.substr(6, 2));

	int time[360000] = { 0 };
	long start = 0;
	long end = 0;
	for (int i = 0; i < logs.size(); i++) {
		start = stol(logs[i].substr(0, 2)) * 3600 + stol(logs[i].substr(3, 2)) * 60 + stol(logs[i].substr(6, 2));
		end = stol(logs[i].substr(9, 2)) * 3600 + stol(logs[i].substr(12, 2)) * 60 + stol(logs[i].substr(15, 2));
		for (long j = start; j < end; j++) {
			time[j]++;
		}
	}

	long max = 0;
	long time2 = 0;
	for (long i = 0; i <= play - adv; i++) {
		long sum = 0;
		long start = i;
		long end = i + adv;

		for (long j = start; j < end; j++) {
			sum += time[j];
		}

		if (max < sum) {
			time2 = start;
			max = sum;
		}
	}

	long hour = time2 / 3600;
	string h = to_string(hour);
	if (hour < 10) {
		h = "0" + to_string(time2 / 3600);
	}

	long minute = time2 % 3600 / 60;
	string m = to_string(minute);
	if (minute < 10) {
		m = "0" + to_string(time2 % 3600 / 60);
	}

	long second = time2 % 3600 % 60;
	string s = to_string(second);
	if (second < 10) {
		s = "0" + to_string(time2 % 3600 % 60);
	}

	answer = h + ":" + m + ":" + s;
	return answer;
}