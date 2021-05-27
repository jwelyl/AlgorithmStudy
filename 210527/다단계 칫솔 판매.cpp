#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> cost;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	for (int i = 0; i < referral.size(); i++) {
		parent[enroll[i]] = referral[i];
	}

	for (int i = 0; i < seller.size(); i++) {
		int value = amount[i] * 100 - amount[i] * 100 / 10;
		cost[seller[i]] += value;
		value = amount[i] * 100 / 10;
		string pare = parent[seller[i]];

		while (1) {
			cost[pare] += value - value / 10;
			pare = parent[pare];
			value /= 10;
			if (value == 0)break;
			if (pare == "") break;
		}
	}
	for (int i = 0; i < enroll.size(); i++) {
		answer.push_back(cost[enroll[i]]);
	}
	return answer;
}