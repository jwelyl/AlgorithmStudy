#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;
int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.size(); i++) {
		stack<char> stack;
		bool chk = true;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '[' || s[j] == '{' || s[j] == '(') {
				stack.push(s[j]);
			}
			else {
				if (stack.empty()) {
					chk = false;
					break;
				}
				else {
					if (stack.top() == '[' && s[j] == ']') {
						stack.pop();
					}
					else if (stack.top() == '{' && s[j] == '}') {
						stack.pop();
					}
					else if (stack.top() == '(' && s[j] == ')') {
						stack.pop();
					}
					else {
						chk = false;
						break;
					}
				}
			}
		}
		if (chk && stack.empty()) answer++;
		s.push_back(s[0]);
		s.erase(s.begin());

	}

	return answer;
}