#include <string>
#include <vector>
#include <iostream>

using namespace std;
string change_binary(const string& s, int& zero_cnt)
{
	string str;
	//remove zero
	for (const auto& c : s) {
		if (c == '1')
			str.push_back('1');
	}
	zero_cnt += s.size() - str.size();
	int num = str.length();
	str.clear();
	while (num != 0) {
		if (num % 2 == 1)
			str.insert(0, 1, '1');
		else
			str.insert(0, 1, '0');
		num /= 2;
	}
	return str;
}
vector<int> solution(string s) {
	vector<int> answer;
	int cnt = 0, zero_cnt = 0;
	while (s.length() != 1) {
		s = change_binary(s, zero_cnt);
		cnt++;
	}
	answer.push_back(cnt);
	answer.push_back(zero_cnt);
	return answer;
}