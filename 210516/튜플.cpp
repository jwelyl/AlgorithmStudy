#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
unordered_set<int> se;
bool cmp(vector<string>& v1, vector<string>& v2)
{
	return v1.size() < v2.size();
}
vector<int> solution(string s) {
	vector<int> answer;
	vector<string> parse;
	vector<vector<string>> v;
	string num;
	for (const auto& c : s) {
		if ('0' <= c && c <= '9') {
			num += c;
		}
		else if (c == ',') {
			if (num.length()) {
				parse.push_back(num);
			}
			num.clear();
		}
		else if (c == '}') {
			if (num.length()) {
				parse.push_back(num);
				num.clear();
			}
			if (parse.size())
				v.push_back(parse);
			parse.clear();
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int num = stoi(v[i][j]);
			if (se.find(num) == se.end()) {
				se.insert(num);
				answer.push_back(num);
			}
		}
	}
	return answer;
}