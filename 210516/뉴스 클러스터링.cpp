#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

using namespace std;
bool IsAlpha(string& str)
{
	if (str[0] <= 'z' && str[0] >= 'a' &&
		str[1] <= 'z' && str[1] >= 'a')
		return true;
	return false;
}
int solution(string str1, string str2) {
	int answer = 0, len = 0;
	string str;
	map<string, int> m1;
	map<string, int> m2;
	set<string> words;
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	len = str1.length();
	for (int i = 1; i<len; i++) {
		str = str1.substr(i - 1, 2);
		if (IsAlpha(str)) {
			m1[str]++;
			words.insert(str);
		}
	}
	len = str2.length();
	for (int i = 1; i<len; i++) {
		str = str2.substr(i - 1, 2);
		if (IsAlpha(str)) {
			m2[str]++;
			words.insert(str);
		}
	}
	int Intersection = 0, Union = 0;
	for (const auto& word : words) {
		Intersection += min(m1[word], m2[word]);
		Union += max(m1[word], m2[word]);
	}
	if (words.size() == 0)
		return 65536;
	answer = (double)Intersection / Union * 65536;
	return answer;
}