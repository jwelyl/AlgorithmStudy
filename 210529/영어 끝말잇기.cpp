#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
set<string> se;
vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	int order = 1, turn = 1, cnt = 0;
	char pre = words[0][0];
	for (const auto& word : words) {
		if (pre != word[0])
			break;
		else if (se.find(word) == se.end())
			se.insert(word);
		else
			break;
		if (++order > n) {
			order = 1;
			turn++;
		}
		pre = word[word.length() - 1];
		cnt++;
	}
	if (cnt == words.size()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(order);
		answer.push_back(turn);
	}
	return answer;
}