#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	vector<pair<int, pair<int, string>>> answerlist;

	for (int i = 0; i < musicinfos.size(); i++) {
		vector<string> result = split(musicinfos[i], ',');
		string h1 = "", m1 = "";
		h1 = result[0].substr(0, 2);
		m1 = result[0].substr(3, 2);

		string h2 = "", m2 = "";
		h2 = result[1].substr(0, 2);
		m2 = result[1].substr(3, 2);

		int t1 = 0, t2 = 0;
		t1 = stoi(h1) * 60 + stoi(m1);
		t2 = stoi(h2) * 60 + stoi(m2);
		int time = t2 - t1;
		string code = "";
		int cnt = 0;
		int idx = 0;

		for (int j = 0; j <= time; j++) {
			if (j == time && idx != result[3].size() && result[3].at(idx) == '#') {
				code += result[3].at(idx);
				break;
			}
			else if (j == time) {
				break;
			}
			if (idx == result[3].size()) {
				idx = 0;
			}
			code += result[3].at(idx);
			if (result[3].at(idx) == '#') {
				time++;
			}
			idx++;
		}

		int m_size = m.size();

		int index = 0;
		int temp;
		while ((temp = (int)code.find(m, index)) != -1) {
			index = temp + 1;
			if (code[index + m.size() - 1] == '#') {
				continue;
			}
			else {
				answerlist.push_back(make_pair(t2 - t1, make_pair(i, result[2])));
				break;
			}
		}
		//#이 붙었냐 안붙었냐
	}

	//8
	if (answerlist.size() == 0) {
		return "(None)";
	}
	else {
		sort(answerlist.begin(), answerlist.end(), greater<>());
		int t = answerlist[0].first;

		vector<pair<int, string>> v;
		for (int i = 0; i < answerlist.size(); i++) {
			if (answerlist[i].first == t) {
				v.push_back(make_pair(answerlist[i].second.first, answerlist[i].second.second));
			}
		}
		sort(v.begin(), v.end());
		return answer = v[0].second;
	}

}