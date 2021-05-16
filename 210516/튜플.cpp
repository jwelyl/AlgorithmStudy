#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<string> a, vector<string> b) {
	return a.size() < b.size();
}

vector<int> solution(string s) {
	vector<int> answer;
	int length = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '}') length++;
	}
	length--;
	vector<vector<string>> v(length);

	string temp = "";
	int cnt = 0;
	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == '{') {
			temp = "";
			continue;
		}
		else if (s[i] == '}') {
			i++;
			v[cnt].push_back(temp);
			cnt++;
		}
		else if (s[i] == ',') {
			v[cnt].push_back(temp);
			temp = "";
		}
		else {
			temp += s[i];
		}
	}

	sort(v.begin(), v.end(), cmp);
	int num2 = 0;
	for (int i = 0; i < v.size(); i++) {
		int num = 0;
		for (int j = 0; j < v[i].size(); j++) {
			num += stoi(v[i][j]);
		}
		answer.push_back(num - num2);
		num2 = num;
	}
	return answer;
}