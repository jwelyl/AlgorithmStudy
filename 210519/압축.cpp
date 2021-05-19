#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	string next;
	map<string, int> dict;
	int order = 1;
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		next = ch;
		dict[next] = order++;
	}
	int idx = 0, len = msg.length();
	int size = 1;
	string post, key;
	while (idx + size <= len) {
		key = msg.substr(idx, size++);
		if (dict.find(key) != dict.end()) {
			post = key;
			continue;
		}
		else {
			answer.push_back(dict[post]);
			dict[key] = order++;
			idx += post.length();
			size = 1;
		}
	}
	if (key.length() != 0)
		answer.push_back(dict[key]);
	return answer;
}