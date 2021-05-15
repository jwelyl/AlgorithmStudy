#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	string op, uid, name;
	vector<pair<string, string>> logs;
	map<string, string> m;
	for (const auto& r : record) {
		istringstream ss(r);
		getline(ss, op, ' ');
		getline(ss, uid, ' ');
		getline(ss, name, ' ');
		logs.push_back({ uid, op });
		if (op == "Enter" || op == "Change")
			m[uid] = name;
	}
	for (const auto& log : logs) {
		uid = log.first;
		op = log.second;
		string result;
		if (op == "Enter") {
			result = m[uid] + "님이 들어왔습니다.";
		}
		else if (op == "Leave") {
			result = m[uid] + "님이 나갔습니다.";
		}
		if (result.length() != 0)
			answer.push_back(result);
	}
	return answer;
}