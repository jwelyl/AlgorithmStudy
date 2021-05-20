#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
set<string> s;

string makeAnswer(vector<string> array) {
	sort(array.begin(), array.end());
	string ans = "";
	for (string str : array) { ans += str; }
	return ans;
}

bool check(string str, string ban) {
	if (str.length() != ban.length()) { return false; }
	for (int i = 0; i<str.length(); i++) {
		if (ban.at(i) != '*') {
			if (str.at(i) != ban.at(i)) { return false; }
		}
	}
	return true;
}

void dfs(vector<string> user_id, vector<string> banned_id, int index) {

	if (index == banned_id.size()) {
		string ans = makeAnswer(banned_id);
		s.insert(ans);
		return;
	}


	for (int i = 0; i<user_id.size(); i++) {
		string origin = user_id[i], ban = banned_id[index];
		if (check(origin, ban)) {
			user_id[i] = ""; banned_id[index] = origin;
			dfs(user_id, banned_id, index + 1);
			user_id[i] = origin; banned_id[index] = ban; 
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {

	dfs(user_id, banned_id, 0);
	return s.size();
}