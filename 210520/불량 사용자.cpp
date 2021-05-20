#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

bool visit[10] = { false };
set<string> set2;

bool check(string user, string banned) {
	if (user.size() != banned.size()) {
		return false;
	}
	bool check = false;

	for (int i = 0; i < user.size(); i++) {
		if (user[i] == banned[i] || banned[i] == '*')
		{
			check = true;
		}
		else {
			check = false;
			break;
		}
	}

	return check;
}

void dfs(vector<string> user, vector<string> banned, vector<string> s) {

	if (s.size() == banned.size()) {
		string temp = "";
		int cnt = 0;
		vector<string> ss;
		for (int i = 0; i < s.size(); i++) {
			if (check(s[i], banned[i]))
			{
				temp = temp + s[i];
				ss.push_back(s[i]);
			}
			else {
				return;
			}
		}

		sort(ss.begin(), ss.end());
		string str = "";
		for (int i = 0; i < ss.size(); i++) {
			str += ss[i];
		}
		set2.insert(str);
		return;
	}

	for (int i = 0; i < user.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			s.push_back(user[i]);
			dfs(user, banned, s);
			s.pop_back();
			visit[i] = false;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	vector<string> s;
	dfs(user_id, banned_id, s);
	answer = set2.size();
	return answer;
}